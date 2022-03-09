#include <Servo.h>

int pos = 0; // promenna pro pozici zavor
int buttonState;  
int svit = 0; // promenna pro svit bilych ledek
Servo servo1; // servo 1
Servo servo2; // servo 2

void setup() {
  pinMode(2, INPUT_PULLUP); // tlacitko
  pinMode(10, OUTPUT); // cervena led
  pinMode(12, OUTPUT); // cervena led
  pinMode(11, OUTPUT); // bila led
  pinMode(5, OUTPUT); // cervena led
  pinMode(7, OUTPUT); // cervena led
  pinMode(6, OUTPUT); // bila led
  pinMode(4, OUTPUT); // servo 1
  pinMode(3, OUTPUT); // servo 2
}

void loop() {
  
  servo1.attach(4);
  servo2.attach(3);
  servo1.write(180);
  servo2.write(180);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  buttonState = digitalRead(2);
  
  // udelej tohle kdyz se tlacitko stiskne
  
      if(buttonState==LOW){
          zavory();
        }
        

 // for, ktery rozsvicuje a zhasina bilou led
 
      for(int i = 0;i<255;i+=10){
           analogWrite(6,i);
           analogWrite(11,i);
           delay(25);
         }   
          
      for(int i = 250;i>0;i-=10){
           analogWrite(6,i);
           analogWrite(11,i);
           delay(25);
         }

        
  analogWrite(6,LOW);
  analogWrite(11,LOW);
  delay(550);
  
}

//funkce ktera se spusti pri stisknuti tlacitka

void zavory(){
  
  //for na blikajici svetla
  
      for(int i =0;i<5;i++){
           analogWrite(11, 0);   
           analogWrite(6, 0); 
           delay(350);
           digitalWrite(5, HIGH);
           digitalWrite(7, LOW);
           digitalWrite(10, HIGH);
           digitalWrite(12, LOW);
           delay(350);
           digitalWrite(5, LOW);
           digitalWrite(7, HIGH);
           digitalWrite(10, LOW);
           digitalWrite(12, HIGH);
         }
         
  //for na polozeni zavor
         
       for (pos = 180; pos >= 90; pos -= 1){
           digitalWrite(5, LOW);
           digitalWrite(7, LOW);
           digitalWrite(10, LOW);
           digitalWrite(12, LOW);
           servo1.write(pos);  
           servo2.write(pos);             
           delay(20);                  
         }
       
       servo1.write(90);
       servo2.write(90);  
  
   //for na blikajici svetla       
    
       for(int i =0;i<10;i++){
           analogWrite(11, 0);   
           analogWrite(6, 0); 
           delay(350);
           digitalWrite(5, HIGH);
           digitalWrite(7, LOW);
           digitalWrite(10, HIGH);
           digitalWrite(12, LOW);
           delay(350);
           digitalWrite(5, LOW);
           digitalWrite(7, HIGH);
           digitalWrite(10, LOW);
           digitalWrite(12, HIGH);
         }
         
    //for na zvednuti zavor    
    
         for (pos = 90; pos <= 180; pos += 1){
           digitalWrite(5, LOW);
           digitalWrite(7, LOW);
           digitalWrite(10, LOW);
           digitalWrite(12, LOW);
           servo1.write(pos);  
           servo2.write(pos);             
           delay(20);                  
         }

  servo1.write(180);
  servo2.write(180);     

  delay(50);
  
}
  
 

    
