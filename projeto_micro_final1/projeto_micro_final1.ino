#include <Keypad.h>				// Define bibliotecas
#include <LiquidCrystal.h>		// Define bibliotecas

const byte linhas = 4;			// Define constante para linhas
const byte colunas = 4;			// Define constante para colunas

int erro = 0;					// Variaveis globais
int acerto = 0;
int pontuacao = 0;
int dificuldadeAtual=0;
int recordeNivel1 = 0;
int recordeNivel2 = 0;
int recordeNivel3 = 0;
int jogoAtual = 0;

char digitado;

char mapateclado[linhas][colunas]=	// Mapeamento do teclado matricial
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinlinhas[linhas] = {22, 24,26, 28};		// Definicao de pinos do teclado matricial
byte pincolunas[colunas] = {30, 32, 34, 36};	// Definicao de pinos do teclado matricial

Keypad tecladomat = Keypad(makeKeymap(mapateclado), pinlinhas, pincolunas, linhas, colunas);	// Mapemento de linhas e colunas do teclado matricial

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);			// Definicao de pinso do LCD

void setup(){						// Inicia a funcao de setup do programa
  lcd.begin(16, 2);					// Define a resolucao do LCD
  randomSeed(analogRead(A0));		// Seleciona uma porta do arduino para definir valores randomicos
  lcd.setCursor(0, 0);		//
  lcd.print("Multi-");		// Setup do cursor do LCD e impressao no LCD
  lcd.setCursor(3, 1);		//
  lcd.print("Jogos");		//
  delay(1500);				// Delay
}

void loop(){		// Funcao de loop
  menuInicial();	// Direciona o programa para a funcao de menu Inicial
}

void menuInicial(){				// Funcao de menu Inicial do Jogo
  lcd.clear();				//
  lcd.setCursor(0, 0);		//
  lcd.print("Selecione");	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);		//
  lcd.print("o jogo");		//
  delay(1000);
  
  lcd.clear();				//
  lcd.setCursor(0, 0);		//
  lcd.print("1-Sequencia");	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);		//
  lcd.print("2-Conversao");	//
    delay(1000);
  
  selecaoDoJogo();				//Direciona o programa para a funcao de selecao de jogo
  
   

}

void selecaoDoJogo(){				// Inicia a funcao de selecao de jogo
  digitado=0;						// Zera a variaval digitado para evitar bugs

  while(digitado == NO_KEY){		// Abre laço while para fazer leitura do teclado e aciona apos qualquer tecla ser pressionada
    digitado = tecladomat.getKey();	// Faz a leitura da tecla pressionada
  }
  
  switch(digitado){					// Inicia uma selecao do tipo swwitch/case para o valor lido do teclado
    case '1':						// Aciona caso 1
      lcd.clear();				//
      lcd.setCursor(0, 0);		//
      lcd.print("Jogo selec.");	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
      lcd.setCursor(0, 1);		//
      lcd.print("Sequencia" );	//
    delay(3000);
    menuJogoSequencia();	// Direciona o programa para a funcao do menu do jogo de sequencia
      break;
    case '2':						// Aciona caso 2
      lcd.clear();				//
      lcd.setCursor(0, 0);		//
      lcd.print("Jogo selec.");	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
      lcd.setCursor(0, 1);		//
      lcd.print("Conversao" );	//
    delay(3000);
    menuJogoConversao();	// Direciona o programa para a funcao do menu do jogo de conversao
      break;
  }
}

void menuJogoSequencia(){		// Inicia a funcao do jogo de sequencia (1)
  jogoAtual = 1;	// Define a variavel do jogo atual para verificacao futura
  digitado=0;		// Zera a variaval digitado para evitar bugs

  lcd.clear();				//
  lcd.setCursor(0, 0);		//
  lcd.print("Selecione a");	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);		//
  lcd.print("dificuldade:");//
  delay(1000);
  
  pontuacao = 0;	// Zera variavel de pontuacao

  lcd.clear();			//
  lcd.setCursor(0, 0);	//
  lcd.print("1");		//
  lcd.setCursor(5, 0);	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
  lcd.print("2");		//
  lcd.setCursor(10, 0);	//
  lcd.print("3");		//
  selecionaDificuldadeJ1();		// Direciona o programa para a funcao que seleciona dificuldade do jogo de sequencia (1)
}

