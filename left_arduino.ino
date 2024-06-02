#define ldr_R A0
#define led_F 11
#define led_B 12

#define ldr_L A4
#define led_BLUE 2 
#define led_RED 3

#define smoke A1
#define rain A2
#define led_S 4

float x=0 , y=0 , ldr_L_read , ldr_R_read,rain_Read, smoke_Read;
unsigned long time_now = 0;
bool rb, bb,shuffle;

void setup() {
  pinMode(ldr_L, INPUT);
  pinMode (led_BLUE, OUTPUT);
  pinMode (led_RED, OUTPUT);
  pinMode(ldr_R, INPUT);
  pinMode (led_F, OUTPUT);
  pinMode (led_B, OUTPUT);

  pinMode (smoke, OUTPUT);
  pinMode (rain, OUTPUT);
  pinMode (led_S, OUTPUT);
Serial.begin(9600);
time_now = millis();
}

void loop() {  
  smoke_Read = analogRead(smoke);
  rain_Read = analogRead(rain);
  ldr_L_read = analogRead(ldr_L);
  ldr_R_read = analogRead(ldr_R);
  if(ldr_L_read <= 5 || ldr_R_read <=5)
  { 
    if(millis()-time_now >= 100 && shuffle == false){
    digitalWrite(led_RED,HIGH);
    digitalWrite(led_BLUE,LOW);
    digitalWrite(led_F,HIGH);
    digitalWrite(led_B,LOW);
    shuffle = !shuffle;
    time_now = millis();
    }else if(millis()-time_now >= 100 && shuffle == true){
      shuffle = !shuffle;
      digitalWrite(led_RED,LOW);
      digitalWrite(led_BLUE,HIGH);
      digitalWrite(led_F,LOW);
      digitalWrite(led_B,HIGH);
      time_now = millis();
      }
    
  }else{
    digitalWrite(led_RED,LOW);
    digitalWrite(led_BLUE,LOW);
    digitalWrite(led_F,LOW);
    digitalWrite(led_B,LOW);
    }
  if(smoke_Read>=1)
  {
    digitalWrite(led_S,1);
    }
    Serial.println(smoke_Read);
  
        
}
