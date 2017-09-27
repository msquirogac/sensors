
#define MPU9250_READ_FLAG						0x80

// Sensor Self-Test
#define MPU9250_SELF_TEST_X_GYRO    0x00
#define MPU9250_SELF_TEST_Y_GYRO    0x01
#define MPU9250_SELF_TEST_Z_GYRO    0x02
#define MPU9250_SELF_TEST_X_ACCEL   0x0D
#define MPU9250_SELF_TEST_Y_ACCEL   0x0E
#define MPU9250_SELF_TEST_Z_ACCEL   0x0F

// Sensor Config Regs
#define MPU9250_SMPLRT_DIV          0x19
#define MPU9250_CONFIG							0x1A
#define MPU9250_GYRO_CONFIG					0x1B
#define MPU9250_ACCEL_CONFIG				0x1C
#define MPU9250_ACCEL_CONFIG2				0x1D
#define MPU9250_LP_ACCEL_ODR        0x1E
#define MPU9250_WOM_THR             0x1F
#define MPU9250_FIFO_EN             0x23

#define MPU9250_SIGNAL_PATH_RESET   0x68
#define MPU9250_MOT_DETECT_CTRL     0x69
#define MPU9250_USER_CTRL						0x6A
#define MPU9250_PWR_MGMT_1					0x6B
#define MPU9250_PWR_MGMT_2					0x6C

#define MPU9250_FIFO_COUNTH         0x72
#define MPU9250_FIFO_COUNTL         0x73
#define MPU9250_FIFO_R_W            0x74
#define MPU9250_WHO_AM_I            0x75

// Sensor Measurement Regs
#define MPU9250_ACCEL_XOUT_H				0x3b
#define MPU9250_ACCEL_XOUT_L				0x3C
#define MPU9250_ACCEL_YOUT_H				0x3D
#define MPU9250_ACCEL_YOUT_L				0x3E
#define MPU9250_ACCEL_ZOUT_H				0x3F
#define MPU9250_ACCEL_ZOUT_L				0x40
#define MPU9250_TEMP_OUT_H					0x41
#define MPU9250_TEMP_OUT_L					0x42
#define MPU9250_GYRO_XOUT_H					0x43
#define MPU9250_GYRO_XOUT_L					0x44
#define MPU9250_GYRO_YOUT_H					0x45
#define MPU9250_GYRO_YOUT_L					0x46
#define MPU9250_GYRO_ZOUT_H					0x47
#define MPU9250_GYRO_ZOUT_L					0x48
#define MPU9250_EXT_SENS_DATA_00		0x49
#define MPU9250_EXT_SENS_DATA_01		0x4A
#define MPU9250_EXT_SENS_DATA_02		0x4B
#define MPU9250_EXT_SENS_DATA_03		0x4C
#define MPU9250_EXT_SENS_DATA_04		0x4D
#define MPU9250_EXT_SENS_DATA_05		0x4E
#define MPU9250_EXT_SENS_DATA_06		0x4F
#define MPU9250_EXT_SENS_DATA_07		0x50
#define MPU9250_EXT_SENS_DATA_08		0x51
#define MPU9250_EXT_SENS_DATA_09		0x52
#define MPU9250_EXT_SENS_DATA_10		0x53
#define MPU9250_EXT_SENS_DATA_11		0x54
#define MPU9250_EXT_SENS_DATA_12		0x55
#define MPU9250_EXT_SENS_DATA_13		0x56
#define MPU9250_EXT_SENS_DATA_14		0x57
#define MPU9250_EXT_SENS_DATA_15		0x58
#define MPU9250_EXT_SENS_DATA_16		0x59
#define MPU9250_EXT_SENS_DATA_17		0x5A
#define MPU9250_EXT_SENS_DATA_18		0x5B
#define MPU9250_EXT_SENS_DATA_19		0x5C
#define MPU9250_EXT_SENS_DATA_20		0x5D
#define MPU9250_EXT_SENS_DATA_21		0x5E
#define MPU9250_EXT_SENS_DATA_22		0x5F
#define MPU9250_EXT_SENS_DATA_23		0x60

// Sensor offset Regs
#define MPU9250_XG_OFFSET_H         0x13
#define MPU9250_XG_OFFSET_L         0x14
#define MPU9250_YG_OFFSET_H         0x15
#define MPU9250_YG_OFFSET_L         0x16
#define MPU9250_ZG_OFFSET_H         0x17
#define MPU9250_ZG_OFFSET_L         0x18
#define MPU9250_XA_OFFSET_H         0x77
#define MPU9250_XA_OFFSET_L         0x78
#define MPU9250_YA_OFFSET_H         0x7A
#define MPU9250_YA_OFFSET_L         0x7B
#define MPU9250_ZA_OFFSET_H         0X7D
#define MPU9250_ZA_OFFSET_L         0X7E

