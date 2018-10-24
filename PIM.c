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
	system("cls");

	// Cadastro
	if (opcao == 1){
		int tipoPessoa, esco = 2;
		printf("Você é: \n 1 - Professor \n 2 - Aluno \n 3 - Convidado \n 4 - Portador de necessidade especial \n 5 - sair \n");
		scanf("%i", &tipoPessoa);
		system("cls");
		switch(tipoPessoa){
			case 1: {
				MYSQL conexao;
				int res;
				char query[100];
				char nomeProfessor[31], rgProfessor[12], emailProfessor[65], carteirinhaProfessor[16], telefoneProfessor[21];

                do{
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
				system("cls");

				printf("\n Nome: %s", &nomeProfessor);
                printf("\n RG: %s", &rgProfessor);
                printf("\n Telefone:%s", &telefoneProfessor);
                printf("\n Email: %s", &emailProfessor);
                printf("\n Ra: %s \n \n", &carteirinhaProfessor);

                printf(" \n As Informações acima estão corretas? \n \n 1 - sim\n 2 - não \n");
                scanf("%i",&esco);
                system("cls");

				} while (esco == 2);

			//Inserir dados no banco//
			mysql_init(&conexao);
			if ( mysql_real_connect(&conexao, "localhost", "root", "", "teatro", 0, NULL, 0) )
			{

			sprintf(query,"call cadas_prof ('%s','%s','%s','%s','%s');", nomeProfessor, rgProfessor, emailProfessor, carteirinhaProfessor, telefoneProfessor);

			res = mysql_query(&conexao,query);
			if (!res) printf("Cadastrado com sucesso!! \n");
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
			    MYSQL conexao;
				int res;
				int esco = 2;
				char query[100];
				char nomeAluno[31], rgAluno[12], emailAluno[65], ra[16], telefoneAluno[21];
				do{
				printf("Informe seu nome completo: ");
				scanf(" %[^\n]s", &nomeAluno);
				fflush(stdin);

				printf("Informe seu RG: ");
				scanf(" %s", &rgAluno);
				fflush(stdin);

				printf("Informe seu telefone com DDD: ");
				scanf(" %s", &telefoneAluno);
				fflush(stdin);

				printf("Informe seu E-mail: ");
				scanf(" %s", &emailAluno);
				fflush(stdin);

				printf("Informe seu RA: ");
				scanf(" %s", &ra);
                fflush(stdin);
                system("cls");

                printf("\n Nome: %s", &nomeAluno);
                printf("\n RG: %s", &rgAluno);
                printf("\n Telefone:%s", &telefoneAluno);
                printf("\n Email: %s", &emailAluno);
                printf("\n Ra: %s \n \n", &ra);

                printf(" \n As Informações acima estão corretas? \n \n 1 - sim\n 2 - não \n ");
                scanf("%i",&esco);
                system("cls");
                }
                while(esco == 2);

                //conexao com o banco //
				mysql_init(&conexao);
			if ( mysql_real_connect(&conexao, "localhost", "root", "", "teatro", 0, NULL, 0) )
			{

			sprintf(query,"call cadas_aluno ('%s','%s','%s','%s','%s');", nomeAluno, rgAluno, emailAluno, ra, telefoneAluno);

			res = mysql_query(&conexao,query);
			if (!res) printf("Cadastrado com Sucesso!! \n");
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
			case 3:{
                MYSQL conexao;
				int res, esco = 2;
				char query[100];
				char nomeConvidado[31], rgConvidado[12], emailConvidado[65], numeroConvite[16], telefoneConvidado[21];

                do{
				printf("Informe seu nome completo: ");
				scanf(" %[^\n]s", &nomeConvidado);
				fflush(stdin);

				printf("Informe seu RG: ");
				scanf(" %s", &rgConvidado);
				fflush(stdin);

				printf("Informe seu telefone com DDD: ");
				scanf(" %s", &telefoneConvidado);
				fflush(stdin);

				printf("Informe seu E-mail: ");
				scanf(" %s", &emailConvidado);
				fflush(stdin);

				printf("Informe o número do convite: ");
				scanf(" %s", &numeroConvite);
                fflush(stdin);
                system("cls");

                printf("\n Nome: %s", &nomeConvidado);
                printf("\n RG: %s", &rgConvidado);
                printf("\n Telefone:%s", &telefoneConvidado);
                printf("\n Email: %s", &emailConvidado);
                printf("\n Convite: %s \n \n", &numeroConvite);

                printf(" \n As Informações acima estão corretas? \n \n 1 - sim\n 2 - não \n ");
                scanf("%i",&esco);
                system("cls");

                }while(esco == 2);
				    //conexao com o banco //

            mysql_init(&conexao);
			if ( mysql_real_connect(&conexao, "localhost", "root", "", "teatro", 0, NULL, 0) )
			{

			sprintf(query,"call cadas_convidado ('%s','%s','%s','%s','%s');", nomeConvidado, rgConvidado, emailConvidado, numeroConvite, telefoneConvidado);

			res = mysql_query(&conexao,query);
			if (!res) printf("Cadastrado com Sucesso!! \n");
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
				break;
			}
			case 4:{
			    MYSQL conexao;
				int res, esco = 2;
				char query[100];
				char nomePessoa[31], rgPessoa[12], emailPessoa[65], numeroPd[16], telefonePessoa[21];

                do{
				printf("Informe seu nome completo: ");
				scanf(" %[^\n]s", &nomePessoa);
				fflush(stdin);

				printf("Informe seu RG: ");
				scanf(" %s", &rgPessoa);
				fflush(stdin);

				printf("Informe seu telefone com DDD: ");
				scanf(" %s", &telefonePessoa);
				fflush(stdin);

				printf("Informe seu E-mail: ");
				scanf(" %s", &emailPessoa);
				fflush(stdin);

				printf("Número da carteirinha PD: ");
				scanf(" %s", &numeroPd);
                fflush(stdin);

                system("cls");

                printf("\n Nome: %s", &nomePessoa);
                printf("\n RG: %s", &rgPessoa);
                printf("\n Telefone:%s", &telefonePessoa);
                printf("\n Email: %s", &emailPessoa);
                printf("\n Numero da carteirinha: %s \n \n", &numeroPd);
                printf(" \n As Informações acima estão corretas? \n \n 1 - sim\n 2 - não \n");
                scanf("%i",&esco);
                system("cls");
                }while(esco == 2);
			// -------- Conexão -------- //
            mysql_init(&conexao);
			if ( mysql_real_connect(&conexao, "localhost", "root", "", "teatro", 0, NULL, 0) )
			{

			sprintf(query,"call cadas_pne ('%s','%s','%s','%s','%s');", nomePessoa, rgPessoa, telefonePessoa, emailPessoa, numeroPd);

			res = mysql_query(&conexao,query);
			if (!res) printf("Cadastrado com Sucesso!! \n");
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

		}
	}
}
