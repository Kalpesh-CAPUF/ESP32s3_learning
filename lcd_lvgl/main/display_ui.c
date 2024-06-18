#include "lcd_lvgl.h"
#define MOUNT_POINT "/sdcard"


#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_CAPUF
#define LV_ATTRIBUTE_IMG_CAPUF
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_CAPUF uint8_t capuf_map[] = {
  0x01, 0x01, 0x01, 0xff, 	/*Color of index 0*/
  0x00, 0x0b, 0x2a, 0xff, 	/*Color of index 1*/
  0x00, 0x04, 0x29, 0xff, 	/*Color of index 2*/
  0x00, 0x04, 0x21, 0xff, 	/*Color of index 3*/
  0x00, 0x02, 0x19, 0xff, 	/*Color of index 4*/
  0x00, 0x01, 0x11, 0xff, 	/*Color of index 5*/
  0x00, 0x01, 0x0a, 0xff, 	/*Color of index 6*/
  0x7a, 0xd4, 0xf0, 0xff, 	/*Color of index 7*/
  0x8b, 0xd2, 0xf0, 0xff, 	/*Color of index 8*/
  0x6d, 0xd3, 0xf3, 0xff, 	/*Color of index 9*/
  0x4b, 0xd1, 0xfd, 0xff, 	/*Color of index 10*/
  0x5d, 0xcf, 0xfb, 0xff, 	/*Color of index 11*/
  0x40, 0xd3, 0xf6, 0xff, 	/*Color of index 12*/
  0x5f, 0xd1, 0xf1, 0xff, 	/*Color of index 13*/
  0x6e, 0xd1, 0xeb, 0xff, 	/*Color of index 14*/
  0x4d, 0xd1, 0xf6, 0xff, 	/*Color of index 15*/
  0x43, 0xd0, 0xfb, 0xff, 	/*Color of index 16*/
  0x3a, 0xd1, 0xf8, 0xff, 	/*Color of index 17*/
  0x50, 0xcd, 0xfc, 0xff, 	/*Color of index 18*/
  0x88, 0xce, 0xe3, 0xff, 	/*Color of index 19*/
  0x6f, 0xcc, 0xf2, 0xff, 	/*Color of index 20*/
  0x2e, 0xd0, 0xf7, 0xff, 	/*Color of index 21*/
  0x48, 0xcc, 0xf9, 0xff, 	/*Color of index 22*/
  0x42, 0xcb, 0xfb, 0xff, 	/*Color of index 23*/
  0x3a, 0xcb, 0xfb, 0xff, 	/*Color of index 24*/
  0x51, 0xcb, 0xf3, 0xff, 	/*Color of index 25*/
  0x60, 0xc9, 0xf0, 0xff, 	/*Color of index 26*/
  0x3b, 0xcb, 0xf4, 0xff, 	/*Color of index 27*/
  0x23, 0xca, 0xfe, 0xff, 	/*Color of index 28*/
  0x35, 0xc9, 0xfb, 0xff, 	/*Color of index 29*/
  0x4c, 0xc9, 0xf3, 0xff, 	/*Color of index 30*/
  0x61, 0xcb, 0xe5, 0xff, 	/*Color of index 31*/
  0x33, 0xcb, 0xf4, 0xff, 	/*Color of index 32*/
  0x43, 0xc9, 0xf4, 0xff, 	/*Color of index 33*/
  0x43, 0xcb, 0xed, 0xff, 	/*Color of index 34*/
  0x2b, 0xc9, 0xfb, 0xff, 	/*Color of index 35*/
  0x0c, 0xca, 0xfe, 0xff, 	/*Color of index 36*/
  0x3b, 0xc6, 0xfb, 0xff, 	/*Color of index 37*/
  0x4a, 0xc8, 0xef, 0xff, 	/*Color of index 38*/
  0x71, 0xc6, 0xe8, 0xff, 	/*Color of index 39*/
  0x2c, 0xc9, 0xf5, 0xff, 	/*Color of index 40*/
  0x13, 0xc9, 0xfd, 0xff, 	/*Color of index 41*/
  0x54, 0xc7, 0xed, 0xff, 	/*Color of index 42*/
  0x1a, 0xc7, 0xfd, 0xff, 	/*Color of index 43*/
  0x26, 0xc8, 0xf4, 0xff, 	/*Color of index 44*/
  0x49, 0xc4, 0xf4, 0xff, 	/*Color of index 45*/
  0x41, 0xc4, 0xf6, 0xff, 	/*Color of index 46*/
  0x50, 0xc7, 0xe6, 0xff, 	/*Color of index 47*/
  0x3a, 0xc5, 0xf3, 0xff, 	/*Color of index 48*/
  0x1f, 0xc6, 0xf7, 0xff, 	/*Color of index 49*/
  0x0b, 0xc8, 0xf7, 0xff, 	/*Color of index 50*/
  0x32, 0xc3, 0xfa, 0xff, 	/*Color of index 51*/
  0x28, 0xc4, 0xfa, 0xff, 	/*Color of index 52*/
  0x80, 0xc3, 0xdd, 0xff, 	/*Color of index 53*/
  0x2b, 0xc5, 0xf2, 0xff, 	/*Color of index 54*/
  0x06, 0xc7, 0xf7, 0xff, 	/*Color of index 55*/
  0x10, 0xc6, 0xf5, 0xff, 	/*Color of index 56*/
  0x23, 0xc2, 0xfb, 0xff, 	/*Color of index 57*/
  0x13, 0xc3, 0xfc, 0xff, 	/*Color of index 58*/
  0x3d, 0xc4, 0xea, 0xff, 	/*Color of index 59*/
  0x06, 0xc5, 0xf9, 0xff, 	/*Color of index 60*/
  0x4e, 0xc1, 0xee, 0xff, 	/*Color of index 61*/
  0x1a, 0xc2, 0xfc, 0xff, 	/*Color of index 62*/
  0x30, 0xc2, 0xf4, 0xff, 	/*Color of index 63*/
  0x0d, 0xc3, 0xfb, 0xff, 	/*Color of index 64*/
  0x35, 0xc3, 0xec, 0xff, 	/*Color of index 65*/
  0x29, 0xbe, 0xff, 0xff, 	/*Color of index 66*/
  0x1d, 0xc4, 0xee, 0xff, 	/*Color of index 67*/
  0x3a, 0xc0, 0xf1, 0xff, 	/*Color of index 68*/
  0x62, 0xc0, 0xe2, 0xff, 	/*Color of index 69*/
  0x23, 0xc1, 0xf4, 0xff, 	/*Color of index 70*/
  0x32, 0xbd, 0xfa, 0xff, 	/*Color of index 71*/
  0x1c, 0xc1, 0xf4, 0xff, 	/*Color of index 72*/
  0x2b, 0xc1, 0xee, 0xff, 	/*Color of index 73*/
  0x4a, 0xc1, 0xe3, 0xff, 	/*Color of index 74*/
  0x21, 0xbe, 0xfb, 0xff, 	/*Color of index 75*/
  0x14, 0xc1, 0xf5, 0xff, 	/*Color of index 76*/
  0x0d, 0xc1, 0xf7, 0xff, 	/*Color of index 77*/
  0x42, 0xbf, 0xe9, 0xff, 	/*Color of index 78*/
  0x13, 0xbe, 0xfb, 0xff, 	/*Color of index 79*/
  0x40, 0xbd, 0xef, 0xff, 	/*Color of index 80*/
  0x22, 0xc0, 0xef, 0xff, 	/*Color of index 81*/
  0x1b, 0xbd, 0xfb, 0xff, 	/*Color of index 82*/
  0x34, 0xbd, 0xf1, 0xff, 	/*Color of index 83*/
  0x2a, 0xbe, 0xf1, 0xff, 	/*Color of index 84*/
  0x15, 0xbe, 0xf5, 0xff, 	/*Color of index 85*/
  0x0d, 0xbd, 0xfb, 0xff, 	/*Color of index 86*/
  0x62, 0xbd, 0xdd, 0xff, 	/*Color of index 87*/
  0x1c, 0xbd, 0xf4, 0xff, 	/*Color of index 88*/
  0x21, 0xbd, 0xf2, 0xff, 	/*Color of index 89*/
  0x11, 0xbf, 0xef, 0xff, 	/*Color of index 90*/
  0x3a, 0xbe, 0xe2, 0xff, 	/*Color of index 91*/
  0x21, 0xbd, 0xe9, 0xff, 	/*Color of index 92*/
  0x1a, 0xbc, 0xee, 0xff, 	/*Color of index 93*/
  0x0e, 0xbb, 0xf5, 0xff, 	/*Color of index 94*/
  0x52, 0xb9, 0xe2, 0xff, 	/*Color of index 95*/
  0x4c, 0xbb, 0xdd, 0xff, 	/*Color of index 96*/
  0x1d, 0xb8, 0xf7, 0xff, 	/*Color of index 97*/
  0x73, 0xba, 0xcf, 0xff, 	/*Color of index 98*/
  0x35, 0xba, 0xe3, 0xff, 	/*Color of index 99*/
  0x3c, 0xb7, 0xea, 0xff, 	/*Color of index 100*/
  0x32, 0xb8, 0xea, 0xff, 	/*Color of index 101*/
  0x27, 0xb8, 0xec, 0xff, 	/*Color of index 102*/
  0x7e, 0xb6, 0xd4, 0xff, 	/*Color of index 103*/
  0x41, 0xb8, 0xdf, 0xff, 	/*Color of index 104*/
  0x3e, 0xb6, 0xe5, 0xff, 	/*Color of index 105*/
  0x20, 0xb6, 0xea, 0xff, 	/*Color of index 106*/
  0x47, 0xb4, 0xe3, 0xff, 	/*Color of index 107*/
  0x53, 0xb4, 0xdc, 0xff, 	/*Color of index 108*/
  0x2a, 0xb5, 0xe5, 0xff, 	/*Color of index 109*/
  0x62, 0xb4, 0xd5, 0xff, 	/*Color of index 110*/
  0x44, 0xb4, 0xd7, 0xff, 	/*Color of index 111*/
  0x35, 0xb3, 0xdf, 0xff, 	/*Color of index 112*/
  0x1f, 0xb4, 0xdf, 0xff, 	/*Color of index 113*/
  0x52, 0xb3, 0xd1, 0xff, 	/*Color of index 114*/
  0x62, 0xb3, 0xca, 0xff, 	/*Color of index 115*/
  0x3a, 0xaf, 0xdb, 0xff, 	/*Color of index 116*/
  0x79, 0xaf, 0xc5, 0xff, 	/*Color of index 117*/
  0x4b, 0xaf, 0xd2, 0xff, 	/*Color of index 118*/
  0x1d, 0xac, 0xea, 0xff, 	/*Color of index 119*/
  0x32, 0xb0, 0xd3, 0xff, 	/*Color of index 120*/
  0x42, 0xae, 0xd4, 0xff, 	/*Color of index 121*/
  0x21, 0xad, 0xd8, 0xff, 	/*Color of index 122*/
  0x3d, 0xaa, 0xd7, 0xff, 	/*Color of index 123*/
  0x3d, 0xac, 0xcb, 0xff, 	/*Color of index 124*/
  0x53, 0xa8, 0xc7, 0xff, 	/*Color of index 125*/
  0x62, 0xa7, 0xc4, 0xff, 	/*Color of index 126*/
  0x30, 0xa8, 0xcf, 0xff, 	/*Color of index 127*/
  0x41, 0xa8, 0xc3, 0xff, 	/*Color of index 128*/
  0x2e, 0xa3, 0xd5, 0xff, 	/*Color of index 129*/
  0x6c, 0xa4, 0xba, 0xff, 	/*Color of index 130*/
  0x53, 0xa4, 0xc0, 0xff, 	/*Color of index 131*/
  0x35, 0xa4, 0xc7, 0xff, 	/*Color of index 132*/
  0x3d, 0xa0, 0xce, 0xff, 	/*Color of index 133*/
  0x25, 0xa3, 0xcc, 0xff, 	/*Color of index 134*/
  0x3f, 0xa2, 0xc1, 0xff, 	/*Color of index 135*/
  0x76, 0xa0, 0xb4, 0xff, 	/*Color of index 136*/
  0x54, 0xa0, 0xb7, 0xff, 	/*Color of index 137*/
  0x2d, 0x9e, 0xc9, 0xff, 	/*Color of index 138*/
  0x4d, 0x9d, 0xbe, 0xff, 	/*Color of index 139*/
  0x10, 0x9c, 0xca, 0xff, 	/*Color of index 140*/
  0x31, 0x9b, 0xbe, 0xff, 	/*Color of index 141*/
  0x61, 0x9a, 0xae, 0xff, 	/*Color of index 142*/
  0x1d, 0x9a, 0xc2, 0xff, 	/*Color of index 143*/
  0x28, 0x99, 0xc1, 0xff, 	/*Color of index 144*/
  0x24, 0x96, 0xc0, 0xff, 	/*Color of index 145*/
  0x62, 0x94, 0xaa, 0xff, 	/*Color of index 146*/
  0x09, 0x94, 0xc6, 0xff, 	/*Color of index 147*/
  0x31, 0x95, 0xb5, 0xff, 	/*Color of index 148*/
  0x4e, 0x93, 0xb1, 0xff, 	/*Color of index 149*/
  0x1b, 0x93, 0xb7, 0xff, 	/*Color of index 150*/
  0x3e, 0x90, 0xb3, 0xff, 	/*Color of index 151*/
  0x26, 0x8e, 0xbb, 0xff, 	/*Color of index 152*/
  0x40, 0x91, 0xa3, 0xff, 	/*Color of index 153*/
  0x13, 0x8d, 0xbb, 0xff, 	/*Color of index 154*/
  0x18, 0x8f, 0xb0, 0xff, 	/*Color of index 155*/
  0x34, 0x8e, 0xa5, 0xff, 	/*Color of index 156*/
  0x28, 0x8c, 0xac, 0xff, 	/*Color of index 157*/
  0x01, 0x8b, 0xbc, 0xff, 	/*Color of index 158*/
  0x51, 0x8a, 0xa4, 0xff, 	/*Color of index 159*/
  0x3b, 0x8a, 0xa9, 0xff, 	/*Color of index 160*/
  0x5d, 0x88, 0x9c, 0xff, 	/*Color of index 161*/
  0x5a, 0x86, 0xa1, 0xff, 	/*Color of index 162*/
  0x2e, 0x87, 0xab, 0xff, 	/*Color of index 163*/
  0x3f, 0x86, 0xa3, 0xff, 	/*Color of index 164*/
  0x04, 0x88, 0xad, 0xff, 	/*Color of index 165*/
  0x00, 0x82, 0xb8, 0xff, 	/*Color of index 166*/
  0x1a, 0x83, 0xaa, 0xff, 	/*Color of index 167*/
  0x07, 0x81, 0xac, 0xff, 	/*Color of index 168*/
  0x17, 0x81, 0xa1, 0xff, 	/*Color of index 169*/
  0x44, 0x7f, 0x96, 0xff, 	/*Color of index 170*/
  0x2b, 0x7d, 0x9c, 0xff, 	/*Color of index 171*/
  0x02, 0x7c, 0xa5, 0xff, 	/*Color of index 172*/
  0x36, 0x7f, 0x89, 0xff, 	/*Color of index 173*/
  0x19, 0x7b, 0x9b, 0xff, 	/*Color of index 174*/
  0x0b, 0x7c, 0x9c, 0xff, 	/*Color of index 175*/
  0x32, 0x79, 0x8f, 0xff, 	/*Color of index 176*/
  0x00, 0x74, 0xad, 0xff, 	/*Color of index 177*/
  0x26, 0x75, 0x99, 0xff, 	/*Color of index 178*/
  0x03, 0x76, 0x9f, 0xff, 	/*Color of index 179*/
  0x24, 0x75, 0x91, 0xff, 	/*Color of index 180*/
  0x41, 0x73, 0x8c, 0xff, 	/*Color of index 181*/
  0x14, 0x76, 0x90, 0xff, 	/*Color of index 182*/
  0x2c, 0x71, 0x90, 0xff, 	/*Color of index 183*/
  0x26, 0x75, 0x82, 0xff, 	/*Color of index 184*/
  0x05, 0x73, 0x92, 0xff, 	/*Color of index 185*/
  0x3c, 0x70, 0x83, 0xff, 	/*Color of index 186*/
  0x1a, 0x6f, 0x8f, 0xff, 	/*Color of index 187*/
  0x13, 0x70, 0x8c, 0xff, 	/*Color of index 188*/
  0x03, 0x6a, 0x97, 0xff, 	/*Color of index 189*/
  0x38, 0x66, 0x88, 0xff, 	/*Color of index 190*/
  0x13, 0x6a, 0x85, 0xff, 	/*Color of index 191*/
  0x02, 0x69, 0x8e, 0xff, 	/*Color of index 192*/
  0x34, 0x6a, 0x79, 0xff, 	/*Color of index 193*/
  0x27, 0x65, 0x83, 0xff, 	/*Color of index 194*/
  0x17, 0x65, 0x7c, 0xff, 	/*Color of index 195*/
  0x01, 0x63, 0x89, 0xff, 	/*Color of index 196*/
  0x0a, 0x64, 0x80, 0xff, 	/*Color of index 197*/
  0x12, 0x60, 0x83, 0xff, 	/*Color of index 198*/
  0x11, 0x60, 0x78, 0xff, 	/*Color of index 199*/
  0x05, 0x5f, 0x7e, 0xff, 	/*Color of index 200*/
  0x18, 0x5b, 0x76, 0xff, 	/*Color of index 201*/
  0x00, 0x59, 0x80, 0xff, 	/*Color of index 202*/
  0x28, 0x59, 0x70, 0xff, 	/*Color of index 203*/
  0x0f, 0x5b, 0x6c, 0xff, 	/*Color of index 204*/
  0x06, 0x57, 0x71, 0xff, 	/*Color of index 205*/
  0x00, 0x52, 0x74, 0xff, 	/*Color of index 206*/
  0x10, 0x51, 0x6f, 0xff, 	/*Color of index 207*/
  0x0b, 0x51, 0x69, 0xff, 	/*Color of index 208*/
  0x01, 0x51, 0x67, 0xff, 	/*Color of index 209*/
  0x00, 0x4b, 0x74, 0xff, 	/*Color of index 210*/
  0x16, 0x4e, 0x61, 0xff, 	/*Color of index 211*/
  0x00, 0x4d, 0x61, 0xff, 	/*Color of index 212*/
  0x00, 0x4a, 0x69, 0xff, 	/*Color of index 213*/
  0x0a, 0x4a, 0x63, 0xff, 	/*Color of index 214*/
  0x20, 0x48, 0x5f, 0xff, 	/*Color of index 215*/
  0x1a, 0x49, 0x55, 0xff, 	/*Color of index 216*/
  0x07, 0x46, 0x64, 0xff, 	/*Color of index 217*/
  0x02, 0x46, 0x5c, 0xff, 	/*Color of index 218*/
  0x01, 0x41, 0x60, 0xff, 	/*Color of index 219*/
  0x0d, 0x42, 0x57, 0xff, 	/*Color of index 220*/
  0x00, 0x3d, 0x5a, 0xff, 	/*Color of index 221*/
  0x0b, 0x3b, 0x53, 0xff, 	/*Color of index 222*/
  0x00, 0x3b, 0x4b, 0xff, 	/*Color of index 223*/
  0x00, 0x38, 0x55, 0xff, 	/*Color of index 224*/
  0x00, 0x33, 0x59, 0xff, 	/*Color of index 225*/
  0x00, 0x33, 0x4a, 0xff, 	/*Color of index 226*/
  0x00, 0x2e, 0x53, 0xff, 	/*Color of index 227*/
  0x00, 0x2e, 0x41, 0xff, 	/*Color of index 228*/
  0x00, 0x2b, 0x4b, 0xff, 	/*Color of index 229*/
  0x13, 0x2c, 0x38, 0xff, 	/*Color of index 230*/
  0x00, 0x2c, 0x3b, 0xff, 	/*Color of index 231*/
  0x00, 0x25, 0x52, 0xff, 	/*Color of index 232*/
  0x00, 0x25, 0x47, 0xff, 	/*Color of index 233*/
  0x00, 0x24, 0x42, 0xff, 	/*Color of index 234*/
  0x00, 0x23, 0x3a, 0xff, 	/*Color of index 235*/
  0x00, 0x23, 0x33, 0xff, 	/*Color of index 236*/
  0x00, 0x1e, 0x41, 0xff, 	/*Color of index 237*/
  0x00, 0x1a, 0x3a, 0xff, 	/*Color of index 238*/
  0x00, 0x1a, 0x32, 0xff, 	/*Color of index 239*/
  0x00, 0x1b, 0x2b, 0xff, 	/*Color of index 240*/
  0x00, 0x14, 0x3c, 0xff, 	/*Color of index 241*/
  0x00, 0x12, 0x34, 0xff, 	/*Color of index 242*/
  0x00, 0x12, 0x2b, 0xff, 	/*Color of index 243*/
  0x00, 0x14, 0x1f, 0xff, 	/*Color of index 244*/
  0x00, 0x0d, 0x1b, 0xff, 	/*Color of index 245*/
  0x00, 0x0a, 0x21, 0xff, 	/*Color of index 246*/
  0x00, 0x08, 0x12, 0xff, 	/*Color of index 247*/
  0x01, 0x06, 0x09, 0xff, 	/*Color of index 248*/
  0x3e, 0x8f, 0x98, 0xff, 	/*Color of index 249*/
  0x02, 0x0a, 0x03, 0xff, 	/*Color of index 250*/
  0x08, 0x09, 0x04, 0xff, 	/*Color of index 251*/
  0x0b, 0x08, 0x09, 0xff, 	/*Color of index 252*/
  0x14, 0x07, 0x06, 0xff, 	/*Color of index 253*/
  0x08, 0x00, 0x02, 0xff, 	/*Color of index 254*/
  0x08, 0x02, 0x08, 0xff, 	/*Color of index 255*/

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xfa, 0x00, 0xfa, 0xfe, 0xfe, 0xfe, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0x00, 0xfa, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0xfb, 0x06, 0xbb, 0x2d, 0x42, 0x3e, 0x3c, 0x37, 0x29, 0x3e, 0x3e, 0x3e, 0x4f, 0x4f, 0x4d, 0x32, 0x31, 0x3e, 0x3a, 0x2b, 0x29, 0x4f, 0x3e, 0x52, 0x3e, 0x40, 0x2b, 0x3c, 0x2b, 0x4d, 0x2b, 0x40, 0x3a, 0x40, 0x29, 0x3c, 0x40, 0x3a, 0x4f, 0x2b, 0x4f, 0x29, 0x40, 0x29, 0x37, 0x38, 0x2b, 0x3e, 0x4d, 0x29, 0x2b, 0x4f, 0x3a, 0x2b, 0x4f, 0x4f, 0x3a, 0x2b, 0x3a, 0x3a, 0x3a, 0x3a, 
  0xf8, 0x00, 0x00, 0xfb, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfe, 0xfe, 0xfd, 0x00, 0xfa, 0x00, 0xfe, 0xfe, 0xff, 0xff, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0xfa, 0x00, 0x06, 0xbb, 0x12, 0x61, 0x4f, 0x24, 0x37, 0x3a, 0x4f, 0x3e, 0x3e, 0x4f, 0x3a, 0x29, 0x29, 0x2b, 0x4d, 0x4f, 0x3a, 0x40, 0x29, 0x4f, 0x3e, 0x3e, 0x2b, 0x29, 0x4d, 0x4f, 0x2b, 0x40, 0x29, 0x3a, 0x2b, 0x4d, 0x29, 0x3a, 0x3a, 0x3e, 0x3a, 0x1c, 0x40, 0x3a, 0x40, 0x29, 0x38, 0x4f, 0x3e, 0x29, 0x4d, 0x3a, 0x2b, 0x3e, 0x56, 0x3e, 0x3a, 0x3a, 0x40, 0x3a, 0x29, 0x4f, 0x29, 
  0x00, 0x00, 0xfe, 0x00, 0xff, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0xf8, 0x00, 0x00, 0xff, 0xfe, 0x06, 0xf8, 0xff, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x06, 0xbc, 0x12, 0x61, 0x2b, 0x3a, 0x38, 0x3e, 0x2b, 0x3a, 0x2b, 0x4d, 0x40, 0x3a, 0x4f, 0x40, 0x2b, 0x2b, 0x29, 0x29, 0x3a, 0x56, 0x52, 0x3a, 0x3a, 0x29, 0x2b, 0x3e, 0x4f, 0x3a, 0x40, 0x3a, 0x3a, 0x48, 0x2b, 0x56, 0x2b, 0x52, 0x4f, 0x3e, 0x3a, 0x3a, 0x56, 0x39, 0x34, 0x3e, 0x40, 0x29, 0x3c, 0x3a, 0x3e, 0x40, 0x2b, 0x40, 0x40, 0x38, 0x3a, 0x4f, 0x2b, 0x3a, 0x2b, 
  0xf8, 0x00, 0xfe, 0xfe, 0xff, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x05, 0x05, 0x05, 0x06, 0x06, 0x00, 0x00, 0xff, 0x05, 0x06, 0x06, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0x06, 0x06, 0x06, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xbc, 0x21, 0x3e, 0x3a, 0x4f, 0x1c, 0x4f, 0x58, 0x46, 0x28, 0x36, 0x23, 0x39, 0x2b, 0x4f, 0x3a, 0x56, 0x3a, 0x38, 0x43, 0x34, 0x23, 0x2b, 0x2b, 0x5a, 0x3a, 0x39, 0x42, 0x39, 0x23, 0x33, 0x3f, 0x25, 0x34, 0x52, 0x3a, 0x39, 0x23, 0x39, 0x3e, 0x4f, 0x2b, 0x39, 0x61, 0x34, 0x34, 0x3a, 0x4f, 0x39, 0x34, 0x2c, 0x23, 0x51, 0x23, 0x23, 0x34, 0x2b, 0x4f, 0x2b, 0x3a, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x06, 0x05, 0xf6, 0xef, 0xef, 0xf6, 0x05, 0x06, 0x00, 0xf8, 0xfe, 0xfe, 0x06, 0xf7, 0x05, 0x06, 0xf5, 0xec, 0xeb, 0xec, 0xf6, 0x05, 0x06, 0x00, 0xff, 0x00, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x06, 0xb6, 0x16, 0x39, 0x3a, 0x3a, 0x5a, 0x1c, 0x18, 0x26, 0x7b, 0x7c, 0x6f, 0x3b, 0x25, 0x3e, 0x4f, 0x3a, 0x4f, 0x36, 0x41, 0x60, 0x63, 0x31, 0x4d, 0x29, 0x55, 0x33, 0x53, 0x74, 0x5f, 0x6c, 0x5f, 0x68, 0x0f, 0x43, 0x31, 0x46, 0x6d, 0x6d, 0x36, 0x2b, 0x40, 0x42, 0x33, 0x69, 0x70, 0x54, 0x33, 0x4e, 0x68, 0x6f, 0x60, 0x4a, 0x5f, 0x79, 0x64, 0x54, 0x2b, 0x4f, 0x3e, 
  0xfe, 0x00, 0x00, 0x00, 0xfc, 0x06, 0x06, 0xf0, 0xc9, 0x99, 0x72, 0x72, 0x6c, 0x72, 0x9c, 0xc7, 0xf0, 0xf8, 0x06, 0xf8, 0x06, 0x05, 0xdf, 0xb4, 0x80, 0x6f, 0x60, 0x60, 0x76, 0xa0, 0xd6, 0xf5, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x06, 0xb6, 0x22, 0x58, 0x2b, 0x3e, 0x31, 0x30, 0x96, 0xdd, 0xef, 0x04, 0xf2, 0xdb, 0x91, 0x33, 0x3e, 0x56, 0x23, 0x68, 0xe2, 0xf0, 0xdf, 0x65, 0x1c, 0x3a, 0x1c, 0x63, 0xe1, 0xed, 0xee, 0xee, 0xf1, 0xe2, 0xd5, 0x70, 0x22, 0x70, 0xe3, 0xea, 0x96, 0x15, 0x4d, 0x39, 0x6d, 0xdb, 0xee, 0xac, 0x12, 0xca, 0xf3, 0xee, 0xeb, 0xf3, 0xf2, 0xe9, 0xf1, 0x9e, 0x1c, 0x55, 0x3e, 
  0xfe, 0xfe, 0x00, 0x00, 0x06, 0x05, 0xce, 0x6f, 0x16, 0x25, 0x28, 0x41, 0x20, 0x30, 0x18, 0x22, 0x6f, 0xd1, 0x05, 0x05, 0xf6, 0xab, 0x50, 0x10, 0x36, 0x18, 0x43, 0x51, 0x1d, 0x16, 0x3b, 0x84, 0xe2, 0xf5, 0x06, 0xf8, 0xfe, 0x00, 0x00, 0x06, 0xbc, 0x0f, 0x48, 0x3e, 0x48, 0x21, 0xb2, 0x01, 0x04, 0x04, 0xef, 0x04, 0x05, 0x02, 0x93, 0x39, 0x3e, 0x25, 0xab, 0x05, 0xf8, 0x05, 0xa7, 0x25, 0x58, 0x34, 0x4a, 0xeb, 0x05, 0x05, 0x04, 0x03, 0x05, 0xf7, 0xec, 0x6e, 0x6c, 0x02, 0x03, 0x94, 0x28, 0x38, 0x1c, 0x4e, 0xeb, 0x05, 0xb9, 0x0d, 0xda, 0x04, 0xf7, 0x05, 0xf7, 0x04, 0x04, 0x02, 0xa6, 0x1c, 0x3e, 0x3e, 
  0xfe, 0xfe, 0xfb, 0x00, 0xf7, 0xb5, 0x0d, 0x3f, 0x55, 0x3e, 0x43, 0x2c, 0x36, 0x43, 0x46, 0x48, 0x36, 0x2a, 0xb7, 0xeb, 0x87, 0x19, 0x3f, 0x52, 0x58, 0x23, 0x28, 0x28, 0x48, 0x48, 0x31, 0x20, 0x4a, 0xd0, 0x05, 0x06, 0x00, 0x00, 0x00, 0x05, 0xbc, 0x0f, 0x58, 0x3e, 0x18, 0x90, 0x02, 0x04, 0xdd, 0x89, 0x72, 0x83, 0xe0, 0xce, 0x65, 0x39, 0x46, 0x26, 0xde, 0x06, 0x00, 0x06, 0xdb, 0x2d, 0x34, 0x36, 0x60, 0xe7, 0x05, 0xba, 0x7d, 0x8b, 0xba, 0xf0, 0x06, 0xc1, 0x67, 0xf2, 0x04, 0xa0, 0x18, 0x3a, 0x55, 0x4e, 0xe7, 0xf8, 0xb6, 0x09, 0xd7, 0x05, 0xdc, 0x82, 0x89, 0x89, 0x95, 0x85, 0x66, 0x2b, 0x3e, 0x2b, 
  0x00, 0xff, 0xfe, 0x00, 0xf8, 0xa2, 0x19, 0x54, 0x39, 0x25, 0x21, 0x4a, 0x4a, 0x16, 0x1d, 0x52, 0x39, 0x46, 0x1e, 0x9b, 0x64, 0x3f, 0x42, 0x47, 0x2d, 0x6f, 0x87, 0x79, 0x26, 0x1d, 0x31, 0x48, 0x30, 0x2a, 0xdb, 0x05, 0x00, 0xfb, 0x00, 0x06, 0xbc, 0x0f, 0x4c, 0x46, 0x2e, 0xd5, 0x04, 0xe4, 0x60, 0x21, 0x3f, 0x17, 0x54, 0x49, 0x23, 0x58, 0x17, 0x8d, 0xf6, 0x05, 0xe6, 0xf7, 0xf5, 0x87, 0x1d, 0x46, 0x2f, 0xeb, 0x04, 0x9f, 0x19, 0x2d, 0x07, 0xdc, 0x05, 0xd7, 0x67, 0x01, 0x04, 0x97, 0x1d, 0x52, 0x1c, 0x5b, 0xe7, 0x06, 0xb6, 0x07, 0xd7, 0x04, 0xcb, 0x08, 0x1f, 0x09, 0x1a, 0x12, 0x34, 0x3e, 0x3e, 0x3e, 
  0x00, 0x00, 0x00, 0xf8, 0x06, 0xf6, 0x9d, 0x19, 0x2d, 0x90, 0xd9, 0xe9, 0xea, 0xd5, 0x8a, 0x25, 0x39, 0x3e, 0x46, 0x71, 0x9e, 0x3f, 0x25, 0x74, 0xce, 0xed, 0xf6, 0xf0, 0xe0, 0x90, 0x21, 0x59, 0x2b, 0x3f, 0x72, 0xef, 0x00, 0x00, 0xfc, 0x05, 0xb6, 0x41, 0x31, 0x34, 0x6b, 0xee, 0x05, 0xb8, 0x0d, 0x55, 0x34, 0x56, 0x38, 0x24, 0x3a, 0x39, 0x2d, 0xc8, 0x05, 0xf0, 0x88, 0xf0, 0x05, 0xc3, 0x11, 0x5c, 0x60, 0xea, 0x04, 0xb5, 0x1a, 0x6b, 0x95, 0xeb, 0xf6, 0xcb, 0x67, 0xef, 0x04, 0x97, 0x25, 0x4b, 0x3a, 0x5b, 0xec, 0xf8, 0xb6, 0x14, 0xd7, 0x05, 0xeb, 0xcd, 0xcd, 0xcd, 0xd2, 0xbd, 0x34, 0x3a, 0x2b, 0x3a, 
  0x00, 0xfa, 0x00, 0x00, 0x00, 0xf7, 0x04, 0x92, 0xaa, 0x03, 0x06, 0x06, 0x06, 0x05, 0xf3, 0xa3, 0x30, 0x1c, 0x3e, 0x31, 0x9e, 0x7f, 0x72, 0xe2, 0x05, 0x06, 0x06, 0x06, 0x04, 0x01, 0xa3, 0x0a, 0x48, 0x4b, 0x0b, 0xbf, 0xff, 0xf8, 0xf8, 0x06, 0xbc, 0x1b, 0x58, 0x18, 0x7b, 0xf2, 0xf7, 0xf9, 0x22, 0x48, 0x52, 0x2b, 0x32, 0x32, 0x4c, 0x33, 0x6c, 0xed, 0x05, 0xcb, 0x13, 0xd0, 0x05, 0xeb, 0x5b, 0x20, 0x5f, 0xe5, 0x05, 0xf4, 0xf0, 0xe7, 0xf5, 0x05, 0xf6, 0x83, 0x6e, 0xf3, 0xf7, 0x99, 0x25, 0x52, 0x1c, 0x3b, 0xe7, 0x06, 0xb6, 0x07, 0xd8, 0x06, 0x05, 0x05, 0x05, 0x04, 0x04, 0xe9, 0x3f, 0x3a, 0x3a, 0x3a, 
  0xf8, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x06, 0xf4, 0xf8, 0x00, 0xfc, 0x00, 0x00, 0xf7, 0x06, 0xf6, 0x86, 0x34, 0x4c, 0x46, 0x7a, 0x9b, 0xd4, 0xf8, 0x06, 0x06, 0x06, 0x05, 0x05, 0x04, 0x01, 0x81, 0x34, 0x4f, 0x3f, 0x80, 0xf4, 0x00, 0x00, 0x05, 0xbb, 0x16, 0x31, 0x59, 0x3d, 0xe5, 0x05, 0xcc, 0x0d, 0x51, 0x33, 0x58, 0x2c, 0x15, 0x2c, 0x21, 0xab, 0x04, 0x04, 0xa1, 0x62, 0xa4, 0x05, 0x04, 0xa9, 0x22, 0x5f, 0xed, 0x05, 0x06, 0xf7, 0x05, 0x03, 0xe2, 0x9d, 0x2a, 0x76, 0xef, 0xf8, 0xf9, 0x0a, 0x66, 0x46, 0x60, 0xf0, 0x05, 0xae, 0x09, 0xd8, 0xf8, 0xe2, 0xaa, 0xb0, 0xb0, 0xb4, 0x9d, 0x36, 0x3a, 0x2b, 0x3a, 
  0x00, 0xf8, 0x00, 0xfe, 0x00, 0xff, 0x00, 0x00, 0xf8, 0x00, 0x00, 0xfb, 0xff, 0x00, 0x00, 0x04, 0xce, 0x30, 0x2b, 0x1c, 0x63, 0xb9, 0xd1, 0xd1, 0xd1, 0xd1, 0xd6, 0xd5, 0xd1, 0xd5, 0xd2, 0x9a, 0x23, 0x52, 0x30, 0x4a, 0xe4, 0x00, 0x00, 0x05, 0xbb, 0x1e, 0x51, 0x31, 0x16, 0xca, 0x04, 0xf3, 0x97, 0x0b, 0x2d, 0x12, 0x8d, 0x7c, 0x3b, 0x2f, 0xdf, 0x06, 0x05, 0xf7, 0xf5, 0xf8, 0x06, 0x06, 0xdb, 0x14, 0x6c, 0xea, 0xf7, 0xc1, 0x80, 0x90, 0x81, 0x64, 0x10, 0x3f, 0x1e, 0xe0, 0x05, 0xd8, 0x1f, 0x26, 0x0d, 0xa4, 0x04, 0x04, 0x84, 0x19, 0xd3, 0x05, 0xc9, 0x09, 0x19, 0x1b, 0x10, 0x36, 0x3e, 0x3a, 0x3a, 0x3a, 
  0x00, 0x06, 0xff, 0xfe, 0xff, 0x00, 0x00, 0xfa, 0x00, 0xfa, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x06, 0xd1, 0x17, 0x39, 0x48, 0x44, 0xac, 0x2f, 0x1f, 0x2f, 0x19, 0x19, 0x26, 0x22, 0x22, 0x16, 0x33, 0x39, 0x3e, 0x31, 0x26, 0xdc, 0xf8, 0x00, 0x05, 0xbb, 0x12, 0x31, 0x5a, 0x23, 0x68, 0xe9, 0x04, 0xf2, 0xc6, 0xa3, 0xca, 0xf3, 0xf0, 0x78, 0x80, 0xf7, 0x05, 0xef, 0xeb, 0xec, 0xec, 0xf4, 0x05, 0x03, 0x8b, 0x27, 0xea, 0x05, 0x99, 0x22, 0x23, 0x39, 0x39, 0x61, 0x4b, 0x36, 0xa9, 0x04, 0x05, 0xda, 0x9c, 0xc3, 0xf3, 0x04, 0xe1, 0x50, 0x1e, 0xd0, 0x04, 0xce, 0x1e, 0x5d, 0x3a, 0x2b, 0x4d, 0x3a, 0x3a, 0x3a, 0x3a, 
  0xf8, 0x00, 0xfe, 0xfe, 0x00, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0xfa, 0x06, 0xc7, 0x19, 0x51, 0x3e, 0x18, 0x9e, 0x7a, 0x36, 0x46, 0x59, 0x46, 0x51, 0x43, 0x43, 0x46, 0x48, 0x4c, 0x32, 0x5a, 0x22, 0xd3, 0xfe, 0xf7, 0x05, 0xbb, 0x16, 0x5a, 0x24, 0x32, 0x30, 0x7b, 0xe3, 0x04, 0x05, 0x04, 0x05, 0xf6, 0xe5, 0x79, 0xce, 0x05, 0xef, 0x76, 0x69, 0x64, 0x4a, 0x7d, 0xf3, 0xf6, 0xcd, 0x45, 0xee, 0x04, 0xa9, 0x0c, 0x5a, 0x58, 0x3e, 0x3e, 0x2b, 0x34, 0x44, 0xc8, 0xf7, 0x05, 0x05, 0xf7, 0x05, 0xe5, 0x7b, 0x33, 0x1d, 0xd5, 0x04, 0xce, 0x2e, 0x2b, 0x4d, 0x4f, 0x1c, 0x3a, 0x3a, 0x3a, 0x3a, 
  0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xfe, 0xfe, 0x00, 0x00, 0xcd, 0x22, 0x34, 0x31, 0x47, 0xa6, 0x41, 0x17, 0x17, 0x25, 0x17, 0x21, 0x0c, 0x1b, 0x1b, 0x18, 0x11, 0x18, 0x11, 0x0d, 0xd8, 0x06, 0xff, 0x06, 0xbb, 0x1b, 0x2b, 0x32, 0x38, 0x31, 0x30, 0x4a, 0xab, 0xd4, 0xdd, 0xd0, 0xab, 0x4a, 0x3d, 0xb3, 0xcd, 0xa3, 0x30, 0x34, 0x2b, 0x47, 0x30, 0xa9, 0xce, 0xae, 0x5f, 0xb3, 0xca, 0x86, 0x43, 0x2b, 0x2b, 0x3e, 0x3e, 0x52, 0x3e, 0x34, 0x26, 0x9d, 0xcd, 0xdc, 0xda, 0xb4, 0x68, 0x18, 0x55, 0x34, 0x9d, 0xce, 0x9a, 0x1d, 0x4f, 0x3a, 0x2b, 0x5e, 0x3e, 0x3a, 0x3a, 0x3a, 
  0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0xf8, 0x00, 0xfa, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x05, 0xcd, 0x3b, 0x23, 0x4b, 0x30, 0xc4, 0xd5, 0xcd, 0xd0, 0xcf, 0xcf, 0xd0, 0xcc, 0xda, 0xcc, 0xd0, 0xcf, 0xd9, 0xd0, 0xd3, 0xf4, 0x00, 0xf8, 0x06, 0xbc, 0x0a, 0x58, 0x2b, 0x3a, 0x4c, 0x34, 0x44, 0x16, 0x12, 0x2d, 0x21, 0x10, 0x44, 0x28, 0x18, 0x17, 0x1b, 0x31, 0x3e, 0x4b, 0x39, 0x46, 0x1c, 0x18, 0x18, 0x47, 0x25, 0x10, 0x36, 0x31, 0x4f, 0x29, 0x4f, 0x3a, 0x2b, 0x31, 0x2c, 0x34, 0x18, 0x18, 0x21, 0x17, 0x18, 0x36, 0x23, 0x4c, 0x31, 0x1d, 0x18, 0x23, 0x52, 0x3a, 0x4f, 0x1c, 0x3e, 0x23, 0x52, 0x2b, 0x29, 
  0x00, 0x00, 0x00, 0xfe, 0x06, 0x06, 0x06, 0x06, 0x06, 0xf8, 0xfa, 0x00, 0x00, 0xf7, 0x06, 0xe2, 0x9d, 0x71, 0x34, 0x48, 0x18, 0xaf, 0x04, 0x05, 0x06, 0x05, 0x05, 0x06, 0x05, 0xf5, 0x05, 0x03, 0x03, 0x03, 0xf7, 0xf7, 0xf7, 0x00, 0x00, 0x00, 0xb6, 0x21, 0x59, 0x2b, 0x1c, 0x31, 0x6d, 0x44, 0x64, 0x65, 0x59, 0x34, 0x5d, 0x5a, 0x31, 0x51, 0x46, 0x59, 0x4c, 0x23, 0x66, 0x66, 0x39, 0x48, 0x4c, 0x3a, 0x52, 0x42, 0x55, 0x46, 0x4c, 0x2b, 0x4f, 0x3e, 0x3e, 0x39, 0x49, 0x71, 0x55, 0x3e, 0x55, 0x46, 0x66, 0x6a, 0x5d, 0x31, 0x31, 0x31, 0x48, 0x52, 0x5e, 0x2b, 0x39, 0x58, 0x51, 0x6a, 0x6a, 0x23, 0x2b, 0x40, 
  0x00, 0xfb, 0xfe, 0xfe, 0x05, 0x05, 0xdc, 0xb0, 0x05, 0x06, 0x00, 0x00, 0xf8, 0x00, 0x03, 0x87, 0x74, 0x93, 0x2b, 0x3e, 0x39, 0x26, 0xd5, 0x05, 0x06, 0x06, 0xf7, 0x06, 0xec, 0x83, 0x76, 0x7f, 0x86, 0x84, 0x72, 0xba, 0x06, 0x06, 0xfc, 0x06, 0xbc, 0x1b, 0x48, 0x31, 0x2c, 0xa5, 0xee, 0xe9, 0xe9, 0xf1, 0xc4, 0x17, 0x1d, 0x15, 0x23, 0x23, 0x33, 0x25, 0x1c, 0x28, 0x9a, 0xe3, 0x63, 0x18, 0x15, 0x48, 0x2b, 0x46, 0x2c, 0x11, 0x31, 0x3e, 0x39, 0x39, 0x33, 0x0a, 0xa7, 0xe1, 0x53, 0x34, 0x20, 0x16, 0x6b, 0xe8, 0x8c, 0x36, 0x2c, 0x23, 0x15, 0x48, 0x2b, 0x39, 0x3f, 0x12, 0x2a, 0xe3, 0x9e, 0x23, 0x3e, 0x4d, 
  0x00, 0x00, 0xfb, 0x00, 0x06, 0xde, 0x45, 0x1a, 0xab, 0xeb, 0xf7, 0xf8, 0xf7, 0xe7, 0x8d, 0x2d, 0x53, 0xa6, 0x6a, 0x2b, 0x46, 0x3f, 0x5f, 0xc6, 0xf3, 0x06, 0x05, 0x05, 0xea, 0x84, 0x21, 0x23, 0x23, 0x0c, 0x45, 0xe4, 0x05, 0xff, 0xfe, 0x00, 0xbc, 0x0f, 0x48, 0x4c, 0x0c, 0xb9, 0xef, 0xa2, 0xa2, 0xa0, 0x90, 0x70, 0x8f, 0x8f, 0xac, 0x70, 0x7b, 0xb1, 0x86, 0x0f, 0xa9, 0xed, 0x7c, 0xaf, 0x8f, 0x30, 0x41, 0x1b, 0x96, 0xaf, 0x7a, 0x30, 0x3f, 0x50, 0xa6, 0x94, 0xb4, 0xee, 0x4e, 0x44, 0x8f, 0xae, 0x8b, 0xf2, 0x9a, 0x0f, 0x78, 0xa9, 0xa5, 0x1b, 0x44, 0x30, 0x8a, 0xae, 0x8b, 0xe9, 0xb3, 0x1d, 0x31, 0x3a, 
  0xf7, 0x00, 0x00, 0xf8, 0xdf, 0x72, 0x3b, 0x47, 0x17, 0x70, 0xa7, 0xa9, 0x9b, 0x3b, 0x1d, 0x42, 0x42, 0x77, 0x93, 0x1d, 0x46, 0x34, 0x3f, 0x2e, 0x7f, 0x9b, 0xaf, 0x96, 0x7a, 0x3f, 0x4b, 0x48, 0x5a, 0x22, 0xb4, 0x05, 0x06, 0x00, 0x00, 0xf8, 0xbc, 0x0a, 0x5a, 0x48, 0x0f, 0xc0, 0xef, 0x88, 0x82, 0x8b, 0x2a, 0x96, 0x01, 0xe2, 0xec, 0xeb, 0xdb, 0xe8, 0xf1, 0x7e, 0x99, 0xf5, 0xe3, 0xe1, 0x01, 0xae, 0x0d, 0xc8, 0xef, 0xe2, 0xe9, 0x95, 0x45, 0xe0, 0xee, 0xdd, 0xeb, 0xe7, 0x27, 0xb6, 0x01, 0xe0, 0xe9, 0x03, 0x89, 0x7c, 0xeb, 0xe2, 0xea, 0xcd, 0x14, 0xa9, 0x01, 0xe2, 0xdf, 0x03, 0xa8, 0x10, 0x58, 0x31, 
  0x00, 0x06, 0x00, 0xf8, 0xad, 0x0e, 0x41, 0x48, 0x4b, 0x23, 0x1d, 0x10, 0x20, 0x5d, 0x3e, 0x61, 0x47, 0x0b, 0xca, 0xa9, 0x22, 0x36, 0x39, 0x58, 0x2c, 0x28, 0x15, 0x15, 0x23, 0x58, 0x39, 0x48, 0x28, 0x68, 0xec, 0x05, 0x00, 0x00, 0xfa, 0xf8, 0xbc, 0x25, 0x3e, 0x39, 0x21, 0xb2, 0x04, 0xf3, 0xf3, 0xee, 0x91, 0x98, 0x02, 0x75, 0x75, 0xf7, 0xb2, 0x27, 0xed, 0xba, 0x8e, 0xf7, 0xa0, 0x08, 0xc9, 0xeb, 0x89, 0xf6, 0xcb, 0x88, 0xeb, 0xd6, 0x95, 0x01, 0x83, 0x13, 0xd8, 0xef, 0x73, 0xef, 0xbf, 0x08, 0xa1, 0x04, 0x8b, 0xd1, 0xf3, 0x92, 0xba, 0x04, 0x8b, 0xe1, 0xd0, 0x13, 0x8e, 0xf6, 0xa8, 0x18, 0x58, 0x2b, 
  0x06, 0xff, 0xfe, 0x00, 0xf7, 0xad, 0x2f, 0x1b, 0x33, 0x52, 0x58, 0x61, 0x46, 0x31, 0x23, 0x30, 0x45, 0xc3, 0xf7, 0xf7, 0xb8, 0x1f, 0x4e, 0x1d, 0x34, 0x48, 0x46, 0x58, 0x59, 0x39, 0x21, 0x30, 0x0d, 0xbf, 0x05, 0x00, 0xfb, 0x00, 0xfa, 0x00, 0xbb, 0x12, 0x61, 0x52, 0x12, 0xbd, 0xed, 0x62, 0x57, 0x76, 0x0b, 0x98, 0xf2, 0x73, 0x73, 0xef, 0x94, 0x09, 0xe1, 0xbe, 0x92, 0xf3, 0x57, 0x14, 0x8e, 0xf2, 0xaa, 0x01, 0xdd, 0xdc, 0xdb, 0xc2, 0xc2, 0xe5, 0x1f, 0x09, 0xb5, 0xeb, 0x89, 0xee, 0x87, 0x07, 0x75, 0x01, 0x95, 0xdb, 0xef, 0xd7, 0xd3, 0xd6, 0xa0, 0xed, 0x9c, 0x07, 0x35, 0xed, 0xa8, 0x18, 0x31, 0x1c, 
  0xfe, 0xfe, 0xff, 0xfe, 0xf8, 0x06, 0xdc, 0x94, 0x4e, 0x1e, 0x17, 0x2e, 0x12, 0x26, 0x60, 0x9d, 0xdf, 0x06, 0xf8, 0x00, 0xf8, 0xe4, 0xab, 0x74, 0x4e, 0x21, 0x2d, 0x2d, 0x4e, 0x7f, 0xc4, 0xc5, 0x73, 0xf0, 0x00, 0xff, 0x00, 0x00, 0x00, 0xf8, 0xbb, 0x25, 0x39, 0x4b, 0x25, 0xbd, 0xf2, 0xa4, 0x9d, 0xa7, 0x85, 0xa7, 0xf1, 0x72, 0x72, 0xf3, 0xa5, 0x0b, 0xe8, 0xb7, 0x95, 0x04, 0xc4, 0x76, 0xe0, 0xe2, 0x6e, 0xf2, 0xc9, 0x7e, 0xb2, 0x6e, 0x8b, 0x02, 0xaf, 0x80, 0xe5, 0xef, 0x57, 0xe9, 0xdb, 0x76, 0xc9, 0x02, 0x8b, 0xc4, 0xee, 0x8e, 0xa4, 0xa4, 0x14, 0xdd, 0xe5, 0x73, 0xbf, 0x02, 0xa8, 0x18, 0x3e, 0x4c, 
  0x00, 0x00, 0xfe, 0x00, 0x06, 0x06, 0x06, 0x05, 0xe4, 0xd6, 0xc2, 0xb7, 0xc2, 0xd0, 0xeb, 0x05, 0x06, 0x06, 0x00, 0xfa, 0x06, 0x00, 0x04, 0xf4, 0xe2, 0xdc, 0xdc, 0xde, 0xec, 0xf5, 0xf8, 0xf7, 0xe6, 0xf7, 0x00, 0x00, 0xfe, 0xfb, 0x00, 0x06, 0xbc, 0x16, 0x52, 0x3e, 0x18, 0xa8, 0xf1, 0xf1, 0xee, 0xf2, 0xca, 0x91, 0xe3, 0x68, 0x68, 0xe3, 0x93, 0x10, 0xd2, 0xae, 0x94, 0xe2, 0xd2, 0xea, 0xe3, 0x8d, 0x0f, 0x96, 0xea, 0xed, 0xe3, 0x8a, 0x19, 0xbd, 0xf1, 0xe1, 0xd5, 0xdd, 0x4e, 0x8f, 0xe9, 0xe5, 0xd5, 0xe5, 0x8f, 0x3d, 0xce, 0xed, 0xed, 0xc0, 0x4e, 0x81, 0xe2, 0xee, 0xd5, 0xe3, 0x9e, 0x2c, 0x1c, 0x4c, 
  0x00, 0x00, 0x06, 0xfe, 0x06, 0x00, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x05, 0xf8, 0x06, 0x06, 0x06, 0xff, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xf8, 0xbb, 0x21, 0x34, 0x3a, 0x48, 0x36, 0x68, 0x5f, 0x5f, 0x6b, 0x50, 0x44, 0x6d, 0x2e, 0x65, 0x6a, 0x43, 0x46, 0x6d, 0x44, 0x4a, 0x4e, 0x22, 0x74, 0x69, 0x12, 0x5c, 0x11, 0x3b, 0x7b, 0x2d, 0x33, 0x3f, 0x1d, 0x69, 0x74, 0x1e, 0x63, 0x3f, 0x25, 0x64, 0x7b, 0x4a, 0x41, 0x59, 0x3f, 0x17, 0x78, 0x69, 0x3b, 0x18, 0x1d, 0x69, 0x68, 0x4a, 0x4e, 0x5c, 0x23, 0x4c, 0x38, 
  0x00, 0x00, 0xfe, 0x06, 0xfe, 0x06, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0xfe, 0xfe, 0xfa, 0x00, 0x00, 0xfe, 0xfe, 0x06, 0xbb, 0x16, 0x46, 0x2b, 0x43, 0x4c, 0x28, 0x46, 0x34, 0x42, 0x34, 0x39, 0x39, 0x34, 0x39, 0x23, 0x3a, 0x1c, 0x29, 0x48, 0x48, 0x39, 0x46, 0x39, 0x33, 0x61, 0x31, 0x1c, 0x46, 0x46, 0x34, 0x4b, 0x34, 0x4b, 0x39, 0x34, 0x5d, 0x1c, 0x39, 0x52, 0x34, 0x23, 0x31, 0x31, 0x3e, 0x4f, 0x39, 0x23, 0x36, 0x42, 0x52, 0x4b, 0x23, 0x46, 0x23, 0x31, 0x23, 0x31, 0x3a, 0x29, 
  0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0xfe, 0xfe, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x06, 0xfe, 0x06, 0xbb, 0x0f, 0x66, 0x3e, 0x1c, 0x4d, 0x38, 0x2b, 0x29, 0x4f, 0x3a, 0x2b, 0x4f, 0x2b, 0x4f, 0x4f, 0x3a, 0x32, 0x40, 0x29, 0x2b, 0x4f, 0x3a, 0x2b, 0x3e, 0x3e, 0x2b, 0x56, 0x38, 0x29, 0x3e, 0x4f, 0x4f, 0x2b, 0x4f, 0x3a, 0x24, 0x3a, 0x3e, 0x4b, 0x3e, 0x5e, 0x3a, 0x40, 0x56, 0x2b, 0x3e, 0x55, 0x3a, 0x4c, 0x39, 0x3e, 0x56, 0x4d, 0x29, 0x5e, 0x3e, 0x55, 0x2b, 0x24, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfa, 0x06, 0x00, 0x00, 0x06, 0xbc, 0x16, 0x39, 0x2b, 0x3e, 0x3e, 0x3a, 0x40, 0x3a, 0x3a, 0x3e, 0x4d, 0x24, 0x40, 0x56, 0x1c, 0x2b, 0x3a, 0x3a, 0x2b, 0x4f, 0x3e, 0x3e, 0x4d, 0x40, 0x24, 0x4d, 0x3a, 0x31, 0x2b, 0x52, 0x2b, 0x2b, 0x3a, 0x2b, 0x52, 0x32, 0x40, 0x2b, 0x3e, 0x39, 0x3e, 0x40, 0x3a, 0x3a, 0x52, 0x3e, 0x31, 0x1c, 0x3a, 0x3e, 0x4f, 0x3e, 0x2b, 0x4b, 0x2b, 0x39, 0x2b, 0x3a, 0x40, 
  0xfb, 0xfb, 0xfb, 0xfb, 0xfa, 0xfa, 0xfd, 0xfd, 0xfd, 0xfc, 0xfc, 0xfa, 0xfa, 0xfa, 0xfc, 0xfb, 0xfb, 0xfb, 0xf7, 0xfc, 0xf8, 0xfc, 0xfb, 0xfb, 0xfc, 0xfc, 0xfc, 0xfc, 0xfa, 0xfa, 0xfa, 0xfa, 0xfa, 0xfa, 0xfa, 0xfa, 0xf8, 0xf8, 0xfc, 0x06, 0xb6, 0x11, 0x34, 0x3e, 0x61, 0x3e, 0x2b, 0x2b, 0x3a, 0x2b, 0x1c, 0x29, 0x24, 0x24, 0x29, 0x3e, 0x4f, 0x1c, 0x3a, 0x3e, 0x2b, 0x39, 0x1c, 0x2b, 0x24, 0x32, 0x24, 0x2b, 0x3a, 0x1c, 0x55, 0x2b, 0x32, 0x1c, 0x3e, 0x39, 0x29, 0x29, 0x31, 0x39, 0x39, 0x3e, 0x4f, 0x29, 0x2b, 0x52, 0x1c, 0x31, 0x38, 0x29, 0x2b, 0x3a, 0x2b, 0x4b, 0x52, 0x39, 0x2b, 0x2b, 0x3a, 0x40, 
};

