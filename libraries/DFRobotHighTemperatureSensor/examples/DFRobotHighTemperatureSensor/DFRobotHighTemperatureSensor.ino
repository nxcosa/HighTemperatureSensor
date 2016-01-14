/***************************************************
 This example reads HighTemperature Sensor.
 
 Created 2016-1-13
 By berinie Chen <bernie.chen@dfrobot.com>
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here  https://www.dfrobot.com/wiki/index.php?title=HighTemperatureSensor_SKU:SEN0198
 2.This code is tested on Arduino Uno.
 ****************************************************/
#include<DFRobotHighTemperatureSensor.h>

const float voltageRef = 5.000;       //Set reference voltage,you need test your IOREF voltage. 
//const float voltageRef = 3.300;    
int HighTemperaturePin = A0;	//Setting pin
DFRobotHighTemperature PT100 = DFRobotHighTemperature(voltageRef); //Define an PT100 object

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  int temperature = PT100.readTemperature(HighTemperaturePin);  //Get temperature
  Serial.print("temperature:  ");
  Serial.print(temperature);
  Serial.println("  ^C");
  delay(1000); //just here to slow down the output so it is easier to read
}