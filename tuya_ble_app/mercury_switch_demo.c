#include "tuya_ble_log.h"

#include "mercury_switch_demo.h"

/* update DP array len */
#define ARRAY_LEN		4
#define UPDATE_DP_LEN	1

void mercury_switch_init(void)
{
	gpio_set_func(MERCURY_SWITCH_PORT, AS_GPIO);
	gpio_set_input_en(MERCURY_SWITCH_PORT, 1);
	gpio_setup_up_down_resistor(MERCURY_SWITCH_PORT, PM_PIN_PULLUP_10K);
}

void mercury_switch_task(void)
{
	unsigned char pin_value;
	pin_value = gpio_read(MERCURY_SWITCH_PORT);
	if (pin_value) {
		TUYA_APP_LOG_INFO("gpio read high");
		dp_update(DP_ID_SENSOR_STATE, DT_BOOL, MERCURY_SWIYCH_ON);
	} else {
		TUYA_APP_LOG_INFO("gpio read low");
		dp_update(DP_ID_SENSOR_STATE, DT_BOOL, MERCURY_SWITCH_OFF);
	}
}

/*
 * data_type: bool:1 ,value:2, string:3, enum:4, bitmap:5
 * */
void dp_update(unsigned char dp_id, unsigned char data_type, unsigned char data)
{
	unsigned char mercury_switch_state_array[ARRAY_LEN];
	mercury_switch_state_array[0] = dp_id;
	mercury_switch_state_array[1] = data_type;
	mercury_switch_state_array[2] = UPDATE_DP_LEN;
	mercury_switch_state_array[3] = data;

	tuya_ble_dp_data_report(mercury_switch_state_array, ARRAY_LEN);
}






