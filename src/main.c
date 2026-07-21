#include "rtc.h"
#include "moisture_sensor.h"
#include "pump_control.h"
#include "sleep.h"

int soil_moisture_level = 0;

void app_main(){
  if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_UNDEFINED){
    rtc_module_init();
  }

  moisture_sensor_init();
  while (ready != true){
    vTaskDelay(pdMS_TO_TICKS(100));
  }

  /*------------ PUMP CONTROL LOGIC --------------*/
  while (get_current_time(HOUR) == 5 && get_current_time(MIN) == 23){
    soil_moisture_level = moisture_sensor_read();
    if (soil_moisture_level > 1800 && get_pump_state() == LOW){
      // Turn the Pump ON
      pump_on();
    }
    else if(soil_moisture_level < 1200 && get_pump_state() == HIGH){
      // Turn the Pump OFF
      pump_off();
    }
    else {continue;}
    vTaskDelay(pdMS_TO_TICKS(2000));
  }
    // printf("HOUR: %d      MIN: %d\n", get_current_time(HOUR), get_current_time(MIN));

    // printf("Local Time: %02d:%02d:%02d\n",
    //       time_info.tm_hour,
    //       time_info.tm_min,
    //       time_info.tm_sec);
    // vTaskDelay(pdMS_TO_TICKS(1000));
  }
  