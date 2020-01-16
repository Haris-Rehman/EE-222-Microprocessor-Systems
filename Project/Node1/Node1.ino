#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define trigPin1  D2
#define echoPin1  D1

#define trigPin2  D4
#define echoPin2  D3

#define trigPin3  D6
#define echoPin3  D5

#define trigPin4  D9
#define echoPin4  D10


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e9d24fc0dbb245b1a0ff080e8fb22842";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "grace";
char pass[] = "gracious";


WidgetLCD lcd1(V1);
WidgetBridge bridge1(V1);

WidgetLCD lcd2(V2);
WidgetBridge bridge2(V2);

WidgetLCD lcd3(V3);
WidgetBridge bridge3(V3);

WidgetLCD lcd4(V4);
WidgetBridge bridge4(V4);


BLYNK_CONNECTED() {
  // Place the AuthToken of the second hardware here
  bridge1.setAuthToken("2d543722e2504842ac1cc544850a75da"); 
  bridge2.setAuthToken("2d543722e2504842ac1cc544850a75da"); 
  bridge3.setAuthToken("2d543722e2504842ac1cc544850a75da"); 
  bridge4.setAuthToken("2d543722e2504842ac1cc544850a75da"); 
}
void setup(){
  Serial.begin(9600);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  
  Blynk.begin(auth, ssid, pass);
 
  lcd1.clear(); //Use it to clear the LCD Widget
  lcd1.print(0, 0,  "Slot 1:"); 
  
  lcd2.clear(); //Use it to clear the LCD Widget
  lcd2.print(0, 0, "Slot 2:");
  
  lcd3.clear(); //Use it to clear the LCD Widget
  lcd3.print(0, 0, "Slot 3:");
  
  lcd4.clear(); //Use it to clear the LCD Widget
  lcd4.print(0, 0, "Slot 4:");
}

void loop(){
  Blynk.run();
  
  lcd1.clear();
  lcd1.print(0, 0, "Slot 1:"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print") 

  lcd2.clear();
  lcd2.print(0, 0, "Slot 2:"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print") 

  lcd3.clear();
  lcd3.print(0, 0, "Slot 3:"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print") 

  lcd4.clear();
  lcd4.print(0, 0, "Slot 4:"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print") */



  long duration_a, distance_a;
  long duration_b, distance_b;
  long duration_c, distance_c;
  long duration_d, distance_d;

  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin1, LOW);
  duration_a=pulseIn(echoPin1, HIGH);
  distance_a =(duration_a/2)/29.1;
  Serial.print(distance_a);
  Serial.println("CM");
  delay(10);

  if((distance_a<=25)) 
  {
    bridge1.virtualWrite(V1, distance_a);
    lcd1.print(7, 1, "Full");
    delay(500);
  }
  else 
  {
    bridge1.virtualWrite(V1, distance_a);
    lcd1.print(7, 1, "Empty");
    delay(500);
  }

  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin2, LOW);
  duration_b=pulseIn(echoPin2, HIGH);
  distance_b =(duration_b /2)/29.1;
  Serial.print(distance_b);
  Serial.println("CM");
  delay(10);

  if((distance_b<=25)) 
  {
    bridge2.virtualWrite(V2, distance_b);
    lcd2.print(7, 1, "Full");
    delay(500);
  }
  else 
  {
    bridge2.virtualWrite(V2, distance_b); ///////////
    lcd2.print(7, 1, "Empty");
    delay(500);
  }
  
  digitalWrite(trigPin3,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin3, LOW);
  duration_c=pulseIn(echoPin3, HIGH);
  distance_c =(duration_c /2)/29.1;
  Serial.print(distance_c);
  Serial.println("CM");
  delay(10);

  if((distance_c<=25)) 
  {
    bridge3.virtualWrite(V3, distance_c);
    lcd3.print(7, 1, "Full");
    delay(500);
  }
  else
  {
    bridge3.virtualWrite(V3, distance_c);
    lcd3.print(7, 1, "Empty");
    delay(500);
  }
 
  digitalWrite(trigPin4,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin4, LOW);
  duration_d=pulseIn(echoPin4, HIGH);
  distance_d =(duration_d /2)/29.1;
  Serial.print(distance_d);
  Serial.println("CM");
  delay(10);

  if((distance_d<=25)) 
  {
    bridge4.virtualWrite(V4, distance_d);
    lcd4.print(7, 1, "Full");
    delay(500);
  }
  else 
  {
    bridge4.virtualWrite(V4, distance_d);
    lcd4.print(7, 1, "Empty");
    delay(500);  
  }
}
