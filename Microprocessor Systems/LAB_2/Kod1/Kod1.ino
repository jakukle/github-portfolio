
int t = 500, i = 0, j = 0, k = -1, a = 1, w = 0, s=0, b = 0, l = 0, sw3 = 0, r = 0;
unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzas = 0;
unsigned long roznicaCzasu = 0;
 
void setup(){
  Serial.begin(9600);

  
 // pinMode(0, OUTPUT);
 // pinMode(1, OUTPUT);
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
 
void loop(){

  //Pobierz liczbe milisekund od startu
  aktualnyCzas = millis();
  roznicaCzasu = aktualnyCzas - zapamietanyCzas;
  
  //Jeśli różnica wynosi ponad sekundę
  if (roznicaCzasu >= 500) {
    //Zapamietaj aktualny czas
    zapamietanyCzas = aktualnyCzas;
    //Wyslij do PC

  digitalWrite(k+2, LOW);
  digitalWrite(j+2, HIGH);

 
     i+=a;
    k = (i-a)%6;
    j = i%6;
 
       if(j == 5 || j == 0) a = -a;

}
}
