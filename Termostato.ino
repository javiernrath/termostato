
#include <OneWire.h> 
#include <DallasTemperature.h>

#define Pin 3 //DS1B29 al pin 3
OneWire ourWire(Pin);  
DallasTemperature sensors(&ourWire);

int Temp=40;//parametro de temperatura que activa el relay 


void setup() {
        Serial.begin(9600); 
        pinMode (5,OUTPUT);
   sensors.begin(); //Se inicia el DS18B20 
}

void loop() {
sensors.requestTemperatures();  //Prepara al DS18B20 para la lectura
float tDS = sensors.getTempCByIndex(0);  //Lectura del DS18B20

//Se imprimen las temperaturas
Serial.println ("Temperatura Actual");
Serial.print(tDS );
Serial.print("°celsius");
Serial.println (" ");
Serial.println (" ");
Serial.println ("Creado por jadasupport.wordpress.org");
Serial.println ("Javier Brathwaite");
Serial.println (" ");
delay(1000);// espera 1 segundos para seguir leyendo datos

if (tDS >=Temp){
    digitalWrite(5,HIGH);
 }
  if(tDS < Temp){
    digitalWrite(5,LOW);
  }
delay(1000);
}


