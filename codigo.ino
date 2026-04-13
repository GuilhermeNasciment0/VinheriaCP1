#include <LiquidCrystal.h>
// Declaração das variáveis
int valor_sensor = 0;
int porcentagem = 0;

int intensidade_verde = 0;
int intensidade_amarelo = 0;
int intensidade_vermelho = 0;

// Declaração das portas do Arduino e suas funções
int led_verde = 6;
int led_amarelo = 9;
int led_vermelho = 11;

int buzzer = 7;

LiquidCrystal lcd(12, 13, 10, 5, 4, 3, 2);

// ===== Declração dos desenhos para o Display LCD =====
byte sol[8] = {
  0b00100,
  0b10101,
  0b01110,
  0b11111,
  0b01110,
  0b10101,
  0b00100,
  0b00000
};

byte alerta[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00000,
  0b00100,
  0b00000
};
//Código de Configuração de Ambiente
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); // Definindo tamanho do Display LCD

  lcd.createChar(0, sol);
  lcd.createChar(1, alerta);

  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  //Mensagem de Boas Vindas
  lcd.setCursor(0, 0);
  lcd.print ("Boas vindas *");
   delay(2500);
  lcd.clear();
  lcd.print("Luminosidade:");
  lcd.write(byte(0)); // sol
}
// Código de Execução Contínua
void loop()
{
  //Convertendo o Valor do fotoresistor para porcentagem com map()
  valor_sensor = analogRead(A1);
  porcentagem = map(valor_sensor, 0, 1023, 0, 100);
  
  //Exibição da Mensagem Fixa
  Serial.print("Sensor: ");
  Serial.print(valor_sensor);
  Serial.print(" | %: ");
  Serial.println(porcentagem);

  lcd.setCursor(0, 1);

  //Verificação de estado da luminosidade e exibição
  if (porcentagem <= 20) {
    lcd.print(" Baixa ");
  }
  else if (porcentagem <= 50) {
    lcd.write(byte(1)); // alerta
    lcd.print(" Media ");
  }
  else {
    lcd.write(byte(1)); // alerta
    lcd.print(" Alta! ");
  }

  // porcentagem no final
  lcd.setCursor(10, 1);
  lcd.print(porcentagem);
  lcd.print("% ");

  // ===== LEDs =====
  analogWrite(led_verde, 0);
  analogWrite(led_amarelo, 0);
  analogWrite(led_vermelho, 0);
  digitalWrite(buzzer, 0);
  // Verificação do estado da luminosidade e atribuição aos leds
  if (porcentagem <= 20) {
    analogWrite(led_verde, 255); // ACENDE VERDE
  }
  else if (porcentagem <= 50) {
    analogWrite(led_amarelo, 255); // ACENDE AMARELO
    digitalWrite(buzzer, 1);
  }
  else {
    analogWrite(led_vermelho, 255); // ACENDE VERMELHO
    digitalWrite(buzzer, 1);
  }

  delay(300);
}