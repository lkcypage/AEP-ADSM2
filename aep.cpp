
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int id;
char i[20];
int a;
int rm = 0;
int sair;

int main() {
	do{
		printf("_____________________________________________________________________\n");
		printf("________INICIO________BANCO DE DADOS__________SUPORTE___________EXIT_\n\n\n");
		printf("ESCOLHA UMA OPCAO(inicio/banco/suporte/sair)");
		scanf("%8s", i);
		if(strcmp(i, "inicio") == 0) {
			printf("________INICIO_______________________________________________________\n");
			printf("______________________BANCO DE DADOS__________SUPORTE___________EXIT_\n\n\n");
			printf("PARA AEP!!!!! \n");
		} 
		else if(strcmp(i, "banco") == 0) {
			do{
				printf("______________________BANCO DE DADOS_________________________________\n");
				printf("________INICIO________________________________SUPORTE___________EXIT_\n\n\n");
				printf("ESCOLHA MODO /ESCRITA 1/LEITURA 2/REMOVER 3/SAIR 4(1/2/3/4): ");
				scanf("%d", &a);
				getchar();
				FILE *arquivo;
				int id_lido;
				int c;
				switch(a){
					case 1:
						printf("Digite o ID até 4 digitos numericos excluindo 1 e o 0: ");
                        scanf("%d", &id);
                        while ((c = getchar()) != '\n' && c != EOF){}
						char ocorrencia[1000];
						arquivo = fopen("Arquivo.txt", "a");
						printf("ESCREVA OCORRENCIA ate 1000 caracteres: \n");
						fgets(ocorrencia, sizeof(ocorrencia), stdin);
						fprintf(arquivo, "%d|%s", id, ocorrencia);
						fclose(arquivo);
						break;

					case 2:
					    printf("Digite o ID para consultar: ");
					    scanf("%d", &id);	
					    while ((c = getchar()) != '\n' && c != EOF) {}
					    printf("Armazenamento maximo 1000 Caracteres\n");
					    char leitura[1000];
					    arquivo = fopen("Arquivo.txt", "r");
					    if (arquivo == NULL) {
					        perror("Erro ao abrir arquivo");
					        break;
					    }
					    while (fgets(leitura, sizeof(leitura), arquivo) != NULL) {
					        if (sscanf(leitura, "%d|", &id_lido) == 1) {
					            if (id == 0 || id_lido == id) {
					                printf("%s", leitura);
					            }
					        }
					        else {
					            printf("%s", leitura);
					        }
					    }
					    fclose(arquivo);
					    break;
					case 3: 
					    int id_remover;
					    int id_lido;
					    int c;
					    int encontrado = 0;
					    printf("Escolha um ID para deletar: ");
					    if (scanf("%d", &id_remover) != 1 || id_remover < 0 || id_remover > 9999) {
					        printf("ID invalido!\n");
							while ((c = getchar()) != '\n' && c != EOF) {}
					        break;
					    }
						while ((c = getchar()) != '\n' && c != EOF) {}
					    arquivo = fopen("Arquivo.txt", "r");
					    if (arquivo == NULL) {
					        perror("Erro ao abrir Arquivo.txt");
					        break;
					    }
					    FILE *temporario = fopen("Temporario.txt", "w");
					    if (temporario == NULL) {
					        perror("Erro ao criar arquivo temporario");
					        fclose(arquivo);
					        break;
					    }
					    while (fgets(leitura, sizeof(leitura), arquivo) != NULL) {
					        if (sscanf(leitura, "%d|", &id_lido) == 1 &&
					            id_lido == id_remover) {
					            encontrado = 1;
					            continue; 
					        }
					        fputs(leitura, temporario);
					    }
					    fclose(arquivo);
					    if (fclose(temporario) != 0) {
					        printf("Erro ao fechar arquivo temporario.\n");
					        break;
					    }
					    if (!encontrado) {
					        printf("ID nao encontrado: %04d\n", id_remover);
					        remove("Temporario.txt");
					        break;
					    }
					    if (remove("Arquivo.txt") != 0) {
					        perror("Erro ao remover arquivo original");
					        break;
					    }
					    if (rename("Temporario.txt", "Arquivo.txt") != 0) {
					        perror("Erro ao renomear arquivo temporario");
					        printf("O arquivo restante esta em Temporario.txt\n");
					        break;
					    }
					    printf("Registro ID %04d removido com sucesso!\n",
					           id_remover);
					    break;
				}
		}while(a != 4);
		}
		else if((strcmp (i, "suporte") == 0)){
			printf("______________________________________________SUPORTE________________\n");
			printf("________INICIO________BANCO DE DADOS____________________________EXIT_\n\n\n");
			printf("O trabalho sera organizado apenas para AEP, entao esta area e apenas um possivel complemento. \n");
			
		}
	}while(strcmp (i, "sair") != 0);
}
