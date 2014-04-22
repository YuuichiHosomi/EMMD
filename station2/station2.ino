#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#define SERIAL_BUFFER_MAX 320
#define DATA_BUFFER_MAX 32

char sendDataBuffer[DATA_BUFFER_MAX];
char serialBuffer[SERIAL_BUFFER_MAX];
char recDataBuffer[DATA_BUFFER_MAX];
boolean dataReady;
int i,j,k,m;
void setup(){
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"Base");
  Mirf.payload = DATA_BUFFER_MAX;
  Mirf.config();
  dataReady==false;
  Mirf.setTADDR((byte *)"Boat");
  k=0;
  pinMode(RED_LED,OUTPUT);
  digitalWrite(RED_LED,LOW);
}

void loop(){


  if(!Mirf.isSending() && Mirf.dataReady()){
    
    Mirf.getData((byte *)&recDataBuffer[0]);
    Serial.print(recDataBuffer);  
    for(i=0;i<strlen(recDataBuffer);i++){
      recDataBuffer[i]=0;
    } 
   
  }
  
  if(dataReady==true){
    j=0;
    for(i=0;i<strlen(serialBuffer);i++){
      sendDataBuffer[j]=serialBuffer[i];
      j++;
      if(j>=DATA_BUFFER_MAX || (i>=(strlen(serialBuffer)-1))){
       Mirf.send((byte *)&sendDataBuffer);
       for(m=0;m<DATA_BUFFER_MAX;m++){
         sendDataBuffer[m]=0;
       }
       j=0;
       delay(10);
      }
     
    }  
    for(i=0;i<=strlen(serialBuffer);i++){
      serialBuffer[i]=0;
    }
    
    digitalWrite(RED_LED,LOW);
    dataReady=false;
  } 
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if(k<SERIAL_BUFFER_MAX-1){
      serialBuffer[k] = inChar;
      k++;
    }  
    if(inChar=='\n'){
      digitalWrite(RED_LED,HIGH);
      serialBuffer[k]='\0';
      dataReady = true;
      k=0;
    }
    
  }
}
