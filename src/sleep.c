#include "sleep.h"
#include "rtc.h"

uint64_t wakeup = 0;

uint64_t convert_to_us(int hour, int min){
  uint64_t us = (((uint64_t) hour * 3600000000) + (uint64_t) (min * 60000000));
  return us;
}


uint64_t get_wakeup_time(){
  uint64_t wakeup_time = 0;
  uint64_t target_time = 0;
  uint64_t current_time = 0;
  int hour = get_current_time(HOUR);
  if (hour >= 6 && hour < 12){
    target_time = convert_to_us(2, 0);
    current_time = convert_to_us(0, PROCESS_TIME);
    wakeup_time = target_time - current_time;
  }
  else {
    target_time = convert_to_us(30, 0);                                    // 30 is taken since its 6 am next day (6 + 24)
    current_time = convert_to_us(hour, get_current_time(MIN));
    wakeup_time = target_time - current_time;
  }
  return wakeup_time;
}

void sleep_enable(){
  wakeup = get_wakeup_time();
  esp_sleep_enable_timer_wakeup(wakeup);

  esp_deep_sleep_start();
}