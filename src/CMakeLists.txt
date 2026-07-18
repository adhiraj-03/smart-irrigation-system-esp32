# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

REQUIRES esp_driver_gpio

idf_component_register(
    SRCS
        "main.c"

    INCLUDE_DIRS "."
)

idf_component_register(SRCS ${app_sources})

