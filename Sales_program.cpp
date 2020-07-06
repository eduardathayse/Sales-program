#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include<string.h>


typedef struct { //Registro (Clientes)
	
char nome [15];
int sexo, idade, pacote, pontostv,id;
int sair;
float mensalidade;
	
}clientes;

FILE *Pclientes; //Criar Arquivo.

clientes Rclientes, Xclientes;//Vari�veis para chamar o Registro.

main() {//Programa Principal Com os Menus de Op��es.

setlocale (LC_ALL, "Portuguese"); //Utilizar a l�ngua Portuguesa nos enunciados.

int opcao; //Vari�vel Utilizada para ser chamada no menuop. Abaixo estamos declarando as fun��es.
void menuop(); 
	void cadastrarcliente();
		void arquivo();
			void listagemgeral();
				void linha();
					void cabecalho();
						void editar();
							void remover();
								void listagemporpacote();
									void relatorioestatistico();
										int qdtclientemaiorque3pontos();
											int somadordepontosdetv();
												float mediacliente60();
													float somaempresa();
													

do { //Estrutura de Repeti��o para o Menu de Op��es.
	
	cabecalho();
	menuop();
	
	do{ //Estrutura de Repeti��o para a Escolha de Op��es do Menu, e corre��o caso seja digitado n�mero n�o correspondente.
		
			printf("Escolha uma das Op��es:\n");
	scanf("%d",&opcao);
						system("cls");
		if(opcao !=1 && opcao !=2 && opcao !=3 && opcao !=4 && opcao !=5 && opcao !=6 && opcao !=7 && opcao !=0){
			printf("Op��o Inv�lida\n");
		}
	}while(opcao !=1 && opcao !=2 && opcao !=3 && opcao !=4 && opcao !=5 && opcao !=6 && opcao !=7 && opcao !=0);
			
	if(opcao==1){ //Primeira Op��o do Menu.
		cabecalho(); //Procedimento para ficar chamando o cabe�alho.
				arquivo(); //Abertura do Arquivo.
			printf ("Cadastrar Cliente:\n\n\n"); 
					cadastrarcliente(); //Procedimento para Cadastrar Cliente.
					fclose(Pclientes);	//Fechamento do Arquivo
			}
	if(opcao==2){ //Segunda Op��o do Menu.
		cabecalho(); //Procedimento para ficar chamando o cabe�alho.
			printf("Listagem Geral dos Clientes.\n\n");	
				arquivo();//Abertura do Arquivo.
					listagemgeral(); //Procedimento para Listagem Geral.
					fclose(Pclientes);//Fechamento do Arquivo
												
			}
	if(opcao==3){ //Terceira Op��o do Menu.
		cabecalho(); //Procedimento para ficar chamando o cabe�alho.
				arquivo();//Abertura do Arquivo.
					relatorioestatistico(); //Fun��o para chamar o Relat�rio Estat�stico.
					fclose(Pclientes);//Fechamento do Arquivo									
			}
	if(opcao==4){ //Quarta Op��o do Menu.
		cabecalho(); //Procedimento para ficar chamando o cabe�alho.
			printf("Editar Cliente\n\n");	
				arquivo();//Abertura do Arquivo.
					editar();//Procedimento para Editar o Cliente.
					fclose(Pclientes);//Fechamento do Arquivo
												
			}
	if(opcao==5){ //Quinta Op��o do Menu.
		cabecalho(); //Procedimento para ficar chamando o cabe�alho.
				arquivo();//Abertura do Arquivo.
					remover();//Procedimento para Remover o Cliente.
					fclose(Pclientes);//Fechamento do Arquivo
			}
	if(opcao==6){ //Sexta Op��o do Menu.
		cabecalho(); //Procedimento para ficar chamando o cabe�alho.
				arquivo();//Abertura do Arquivo.
					listagemporpacote(); //Procedimento para Listar por Pacote.
					fclose(Pclientes);//Fechamento do Arquivo
			}
	if(opcao==0){ //Op��o para sair do menu.
				exit(0);
			}
		
}while (opcao!=0);//Fim da Estrutura de Repeti��o do Menu de Op��es.

getche ();
}
 
