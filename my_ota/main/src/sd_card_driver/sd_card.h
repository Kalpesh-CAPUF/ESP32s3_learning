#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h> 
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define PIN_NUM_MISO  GPIO_NUM_13
#define PIN_NUM_MOSI  GPIO_NUM_11
#define PIN_NUM_CLK   GPIO_NUM_12
#define PIN_NUM_CS    GPIO_NUM_10

#define MOUNT_POINT "/sdcard"

esp_err_t sd_card_init(void);
esp_err_t sd_card_unmount(void);