#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo de dados
	file = fopen(arquivo, "w");
	fprintf(file,cpf); // Salvo o valor da vari�vel
	fclose(file); // Fecha o arquivo

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s",sobrenome);	
		
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite a cargo a ser cadastrado:");
	scanf("%s", cargo);	
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);	
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	char cpf [40];
	char conteudo [100];
	
	printf ("Digite o cpf a ser consultado:");
	scanf("%s", cpf);
		
	FILE *file; 
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
	printf("Arquivo n�o localizado!\n");
}	

	while(fgets(conteudo, 100, file) !=NULL)

	{
		printf("\nEssas s�s as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar ()
{
		char cpf[40];
		printf("Digitar o CPF a ser deletado:");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file ==NULL)
		{
			printf("O usu�rio n�o se encontra no sistema!\n");			system("pause");
			
		}
		
}

int main()

	{	
	int opcao=0; //Definindo as vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
		printf("###Cart�rio C�digo###\n\n"); //In�cio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar os nomes\n");
		printf ("\t2 - Consultar os nomes\n");
		printf ("\t3 - Deletar os nomes\n\n\n");
		printf ("\t4 - Sair do sistema!\n\n");
		printf("Op�ao");// Fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao)
	{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema!\n");
			return 0;
			break;
			
						
			default:
			printf("Opc�o inv�lida\n");
			system("pause");
			break;
		}
		
	
		
	}//Fim da sele��o
	
}

