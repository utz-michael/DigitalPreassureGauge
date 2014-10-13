#include <LiquidCrystal.h>
#include <EasyTransfer.h>
//create object
EasyTransfer ET;
struct RECEIVE_DATA_STRUCTURE{
//put your variable definitions here for the data you want to receive
//THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
int SeriallMain;
int SeriallCarburtor;
int SeriallNos;
};
//give a name to the group of data
RECEIVE_DATA_STRUCTURE mydata;



unsigned long time;




LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


float FuelMainPSI = -99; 
float FuelCarburtorPSI = -99; 
float FuelNOSPSI = -99; 

int FuelMain = 706; 
int FuelCarburtor = 706; 
int FuelNOS = 706; 


void setup() {
   Serial.begin(57600);
//start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc.
ET.begin(details(mydata), &Serial);
  
 
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
    

 
 
  
    lcd.setCursor(0, 0);
    lcd.print("   Switch on    ");
    lcd.setCursor(0, 1);
    lcd.print("    Fuelpump    ");

delay(3000);
}

void loop() {

if(ET.receiveData()){
//this is how you access the variables. [name of the group].[variable name]
//since we have data, we will blink it out.
FuelMain = mydata.SeriallMain ;
FuelCarburtor = mydata.SeriallCarburtor ;
FuelNOS = mydata.SeriallNos ;
 time = millis();
}


if (millis()-time >= 1000 )
{
 FuelMain = 706; 
 FuelCarburtor = 706; 
 FuelNOS = 706; 
}


FuelMainPSI = FuelMain /7.14;
FuelCarburtorPSI = FuelCarburtor /7.14;
FuelNOSPSI = FuelNOS /7.14;

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
