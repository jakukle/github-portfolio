#include <WiFi.h>
#include <WiFiClient.h>
#include <math.h>
#include <WiFiAP.h>


const char* ssid = "AndroidKuba";
const char* password = "projekt123";

//ssid dom lc: ZTE_E257FF
//password dom lc: abcdefgh

//ssid gliwice: Nazwa sieci
//password gliwice: 12345678

WiFiServer server(80);

//zmienna mówiąca czy chcemy autorefreshing
bool autoRefresh = 0;
String StanAutoRefresh;

// Variable to store the HTTP request 
String header;
//Variable to store current position of doors
String position;

//zmienna pomocnicza
int onlyOnce = 0;

//zmienne do zbierania statystyk
int totalCount = 0;
int dinnerCount= 0;
int lunchCount = 0;
int breakfastCount = 0;
String StanDogAround;

//variables to store the current output state //NWM CZY POTRZEBNE
//String outputClosedState = "off";
//String outputBreakfastState = "off";
//String outputLunchState = "off";
//String outputDinnerState = "off";

//PRZYPISANIE PINÓW
//czujniki
const int sensorBreakfast = 34;
const int sensorLunch = 35;
const int sensorDinner = 32;
const int sensorDog = 4;

//diody
const int outputClosed = 18;
const int outputBreakfast = 19;
const int outputLunch = 22;
const int outputDinner = 23;

//buzzer
const int pinBuzzer = 13;

//silnik
const int stepperPIN_1 = 27; //IN1
const int stepperPIN_2 = 26; //IN2 
const int stepperPIN_3 = 25; //IN3
const int stepperPIN_4 = 33; //IN4


// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds 
const long timeoutTime = 2000;

void setup() {

  Serial.begin(115200); 
  pinMode(outputClosed, OUTPUT);
  pinMode(outputBreakfast, OUTPUT);
  pinMode(outputLunch, OUTPUT);
  pinMode(outputDinner, OUTPUT);

  pinMode (pinBuzzer,OUTPUT);

  pinMode(stepperPIN_1, OUTPUT);
  pinMode(stepperPIN_2, OUTPUT);
  pinMode(stepperPIN_3, OUTPUT);
  pinMode(stepperPIN_4, OUTPUT);

  pinMode(sensorBreakfast, INPUT);
  pinMode(sensorLunch, INPUT);
  pinMode(sensorDinner, INPUT);
  pinMode(sensorDog, INPUT);
  
  digitalWrite(outputClosed, LOW);
  digitalWrite(outputBreakfast, LOW);
  digitalWrite(outputLunch, LOW);
  digitalWrite(outputDinner, LOW);
  digitalWrite(pinBuzzer, HIGH);

  // Connect to Wi-Fi network with SSID and password 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

  //PRZERWANIA OBSŁUGUJĄCE FUNKCJE WYKRYWANIA CZUJNIKÓW
  attachInterrupt(digitalPinToInterrupt(sensorBreakfast), Check, CHANGE);
  attachInterrupt(digitalPinToInterrupt(sensorLunch), Check, CHANGE);
  attachInterrupt(digitalPinToInterrupt(sensorDinner), Check, CHANGE);
}

