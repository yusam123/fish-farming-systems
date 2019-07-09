#include "Button.h"

void setup()
{
  Serial.begin(115200);
  for(int i=0;i<8;i++){
  pinMode(input[i],INPUT_PULLUP);
  }
  for(int i=0;i<8;i++){
  pinMode(output[i],OUTPUT);
  }
}
void loop()
{
    for(int i=0;i<8;i++){
        int reading = digitalRead(input[i]);
        if (reading != lastButtonState[i]) {
            lastDebounceTime[i] = millis();
        } 
        if ((millis() - lastDebounceTime[i]) > debounceDelay[i]) {
          if (reading != buttonState[i]) {
              buttonState[i] = reading;
      
              if (buttonState[i] == HIGH) {
                    flag[i]=flag[i]^1; 
                    digitalWrite(output[i],flag[i]);
                    count[i]++;
                    Serial.print("pin:"+i);
                    Serial.print("have use ");
                    Serial.print(count[i]+"times");
                  }
                }
          }
        lastButtonState[i] = reading;
    }
}
