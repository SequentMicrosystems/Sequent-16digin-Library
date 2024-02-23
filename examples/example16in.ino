/*!
*   Inputs change detect example for Sequent Microsystems Sixteen LV Digital Inputs 8-Layer Stackable HAT for Raspberry Pi
*   -->https://sequentmicrosystems.com/products/16-universal-inputs-card-for-raspberry-pi
*   Requirments: Any arduino card with I2C, Sixteen LV Digital Inputs HAT from Sequent Microsystems
*
*   Method 1:
*     Connect I2C bus, 5V and GND from Arduino card to Sixteen LV Digital Inputs hat, pin map below
*    SIGNAL  CONNECTOR    SIGNAL\n
*     ---------------------------
*          -- 1|O O| 2--  +5V
*  I2C SDA -- 3|O O| 4--  +5V
*  I2C SCL -- 5|O O| 6--  GND
*          -- 7|O O| 8--
*      GND -- 9|O O|10--
*          --11|O O|12--
*          --13|O O|14--  GND
*          --15|O O|16--
*          --17|O O|18--
*          --19|O O|20--  GND
*          --21|O O|22--
*          --23|O O|24--
*      GND --25|O O|26--
*          --27|O O|28--
*          --29|O O|30--  GND
*          --31|O O|32--
*          --33|O O|34--  GND
*          --35|O O|36--
*          --37|O O|38--
*      GND --39|O O|40--
*
*   Method 2:
*   Use sequent Microsystems Uno, Nano, Teensy,Feather, ESP32 Raspberry Pi Replacement Kit with prefered arduino processor
*   -->https://sequentmicrosystems.com/collections/accessories/products/raspberry-pi-replacement-card
*
*   Method 3:
*    Use Sequent Microsysstems ESP32 Pi replacement connected directly with the Sixteen LV Digital Inputs card.
*    Set the board type to DOIT ESP32 DEVKIT V1: Tool >> Board >> ESP32 Arduino >> DOIT ESP32 DEVKIT V1
*    -->https://sequentmicrosystems.com/collections/all-io-cards/products/esp32-pi-low-cost-replacement-for-raspberry-pi
*/
#include "SM_16DIGIN.h"

SM_16DIGIN card(0);// Sixteen LV Digital Inputs HAT with stack level 0 (no jumpers installed)

void setup() {
  Serial.begin(115200);
  delay(2000);

  if (card.begin() )
  {
    Serial.print("Sixteen LV Digital Inputs 8-Layer Stackable HAT for Raspberry Pi detected\n");
  }
  else
  {
    Serial.print("Sixteen LV Digital Inputs 8-Layer Stackable HAT for Raspberry Pi NOT detected!\n");
  }
}

static int lastState = 0;
static int currentState = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int ret = card.readInputs();
  if (ret < 0)
  {
    Serial.print("Read ERROR!\n");
  }
  else
  {
    currentState = ret;
    if (lastState != currentState)
    {
      for (int i = 0; i < 16; i++)
      {
        if ((lastState & (1 << i)) != (currentState & (1<<i)))
        {
          Serial.print("Input #");
          Serial.print(i + 1);
          Serial.print(" has changed to");
          if ((currentState & (1 << i)) != 0)
          {
            Serial.print(" 1\n");
          }
          else
          {
            Serial.print(" 0\n");
          }
        }
      }
    }
    lastState = currentState;
  }
  delay(100);// debounce delay
}
