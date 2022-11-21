int INF = 4;

int lampada = 3;
int LED_yellow = 10;
int LED_red = 9;
int LED_green = 8;
int sensor;

boolean ultimo_inf = LOW;
boolean atual_inf = LOW;
boolean ledOn = false;

void setup() {
  pinMode(INF, INPUT);
  pinMode(lampada, OUTPUT);
  pinMode(LED_yellow, OUTPUT);
  pinMode(LED_red, OUTPUT);
  pinMode(LED_green, OUTPUT);
}

boolean armazena(boolean ultimo){
  boolean atual = digitalRead(INF);
  if(atual != ultimo){
    atual = digitalRead(INF);
  }
  return atual;
}

void loop() {
  atual_inf = armazena(ultimo_inf);
  digitalWrite(LED_red, HIGH);
  digitalWrite(LED_yellow, HIGH);
  if(ultimo_inf == LOW && atual_inf == HIGH){
    ledOn = !ledOn;
  }
  if(ledOn == HIGH){
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_red, HIGH);
  }
  else{
    digitalWrite(LED_green, HIGH);
    digitalWrite(LED_red, LOW);
  }
  ultimo_inf = atual_inf;
  digitalWrite(lampada, ledOn);
  delay(700);
}
