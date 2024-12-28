/////////////////////////////////////////////////
// TIMERY

//#include <D:\Dysk_moje_Kuba\Arduino\Timers.h>
//#include <D:\Dysk_moje_Kuba\Arduino\arduino_timer-2.3.1\src\arduino-timer.h>
//#include <D:\Dysk_moje_Kuba\Arduino\arduino_timer-2.3.1\src\timer.h>
//#include <arduino-timer.h>
/*Timer ledBlinkTimer;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  ledBlinkTimer.begin(SECS(2));
}

void loop() {
  if (ledBlinkTimer.available())
  {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    ledBlinkTimer.restart();
  }
}*/

///////////////////////////////////////////////////////////////
// PRZERWANIA

//Do obsługi przerwań służy funkcja “attachInterrupt”

//attachInterrupt(int, func, mode);

/*int – numer przerwania 0 lub 1 w zależności od pinu
func – nazwa fukcji obsługującej przerwanie
mode – ustala kiedy przerwanie ma być wywołane:
LOW – kiedy na pinie jest stan niski;
CHANGE – kiedy zmienia się stan;
RISING – kiedy zmienia się stan z LOW na HIGH;
FALLING – kiedy zmienia się stan z HIGH na LOW.
Program licznika z użyciem przerwania będzie wyglądał tak: */

word steps;

void setup()
{
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  attachInterrupt(8, onStep, FALLING);
}

void loop()
{
}

void onStep()
{
  static unsigned long lastTime;
  unsigned long timeNow = millis();
  if (timeNow - lastTime < 5)
  {
    digitalWrite(5, HIGH);
  }
    return;
    
  steps++;
  Serial.println(steps);
  lastTime = timeNow;
}
