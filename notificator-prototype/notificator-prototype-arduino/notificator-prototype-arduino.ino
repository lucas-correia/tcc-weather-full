
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pino de leitura do sensor
  pinMode(5, INPUT);
  pinMode(A1, INPUT);
  //pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  //pino de energização do nodemcu
}

void loop() {

  float res = analogRead(A1) * (5.0 / 1024.0);
//  Serial.print("\nread: ");
//  Serial.print(analogRead(A1));
//  Serial.print("\nres: ");
//  Serial.print(res);
//  if(digitalRead(5) == HIGH) {
//    Serial.print("ativo");
//    digitalWrite(7, HIGH);
//  }

  if(res > 0.5) {
    Serial.print("ativo");
    digitalWrite(7, HIGH);
  }
  
  // put your main code here, to run repeatedly:
  //verifica agua no nível estabelecido
//  if(digitalRead(5) == HIGH) {
//    Serial.print("Agua encontrado, ligando mcu\n");
//    delay(2000);
//    digitalWrite(2, LOW);
//    digitalWrite(7, HIGH);
//    delay(40000);
//    digitalWrite(7, LOW);
//    Serial.print("DESLIGANDO\n");
//    digitalWrite(2, HIGH);
//    delay(120000);
//    
////    //verifica se o node mcu ja terminou a requisição
////    if(analogRead(A1) < 3.0) {
////      //energiza nodemcu para disparo de notificação
////      digitalWrite(7, HIGH);
////    } else {
////      //desliga nodemcu
////      digitalWrite(7, LOW);
////      delay(120000);
////    }
//  } 
  
}
