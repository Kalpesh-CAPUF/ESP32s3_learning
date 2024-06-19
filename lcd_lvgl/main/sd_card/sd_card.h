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


#include <string.h>
#include <unistd.h>
#include <dirent.h> 
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"

#include <fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define PIN_NUM_MISO  GPIO_NUM_13
#define PIN_NUM_MOSI  GPIO_NUM_11
#define PIN_NUM_CLK   GPIO_NUM_12
#define PIN_NUM_CS    GPIO_NUM_10

#define MOUNT_POINT "/sdcard"

void SdCardInit();