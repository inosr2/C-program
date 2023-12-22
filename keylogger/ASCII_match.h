void key_code( uint64_t c ) {
  if( c >= ' ' && c <= '~' ) 
    printf("\nASCII KEY: %s%c%s\n", TC_GRN,c,TC_NRM);
  else {
    switch(c) {
        case TC_KEY_F1:
		printf("\npressed: %sFunction Key 1%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F2:
		printf("\npressed: %sFunction Key 2%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F3:
		printf("\npressed: %sFunction Key 3%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F4:
		printf("\npressed: %sFunction Key 4%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F5:
		printf("\npressed: %sFunction Key 5%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F6:
		printf("\npressed: %sFunction Key 6%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F7:
		printf("\npressed: %sFunction Key 7%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F8:
		printf("\npressed: %sFunction Key 8%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F9:
		printf("\npressed: %sFunction Key 9%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F10:
		printf("\npressed: %sFunction Key 10%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F11:
		printf("\npressed: %sFunction Key 11%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_F12:
		printf("\npressed: %sFunction Key 12%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_ESCAPE:
		printf("\npressed: %sEscape Key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_ARROW_UP:
		printf("\npressed: %sup arrow key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_ARROW_DOWN:
		printf("\npressed: %sdown arrow key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_ARROW_LEFT:
		printf("\npressed: %sleft arrow key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_ARROW_RIGHT:
		printf("\npressed: %sright arrow key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_TAB:
		printf("\npressed: %sTAB key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_RETURN:
		printf("\npressed: %sReturn key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_INSERT:
		printf("\npressed: %sInsert key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_HOME:
		printf("\npressed: %sHome key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_PAGE_UP:
		printf("\npressed: %sPage Up key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_DELETE:
		printf("\npressed: %sDelete key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_END:
		printf("\npressed: %sEnd key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_PAGE_DOWN:
		printf("\npressed: %sPage Down key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_EURO:
		printf("\npressed: %s€ key%s\n",TC_RED,TC_NRM);
		break;
	case TC_KEY_GBP:
		printf("\npressed: %s£%s\n",TC_RED,TC_NRM);
		break;
	default:
		printf("\nkey pressed: %s0x%lx%s\n", TC_RED,c,TC_NRM);
		break;
    }
  }
  return;
}
