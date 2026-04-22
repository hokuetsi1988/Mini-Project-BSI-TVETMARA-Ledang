/*
 DEVNOTES
 - The code works as intended
 - Proceed to design process
 ***Things to note
    - Smoke sensor is sensitive, might need calibration
    - Personal opinion but the OLED screen looked boring lol
*/
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6EQUxZ6cx"
#define BLYNK_TEMPLATE_NAME "Mini Project BSI"
#define BLYNK_AUTH_TOKEN "-rJhVY3dqT2m0Gtar3Dx7AnjLYcr85H5"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;

char ssid[] = "SabaSameko";
char pass[] = "SukaBumi";
// this one above responsible for blynk configuration and library prerequisites

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// this one is responsible for OLED screen prerequisites library

int b = 33; //buzzer pin
int d = 400; //delay time for buzzer
#define fs A3 //Flame sensor pin
#define ss A0 //Smoke sensor pin
void TimerEvent()
{
  int smoke = analogRead(ss);// read smoke sensor
  int fire = analogRead(fs);// read flame sensor
  Blynk.virtualWrite(V0, smoke);
  Blynk.virtualWrite(V3, fire);
  Serial.print("FS read : ");
  Serial.println(fire);
  Serial.print("SS read : ");
  Serial.println(smoke);

  //Scenario A Smoke 1 : Fire 0
  if(smoke >= 2200 && fire >= 400) 
  {
  Blynk.virtualWrite(V1, 1);
  Blynk.virtualWrite(V2, 0);
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
  tone(b, 753);
  delay(d);
  tone(b,860);
  delay(d);
  }

  //Scenario B Smoke 0 : Fire 1
  if(smoke <= 2200 && fire <= 400)
  {
  Blynk.virtualWrite(V1, 0);
  Blynk.virtualWrite(V2, 1);
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
  tone(b, 1550);
  delay(1000);
  noTone(b);
  delay(1000);
  }


  //Scenario C Smoke 1 : Fire 1
  if(smoke >= 2200 && fire <= 400)
  {
  Blynk.virtualWrite(V1, 1);
  Blynk.virtualWrite(V2, 1);
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
  tone(b, 753);
  delay(d);
  tone(b,860);
  delay(d);
  tone(b, 1550);
  delay(1000);
  noTone(b);
  delay(1000);
  }


  //Scenario D Smoke 0 : Fire 0
  if(smoke <= 2200 && fire >= 400)
  {
  Blynk.virtualWrite(V1, 0);
  Blynk.virtualWrite(V2, 0);
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
}
void setup() 
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  timer.setInterval(1000L, TimerEvent);
}
void loop() 
{
  Blynk.run();
  timer.run();
}