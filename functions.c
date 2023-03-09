#include "includes.h"


void set_rng(){
    time_t t;
    srand((unsigned) time(&t));
}

float rng_f(){
    return (float)(rand() % 100);
}

int rng_a(){
    int aux = rand() % 100000;
    if(1){ // TODO: verificar se ja existe
        return aux;
    }else{
        return rng_a();
    }
    
}

int rng_d(){
    int aux = rand() % 10000;
    if(1){ // TODO: verificar se ja existe
        return aux;
    }else{
        return rng_d();
    }
}

int array_comparator(int* a, int* b){
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}

void menu(int* flag){
    // !int i = 0, j = 0;
    // !printf("Bem-Vindo ao sistema de matrículas!\nO que gostaria de fazer?");
    // !printf("0: Criar novos dados\n1: adicionar\n2: remover\n3: editar\nprintar\n5: salvar e sair\n");
    // !scanf("%d",&i);
    // !switch (i)
    // !{
    // !case 1:
    // !    printf("\nO que gostaria de adicionar?\n1: Aluno\n2: Disciplina\n");
    // !    scanf("%d",&j);
    // !    if(j == 1){!

    //     } else{

    //     }
    //     break;
    // case 2:
    //     printf("\nO que gostaria de remover?\n1: Aluno\n2: Disciplina\n");
    //     scanf("%d",&j);
    //     if(j == 1){

    //     } else{

    //     }
    //     break;
    // case 3:
    //     printf("\nO que gostaria de editar?\n1: Aluno\n2: Disciplina\n");
    //     scanf("%d",&j);
    //     if(j == 1){

    //     } else{

    //     }
    //     break;
    // case 4:
    //     break;
    // case 5:
    //     *flag = 0;
    //     return;
    //     break;
    // default:
    //     *flag = 0;
    //     printf("valor invalido! Saindo...\n");
    //     return;
    // }
}

// void insert();

// void remove();

// void print_data();

void free_data(list_aluno* lista_aluno, list_disciplina* lista_disciplina){
    free_student_list(lista_aluno);
    free_discipline_list(lista_disciplina);
}

void store_data(FILE* f){
    f = fopen("dados.txt","w");
    if(f==NULL){
        int d = 0;
        printf("Falha em abrir arquivo!\n");
        printf("Tentar novamente: 1\nCancelar: 2\n");
        scanf("%d",&d);
        if(d == 2){
            char c='\0';
            printf("Tem certeza? Todos os dados serão perdidos (Y/N): ");
            scanf("%c",&c);
            printf("\n");
            if(c == 'y' || c == 'Y') return;
            else store_data(f);
        }
        else store_data(f);
    }

}

list_aluno* retrieve_student_data(char* file_name){
    FILE* f = fopen(file_name,"r");
    if(f == NULL){
    }
    int codigo;
    char nome[30];
    char cpf[12];
    int i = 0, step = 4;
    while(!feof(f)){
        fscanf(f,"%d",&codigo);
        for(int j=0;j<30;j++){
            
        }

        i+=step;
    }
}

list_disciplina* retrieve_discipline_data(char* file_name){
    FILE* f = fopen(file_name,"r");
    if(f == NULL){
    }
    int codigo[4];
    char nome[70];
    char professor[70];
    float credito;
    int i = 0, step = 4;
    while(!feof(f)){
        for(int j = 0; j< 4; j++){
            fscanf(f,"%d",&codigo[j]);
        }
        for(int j=0;j<30;j++){

        }
        i+=step;
    }
}
