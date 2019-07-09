#include <Energia.h>
const int input[8]={19,18,15,14,12,11,32,31};
const int output[8]={3,4,5,7,8,9,10,27};
int buttonState[8] = {HIGH};
int lastButtonState[8] = {HIGH};
long lastDebounceTime[8] = {HIGH};
long debounceDelay[8]={HIGH};
boolean flag[8]={0};
int count[8]={0};
