# Jogo robótico educativo para ensino de leis de trânsito a crianças
Arquivos necessários para a construção do Jogo robótico educativo para ensino de leis de trânsito a crianças, junto com uma breve descrição destes para facilitar a construção do jogo.

O jogo robótico educativo para ensino de leis de trânsito a crianças é um jogo físico desenvolvido no intuito de demonstrar de forma prática a aplicação das leis impostas pelo Código de Trânsito Brasileiro para crianças. O jogo utiliza um carrinho de controle remoto e uma maquete de cidade que contém obstáculos com regras, das quais as crianças devem demonstrar um comportamento digno de um motorista correto.
O presente documento, portanto, contém instruções de como construir o jogo para si, junto a ideias de adaptações e melhorias baseadas na construção original do jogo.

Lista de componentes:

1x Esp32 Dev Kit v1;

1x Beetle Esp32 C6;

1x Módulo Joystick KY-023;

1x Módulo Ponte H* (o utilizado foi um semelhante ao TB6612FNG);

3x Bateria 3.7v, 650mAh, LiPo recarregável;

3x Chapa MDF 6mm, 60x90mm;

1x Chave interruptor;

2x Micro Motor N20;

1x Tinta PVA Preta;

1x Tinta PVA Laranja;

1x Tinta PVA Branca;

1x Tinta PVA Vermelha;

2x Borracha de impressora;

Papelão;

Impressão 3d / Filamento PLA.

# A construção do carrinho

Chassi feito em impressão 3D:
A estrutura base de suporte do veículo foi feita em impressão 3d, peça única;

Dos componentes do carrinho:
A estrutura foi pensada com tamanho suficiente para caber todos os componentes necessários. Na parte superior do veículo, foi colada a Beetle Esp32 C6, o driver de motor e duas das baterias em paralelo, que alimentam todo o circuito. Abaixo, nos devidos encaixes, os dois motores, que movimentam o carrinho. As rodas foram feitas utilizando dois pedaços de borracha de rolete de impressora, cortados ao meio, junto a pequenos adaptadores impressos em 3d, que adequam o diâmetro do furo da borracha a bitola do eixo do motor. Seguem abaixo, fotos da montagem do carrinho.

<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/f264f1a4-c42e-4337-b1d3-8c69f744ff13" />    <img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/74254477-899b-46a9-aae5-b25ceacafa8a" />


As ligações (onde vai cada fio)
GND é comum;

Positivo da Bateria - BAT+ do esp;

Negativo da Bateria - BAT- do esp;


AIN1 do Driver - 3 do esp;

AIN2 do Driver - 4 do esp;

BIN1 do Driver - 6 do esp;

BIN2 do Driver - 7 do esp;


PWM A do Driver - Bateria;

PWM B do Driver - Bateria;

STBY do Driver - Bateria;

VM do Driver - Bateria;


AO1 do Driver - Positivo do Motor 1;

AO2 do Driver - Negativo do Motor 1;

BO1 do Driver - Positivo do Motor 2;

BO2 do Driver - Negativo do Motor 2;

<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/e30c3682-69fd-4c39-9d23-5d9992d855b9" />


# Do controle remoto

Da estrutura e dos componentes:
O controle é feito de forma simples; Esp32 Dev Kit v1, um módulo Joystick KY-023 e uma bateria 3.7v 650mAh. Tudo isso, guardado inserido em uma pequena caixa de papelão.

<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/8c838d57-0a33-4611-b125-9b344750d75a" />


Positivo da Bateria - 3.3v da esp e alimentação do controle;

Negativo da Bateria - GND;

JOY_X do controle - 34 da esp;
JOY_Y do controle - 35 da esp;

# Da conexão carro-controle

Código do carrinho:
A conexão entre as duas Esp32, feita no intuito da passagem de comandos entre controle e carrinho é feita através de BLE (Bluetooth Low Energy), que possui alcance viável para o trabalho e alta taxa de economia de energia. Nesse caso, a Esp32 do carrinho atua como “client” do Bluetooth (ou seja, o receptor, que recebe os comandos vindos do controle, que é o server). O código está contido nesse repositório.

 Código do Controle:
O controle atua como “server” Bluetooth, ou seja, quem envia os comandos, que são captados pelo client. Nesse caso, ele capta os sinais elétricos correspondentes ao movimento do joystick, os converte em um sinal que pode ser enviado pelo bluetooth, e a Esp32 do carrinho responde a esses sinais na forma de movimento dos motores. O código está contido nesse repositório.

# Da maquete

 Estrutura base:
A estrutura base é construída com as três chapas de MDF mencionadas na lista de materiais. As chapas possuem recortes que se encaixam para formar uma única estrutura, e gravações na forma de ruas, que guiam o caminho do jogo. Além disso, há faixas de pedestres gravadas na maquete. Esses recortes e gravações, feitos justamente em máquina de corte à laser, com os arquivos DXF localizados neste repositório.

<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/94321f75-64ac-439d-a02e-b5c8e4bfa50c" />


 Obstáculos:
Os obstáculos físicos (placa de pare, placa de obras na pista, placa de virada obrigatória, cones) foram parte modelados e impressos em impressão 3D, parte, feitos manualmente. Nesse sentido, os cones e as bases de sustentação das placas foram impressas, enquanto suas partes correspondentes à sinalização foram recortadas em papelão, e pintadas com tinta PVA. Os arquivos para impressão 3D estão contidos neste repositório, enquanto as partes de construção manual estão descritas e demonstradas abaixo:
(INSIRA MEDIDAS E FOTOS)

<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/cceafd00-d8a8-4ac9-ae52-c1b3726d68de" />  <img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/d9f991f3-c8f7-4f61-a2c5-e79e35ee1a79" />  <img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/f9115fb9-e07e-420c-b8c0-94cf93c49241" />



