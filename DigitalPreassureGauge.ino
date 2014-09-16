#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

float FuelMainCal = 0; 
float FuelCarburtorCal = 0; 
float FuelNOSCal = 0; 

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
delay(3000);

   
    lcd.setCursor(0, 0);
    lcd.print("Calibrate Sensor");
    lcd.setCursor(0, 1);
    lcd.print("Fuelpump off    ");
delay(3000);    
    
for(int x =0 ; x < 1000 ; x++){
 
 FuelMainCal = FuelMainCal + analogRead(1); 
 FuelCarburtorCal = FuelCarburtorCal + analogRead(2); 
 FuelNOSCal = FuelNOSCal + analogRead(3); 

}

  
 FuelMainCal = (int)((FuelMainCal /1000)+ .5);
 FuelCarburtorCal = (int)((FuelCarburtorCal /1000)+ .5); 
 FuelNOSCal = (int)((FuelNOSCal /1000)+ .5); 
  Serial.print("FuelMainCal: ");
  Serial.println(FuelMainCal);
   Serial.print("FuelCarburtorCal: ");
  Serial.println(FuelCarburtorCal);
  Serial.print("FuelNOS_cal: ");
  Serial.println(FuelNOSCal);
 
  
    lcd.setCursor(0, 0);
    lcd.print("   Switch on    ");
    lcd.setCursor(0, 1);
    lcd.print("    Fuelpump    ");
 /*   
 do
{
  delay(50);          // wait for sensors to stabilize
 FuelMain = analogRead(1);  // check the sensors

} while (FuelMain < FuelMainCal +10 );   

*/
delay(3000);
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