void menuop() { //Procedimento para o Menu de Op��es.
	
			printf ("Menu de Op��es\n\n Op��es:\n1. Cadastrar Cliente\n2. Listagem Geral\n3. Relat�rio Estat�stico\n4. Editar Cliente\n5. Remover Cliente\n6. Listar Clientes por Pacote\n0. Sair\n\n");
 }
 
 float CalculoMensalidade(int pacote, int pontostv); //Chamar Calculo da Mensalidade.
 
void cadastrarcliente(){ //Procedimento para Cadastrar Cliente
	printf("Informe o C�digo: \n");
		scanf("%d",&Rclientes.id);
		 
					system("cls");
					
	printf("Informe o seu Nome:\n");
		fflush(stdin);// BUFFER � A MEM�RIA TEMPOR�RIA UTILIZADA PARA ESCRITA E LEITURA DE DADOS.E A FUN��O FFLUSH(STDIN) LIMPA O BUFFER DO TECLADO
			gets(Rclientes.nome);
					system("cls");
					
do{//Estrutura de Repeti��o para realizar verifica��o se o C�digo for inv�lido.
	printf("Informe o seu Sexo:\n1 - Feminino\n2 - Masculino\n");
		scanf("%d",&Rclientes.sexo);
					system("cls");
					
if(Rclientes.sexo!=1 && Rclientes.sexo !=2){
	printf("Sexo informado est� errado!\n");
					system("cls");	
}
			
}while(Rclientes.sexo!=1 && Rclientes.sexo !=2);	

	printf("Informe a sua Idade:\n");
		scanf("%d",&Rclientes.idade);	
					system("cls");
do{
	printf("Escolha o seu Pacote\n\n1 - Premium\n2 - Ouro\n3 - Standard\n");
		scanf("%d",&Rclientes.pacote);
					system("cls");
					
if(Rclientes.pacote != 1 && Rclientes.pacote !=2 && Rclientes.pacote != 3 ){
	printf("Pacote Inv�lido!\n");
					system("cls");
}
		
}while(Rclientes.pacote != 1 && Rclientes.pacote !=2 && Rclientes.pacote != 3);
	printf("Quantidade de Pontos de TV:\n");
		scanf("%d",&Rclientes.pontostv);
					system("cls");
				
Rclientes.mensalidade = CalculoMensalidade(Rclientes.pacote,Rclientes.pontostv);//Realizar o C�lculo da Mensalidade.
	fseek(Pclientes, 0, SEEK_END);
		fwrite(&Rclientes, sizeof(clientes), 1, Pclientes);

	printf("\nDeseja cadastrar outro Cliente?\n1 - Sim\n0 - N�o\n");
		scanf("%d",&Rclientes.sair);
	
if (Rclientes.sair == 1){
		cadastrarcliente();
	
}else{
					system("cls");
	}
}

void arquivo(){ //Procedimento para criar arquivo txt.
Pclientes = fopen("Clientes.txt", "r+b");  //FOPEN ABRE UM ARQUIVO PARA LEITURA OU ESCRITA
	if (Pclientes == NULL){ // VERIFICA SE O ARQUIVO EXISTE, PARA NAO FICAR PROCURANDO O QUE NAO EXISTE 
			Pclientes = fopen("Clientes.txt", "w+b");
		}
}

void linha();//Chamar linha.

void listagemgeral(){ //Procedimento para chamar Listagem de Clientes Cadastrados.
	printf("\n\nListagem Geral\n\n\n");
    	linha();
    printf(" C�digo   Nome      Sexo       Idade      Pacote            Quantidade de Pontos       Mensalidade    \n");
    	linha();
    rewind(Pclientes); //Posicionar arquivo para buscar do in�cio.
    	fread(&Rclientes, sizeof(clientes), 1, Pclientes); //Ler o arquivo.

while (feof(Pclientes)==0){ 
if (Rclientes.id != 0)
		printf("   %d      %9s     %-10d %-10d %-20d %-5d                 %-80.2f\n",Rclientes.id, Rclientes.nome,Rclientes.sexo, Rclientes.idade,Rclientes.pacote,Rclientes.pontostv,Rclientes.mensalidade);
fread(&Rclientes, sizeof(clientes), 1, Pclientes);

}
linha();
		printf("Tecle Enter para voltar ao menu...");
getche();
	system ("cls");
}

void linha(){//Procedimento para criar linhas.
	int i;
	for (i=1; i<=100; i++){
			printf("_");
	}
}

