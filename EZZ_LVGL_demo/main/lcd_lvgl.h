#ifndef LCD_LVGL_H
#define LCD_LVGL_H
#define LV_FONT_CUSTOM_DECLARE
#include <stdio.h>
#include <unistd.h>
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

#define EXAMPLE_LCD_PIXEL_CLOCK_HZ     (18 * 1000 * 1000)
#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL  1
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL !EXAMPLE_LCD_BK_LIGHT_ON_LEVEL
#define EXAMPLE_PIN_NUM_BK_LIGHT       2
#define EXAMPLE_PIN_NUM_HSYNC          39
#define EXAMPLE_PIN_NUM_VSYNC          40
#define EXAMPLE_PIN_NUM_DE             41
#define EXAMPLE_PIN_NUM_PCLK           0
#define EXAMPLE_PIN_NUM_DATA0          15 // B0
#define EXAMPLE_PIN_NUM_DATA1          7 // B1
#define EXAMPLE_PIN_NUM_DATA2          6 // B2
#define EXAMPLE_PIN_NUM_DATA3          5 // B3
#define EXAMPLE_PIN_NUM_DATA4          4 // B4
#define EXAMPLE_PIN_NUM_DATA5          9 // G0
#define EXAMPLE_PIN_NUM_DATA6          46 // G1
#define EXAMPLE_PIN_NUM_DATA7          3 // G2
#define EXAMPLE_PIN_NUM_DATA8          8 // G3
#define EXAMPLE_PIN_NUM_DATA9          16 // G4
#define EXAMPLE_PIN_NUM_DATA10         1 // G5
#define EXAMPLE_PIN_NUM_DATA11         14  // R0
#define EXAMPLE_PIN_NUM_DATA12         21  // R1
#define EXAMPLE_PIN_NUM_DATA13         47 // R2
#define EXAMPLE_PIN_NUM_DATA14         48 // R3
#define EXAMPLE_PIN_NUM_DATA15         45 // R4
#define EXAMPLE_PIN_NUM_DISP_EN        -1

// The pixel number in horizontal and vertical
#define EXAMPLE_LCD_H_RES              800
#define EXAMPLE_LCD_V_RES              480

#if CONFIG_EXAMPLE_DOUBLE_FB
#define EXAMPLE_LCD_NUM_FB             2
#else
#define EXAMPLE_LCD_NUM_FB             1
#endif // CONFIG_EXAMPLE_DOUBLE_FB

#define EXAMPLE_LVGL_TICK_PERIOD_MS    2
#define EXAMPLE_LVGL_TASK_MAX_DELAY_MS 500
#define EXAMPLE_LVGL_TASK_MIN_DELAY_MS 1
#define EXAMPLE_LVGL_TASK_STACK_SIZE   (4 * 1024)
#define EXAMPLE_LVGL_TASK_PRIORITY     2


static const char *TAG = "example";
void lv_port_disp_init(void);

#endif