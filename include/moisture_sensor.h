#include "esp_adc/adc_oneshot.h"

#define SAMPLE_SIZE             500
#define MOIST_THRES_UPPER            1800
#define MOIST_THRES_LOWER            1200

void moisture_sensor_init(void);
int moisture_sensor_read(void);

