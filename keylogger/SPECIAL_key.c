#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <termios.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include "CANON_switch.h"
#include "COLOR_string.h"
#include "ASCII_key.h"
#include "ASCII_match.h"

void handler(int sig ) {
  tc_canon_off();
  exit(0);
}

typedef struct raw_input {
  struct timespec tm;
  char ch;
}raw_input;

void* input_process( void *arg ) {
  int i;
  raw_input *ri;
  ri = (raw_input*) arg;
  i = 0;
  tc_canon_off();
  while(1) {
    fread(&ri[i].ch,1,1,stdin);
    clock_gettime(CLOCK_MONOTONIC,&ri[i].tm);
    i += 1;
    if( i >= BUFSIZE )
      i = 0;
  }
  return NULL;
}

void* key_process( void *arg ) {
  int i;
  char c;
  long time;
  long nexttime;
  uint64_t key;
  raw_input *ri;
  ri = (raw_input*) arg;

  i = 0;
  while(1) {
    
    while( !ri[i].tm.tv_nsec );
    usleep(100);
    key = ri[i].ch;
    time = ri[i].tm.tv_sec;
    time *= 1000000000;
    time += ri[i].tm.tv_nsec;
    
    ri[i].tm.tv_nsec = 0;
    i += 1;
    if( i >= BUFSIZE )
      i = 0;

    if( ri[i].tm.tv_nsec ) {
       nexttime = ri[i].tm.tv_sec;
       nexttime *= 1000000000;
       nexttime += ri[i].tm.tv_nsec;
       while( (nexttime-time < 100000) && (nexttime != 0 ) ) {
         key <<= 8;
	 key += ri[i].ch;

	 ri[i].tm.tv_nsec = 0;
	 i += 1;
	 if( i >= BUFSIZE )
	   i = 0;

	 time = nexttime;
	 nexttime = ri[i].tm.tv_sec*1000000000;
	 nexttime += ri[i].tm.tv_nsec;
	 usleep(100);
       }
    }
    key_code(key);
  }
  return NULL;
}

int main() {
  
  signal(SIGINT,handler);

  raw_input *ri;
  ri = (raw_input*) malloc( sizeof(raw_input) * BUFSIZE );
  memset(ri, 0, sizeof(raw_input) * BUFSIZE );
  
  pthread_t th1, th2;
  pthread_create( &th1, NULL, (void*)&input_process, (void*)ri );
  pthread_create( &th2, NULL, (void*)&key_process, (void*)ri );
  pthread_join( th1, NULL );
  pthread_join( th2, NULL );
  return 0;
}
