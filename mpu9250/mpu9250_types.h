#include <stdint.h>

typedef struct
{
	uint8_t Clock_Source;		  /* Clock source */
	uint8_t Sample_Rate_Div;  /* Sample Rate Divider */
} MPU9250_InitTypeDef;

typedef struct
{
	uint8_t Full_Scale;       /* Full Scale selection */
	uint8_t Enable_Axis;      /* Gyroscope Enable Axis */
	uint8_t DLPF_Config;      /* Configure DLPF */
} MPU9250G_InitTypeDef;

typedef struct
{
	uint8_t Full_Scale;	      /* Full Scale selection */
	uint8_t Enable_Axis;      /* Accelerometer Enable Axis */
	uint8_t DLPF_Config;      /* Configure DLPF */
} MPU9250A_InitTypeDef;

typedef struct
{
	uint8_t Full_Resolution;  /* Full Resolution selection */
	uint8_t Working_Mode;		  /* Operating mode */
} MPU9250M_InitTypeDef;

typedef struct
{
	uint8_t Enable_Interrupt; /* Interrupts enabled */
	uint8_t Logic_Level;			/* Logic level for INT pin */
	uint8_t Enable_Latch_Int; /* INT pin level held or pulse */
	uint8_t Status_Clear;			/* Interrupt status is cleared with any read operation*/
} MPU9250I_InitTypeDef;

typedef struct
{
	MPU9250_InitTypeDef Init;
	MPU9250G_InitTypeDef InitGyro;
	MPU9250A_InitTypeDef InitAccel;
	MPU9250M_InitTypeDef InitMagnet;
	MPU9250I_InitTypeDef InitInt;
} MPU9250_HandleTypeDef;