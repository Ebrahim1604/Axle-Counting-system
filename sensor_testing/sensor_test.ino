/*
 Pin connections:
    Sensor1      Arduino Nano   
 1) output        2
 2) GND           GND/Power supply(-)
 3) VCC           Power supply(+)

   Sensor2       Arduino Nano   
 1) output        3
 2) GND           GND/Power supply(-)
 3) VCC           Power supply(+)

 Note: Please make sure GND of Arduino is made common to Power supply(-)
 */

const byte sensor_1 = 2;
const byte sensor_2 = 3;

float count_1 = 0.0;
float count_2 = 0.0;

void setup() {

  Serial.begin(9600);
  Serial.println("_____________Axle counting test code____________");
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(sensor_1), isr_1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(sensor_2), isr_2, CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Count1 = ");
  Serial.print(count_1);
  Serial.print(", ");
  Serial.print("count_2 = ");
  Serial.print(count_2);
  Serial.print(", ");
  Serial.print("Total count = ");
  Serial.println((count_1+count_2)/2.0);
  delay(20);
}

void isr_1()
{ 
  count_1 = count_1 + 0.5;
}

void isr_2()
{ 
  count_2 = count_2 + 0.5;
}