// Sensor I2C Config Regs
#define MPU9250_I2C_MST_CTRL				0x24
#define MPU9250_I2C_SLV0_ADDR				0x25
#define MPU9250_I2C_SLV0_REG				0x26
#define MPU9250_I2C_SLV0_CTRL				0x27
#define MPU9250_I2C_SLV1_ADDR				0x28
#define MPU9250_I2C_SLV1_REG				0x29
#define MPU9250_I2C_SLV1_CTRL				0x2A
#define MPU9250_I2C_SLV2_ADDR				0x2B
#define MPU9250_I2C_SLV2_REG				0x2C
#define MPU9250_I2C_SLV2_CTRL				0x2D
#define MPU9250_I2C_SLV3_ADDR				0x2E
#define MPU9250_I2C_SLV3_REG				0x2F
#define MPU9250_I2C_SLV3_CTRL				0x30
#define MPU9250_I2C_SLV0_DO					0x63
#define MPU9250_I2C_SLV1_DO					0x64
#define MPU9250_I2C_SLV2_DO					0x65
#define MPU9250_I2C_SLV3_DO					0x66
#define MPU9250_I2C_SLV4_ADDR				0x31
#define MPU9250_I2C_SLV4_REG				0x32
#define MPU9250_I2C_SLV4_DO					0x33
#define MPU9250_I2C_SLV4_CTRL				0x34
#define MPU9250_I2C_SLV4_DI					0x35
#define MPU9250_I2C_MST_DELAY_CTRL  0x67

// Sensor INT regs
#define MPU9250_INT_PIN_CFG         0x37
#define MPU9250_INT_ENABLE          0x38
#define MPU9250_INT_STATUS          0x3A


#define MPU9250_ACCEL_SENSITIVITY_2G		((float) 16384) /* accelerometer sensitivity for 2g full scale [LSB/g] */
#define MPU9250_ACCEL_SENSITIVITY_4G		((float) 8192)	/* accelerometer sensitivity for 4g full scale [LSB/g] */
#define MPU9250_ACCEL_SENSITIVITY_8G		((float) 4096)	/* accelerometer sensitivity for 8g full scale [LSB/g] */
#define MPU9250_ACCEL_SENSITIVITY_16G		((float) 2048)	/* accelerometer sensitivity for 16g full scale [LSB/g] */
#define MPU9250_GYRO_SENSITIVITY_250		((float) 131)		/* gyroscope sensitivity for 250 dps full scale [LSB/dps] */
#define MPU9250_GYRO_SENSITIVITY_500		((float) 65.5)	/* gyroscope sensitivity for 500 dps full scale [LSB/dps] */
#define MPU9250_GYRO_SENSITIVITY_1000		((float) 32.8)	/* gyroscope sensitivity for 1000 dps full scale [LSB/dps] */
#define MPU9250_GYRO_SENSITIVITY_2000		((float) 16.4)	/* gyroscope sensitivity for 2000 dps full scale [LSB/dps] */


#define	MPU9250_H_RESET									((uint8_t) 0x80)	/* Reset the internal registers and restores the default settings */

#define	MPU9250_ACCEL_FS_2G							((uint8_t) 0x00)	/* Full scale = 2G */
#define	MPU9250_ACCEL_FS_4G							((uint8_t) 0x08)	/* Full scale = 4G */
#define	MPU9250_ACCEL_FS_8G							((uint8_t) 0x10)	/* Full scale = 8G */
#define	MPU9250_ACCEL_FS_16G						((uint8_t) 0x18)	/* Full scale = 16G */

#define	MPU9250_GYRO_FS_250							((uint8_t) 0x00)	/* Full scale = 250 dps */
#define	MPU9250_GYRO_FS_500							((uint8_t) 0x08)	/* Full scale = 500 dps */
#define	MPU9250_GYRO_FS_1000						((uint8_t) 0x10)	/* Full scale = 1000 dps */
#define	MPU9250_GYRO_FS_2000						((uint8_t) 0x18)	/* Full scale = 2000 dps */

#define MPU9250_AX_ENABLE								((uint8_t) 0x20)	/* Enable Accel X */
#define MPU9250_AY_ENABLE								((uint8_t) 0x10)	/* Enable Accel Y */
#define MPU9250_AZ_ENABLE								((uint8_t) 0x08)	/* Enable Accel Z */
#define MPU9250_GX_ENABLE								((uint8_t) 0x04)	/* Enable Gyro X */
#define MPU9250_GY_ENABLE								((uint8_t) 0x02)	/* Enable Gyro Y */
#define MPU9250_GZ_ENABLE								((uint8_t) 0x01)	/* Enable Gyro Z */