void loop()//tutaj programujemy co się stanie jak nowy klient (nasza strona) połączy się z naszym serwerem sieci
{
  WiFiClient client = server.available();   // Listen for incoming clients

//Ta część odpowiada przetwarzanie komunikacji z klientem

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

 //koniec części która odpowiada przetwarzanie komunikacji z klientem

//ta część sprawdza który przycisk na stronie został wciśnięty i odpowiednio reaguje

            // Zapalanie Diód
            if (header.indexOf("GET /Dinner") >= 0) {
              Serial.println("Level Dinner open");
              //outputDinnerState = "on";
              dinnerCount++;
              go_DINNER();
              digitalWrite(outputDinner, HIGH);
              digitalWrite(outputLunch, LOW);
              digitalWrite(outputBreakfast, LOW);
              digitalWrite(outputClosed, LOW);
              Buzzer();
            } else if (header.indexOf("GET /Lunch") >= 0) {
              Serial.println("Level Lunch open");
              //outputLunchState = "on";
              lunchCount++;
              go_LUNCH();
              digitalWrite(outputDinner, LOW);
              digitalWrite(outputLunch, HIGH);
              digitalWrite(outputBreakfast, LOW);
              digitalWrite(outputClosed, LOW);
              Buzzer();
            } else if (header.indexOf("GET /Breakfast") >= 0) {
              Serial.println("Level Breakfast open");
              //outputBreakfastState = "on";
              breakfastCount++;
              go_BREAKFAST();
              digitalWrite(outputDinner, LOW);
              digitalWrite(outputLunch, LOW);
              digitalWrite(outputBreakfast, HIGH);
              digitalWrite(outputClosed, LOW);
              Buzzer();
            } else if (header.indexOf("GET /Closed") >= 0) {
              Serial.println("Smart feeder Closed");
              //outputClosedState = "on";
              go_CLOSED();
              digitalWrite(outputDinner, LOW);
              digitalWrite(outputLunch, LOW);
              digitalWrite(outputBreakfast, LOW);
              digitalWrite(outputClosed, HIGH);
            }

            totalCount = dinnerCount + lunchCount + breakfastCount;          

            //Czy chcemy autorefreshing
            if (header.indexOf("GET /autorefresh") >= 0) {
              autoRefresh = !autoRefresh;
            }

//koniec częsci która sprawdza który przycisk na stronie został wciśnięty i odpowiednio ustawia wyjścia na płytce   

//sprawdza stan czujników ma się wykonać tylko raz na początku
          for(onlyOnce = 0 ; onlyOnce < 1 ; onlyOnce++)
          {
              if ( digitalRead(sensorDinner)==HIGH && digitalRead(sensorLunch)==HIGH && digitalRead(sensorBreakfast)==HIGH )
              {
                setClosed();
              }
              if ( digitalRead(sensorDinner)==HIGH && digitalRead(sensorLunch)==HIGH && digitalRead(sensorBreakfast)==LOW )
              {
                setBreakfast();
              }
              if ( digitalRead(sensorDinner)==HIGH && digitalRead(sensorLunch)==LOW && digitalRead(sensorBreakfast)==LOW )
              {
                setLunch();
              }
              if ( digitalRead(sensorDinner)==LOW && digitalRead(sensorLunch)==LOW && digitalRead(sensorBreakfast)==LOW)
              {
                setDinner();
              //można tu potem zmieniać stan diód
              }
          }
          
//koniec częśći sprawdzającej stan czujników          

//Dodatkowe warunki:
           
          if (autoRefresh==1)
          {
            StanAutoRefresh = "On";
          }
          else
          {
            StanAutoRefresh = "Off";
          }

          if (digitalRead(sensorDog)==LOW)
          {
            StanDogAround = "Yes";
          }
          if (digitalRead(sensorDog)==HIGH)
          {
            StanDogAround = "No";
          }
          
//Koniec dodatkowych warunków
            
//część do kreacji i wyświetlania naszej strony internetowej
//nasza płytka wysle do przeglądarki kod strony w języku html
//za wysyłanie strony do przeglądarki odpowiada funkcja client.println()

            
            
            // Display the HTML web page//te 3 linijki muszą być
            client.println("<!DOCTYPE html>");
            client.println("<html>");
            client.println("<head>");
            client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<script>");
            client.println("");
    

            //kod w html i css modelujący naszą stronę

            //Auto Refreshing
            if(autoRefresh==1)
            {       
            client.println("function myFunction() { document.getElementById(\"ref\").click();}");
            client.println("setInterval(function(){myFunction()}, 4000)   ");  
            }
            
            
            
            //timer (Working:____)
            client.println("");
            client.println("var CzasOdniesienia = new Date().getTime();");
            client.println("    ");
            client.println("var x = setInterval(function() { ");
            client.println("");
            client.println("var Czas = new Date().getTime();");
            client.println("var Roznicaczasu = Czas-CzasOdniesienia;");
            client.println("    ");
            client.println("  var godziny = Math.floor((Roznicaczasu % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));");
            client.println("  var minuty = Math.floor((Roznicaczasu % (1000 * 60 * 60)) / (1000 * 60));");
            client.println("  var sekundy = Math.floor((Roznicaczasu % (1000 * 60)) / 1000);");
            client.println("    ");
            client.println("  document.getElementById(\"counter\").innerHTML = godziny + \"h \" + minuty + \"m \" + sekundy + \"s\"; ");
            client.println("    }, 1000); ");
            client.println("    ");
            
            client.println("</script>");


            //<!-- CSS part of code -->
            client.println("<style>");
            ///* ustawienia globalne */
            client.println("html { font-family: fantasy; display: inline-block; margin: 1px auto; text-align: center;}");
            client.println("#gradient1 {height: 1100px; background-color: white; background-image: linear-gradient(to right, rgba(194, 178, 128,1), rgba(194, 178, 128,1)); }");
            
            /* klasy z ustawieniami */
            client.println(" .ButtonStandard { background-color: rgba(245, 222, 179,1); color: black; padding: 18px 25px; text-align: center; font-size: 20px;  cursor: pointer;border-radius: 1px; border: 3px solid black; width: 140px; opacity: 1;}");
            client.println(".ButtonSpecial { background-color: rgba(245, 222, 179,1); color: black; padding: 22px 25px; text-align: center; font-size: 33px; margin:3px; cursor: pointer;border-radius: 1px; border: 3px solid black; width: 170px; opacity: 1;}");
            client.println(".ButtonAuto { background-color: rgba(245, 222, 179,1);  color: black; padding: 4px 25px; text-decoration: none ; text-align: center; font-size: 13px; margin:3px cursor: pointer;border-radius: 1px; border: 3px solid black; width: 150px; opacity: 1;}");

            client.println(".ButtonStandardThis:hover { background-color: rgba(160, 82, 45,1); color: white; width: 200px; opacity: 1;}");
            client.println(".ButtonSpecialThis:hover {background-color: rgba(218, 165, 32,1); color: white; width: 230px; opacity: 1;} ");
            client.println(".ButtonAutoThis:hover {  background-color: rgba(160, 82, 45,1); color: white; width: 210px; opacity: 1;} ");
            

                            

            client.println(".Frame {border: 10px double black; border-radius: 5px; background: lightblue; max-width:530px; margin: auto; margin-top:1px}");  

            client.println(".DoorPosition{max-width:300px; margin: auto; border: 5px double #000000; border-radius: 1px;}");  

            client.println(".Background{background: rgb(100,207,193);");
            client.println("background: linear-gradient(90deg, rgba(205, 127, 50,1) 5%, rgba(210, 125, 45,1) 50%, rgba(123, 63, 0,1) 95%);}");
                           

            client.println(".SpecialText{text-align: center; max-width:530px; margin: auto; margin-top:3px; margin-left:0}");

            /* spraw, aby pozycja drzwi i odświeżenie tekstu wyglądały jak zwykły tekst*/
            client.println("a { color: inherit; text-decoration: inherit;} ");      

            client.println(" legend {");
            client.println("background-color: rgba(210, 125, 45,1);");
            client.println("color: black;");
            client.println("padding: 5px 10px;");
            client.println("}");                
            
            client.println("fieldset {");
            client.println("background-color: rgba(245, 222, 179,1);");
            client.println(" color:  black;"); 
            client.println("}");                
                            

            client.println("</style>");  
            client.println("</head>");
                            

            //<!-- HTML part of code -->  
            client.println("<body class=\"Background\" > ");

            //<!-- first section -->                
            client.println("<section class=\"Frame\" id=\"gradient1\">");
            client.println("<h1> <font size=\"6\"> Welcome to Smart Feeder </font> </h1>");
            client.println("<p>Here you can change current door position and much more</p>");
            client.println("<p>Simply press one of the buttons and see what things can happen</p>");
            client.println("<p>Refresh door position by clicking on it</p>");                
                            

            client.println("<p> > > > <a href=\"/Dinner\"><button class=\"ButtonStandard ButtonStandardThis\">Dinner</button></a> < <  < </p>");
            client.println("<p> > > > <a href=\"/Lunch\"><button class=\"ButtonStandard ButtonStandardThis\">Lunch</button></a> < < < </p>");
            client.println("<p> > > > <a href=\"/Breakfast\"><button class=\"ButtonStandard ButtonStandardThis\">Breakfast</button></a> < < < </p>");
            client.println("<p> > > > <a href=\"/Closed\"><button class=\"ButtonStandard ButtonStandardThis\">Closed</button></a> < < < </p>");                      
            
            //door position
            client.println("<p><fieldset class=\"DoorPosition\">");
            client.println("<legend>Current door position</legend>");
            client.println("<a href=\"/ref\"><font id=\"ref\" size=\"5\" color=black>"+(String)position+"</font><br /></a>"); 
            client.println("</fieldset></p>");   

            //EXTRA BUTTON REFERS TO LINK
            client.println(" > > > <a href=\"/spec\"><button class=\"ButtonSpecial ButtonSpecialThis\" onclick=\"window.open('https://www.littlecooperbear.com/hound/2017/5/15/dog-nutrition-facts');\" >EXTRA</button></a>  < < < ");
            client.println("</fieldset></p>");                


            //STATYSTYKI
            client.println("<p class=\"SpecialText\">STATISCTICS:&nbsp;&nbsp; </p>");
            client.println("<p class=\"SpecialText\">Working:&nbsp;&nbsp;<p1 id=\"counter\">0m 0s</p1></p>");  
            client.println("<p class=\"specialtext\">Auto Refreshing:&nbsp;&nbsp;"+(String)StanAutoRefresh+"</p>");
            client.println("<p class=\"SpecialText\">Is dog around?:&nbsp;&nbsp;"+(String)StanDogAround+"</p>");
            client.println("<p class=\"SpecialText\">Number of door moves:&nbsp;&nbsp;"+(String)totalCount+"</p>");
            client.println("<p class=\"SpecialText\">Number of openings (Dinner):&nbsp;&nbsp;"+(String)dinnerCount+"</p>");
            client.println("<p class=\"SpecialText\">Number of openings (Lunch):&nbsp;&nbsp;"+(String)lunchCount+"</p>");
            client.println("<p class=\"SpecialText\">Number of openings (Breakfast):&nbsp;&nbsp;"+(String)breakfastCount+"</p>");
            client.println("</fieldset></p>");           

            //Auto Refresh button
            client.println("> > > <a href=\"/autorefresh\"><button class=\"ButtonAuto ButtonAutoThis\"> Auto Refresh </button></a> < < <");
            client.println("</fieldset></p>");
            //Single Refresh button
            client.println("> > > <a href=\"/refresh\"><button class=\"ButtonAuto ButtonAutoThis\"> Single Refresh </button></a> < < <");

            client.println("</section>");                
            
            client.println("</body></html>");

                 

            client.println("");


            //koniec kodu modyfikującego wygląd naszej strony
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }

    //zamykanie komunikacji
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}


