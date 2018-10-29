#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <locale.h>
#include <stdlib.h>
#include<conio.h>
#define COL 10
#define ROW 10
#define FALSE 0
#define TRUE 1

void inicializa(char matriz[ROW][COL]);
void mostrarPainelProf(char matriz[2][10]);
void mostrarPainelAluno(char matriz[8][10]);
void reservar(char matriz[ROW][COL]);
void legenda();
void reservarProfessores();
void reservaAluno();
int menuOpcao();
int colunaY();
int linhaX();

//estrutura dos dados
struct dados {
          char nome[30];
          char bairro[30];
          int regnum;
};
struct dados cod[50];
    int n=0;
int main (void){
    char matriz[ROW][COL];
    int opcao;
    int loopContinue=TRUE;

    inicializa(matriz); //Iniciliza a matriz com valores .(Livre)
    do{
        system("cls");//Limpa a tela
        opcao=menuOpcao();
        int tipoPessoa;
        switch(opcao){
            case 1: {
                int tipoPessoa, esco = 2;
                printf("Voc� �: \n 1 - Professor \n 2 - Aluno \n 3 - Convidado \n 4 - Portador de necessidade especial \n 5 - sair \n");
                scanf("%i", &tipoPessoa);
                system("cls");
                switch(tipoPessoa){
                    case 1: {
                        MYSQL conexao;
                        int res;
                        char query[100];
                        char nomeProfessor[31], rgProfessor[12], emailProfessor[65], carteirinhaProfessor[16], telefoneProfessor[21];

                        do {
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

                            printf(" \n As Informa��es acima est�o corretas? \n \n 1 - sim\n 2 - n�o \n");
                            scanf("%i",&esco);
                            system("cls");

                        }while (esco == 2);

                        //Inserir dados no banco//
                        mysql_init(&conexao);

                        if ( mysql_real_connect(&conexao, "localhost", "root", "", "teatro", 0, NULL, 0) ) {
                            sprintf(query,"call cadas_prof ('%s','%s','%s','%s','%s');", nomeProfessor, rgProfessor, emailProfessor, carteirinhaProfessor, telefoneProfessor);
                            res = mysql_query(&conexao,query);
                            if (!res)
                                printf("Cadastrado com sucesso!! \n");
                            else
                                printf("Erro na inser��o %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                            mysql_close(&conexao);
                        }else{
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
                        do {
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

                            printf(" \n As Informa��es acima est�o corretas? \n \n 1 - sim\n 2 - n�o \n ");
                            scanf("%i",&esco);
                            system("cls");
                        } while(esco == 2);
                        //conexao com o banco //
                        mysql_init(&conexao);
                        if ( mysql_real_connect(&conexao, "localhost", "root", "", "teatro", 0, NULL, 0) ){
                            sprintf(query,"call cadas_aluno ('%s','%s','%s','%s','%s');", nomeAluno, rgAluno, emailAluno, ra, telefoneAluno);
                            res = mysql_query(&conexao,query);
                            if (!res)
                                printf("Cadastrado com Sucesso!! \n");
                            else
                                printf("Erro na inser��o %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                                mysql_close(&conexao);
                        }else{
                            printf("Falha de conexao\n");
                            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                        }
                        system("pause");
                        return(0);
                        break;
                    }
                    case 3: {
                        MYSQL conexao;
                        int res, esco = 2;
                        char query[100];
                        char nomeConvidado[31], rgConvidado[12], emailConvidado[65], numeroConvite[16], telefoneConvidado[21];
                        do {
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

                            printf("Informe o n�mero do convite: ");
                            scanf(" %s", &numeroConvite);
                            fflush(stdin);
                            system("cls");

                            printf("\n Nome: %s", &nomeConvidado);
                            printf("\n RG: %s", &rgConvidado);
                            printf("\n Telefone:%s", &telefoneConvidado);
                            printf("\n Email: %s", &emailConvidado);
                            printf("\n Convite: %s \n \n", &numeroConvite);

                            printf(" \n As Informa��es acima est�o corretas? \n \n 1 - sim\n 2 - n�o \n ");
                            scanf("%i",&esco);
                            system("cls");
                        } while(esco == 2);
                        //conexao com o banco //
                        mysql_init(&conexao);
                        if ( mysql_real_connect(&conexao, "localhost", "root", "", "teatro", 0, NULL, 0) ){
                            sprintf(query,"call cadas_convidado ('%s','%s','%s','%s','%s');", nomeConvidado, rgConvidado, emailConvidado, numeroConvite, telefoneConvidado);
                            res = mysql_query(&conexao,query);
                            if (!res)
                                printf("Cadastrado com Sucesso!! \n");
                            else
                                printf("Erro na inser��o %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                            mysql_close(&conexao);
                        } else {
                            printf("Falha de conexao\n");
                            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                        }
                        system("pause");
                        return(0);
                        break;
                        break;
                    }
                    case 4: {
                        MYSQL conexao;
                        int res, esco = 2;
                        char query[100];
                        char nomePessoa[31], rgPessoa[12], emailPessoa[65], numeroPd[16], telefonePessoa[21];
                        do {
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

                            printf("N�mero da carteirinha PD: ");
                            scanf(" %s", &numeroPd);
                            fflush(stdin);

                            system("cls");

                            printf("\n Nome: %s", &nomePessoa);
                            printf("\n RG: %s", &rgPessoa);
                            printf("\n Telefone:%s", &telefonePessoa);
                            printf("\n Email: %s", &emailPessoa);
                            printf("\n Numero da carteirinha: %s \n \n", &numeroPd);
                            printf(" \n As Informa��es acima est�o corretas? \n \n 1 - sim\n 2 - n�o \n");
                            scanf("%i",&esco);
                            system("cls");
                        } while(esco == 2);
                        // -------- Conex�o -------- //
                        mysql_init(&conexao);
                        if ( mysql_real_connect(&conexao, "localhost", "root", "", "teatro", 0, NULL, 0) ) {
                            sprintf(query,"call cadas_pne ('%s','%s','%s','%s','%s');", nomePessoa, rgPessoa, telefonePessoa, emailPessoa, numeroPd);
                            res = mysql_query(&conexao,query);
                            if (!res)
                                printf("Cadastrado com Sucesso!! \n");
                            else
                                printf("Erro na inser��o %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                            mysql_close(&conexao);
                        }else {
                            printf("Falha de conexao\n");
                            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
                        }
                        system("pause");
                        return(0);
                        break;
                    }
                }
                break;
            }
                break;

                case 2:
                system("cls");
                system("cls");
                printf("Voce deseja reservar uma cadeira para: \n \n1 - Professor \n2 - Convidado \n3 - Aluno \n4 - PNE:");
                scanf("%d", &tipoPessoa);

                if (tipoPessoa == 1 || tipoPessoa == 2 ){
                    mostrarPainelProf(matriz);
                    reservarProfessores(matriz); //Realiza a reserva de uma cadeira no painel, marcando c/ um R
                } if (tipoPessoa == 3 || tipoPessoa == 4){

                    mostrarPainelAluno(matriz);
                    reservaAluno(matriz);

                }

                break;
                case 3:

                system("cls");
                //mostrarPainel(matriz);
                getch();
                break;

                case 4:
                loopContinue = FALSE; //condicao para sa�da do programa
        }
    }while(loopContinue);
    getchar();
    return 0;
}
void inicializa(char matriz[ROW][COL]){
     int i,j;
     for(i=1;i<=ROW;i++)
       for(j=1;j<=COL;j++)
          matriz[i][j] = '.';
          matriz [6][9] = 'P';
          matriz [7][9] = 'P';
          matriz [8][9] = 'P';
          matriz [6][10] = 'P';
          matriz [7][10] = 'P';
}

void mostrarPainelProf(char matriz[2][10]){
  int i,j;
  printf("\n\n         %c   PAINEL DE OCUPACOES   %c\n\n",16,17);
  printf("          ");
  for(i=1;i<=10;i++)
    printf("%d     ",i);
  for(i=9;i<=10;i++){
     printf("\n\n     %d",i);
     for(j=1;j<=10;j++)
       printf("   (%c)",matriz[i][j]);
  }
  //apresenta o menu na tela
  legenda();
}

void mostrarPainelAluno(char matriz[8][10]){
  int i,j;
  printf("\n\n         %c   PAINEL DE OCUPACOES   %c\n\n",16,17);
  printf("          ");
  for(i=1;i<=10;i++)
    printf("%d     ",i);
  for(i=1;i<=8;i++){
     printf("\n\n     %d",i);
     for(j=1;j<=10;j++)
       printf("   (%c)",matriz[i][j]);
  }
  //apresenta o menu na tela
  legenda();
}

int menuOpcao(){
    int opcao=4;
    do {
         system("cls");
         printf("\n\n                    %c  MENU  %c\n\n",16,17);

         printf("                %c  1- Cadastro        %c\n",16,17);

         printf("                %c  2- Reservar       %c\n",16,17);

         printf("                %c  3- Sair           %c\n\n",16,17);

         printf("                   opcao: ");scanf("%d",&opcao);

         if(opcao <= 0 || opcao > 4){
            printf("\n\n\n    DIGITE APENAS VALORES CORESPONDENTES AO MENU !!");
            getch();
         }

     }while(opcao <= 0 || opcao > 4);

    return opcao;
}
//apresenta  a legenda na tela
void legenda(){
   printf("\n\n\n        .-Livre  P-PNE  R-Reservado\n\n");

}
    //efetica a compra da cadeira

//reserva a cadeira no teatro
void reservarProfessores(char matriz[2][10]){
   int row, col;
    printf("\n\n         RESERVA DE CADEIRAS\n\n");
   row = linhaX();
   col = colunaY();

   if(matriz[row][col]=='.'){
       matriz[row][col] = 'R';
       printf("\n\n      RESERVA EFETIVADA COM SUCESSO !!");
   }
   else if (matriz[row][col]=='X')
             printf("\n\n      CADEIRA JA OCUPADA!! ESCOLHA OUTRA !!\n\n");
        else if(matriz[row][col]=='R')
               printf("\n\n      CADEIRA JA RESERVADA !! ESCOLHA OUTRA !!\n\n");

    getch();

}
void reservaAluno(char matriz[8][10]){
   int row, col;
    printf("\n\n         RESERVA DE CADEIRAS\n\n");
   row = linhaX();
   col = colunaY();

   if(matriz[row][col]=='.'){
       matriz[row][col] = 'R';
       printf("\n\n      RESERVA EFETIVADA COM SUCESSO !!");
   }
   else if (matriz[row][col]=='X')
             printf("\n\n      CADEIRA JA OCUPADA!! ESCOLHA OUTRA !!\n\n");
        else if(matriz[row][col]=='R')
               printf("\n\n      CADEIRA JA RESERVADA !! ESCOLHA OUTRA !!\n\n");

    getch();

}
//ler a linha oferecida pelo usuario
int linhaX(){
   int row;
   printf("          Linha: "); scanf("%d",&row);
     if(row>10)
     {
       printf("\t\n Esta cadeira nao existe!!! ");
       }
   return row;
}
//ler  coluna oferecida pelo usuario
int colunaY(){
   int col;
   printf("          Coluna: "); scanf("%d",&col);
   if(col>10)
     {
       printf("\t\n Esta cadeira nao existe!!! ");
       }
   return col;
}
