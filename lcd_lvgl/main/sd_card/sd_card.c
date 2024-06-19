
#include "sd_card.h"

void SdCardInit() {
    time_t seconds;
    
    seconds = time(NULL);
    printf("Seconds since January 1, 1970 = %lld\n", seconds);

    esp_err_t ret;

    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .max_files = 5,
        .allocation_unit_size = 4 * 1024
    };

    sdmmc_card_t *card = NULL;

    const char mount_point[] = MOUNT_POINT;

    sdmmc_host_t host = SDSPI_HOST_DEFAULT();

    spi_bus_config_t bus_cfg = {
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4096,
    };

    spi_bus_initialize(host.slot, &bus_cfg, SDSPI_DEFAULT_DMA);

    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = PIN_NUM_CS;
    slot_config.host_id = host.slot;

    ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            printf("Failed to mount filesystem\n");
        } else {
            printf("Failed to initialize the card (%s)\n", esp_err_to_name(ret));
        }
        return;
    }
    else
        printf("filesystem is mounted and sd card is initialized\n");
}