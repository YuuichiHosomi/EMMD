#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

void setup(){
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"Station");
  Mirf.payload = sizeof(char);
  Mirf.config();
}

void loop(){
  char data;
  if(!Mirf.isSending() && Mirf.dataReady()){
    Mirf.getData((byte *)&data);
    Serial.print(data);
  }
  
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    Mirf.setTADDR((byte *)"Boat");  
    Mirf.send((byte *)&inChar);
  }
}
