#define echo 5
#define trig 4
#define echo2 8
#define trig2 9
#define buzzer 6
#define forw 7
#define back 10
#define left 2
#define right A4
#define motor_Right 10
#define motor_Left 13  
#define motor2_Left 11
#define motor2_Right 12
float duration, distance,duration1,distance1,duration2,distance2,freq;
bool  flag = true,_shouldStop; 
char Incoming_value=NULL;
unsigned long time_now_micro,time_now_milli;
void setup()
{
time_now_micro = micros();
time_now_milli = millis();
pinMode(left, INPUT);
pinMode(echo, INPUT);
pinMode(echo2, INPUT);
pinMode(forw, INPUT);
pinMode(back, INPUT);
pinMode(right, INPUT);
pinMode(trig, OUTPUT);
pinMode(trig2, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(motor_Right, OUTPUT);
pinMode(motor_Left, OUTPUT);
pinMode(motor2_Left, OUTPUT);
pinMode(motor2_Right, OUTPUT);
 Serial.begin(9600);
}

int ultraSonic(int x, int y){
  digitalWrite(x, LOW);
   if(micros()- time_now_micro >=5 && flag == true){
   time_now_micro = micros();
   flag = false;
   digitalWrite(x, HIGH);
 } 
  if(micros()- time_now_micro >=5 && flag == false){
   time_now_micro = micros();
   flag = true;
   digitalWrite(x, LOW);
 }
  duration = pulseIn(y, HIGH);
  distance = duration/29/2;
  return distance;
  }
  void movebackward(){
  digitalWrite(motor_Right, HIGH);
  digitalWrite(motor_Left, LOW);
  digitalWrite(motor2_Right, LOW);
  digitalWrite(motor2_Left, HIGH);
}
void moveforward(){
  digitalWrite(motor_Right, LOW);
  digitalWrite(motor_Left, HIGH);
  digitalWrite(motor2_Right, HIGH);
  digitalWrite(motor2_Left, LOW);
}
void moveright(){
  digitalWrite(motor_Right, LOW);
  digitalWrite(motor_Left, HIGH);
  digitalWrite(motor2_Right, LOW);
  digitalWrite(motor2_Left, LOW);
}
void moveleft(){
  digitalWrite(motor_Right, LOW);
  digitalWrite(motor_Left, LOW);
  digitalWrite(motor2_Right, HIGH);
  digitalWrite(motor2_Left, LOW);
}
void stopmoving(){ 
  digitalWrite(motor_Right, LOW);
  digitalWrite(motor_Left, LOW);
  digitalWrite(motor2_Right, LOW);
  digitalWrite(motor2_Left, LOW);
  }

void loop()
{
  Serial.println("a");
    if(Serial.available()>0)
  {
    Incoming_value=Serial.read();
  Serial.print(Incoming_value);
  Serial.print("\n");
  }
    if(distance1 <=30 || distance2 <=30){
    _shouldStop = true;
    }
  distance1 = ultraSonic(4,5);
  distance2 = ultraSonic(9,8);
  freq = 5000/distance1+distance2;

 if(distance1 <= 50 && distance1 >= 30 || distance2 <= 50 && distance2 >= 30){
    tone(buzzer, freq);
    } else {
      noTone(buzzer);
      }
  if(Incoming_value == 'f'||Incoming_value == 'F'||(digitalRead(forw)!=0) && !_shouldStop)
    {
      moveforward();
    }else if(Incoming_value == 'B'||Incoming_value == 'b'||(digitalRead(back)!=0) && !_shouldStop){
      movebackward();
      }
      else if(Incoming_value == 'R'||Incoming_value == 'r'||(digitalRead(right)!=0) && !_shouldStop){
      moveright();
      }
      else if(Incoming_value == 'L'||Incoming_value == 'l'||(digitalRead(left)!=0) && !_shouldStop){
      moveleft();
      }else{
        stopmoving();
        }
  if(_shouldStop){
    stopmoving();
    }
  
}
