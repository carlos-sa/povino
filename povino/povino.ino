//Include a biblioteca NeoPixel, disponibilidaza pela Adafruit
//e o arquivo que contem as definições de cores.
#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

//Define o pino onde está o receptor de infra-vermelho (sensor de posição).
int led_infra = 2;

//define o pino 4 como o pino de dados dos LED's
#define LEDS_PIN 4
//Define como 8 o numero de LED's em sequencia.
#define LED_COUNT 8

//Define o tempo de atraso entre cada coluna.
#define delay_time 2300
//Define quantas vezes cada quadra da animação aparece.
#define nVezesQuadro 3

//Cria um objeto para controlar os LED's.
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, LEDS_PIN, NEO_GRB + NEO_KHZ800);

//Espaço usado para criar a animação do pacman (usado para criar o efeito de aproximação).
int space = 15;
//Direção da movimentação do fantasma na animação do PACMAN.
bool direc = true;

//Cor inicial dos corações.
long HeartColor = RED;

//Desenho do PACMAN1 (Boca aberta)
long Pacman1[6][8] = {{BLACK  ,BLACK  ,YELLOW ,YELLOW ,YELLOW  ,BLACK  , BLACK  , BLACK },
                     {BLACK  ,YELLOW ,YELLOW ,YELLOW ,YELLOW  ,YELLOW , BLACK  , BLACK },
                     {YELLOW ,YELLOW ,YELLOW ,YELLOW ,YELLOW  ,YELLOW  , YELLOW , BLACK },
                     {YELLOW ,YELLOW ,YELLOW ,BLACK  ,YELLOW  ,YELLOW , YELLOW , BLACK },
                     {BLACK  ,YELLOW ,YELLOW ,BLACK  ,YELLOW  ,YELLOW , BLACK  , BLACK },
                     {BLACK  ,BLACK  ,YELLOW ,BLACK  ,YELLOW  ,BLACK  , BLACK  , BLACK }};

//Desenho do PACMAN2 (Boca fechada)
long Pacman2[6][8] = {{BLACK  ,BLACK  ,YELLOW ,YELLOW ,YELLOW  ,BLACK  , BLACK  , BLACK },
                      {BLACK  ,YELLOW ,YELLOW ,YELLOW ,YELLOW  ,YELLOW , BLACK  , BLACK },
                      {YELLOW ,YELLOW ,YELLOW ,YELLOW ,YELLOW  ,YELLOW  , YELLOW , BLACK },
                      {YELLOW ,YELLOW ,YELLOW ,YELLOW ,YELLOW  ,YELLOW , YELLOW , BLACK },
                      {BLACK  ,YELLOW ,YELLOW ,YELLOW ,YELLOW  ,YELLOW , BLACK  , BLACK },
                      {BLACK  ,BLACK  ,YELLOW ,YELLOW ,YELLOW  ,BLACK  , BLACK  , BLACK }};

//Coluna apagada, usada para criar espaços nas animações.
long black_row[1][8] = {{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK}};

//Desenho do Fantasma1 (Parado, vermelho).
long Ghost1[5][8] = {{RED   ,RED  ,RED  ,RED  ,RED   ,RED   , BLACK  , BLACK},
                     {BLACK ,RED  ,RED  ,RED  ,BLACK ,RED   , RED    , BLACK},
                     {RED   ,RED  ,RED  ,RED  ,RED   ,RED   , RED    , BLACK},
                     {BLACK ,RED  ,RED  ,RED  ,BLACK ,RED , RED    , BLACK},
                     {RED   ,RED  ,RED  ,RED  ,RED   ,RED   , BLACK    , BLACK}};

//Desenho do Fantasma2 (Movendo a perna, vermelho).
long Ghost2[5][8] = {{BLACK ,RED  ,RED  ,RED  ,RED   ,RED   , BLACK  , BLACK},
                     {RED   ,RED  ,RED  ,RED  ,BLACK ,RED   , RED    , BLACK},
                     {BLACK ,RED  ,RED  ,RED  ,RED   ,RED   , RED    , BLACK},
                     {RED   ,RED  ,RED  ,RED  ,BLACK ,RED   , RED    , BLACK},
                     {BLACK ,RED  ,RED  ,RED  ,RED   ,RED   , BLACK  , BLACK}};

