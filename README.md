# Sequent-16digin-Library
Arduino library for Sequent Microsystems [Sixteen LV Digital Inputs 8-Layer Stackable HAT](https://sequentmicrosystems.com/products/sixteen-lv-digital-inputs-card-for-raspberry-pi)

## Install
### Library manager
Go to **Tools**>>**Manage Libraries..** menu and search for *SM_16DIGIN* and click install 
### Manual install
To download click <>Code > [Download ZIP](https://github.com/SequentMicrosystems/Sequent-16digin-Library/archive/refs/heads/main.zip) button from the main [page](https://github.com/SequentMicrosystems/Sequent-16digin-Library), rename the uncompressed folder to "SM_16DIGIN" 
and copy to the libraries subdirectory of your sketchbook directory ("This PC > Documents > Arduino > libraries" for a Windows PC
 or "Home > arduino > libraries" on Linux PC). Now launch the Arduino environment. If you open the Sketch > Include Library menu, you should see SM_TC inside. 
 The library will be compiled with sketches that use it. Open an arduino sketch, go to File > Examples > SM_16DIGIN > and chose your example to run.

## Usage
There are three ways to control the Sixteen LV Digital Inputs Card from the Arduino environment.

### Method 1: Using any Arduino controller
You can use this method with any Arduino card with an I2C port by connecting I2C-SDA, I2C-SCL, +5V and GND, as shown in the following table.
      
| SIGNAL | PIN# |CONN| PIN# | SIGNAL|
|---|---|---|---|---|
| | --1 | O - O | 2-- |  +5V | 
| I2C-SDA | --3| O - O | 4-- |  +5V |
| I2C-SCL |-- 5|O - O| 6--|  GND |
|  |-- 7|O - O| 8--||
| GND |-- 9|O - O|10--||
| |--11|O - O|12--||
| |--13|O - O|14--| GND|
| |--15|O - O|16--||
||--17|O - O|18--||
||--19|O - O|20--|  GND|
||--21|O - O|22--||
||--23|O - O|24--||
|GND |--25|O - O|26--||
||--27|O - O|28--||
||--29|O - O|30--|  GND|
||--31|O - O|32--||
||--33|O - O|34--|  GND|
||--35|O - O|36--||
||--37|O - O|38--||
|GND |--39|O - O|40--||
 
### Method 2: Using the SM Arduino Raspberry Pi Replacement Kit
Sequent Microsystems [Arduino Uno, Nano, Teensy, Feather or ESP32 Raspberry Pi Replacement Kit](https://sequentmicrosystems.com/products/raspberry-pi-replacement-card) is an inexpensive adapter which can be used to control any of our HATs using Uno, Nano, Teensy, Feather or ESP32. Plug the Home Automation HAT into the 40 pin connector of the adapter and write your Arduino software.

### Method 3: Using the [SM ESP32-Pi Raspberry Pi Alternative Card](https://sequentmicrosystems.com/collections/all-io-cards/products/esp32-pi-low-cost-replacement-for-raspberry-pi)
ESP32-Pi is a Raspberry Pi alternate solution which can control directly the Eight Thermocouples DAQ HAT.
In your sketchbook set the board type to DOIT ESP32 DEVKIT V1: Tool >> Board >> ESP32 Arduino >> DOIT ESP32 DEVKIT V1

## Function prototypes
```
/*!
 * @brief Class constructor.
 */
SM_16DIGIN(uint8_t stack = 0);

/*!
 * @brief Check card presence
 * @return Returns true if successful
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
```
