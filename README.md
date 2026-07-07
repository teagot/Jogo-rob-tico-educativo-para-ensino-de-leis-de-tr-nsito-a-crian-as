# Jogo-robotico-educativo-para-ensino-de-leis-de-transito-a-criancas
Arquivos necessários para a construção do Jogo robótico educativo para ensino de leis de trânsito a crianças, junto com uma breve descrição destes para facilitar a construção do jogo.

O jogo robótico educativo para ensino de leis de trânsito a crianças é um jogo físico desenvolvido no intuito de demonstrar de forma prática a aplicação das leis impostas pelo Código de Trânsito Brasileiro para crianças. O jogo utiliza um carrinho de controle remoto e uma maquete de cidade que contém obstáculos com regras, das quais as crianças devem demonstrar um comportamento digno de um motorista correto.
O presente documento, portanto, contém instruções de como construir o jogo para si, junto a ideias de adaptações e melhorias baseadas na construção original do jogo.

1. Lista de componentes:

1x Esp32 Dev Kit v1

1x Beetle Esp32 C6

1x Módulo Joystick KY-023

1x Módulo Ponte H* (o utilizado foi um semelhante ao TB6612FNG)

3x Bateria 3.7v, 650mAh, LiPo recarregável

3x Chapa MDF 6mm, 60x90mm

1x Chave interruptor

2x Micro Motor N20

1x Tinta PVA Preta

1x Tinta PVA Laranja

1x Tinta PVA Branca

1x Tinta PVA Vermelha

1x “Borracinha de impressora?”

?x Papelão

?x Impressão 3d / Filamento PLA

# A Construção do carrinho

Chassi feito em impressão 3d:
A estrutura base de suporte do veículo foi feita em impressão 3d, peça única, modelada no fusion. Segue abaixo modelo para impressão:

(Inserir o arquivo do chassi)

Dos componentes do carrinho:
A estrutura foi pensada com tamanho suficiente para caber todos os componentes necessários. Na parte superior do veículo, foi colada a Beetle Esp32 C6, o driver de motor e duas das baterias em paralelo, que alimentam todo o circuito. Abaixo, nos devidos encaixes, os dois motores, que movimentam o carrinho. As rodas foram feitas utilizando [Borrachinhas de impressora?], junto a pequenos adaptadores impressos em 3d, que adequam o diâmetro do furo da borracha a bitola do eixo do motor. Seguem abaixo, fotos da montagem do carrinho.

(Inserir foto da montagem do carrinho)
(Inserir arquivo do adaptador de roda)

As ligações (onde vai cada fio)