float CalculoMensalidade(int pacote,int qtdP){ //Fun��o para Retornar o C�lculo da Mensalidade.
	float valormensalidade;
	float valorponto;
	
if (pacote == 1){
	valorponto = 32;
	
	if(qtdP>2){
		valorponto = valorponto - (valorponto*0.15);		
}
		valormensalidade = 220+(valorponto*qtdP);
		
}
if (pacote == 2){
	valorponto = 27;
		
	if(qtdP>2){			
		valorponto = valorponto - (valorponto*0.15);			
}
		valormensalidade = 170+(valorponto*qtdP);
		
}
if (pacote == 3){
	valorponto = 21;
	
	if(qtdP>2){
		valorponto = valorponto - (valorponto*0.15);			
		}
		valormensalidade = 120+(valorponto*qtdP);		
}				
	return valormensalidade;
}

void cabecalho(){ //Procedimento para chamar o Cabe�alho.
	
	printf("Empresa de TV/Telefonia/Internet\n\n");
	
}

int procura(int matp)
{ int p;//Fun��o para verificar o indicador de fim do arquivo, e retorna um valor diferente de zero se o indicador estiver setado.

	p = 0;
	rewind(Pclientes);
	fread(&Rclientes, sizeof(clientes), 1, Pclientes);
	
while (feof(Pclientes)==0){

if (Rclientes.id == matp)
	return p;
else

{ 
fread(&Rclientes, sizeof(clientes), 1,Pclientes);
p++;

}
}
	return -1;
}

void mostre(int pos){ //Procedimento para mostrar a posi��o indicada.
	fseek(Pclientes,pos*sizeof(clientes), SEEK_SET);
		fread(&Rclientes, sizeof(clientes), 1, Pclientes);
    linha();
    	printf(" C�digo   Nome      Sexo       Idade      Pacote            Quantidade de Pontos       Mensalidade    \n");
    	printf("   %d  %9s     %-10d %-10d %-20d %-5d                   %-80.2f\n",Rclientes.id, Rclientes.nome,Rclientes.sexo, Rclientes.idade,Rclientes.pacote,Rclientes.pontostv,Rclientes.mensalidade);
    linha();  
}

void remover(){ //Procedimento para Remover o Cliente
int id, conf, resp, posicao;
Xclientes.id = 0;
		
do{ cabecalho();
	printf("\n\nRemover o Cliente\n");
	printf("Digite o C�digo do Cliente: ");
		scanf("%d", &id);
			posicao = procura(id);//Ir� procurar o Cliente e indicar se a Posi��o for -1 (Inexistente).
			
if (posicao == -1)
	printf("\n Cliente n�o encontrado!!\n");

else { 
	mostre(posicao); //Mostrar a Posi��o.
	printf("\n\nDeseja Remover o Cliente (1 - Sim | 2 - N�o)? ");
		scanf("%d", &conf);
		
if (conf == 1){ 
	fseek(Pclientes,posicao*sizeof(clientes),SEEK_SET);//posicao*sizeof, ir� indicar a posi��o exata a ser removida, pois foi declarada acima;
		fwrite (&Xclientes, sizeof(clientes), 1, Pclientes);
	printf("\nCliente Removido com Sucesso!");
}
else
	printf("\nRemo��o Cancelada!");
}
	printf("\n\n\nDeseja Remover outro Cliente (1 - Sim | 2 - N�o)? ");
		scanf("%d", &resp);
		
	}while (resp ==1);
}

