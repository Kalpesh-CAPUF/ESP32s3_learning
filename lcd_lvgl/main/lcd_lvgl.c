#include "lcd_lvgl.h"

// static const char *TAG = "example";
static SemaphoreHandle_t lvgl_mux = NULL;

#if 1
void my_flush_cb(lv_display_t * display, const lv_area_t * area, uint8_t * px_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t) lv_display_get_user_data(display);
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one
     *`put_px` is just an example, it needs to be implemented by you.*/
    // uint16_t * buf16 = (uint16_t *)px_map; /*Let's say it's a 16 bit (RGB565) display*/
    uint32_t offsetx1 = area->x1;
    uint32_t offsetx2 = area->x2;
    uint32_t offsety1 = area->y1;
    uint32_t offsety2 = area->y2;
    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, px_map);
    /* IMPORTANT!!!
     * Inform LVGL that you are ready with the flushing and buf is not used anymore*/
    lv_display_flush_ready(display);
}

static bool example_on_vsync_event(esp_lcd_panel_handle_t panel, const esp_lcd_rgb_panel_event_data_t *event_data, void *user_data)
{
    BaseType_t high_task_awoken = pdFALSE;
#if CONFIG_EXAMPLE_AVOID_TEAR_EFFECT_WITH_SEM
    if (xSemaphoreTakeFromISR(sem_gui_ready, &high_task_awoken) == pdTRUE) {
        xSemaphoreGiveFromISR(sem_vsync_end, &high_task_awoken);
    }
#endif
    return high_task_awoken == pdTRUE;
}
#endif
// bool example_lvgl_lock(int timeout_ms)
// {
//     // Convert timeout in milliseconds to FreeRTOS ticks
//     // If `timeout_ms` is set to -1, the program will block until the condition is met
//     const TickType_t timeout_ticks = (timeout_ms == -1) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
//     return xSemaphoreTakeRecursive(lvgl_mux, timeout_ticks) == pdTRUE;
// }

// void example_lvgl_unlock(void)
// {
//     xSemaphoreGiveRecursive(lvgl_mux);
// }
// static void example_increase_lvgl_tick(void *arg)
// {
//     /* Tell LVGL how many milliseconds has elapsed */
//     lv_tick_inc(EXAMPLE_LVGL_TICK_PERIOD_MS);
// }

// static void example_lvgl_port_task(void *arg)
// {

//     lv_lock();

//     lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x003a57), LV_PART_MAIN);
//     lv_obj_t * label = lv_label_create(lv_screen_active());
//     lv_label_set_text(label, "Hello world");
//     lv_obj_set_style_text_color(lv_screen_active(), lv_color_hex(0xffffff), LV_PART_MAIN);
//     lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

//     lv_unlock();
//     while(1) {
//         sleep(2);
//     }
//     // ESP_LOGI(TAG, "Starting LVGL task");
//     // uint32_t task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
//     // while (1) {
//     //     printf("[KALPESH] thread working fine\n");
//     //     // Lock the mutex due to the LVGL APIs are not thread-safe
//     //     if (example_lvgl_lock(-1)) {
//     //         task_delay_ms = lv_timer_handler();
//     //         printf("nex delay = %lu\n",task_delay_ms);
//     //     //     // Release the mutex
//     //         example_lvgl_unlock();
//     //     }
//     //     // if (task_delay_ms > EXAMPLE_LVGL_TASK_MAX_DELAY_MS) {
//     //     //     task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
//     //     // } else if (task_delay_ms < EXAMPLE_LVGL_TASK_MIN_DELAY_MS) {
//     //     //     task_delay_ms = EXAMPLE_LVGL_TASK_MIN_DELAY_MS;
//     //     // }
        
//         vTaskDelay(pdMS_TO_TICKS(task_delay_ms));
//     // }
// }

