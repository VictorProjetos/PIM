#include<stdio.h>
#include<stdlib.h>
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
		printf("Você é: \n 1 - Professor \n 2 - Aluno \n 3 - Convidado \n 4 - Portador de necessidade especial \n");
		scanf("%d", &tipoPessoa);
		switch(tipoPessoa){
			case 1: {
				char nomeProfessor[31], rgProfessor[12], emailProfessor[65], carteirinhaProfessor[16], telefoneProfessor[21];
				printf("Informe seu nome completo: ");
				scanf("%30s", &nomeProfessor);
				printf("Informe seu RG: ");
				scanf("%9s", &rgProfessor);
				printf("Informe seu telefone com DDD: ");
				scanf("%20s", &telefoneProfessor);
				printf("Informe seu E-mail: ");
				scanf("%64s", &emailProfessor);
				printf("Carteirinha oficial de registro de professor: ");
				scanf("%15s", &carteirinhaProfessor);
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