const lv_img_dsc_t capuf = {
  .header.cf = LV_IMG_CF_INDEXED_8BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 100,
  .header.h = 30,
  .data_size = 4024,
  .data = capuf_map,
};


#define LV_FONT_MONTSERRAT_16
void example_lvgl_demo_ui(lv_disp_t *disp)
{   
    

    lv_obj_t * scr = lv_scr_act();
    // lv_color_t color = lv_color_hex(0x80D8FF);
    // lv_obj_set_style_bg_color(scr,color,0);
    lv_obj_set_style_bg_color(scr,lv_palette_main(LV_PALETTE_TEAL),0);
    lv_obj_t * textarea = lv_textarea_create(scr);
    lv_textarea_add_text(textarea, "insert this text");
    lv_obj_align(textarea, LV_ALIGN_TOP_MID,0,0);
    lv_obj_set_style_bg_color(textarea,lv_palette_main(LV_PALETTE_DEEP_PURPLE),0);
    
    //show text
    // lv_obj_t * scr = lv_scr_act();
    lv_obj_t * label14 = lv_label_create(scr);
    lv_label_set_recolor(label14, true);


    lv_obj_set_style_text_font(label14,&lv_font_montserrat_14,0);
    lv_label_set_text(label14,"#0000ff size=14");
    lv_obj_align(label14,LV_ALIGN_TOP_LEFT,0,0);

    //custom font
    #if 1
    // LV_FONT_DECLARE()
    LV_FONT_DECLARE(Teko_Bold_20_4bpp);
    lv_obj_t *customFont1 = lv_label_create(scr);
    lv_label_set_recolor(customFont1, true);
    lv_obj_set_style_text_font(customFont1,&Teko_Bold_20_4bpp,0);
    lv_label_set_text(customFont1,"#0000ff CAPUF EMBEDDED");
    lv_obj_align(customFont1,LV_ALIGN_BOTTOM_MID,0,0);
    #endif

    lv_obj_t * label48 = lv_label_create(scr);
    lv_label_set_recolor(label48, true);
    lv_obj_set_style_text_font(label48,&lv_font_montserrat_48,0);
    lv_label_set_text(label48,"#0000ff size=48");
    lv_obj_align(label48,LV_ALIGN_LEFT_MID,0,0);

    // //copying image from file to buffer
    // char *fileName = MOUNT_POINT"/capuf1.bin";
    // FILE *fd = fopen(fileName,"r");
    // if(fd == NULL) printf("file opening error\n");
    // size_t imgBufSize = fseek(fd,0,SEEK_END) + 2;
    // char *imgBuf = heap_caps_malloc(imgBufSize, MALLOC_CAP_SPIRAM);
    // fseek(fd,0,SEEK_SET);
    // // char ch = NULL;
    // int64_t i = 0;
    // unsigned char ch = 0;
    // while( EOF != (ch = fgetc(fd)))
    // {
    //     imgBuf[i] = ch;
    //     i++;
    //     // vTaskDelay(portTICK_PERIOD_MS);
    //     printf("\r reading file ... ch = %d and i = %llu",imgBuf[i],i);
    // }

    // printf("\nreading file finished\n");
    // imgBuf[i] = '\0';

    // lv_obj_t * scr = lv_scr_act();
    lv_obj_t * icon = lv_img_create(scr);
    lv_img_set_src(icon, &capuf);
    // lv_obj_set_style_bg_color(scr,lv_palette_main(LV_PALETTE_ORANGE),0);
    // lv_obj_set_pos(icon,400,240);
    // lv_obj_set_size(icon,200,70);
    lv_obj_align_to(icon,lv_scr_act(),LV_ALIGN_CENTER,0,0);
}