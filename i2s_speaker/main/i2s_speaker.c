#include <stdio.h>
#include "wave.h"
#include "sd_card.h"
#include "driver/i2s.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "string.h"
#include <unistd.h>
#include <math.h>
#include "driver/gpio.h"




/* I2S parameter config*/
// #define SOUNDBOX_BITS_PER_SAMPLE    I2S_BITS_PER_SAMPLE_16BIT
// #define SOUNDBOX_BITS_PER_SAMPLE    I2S_BITS_PER_SAMPLE_24BIT
#define SOUNDBOX_BITS_PER_SAMPLE    I2S_BITS_PER_SAMPLE_32BIT 
// #define SOUNDBOX_BITS_PER_SAMPLE    I2S_BITS_PER_SAMPLE_8BIT

// #define SOUNDBOX_SAMPLE_RATE        44100
#define SOUNDBOX_SAMPLE_RATE        16000
#define SOUNDBOX_DMA_BUF_COUNT      8
#define SOUNDBOX_DMA_BUF_LENGTH     512

/* I2S GPIO config*/
#define SOUNDBOX_BCK_PIN        GPIO_NUM_42
#define SOUNDBOX_WS_PIN         GPIO_NUM_18
#define SOUNDBOX_DATAOUT_PIN    GPIO_NUM_17

// char buff[300*1024];
char *buff = NULL;


