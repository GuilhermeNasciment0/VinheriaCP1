🍷 Monitor de Luminosidade para Vinheria

Este projeto utiliza um Arduino para monitorar os níveis de luz em ambientes de armazenamento de vinho (adegas).
O sistema categoriza a luminosidade em três níveis (Baixa, Média e Alta), fornecendo alertas visuais via display LCD e LEDs, além de um alarme sonoro para níveis de luz prejudiciais.


🚀 Funcionalidades

Leitura Percentual: Converte o sinal analógico do sensor LDR para uma escala de 0% a 100%.

Interface LCD: Exibe o status da luminosidade e a porcentagem em tempo real, com ícones customizados (Sol e Alerta).

Indicadores LED: \* 
🟢 Verde: Luminosidade ideal (Baixa).

🟡 Amarelo: Luminosidade média (Atenção).

🔴 Vermelho: Luminosidade alta (Risco).

Alerta Sonoro: O buzzer é acionado automaticamente se a luz ultrapassar o nível considerado seguro (acima de 20%).

🛠️ Hardware Necessário
1x Arduino (Uno, Nano ou similar)
1x Display LCD 16x2
1x Potenciômetro (para ajuste de contraste do LCD)
1x Sensor de Luz LDR
3x LEDs (Verde, Amarelo e Vermelho)
1x BuzzerResistores adequados para os LEDs e LDR
Jumpers e Protoboard

📌 Pinagem

Componente
Pino ArduinoLDR
(Sensor) A1
LED Verde 6
LED Amarelo 9
LED Vermelho 11
Buzzer 7
LCD (RS, E, D4, D5, D6, D7) 12, 13, 5, 4, 3, 2

⚙️ Funcionamento do Código

O sistema opera baseado em faixas de intensidade luminosa:

Luminosidade Baixa (0% - 20%): Estado ideal para vinhos. Apenas o LED verde acende.
Luminosidade Média (21% - 50%): Estado de alerta. O LED amarelo acende, o ícone de exclamação aparece no LCD e o buzzer é ativado.Luminosidade Alta (> 50%): Estado crítico. O LED vermelho acende, o display exibe "Alta!" e o buzzer permanece ativo.

📂 Como Usar
Conecte os componentes conforme a tabela de pinagem.
Certifique-se de ter a biblioteca LiquidCrystal.h instalada na sua IDE Arduino.
Carregue o código para o seu microcontrolador.
Acompanhe os valores pelo Monitor Serial (9600 bps) ou diretamente no Display LCD.