void menuJogoConversao(){		// Inicia a fncao do menu do jogo de conversao (2)
  jogoAtual = 2;	// Define a variavel do jogo atual para verificacao futura
  digitado=0;		// Zera a variaval digitado para evitar bugs

  lcd.clear();					//
  lcd.setCursor(0, 0);			//
  lcd.print("Selecione a");		// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);			//
  lcd.print("dificuldade:");	//
  delay(1000);

  lcd.clear();			//
  lcd.setCursor(0, 0);	//
  lcd.print("1");		//
  lcd.setCursor(5, 0);	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
  lcd.print("2");		//
  lcd.setCursor(10, 0);	//
  lcd.print("3");		//
  
  selecionaDificuldadeJ2();		// Direciona o programa para a funcao que seleciona dificuldade do jogo de conversao (2)
}

void selecionaDificuldadeJ1(){		// Inicia a funcao de selecao da dificuldade do jogo de sequencia (1)
  digitado=0;		// Zera a variaval digitado para evitar bugs

  while(digitado == NO_KEY){		// Abre laço while para fazer leitura do teclado e aciona apos qualquer tecla ser pressionada
    digitado = tecladomat.getKey();	// Faz a leitura da tecla pressionada
  }

  switch(digitado){					// Inicia uma selecao do tipo swwitch/case para o valor lido do teclado
    case '1':						// Aciona caso 1
      lcd.clear();				//
      lcd.setCursor(0, 0);		//
      lcd.print("Dificuldade");	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
      lcd.setCursor(3, 1);		//
      lcd.print("selec.:Facil");//
      delay(3000);
      
      dificuldadeUmJ1();		// Direciona o programa para a funcao da dificuldade um do jogo de sequencia (1)
      break;
    
     case '2':						// Aciona caso 2
      lcd.clear();				//
      lcd.setCursor(0, 0);		//
      lcd.print("Dificuldade");	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
      lcd.setCursor(3, 1);		//
      lcd.print("selec.:Medio");//
      delay(3000);
      
      dificuldadeDoisJ1();		// Direciona o programa para a funcao da dificuldade dois do jogo de sequencia (1)
      break;
    
     case '3':						// Aciona caso 3
      lcd.clear();					//
      lcd.setCursor(0, 0);			//
      lcd.print("Dificuldade");		// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
      lcd.setCursor(2, 1);			//
      lcd.print("selec.:Dificil");	//
      delay(3000);
      
      //Chama a funcao do jogo
      dificuldadeTresJ1();		// Direciona o programa para a funcao da dificulcade tres do jogo de sequencia (1)
      break;
  }
}

void selecionaDificuldadeJ2(){		// Inicia a funcao de selecao da dificuldade do jogo de sequencia (1)
  digitado=0;		// Zera a variaval digitado para evitar bugs
  
  while(digitado == NO_KEY){		// Abre laço while para fazer leitura do teclado e aciona apos qualquer tecla ser pressionada
    digitado = tecladomat.getKey();	// Faz a leitura da tecla pressionada
  }

  switch(digitado){					// Inicia uma selecao do tipo swwitch/case para o valor lido do teclado
    case '1':						// Aciona caso 1
      lcd.clear();					//
      lcd.setCursor(0, 0);			//
      lcd.print("Dificuldade");		// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
      lcd.setCursor(3, 1);			//
      lcd.print("selec.:Facil");	//
      delay(3000);
      
      //Chama a funcao do jogo
      dificuldadeUmJ2();		// Direciona o programa para a funcao da dificulcade um do jogo de conversao (2)
      break;
    
     case '2':						// Aciona caso 2
      lcd.clear();					//
      lcd.setCursor(0, 0);			//
      lcd.print("Dificuldade");		// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
      lcd.setCursor(3, 1);			//
      lcd.print("selec.:Medio");	//
      delay(3000);
      
      //Chama a funcao do jogo
      dificuldadeDoisJ2();		// Direciona o programa para a funcao da dificulcade dois do jogo de conversao (2)
      break;
    
     case '3':						// Aciona caso 3
      lcd.clear();					//
      lcd.setCursor(0, 0);			//
      lcd.print("Dificuldade");		// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
      lcd.setCursor(2, 1);			//
      lcd.print("selec.:Dificil");	//
      delay(3000);
      
      dificuldadeTresJ2();		// Direciona o programa para a funcao da dificulcade tres do jogo de conversao (2)
      break;
  }
}

