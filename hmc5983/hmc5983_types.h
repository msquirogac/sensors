#include <stdint.h>

typedef struct
{
	uint8_t Temperature_Sensor; /* Temperature sensor enable/disable */
	uint8_t Average_Sample;			/* Select number of samples averaged */
	uint8_t Output_DataRate;		/* OUT data rate */
	uint8_t Working_Mode;				/* Operating mode */
	uint8_t Full_Scale;					/* Full Scale selection */
} HMC5983_InitTypeDef;

typedef struct
{
	HMC5983_InitTypeDef Init;
} HMC5983_HandleTypeDef;