#include "shin.h"

PPD71 sh(Serial3);
PPD71::DATA data;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  while(sh.read(data)){}
  Serial.print("10 secs: ");
  Serial.println(data.avg_10s);
  
  Serial.print("30 secs: ");
  Serial.println(data.avg_30s);
  delay(2000);
}
