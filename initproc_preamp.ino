#include <EEPROM.h>
struct SavedData {                                    // definition of the data stored in eeprom
  bool VolPerChannel;                                 // boolean, if True volume level is fixed with channel change. Otherwise Volume is Attenuator
  uint8_t SelectedInput;                              // last selected input
  int BalanceOffset;                                  // balance offset of volume 
  bool HeadphoneActive;                               // headphones active, no output to amp
  bool AmpPassive;                                    // defines if preamp is used passive mode
  };
SavedData initdata;
int VolLevelsInit [5] = {                         // array of volumelevels if volumelevel per channel is active
  //Attenuator generic
  30,
  //AttenuatorCh1
  30,
  //AttenuatorCh2
  30,
  //AttenuatorCh3
  30,
  //AttenuatorCh4
  30
  };
int VolLevels [5];

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);                                     // open serial
initializeEEPROM();
ReadEEPROM();                                    
//UpdateEEPROM();
}

void loop() {

  // put your main code here, to run repeatedly:

}

void initializeEEPROM() {                                 // program the EEPROM of the Arduino with starting values, setup of programm will use these values
SavedData start = {
  false,                                                  // boolean, volume level per channel
  1,                                                      // channel used for start
  0,                                                      // balance offset 
  false,                                                  // headphones active 
  false                                                   // ampassive active
  };

  EEPROM.put(0, start);                                    // schrijf init naar eeprom
  EEPROM.put(10,VolLevelsInit);                            // scrijf volumelevels

}

void ReadEEPROM() {                                       // retrieve data from EEPROM
 // SavedData init;
  EEPROM.get(0, initdata);
  EEPROM.get(10,VolLevels);
  Serial.print("volume per channel    : ");
  Serial.println(initdata.VolPerChannel); 
  Serial.print("selected input chan   : "); 
  Serial.println(initdata.SelectedInput);  
  Serial.print("Balance offset        : "); 
  Serial.println(initdata.BalanceOffset);  
  Serial.print("Headphones active     : "); 
  Serial.println(initdata.HeadphoneActive); 
  Serial.print("AmpPassive active     : "); 
  Serial.println(initdata.AmpPassive); 
  Serial.print("Generic volume level  : "); 
  Serial.println(VolLevels[0]);  
  Serial.print("volumelevel input 1   : "); 
  Serial.println(VolLevels[1]); 
  Serial.print("volumelevel input 2   : "); 
  Serial.println(VolLevels[2]); 
  Serial.print("volumelevel input 3   : "); 
  Serial.println(VolLevels[3]);  
  Serial.print("volumelevel input 4   : "); 
  Serial.println(VolLevels[4]);    
  Serial.print("The Arduino EEPROM is now programmed, ready to be used when you load the preAmpArduino program "); 

}


void UpdateEEPROM()  {                                       // update data within EEPROM
 // SavedData init;
 // EEPROM.get(0, init); 
  Serial.println(VolLevels[0]);
  VolLevels[0]=20;
  EEPROM.put(10,VolLevels);
  EEPROM.get(10,VolLevels);
  Serial.println(VolLevels[0]);


}



