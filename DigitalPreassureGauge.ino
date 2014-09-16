#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int FuelMainCal = 0; 
int FuelCarburtorCal = 0; 
int FuelNOSCal = 0; 

int FuelMainPSI = 0; 
int FuelCarburtorPSI = 0; 
int FuelNOSPSI = 0; 

int FuelMain = 0; 
int FuelCarburtor = 0; 
int FuelNOS = 0; 


void setup() {
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
 FuelMainCal = FuelMainCal /100; 
 FuelCarburtorCal = FuelCarburtorCal /100; 
 FuelNOSCal = FuelNOSCal /100; 

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

    lcd.setCursor(0, 0);
    lcd.print("Main  Carb. NOS ");
    lcd.setCursor(0, 1);
    lcd.print(FuelMainPSI);
    lcd.setCursor(5, 1);
    lcd.print(FuelCarburtorPSI);
    lcd.setCursor(10, 1);
    lcd.print(FuelNOSPSI);
    
delay(50);
}
