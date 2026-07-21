#include "nvs_flash.h"
#include "esp_wifi_default.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_wifi.h"
#include "stdlib.h"
#include "esp_netif_sntp.h"
#include "time.h"

/*
Parameter Definitions for get_current_time() Function.
*/
#define HOUR              0
#define MIN               1
#define SEC               2

/*
----------------- FUNCTION DECLARATIONS -----------------
*/

void wifi_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);

void rtc_module_init(void);

int get_current_time(int current_time);
/*
---------------- STRUCTURE & VARIABLE DECLARATIONS ------------------
*/
extern struct tm time_info;
extern bool ready;