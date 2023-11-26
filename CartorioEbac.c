#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de alica��o de espa�o em mem�ria
#include <locale.h> //biblioteca de alica��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastras os usu�rios no sistema
{
	 //Inicio da cria��o de v�riaveis/string
	char arquivo[40]; //char = � uma vari�vel de caracteres 
	char cpf[40]; //o n�mero 40 � a quantidade de caracteres
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de v�riaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando a informa��o 
	scanf("%s", cpf); //%s faz referencia a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo / "w" vem de write = escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" = atualizar, logo vai abrir o arquilo para adicionar mais informa��es
	fprintf(file,","); // ser� adicionado uma v�rgula ap�s o cpf
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," "); //adiciona um espa�o ap�s o nome
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // b�sicamente da um pause na tela, trava na tela ap�s o comando
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //defini��o do idioma
	
	char cpf[40];
	char conteudo[200]; //conteudo total dentro do arquivo cpf
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // fazer a leitura do arquivo pela busca do cpu digitado pelo usu�rio
	
	if(file == NULL) //caso o cpf digitado n�o existir vai informar o usu�rio com a mensagem abaixo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}

	while(fgets(conteudo, 200, file) != NULL) // salvando os caracteres da busca na vari�vel conteudo e vai parar quando forem diferente do conteudo salvo
	{
		printf("\n Essas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio foi deletado com sucesso e(ou) n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main () // int main � a fun��o principal, � o o n�cleo do projeto
			// () � um conjunto de instru��es
			// {} tudo que estiver nas chaves est� dentro da int main
{
	int opcao=0; //definindo vari�veis e igualando a 0 o valor, local a ser armazenado na mem�ria do computador
	int x=1;
	
	for(x=1;x=1;) //la�o de repeti��o para sempre voltar a vari�vel 1 no caso o menu inicial
	{ //come�o do la�o de repeti��o do menu

		system("cls");
			
     	setlocale(LC_ALL, "Portuguese"); //defini��o do idioma 
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n"); // \n pula uma linha
		//opc�es do menu
		printf("\t1 - Registrar nomes\n");
		//printf tras a informa��o para a tela(para o usu�rio)
		//tudo que esta entre aspas "" � texto
		printf("\t2 - Consultar nomes\n"); // ponto e v�rgula( ; ) � necess�rio para reconecer um comando
		printf("\t3 - Deletar nomes\n"); // \t da um espa�o antes do texto
		printf("\nOp��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); // limpa a tela, deleta as informa��es anteriores
		
		switch(opcao) //in�cio da sele��o
		{
			case 1: //abertura da chave abaixo
			registro();
			break; //fecha a chave
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			
			default:
			printf("Essa op��o n�o est� dispon�vel \n");
			system("pause");
			break;
			
		}//fim da sele��o
	
    } //final do la�o de repeti��o do menu
}
