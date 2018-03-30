#define MAG3110_I2C_ADDR            0x1C

#define MAG3110_DR_STATUS           0x00
#define MAG3110_OUT_X_MSB           0x01
#define MAG3110_OUT_X_LSB           0x02
#define MAG3110_OUT_Y_MSB           0x03
#define MAG3110_OUT_Y_LSB           0x04
#define MAG3110_OUT_Z_MSB           0x05
#define MAG3110_OUT_Z_LSB           0x06
#define MAG3110_OUT_Z_LSB           0x06
#define MAG3110_WHO_AM_I            0x07
#define MAG3110_SYSMOD              0x08
#define MAG3110_OFF_X_MSB           0x09
#define MAG3110_OFF_X_LSB           0x0A
#define MAG3110_OFF_Y_MSB           0x0B
#define MAG3110_OFF_Y_LSB           0x0C
#define MAG3110_OFF_Z_MSB           0x0D
#define MAG3110_OFF_Z_LSB           0x0E
#define MAG3110_DIE_TEMP            0x0F
#define MAG3110_CTRL_REG1           0x10
#define MAG3110_CTRL_REG2           0x11

#define MAG3110_ADC_RATE_1          ((uint8_t) 0x00)   /* ADC Rate = 1280 Hz */
#define MAG3110_ADC_RATE_2          ((uint8_t) 0x20)   /* ADC Rate = 640 Hz */
#define MAG3110_ADC_RATE_3          ((uint8_t) 0x40)   /* ADC Rate = 320 Hz */
#define MAG3110_ADC_RATE_4          ((uint8_t) 0x60)   /* ADC Rate = 160 Hz */
#define MAG3110_ADC_RATE_5          ((uint8_t) 0x80)   /* ADC Rate = 80 Hz */
#define MAG3110_ADC_RATE_6          ((uint8_t) 0xA0)   /* ADC Rate = 40 Hz */
#define MAG3110_ADC_RATE_7          ((uint8_t) 0xC0)   /* ADC Rate = 20 Hz */
#define MAG3110_ADC_RATE_8          ((uint8_t) 0xE0)   /* ADC Rate = 10 Hz */

#define MAG3110_AVERAGE_SAMPLE_1    ((uint8_t) 0x00)   /* Average 16 sample */
#define MAG3110_AVERAGE_SAMPLE_2    ((uint8_t) 0x08)   /* Average 32 sample */
#define MAG3110_AVERAGE_SAMPLE_3    ((uint8_t) 0x10)   /* Average 64 sample */
#define MAG3110_AVERAGE_SAMPLE_4    ((uint8_t) 0x18)   /* Average 128 sample */

#define MAG3110_FULL_READ           ((uint8_t) 0x00)   /* The full 16-bit values are read */
#define MAG3110_FAST_READ           ((uint8_t) 0x04)   /* Fast Read, 8-bit values read from the MSB registers */

#define MAG3110_NORMAL_MODE         ((uint8_t) 0x00)   /* */
#define MAG3110_TRIGGER_MODE        ((uint8_t) 0x02)   /* */

#define MAG3110_STANDBY_MODE        ((uint8_t) 0x00)   /* Select standby mode */
#define MAG3110_ACTIVE_MODE         ((uint8_t) 0x01)   /* Select active mode */

#define MAG3110_AUTO_MRST_DISABLE   ((uint8_t) 0x00)   /* Automatic magnetic sensor resets disabled */
#define MAG3110_AUTO_MRST_ENABLE    ((uint8_t) 0x80)   /* Automatic magnetic sensor resets enabled */
#define MAG3110_RAW_MODE            ((uint8_t) 0x20)   /* Raw mode */
#define MAG3110_MAG_RST             ((uint8_t) 0x10)   /* Cycle reset */
