
#include<Servo.h>
Servo Myservo;
int pos;
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(2,OUTPUT);//GREEN LIGHT
   pinMode(4,OUTPUT);//RED LIGHT
  pinMode(8,OUTPUT);//WHITE LIGHT
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);

   if(cm < 20){
      digitalWrite(2,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(4,LOW);
      Myservo.attach(3);
        for(pos=0;pos<=180;pos++)
        {
          Myservo.write(pos);  
        }
    delay(1000);
      for(pos=180;pos>=0;pos--){
        Myservo.write(pos);
        delay(100);
  if(pos == 0){
    Myservo.detach();
  }
}

  }else if(cm >= 25 && cm <= 100){
         digitalWrite(8,HIGH);
          digitalWrite(2,LOW);
          digitalWrite(4,HIGH);
  }
    else{
      digitalWrite(4,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(8,LOW);
    pos=0;
    Myservo.detach();
    delay(1000);
  }
}// closes loop
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}