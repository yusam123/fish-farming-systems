int buttonState = 0;         // variable for reading the pushbutton status   
    const int input[8]={19,18,15,14,12,11,32,31};
    const int output[8]={3,4,5,7,8,9,10,27};
    boolean flag[8]={0};
    int count[8]={0};
void setup()
{
  for(int i=0;i<8;i++){
  pinMode(input[i],INPUT_PULLUP);
  }
  for(int i=0;i<8;i++){
  pinMode(output[i],OUTPUT);
  }
}
void loop()
{
    for(int i =0;i<8;i++){
    buttonState=digitalRead(input[i]);
    if(buttonState!=1){
      flag[i]=flag[i]^1; 
      count[i]++;
    }   
    if(flag[i]==0){
      digitalWrite(output[i],1);
    }
    else if(flag[i]==1){
      digitalWrite(output[i],0);
    }
    }
   delay(500);
}
