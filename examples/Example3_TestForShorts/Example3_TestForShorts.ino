/*
  This example shows how to test if there are VCC to GND shorts on the target board.

  To do this we push a small current across a 10/100 resistor divider and look at the ADC value.
  If ADC value is near 486 then there is a jumper.
  If ADC value is far from 486, there is no jumper on the target board.
  See FJ schematic 'Pre-Test' area to see the resistor and ADC setup.

  Test for shorts on the two power supplies
  testRegulator1()
  testRegulator2()

  Pete Lewis, started on 11/3/2016
  Contributions by NES November 15th, 2016

  Select Mega2560 from the boards list
*/

#define STATUS_LED 13

#include "SparkFun_Flying_Jalapeno_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_Jalapeno
FlyingJalapeno FJ(STATUS_LED, 3.3); //Blink status msgs on pin 13. Board has VCC jumper set to 3.3V.

void setup()
{
  Serial.begin(9600);
  Serial.println("Test for shorts");

  FJ.setRegulatorVoltage1(5.0); //Set regulator1 to 5V
  FJ.setRegulatorVoltage2(3.3); //Set regulator2 to 3.3V

  if(FJ.testRegulator1() == false)
  {
    Serial.println("Whoa! Short on power rail 1");
    while(1);
  }

  if(FJ.testRegulator2() == false)
  {
    Serial.println("Whoa! Short on power rail 2");
    while(1);
  }

  Serial.println("No shorts detected!");

  //Now power up the target
  //FJ.enableRegulator1();
  //FJ.enableRegulator2();
}

void loop()
{

}

