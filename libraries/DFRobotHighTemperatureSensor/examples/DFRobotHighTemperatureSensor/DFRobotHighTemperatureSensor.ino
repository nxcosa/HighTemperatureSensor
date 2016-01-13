#include<DFRobotHighTemperatureSensor.h>

const float voltageRef = 5.000; //Set reference voltage,you need test your IOREF voltage. 
int HighTemperaturePin = A0;	//Setting pin
DFRobotHighTemperature PT100 = DFRobotHighTemperature(voltageRef); //Define an PT100 object

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  int temperature = PT100.readTemperature(HighTemperaturePin);  //Get temperature
  Serial.print("temperature:  ");
  Serial.println(temperature);
  delay(1000); //just here to slow down the output so it is easier to read
}

