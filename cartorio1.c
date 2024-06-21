#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca de responsável por cuidar das string

int registro() // função responsável por cadastrar usuários do sistema

{
	// inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: "); // coletando informação do usuário	
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo do banco de dados
	file = fopen(arquivo, "w"); // escreve arquivo de banco de dados "w"
	fprintf(file,cpf); // salva valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file,","); // salva valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");	
	scanf("%s", nome);
				
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file, nome); // salva valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file,",");  // salva valor da variável
	fclose(file); // fecha o arquivo
		
	printf("Digite o sobrenome a ser cadastrado: ");	
	scanf("%s", sobrenome);
		
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file, sobrenome);  // salva valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file,","); // salva valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");	
	scanf("%s", cargo);
		
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file, cargo); // salva valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo banco de dados
	fprintf(file,","); // salva valor da variável
	fclose(file); // fecha o arquivo
	
	system("pause");
	
	
}


int consulta()
{
	//setlocale(LCC_ALL, "portuguese"); // Definindo a linguagem
	char cpf[40];
	char conteudo[200];

	printf("Digite CPF a ser consultado: "); // opção mostrada na tela
	scanf("%s",cpf);

	FILE *file;
	file=fopen(cpf,"r");
	
	
	if(file == NULL)
	
	{
		printf("Não foi possível abrir o arquivo, não localizado.\n"); // para opção invalida
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	printf("\Essas sao as infomacoes dos usuarios: ");
	printf("%s", conteudo);
	printf("\n\n");

	system("pause");
}



int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");	
	scanf("%s",cpf);
	
	remove("cpf");
	
	FILE *file;  // Abre arquivo ref ao cpf e aplica comando "r" para ler
	file = fopen(cpf,"r"); // salva valor da variável
	fclose(file);
	
	if(file == NULL)  // Caso numero digitado não seja encontrado no banco de dados
	{ 
		
		printf("O usuario nao se encontra no sistema!.\n");   // mensagem exibida ao usuário
		system("pause");
	}
	
	else
	
	{ 
		if(remove(cpf) == 0) //
		printf("Usuário deletado com sucesso \n\n");	
		system("pause");  // comando que pausa na tela atual	
	}
		
		
}


int main()


	{
	int opcao=0; // Defenindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); 			
  		//setlocale(LCC_ALL, "portuguese"); // Definindo a linguagem
  
  
  		printf("###Cartorio da EBAC###\n\n"); // Inicio do menu 
  		printf("Escolha a opcao desejada do menu:\n\n");
  		printf("\t1 - Registrar nomes\n");
  		printf("\t2 - Consultar nomes\n");
  		printf("\t3 - Deletar nomes\n\n"); 
  		printf("\t4 - Sair do sistema\n\n");
		  printf("Opcao:"); // Fim do menu
  
  		scanf("%d",&opcao); // Armazenando a escolha do usuário
  
  		system("cls"); // reponsável por limpar a tela
  		
  		switch(opcao)
  			{
			case 1:
  			registro(); // chamada de funções
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
	

    
