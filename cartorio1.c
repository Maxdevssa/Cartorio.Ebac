#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca de respons�vel por cuidar das string

int registro() // fun��o respons�vel por cadastrar usu�rios do sistema

	{
	// inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�vel
	
	
	printf("Digite o cpf a ser cadastrado: "); // coletando informa��o do usu�rio	
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string "cpf" para o arquivo
	
	//cria��o de arquivo atribuindo valor do cpf para ele
	FILE *file; // cria o arquivo do banco de dados
	file = fopen(arquivo, "w"); // escreve arquivo de banco de dados "w"
	fprintf(file,cpf); // salva valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file,","); // salva valor da vari�vel
	fclose(file); // fecha o arquivo
	
	//abrindo o arquivo no modo de inclus�o e inserindo valor da variavel e nome
	printf("Digite o nome a ser cadastrado: ");	
	scanf("%s", nome);
				
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file, nome); // salva valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file,",");  // salva valor da vari�vel
	fclose(file); // fecha o arquivo
	
	
	//abrindo o arquivo no modo de inclus�o e inserindo valor da variavel e sobrenome	
	printf("Digite o sobrenome a ser cadastrado: ");	
	scanf("%s", sobrenome);
		
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file, sobrenome);  // salva valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file,","); // salva valor da vari�vel
	fclose(file); // fecha o arquivo
	
	
	//abrindo o arquivo no modo de inclus�o e inserindo valor da variavel e cargo
	printf("Digite o cargo a ser cadastrado: ");	
	scanf("%s", cargo);
		
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file, cargo); // salva valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file,","); // salva valor da vari�vel
	fclose(file); // fecha o arquivo
	
	system("pause");
	
	
	}


int consulta() //Fun��o respons�vel por consultar usu�rios no sistema 
	{
	//setlocale(LCC_ALL, "portuguese"); // Definindo a linguagem
	char cpf[40];
	char conteudo[200];

	printf("Digite CPF a ser consultado: "); // op��o mostrada na tela
	scanf("%s",cpf);
	
	// Acessando arquivo para leitura
	FILE *file;
	file=fopen(cpf,"r");
	
	// Procura no "file" o "cpf" se n�o encontra dispara mensagem de alerta
	if(file == NULL)
	
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n"); // para op��o invalida
 	
	while(fgets(conteudo, 200, file) != NULL)
	
	printf("\Essas sao as infomacoes dos usuarios: ");
	printf("%s", conteudo);
	printf("\n\n");

	system("pause");
	}



int deletar() //Fun��o respons�vel por deletar usu�rio no sistema
	{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");	
	scanf("%s",cpf);
	
	
	FILE *file;  // Abre arquivo ref ao cpf e aplica comando "r" para ler
	file = fopen(cpf,"r"); // salva valor da vari�vel
	fclose(file);

	{
	if(remove(cpf) == 0); 
	printf("Usu�rio deletado com sucesso \n\n");	
	system("pause");  // comando que pausa na tela atual
	}			
	
	if(file == NULL)  // Caso numero digitado n�o seja encontrado no banco de dados
	remove("cpf");
	printf("O usuario nao se encontra no sistema!.\n");   // mensagem exibida ao usu�rio
	system("pause");
 
 	
}
			
	
int main()


{
	int opcao=0; // Defenindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	
	printf("### Cartorio da EBAC ###\n\n");
	printf("Login de administrador! \n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	if (strcmp(senhadigitada, "admin") == 0)
	{
			
		
		for(laco=1;laco=1;)
		{
			
			system("cls"); 			
			//setlocale(LCC_ALL, "portuguese"); // Definindo a linguagem
  
  
			printf("### Cartorio da EBAC ###\n\n"); // Inicio do menu 
			printf("Escolha a opcao desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Opcao:"); // Fim do menu
  
			scanf("%d",&opcao); // Armazenando a escolha do usu�rio
  
			system("cls"); // repons�vel por limpar a tela
  		
			switch(opcao)
			{
				case 1:
				registro(); // chamada de fun��es
				break;	
  			
				case 2:
				consulta();	
				break;  
	  
				case 3:
				deletar();	
				break;  		
  			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;  	
				break;  	
						    			  			
				default:
				printf("Essa opcao nao esta disponivel\n");
				system("pause");  	
				break;
			}
		}		
	}	
	
	else{printf("Senha incorreta!");}
	

}	

    