////////////////////////////////////////////////////////////FUNKCJE//////////////////////////////////////////////////////////

//Funckje obsługujące wykrywanie czujników:

void setDinner(){
  position = "Dinner";
}

void setLunch(){
  position = "Lunch";
}

void setBreakfast(){
  position = "Breakfast";
}

void setClosed(){
  position = "Closed";
}

//funckja sprawdzająca stan czujników
void Check(){
  if ( digitalRead(sensorDinner)==HIGH && digitalRead(sensorLunch)==HIGH && digitalRead(sensorBreakfast)==HIGH )
      {
       setClosed();
      }
  if ( digitalRead(sensorDinner)==HIGH && digitalRead(sensorLunch)==HIGH && digitalRead(sensorBreakfast)==LOW )
      {
      setBreakfast();
      }
  if ( digitalRead(sensorDinner)==HIGH && digitalRead(sensorLunch)==LOW && digitalRead(sensorBreakfast)==LOW )
      {
      setLunch();
      }
  if ( digitalRead(sensorDinner)==LOW && digitalRead(sensorLunch)==LOW && digitalRead(sensorBreakfast)==LOW)
      {
      setDinner();
      }
}


//funkcja buzzera
void Buzzer(){
  int i=0;
  for (i=0;i<1;i++)
  {
    digitalWrite(pinBuzzer, LOW); //właczenie
    delay(100);
    digitalWrite(pinBuzzer, HIGH); //wylaczenie
    delay(350);
    digitalWrite(pinBuzzer, LOW);
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(400);

    digitalWrite(pinBuzzer, LOW); 
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW); 
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW); 
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(400);

    digitalWrite(pinBuzzer, LOW); 
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW); 
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW); 
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW); 
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(400);

    digitalWrite(pinBuzzer, LOW); 
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW); 
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(1000);
  }
}