void dificuldadeUmJ1(){			// Inicia a funcao de dificuldade do jogo de sequencia (1)
  digitado=0;		// Zera a variaval digitado para evitar bugs
  
  dificuldadeAtual = 1;	// Define valor para a dificuldade atual
  
  lcd.clear();						//
  lcd.setCursor(0, 0);				//
  lcd.print ("Pontuacao atual");	// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);				//
  lcd.print (pontuacao);			// Imprime variavel de pontuacao
  delay(1000);
  lcd.clear();
  
  int num1 = random(10, 99);		// Define um valor aleatorio para a variavel
 
  lcd.setCursor(0, 0);		// Seta cursor do LCD em 0, 0
  lcd.print (num1);			// Imprime o valor da variavel
  delay(1000);				// Delay de 1 segundo
  lcd.clear();				// Limpa o LCD
 
  int resultado1 = num1;	// Salva valor da variavel impressa na variavel de resultado1
 
  
  lcd.setCursor(0, 0);		//
  lcd.print ("Numeros");	// Seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);		//
  lcd.print ("Digitados?");	//
  delay(1000);
  lcd.clear();
  
  String valorLido();							// Define valorLido como string para a funcao do valor que for digitado
  int resposta = valorLido().toInt();			// Salva valor digitado na variavel de resposta
   comparacaoValores( resposta, resultado1);	// Direciona o programa para fazer a comparacao de valores entre 'resultado1' e 'resposta'
} 

void dificuldadeUmJ2(){			// Inicia a funcao de dificuldade do jogo de conversao (2)
  digitado=0;		// Zera a variaval digitado para evitar bugs
  
  dificuldadeAtual = 1;	// Define valor para a dificuldade atual

  int n, c, k;			// Define variaveis locais da funcao

  n = random(1, 15);	// Define valor aleatorio para a variavel

  lcd.clear();			// Limpa LCD
  lcd.setCursor(0, 0);	// Seta cursor em 0, 0

  for(c = 3; c >= 0; c--)		// Inicia laco for para a impressao de ate 4 digitos no LCD
  {
    k = n >> c;					// Desloca os bits a direita dividindo por dois, assim convertendo e imprimindo o valor aleatorio em numero binario

    if(k & 1)			// Verificacao em if else para valor de 'k'
      lcd.print("1");	// Se 'k' for 1, imprime no LCD o valor 1
    else				// Caso 'k' nao seja 1
      lcd.print("0");	// Imprime no LCD o valor 0
  }

  lcd.setCursor(0, 1);	// Seta cursor em 0, 0
  lcd.print("R: ");		// Imprime mensagem no LCD
  
  String valorLido();					// Define valorLido como string para a funcao do valor que for digitado
  int resposta = valorLido().toInt();	// Salva valor digitado na variavel de resposta
  comparacaoValores(n, resposta);		// Direciona o programa para fazer a comparacao de valores entre 'n' e 'resposta'
}

void dificuldadeDoisJ1(){			// Inicia a funcao de dificuldade do jogo de sequencia (1)
  digitado=0;		// Zera a variaval digitado para evitar bugs
  
  dificuldadeAtual = 2;	// Define valor para a dificuldade atual
   
  lcd.clear();						//
  lcd.setCursor(0, 0);				// Limpa o LCD, seta o cursor em ponto especifico e imprime mensagem
  lcd.print ("Pontuacao atual");	//
  lcd.setCursor(0, 1);				//
  lcd.print (pontuacao);			// Imprime valor da variavel
  delay(1000);
  lcd.clear();						// Limpa Lcd
  
  int num1 = random(100*9, 999*9);	//Define valor aleatorio para a variavel
 
  lcd.setCursor(0, 0);	// Seta cursor em 0, 0
  lcd.print (num1);		// Imprime variavel
  delay(1000);
  lcd.clear();			// Limpa LCD
  
  int resultado1 = num1;	// Salva valor de 'num1' em 'resultado1'
 
  
  lcd.setCursor(0, 0);		//
  lcd.print ("Numeros");	// Seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);		//
  lcd.print ("Digitados?");	//
  delay(1000);
  lcd.clear();				// Limpa LCD
  
  String valorLido();							// Define valorLido como string para a funcao do valor que for digitado
  int resposta = valorLido().toInt();			// Salva valor digitado na variavel de resposta
  comparacaoValores(resposta, resultado1);		// Direciona o programa para fazer a comparacao de valores entre 'resultado1' e 'resposta'
} 

