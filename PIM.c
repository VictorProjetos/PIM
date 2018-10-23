#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <locale.h>
#include <stdlib.h>

int main () {
	setlocale(LC_ALL, "Portuguese");
	int opcao, i;
	printf("Bem Vindo ! \n O que deseja fazer ? \n 1 - Se cadastrar \n 2 - Reservar um lugar \n");
	scanf("%d",&opcao);
	
	// Cadastro
	if (opcao == 1){
		int tipoPessoa;
		printf("Você é: \n 1 - Professor \n 2 - Aluno \n 3 - Convidado \n 4 - Portador de necessidade especial \n 5 - sair \n");
		scanf("%i", &tipoPessoa);
		switch(tipoPessoa){
			case 1: {
				MYSQL conexao;
				int res;
				char query[100];
				char nomeProfessor[31], rgProfessor[12], emailProfessor[65], carteirinhaProfessor[16], telefoneProfessor[21];
				
				printf("Informe seu nome completo: ");
				scanf(" %[^\n]s", &nomeProfessor);
				fflush(stdin);
				
				printf("Informe seu RG: ");
				scanf(" %s", &rgProfessor);
				fflush(stdin);
				
				printf("Informe seu telefone com DDD: ");
				scanf(" %s", &telefoneProfessor);
				fflush(stdin);
				
				printf("Informe seu E-mail: ");
				scanf(" %s", &emailProfessor);
				fflush(stdin);
				
				printf("Carteirinha oficial de registro de professor: ");
				scanf(" %s", &carteirinhaProfessor);
				fflush(stdin);
		
			//Inserir dados no banco//		
			mysql_init(&conexao);
			if ( mysql_real_connect(&conexao, "localhost", "root", "", "teatro", 0, NULL, 0) )
			{
			printf("conectado com sucesso!\n");
	
			sprintf(query,"call cadas_prof ('%s','%s','%s','%s','%s');", nomeProfessor, rgProfessor, emailProfessor, carteirinhaProfessor, telefoneProfessor);
	
			res = mysql_query(&conexao,query);
			if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
			else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	
	
			mysql_close(&conexao);
			}
			else
			{
			printf("Falha de conexao\n");
			printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
			}
			
			system("pause");
			return(0);
				
				
				
				
				
				break;
			}
			case 2: {
				char nomeAluno[31], rgAluno[12], emailAluno[65], ra[16], telefoneAluno[21];
				printf("Informe seu nome completo: ");
				scanf("%30s", &nomeAluno);
				printf("Informe seu RG: ");
				scanf("%9s", &rgAluno);
				printf("Informe seu telefone com DDD: ");
				scanf("%20s", &telefoneAluno);
				printf("Informe seu E-mail: ");
				scanf("%64s", &emailAluno);
				printf("Informe seu RA: ");
				scanf("%15s", &ra);
				break;
			}
			case 3:{
				char nomeConvidado[31], rgConvidado[12], emailConvidado[65], numeroConvite[16], telefoneConvidado[21];
				printf("Informe seu nome completo: ");
				scanf("%30s", &nomeConvidado);
				printf("Informe seu RG: ");
				scanf("%9s", &rgConvidado);
				printf("Informe seu telefone com DDD: ");
				scanf("%20s", &telefoneConvidado);
				printf("Informe seu E-mail: ");
				scanf("%64s", &emailConvidado);
				printf("Informe o número do convite: ");
				scanf("%15s", &numeroConvite);
				break;
			}
			case 4:{
				char nomePessoa[31], rgPessoa[12], emailPessoa[65], numeroPd[16], telefonePessoa[21];
				printf("Informe seu nome completo: ");
				scanf("%30s", &nomePessoa);
				printf("Informe seu RG: ");
				scanf("%9s", &rgPessoa);
				printf("Informe seu telefone com DDD: ");
				scanf("%20s", &telefonePessoa);
				printf("Informe seu E-mail: ");
				scanf("%64s", &emailPessoa);
				printf("Número da carteirinha PD: ");
				scanf("%15s", &numeroPd);
				break;
			}
					
		}		
	}
}
