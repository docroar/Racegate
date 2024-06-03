//Original Creator ProfessorBoots

#include <Arduino.h>
#include <NewPing.h>
//NewPing by Tim Eckel

 
//Variables
double raceStart = 0;
String raceEnd = "";
String currentTime = "";
bool racing = false;
int pingParameter = 29;

//Record time variables
int milliSec1 = 0;
int milliSec2 = 0;
int sec = 0;
int tenSec = 0;
 
//ULTRASONIC CODE1
#define triggerPin 5
#define echoPin 18
#define maxDistance 35 //maximale Distanz --> angepasst an Tor
NewPing sonar(triggerPin, echoPin, maxDistance);
 
void setup() {
  Serial.begin(9600);
 
}
 
void loop() {
    if(pingCheck())
  {
    if(!racing)
    {
    //Serial.println("Neue Runde");
    raceEnd =  String((millis()-raceStart)/1000);
    Serial.println(raceEnd);
    //Serial.println(" sec");


    raceStart = millis();
    racing = true;
     delay(500);
    }
    else if(racing)
    {
      racing = false;
    
    }
  }
  if(racing)
  {
    currentTime = String((millis()-raceStart)/1000);
       
  }
 


}
bool pingCheck(){
  unsigned long pingTime     = sonar.ping();
  unsigned long distanceInCm = sonar.convert_cm(pingTime);

  if((distanceInCm <= pingParameter && pingTime > 0))
  {
    return true;
  }
  else
  {
    return false;
  }
}


  
void displayTime(String currentTime){
  milliSec1 = (String(currentTime.charAt(currentTime.length()-2))).toInt();
  milliSec2 = (String(currentTime.charAt(currentTime.length()-1))).toInt();
  sec = (String(currentTime.charAt(currentTime.length()-4))).toInt();
  tenSec = (String(currentTime.charAt(currentTime.length()-5))).toInt(); 
  Serial.println(currentTime);
  
}
