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

int main(){
    int opt;
    telaInicial();

    do{
        printf("> ");
        scanf("%d", &opt);

        switch (opt){
        case 1:
            printf("\tCadastrar\n");
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

    return 0;
}