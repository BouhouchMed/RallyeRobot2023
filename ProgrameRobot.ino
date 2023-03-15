// C++ code
//
int captg = 0;

int captm = 0;
int ObsAll=0;
int captd = 0;
int in1 =1;
int in2 =2;
int in3 =7;
int in4 =8;
int ledbleu=13;
int led=1;
int stop=0;
int temp=7000;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(ledbleu, OUTPUT);
 digitalWrite(ledbleu, 0);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(3,1000);
  analogWrite(11,1000);
  AV();
  delay(7000);
}
void loop()
{ 
  captg = 0.01723 * readUltrasonicDistance(6, 12);
  captm = 0.01723 * readUltrasonicDistance(5, 10);
  captd = 0.01723 * readUltrasonicDistance(4, 9);
  if (captg<6 && 6>captd && 4>captm){
    if (led==2){
      digitalWrite(ledbleu,1);
      ART();
      stop=1;}
    }else if (stop==0)
      {delay(temp);
      led=2;
      if (4>captg)
        {TD();
        }else if (4>captd)
          TG();
          else if (8> captm)
            TG();
            else{
              AV();
              }
      }
    temp=0;

  
}
          
  
void MR(){
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void AV(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  
}
void TD(){
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
void TG(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void ART(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}
