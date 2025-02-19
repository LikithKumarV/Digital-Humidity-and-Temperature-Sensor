#include "DHT.h"
#define DHTPIN 15
#define DHTTYPE DHT11
int LED = 33;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT11 TEST...!"));
  dht.begin();
  pinMode(LED, OUTPUT);

}
void loop(){
  delay(2000);
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  float f=dht.readTemperature(true);
  if(isnan(h)|| isnan(t)|| isnan(f))
  {
    Serial.println(F("failed to read the DHT sensor"));
    return;

  } 
  float hif=dht.computeHeatIndex(f,h);
  float hic=dht.computeHeatIndex(t,h,false);
  Serial.println(F("Humidity: "));
  Serial.println(h);
  Serial.println(F("% Temperature "));
  Serial.print(t);
  Serial.println(F("C "));
  Serial.print(f);
  Serial.println(F("F "));
  Serial.print(F("Heat Index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F "));
  if(t > 20) {
    Serial.print("led is on");
    digitalWrite(LED, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(LED, LOW);
    Serial.print("LED  is off");
  }
}