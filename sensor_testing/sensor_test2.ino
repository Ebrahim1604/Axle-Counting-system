/*
 Pin connections:
    Sensor1      Arduino Nano   
 1) output        2
 2) GND           GND/Power supply(-)
 3) VCC           Power supply(+)

   Sensor2      Arduino Nano   
 1) output        3
 2) GND           GND/Power supply(-)
 3) VCC           Power supply(+)

 Note: Please make sure GND of Arduino is made common to Power supply(-)
 */

const byte sensor_1 = 2;

void setup() {

  Serial.begin(9600);
  Serial.println("_____________Axle counting test code____________");
  Serial.println("");
  Serial.println("");
  
  pinMode(sensor_1,INPUT);

}

void loop(){

  int val = digitalRead(sensor_1);
  Serial.println(val);
  
  if(val == LOW)
  {
    unsigned long t1 = millis();
    
    while(val != HIGH)
    { 
      val = digitalRead(sensor_1);
    }
    
    unsigned long t2 = millis();
    Serial.print("Sensor triggered for: ");
    Serial.print(t2-t1);
    Serial.println(" millisecs");
  }
 }