void dificuldadeDoisJ2(){		// Inicia a funcao de dificuldade do jogo de conversao (2)
  digitado=0;		// Zera a variaval digitado para evitar bugs
  
  dificuldadeAtual = 2;	// Define valor para a dificuldade atual

  int n, c, k;		// Define variaveis locais da funcao

  n = random(16, 63);	// Define valor aleatorio para a variavel

  lcd.clear();			// Limpa LCD
  lcd.setCursor(0, 0);	// Seta cursor em 0, 0

  for(c = 5; c >= 0; c--)		// Inicia laco for para a impressao de ate 4 digitos no LCD
  {
    k = n >> c;					// Desloca os bits a direita dividindo por dois, assim convertendo e imprimindo o valor aleatorio em numero binario

    if(k & 1)			// Verificacao em if else para valor de 'k'
      lcd.print("1");	// Se 'k' for 1, imprime no LCD o valor 1
    else				// Caso 'k' nao seja 1
      lcd.print("0");	// Imprime no LCD o valor 0
  }

  lcd.setCursor(0, 1);	// Seta cursor em 0, 0
  lcd.print("R: ");		// Imprime mensagem no LCD
  
  String valorLido();					// Define valorLido como string para a funcao do valor que for digitado
  int resposta = valorLido().toInt();	// Salva valor digitado na variavel de resposta
  comparacaoValores(n, resposta);		// Direciona o programa para fazer a comparacao de valores entre 'n' e 'resposta'
}

void dificuldadeTresJ1(){			// Inicia a funcao de dificuldade do jogo de sequencia (1)
  digitado=0;		// Zera a variaval digitado para evitar bugs
  
  dificuldadeAtual = 3;	// Define valor para a dificuldade atual
  
  lcd.clear();						//
  lcd.setCursor(0, 0);				//
  lcd.print ("Pontuacao atual");	// Limpa e seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);				//
  lcd.print (pontuacao);			//
  delay(1000);
  lcd.clear();						// Limpa LCD
  
  int num1 = random(1000*9, 9999*9);	//Define valor aleatorio para a variavel
 
  lcd.setCursor(0, 0);	// Seta cursor em 0, 0
  lcd.print (num1);		// Imprime a variavel
  delay(1000);             
  lcd.clear();			// Limpa LCD
  
  int resultado1 = num1;	// Salva valor de 'num1' em 'resultado1
 
  
  lcd.setCursor(0, 0);		//
  lcd.print ("Numeros");	// Seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);		//
  lcd.print ("Digitados?");	//
  delay(1000);
  lcd.clear();				// Limpa LCD
  
  String valorLido();							// Define valorLido como string para a funcao do valor que for digitado
  int resposta = valorLido().toInt();			// Salva valor digitado na variavel de resposta
  comparacaoValores( resposta, resultado1);		// Direciona o programa para fazer a comparacao de valores entre 'resultado1' e 'resposta'
} 

void dificuldadeTresJ2(){		// Inicia a funcao de dificuldade do jogo de conversao (2)
  digitado=0;				// Zera a variaval digitado para evitar bugs
  
  dificuldadeAtual = 3;	// Define valor para a dificuldade atual

  int n, c, k;		// Define variaveis locais da funcao

  n = random(64, 255);	// Define valor aleatorio para a variavel

  lcd.clear();			// Limpa LCD
  lcd.setCursor(0,0);	// Seta cursor em 0, 0

  for(c = 7; c >= 0; c--)		// Inicia laco for para a impressao de ate 4 digitos no LCD
  {
    k = n >> c;					// Desloca os bits a direita dividindo por dois, assim convertendo e imprimindo o valor aleatorio em numero binario

    if(k & 1)			// Verificacao em if else para valor de 'k'
      lcd.print("1");	// Se 'k' for 1, imprime no LCD o valor 1
    else				// Caso 'k' nao seja 1
      lcd.print("0");	// Imprime no LCD o valor 0
  }

  lcd.setCursor(0, 1);	// Seta cursor em 0, 0
  lcd.print("R: ");		// Imprime mensagem no LCD
  
  String valorLido();					// Define valorLido como string para a funcao do valor que for digitado
  int resposta = valorLido().toInt();	// Salva valor digitado na variavel de resposta
  comparacaoValores(n, resposta);		// Direciona o programa para fazer a comparacao de valores entre 'n' e 'resposta'
}