// function to reverse a string
void strrev(char* str)
{
    // if the string is empty
    if (!str) {
        return;
    }
    // pointer to start and end at the string
    int i = 0;
    int j = strlen(str) - 1;
 
    // reversing string
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

void app_main(void)
{
#if 0
    esp_err_t ret;

    static const int i2s_num = 0; // i2s port number

    static const i2s_config_t i2s_config = {
        .mode = I2S_MODE_MASTER | I2S_MODE_TX,
        .sample_rate = SOUNDBOX_SAMPLE_RATE,
        .bits_per_sample = SOUNDBOX_BITS_PER_SAMPLE,
        .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,
        .communication_format = I2S_COMM_FORMAT_STAND_I2S,
        .intr_alloc_flags = 0, // default interrupt priority
        .dma_buf_count = SOUNDBOX_DMA_BUF_COUNT,
        .dma_buf_len = SOUNDBOX_DMA_BUF_LENGTH,
        .use_apll = true
    };

    static const i2s_pin_config_t pin_config = {
        .bck_io_num = SOUNDBOX_BCK_PIN,
        .ws_io_num = SOUNDBOX_WS_PIN,
        .data_out_num = SOUNDBOX_DATAOUT_PIN,
        .data_in_num = I2S_PIN_NO_CHANGE
    };
    
    ret = i2s_driver_install(i2s_num, &i2s_config, 0, NULL);
    ret = i2s_set_pin(i2s_num, &pin_config);

    // ret = sd_card_init();

    
    size_t size;
    size_t i2s_bytes_write = 0;
    WaveFile * waveFp = NULL;

    char *num_array[10] = {};

    int nums[8] = {0,34,200,234,1000,1034,1200,1234};
    for(int kalp = 0 ; kalp<8 ; kalp++)
    {
        
        int num = nums[kalp];
        if(!num) continue;
        int i = 0;
        bool flag = true;
        while(num)
        {
            int j;
            if(flag){
                j = num%100;
                num = num/100;
                flag = false;
            }
            else{
                j = num%10;
                num = num/10;
            }
                char temp_str[5] = {};
                sprintf(temp_str,"%d",j);
                num_array[i] = malloc(3);
                strcpy(num_array[i],temp_str);
                printf("%d",j);
            i++;
        }
        num_array[i] = NULL;
        i--;
        printf("\n");

        // "payment recieved" audio
        char *pR = MOUNT_POINT"/PR.wav";
        waveFp = wave_open(pR,WAVE_OPEN_READ);
        size = wave_kalpesh_get_length(waveFp);
        wave_read(waveFp,buff,size);

        i2s_write(i2s_num, buff, size, &i2s_bytes_write, 100);
        wave_close(waveFp);


        while(i>=0)
        {
            char fileName[15] = MOUNT_POINT"/";
            printf("i= %d and %s\n",i,num_array[i]);
            if(!strcmp(num_array[i], "0")) { i--; continue;}
            // strcat(fileName,num_array[i]);
            char temp[50];

            int posix = pow(10,i+1);
            int x = atoi(num_array[i]);

            printf("filename = %s\n",fileName);
            printf("posix = %d\n",posix);
            printf("x = %d\n",x);

            if(posix <= 10)
            posix = 1;

            sprintf(temp,"%s%d%s",fileName,posix*x,".wav");
                // sprintf(temp,"%s%d%s",fileName,x,".wav");



            printf("file name = %s\n\n",temp);
            waveFp = wave_open(temp,WAVE_OPEN_READ);
            if(wave_err()->code != WAVE_OK) printf("error %s\n",wave_err()->message);
            size = wave_kalpesh_get_length(waveFp);
            wave_read(waveFp,buff,size);
            i2s_write(i2s_num, buff, size, &i2s_bytes_write, 100);
            wave_close(waveFp);

            i--;
        }
        char *rS = MOUNT_POINT"/RSONPTM.wav";
        waveFp = wave_open(rS,WAVE_OPEN_READ);
        size = wave_kalpesh_get_length(waveFp);
        wave_read(waveFp,buff,size);
        i2s_write(i2s_num, buff, size, &i2s_bytes_write, 100);
        wave_close(waveFp);
        sleep(2);
    }
#endif

#if 1
    size_t size_buf = 800*1024;
    buff = malloc(size_buf);
    esp_err_t ret;
    ret = sd_card_init();

    WaveFile * waveFp = NULL;
    size_t size;

    static const int i2s_num_rx = 1; // i2s rx port number

    // static const i2s_config_t i2s_config_rx = {
    //     .mode = I2S_MODE_RX,
    //     .sample_rate = SOUNDBOX_SAMPLE_RATE,
    //     .bits_per_sample = SOUNDBOX_BITS_PER_SAMPLE,
    //     .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,
    //     .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    //     .intr_alloc_flags = 0, // default interrupt priority
    //     .dma_buf_count = SOUNDBOX_DMA_BUF_COUNT,
    //     .dma_buf_len = SOUNDBOX_DMA_BUF_LENGTH,
    //     .use_apll = true
    // };

    static const i2s_config_t i2s_config_rx = {
        .mode = I2S_MODE_MASTER | I2S_MODE_RX,
        .sample_rate = SOUNDBOX_SAMPLE_RATE,
        .bits_per_sample = SOUNDBOX_BITS_PER_SAMPLE,   // here 32 bits used but actual is 24 bits(24 was causing white noise)
        .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT, // I2S_CHANNEL_FMT_RIGHT_LEFT //I2S_CHANNEL_FMT_ONLY_RIGHT //I2S_CHANNEL_FMT_ONLY_LEFT
        .communication_format = I2S_COMM_FORMAT_STAND_MSB,
        .intr_alloc_flags = 0, // default interrupt priority
        .dma_buf_count = SOUNDBOX_DMA_BUF_COUNT,
        .dma_buf_len = SOUNDBOX_DMA_BUF_LENGTH,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .bit_order_msb = true,
        // .big_edin = true,
        .left_align = true,
        // .use_apll = true,
    };
    // static const i2s_config_t i2s_config_rx = I2S_STD_MSB_SLOT_DEFAULT_CONFIG(I2S_BITS_PER_SAMPLE_24BIT,I2S_SLOT_MODE_MONO)
    static const i2s_pin_config_t pin_config_rx = {
        .bck_io_num = GPIO_NUM_19,
        .ws_io_num = GPIO_NUM_38,
        .data_out_num = I2S_PIN_NO_CHANGE,
        .data_in_num = GPIO_NUM_20
    };
    
    
    ret = i2s_driver_install(i2s_num_rx, &i2s_config_rx, 0, NULL);
    ret = i2s_set_pin(i2s_num_rx, &pin_config_rx);
    

    static const int i2s_num_tx = 0; // i2s tx port number
    static const i2s_config_t i2s_config_tx = {
        .mode = I2S_MODE_MASTER | I2S_MODE_TX,
        .sample_rate = SOUNDBOX_SAMPLE_RATE,
        .bits_per_sample = SOUNDBOX_BITS_PER_SAMPLE,
        .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,// I2S_CHANNEL_FMT_RIGHT_LEFT //I2S_CHANNEL_FMT_ONLY_RIGHT //I2S_CHANNEL_FMT_ONLY_LEFT
        .communication_format = I2S_COMM_FORMAT_STAND_MSB,
        .intr_alloc_flags = 0, // default interrupt priority
        .dma_buf_count = SOUNDBOX_DMA_BUF_COUNT,
        .dma_buf_len = SOUNDBOX_DMA_BUF_LENGTH,
        .bit_order_msb = true,
        .tx_desc_auto_clear = true,   // need to be true because iot was causing last chunk of data repeating
        // .big_edin = true,
        .left_align = true,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        // .use_apll = true
    };

    static const i2s_pin_config_t pin_config_tx = {
        .bck_io_num = SOUNDBOX_BCK_PIN,
        .ws_io_num = SOUNDBOX_WS_PIN,
        .data_out_num = SOUNDBOX_DATAOUT_PIN,
        .data_in_num = I2S_PIN_NO_CHANGE
    };

    
   
    ret = i2s_driver_install(i2s_num_tx, &i2s_config_tx, 0, NULL);
    ret = i2s_set_pin(i2s_num_tx, &pin_config_tx);
    


    size_t i2s_bytes_read = 0;
    printf("recoring audio\n");
    // i2s_read(i2s_num_rx,buff,sizeof(buff),&i2s_bytes_read,10);
    i2s_read(i2s_num_rx,buff,size_buf,&i2s_bytes_read,10);
    printf("recored bytes = %u\n",i2s_bytes_read);

//     for(size_t i = 0 ; i<sizeof(buff) ; i++){
//     printf("%x,", buff[i]);
//     vTaskDelay(2000 / portTICK_PERIOD_MS);

// }
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    printf("\nplaying recorded audio\n");
    size_t i2s_bytes_write = 0;
    // i2s_write(i2s_num_tx, buff, sizeof(buff), &i2s_bytes_write, 100);
    i2s_write(i2s_num_tx, buff, size_buf, &i2s_bytes_write, 100);
    printf("played bytes = %u\n",i2s_bytes_write);

    while(1)
    {
        printf("playing again...\n");
        i2s_bytes_write = 0;
        // i2s_start(i2s_num_tx);
        // i2s_write(i2s_num_tx, buff, sizeof(buff), &i2s_bytes_write, 10);
        i2s_write(i2s_num_tx, buff, size_buf, &i2s_bytes_write, 40);
        // i2s_stop(i2s_num_tx);
        
        printf("played bytes = %u\n",i2s_bytes_write);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }

    // i2s_driver_uninstall(i2s_num_tx);
    // char *rS = MOUNT_POINT"/test121.wav";

    // static const i2s_config_t i2s_config_tx2 = {
    //     .mode = I2S_MODE_MASTER | I2S_MODE_TX,
    //     .sample_rate = 44100,
    //     .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    //     .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,
    //     .communication_format = I2S_COMM_FORMAT_STAND_MSB,//I2S_COMM_FORMAT_STAND_I2S
    //     .intr_alloc_flags = 0, // default interrupt priority
    //     .dma_buf_count = SOUNDBOX_DMA_BUF_COUNT,
    //     .dma_buf_len = SOUNDBOX_DMA_BUF_LENGTH,
    //     // .use_apll = true
    // };

    // static const i2s_pin_config_t pin_config_tx2 = {
    //     .bck_io_num = SOUNDBOX_BCK_PIN,
    //     .ws_io_num = SOUNDBOX_WS_PIN,
    //     .data_out_num = SOUNDBOX_DATAOUT_PIN,
    //     .data_in_num = I2S_PIN_NO_CHANGE
    // };

    // ret = i2s_driver_install(i2s_num_tx, &i2s_config_tx2, 0, NULL);
    // ret = i2s_set_pin(i2s_num_tx, &pin_config_tx2);

    // while(1){
    //     printf("playing again...\n");
    //     waveFp = wave_open(rS,WAVE_OPEN_READ);
    //     size = wave_kalpesh_get_length(waveFp);
    //     wave_read(waveFp,buff,size);
    //     i2s_write(i2s_num_tx, buff, size, &i2s_bytes_write, 100);
    //     wave_close(waveFp);
    // }
#endif
}
