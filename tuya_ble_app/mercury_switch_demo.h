#ifndef __MERCURY_SWITCH_DEMO_H__
#define __MERCURY_SWITCH_DEMO_H__

#include "tuya_ble_common.h"

/* mercury switch sensor pin define */
#define MERCURY_SWITCH_PORT GPIO_PD2

/* DP define */
#define DP_ID_SENSOR_STATE	101

#define MERCURY_SWITCH_OFF	0
#define MERCURY_SWIYCH_ON 	1

void mercury_switch_init(void);
void mercury_switch_task(void);
void dp_update(unsigned char dp_id, unsigned char data_type, unsigned char data);


#endif /* __MERCURY_SWITCH_DEMO_H__ */
