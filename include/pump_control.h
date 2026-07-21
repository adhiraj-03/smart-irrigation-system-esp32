#include "driver/gpio.h"

void pump_init(void);
void pump_on(void);
void pump_off(void);
int get_pump_state(void);

/*----------------MACROS for Pump Control ON and OFF----------------*/
#define HIGH              1
#define LOW               0