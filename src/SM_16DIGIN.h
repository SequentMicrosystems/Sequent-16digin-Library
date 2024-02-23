/*!
 * @file SM_16DIGIN.h
 * 
 * Designed specifically to work with the Sequent Microsysatems 
 * Sixteen LV Digital Inputs HAT for Raspberry Pi
 * 
 * ----> https://sequentmicrosystems.com/products/16-universal-inputs-card-for-raspberry-pi
 * 
 *   This card use I2C to communicate.
 *   
 *   Written by Alexandru Burcea for Sequent Microsystems
 * 
 *   Software License Agreement (BSD License)
 *
 *  Copyright (c) 2024, Sequent Microsystems 
 *  
 */
#ifndef __SM_16DIGIN__
#define __SM_16DIGIN__

#define SLAVE_OWN_ADDRESS_16DIGIN 0x20


#define INPUTS16_INPORT_REG_ADD	0x00
#define INPUTS16_OUTPORT_REG_ADD	0x02
#define INPUTS16_POLINV_REG_ADD	0x04
#define INPUTS16_CFG_REG_ADD		0x06

#define INPUTS16_CHANNEL_NR_MIN		1
#define INPUTS16_CHANNEL_NR_MAX		16

/*!
 * @brief SM_BAS class
 */
class SM_16DIGIN
{
public:
	/*!
	 * @brief Class constructor.
	 */
	SM_16DIGIN(uint8_t stack = 0);

	/*!
	 * @brief Check card presence
	 * @return Returns true is successful
	 */
	bool begin();

	/*!
	 * @brief Return card existance status
	 * @return Returns true if card is present
	 */
	bool isAlive();
	/*!
	 * @brief Read digital ports as a bitmap.
	 * @return the state of all inputs
	 */
	int readInputs();

	/*!
	 * @brief Read one digital input channel.
	 * @param channel [1..16]
	 * @return the state of one  digital input channel
	 */
	bool readInputs(uint8_t channel);
		
private:
	uint8_t _hwAdd;
	bool _detected;
	int readWord(uint8_t add, uint16_t* value);
};
#endif // __SM_16DIGIN__
