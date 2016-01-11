#include<HighTemp.h>
HighTemp sensorA= HighTemp(5.000);
void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  int tempA = sensorA.getTemp(A0);
  Serial.print("PT100A:  ");
  Serial.println(tempA);
  delay(1000); //just here to slow down the output so it is easier to read
}

