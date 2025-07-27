const int PD = 2;
const int R2 = 4;
const int G1 = 3;
const int G2 = 5;
const int V1 = 6;
const int V2 = 7;
const int INT = 8;
const int R1 = 9;
const int PV = 10;
const int Fres = A0;
const int trig = 12;
const int echo = 11;
const int buz = 13;
const int PR = 16;
const int PG = 15;
int PREN = 0, a = 0, b = 0, c = 0, e = 0, d = 0, f = 0;
int distanza = 101;


void setup()
{
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(G1,OUTPUT);
  pinMode(G2,OUTPUT);
  pinMode(V1,OUTPUT);
  pinMode(V2,OUTPUT);
  pinMode(INT,INPUT);
  pinMode(Fres,INPUT);
  pinMode(PD, INPUT_PULLUP);
  pinMode(PV,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buz, OUTPUT);
  pinMode(PR, OUTPUT);
  pinMode(PG, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(PD), PRENOTAZIONE, RISING);
  
  Serial.begin(9600);
  PREN = 0;
}

void loop(){
  
  int ST = digitalRead(INT);
  int res = analogRead(Fres);
 
  if(INT == 0){
    f=0;
   digitalWrite(PR,HIGH);
    if(PREN == 0){
      a=0;
      if(res >= 300){
        if(b==0){
      Serial.println("Giorno");
      b=1;
      c=0;
        }
      NOTTE:
    digitalWrite(G1,LOW);
    digitalWrite(R2,LOW);
    digitalWrite(R1,HIGH);
    digitalWrite(V2,HIGH);

    delay(1000);
    digitalWrite(G2,HIGH);
    digitalWrite(V2,LOW);

    delay(1000);
    digitalWrite(G2,LOW);
    digitalWrite(V1,HIGH);
    digitalWrite(R2,HIGH);
    digitalWrite(R1,LOW);

    delay(1000);
    digitalWrite(G1,HIGH);
    digitalWrite(V1,LOW);
    digitalWrite(R2,HIGH);
    digitalWrite(R1,LOW);

    delay(1000);
    return;
      }else /*----------------------------NOTTE--*/ 
      b = 0;   
      if(c==0){
      Serial.println("Notte");
      c=1;
      }
      
      digitalWrite(trig,LOW);
      delayMicroseconds(5);
      digitalWrite(trig,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig,LOW);
      delayMicroseconds(5);
      unsigned long tempo = pulseIn(echo,HIGH);
      distanza = tempo/58;
      if(distanza <= 100){
        if(e==0)
        Serial.println("Macchina rilevata");
        d=0;
        e=1;
        digitalWrite(V1,LOW);
        digitalWrite(G1,HIGH);
        delay(1000);
        goto NOTTE;
        
      }else{
          if(d==0)
     Serial.println("Macchina non rilevata");
     d=1;
     e=0;
     
    digitalWrite(R1,LOW);   
    digitalWrite(G1,LOW);
    digitalWrite(V1,HIGH);
    digitalWrite(G2,LOW);
    digitalWrite(V2,LOW);
    digitalWrite(R2,HIGH);
      delay(1000);
      }
      
    }else
    {
      
    digitalWrite(G1,LOW);
    digitalWrite(V1,LOW);
    digitalWrite(G2,LOW);
    digitalWrite(V2,LOW);
    digitalWrite(PR,LOW);
   
    
    if(distanza >=100){
      digitalWrite(G1, HIGH);
      delay(1000);
      digitalWrite(G1, LOW);
    }
     digitalWrite(R2,HIGH);
     digitalWrite(R1,HIGH);
    digitalWrite(PV,HIGH);
    Serial.println("5 secondi al termine del passaggio pedone");
      for(int i=0; i<=1; i++){
      tone(buz,500,1000);
      delay(900);
        noTone(buz);
        delay(100);
      }
       Serial.println("4 secondi al termine del passaggio pedone");
      for(int i=0; i<=1; i++){
      tone(buz,500,1000);
      delay(900);
        noTone(buz);
        delay(100);
      }
       Serial.println("3 secondi al termine del passaggio pedone");
      for(int i=0; i<=1; i++){
      tone(buz,500,1000);
      delay(900);
        noTone(buz);
        delay(100);
      }
       Serial.println("2 secondi al termine del passaggio pedone");
      for(int i=0; i<=1; i++){
      tone(buz,500,1000);
      delay(900);
        noTone(buz);
        delay(100);
      }
      digitalWrite(PV,LOW);
      digitalWrite(PG,HIGH);
      Serial.println("1 secondo al termine del passaggio pedone");
      for(int i=0; i<=4; i++){
      tone(buz,500,500);
      delay(400);
        noTone(buz);
        delay(100);
      }
      Serial.println("Fine passaggio pedone");
      digitalWrite(PG,LOW);
      digitalWrite(PR,HIGH);
    PREN = 0;
     
    
      
    }
  } else{
    digitalWrite(PR,LOW);
    digitalWrite(V2,LOW);
    digitalWrite(R2,LOW);
    digitalWrite(G1,HIGH);
    digitalWrite(G2,HIGH);
    digitalWrite(PG,HIGH);
    delay(500);
    digitalWrite(PG,LOW);
    digitalWrite(G1,LOW);
    digitalWrite(G2,LOW);
    delay(500);
    if(f==0)
    Serial.println("Spento");
    f=1;
    b=0;
  }
  
}
void PRENOTAZIONE(){
 
  if (a==0){
      Serial.println("Prenotato");
      a=1;
      }
      PREN = 1;
    }
