#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alicação de espaço em memória
#include <locale.h> //biblioteca de alicação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastras os usuários no sistema
{
	 //Inicio da criação de váriaveis/string
	char arquivo[40]; //char = é uma variável de caracteres 
	char cpf[40]; //o número 40 é a quantidade de caracteres
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de váriaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando a informação 
	scanf("%s", cpf); //%s faz referencia a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo / "w" vem de write = escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" = atualizar, logo vai abrir o arquilo para adicionar mais informações
	fprintf(file,","); // será adicionado uma vírgula após o cpf
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," "); //adiciona um espaço após o nome
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
	
	system("pause"); // básicamente da um pause na tela, trava na tela após o comando
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definição do idioma
	
	char cpf[40];
	char conteudo[200]; //conteudo total dentro do arquivo cpf
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // fazer a leitura do arquivo pela busca do cpu digitado pelo usuário
	
	if(file == NULL) //caso o cpf digitado não existir vai informar o usuário com a mensagem abaixo
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}

	while(fgets(conteudo, 200, file) != NULL) // salvando os caracteres da busca na variável conteudo e vai parar quando forem diferente do conteudo salvo
	{
		printf("\n Essas são as informações do usuário: \n\n");
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
		printf("O usuário foi deletado com sucesso e(ou) não se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main () // int main é a função principal, é o o núcleo do projeto
			// () é um conjunto de instruções
			// {} tudo que estiver nas chaves está dentro da int main
{
	int opcao=0; //definindo variáveis e igualando a 0 o valor, local a ser armazenado na memória do computador
	int x=1;
	
	for(x=1;x=1;) //laço de repetição para sempre voltar a variável 1 no caso o menu inicial
	{ //começo do laço de repetição do menu

		system("cls");
			
     	setlocale(LC_ALL, "Portuguese"); //definição do idioma 
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu: \n\n"); // \n pula uma linha
		//opcões do menu
		printf("\t1 - Registrar nomes\n");
		//printf tras a informação para a tela(para o usuário)
		//tudo que esta entre aspas "" é texto
		printf("\t2 - Consultar nomes\n"); // ponto e vírgula( ; ) é necessário para reconecer um comando
		printf("\t3 - Deletar nomes\n"); // \t da um espaço antes do texto
		printf("\nOpção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); // limpa a tela, deleta as informações anteriores
		
		switch(opcao) //início da seleção
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
			printf("Essa opção não está disponível \n");
			system("pause");
			break;
			
		}//fim da seleção
	
    } //final do laço de repetição do menu
}
