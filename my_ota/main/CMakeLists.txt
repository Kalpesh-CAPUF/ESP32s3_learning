
idf_build_get_property(project_dir PROJECT_DIR)
idf_component_register(SRCS             "my_ota.c"
                                        "./src/sd_card_driver/sd_card.c"
                        INCLUDE_DIRS    "."
                                        "./src/sd_card_driver/")