void comparacaoValores(int x, int y){	// Inicia funcao para comparacao dos valores que serao recebidas de outra funcao
  digitado=0;							// Zera a variaval digitado para evitar bugs

  digitado = tecladomat.getKey();		// Recebe o primeiro valor digitado no teclado matricial

  if(y == x)		// Compara se os valores recebidos sao iguais
    acertos();		// Se forem iguais, direciona o programa para a funcao de 'acertos'
  else				// Senao
    erros();		// Direciona o programa para a funcao de 'erros'
}

void acertos(){		// Inica a funcao de acertos
  digitado=0;		// Zera a variaval digitado para evitar bugs
  
  lcd.clear();						//
  lcd.setCursor(0, 0);				// Limpa e seta o cursor em ponto especifico e imprime mensagem
  lcd.print("Acertou!");	//
  delay(1500);
	
  pontuacao++;						// Incrementa variavel de pontuacao para ser impresso no programa a pontuacao enquanto roda
  
  acerto = acrescimo(acerto);		// Faz incremento da variavel atravez de uma funcao especifica que recebe a mesma variavel e retorna o mmesmo incrementado
  
  if(dificuldadeAtual == 1){		// Confere, com uma variavel para conferencia de funcao, qual a dificuldade atual em que o programa entrou nesta funcao, para retornar na funcao anterior
    if(jogoAtual==1)				// Confere, com uma variavel para conferencia de funcao, qual o jogo atual em que o programa entrou nesta funcao, para retonar ao jogo anterior
    	dificuldadeUmJ1();			// Direciona o programa para a funcao de dificuldade do jogo (1)
    else
      	dificuldadeUmJ2();			// Direciona o programa para a funcao de dificuldade do jogo (2)
  }
  else if(dificuldadeAtual == 2){	// Confere, com uma variavel para conferencia de funcao, qual a dificuldade atual em que o programa entrou nesta funcao, para retornar na funcao anterior
    if(jogoAtual==1)				// Confere, com uma variavel para conferencia de funcao, qual o jogo atual em que o programa entrou nesta funcao, para retonar ao jogo anterior
    	dificuldadeDoisJ1();		// Direciona o programa para a funcao de dificuldade do jogo (1)
    else
      	dificuldadeDoisJ2();		// Direciona o programa para a funcao de dificuldade do jogo (2)
  }
  else{
    if(jogoAtual==1)				// Confere, com uma variavel para conferencia de funcao, qual o jogo atual em que o programa entrou nesta funcao, para retonar ao jogo anterior
    	dificuldadeTresJ1();		// Direciona o programa para a funcao de dificuldade do jogo (1)
    else
      	dificuldadeTresJ2();		// Direciona o programa para a funcao de dificuldade do jogo (2)
  }

  return;
}

void erros(){		// Inicia a funcai de erros
  digitado=0;		// Zera a variaval digitado para evitar bugs
  
  lcd.clear();						//
  lcd.setCursor(0, 0);				// Limpa e seta o cursor em ponto especifico e imprime mensagem
  lcd.print("Errou!");				//
  delay(1500);

  erro = acrescimo(erro);			// Faz incremento da variavel atravez de uma funcao especifica que recebe a mesma variavel e retorna o mmesmo incrementado

  if(erro == 3){					// Compara se a variovavel de erro e igual a zero
    erro=0;							// Se entrar no if, zera a variavel
    FimDeJogo();					// Direciona o programa para a funcao de Fim de Jogo
  }

  if(dificuldadeAtual == 1){		// Confere, com uma variavel para conferencia de funcao, qual a dificuldade atual em que o programa entrou nesta funcao, para retornar na funcao anterior
    if(jogoAtual==1)				// Confere, com uma variavel para conferencia de funcao, qual o jogo atual em que o programa entrou nesta funcao, para retonar ao jogo anterior
    	dificuldadeUmJ1();			// Direciona o programa para a funcao de dificuldade do jogo (1)
    else
      	dificuldadeUmJ2();			// Direciona o programa para a funcao de dificuldade do jogo (2)
  }
  else if(dificuldadeAtual == 2){	// Confere, com uma variavel para conferencia de funcao, qual a dificuldade atual em que o programa entrou nesta funcao, para retornar na funcao anterior
    if(jogoAtual==1)				// Confere, com uma variavel para conferencia de funcao, qual o jogo atual em que o programa entrou nesta funcao, para retonar ao jogo anterior
    	dificuldadeDoisJ1();		// Direciona o programa para a funcao de dificuldade do jogo (1)
    else
      	dificuldadeDoisJ2();		// Direciona o programa para a funcao de dificuldade do jogo (2)
  }
  else{
    if(jogoAtual==1)				// Confere, com uma variavel para conferencia de funcao, qual o jogo atual em que o programa entrou nesta funcao, para retonar ao jogo anterior
    	dificuldadeTresJ1();		// Direciona o programa para a funcao de dificuldade do jogo (1)
    else
      	dificuldadeTresJ2();		// Direciona o programa para a funcao de dificuldade do jogo (2)
  }
  return;
}

