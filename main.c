#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "tadlista.h"

typedef struct produto{
    int cod;
    int qtd;
    char prod[30];
    float prc;
} tp;

void telaMenu(){
    printf("\t\t+-------------------------------------------------+\n");
    printf("\t\t\t _____     _                         \n");
    printf("\t\t\t| ____|___| |_ ___   __ _ _   _  ___ \n");
    printf("\t\t\t|  _| / __| __/ _ \\ / _` | | | |/ _ \\\n");
    printf("\t\t\t| |___\\__ \\ || (_) | (_| | |_| |  __/\n");
    printf("\t\t\t|_____|___/\\__\\___/ \\__, |\\__,_|\\___|\n");
    printf("\t\t\t                       |_|           \n");
    printf("\t\t+-------------------------------------------------+\n\n");

    printf("Insira uma operacao:\n");
    printf("\t[1] - Cadastrar\n");
    printf("\t[2] - Editar\n");
    printf("\t[3] - Remover\n");
    printf("\t[4] - Buscar\n");
    printf("\t[5] - Listar\n");
    printf("\t[6] - Sair\n\n");
    return;
}

void telaCadastrar(tl *l){
    int opt, cod, qtd, ret;
    char prod[30];
    float prc;

    system("cls");
    printf("+-------------------------------------------------+\n");
    printf("Insira o codigo do produto:\n> ");
    scanf("%d", &cod);
    printf("Insira o nome do produto:\n> ");
    scanf(" %[^\n]", prod);
    printf("Insira o preco do produto:\n> ");
    scanf("%f", &prc);
    printf("Insira a quantidade em estoque:\n> ");
    scanf("%d", &qtd);
    printf("+-------------------------------------------------+\n");
    printf("\nInsira uma operacao:\n");
    printf("[1] - Salvar e sair\n");
    printf("[2] - Descartar e sair\n");
    printf("[3] - Cadastrar outro produto\n\n");

    do{
        printf("> ");
        scanf("%d", &opt);
        
        switch(opt){
            case 1:
                ret = insereLista(l, cod, qtd, prod, prc);
                if(ret != 1){
                    printf("Error! Falha ao cadastrar\n");
                    return;
                }
                else{
                    printf("Produto cadastrado com sucesso\n");
                    Sleep(1000);
                }
                return;
            
            case 2:
                printf("Cadastro descartado\n");
                Sleep(2000);
                return;

            case 3:
                ret = insereLista(l, cod, qtd, prod, prc);
                if(ret != 1){
                    printf("Error! Falha ao cadastrar\n");
                    return;
                }
                else{
                    printf("Produto cadastrado com sucesso\n");
                    Sleep(1000);
                }
                system("cls");
                printf("+-------------------------------------------------+\n");
                printf("Insira o codigo do produto:\n> ");
                scanf("%d", &cod);
                printf("Insira o nome do produto:\n> ");
                scanf(" %[^\n]", prod);
                printf("Insira o preco do produto:\n> ");
                scanf("%f", &prc);
                printf("Insira a quantidade em estoque:\n> ");
                scanf("%d", &qtd);
                printf("+-------------------------------------------------+\n");
                printf("\nInsira uma operacao:\n");
                printf("[1] - Salvar e sair\n");
                printf("[2] - Descartar e sair\n");
                printf("[3] - Cadastrar outro produto\n\n");
                break;

            default:
                printf("Error! Operacao invalida\n");
                Sleep(2000);
                break;
        }

    } while((opt != 1) || (opt != 2));

    return;
}

void telaRemover(tl *l){
    int cod, ret;

    system("cls");
    printf("+-------------------------------------------------+\n");
    printf("Insira o codigo do produto:\n> ");
    scanf("%d", &cod);

    ret = removeLista(l, cod);

    if(ret == 1){
        printf("Produto removido com sucesso\n");
        Sleep(1000);
    }
    else{
        printf("Error! Falha ao remover o produto\n");
        Sleep(1000);
    }

    return;
}

void lerArquivo(tl *l){
    FILE *arq;
    tp buffer;

    arq = fopen("data.dat", "rb");

    fread(&buffer, sizeof(tp), 1, arq);
    while(!feof(arq)){
        insereLista(l, buffer.cod, buffer.qtd, buffer.prod, buffer.prc);
        fread(&buffer, sizeof(tp), 1, arq);
    }

    fclose(arq);

    return;
}

void salvarArquivo(tl l){
    FILE *arq;
    tp buffer;
    tno *no;
    no = l.com;

    arq = fopen("data.dat", "wb");
    while(no != NULL){
        buffer.cod = no->cod;
        buffer.qtd = no->qtd;
        buffer.prc = no->prc;
        strcpy(buffer.prod, no->prod);
        fwrite(&buffer, sizeof(buffer), 1, arq);
        no = no->prox;
    }

    fclose(arq);
    return;
}

int main(){
    int opt;
    tl l;
    tp buffer;
    FILE *arq;
    iniciaLista(&l);

    arq = fopen("data.dat", "ab+");
    
    if(arq == NULL){
        printf("Error! Falha ao abrir o arquivo\n");
        return -1;
    }

    if(fread(&buffer, sizeof(tp), 1, arq)){
        lerArquivo(&l);
    }

    fclose(arq);
    system("cls");
    telaMenu();

    do{
        printf("> ");
        scanf("%d", &opt);

        switch (opt){
        case 1:
            telaCadastrar(&l);
            system("cls");
            break;
        
        case 2:
            printf("\tEditar\n");
            break;
        
        case 3:
            telaRemover(&l);
            system("cls");
            break;
        
        case 4:
            printf("\tBuscar\n");
            break;
        
        case 5:
            imprimeLista(l);
            break;
        
        case 6:
            break;

        default:
            printf("Error! Operacao invalida\n");
            Sleep(2000);
            system("cls");
            break;
        }

        telaMenu();
        
    } while(opt != 6);

    salvarArquivo(l);
    system("cls");
    
    return 0;
}
