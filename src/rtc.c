
#include "rtc.h"

void rtc_init(){

  esp_err_t err;
  wifi_init_config_t wifi_init_config = WIFI_INIT_CONFIG_DEFAULT();
  wifi_config_t wifi_config = {
    .sta = {
      .ssid = "Airtel_Punit",
      .password = "Airtel@123"
    }
  };

  

  err = nvs_flash_init();                                                       // Initialize the NVS (Wifi needs it)
  printf("nvs_flash_init: %s\n", esp_err_to_name(err));

  err = esp_netif_init();                                                       // Create a netif object (abstraction layer for communication)
  printf("esp_netif_init: %s\n", esp_err_to_name(err));

  err = esp_event_loop_create_default();                                        // Create an event loop for wifi handlers
  printf("esp_event_loop_create_default: %s\n", esp_err_to_name(err));
  esp_netif_create_default_wifi_sta();                                          // Create WiFi interface

  err = esp_wifi_init(&wifi_init_config);                                                 // Initialising WiFi Driver
  printf("esp_wifi_init: %s\n", esp_err_to_name(err));
  err = esp_wifi_set_mode(WIFI_MODE_STA);                                       // Set WiFi Mode to Station
  printf("esp_wifi_set_mode: %s\n", esp_err_to_name(err));
  err = esp_wifi_set_config(WIFI_IF_STA, &wifi_config);                                // Set WiFi Configurations for Connection
  printf("esp_wifi_set_config: %s\n", esp_err_to_name(err));
  err = esp_wifi_start();                                                       // Start WiFi according to current configuration
  printf("esp_wifi_start: %s\n", esp_err_to_name(err));

  err = esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL);
  printf("esp_event_handler_register: %s\n", esp_err_to_name(err));

  err = esp_wifi_connect();                                                     // Connect to Wifi
  printf("esp_wifi_connect: %s\n", esp_err_to_name(err));



  // err = esp_wifi_disconnect();
  // printf("esp_wifi_disconnect: %s\n", esp_err_to_name(err));

}

/*
Event Handler for WiFi to run SNTP on getting IP Address
*/
static void wifi_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data){
  esp_sntp_config_t sntp_config = ESP_NETIF_SNTP_DEFAULT_CONFIG("pool.ntp.org");
  sntp_config.start = true;

  if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP){
    printf("WiFi Connected! \n");
    
    // SNTP Code
    esp_netif_sntp_init(&sntp_config);
    if (esp_netif_sntp_sync_wait(pdMS_TO_TICKS(10000)) != ESP_OK){
      printf("Failed to update system time within 10s timeout");
      return;
    }

    time_t now;
    time(&now);

    setenv("TZ", "IST-5:30", 1);
    tzset();

    localtime_r(&now, &time_info);

    printf("Local Time: %02d:%02d:%02d\n",
          time_info.tm_hour,
          time_info.tm_min,
          time_info.tm_sec);
  }
}