int acrescimo(int acr){		// Inicia a funcao de incremento
  digitado=0;				// Zera a variaval digitado para evitar bugs
  
  acr++;					// Faz incremento da variavel que a funcao recebe
  
  return acr;				// Retorna o valor da variavel
}

void FimDeJogo(){				// Inicia a funcao de fim de jogo
  digitado=0;					// Zera a variaval digitado para evitar bugs
  
  lcd.clear();					//
  lcd.setCursor(0, 0);			//
  lcd.print("Game Over");		// Limpa e seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(0, 1);			//
  lcd.print("Game Over");		//
  delay(2500);

  lcd.clear();					//
  lcd.setCursor(0, 0);			//
  lcd.print("Pontuacao: ");		// Limpa e seta o cursor em ponto especifico e imprime mensagem
  lcd.setCursor(14, 0);			//
  lcd.print(acerto);			//
  
  delay(5000);

  pontuacao=0;		// Zera a variavel de pontuacao
  continuar();		// Direciona o programa para a funcao de continuacao
}

void continuar(){			// Inicia a funcao continuar
  digitado=0;				// Zera a variaval digitado para evitar bugs
  
  lcd.clear();				//
  lcd.setCursor(0, 0);		//
  lcd.print("Continue?");	//
  lcd.setCursor(0, 1);		// Limpa e seta o cursor em ponto especifico e imprime mensagem
  lcd.print("1 - Sim");		//
  lcd.setCursor(9, 1);		//
  lcd.print("2 - Nao");		//

  while(digitado == NO_KEY){			// Inicia laco while enquanto nao for digitado nada
    digitado = tecladomat.getKey();		// Recebe o valor digitado do teclado matricial
  }

  switch(digitado){				// Inicia uma selecao do tipo swwitch/case para o valor lido do teclado
    case '1':					// Caso 1
      if(jogoAtual == 1)		// Confere, com uma variavel para conferencia de funcao, qual o jogo atual em que o programa entrou nesta funcao, para retonar ao jogo anterior
        menuJogoSequencia();	// Direciona o programa para a funcao de menu do jogo de sequencia (1)
      else
        menuJogoConversao();	// Direciona o programa para a funcao de menu do jogo de conversao (2)
      break;

    case '2':					// Caso 2
      menuInicial();			// Direciona o programa para a funcao de menu Inicial
      break;
  }
}

String valorLido(){										// Inicia a funcao de valor lido
  String valorDigitado = "";							// Declara a variavel para o valor que vai ser digitado
  char  teclaPress = tecladomat.getKey();				// Declara uma variavel para cada digito e recebe o valor digitado
  while(teclaPress != '#'){								// Laco que roda ate que a tecla '#' seja digitada
    teclaPress = tecladomat.getKey();					// Recebe o valor da tecla
    if((teclaPress != NO_KEY) && (teclaPress != '#')){	// Compara se foi recebido algo do teclado e se e diferente de '#'
      valorDigitado.concat(teclaPress);					// Concatena as teclas da variavel tipo char em variavel tipo string
      lcd.print(teclaPress);							// Imprime a tecla digitada
    }
  }
  return(valorDigitado);								// Retorna o valor digitado apos ser pressionado a tecla '#'
}