#include <LiquidCrystal.h>
#include <EasyTransfer.h>
//create object
EasyTransfer ET;
struct RECEIVE_DATA_STRUCTURE{
//put your variable definitions here for the data you want to receive
//THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
float SeriallMain;
float SeriallCarburtor;
float SeriallNos;

 
int   SeriallRPM1;
int   SeriallRPM2 ;
   
float   SeriallMAP;
float   SeriallBAT;
float   SeriallLambda;

int   SeriallEGT1;
int   SeriallEGT2;
   
int   SeriallEGT3;
int   SeriallEGT4;
   
int   SeriallEGT5;
int   SeriallEGT6; 
   
int   SeriallEGT7;
int   SeriallEGT8;

};
//give a name to the group of data
RECEIVE_DATA_STRUCTURE mydata;
int Menue = 1;
float FuelMainPSI;
float FuelCarburtorPSI;
float FuelNOSPSI;
float MAPPSI;
float BordspannungVolt;
float LambdaRaw;
int RPM1;
int RPM2;
int EGT1;
int EGT2;
int EGT3;
int EGT4;
int EGT5;
int EGT6;
int EGT7;
int EGT8;


unsigned long time;




LiquidCrystal lcd(8, 9, 4, 5, 6, 7);




void setup() {
   Serial.begin(57600);
//start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc.
ET.begin(details(mydata), &Serial);
    pinMode(2, INPUT); // up
    pinMode(3, INPUT); // down
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);  
 
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("    Digital     ");
    lcd.setCursor(0, 1);
    lcd.print(" Pressure Gauge ");
delay(3000);


}

void loop() {

if(ET.receiveData()){
//this is how you access the variables. [name of the group].[variable name]
//since we have data, we will blink it out.
FuelMainPSI = mydata.SeriallMain ;
FuelCarburtorPSI = mydata.SeriallCarburtor ;
FuelNOSPSI = mydata.SeriallNos ;
RPM1 = mydata.SeriallRPM1; 
RPM2 = mydata.SeriallRPM2;
MAPPSI =  mydata.SeriallMAP;
BordspannungVolt =  mydata.SeriallBAT;
LambdaRaw = mydata.SeriallLambda;
EGT1 =  mydata.SeriallEGT1;
EGT2 =  mydata.SeriallEGT2;
EGT3 =  mydata.SeriallEGT3;
EGT4 =  mydata.SeriallEGT4;
EGT5 =  mydata.SeriallEGT5;
EGT6 =  mydata.SeriallEGT6;
EGT7 =  mydata.SeriallEGT7;
EGT8 =  mydata.SeriallEGT8;

 time = millis();
}


if (millis()-time >= 1000 )
{
 FuelMainPSI = 99; 
 FuelCarburtorPSI = 99; 
 FuelNOSPSI = 99; 
 RPM1 =0; 
RPM2 = 0;
MAPPSI =  99;
BordspannungVolt =  99;
LambdaRaw = 99;
EGT1 =  9999;
EGT2 =  9999;
EGT3 =  9999;
EGT4 =  9999;
EGT5 =  9999;
EGT6 =  9999;
EGT7 =  9999;
EGT8 =  9999;
}

char buffer[40];

String FuelMain_PSI = dtostrf(FuelMainPSI, 4, 1, buffer);

String FuelCarburtor_PSI = dtostrf(FuelCarburtorPSI, 4, 1, buffer);

String FuelNOS_PSI = dtostrf(FuelNOSPSI, 4, 1, buffer);

String MAP_PSI = dtostrf(MAPPSI, 6, 2, buffer);

String Bordspannung_Volt = dtostrf(BordspannungVolt, 5, 2, buffer);

String Lambda = dtostrf(LambdaRaw, 5, 2, buffer);


if ( digitalRead (3) == LOW ) { 
  if (Menue != 7) {
  delay (250);
   Menue ++;
 }}
if ( digitalRead (2) == LOW ) { 
  if (Menue != 1) {
  delay (250);
  Menue --;
}}


if (Menue == 1) {
lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Main  Carb. NOS ");
   
    lcd.setCursor(0, 1);
    lcd.print(FuelMain_PSI);
    lcd.setCursor(6, 1);
    lcd.print(FuelCarburtor_PSI);
    lcd.setCursor(12, 1);
    lcd.print(FuelNOS_PSI);
}    

if (Menue == 2) {
lcd.clear();

    lcd.setCursor(0, 0);
    //lcd.print("1234567890123456");
      lcd.print("RPM1  ARF  MAP  ");
    lcd.setCursor(0, 1);
    lcd.print(RPM1);
    lcd.setCursor(5, 1);
    lcd.print(Lambda);
    lcd.setCursor(10, 1);
    lcd.print(MAP_PSI);
    
}    

if (Menue == 3) {
lcd.clear();

    lcd.setCursor(0, 0);
    //lcd.print("1234567890123456");
      lcd.print("RPM2  Spannung  ");
    lcd.setCursor(0, 1);
    lcd.print(RPM2);
    lcd.setCursor(6, 1);
    lcd.print(Bordspannung_Volt);
    
    
}   
  
if (Menue == 4) {
lcd.clear();

    lcd.setCursor(0, 0);
    //lcd.print("1234567890123456");
      lcd.print("  EGT1    EGT2  ");
    lcd.setCursor(2, 1);
    lcd.print(EGT1);
    lcd.setCursor(10, 1);
    lcd.print(EGT2);
    }
    
if (Menue == 5) {
lcd.clear();

    lcd.setCursor(0, 0);
    //lcd.print("1234567890123456");
      lcd.print("  EGT3    EGT4  ");
    lcd.setCursor(2, 1);
    lcd.print(EGT3);
    lcd.setCursor(10, 1);
    lcd.print(EGT4);    
    
}    

if (Menue == 6) {
lcd.clear();

    lcd.setCursor(0, 0);
    //lcd.print("1234567890123456");
      lcd.print("  EGT5    EGT6  ");
    lcd.setCursor(2, 1);
    lcd.print(EGT5);
    lcd.setCursor(10, 1);
    lcd.print(EGT6);
 }  
if (Menue == 7) {
lcd.clear();

    lcd.setCursor(0, 0);
    //lcd.print("1234567890123456");
      lcd.print("  EGT7    EGT8  ");
    lcd.setCursor(2, 1);
    lcd.print(EGT7);
    lcd.setCursor(10, 1);
    lcd.print(EGT8);
 }  
delay(50);
}
