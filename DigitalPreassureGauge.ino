#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int long FuelMainCal = 0; 
int long FuelCarburtorCal = 0; 
int long FuelNOSCal = 0; 

float FuelMainPSI = 0; 
float FuelCarburtorPSI = 0; 
float FuelNOSPSI = 0; 

int FuelMain = 0; 
int FuelCarburtor = 0; 
int FuelNOS = 0; 


void setup() {
   Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("    Digital     ");
    lcd.setCursor(0, 1);
    lcd.print(" Pressure Gauge ");
delay(2000);

   
    lcd.setCursor(0, 0);
    lcd.print("Calibrate Sensor");
    lcd.setCursor(0, 1);
    lcd.print("Fuelpump off    ");
    
for(int x =0 ; x < 100 ; x++){
 
 FuelMainCal = FuelMainCal + analogRead(1); 
 FuelCarburtorCal = FuelCarburtorCal + analogRead(2); 
 FuelNOSCal = FuelNOSCal + analogRead(3); 
}

 FuelMainCal = 27100;
 FuelCarburtorCal = 27100;
 FuelNOSCal = 27100;

 
  
 FuelMainCal = FuelMainCal /100; 
 FuelCarburtorCal = FuelCarburtorCal /100; 
 FuelNOSCal = FuelNOSCal /100; 
 Serial.print("MainFuelCal 2: ");
  Serial.println(FuelMainCal);
  
    lcd.setCursor(0, 0);
    lcd.print("   Switch on    ");
    lcd.setCursor(0, 1);
    lcd.print("    Fuelpump    ");
    
 do
{
  delay(50);          // wait for sensors to stabilize
 FuelMain = analogRead(1);  // check the sensors

} while (FuelMainCal+10 < FuelMain);   



}

void loop() {
  // put your main code here, to run repeatedly:
FuelMain = analogRead(1);
FuelCarburtor = analogRead(2);
FuelNOS = analogRead(3);

FuelMainPSI = (FuelMain - FuelMainCal)/7.14;
FuelCarburtorPSI = (FuelCarburtor - FuelCarburtorCal)/7.14;
FuelNOSPSI = (FuelNOS - FuelNOSCal)/7.14;

char buffer[20];
String FuelMain_PSI = dtostrf(FuelMainPSI, 4, 1, buffer);

String FuelCarburtor_PSI = dtostrf(FuelCarburtorPSI, 4, 1, buffer);

String FuelNOS_PSI = dtostrf(FuelNOSPSI, 4, 1, buffer);
 Serial.print("MainFuelRAW: ");
  Serial.print(FuelMain);
 Serial.print(" MainFuel: ");
  Serial.println(FuelMain_PSI);

lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Main  Carb. NOS ");
   
    lcd.setCursor(0, 1);
    lcd.print(FuelMain_PSI);
    lcd.setCursor(6, 1);
    lcd.print(FuelCarburtor_PSI);
    lcd.setCursor(12, 1);
    lcd.print(FuelNOS_PSI);
    
delay(50);
}
