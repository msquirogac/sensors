#define MS5611_I2C_ADDR1          0xEC
#define MS5611_I2C_ADDR2          0xEE

#define MS5611_CMD_RESET          0x1E // ADC reset command
#define MS5611_CMD_ADC_READ       0x00 // ADC read command
#define MS5611_CMD_ADC_CONV       0x40 // ADC conversion command
#define MS5611_CMD_ADC_D1         0x00 // ADC D1 conversion (pressure)
#define MS5611_CMD_ADC_D2         0x10 // ADC D2 conversion (temperature)
#define MS5611_CMD_PROM_READ      0xA0 // Prom read command 

#define MS5611_OSR_256            0x00 // ADC OSR=256
#define MS5611_OSR_512            0x02 // ADC OSR=512
#define MS5611_OSR_1024           0x04 // ADC OSR=1024
#define MS5611_OSR_2048           0x06 // ADC OSR=2056
#define MS5611_OSR_4096           0x08 // ADC OSR=4096
