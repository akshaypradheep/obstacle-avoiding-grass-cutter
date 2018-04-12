int vcc =4;
int gnd = 7;
int trigger=5;
int f =10;
int echo=6;
int left = 13;
int right = 12;
long time=0;
long dist=0;
void setup()
{
Serial.begin (9600);
pinMode(trigger, OUTPUT);
pinMode(vcc, OUTPUT);
pinMode(gnd, OUTPUT);
digitalWrite(vcc,HIGH);
digitalWrite(gnd,LOW);
pinMode(echo, INPUT);
pinMode(left,OUTPUT);
pinMode(right,OUTPUT);
}
void loop()
{
digitalWrite(trigger, LOW);
delay(5);
digitalWrite(trigger, HIGH);
delay(10);
digitalWrite(trigger, LOW);
time = pulseIn(echo, HIGH);
dist = (time/2) / 29.1;

 if(dist < 10)
{
 if(f<0){
  digitalWrite(left,HIGH);
  digitalWrite(right,LOW);
  Serial.println("<");
  delay(5000);
 }
 else{
  digitalWrite(left,LOW);
  digitalWrite(right,HIGH);
  Serial.println(">");
  delay(5000);
 }
}
else{
  digitalWrite(left,HIGH);
  digitalWrite(right,HIGH);
  Serial.println("^");
  
}
f=-f;
}
