
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_timer.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"


bool my_ready_cb(lv_fs_drv_t * drv);
void * my_open_cb(lv_fs_drv_t *drv, const char *path, lv_fs_mode_t mode);
lv_fs_res_t my_close_cb(lv_fs_drv_t * drv, void * file_p);
lv_fs_res_t my_read_cb(lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br);
lv_fs_res_t my_write_cb(lv_fs_drv_t * drv, void * file_p, const void * buf, uint32_t btw, uint32_t * bw);
lv_fs_res_t my_seek_cb(lv_fs_drv_t * drv, void * file_p, uint32_t pos, lv_fs_whence_t whence);
lv_fs_res_t my_tell_cb(lv_fs_drv_t * drv, void * file_p, uint32_t * pos_p);

void * my_dir_open_cb(lv_fs_drv_t * drv, const char * path);
lv_fs_res_t my_dir_read_cb(lv_fs_drv_t * drv, void * rddir_p, char * fn, uint32_t fn_len);
lv_fs_res_t my_dir_close_cb(lv_fs_drv_t * drv, void * rddir_p);


void LvFsInit() {
    static lv_fs_drv_t *drv = heap_caps_malloc(sizeof(lv_fs_drv_t), MALLOC_CAP_SPIRAM);                   /*Needs to be static or global*/
    lv_fs_drv_init(&drv);                     /*Basic initialization*/

    drv->letter = 'S';                         /*An uppercase letter to identify the drive */
    drv->cache_size = 0;           /*Cache size for reading in bytes. 0 to not cache.*/

    drv->ready_cb = my_ready_cb;               /*Callback to tell if the drive is ready to use */
    drv->open_cb = my_open_cb;                 /*Callback to open a file */
    drv->close_cb = my_close_cb;               /*Callback to close a file */
    drv->read_cb = my_read_cb;                 /*Callback to read a file */
    drv->write_cb = my_write_cb;               /*Callback to write a file */
    drv->seek_cb = my_seek_cb;                 /*Callback to seek in a file (Move cursor) */
    drv->tell_cb = my_tell_cb;                 /*Callback to tell the cursor position  */

    drv->dir_open_cb = my_dir_open_cb;         /*Callback to open directory to read its content */
    drv->dir_read_cb = my_dir_read_cb;         /*Callback to read a directory's content */
    drv->dir_close_cb = my_dir_close_cb;       /*Callback to close a directory */

    drv->user_data = my_user_data;             /*Any custom data if required*/

    lv_fs_drv_register(drv);                 /*Finally register the drive*/
}