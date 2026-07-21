#include "moisture_sensor.h"

static esp_err_t err;

adc_oneshot_unit_init_cfg_t adc_config = {
  .unit_id = ADC_UNIT_1,
  .ulp_mode = ADC_ULP_MODE_DISABLE
};

adc_oneshot_unit_handle_t adc_handle;

adc_oneshot_chan_cfg_t adc_channel = {
  .atten = ADC_ATTEN_DB_12,
  .bitwidth = ADC_BITWIDTH_DEFAULT
};

int adc_raw_value;
int avg_adc_value = 0;


void moisture_sensor_init()                                                                   // Initialization of ADC
{

  err = adc_oneshot_new_unit(&adc_config, &adc_handle);                                       // Create a handle to a specific ADC unit.
  printf("adc_oneshot_new_unit: %s\n", esp_err_to_name(err));

  err = adc_oneshot_config_channel(adc_handle, ADC_CHANNEL_6, &adc_channel);                  // Set ADC oneshot mode required configurations.
  printf("adc_oneshot_config_channel: %s\n", esp_err_to_name(err));
}

int moisture_sensor_read(){                                                                   // Reading ADC Value
  int sum = 0;
  for(int i = 0; i<SAMPLE_SIZE; i++){
    adc_oneshot_read(adc_handle, ADC_CHANNEL_6, &adc_raw_value);                              // Get one ADC conversion raw result.
    sum += adc_raw_value;
    
  }
  avg_adc_value = sum / SAMPLE_SIZE;                                                          // Final Moisture reading stored in avg_adc_value
  
  printf("ADC Average Moisture Reading: %d\n", avg_adc_value);

  return avg_adc_value;
}
