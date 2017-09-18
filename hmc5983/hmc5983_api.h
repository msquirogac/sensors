
#define HMC5983_READ_FLAG						0x80
#define HMC5983_MULTI_FLAG					0x40

#define HMC5983_CRA									0x00
#define HMC5983_CRB									0x01
#define HMC5983_MR									0x02
#define HMC5983_DXRA								0x03
#define HMC5983_DXRB								0x04
#define HMC5983_DZRA								0x05
#define HMC5983_DZRB								0x06
#define HMC5983_DYRA								0x07
#define HMC5983_DYRB								0x08
#define HMC5983_SR									0x09
#define HMC5983_IRA									0x0A
#define HMC5983_IRB									0x0B
#define HMC5983_IRC									0x0C
#define HMC5983_TEMPH								0x31
#define HMC5983_TEMPL								0x32


#define HMC5983_SENSITIVITY_0_88Ga			((float) 1370) /* magnetometer sensitivity for 0.88 Ga full scale [LSB/Ga] */
#define HMC5983_SENSITIVITY_1_3Ga				((float) 1090) /* magnetometer sensitivity for 1.3 Ga full scale [LSB/Ga] */
#define HMC5983_SENSITIVITY_1_9Ga				((float) 820)	 /* magnetometer sensitivity for 1.9 Ga full scale [LSB/Ga] */
#define HMC5983_SENSITIVITY_2_5Ga				((float) 660)	 /* magnetometer sensitivity for 2.5 Ga full scale [LSB/Ga] */
#define HMC5983_SENSITIVITY_4_0Ga				((float) 440)	 /* magnetometer sensitivity for 4.0 Ga full scale [LSB/Ga] */
#define HMC5983_SENSITIVITY_4_7Ga				((float) 390)	 /* magnetometer sensitivity for 4.7 Ga full scale [LSB/Ga] */
#define HMC5983_SENSITIVITY_5_6Ga				((float) 330)	 /* magnetometer sensitivity for 5.6 Ga full scale [LSB/Ga] */
#define HMC5983_SENSITIVITY_8_1Ga				((float) 230)	 /* magnetometer sensitivity for 8.1 Ga full scale [LSB/Ga] */


#define HMC5983_ODR_0_75_HZ							((uint8_t) 0x00)	/* Output Data Rate = 0.75 Hz */
#define HMC5983_ODR_1_5_HZ							((uint8_t) 0x04)	/* Output Data Rate = 1.5 Hz */
#define HMC5983_ODR_3_0_HZ							((uint8_t) 0x08)	/* Output Data Rate = 3 Hz */
#define HMC5983_ODR_7_5_HZ							((uint8_t) 0x0C)	/* Output Data Rate = 7.5 Hz */
#define HMC5983_ODR_15_HZ								((uint8_t) 0x10)	/* Output Data Rate = 15 Hz */
#define HMC5983_ODR_30_HZ								((uint8_t) 0x14)	/* Output Data Rate = 30 Hz */
#define HMC5983_ODR_75_HZ								((uint8_t) 0x18)	/* Output Data Rate = 75 Hz */
#define HMC5983_ODR_220_HZ							((uint8_t) 0x1C)	/* Output Data Rate = 220 Hz */

#define	HMC5983_FS_0_88_GA							((uint8_t) 0x00)	/* Full scale = 0.88 Gauss */
#define	HMC5983_FS_1_3_GA								((uint8_t) 0x20)	/* Full scale = 1.3 Gauss */
#define	HMC5983_FS_1_9_GA								((uint8_t) 0x40)	/* Full scale = 1.9 Gauss */
#define	HMC5983_FS_2_5_GA								((uint8_t) 0x60)	/* Full scale = 2.5 Gauss */
#define	HMC5983_FS_4_0_GA								((uint8_t) 0x80)	/* Full scale = 4.0 Gauss */
#define	HMC5983_FS_4_7_GA								((uint8_t) 0xA0)	/* Full scale = 4.7 Gauss */
#define	HMC5983_FS_5_6_GA								((uint8_t) 0xC0)	/* Full scale = 5.6 Gauss */
#define	HMC5983_FS_8_1_GA								((uint8_t) 0xE0)	/* Full scale = 8.1 Gauss */

#define HMC5983_CONTINUOS_CONVERSION		((uint8_t) 0x00)	 /* Continuous-Conversion Mode */
#define HMC5983_SINGLE_CONVERSION				((uint8_t) 0x01)	 /* Single-Conversion Mode */
#define HMC5983_SLEEP										((uint8_t) 0x02)	 /* Sleep Mode */				 

#define HMC5983_TEMPSENSOR_ENABLE				((uint8_t) 0x80)	 /* Temp sensor Enable */
#define HMC5983_TEMPSENSOR_DISABLE			((uint8_t) 0x00)	 /* Temp sensor Disable */

#define HMC5983_AVERAGE_SAMPLE_1				((uint8_t) 0x00)	 /* Average 1 sample */
#define HMC5983_AVERAGE_SAMPLE_2				((uint8_t) 0x20)	 /* Average 2 sample */
#define HMC5983_AVERAGE_SAMPLE_4				((uint8_t) 0x40)	 /* Average 4 sample */
#define HMC5983_AVERAGE_SAMPLE_8				((uint8_t) 0x60)	 /* Average 8 sample */