//Desenho do Fantasma3 (Parado, azul).
long Ghost3[5][8] = {{BLUE   ,BLUE  ,BLUE  ,BLUE  ,BLUE  ,BLUE , BLACK , BLACK},
                     {BLACK  ,BLUE  ,BLUE  ,BLUE  ,WHITE ,BLUE , BLUE  , BLACK},
                     {BLUE   ,BLUE  ,BLUE  ,BLUE  ,BLUE  ,BLUE , BLUE  , BLACK},
                     {BLACK  ,BLUE  ,BLUE  ,BLUE  ,WHITE ,BLUE , BLUE  , BLACK},
                     {BLUE   ,BLUE  ,BLUE  ,BLUE  ,BLUE  ,BLUE , BLACK    , BLACK}};

//Desenho do Fantasma4 (Movendo a perna, azul).
long Ghost4[5][8] = {{BLACK  ,BLUE ,BLUE ,BLUE  ,BLUE   ,BLUE   , BLACK    , BLACK},
                     {BLUE ,BLUE ,BLUE ,BLUE  ,WHITE  ,BLUE   , BLUE    , BLACK},
                     {BLACK  ,BLUE ,BLUE ,BLUE  ,BLUE   ,BLUE   , BLUE    , BLACK},
                     {BLUE ,BLUE ,BLUE ,BLUE  ,WHITE  ,BLUE   , BLUE    , BLACK},
                     {BLACK  ,BLUE ,BLUE ,BLUE  ,BLUE   ,BLUE   , BLACK   , BLACK}};

//Mapa de qual pixel deve ser acesso para formar o coração.
bool heart[11][8] = {{false, false, false, false, true , true , true , false},
                    {false, false, false, true , true , true , true , true },
                    {false, false, true , true , true , true , true , true },
                    {false, true , true , true , true , true , true , false},
                    {true , true , true , true , true , true , false, false},
                    {false, true , true , true , true , true , true , false},
                    {false, false, true , true , true , true , true , true },
                    {false, false, false, true , true , true , true , true },
                    {false, false, false, false, true , true , true , false},
                    {false, false, false, false, false, false, false, false},
                    {false, false, false, false, false, false, false, false}};
          

void setup() {
  //Coloca o pino do sensor de posição como INPUT com PULLUP.
  pinMode(led_infra, INPUT_PULLUP);
  //Inicia a cadeia de LED's.
  leds.begin();
  //Define a cor de todos os LED's como preto.
  clearLEDs();
  //Atualiza a cor de todos os LED's com o preto definido acima.
  leds.show();
}

