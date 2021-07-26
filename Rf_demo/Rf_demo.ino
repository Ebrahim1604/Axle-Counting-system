/*

Pin connections:
    RF module         Arduino Nano   
 1) Pin 10(OPT1) ----->   GND
 2) Pin 2,15(GND)----->   GND
 3) Pin 16(VCC)  ----->   3.3V
 4) Pin 3        ----->   A0     
 5) Pin 4        ----->   A1        
 6) Pin 9        ----->   A2
 7) Pin 11       ----->   A3

 Other connections:
 Arduio Mega:
 1) Pin A6 ----> 3.3V Led
 2) Pin A7 ----> 3.3V Led

 Note: connect the other end of the led via a 3.3K resistor to the ground
 
 IMPORTANT: Before flashing the code, both the transceivers have to be paired with each other. 
*/
 
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A6,OUTPUT);
  pinMode(A7,OUTPUT);
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(A2,LOW);
  delay(5);
    if (digitalRead(A0) == HIGH)
  {
    Serial.println("Signal received from A2");
    digitalWrite(A6,HIGH);
    while(digitalRead(A0) != LOW)
    {
      digitalWrite(A2,HIGH);
      delay(500);
      }
    digitalWrite(A6,LOW);
    }
  delay(20);

  digitalWrite(A3,LOW);
  delay(5);
    if (digitalRead(A1) == HIGH)
  {
    Serial.println("Signal received from A3");
    digitalWrite(A7,HIGH);
    while(digitalRead(A1) != LOW)
    {
      digitalWrite(A3,HIGH);
      delay(500);
      }
    digitalWrite(A7,LOW);
    }
  
  
  delay(2000);

  

}

