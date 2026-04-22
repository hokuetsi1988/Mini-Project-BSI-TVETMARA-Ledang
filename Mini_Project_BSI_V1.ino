/*
DEVNOTES
- this code has been tested and working as intended
- implement the system along with blynk, do it on new sketch
- dont forget to design the casing for this thing too
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//The code above for the OLED screen
int b = 33; //buzzer pin
int d = 400; //delay time for buzzer, We use a passive buzzer to differentiate smoke and fire warning
#define fs A3 //Flame sensor pin
#define ss A0 //Smoke sensor pin

void setup() 
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //display initialization
  display.clearDisplay(); //clear the screen
}

void loop() 
{
  int smoke = analogRead(ss);// read smoke sensor
  int fire = analogRead(fs);// read flame sensor
  Serial.print("FS read : ");
  Serial.println(fire);
  Serial.print("SS read : ");
  Serial.println(smoke);
  /*
  Considering we have two sensor, the nature of the code forbid to read and write simultaneously. However, we can bypass it by following these sequence below :
  1. The code reads both sensor first, then display it to the serial monitor
  2. Use the if else function to determine the situation whether fire or smoke detected. There are few scenarios
      a. smoke is present, but no fire
      b. fire is present, but no smoke
      c. there are both fire and smoke
      d. No fire nor smoke 
  3. display it to OLED screen and blynk
  */

  //Scenario A Smoke 1 : Fire 0
  if(smoke >= 2200 && fire >= 100) 
  {
  tone(b, 753);
  delay(d);
  tone(b,860);
  delay(d);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(3, 35);
  display.println("SS Active!");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(3, 15);
  display.println("FS Idle..");
  display.display();
  }

  //Scenario B Smoke 0 : Fire 1
  if(smoke <= 2200 && fire <= 100)
  {
  tone(b, 1550);
  delay(1000);
  noTone(b);
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(3, 15);
  display.println("FS Active!");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(3, 35);
  display.println("SS Idle..");
  display.display();
  }


  //Scenario C Smoke 1 : Fire 1
  if(smoke >= 2200 && fire <= 100)
  {
  tone(b, 753);
  delay(d);
  tone(b,860);
  delay(d);
  tone(b, 1550);
  delay(1000);
  noTone(b);
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(3, 15);
  display.println("FS Active!");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(3, 35);
  display.println("SS Active!");
  display.display();
  }


  //Scenario D Smoke 0 : Fire 0
  if(smoke <= 2200 && fire >= 100)
  {
  noTone(b);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(3, 15);
  display.println("FS Idle..");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(3, 35);
  display.println("SS Idle..");
  display.display();
  }
  delay(1000);
}