void editar(){ //Procedimento para Editar o Cliente.
int id,verificar, resp, conf,posicao;

do { 
	
		
		
				
	//printf("\n\nAlterar de Cliente\n\n\n");
	
	
	printf("Digite o Codigo:\n");
		scanf("%d",&id);
			posicao = procura(id);
			
if (posicao == -1){

printf("\nCliente, n�o encontrado!!\n");

}else{ 

mostre(posicao);
	
		printf("Digite op��o desejada para altera��o:\n 1 - Nome \n 2 - Sexo \n 3 - Idade \n 4 - Pacote \n 5 - Ponto\n");
		scanf("%d", &conf);

if(conf == 1){
	
	printf("Digite o Nome Correto:\n");
	fflush(stdin);
	gets(Rclientes.nome);
	
} 
if(conf ==2){
	do{//Estrutura de Repeti��o para realizar verifica��o se o C�digo for inv�lido.
	printf("Informe o seu Sexo:\n1 - Feminino\n2 - Masculino\n");
		scanf("%d",&Rclientes.sexo);
				
					
if(Rclientes.sexo!=1 && Rclientes.sexo !=2){
	printf("Sexo informado est� errado!\n");
					
}
			
}while(Rclientes.sexo!=1 && Rclientes.sexo !=2);	
		
}
if(conf == 3){
	 printf("Digite a Idade Correta:\n");
	 scanf("%d",&Rclientes.idade);
	
}

if (conf == 4){ 

do{
	printf("Escolha seu Novo Pacote\n\n1 - Premium\n2 - Ouro\n3 - Standard\n");
		scanf("%d",&Rclientes.pacote);
				
					
	if(Rclientes.pacote != 1 && Rclientes.pacote !=2 && Rclientes.pacote != 3 ){
					printf("Pacote Inv�lido!\n");		
		}
	}while(Rclientes.pacote != 1 && Rclientes.pacote !=2 && Rclientes.pacote != 3);   
	
	
}
	if (conf == 5)	{		
	
	printf("Nova quantidade de ponto:\n");
		scanf("%d",&Rclientes.pontostv);
	}

	

Rclientes.mensalidade = CalculoMensalidade(Rclientes.pacote,Rclientes.pontostv);
printf("Deseja salvar as Altera��es?\n 1 - Sim  2 - N�o\n");
scanf("%d",&conf);
system ("cls"); 
if(conf == 1){

		fseek(Pclientes,posicao*sizeof(clientes),SEEK_SET);
			fwrite(&Rclientes,sizeof(clientes), 1,Pclientes);
			cabecalho();
				mostre(posicao);					
	printf("\nAltera��es Realizadas com sucesso!\n");
}
else{

	printf("\n\nAltera��o Cancelada!\n\n");
}
 	printf("\n\nDeseja Alterar Outro ( 1 - Sim | 0 - N�o)?\n");
		scanf("%d", &resp);
		system ("cls"); 
		


}
}while (resp == 1);
}

void listagemporpacote(){ //Procedimento para Listagem Por Pacote.
	printf("\n\nListagem Por Pacote\n\n\n");
	printf("\nPacote Premium:\n\n");
    	linha();
    printf(" C�digo   Nome      Sexo       Idade      Pacote            Quantidade de Pontos       Mensalidade    \n");
    	linha();
    		rewind(Pclientes);//Buscar pelo ponteiro.
    			fread(&Rclientes, sizeof(clientes), 1, Pclientes);

while (feof(Pclientes)==0){
if (Rclientes.pacote == 1)
		printf("   %d      %9s     %-10d %-10d %-20d %-5d                 %-80.2f\n",Rclientes.id, Rclientes.nome,Rclientes.sexo, Rclientes.idade,Rclientes.pacote,Rclientes.pontostv,Rclientes.mensalidade);
			fread(&Rclientes, sizeof(clientes), 1, Pclientes);
}

linha();
	printf("\nPacote Ouro:\n\n");
   		 linha();
    printf(" C�digo   Nome      Sexo       Idade      Pacote            Quantidade de Pontos       Mensalidade    \n");
    	linha();
    		rewind(Pclientes);
    			fread(&Rclientes, sizeof(clientes), 1, Pclientes);

while (feof(Pclientes)==0){
if (Rclientes.pacote == 2)
		printf("   %d      %9s     %-10d %-10d %-20d %-5d                 %-80.2f\n",Rclientes.id, Rclientes.nome,Rclientes.sexo, Rclientes.idade,Rclientes.pacote,Rclientes.pontostv,Rclientes.mensalidade);
			fread(&Rclientes, sizeof(clientes), 1, Pclientes);
}

linha();
	printf("\nPacote Standard:\n\n");
   		linha();
    printf(" C�digo   Nome      Sexo       Idade      Pacote            Quantidade de Pontos       Mensalidade    \n");
    	linha();
    		rewind(Pclientes);
    			fread(&Rclientes, sizeof(clientes), 1, Pclientes);

while (feof(Pclientes)==0){
if (Rclientes.pacote == 3)
		printf("   %d      %9s     %-10d %-10d %-20d %-5d                 %-80.2f\n",Rclientes.id, Rclientes.nome,Rclientes.sexo, Rclientes.idade,Rclientes.pacote,Rclientes.pontostv,Rclientes.mensalidade);
			fread(&Rclientes, sizeof(clientes), 1, Pclientes);
}
linha();
		printf("Tecle Enter para voltar ao menu...");
getche();
}

