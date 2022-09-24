#include <Wire.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <MFRC522.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>
SoftwareSerial sim(4, 5);// Rx,TX;                  // mySerial.println("AT+CMGF=1");
int ss = 10;
in
void setup(){
Serial.begin(9600);
sim.begin(9600); 
sim.println("AT+CNMI=2,2,0,0,0");
delay(1000);
sim.println("AT+CMGF=1");
delay(500);
SPI.begin();
rf.PCD_Init();
Serial.println("HI SIR \n ACTIVATED");
display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
s1.attach(3);
s1.write(pos);
delay(1000);
s1.write(120);
delay(1000);
s1.write(pos);
pinMode(buzz , OUTPUT);
 TexT ="\n WARMACHINE\n ADVANCED SECURIT \n   SYSTEM";
 screen();
delay(1000);
sim.print("AT+CMGF=1\r");
delay(1000);
  }
void loop() 
{
  TexT ="NO CARD";
screen();
  if(!rf.PICC_IsNewCardPresent())
  {
    return;
  }
if(!rf.PICC_ReadCardSerial())
{
  return;
}
String tag="";
for( int i=0; i<rf.uid.size; i++)
{
  tag.concat(String(rf.uid.uidByte[i],HEX));//card F4D3362A ..tag 97627A7A


}
tag.toUpperCase();
//Serial.println(tag);

if ( tag == "F4D3362A")
{ 
  TexT = "welcome sir" ;
  screen();
  Serial.println("welcome sir");
  digitalWrite(buzz, 1);
  delay(100);
  digitalWrite(buzz , 0);
  s1.write(120);
  delay(3000);
  s1.write(pos);
  delay(50);
}
else {
  Serial.println("not allowed");
  p=p+1;
  Serial.print("attempet left = ");
  Serial.print(6-p);
  Serial.print("/5");
  delay(100);
  display.clearDisplay();
  display.setCursor(0,0);
   display.setTextSize(1);
   display.setTextColor(WHITE);//"   ! ALERT! \n Hi sir ome wants to enter in room \n "
    display.println("NOT ALLOWED  \n ATEMPT LEFT\n");
       display.println(6-p);
     display. display();
     delay(900);
}
if(p == 1)
{
  p=0;
  Serial.println("SYSTEM BLOCKED ");
  TexT = "   varifing to\n  Mr. Suryansh";
  screen();
  SendMessage();
   while (true)
  {
    s1.write(pos);
    if (true)
    {
      if(!rf.PICC_IsNewCardPresent())
      {
      }
if(!rf.PICC_ReadCardSerial())
{
}}
String tag="";
for( int i=0; i<rf.uid.size; i++)
{
  tag.concat(String(rf.uid.uidByte[i],HEX));//card F4D3362A ..tag 97627A7A
}
tag.toUpperCase();
 if (sim.available()>=0)
  {
  String sms = sim.readString();
  Serial.println(sms);
  delay(1000);
      s1.write(pos);
      delay(20);
      sms = sim.readString();
      sms.toUpperCase();
    
     if(sms.indexOf("OPEN")>=0  || tag=="F4D3362A")
     {
         TexT ="you are welcome" ;
      screen();
      s1.write(pos);
      s1.write(120);
      delay(3000);
      s1.write(pos);
      Serial.println(sms);
      tag="";
      sms ="";
      delay(1500);
      break;    
     }
   if (sms.indexOf("RESET")>=0)
     {
      TexT = "system is reset by the sir\n you can try again";
      screen();
      delay(1500);
      sms="";
     break;
      }}
  }
}
}


void screen()
{ 
  //String TexT = "ccc";
  display.clearDisplay();
  display.setCursor(0,0);
   display.setTextSize(1);
   display.setTextColor(WHITE);//"   ! ALERT! \n Hi sir ome wants to enter in room \n "
    display.println(TexT);
     display. display();   
}
void SendMessage()
{
  sim.println("AT+CNMI=2,2,0,0,0");
delay(500);
  sim.println("AT+CMGF=1");
  delay(500);
  sim.println("AT+CMGS=\"+919116207724\"\r");
  delay(500);
  delay(500);
  sim.print("   ! ALERT! \n Hi sir ome wants to enter in room \n  ");
  delay(500);
  sim.write(26);
}
