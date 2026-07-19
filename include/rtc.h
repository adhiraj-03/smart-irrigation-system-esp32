#include "driver/gpio.h"
#include "nvs_flash.h"
#include "esp_wifi_default.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_wifi.h"
#include "stdlib.h"
#include "esp_netif_sntp.h"
#include "time.h"

static void wifi_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);

struct tm time_info;
