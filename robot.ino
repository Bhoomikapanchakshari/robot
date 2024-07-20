#include<Servo.h>
 Servo myservo;  // create Servo object to control a servo

#define echopin 8
#define trigger 9
#define Mla 4
#define Mlb 5
#define Mra 6
#define Mrb 7
long duration,distance;
void setup() {
  myservo.attach(9);
  pinMode(echopin,INPUT);
  pinMode(trigger,OUTPUT);
  pinMode(Mla,OUTPUT);
  pinMode(Mlb,OUTPUT);
  pinMode(Mra,OUTPUT);
  pinMode(Mrb,OUTPUT);
  
}

void loop() {
  Serial.begin(9600);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echopin,HIGH);
  distance=duration/58.2;
  Serial.println(distance);
  delay(10);
  if(distance>15){
    myservo.attach(90);
    digitalWrite(Mrb,LOW);
    digitalWrite(Mra,HIGH);
    digitalWrite(Mlb,LOW);
    digitalWrite(Mla,HIGH);
    
  }
    else if((distance<10)&&(distance>0)){
      digitalWrite(Mrb,LOW);
      digitalWrite(Mra,LOW);
      digitalWrite(Mlb,LOW);
      digitalWrite(Mla,LOW);
      delay(100);
      myservo.write(0);
      delay(500);
      myservo.write(180);
      delay(500);
      myservo.write(90);
      delay(500);
      digitalWrite(Mrb,HIGH);
      digitalWrite(Mra,LOW);
      digitalWrite(Mlb,HIGH);
      digitalWrite(Mla,LOW);
      delay(500);
      digitalWrite(Mrb,LOW);
      digitalWrite(Mra,LOW);
      digitalWrite(Mla,LOW);
      digitalWrite(Mlb,LOW);
      delay(100);
      digitalWrite(Mrb,LOW);
      digitalWrite(Mra,LOW);
      digitalWrite(Mla,HIGH);
      digitalWrite(Mlb,LOW);
      delay(500);
    }                         
}
