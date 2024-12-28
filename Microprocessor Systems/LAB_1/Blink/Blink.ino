/*int sensorPin = A3;
bool x = 0;
int i=0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  //pinMode(1,OUTPUT);
  pinMode(8, INPUT_PULLUP);
}*/

// the loop function runs over and over again forever
//void loop() {
  /*digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  // wait for a second
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
  delay(1000);*/
  /*digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  delay(500); 
  digitalWrite(4, LOW); */
  //digitalWrite(3, HIGH);
  //delay(500);
  
  
 
  
//}


// PROGRAM 5
/*void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a 0.1*second
  delay(500);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  // wait for a 0.1*second
  delay(500);
  delay(1000);
} */

// PROGRAM 6

//void loop() {
  /*digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  // wait for a second
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
  delay(1000);*/
 /* digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
} */


// PROGRAM 7
/*void loop() {

  if (digitalRead(8) == LOW) { 
  digitalWrite(5, HIGH); }
  if (digitalRead(8) == HIGH) { 
  digitalWrite(5, LOW); }
  
}*/

// PROGRAM 8
/*
const int S1 = 8;const int S2 = 9;

int StanS1 = 0;int StanS2 = 0;

void setup() {
  pinMode(0,OUTPUT);pinMode(1,OUTPUT);pinMode(2,OUTPUT);pinMode(3,OUTPUT);pinMode(4,OUTPUT);pinMode(5,OUTPUT);pinMode(6,OUTPUT);pinMode(7,OUTPUT);
  pinMode(S1,INPUT);pinMode(S2,INPUT);
}

void loop() {
StanS1 = digitalRead(S1); StanS2 = digitalRead(S2);

if(StanS1 == HIGH && StanS2 == LOW){
 digitalWrite(0, HIGH);delay(200);
 digitalWrite(1, HIGH);delay(200);
 digitalWrite(2, HIGH);delay(200);
 digitalWrite(3, HIGH);delay(200);
 digitalWrite(4, HIGH);delay(200);
 digitalWrite(5, HIGH);delay(200);
 digitalWrite(6, HIGH);delay(200);
 digitalWrite(7, HIGH);delay(200);
 digitalWrite(0, LOW);delay(200);
 digitalWrite(1, LOW);delay(200);
 digitalWrite(2, LOW);delay(200);
 digitalWrite(3, LOW);delay(200);
 digitalWrite(4, LOW);delay(200);
 digitalWrite(5, LOW);delay(200);
 digitalWrite(6, LOW);delay(200);
 digitalWrite(7, LOW);delay(200);
}else if(StanS1 == LOW && StanS2 == LOW){
 digitalWrite(7, HIGH);delay(200);
 digitalWrite(6, HIGH);delay(200);
 digitalWrite(5, HIGH);delay(200);
 digitalWrite(4, HIGH);delay(200);
 digitalWrite(3, HIGH);delay(200);
 digitalWrite(2, HIGH);delay(200);
 digitalWrite(1, HIGH);delay(200);
 digitalWrite(0, HIGH);delay(200);
 digitalWrite(7, LOW);delay(200);
 digitalWrite(6, LOW);delay(200);
 digitalWrite(5, LOW);delay(200);
 digitalWrite(4, LOW);delay(200);
 digitalWrite(3, LOW);delay(200);
 digitalWrite(2, LOW);delay(200);
 digitalWrite(1, LOW);delay(200);
 digitalWrite(0, LOW);delay(200);
}if(StanS1 == HIGH && StanS2 == HIGH){
 digitalWrite(0, HIGH);delay(200);
 digitalWrite(1, HIGH);delay(200);
 digitalWrite(0, LOW);delay(200);
 digitalWrite(2, HIGH);delay(200);
 digitalWrite(1, LOW);delay(200);
 digitalWrite(3, HIGH);delay(200);
 digitalWrite(2, LOW);delay(200);
 digitalWrite(4, HIGH);delay(200);
 digitalWrite(3, LOW);delay(200);
 digitalWrite(5, HIGH);delay(200);
 digitalWrite(4, LOW);delay(200);
 digitalWrite(6, HIGH);delay(200);
 digitalWrite(5, LOW);delay(200);
 digitalWrite(7, HIGH);delay(200);
 digitalWrite(6, LOW);delay(200);
 digitalWrite(7, LOW);delay(200);
}else if(StanS1 == LOW && StanS2 == HIGH){
 digitalWrite(7, HIGH);delay(200);
 digitalWrite(6, HIGH);delay(200);
 digitalWrite(7, LOW);delay(200);
 digitalWrite(5, HIGH);delay(200);
 digitalWrite(6, LOW);delay(200);
 digitalWrite(4, HIGH);delay(200);
 digitalWrite(5, LOW);delay(200);
 digitalWrite(3, HIGH);delay(200);
 digitalWrite(4, LOW); delay(200);
 digitalWrite(2, HIGH); delay(200);
 digitalWrite(3, LOW); delay(200);
 digitalWrite(1, HIGH); delay(200);
 digitalWrite(2, LOW); delay(200);
 digitalWrite(0, HIGH);delay(200);
 digitalWrite(1, LOW); delay(200);
 digitalWrite(0, LOW); delay(200);
}
}*/

// PROGRAM 8C

int t = 500, i = 0, j = 0, k = 0, a = -1, w = 0, s=0, b = 0, l = 0, sw3 = 0, r = 0;
void setup() {

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
    
  pinMode(8, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}


void loop() {

  //if (digitalRead(13) == LOW) digitalWrite(3, HIGH);
  //else digitalWrite(3, LOW);

if (sw3 == 0){
  k = (i-a)%8;
  j = i%8;
  if(j == 7 || j == 0) a = -a;


  digitalWrite(j, HIGH);
  digitalWrite(k, LOW);
  delay(t);                      

  i+=a;
} else {
    
    digitalWrite(r, LOW);
    r = random(8);
    digitalWrite(r, HIGH);
    delay(1000);
}

  if (digitalRead(8) == LOW && s == 0) {
    s = 1;
    a = -a;
    //digitalWrite(3, HIGH);
    //delay(3000);
  }



// switch 2 -------------------------------------
  if (digitalRead(9) == LOW && s == 0 && b == 0) {
    s = 1; b = 1;
    a = 3;
    //digitalWrite(3, HIGH);
    //delay(3000);
  }
  else if (digitalRead(9) == LOW && s == 0 && b == 1){
    s = 1; b = 0; a = -1;
    for (l = 0; l < 8; l++)
      digitalWrite(l, LOW);
  }

//switch 3 --------------------

  w = analogRead(A3);
  if (w <= 2 && s == 0 && sw3 == 0) {
    s = 1; sw3 = 1;
    for (l = 0; l < 8; l++)
      digitalWrite(l, LOW);
    
  }
  else if (w <= 2 && s == 0 && sw3 == 1) {
    s = 1;
    for (l = 0; l < 8; l++)
      digitalWrite(l, LOW);
    sw3 = 0;
  }



  if(s == 1) {
    delay(2000); s = 0;
  }



}

  
