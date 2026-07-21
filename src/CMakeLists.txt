# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

idf_component_register(
    SRCS
        "main.c"
        "rtc.c"
        "moisture_sensor.c"
        "pump_control.c"
        "sleep.c"

    INCLUDE_DIRS "."
    REQUIRES
            esp_driver_gpio
            nvs_flash
            esp_wifi
            esp_event
            esp_netif
            esp_adc
)

