#include <SoftwareSerial.h>
#define fsr_pin A0
#define fsr_pin1 A1
#define fsr_pin2 A2
#define ledpin2 2
#define ledpin3 3
#define ledpin4 4
#define ledpin5 5
#define buzzer 7

SoftwareSerial BT(10,11);

int btnpin = 6;
int buttonOn = 0;
int count=0;
int i=1;
int j=2;
int k=3;
int l=4;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(btnpin, INPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);
  pinMode(ledpin5, OUTPUT);
  pinMode(buzzer, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  BT.write("a");
  int fsr_value = analogRead(fsr_pin);
  int fsr_value1 = analogRead(fsr_pin1);
  int fsr_value2 = analogRead(fsr_pin2);
  Serial.println(fsr_value);
  Serial.println(fsr_value1);
  Serial.println(fsr_value2);

  byte cmmd[1];
  cmmd[0]=0;
  int insize;
  if((insize=(BT.available()))>0){
    Serial.print("input size = "); 
    Serial.println(insize);
    cmmd[0]=char(BT.read());
    Serial.println(cmmd[0]);
  }
      
   if(cmmd[0]==48){
      if (fsr_value > 70){
        Serial.println(111111);
        LED1(i);
      }
    }
    else if(cmmd[0]==49){
      if (fsr_value1 > 70){
        Serial.println(222222);
        LED2(j);
      }
    }
    else if(cmmd[0]==50){
      if (fsr_value2 > 70)
        LED3(k);
    }
    else if(cmmd[0]==52){
      call(l);
    }
    
      
   buttonOn = digitalRead(btnpin);
        Serial.println(buttonOn);
        Serial.println(count);
        if (buttonOn == 1) {
            count++;
          Serial.println(count+"A2");
         }
      if(count%2==1){
          alarmBeep(buzzer);
          digitalWrite(ledpin2, HIGH);
          digitalWrite(ledpin3, HIGH);
          digitalWrite(ledpin4, HIGH);
          
          delay(1000);    
          }
          else{
          digitalWrite(ledpin2, LOW);
          digitalWrite(ledpin3, LOW);
          digitalWrite(ledpin4, LOW);
          
          
          }
  delay(1000);
  Serial.println("--------------");
}


void LED1(int i){
  int x=1;
      if(x==i){
        Serial.println(100001);
      int fsr_value = analogRead(fsr_pin);
      int fsr_value1 = analogRead(fsr_pin1);
      int fsr_value2 = analogRead(fsr_pin2);
      
      while(fsr_value > 70){
      alarmBeep(buzzer);
      digitalWrite(ledpin2, HIGH);
      delay (300);
      digitalWrite(ledpin2, LOW);
      delay (300);
      fsr_value = analogRead(fsr_pin);
      fsr_value1 = analogRead(fsr_pin1);
      fsr_value2 = analogRead(fsr_pin2);
      
      if(fsr_value1 <= 70){
        digitalWrite(ledpin5, HIGH);
        delay (300);
        digitalWrite(ledpin5, LOW);
        delay (300);
        }
      if(fsr_value2 <= 70){
        digitalWrite(ledpin5, HIGH);
        delay (300);
        digitalWrite(ledpin5, LOW);
        delay (300);
        }
      }
        BT.write("b");
      }
}

void LED2(int i){
  Serial.println(i);
  int x=2;
  if(x==i){
        Serial.println(100002);
      int fsr_value1 = analogRead(fsr_pin1);
      int fsr_value2 = analogRead(fsr_pin2);
      
      while(fsr_value1 > 70){
      alarmBeep(buzzer);
      digitalWrite(ledpin3, HIGH);
      delay (300);
      digitalWrite(ledpin3, LOW);
      delay (300);
      fsr_value1 = analogRead(fsr_pin1);
      fsr_value2 = analogRead(fsr_pin2);
      
      if(fsr_value2 <= 70){
        digitalWrite(ledpin5, HIGH);
        delay (300);
        digitalWrite(ledpin5, LOW);
        delay (300);
        }
      }
      
        BT.write("b");
  }
}

void LED3(int i){
  int x=3;
  if(x==i){
      int fsr_value2 = analogRead(fsr_pin2);
      while (fsr_value2 > 70){
      alarmBeep(buzzer);
      digitalWrite(ledpin4, HIGH);
      delay (300);
      digitalWrite(ledpin4, LOW);
      delay (300);
      fsr_value2 = analogRead(fsr_pin2);
      }
        BT.write("b");
        Serial.println(100003);
  }
}

void call(int i){
  int x=4;
  if(x=i){
      while(1){
      buttonOn = digitalRead(btnpin);
      if (buttonOn == 1) {
          break;
       }
       else{
          alarmBeep(buzzer);
          digitalWrite(ledpin2, HIGH);
          digitalWrite(ledpin3, HIGH);
          digitalWrite(ledpin4, HIGH);
          
          delay(1000);   
      }
  }
  }
}

void alarmBeep(int pin) {
  tone(pin, 5200, 100);
  delay(1); 
  }


