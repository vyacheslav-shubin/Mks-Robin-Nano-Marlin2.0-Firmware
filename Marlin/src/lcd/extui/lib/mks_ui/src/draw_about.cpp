#include "../../../../../MarlinCore.h"
#if ENABLED(TFT_LITTLE_VGL_UI)
#include "lv_conf.h"
//#include "../../lvgl/src/lv_objx/lv_imgbtn.h"
//#include "../../lvgl/src/lv_objx/lv_img.h"
//#include "../../lvgl/src/lv_core/lv_disp.h"
//#include "../../lvgl/src/lv_core/lv_refr.h"
//#include "../../MarlinCore.h"
#include "../../../../../../Configuration.h"
#include "../inc/draw_ui.h"
#include "../../../../../module/temperature.h"

static lv_obj_t * scr;
static lv_obj_t * firmWare,*board;

#define ID_A_RETURN		1

static void event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch(obj->mks_obj_id)
	{
		case ID_A_RETURN:
	    if(event == LV_EVENT_CLICKED) {
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
			clear_cur_ui();
	        	draw_return_ui();
	    }
		break;

	}
}


void lv_draw_about(void)
{
	lv_obj_t *buttonBack,*label_Back;
	if(disp_state_stack._disp_state[disp_state_stack._disp_index] != ABOUT_UI)
	{
		disp_state_stack._disp_index++;
		disp_state_stack._disp_state[disp_state_stack._disp_index] = ABOUT_UI;
	}
	disp_state = ABOUT_UI;

	scr = lv_obj_create(NULL, NULL);
	
	lv_obj_set_style(scr, &tft_style_scr);
  lv_scr_load(scr);
  lv_obj_clean(scr);

  lv_obj_t * title = lv_label_create(scr, NULL);
	lv_obj_set_style(title, &tft_style_lable_rel);
	lv_obj_set_pos(title,TITLE_XPOS,TITLE_YPOS);
	lv_label_set_text(title, creat_title_text());
  
  lv_refr_now(lv_refr_get_disp_refreshing());
	
	LV_IMG_DECLARE(bmp_pic);
	
    /*Create an Image button*/
	buttonBack = lv_imgbtn_create(scr, NULL);

	#if 1
	

	lv_obj_set_event_cb_mks(buttonBack, event_handler,ID_A_RETURN,"bmp_Return.bin",0);	
    lv_imgbtn_set_src(buttonBack, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonBack, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonBack, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonBack, LV_BTN_STATE_REL, &tft_style_lable_rel);

	#endif

	lv_obj_set_pos(buttonBack,BTN_X_PIXEL*3+INTERVAL_V*4,  BTN_Y_PIXEL+INTERVAL_H+titleHeight);
	lv_btn_set_layout(buttonBack, LV_LAYOUT_OFF);
    /*Create a label on the Image button*/

	label_Back = lv_label_create(buttonBack, NULL);
	
	if(gCfgItems.multiple_language !=0)
	{
		lv_label_set_text(label_Back, common_menu.text_back);
		lv_obj_align(label_Back, buttonBack, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);
	}

	firmWare = lv_label_create(scr, NULL);
	lv_obj_set_style(firmWare, &tft_style_lable_rel);
	lv_label_set_text(firmWare, "Firmware: Robin_Nano35");
	lv_obj_align(firmWare, NULL, LV_ALIGN_CENTER,0, -20);

	board = lv_label_create(scr, NULL);
	lv_obj_set_style(board, &tft_style_lable_rel);
	lv_label_set_text(board, "Board: MKS Robin nano");
	lv_obj_align(board, NULL, LV_ALIGN_CENTER,0, 20);
}

void lv_clear_about()
{
	lv_obj_del(scr);
}
#endif