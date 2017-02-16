# Povino

Repositório para o projeto final da diciplina Microcontroladores e aplicações, do curso de Engenharia de Computação da Universidade Federal de São Carlos(UFSCar).

![alt text](https://github.com/carlos-sa/povino/blob/master/images/hearts.jpeg)

## Proposta

O intuito do projeto é a realizar a montagem de um display de persistencia de visão com a utilização a de uma estrutura giratória, que será montada através de manufatura aditiva, que contará com uma filheira de led's coloridos endereçaveis. 

## Embasamento Teórico

O projeto se baseia no fenômeno de Persistência Retiniana: Ilusão provocada quando um objeto persiste na retina por uma fração de segundo após sua percepção. Esse efeito é responsável pela interpretação de movimento nos vídeos. A partir dái é possível formar imagens ou vídeos com estruturas estáticas em movimento desde que a alternância de frames aconteça mais rápido do que a percepção da visão humana (Cerda de 27 imagens por segundo). No projeto 8 led's anexados a uma estrutura piscam determinadas cores que junto com o movimento da peça, controlado pelo motor, formam uma animação.

A velocidade em que os led's irão trocar de cores, e a velocidade do motor foram obtidas testanto o projeto até que se pôde perceber a formação da animação.

### Materiais

- Estrutura em formato de ponte H*

- Motor DC (12 volts)

- Suporte para o motor, junto a estrutura

- Arduino Nano

- 8 Led's WS2812B (Led endereçavel)

- Bateria 9 volts 

- Caixa para bateria de 9 volts

- Led emissor infravermelho

- Led receptor infravermelho

- Fonte 12 volts

- Capacitor 100 uF

- Chave Liga/Desliga

![alt text](https://github.com/carlos-sa/povino/blob/master/Estrutura%20do%20projeto.jpg)

*A estrutura em formato de ponte H foi modelada no software 123D e impressa em uma impressora 3D.

![alt text](https://github.com/carlos-sa/povino/blob/master/images/modelo_estruturaH.jpeg)

## Descrição do Projeto

O projeto propõe a construção de um display de persistencia de visão, através de uma coluna de LED's que ao girar em uma frequencia superior a 24 Hz pode criar a impressão de que existe uma matriz de LED's ao invés de uma só coluna. A matriz de LED's virtual será usada para a reprodução de imagens coloridas.

Para controlar os LED's, que estarão acoplados ao eixo de um motor dc, será utilizado um arduino nano. Os LED's são to tipo RGB endereçaveis e também temos um sensor infravermelho que será utilizado como sensor de volta.

<a href="https://youtu.be/xx5EOAy6Ocg
" target="_blank"><img src="https://youtu.be/xx5EOAy6Ocg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

## Tarefas 

 - [x] Projeto CAD da estrutura
 - [x] Impressão da estrutura em 3D
 - [x] Levantamento do todos materiais
 - [x] Teste da rotação da estrutura
 - [x] Teste dos LED's 
 - [x] Implementação do código/animação 
 - [x] Teste da animação

## Desenvolvedores

- Ana Lucia Cardoso - Email: ana.lc18@gmail.com

- Carlos Augusto Santo Andre Junior - Email: carlos.santoandrea@hotmail.com

- Felipe José Bento da Silva - Email: felipejosebento@outlook.com
