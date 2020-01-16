#define BLYNK_PRINT Serial
#include "Wire.h"   // oled k liy header
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "SSD1306.h" // oled

SSD1306  display (0x3c, D1, D2);
SSD1306  display2(0x3c, D3, D4);
SSD1306  display3(0x3c, D5, D6);
SSD1306  display4(0x3c, D9, D10);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2d543722e2504842ac1cc544850a75da";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "grace";
char pass[] = "gracious";

//int f=665;
int pinData1=0;
String slotF1="Full";
String slotE1="N/L";
int pinData2=0;
int pinData3=0;
int pinData4=0;


WidgetLCD lcd1(V1);

// This code will update the virtual port 1
BLYNK_WRITE(V1) {
  pinData1 = param.asInt();
}

BLYNK_WRITE(V2) {
  pinData2 = param.asInt();
}

BLYNK_WRITE(V3) {
  pinData3 = param.asInt();
}
BLYNK_WRITE(V4) {
  pinData4 = param.asInt();
}

void setup(){
  Serial.begin(9600);
  lcd1.clear(); //Use it to clear the LCD Widget
 // lcd1.print(0, 0, "Distance in cm lcd");
 
  Blynk.begin(auth, ssid, pass); // method to access blink
  
  Serial.println();
  Serial.println();


  // Initialising the UI will init the display too.
  display.init();
  display2.init();
  display3.init();
  display4.init();
}


void loop()
{
  Blynk.run();
  
  lcd1.clear();
  lcd1.print(0, 0, "Distance in cm lcd"); 
  lcd1.print(7, 1, pinData1);    

/*
   display2.clear();
  display2.drawString(63, 20, "Slot 2: "+ String("N/L"));
  display2.display();

  display3.clear();
  display3.drawString(0, 35, "Slot 3: " + String("N/L"));
  display3.display();
 
   display4.clear();
  display4.drawString(0, 30, "Slot 4: " + String(pinData4));
  display4.display();
*/
    
  if ( pinData1 <= 25 )
  {
    display.clear();
    display.drawString(0, 10, "Slot 1: " + String(slotF1));
    display.display();
  }
  else 
  {
    display.clear();
    display.drawString(0, 10, "Slot 1: " + String(slotE1));
    display.display();
  }
  
  if( pinData2<=25 ) 
  {
    display2.clear();
    display2.drawString(63, 10, "Slot 2: "+ String(slotF1));
    display2.display();
  }
  else 
  {
    display2.clear();
    display2.drawString(63, 10, "Slot 2: "+ String(slotE1));
    display2.display();  
  }
  if( pinData3<=25 ) 
  {
    display3.clear();
    display3.drawString(0, 30, "Slot 3: " + String(slotF1));
    display3.display();
  }
  else 
  {
    display3.clear();
    display3.drawString(0, 30, "Slot 3: "+ String(slotE1));
    display3.display(); 
  }
  if((pinData4<=25)) 
  {
    display4.clear();
    display4.drawString(63, 30, "Slot 4: " + String(slotF1));
    display4.display();
  }
  else 
  {
    display4.clear();
    display4.drawString(63, 30, "Slot 4: "  + String(slotE1));
    display4.display();
  }
  delay(1000);
}
