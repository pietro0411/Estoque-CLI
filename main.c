#include <stdio.h>
#include <stdlib.h>

void telaInicial(){
    printf("\t+-------------------------------------------------+\n");
    printf("\t\t _____     _                         \n");
    printf("\t\t| ____|___| |_ ___   __ _ _   _  ___ \n");
    printf("\t\t|  _| / __| __/ _ \\ / _` | | | |/ _ \\\n");
    printf("\t\t| |___\\__ \\ || (_) | (_| | |_| |  __/\n");
    printf("\t\t|_____|___/\\__\\___/ \\__, |\\__,_|\\___|\n");
    printf("\t\t                       |_|           \n");
    printf("\t+-------------------------------------------------+\n\n");

    printf("Insira uma operacao:\n");
    printf("[1] - Cadastrar\n");
    printf("[2] - Editar\n");
    printf("[3] - Remover\n");
    printf("[4] - Buscar\n");
    printf("[5] - Listar\n");
    printf("[6] - Sair\n\n");
    return;
}

void telaCadastro(){
    int opt, cod, qtd;
    char prod[30];
    float prc;

    do{
        system("cls");
        printf("Insira o codigo do produto:\n> ");
        scanf("%d", &cod);
        printf("Insira o nome do produto:\n> ");
        scanf(" %[^\n]", prod);
        printf("Insira o preco do produto:\n> ");
        scanf("%f", &prc);
        printf("Insira a quantidade em estoque:\n> ");
        scanf("%d", &qtd);

        printf("\n\nInsira uma operacao:\n");
        printf("[1] - Salvar e sair\n");
        printf("[2] - Descartar e sair\n");
        printf("[3] - Cadastrar outro produto\n\n> ");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                return;
            
            case 2:
                printf("Descartado\n");
                return;

            case 3:
                break;

            default:
                printf("Error! Operacao invalida\n");
                break;
        }

    } while(opt != 1);

    return;
}

int main(){
    int opt;

    do{
        system("cls");
        telaInicial();
        printf("> ");
        scanf("%d", &opt);

        switch (opt){
        case 1:
            telaCadastro();
            break;
        
        case 2:
            printf("\tEditar\n");
            break;
        
        case 3:
            printf("\tRemover\n");
            break;
        
        case 4:
            printf("\tBuscar\n");
            break;
        
        case 5:
            printf("\tListar\n");
            break;
        
        case 6:
            break;

        default:
            printf("Error! Operacao invalida\n");
            break;
        }
        
    } while(opt != 6);

    system("cls");
    
    return 0;
}