void loop() {
  //Reinicia as variaveis da animação do PACMAN.
  space = 15;
  direc = true;
  //Mantem a animação do PACMAN rodando até que acabe.
  for (int k = 0; k < 16; k++){
    //Repete o Quadra nVezesQuadro para melhor vizualização.
    for (int i=0; i<nVezesQuadro; i++){
      //Espera até que o sistema esteja na posição de inicio da animação.
      while(digitalRead(led_infra)){
        leds.setPixelColor(7, BLACK);
        leds.setPixelColor(6, BLACK);
        leds.setPixelColor(5, BLACK);
        leds.setPixelColor(4, BLACK);
        leds.setPixelColor(3, BLACK);
        leds.setPixelColor(2, BLACK);
        leds.setPixelColor(1, BLACK);
        leds.setPixelColor(0, BLACK);
        leds.show();
      }
      //Desenha o Pacman.
      drawImage(Pacman1,6);
      //Desenha o numero de colunas pretas definido em space.
      for (int j=0; j<space; j++){
        drawImage(black_row, 1);
      }
      //Verifica a direção para saber se o fantasma esta azul ou vermelho.
      if(direc == true)
        drawImage(Ghost1,5);
      else
        drawImage(Ghost3,5);
    }
    //Decresce ou aumenta o valor de space, de acordo com a direção atual.
    //Caso chegue ao fim do percurso, inverte a direção.
    if(direc == true){
      if(space == 2)
        direc = false;
      else{
        space--;
      }
    }
    if(direc == false){
      if(space == 15)
        direc = true;
      else{
        space++;
      }
    }
    //O codigo se repete com a outra posição das pernas dos fantasmas
    //e da boca do pacman.
    for (int i=0; i<nVezesQuadro; i++){
      while(digitalRead(led_infra)){
        leds.setPixelColor(7, BLACK);
        leds.setPixelColor(6, BLACK);
        leds.setPixelColor(5, BLACK);
        leds.setPixelColor(4, BLACK);
        leds.setPixelColor(3, BLACK);
        leds.setPixelColor(2, BLACK);
        leds.setPixelColor(1, BLACK);
        leds.setPixelColor(0, BLACK);
        leds.show();
      }
      drawImage(Pacman1,6);
      for (int j=0; j<space; j++){
        drawImage(black_row, 1);
      }
      if (direc == true)
        drawImage(Ghost2,5);
      else
        drawImage(Ghost4,5);
    }
    if(direc == true){
      if(space == 2)
        direc = false;
      else{
        space--;
      }
    }
    if(direc == false){
      if(space == 15)
        direc = true;
      else{
        space++;
      }
    }
  }
  //Reinicia a cor dos corações em vermelho.
  HeartColor = RED;
  //Chama a função que desenha o coração 250 vezes.
  for (int k=0; k<250; k++){
    drawHeart();
  }
}

//Função que seta todos os LEDS em preto
//Ainda é necessário chamar leds.show() para atualizar os LED's.
//Função copiada do código de exemplo da biblioteca.
void clearLEDs()
{
  for (int i=0; i<LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
  }
}

//Desenha a imagem passada em "frame" nos LED's
//É necessário tambem passar o tamanho da imagem em lenght
void drawImage(long frame[][8], int lenght){
   for(int i = 0; i<lenght; i++){
    leds.setPixelColor(7, frame[i][7]);
    leds.setPixelColor(6, frame[i][6]);
    leds.setPixelColor(5, frame[i][5]);
    leds.setPixelColor(4, frame[i][4]);
    leds.setPixelColor(3, frame[i][3]);
    leds.setPixelColor(2, frame[i][2]);
    leds.setPixelColor(1, frame[i][1]);
    leds.setPixelColor(0, frame[i][0]);
    leds.show();
    delayMicroseconds(delay_time);
  }
}

//Função que desenha os coroções
//A cada coração desenhado muda a cor.
void drawHeart(){
  for(int i = 0; i<11; i++){
    if (heart[i][7] == true)
      leds.setPixelColor(7, HeartColor);
    else
      leds.setPixelColor(7, BLACK);

    if (heart[i][6] == true)
      leds.setPixelColor(6, HeartColor);
    else
      leds.setPixelColor(6, BLACK);

    if (heart[i][5] == true)
      leds.setPixelColor(5, HeartColor);
    else
      leds.setPixelColor(5, BLACK);

    if (heart[i][4] == true)
      leds.setPixelColor(4, HeartColor);
    else
      leds.setPixelColor(4, BLACK);

    if (heart[i][3] == true)
      leds.setPixelColor(3, HeartColor);
    else
      leds.setPixelColor(3, BLACK);

    if (heart[i][2] == true)
      leds.setPixelColor(2, HeartColor);
    else
      leds.setPixelColor(2, BLACK);

    if (heart[i][1] == true)
      leds.setPixelColor(1, HeartColor);
    else
      leds.setPixelColor(1, BLACK);

    if (heart[i][0] == true)
      leds.setPixelColor(0, HeartColor);
    else
      leds.setPixelColor(0, BLACK);
      
    leds.show();
    delayMicroseconds(delay_time);
  }
  HeartColor += (1) + (5 << 8);
  
}