void app_main(void)
{
#if 1
    lv_display_t * display = NULL;
    
#if EXAMPLE_PIN_NUM_BK_LIGHT >= 0
    ESP_LOGI(TAG, "Turn off LCD backlight");
    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << EXAMPLE_PIN_NUM_BK_LIGHT
    };
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));
#endif //EXAMPLE_PIN_NUM_BK_LIGHT

    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_rgb_panel_config_t panel_config = {
        .data_width = 16, // RGB565 in parallel mode, thus 16bit in width
        .psram_trans_align = 64,
        .num_fbs = EXAMPLE_LCD_NUM_FB,
#if CONFIG_EXAMPLE_USE_BOUNCE_BUFFER
        .bounce_buffer_size_px = 10 * EXAMPLE_LCD_H_RES,
#endif
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .disp_gpio_num = EXAMPLE_PIN_NUM_DISP_EN,
        .pclk_gpio_num = EXAMPLE_PIN_NUM_PCLK,
        .vsync_gpio_num = EXAMPLE_PIN_NUM_VSYNC,
        .hsync_gpio_num = EXAMPLE_PIN_NUM_HSYNC,
        .de_gpio_num = EXAMPLE_PIN_NUM_DE,
        .data_gpio_nums = {
            EXAMPLE_PIN_NUM_DATA0,
            EXAMPLE_PIN_NUM_DATA1,
            EXAMPLE_PIN_NUM_DATA2,
            EXAMPLE_PIN_NUM_DATA3,
            EXAMPLE_PIN_NUM_DATA4,
            EXAMPLE_PIN_NUM_DATA5,
            EXAMPLE_PIN_NUM_DATA6,
            EXAMPLE_PIN_NUM_DATA7,
            EXAMPLE_PIN_NUM_DATA8,
            EXAMPLE_PIN_NUM_DATA9,
            EXAMPLE_PIN_NUM_DATA10,
            EXAMPLE_PIN_NUM_DATA11,
            EXAMPLE_PIN_NUM_DATA12,
            EXAMPLE_PIN_NUM_DATA13,
            EXAMPLE_PIN_NUM_DATA14,
            EXAMPLE_PIN_NUM_DATA15,
        },
        .timings = {
            .pclk_hz = EXAMPLE_LCD_PIXEL_CLOCK_HZ,
            .h_res = EXAMPLE_LCD_H_RES,
            .v_res = EXAMPLE_LCD_V_RES,
            // The following parameters should refer to LCD spec
            .hsync_back_porch = 40,
            .hsync_front_porch = 40,
            .hsync_pulse_width = 48,
            .vsync_back_porch = 31,
            .vsync_front_porch = 13,
            .vsync_pulse_width = 1,
            .flags.pclk_active_neg = true,
        },
        .flags.fb_in_psram = true, // allocate frame buffer in PSRAM
    };
    ESP_LOGI(TAG, "Initialize RGB LCD panel");
    ESP_ERROR_CHECK(esp_lcd_new_rgb_panel(&panel_config, &panel_handle));

    ESP_LOGI(TAG, "Initialize RGB LCD panel");
    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));
#if EXAMPLE_PIN_NUM_BK_LIGHT >= 0

    printf("Turn on LCD backlight");
    gpio_set_level(EXAMPLE_PIN_NUM_BK_LIGHT, EXAMPLE_LCD_BK_LIGHT_ON_LEVEL);
#endif //EXAMPLE_PIN_NUM_BK_LIGHT

    ESP_LOGI(TAG, "Register event callbacks");
    esp_lcd_rgb_panel_event_callbacks_t cbs = {
        .on_vsync = example_on_vsync_event,
    };
    ESP_ERROR_CHECK(esp_lcd_rgb_panel_register_event_callbacks(panel_handle, &cbs, &display));
    ESP_LOGI(TAG, "Initialize LVGL library");
    lv_init();

    static uint16_t buf[EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES / 10];
    display = lv_display_create(EXAMPLE_LCD_H_RES,EXAMPLE_LCD_V_RES);
    lv_display_set_flush_cb(display,my_flush_cb);
    lv_display_set_buffers(display,buf,NULL,sizeof(buf),LV_DISPLAY_RENDER_MODE_PARTIAL);
    lv_display_set_user_data(display,&panel_handle);
    #endif
   
    // lv_port_disp_init();
   lv_task_handler();
   while(1){
    // vTaskDelay(portTICK_PERIOD_MS);
    // lv_timer_periodic_handler();
    // lv_task_handler();
    vTaskDelay(400/portTICK_PERIOD_MS);
   } 
   
   
   
   
    // #define ROW 10
    // #define COL 10
    // uint8_t color[2][ROW][COL] = {};
    // memset(color,0xf0,ROW*COL*2);
    // // for(int i=0 ; i<50 ; i++)
    // // {
    //     esp_lcd_panel_draw_bitmap(panel_handle,390,230,411,251,&color);    
    // // }
    
    // while(1)
    // vTaskDelay(1/);
    // esp_lcd_panel_disp_on_off(panel_handle,false);
}
