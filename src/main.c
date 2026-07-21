#include "rtc.h"
#include "moisture_sensor.h"


void app_main(){
  rtc_module_init();

  moisture_sensor_init();
  while (ready != true){
    vTaskDelay(pdMS_TO_TICKS(100));
  }
  while (1){
    if (get_current_time(HOUR) == 5 && get_current_time(MIN) == 23){

        moisture_sensor_read();
    }
    // printf("HOUR: %d      MIN: %d\n", get_current_time(HOUR), get_current_time(MIN));

    // printf("Local Time: %02d:%02d:%02d\n",
    //       time_info.tm_hour,
    //       time_info.tm_min,
    //       time_info.tm_sec);
    // vTaskDelay(pdMS_TO_TICKS(1000));
  }
  
}