int qtdmulher(){ //Fun��o para Relat�rio Estat�stico 1.
int contadormulher = 0;

    rewind(Pclientes);
    	fread(&Rclientes, sizeof(clientes), 1, Pclientes);

while (feof(Pclientes)==0){ 

if (Rclientes.sexo == 1)
	contadormulher++;
		fread(&Rclientes, sizeof(clientes), 1, Pclientes);
}
 return contadormulher;	
}

int qdtclientemaiorque3pontos(){ //Fun��o para Relat�rio Estat�stico 2.
int contadorclientemaiorq3 = 0;
    rewind(Pclientes);
    	fread(&Rclientes, sizeof(clientes), 1, Pclientes);

while (feof(Pclientes)==0){ 
	
if (Rclientes.pontostv > 3 )
	contadorclientemaiorq3++;
		fread(&Rclientes, sizeof(clientes), 1, Pclientes);

}
 return contadorclientemaiorq3;	
}

float somadordepontosdetv(){ //Fun��o para Relat�rio Estat�stico 3.
float somadordepontos = 0;
	float contadorponto = 0;
		float mediapontostv = 0;
   			rewind(Pclientes);
    			fread(&Rclientes, sizeof(clientes), 1, Pclientes);

while (feof(Pclientes)==0){ 

somadordepontos = somadordepontos+Rclientes.pontostv;	
	fread(&Rclientes, sizeof(clientes), 1, Pclientes);
		contadorponto++;

}
mediapontostv = somadordepontos/contadorponto;
  	return mediapontostv;	
}

float mediacliente60(){ //Fun��o para Relat�rio Estat�stico 4.
float somadorcliente = 0;
	float contadorcliente = 0;
		float mediamensalidade = 0;
    		rewind(Pclientes);
    	    //fread(&Rclientes, sizeof(clientes), 1, Pclientes);

while (feof(Pclientes)==0){ 
 
 
if(Rclientes.idade > 60){  
	somadorcliente = somadorcliente+Rclientes.mensalidade;
	
	fread(&Rclientes, sizeof(clientes), 1, Pclientes);
	contadorcliente++;
	
	}
	if (contadorcliente>0){
		
		mediamensalidade = somadorcliente/contadorcliente;
		
  	return mediamensalidade;
	}else {
	
	return 0;
}	
	
}

}

float somaempresa(){ //Fun��o para Relat�rio Estat�stico 5.
float somadorempresa = 0;
	rewind(Pclientes);
    	fread(&Rclientes, sizeof(clientes), 1, Pclientes);

while (feof(Pclientes)==0){ 
	somadorempresa = somadorempresa+Rclientes.mensalidade;
		fread(&Rclientes, sizeof(clientes), 1, Pclientes);
}
  	return somadorempresa;	
}

void relatorioestatistico(){ //Procedimento preenchido com as Fun��es para Compor o Relat�rio Estat�stico e mostrar.
int contador = 0;

while (feof(Pclientes)==0){ 
if (Rclientes.sexo == 1 && Rclientes.pacote == 2)
		contador++;
			fread(&Rclientes, sizeof(clientes), 1, Pclientes);
}
 
int qtdmulher(); //Chamando a fun��o 1 e a calculando abaixo.
float qtdm;
	qtdm = qtdmulher();
float per;
 


if (qtdm != 0 && contador != 0 ){
	per = (contador/qtdm)*100;
}else{
	per = 0;
}



printf ("Relat�rio Estat�stico:\n\n");
printf("*	Percentual de Mulheres com Pacote Ouro: %.2f%%\n\n",per);
printf("*	Quantidade de Clientes com mais de 3 Pontos de TV: %d\n\n",qdtclientemaiorque3pontos());
printf("*	M�dia de Pontos de TV: %.3f\n\n",somadordepontosdetv());
printf("*	M�dia da Mensalidade dos Clientes com mais de 60 Anos:R$ %.3f\n\n",mediacliente60());
printf("*	Valor Arrecadado pela Empresa: R$ %.2f\n\n",somaempresa());
	printf("Tecle Enter para voltar ao menu...");
	
getche();
	system("cls");
	
}


	


	
	
	

