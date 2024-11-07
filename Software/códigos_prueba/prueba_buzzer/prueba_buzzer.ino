int buzzerPin =A0;

int doNota = 262;
int reNota = 294;
int miNota = 330;
int faNota = 349;
int solNota = 392;
int laNota = 440;
int siNota = 466; 
int doAltaNota = 523;  

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
  tone(buzzerPin, doNota, 500);
  delay(500);
  tone(buzzerPin, doNota, 500);
  delay(500);
  tone(buzzerPin, faNota, 500);
  delay(500);
  tone(buzzerPin, miNota, 500);
  delay(500);
  delay(500);

  tone(buzzerPin, doNota, 500);
  delay(500);
  tone(buzzerPin, doNota, 500);
  delay(500);
  tone(buzzerPin, faNota, 500);
  delay(500);
  tone(buzzerPin, miNota, 500);
  delay(500);
  delay(500);

  tone(buzzerPin, doNota, 500);
  delay(500);
  tone(buzzerPin, doNota, 500); 
  delay(500);
  tone(buzzerPin, doAltaNota, 500);
  delay(500);
  tone(buzzerPin, siNota, 500);
  delay(500);
  tone(buzzerPin, laNota, 500);
  delay(500);
  delay(500);

  tone(buzzerPin, faNota, 500);
  delay(500);
  tone(buzzerPin, faNota, 500);
  delay(500);
  tone(buzzerPin, miNota, 500);
  delay(500);
  tone(buzzerPin, miNota, 500);
  delay(500);

  delay(1000);
}