#define MPU9250_DLPF_CFG_0							((uint8_t) 0x00)
#define MPU9250_DLPF_CFG_1							((uint8_t) 0x01)
#define MPU9250_DLPF_CFG_2							((uint8_t) 0x02)
#define MPU9250_DLPF_CFG_3							((uint8_t) 0x03)
#define MPU9250_DLPF_CFG_4							((uint8_t) 0x04)
#define MPU9250_DLPF_CFG_5							((uint8_t) 0x05)
#define MPU9250_DLPF_CFG_6							((uint8_t) 0x06)
#define MPU9250_DLPF_CFG_7							((uint8_t) 0x07)

#define MPU9250_CLKSEL_0								((uint8_t) 0x00)
#define MPU9250_CLKSEL_1								((uint8_t) 0x01)
#define MPU9250_CLKSEL_2								((uint8_t) 0x02)
#define MPU9250_CLKSEL_3								((uint8_t) 0x03)
#define MPU9250_CLKSEL_4								((uint8_t) 0x04)
#define MPU9250_CLKSEL_5								((uint8_t) 0x05)
#define MPU9250_CLKSEL_6								((uint8_t) 0x06)
#define MPU9250_CLKSEL_7								((uint8_t) 0x07)

#define MPU9250_INT_WOM									((uint8_t) 0x40)
#define MPU9250_INT_FIFO_OVERFLOW				((uint8_t) 0x10)
#define MPU9250_INT_DATA_RDY						((uint8_t) 0x01)

#define MPU9250_INT_LOGIC_LEVEL_LOW			((uint8_t) 0x80)
#define MPU9250_INT_LOGIC_LEVEL_HIGH		((uint8_t) 0x00)
#define MPU9250_INT_PIN_HELD						((uint8_t) 0x20)
#define MPU9250_INT_PIN_PULSE						((uint8_t) 0x00)
#define MPU9250_INT_ANY_READ_CLEAR			((uint8_t) 0x10)
#define MPU9250_INT_ONLY_STATUS_CLEAR		((uint8_t) 0x00)

#define MPU9250_FIFO_FULL_REPLACE				((uint8_t) 0x00)
#define MPU9250_FIFO_FULL_KEEP					((uint8_t) 0x01)


// Magnetometer AK8963
#define AK8963_I2C_ADDR									((uint8_t) 0x0C)
#define AK8963_WIA											((uint8_t) 0x00)
#define AK8963_INFO											((uint8_t) 0x01)

#define AK8963_HXL											((uint8_t) 0x03)
#define AK8963_HXH											((uint8_t) 0x04)
#define AK8963_HYL											((uint8_t) 0x05)
#define AK8963_HYH											((uint8_t) 0x06)
#define AK8963_HZL											((uint8_t) 0x07)
#define AK8963_HZH											((uint8_t) 0x08)
#define AK8963_ST2											((uint8_t) 0x09)
#define AK8963_CNTL1										((uint8_t) 0x0A)
#define AK8963_CNTL2										((uint8_t) 0x0B)
#define AK8963_ASTC											((uint8_t) 0x0C)
#define AK8963_TS1											((uint8_t) 0x0D)
#define AK8963_TS2											((uint8_t) 0x0E)
#define AK8963_I2CDIS										((uint8_t) 0x0F)
#define AK8963_ASAX											((uint8_t) 0x10)
#define AK8963_ASAY											((uint8_t) 0x11)
#define AK8963_ASAZ											((uint8_t) 0x12)


#define AK8963_SENSITIVITY_14bit				((float) 0.6)	   /* Magnetometer sensitivity for 14bit resolution [uT/LSB] */
#define AK8963_SENSITIVITY_16bit				((float) 0.15)   /* Magnetometer sensitivity for 14bit resolution [uT/LSB] */


#define	AK8963_POWER_DOWN								((uint8_t) 0x00) /* Power-Down mode */
#define AK8963_SINGLE_MEASUREMENT				((uint8_t) 0x01) /* Single Measurement Mode */
#define AK8963_CONTINUOS_MEASUREMENT1		((uint8_t) 0x02) /* Continuous Measurement Mode 1 */
#define AK8963_CONTINUOS_MEASUREMENT2		((uint8_t) 0x06) /* Continuous Measurement Mode 1 */
#define AK8963_SELF_TEST								((uint8_t) 0x08) /* Self-test mode */
#define AK8963_FUSE_ROM									((uint8_t) 0x0F) /* Fuse ROM access mode */

#define	AK8963_RESOLUTION_14bit					((uint8_t) 0x00) /* Resolution 14Bit */
#define	AK8963_RESOLUTION_16bit					((uint8_t) 0x10) /* Resolution 16Bit */


