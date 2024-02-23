extern "C" {
#include <inttypes.h>
}

#include "Arduino.h"
#include "Wire.h"
#include "SM_16DIGIN.h"

const uint16_t pinMask[INPUTS16_CHANNEL_NR_MAX] = { 0x8000, 0x4000, 0x2000, 0x1000, 0x0800, 0x0400, 0x0200, 0x0100, 
			      0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

SM_16DIGIN::SM_16DIGIN(uint8_t stack)
{
	if (stack > 7)
		stack = 7;
	_hwAdd = SLAVE_OWN_ADDRESS_16DIGIN + stack ^ 0x07;
	_detected = false;
}

bool SM_16DIGIN::begin()
{
	uint16_t value = 0;
	Wire.begin();
	if (0 == readWord(INPUTS16_CFG_REG_ADD, &value))
	{
		_detected = true;
	}
	return _detected;
}

bool SM_16DIGIN::isAlive()
{
	return _detected;
}

int SM_16DIGIN::readInputs()
{
	int ret = 0;
	uint16_t val = 0;
	int i = 0;
	
	ret = readWord(INPUTS16_INPORT_REG_ADD, &val);
	if (ret < 0)
		return ret;
	ret = 0;
	val = ~val;
	for(i = 0; i < INPUTS16_CHANNEL_NR_MAX; i++)
	{
		if ((val & (pinMask[i])))
		{
			ret += 1 << i;
		}
	}
	return ret;
}

bool SM_16DIGIN::readInputs(uint8_t channel)
{
	int ret = 0;
	uint16_t val = 0;
	
	if ((channel > INPUTS16_CHANNEL_NR_MAX) || (channel < 1))
		return false;

	ret = readWord(INPUTS16_INPORT_REG_ADD, &val);
	if (ret < 0)
		return false;
	
	if (val & (pinMask[channel - 1]) == 0)
	{
		return true;
	}
	return false;
}

/*
 ***************** 16DIGIN_I2C access functions ****************************
 **********************************************************************
 */
 
 int SM_16DIGIN::readWord(uint8_t add, uint16_t *value)
{
	uint8_t buff[2];

	if (0 == value)
	{
		return -1;
	}
	//Wire.begin();
	Wire.beginTransmission(_hwAdd);
	Wire.write(add);
	if (Wire.endTransmission() != 0)
	{
		return -1;
	}
	Wire.requestFrom(_hwAdd, (uint8_t)2);
	if (2 <= Wire.available())
	{
		buff[0] = Wire.read();
		buff[1] = Wire.read();
	}
	else
	{
		return -1;
	}
	memcpy(value, buff, 2);
	return 0;
}

