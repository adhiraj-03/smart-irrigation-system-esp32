#include "pump_control.h"

gpio_config_t pump_gpio_config = {
  .pin_bit_mask = (1ULL << 25),
  .mode = GPIO_MODE_OUTPUT,
};

gpio_num_t gpio_num = GPIO_NUM_25;

void pump_init(){
  gpio_config(&pump_gpio_config);                                           // Configure the GPIO Pin with given configurations

}

void pump_on(){                                                             // Turn pump on
  gpio_set_level(GPIO_NUM_25, HIGH);
  printf("Turning Pump ON !");

}

void pump_off(){                                                            // Turn pump off
  gpio_set_level(GPIO_NUM_25, LOW);
  printf("Turning Pump OFF !");
}

int get_pump_state(){                                                       // Obtain the pump state whether it is ON or OFF
  int pump_state = gpio_get_level(GPIO_NUM_25);
  return pump_state;
}