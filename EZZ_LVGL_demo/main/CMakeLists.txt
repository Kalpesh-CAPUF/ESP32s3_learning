idf_component_register(SRCS "EZZ_LVGL_demo.c"
                            "src/lvglFs/lv_port_fs.c"
                            "src/SDdriver/sd_driver.c"
                            "display_ui.c"
                    INCLUDE_DIRS    "." 
                                    "src/lvglFs/"
                                    "src/SDdriver/")
