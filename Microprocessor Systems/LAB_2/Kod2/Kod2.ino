#include <D:\Dysk_moje_Kuba\Arduino\arduino_timer-2.3.1\src\arduino-timer.h>
#include "PinChangeInterrupt.h"

auto timer = timer_create_default();




int t = 500, i = 0, j = 0, k = 0, a = -1, w = 0, s=0, b = 0, l = 0, sw3 = 0, r = 0, it = 1;
unsigned long licznik = 0;

//bool fn();
bool fn(){
  /*k = (i-it)%8;
  j = i%8;
  if(j == 7 || j == 0) it = -it;

  digitalWrite(j, HIGH);
  digitalWrite(k, LOW); 
  i+=it;*/
  k = (i-a)%8;
  j = i%8;
  if(j == 7 || j == 0) a = -a;


  digitalWrite(j, HIGH);
  digitalWrite(k, LOW);                    

  i+=a;
  return true;
}

void wechsel(){
  /*if (s == 0) a = -a;
  s = 1;*/
//digitalWrite(6, HIGH);
a = -a;
}

void setup() {


  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, INPUT_PULLUP);
    
  timer.every(1000, fn); 
  
//attachInterrupt(digitalPinToInterrupt(4), wechsel, RISING);
attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(8), wechsel, FALLING);
}


void loop() {

timer.tick();
/*if (s == 1){
  if (licznik == 200000) { //okolo 1s
    s = 0;
    digitalWrite(6, HIGH);
    licznik = 0;
  }
  licznik++;
  //delay(1000); s = 0;
}
*/

//delay(2000);
//digitalWrite(4, HIGH);

/*if (digitalRead(8) == LOW && s == 0) {
    s = 1;
    //a = -a;
    digitalWrite(2, HIGH);
    //delay(3000);
}*/

}
