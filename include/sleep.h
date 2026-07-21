#include "esp_sleep.h"
#include <stdint.h>

#define PROCESS_TIME                2

/*------------- FUNCTION DECLARATIONS --------------*/
uint64_t convert_to_us(int hour, int min);
uint64_t get_wakeup_time(void);
void sleep_enable(void);