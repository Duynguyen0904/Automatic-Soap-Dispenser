#include <Servo.h>   
Servo servo;   
int echoPin = 5;  
int trigPin = 6;   
int servoPin = 7;
long duration, dist, average;   
long avg[3];
void setup() {    
  Serial.begin(9600);
  servo.attach(servoPin);  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  servo.write(0);
  delay(100);
  servo.detach(); 
} 
void measure() {  
    digitalWrite(10,HIGH);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    dist = (duration/58);      
    Serial.println(dist);
    delay(100);
}
void loop() { 
    for (int i=0;i<=2;i++) {
    measure();            
    avg[i]=dist;          
    delay(10);
  }
 dist=(avg[0]+avg[1]+avg[2])/3;  
if ( dist<5 ) {
   servo.attach(servoPin);
   servo.write(0);  
   delay(3000);     
   servo.write(200);  
   delay(1000);
   servo.detach();
}    } 