//Funkcje obsługi silnika


//SINGLE STEPS
//step1
void step_1(){
  digitalWrite(stepperPIN_1,HIGH);
  digitalWrite(stepperPIN_2,LOW);
  digitalWrite(stepperPIN_3,LOW);
  digitalWrite(stepperPIN_4,LOW);
  delay(2);
}
//step2
void step_2(){
  digitalWrite(stepperPIN_1,LOW);
  digitalWrite(stepperPIN_2,HIGH);
  digitalWrite(stepperPIN_3,LOW);
  digitalWrite(stepperPIN_4,LOW);
  delay(2);
}
//step3
void step_3(){
  digitalWrite(stepperPIN_1,LOW);
  digitalWrite(stepperPIN_2,LOW);
  digitalWrite(stepperPIN_3,HIGH);
  digitalWrite(stepperPIN_4,LOW);
  delay(2);
}
//step4
void step_4(){
  digitalWrite(stepperPIN_1,LOW);
  digitalWrite(stepperPIN_2,LOW);
  digitalWrite(stepperPIN_3,LOW);
  digitalWrite(stepperPIN_4,HIGH);
  delay(2);
}

//ruch zgodnie ze wskazówkami zegara w dół
//ruch przeciwnie do wskazówek zegara w górę
//MOVING UP
void steps_DOWN(){
  step_4();
  step_3();
  step_2();
  step_1();
}
//MOVING DOWN
void steps_UP(){
  step_1();  
  step_2();
  step_3();
  step_4();
}


