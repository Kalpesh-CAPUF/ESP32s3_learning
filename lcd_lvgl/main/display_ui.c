#include "lcd_lvgl.h"
#include "fonts.h"
#include "images.h"
#include "sd_card.h"

void example_lvgl_demo_ui(lv_disp_t *disp)
{   
//creating color from hex value and setting it to screen
    // lv_color_t color = lv_color_hex(0x80D8FF);
    // lv_obj_set_style_bg_color(lv_scr_act(),color,0);

// in-built color palette with text are and text area bg using in-built color palette
    lv_obj_set_style_bg_color(lv_scr_act(),lv_palette_main(LV_PALETTE_TEAL),0);
    lv_obj_t * textarea = lv_textarea_create(lv_scr_act());
    lv_textarea_add_text(textarea, "insert this text");
    lv_obj_align(textarea, LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_style_bg_color(textarea,lv_palette_main(LV_PALETTE_DEEP_PURPLE),0);
    
    //montserrat 14 font text
    lv_obj_t * label14 = lv_label_create(lv_scr_act());
    lv_label_set_recolor(label14, true);                            // enabling recolor of text (without enabling font color will not change)
    lv_obj_set_style_text_font(label14,&lv_font_montserrat_14,0);
    lv_label_set_text(label14,"#0000ff size=14");                   //adding hex index for font color (first we have to enable recolor)
    lv_obj_align(label14,LV_ALIGN_TOP_LEFT,0,0);

    //inbuilt font :montserrat 48
    lv_obj_t * label48 = lv_label_create(lv_scr_act());
    lv_label_set_recolor(label48, true);
    lv_obj_set_style_text_font(label48,&lv_font_montserrat_48,0);
    lv_label_set_text(label48,"#0000ff size=48");
    lv_obj_align(label48,LV_ALIGN_LEFT_MID,0,0);


    //custom font : playwriteNL 40 
    lv_obj_t *customFont1 = lv_label_create(lv_scr_act());
    lv_label_set_recolor(customFont1, true);
    lv_obj_set_style_text_font(customFont1,&PlaywriteNL_Regular_40_4bpp,0);
    lv_label_set_text(customFont1,"#ff0000 CAPUF EMBEDDED");
    lv_obj_align(customFont1,LV_ALIGN_BOTTOM_MID,0,0);



    lv_obj_t * icon = lv_img_create(lv_scr_act());
    lv_img_set_src(icon,&capuf);
    // lv_obj_set_style_bg_color(lv_scr_act(),lv_palette_main(LV_PALETTE_ORANGE),0);
    // lv_obj_set_pos(icon,400,240);
    // lv_obj_set_size(icon,200,70);
    lv_obj_align_to(icon,lv_scr_act(),LV_ALIGN_CENTER,0,0);

//Image binary file path 
    char * imageName1 = "P:"MOUNT_POINT"/capuf.bin";
    printf("image file 1 = %s\n",imageName1);
    
    
// checking file system works fine....
    // if(fopen(MOUNT_POINT"/capuf.bin","r")) printf("[KALPESH] file opened\n");
    // lv_fs_drv_t *fsdrv = lv_fs_get_drv('P');
    // lv_fs_res_t res = fsdrv->open_cb(fsdrv,fileName,LV_FS_MODE_RD);
    // if(res != LV_FS_RES_OK) printf("error opening file : %s",fileName);
    // else printf("file opened : %s\n",fileName);

    //Loading image from SD card
    lv_obj_t * sdImage1 = lv_img_create(lv_scr_act());
    lv_img_set_src(sdImage1,imageName1);
    lv_obj_align_to(sdImage1,lv_scr_act(),LV_ALIGN_RIGHT_MID ,0,0);


    char * imageName2 = "P:"MOUNT_POINT"/leaf.bin";
    printf("image file 2 = %s\n",imageName2);
    lv_obj_t * sdImage2 = lv_img_create(lv_scr_act());
    lv_img_set_src(sdImage2,imageName2);
    lv_obj_align_to(sdImage2,lv_scr_act(),LV_ALIGN_TOP_RIGHT,0,0);
}