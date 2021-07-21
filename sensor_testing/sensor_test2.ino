const byte sensor_1 = 2;

#define time_limit 100

void setup() {

  Serial.begin(9600);
  Serial.println("_____________Axle counting test code____________");
  Serial.println("");
  Serial.println("");
  
  pinMode(sensor_1,INPUT);

}

void loop(){

  int val = digitalRead(sensor_1);
  if(val == LOW)
  {
    Serial.println("TIP");
 again:
    while(val != HIGH)
    { 
      val = digitalRead(sensor_1);
    }
    unsigned long t1 = millis();
    
    while(val != LOW)
    { 
      unsigned long t2 = millis();
      if (t2-t1>time_limit)
      {
        Serial.println("Trigger completed!");
        return;
        }
       else
       {
        val = digitalRead(sensor_1);
        Serial.println("TIP");
        }
    }

    goto again;

    
  }
 }