//Funkcje ruchu drzwi ze strony

void go_CLOSED(){
  if(position=="Closed"){Serial.println("Door Already Closed");}
  else {
      while(1){
            steps_DOWN(); 
            if(position=="Closed"){
              int liczclos=0; //przesunięcie drzwi po wykryciu czujnika aby drzwi dojechały do podłogi piętra
              for(liczclos=0; liczclos<=1200; liczclos++)
              {
                steps_DOWN();
              }
              break;}}     
  }                        
}

void go_BREAKFAST(){
  if(position=="Breakfast"){Serial.println("Door Already open on Breakfast");}
  else {
      if(position=="Closed"){
        while(1){
                  steps_UP(); 
                  if(position=="Breakfast"){
                    int liczbreak=0;
                    for(liczbreak=0; liczbreak<=200; liczbreak++)
                    {
                      steps_UP();
                    }
                    break;}}
            }
      if(position=="Lunch"){
        while(1){
                  steps_DOWN(); 
                  if(position=="Breakfast"){
                    int liczbreak=0;
                    for(liczbreak=0; liczbreak<=1200; liczbreak++)
                    {
                      steps_DOWN();
                    }
                    break;}}
            }           
      if(position=="Dinner"){
        while(1){
                  steps_DOWN(); 
                  if(position=="Breakfast"){
                    int liczbreak=0;
                    for(liczbreak=0; liczbreak<=1200; liczbreak++)
                    {
                      steps_DOWN();
                    }
                    break;}}
            }    
  } 
}

void go_LUNCH(){
  if(position=="Lunch"){Serial.println("Door Already open on Lunch");}
  else {
      if(position=="Closed"){
        while(1){
                  steps_UP(); 
                  if(position=="Lunch"){
                    int liczlunch=0;
                    for(liczlunch=0; liczlunch<=200; liczlunch++)
                    {
                      steps_UP();
                    }
                    break;}}
            }
      if(position=="Breakfast"){
        while(1){
                  steps_UP(); 
                  if(position=="Lunch"){
                    int liczlunch=0;
                    for(liczlunch=0; liczlunch<=200; liczlunch++)
                    {
                      steps_UP();
                    }
                    break;}}
            }           
      if(position=="Dinner"){
        while(1){
                  steps_DOWN(); 
                  if(position=="Lunch"){
                    int liczlunch=0;
                    for(liczlunch=0; liczlunch<=1200; liczlunch++)
                    {
                      steps_DOWN();
                    }
                    break;}}
            }    
  } 
}

void go_DINNER(){
  if(position=="Dinner"){Serial.println("Door Already open on Dinner");}
  else {
      if(position=="Closed"){
        while(1){
                  steps_UP(); 
                  if(position=="Dinner"){
                    int liczdinn=0;
                    for(liczdinn=0; liczdinn<=200; liczdinn++)
                    {
                      steps_UP();
                    }
                    break;}}
            }
      if(position=="Breakfast"){
        while(1){
                  steps_UP(); 
                  if(position=="Dinner"){
                    int liczdinn=0;
                    for(liczdinn=0; liczdinn<=200; liczdinn++)
                    {
                      steps_UP();
                    }
                    break;}}
            }           
      if(position=="Lunch"){
        while(1){
                  steps_UP(); 
                  if(position=="Dinner"){
                    int liczdinn=0;
                    for(liczdinn=0; liczdinn<=200; liczdinn++)
                    {
                      steps_UP();
                    }
                    break;}}
            }    
  } 
}

