#define PLAY_E 13
#define REC 11
#define playTime 5000
#define recordTime 3000
#define servoPin 13
#define inputPin 8
#include <Servo.h>
 
Servo servoRight;
Servo servoLeft;
int Right = 9;
int Left = 2;
int angle = 0;               
int pirState = LOW;             
int val = 0;          
 
void setup() 
{
  pinMode(servoPin, OUTPUT);      
  pinMode(inputPin, INPUT);    
  pinMode(PLAY_E, OUTPUT);
  pinMode(REC,OUTPUT);
  servoRight.attach(Right);
  servoLeft.attach(Left);
  Serial.begin(9600);
}
 
void loop()
{
  val = digitalRead(inputPin);
  if (val == HIGH) 
  {
    servoLeft.write(0);
    servoRight.write(180);
    delay(500);
    servoLeft.write(130);
    servoRight.write(50);
    delay(500);
    servoLeft.write(0);
    servoRight.write(180);

    digitalWrite(PLAY_E, HIGH);
    delay(50);
    digitalWrite(PLAY_E, LOW);  
    Serial.println("Playback Started");  
    delay(playTime);

  }
    
  if (pirState == LOW) 
  {
    Serial.println("Motion detected!");
    pirState = HIGH;
  }
  else 
  {
    digitalWrite(servoPin, LOW);
    if (pirState == HIGH)
    {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
  if(REC == 1)
  {
     digitalWrite(REC, HIGH);
     Serial.println("Recording started");
     delay(recordTime);
     digitalWrite(REC, LOW);
     Serial.println("Recording stopped");
  }
  delay(500);
}
