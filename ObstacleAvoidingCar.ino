int MA = 12;
int MB = 13;
int MA_SPEED = 10;
int MB_SPEED = 11;
int trigPin = 5;
int echoPin = 6;
long duration;
int distance;
int R_S = AO;
int L_S = A2;
int S_S = A1;

#define Buzzer 4

void setup(){
  pinMode(MA,OUTPUT);
  pinMode(MB,OUTPUT);
  pinMode(L_S,INPUT);
  pinMode(R_S,INPUT);
  pinMode(S_S,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  Serial.begin(9600);
}

void Forward(){
  digitalWrite(MA,HIGH);
  digitalWrite(MB,HIGH);
  analogWrite(MA_SPEED,255);
  analogWrite(MB_SPEED,255);
}
void Backward(){
  digitalWrite(MA,LOW);
  digitalWrite(MB,LOW);
  analogWrite(MA_SPEED,255);
  analogWrite(MB_SPEED,255);
}
void Right(){
  digitalWrite(MA,HIGH);
  digitalWrite(MB,LOW);
  analogWrite(MA_SPEED,255);
  analogWrite(MB_SPEED,255);
}
void Left(){
  digitalWrite(MA,LOW);
  digitalWrite(MB,HIGH);
  analogWrite(MA_SPEED,255);
  analogWrite(MB_SPEED,255);
}
void Stop(){
  digitalWrite(MA,HIGH);
  digitalWrite(MB,HIGH);
  analogWrite(MA_SPEED,0);
  analogWrite(MB_SPEED,0);
}
void ReadDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance<=10){
    Stop();
    delay(500);
    Backward();
    delay(500);
    Right();
    ReadDistance();
    if (distance<=10){
      Left();
    else{
      Forward();
    }
    }
 else{
    Forward();
  }
}
}
