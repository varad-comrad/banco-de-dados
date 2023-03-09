#include "includes.h"

// #define CHAR(a) ((char)a + 48)
// #define INT(a) ((int)(a-48))

// // ? DEFINING STRUCTS

// typedef struct Aluno Aluno;
// typedef struct Disciplina Disciplina;

// typedef struct node_aluno node_aluno;
// typedef struct list_aluno list_aluno;

// typedef struct node_disciplina node_disciplina;
// typedef struct list_disciplina list_disciplina;

// // ? FUNCTIONS PROTOTYPES

// void set_rng();
// int rng(int);
// int array_comparator(int*a, int* b);

// void menu(int*);
// void print_data();
// void free_data();
// void store_data(FILE*);
// list_aluno* retrieve_student_data(char*);
// list_disciplina* retrieve_discipline_data(char*);

// Aluno generate_student();
// node_aluno* create_student();
// list_aluno* create_student_list();
// void free_student_list(list_aluno*);
// list_aluno* append_aluno(Aluno);
// void print_aluno(list_aluno*);
// list_aluno* remove_student(list_aluno*);
// int student_is_in(list_aluno*, node_aluno*);
// list_aluno* edit_student(list_aluno*);

// Disciplina generate_discipline();
// node_disciplina* create_discipline();
// list_disciplina* create_discipline_list();
// void free_discipline_list();
// list_disciplina* append_discipline(Disciplina);
// void print_disciplinas(list_disciplina*);
// list_disciplina* remove_discipline(list_disciplina*);
// int discipline_is_in(list_disciplina*, node_disciplina*);
// list_disciplina* edit_discipline(list_disciplina*);


// ? MAIN FUNCTION

int main(){
    // set_rng();
    // printf("%d",rng(1000));
    Aluno a;
    a = generate_student();
    list_disciplina* lista_dis = create_discipline_list();
    list_aluno* lista = create_student_list();
    lista = append_aluno(lista, a);
    Disciplina b;
    for(int i = 0;i<4;i++){
        b = generate_discipline();
        lista_dis = append_discipline(lista_dis, b);
    }
    insert_disciplina(lista,lista_dis);
    // search_aluno(lista);
    mostrar_disciplinas(lista,111);


    // list_aluno* lista_de_alunos = retrieve_student_data("alunos.txt");
    // list_disciplina* lista_de_disciplinas = retrieve_discipline_data("disciplinas.txt");
    // int flag = 1;
    // int *FLAG = &flag;
    // do{
    //     menu(FLAG);
    // } while(flag!=0);
    // return 0;
}


// ? STRUCTS

// struct Aluno{
//     int codigo;
//     char nome[70];
//     char cpf[12];
//     Disciplina* disciplinas_cursadas[30];
// };

// struct Disciplina{
//     int codigo;
//     char nome[30];
//     char professor[70];
//     Aluno* alunos_matriculados[100]; // TODO: alunos por codigo
//     float credito;
// };

// struct node_aluno{
//     Aluno al;
//     node_aluno *next;
// };

// struct list_aluno{
//     node_aluno *head;
//     node_aluno *tail;
// };

// struct node_disciplina{
//     Disciplina dis;
//     node_disciplina *next;
// };

// struct list_disciplina{
//     node_disciplina *head;
//     node_disciplina *tail;
// };

// // ? FUNCTIONS

// void set_rng(){
//     time_t t;
//     srand((unsigned) time(&t));
// }

// int rng(int number_algarism){
//     return rand() % number_algarism;
// }

// int array_comparator(int* a, int* b){
//     for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
//         if(a[i]!=b[i]) return 0;
//     }
//     return 1;
// }

// void menu(int* flag){
//     int i = 0, j = 0;
//     printf("Bem-Vindo ao sistema de matrículas!\nO que gostaria de fazer?");
//     printf("0: Criar novos dados\n1: adicionar\n2: remover\n3: editar\nprintar\n5: salvar e sair\n");
//     scanf("%d",&i);
//     switch (i)
//     {
//     case 1:
//         printf("\nO que gostaria de adicionar?\n1: Aluno\n2: Disciplina\n");
//         scanf("%d",&j);
//         if(j == 1){

//         } else{

//         }
//         break;
//     case 2:
//         printf("\nO que gostaria de remover?\n1: Aluno\n2: Disciplina\n");
//         scanf("%d",&j);
//         if(j == 1){

//         } else{

//         }
//         break;
//     case 3:
//         printf("\nO que gostaria de editar?\n1: Aluno\n2: Disciplina\n");
//         scanf("%d",&j);
//         if(j == 1){

//         } else{

//         }
//         break;
//     case 4:
//         break;
//     case 5:
//         *flag = 0;
//         return;
//         break;
//     default:
//         *flag = 0;
//         printf("valor invalido! Saindo...\n");
//         return;
//     }
// }

// void insert();

// void remove();

// void print_data();

// void free_data(list_aluno* lista_aluno, list_disciplina* lista_disciplina){
//     free_student_list(lista_aluno);
//     free_discipline_list(lista_disciplina);
// }

// void store_data(FILE* f){
//     f = fopen("dados.txt","w");
//     if(f==NULL){
//         int d = 0;
//         printf("Falha em abrir arquivo!\n");
//         printf("Tentar novamente: 1\nCancelar: 2\n");
//         scanf("%d",&d);
//         if(d == 2){
//             char c='\0';
//             printf("Tem certeza? Todos os dados serão perdidos (Y/N): ");
//             scanf("%c",&c);
//             printf("\n");
//             if(c == 'y' || c == 'Y') return;
//             else store_data(f);
//         }
//         else store_data(f);
//     }

// }

// // TODO: fopen() returns NULL ptr
// list_aluno* retrieve_student_data(char* file_name){
//     FILE* f = fopen(file_name,"r");
//     if(f == NULL){
//     }
//     int codigo;
//     char nome[30];
//     char cpf[12];
//     int i = 0, step = 4;
//     while(!feof(f)){
//         fscanf(f,"%d",&codigo);
//         for(int j=0;j<30;j++){
            
//         }

//         i+=step;
//     }
// }

// list_disciplina* retrieve_discipline_data(char* file_name){
//     FILE* f = fopen(file_name,"r");
//     if(f == NULL){
//     }
//     int codigo[4];
//     char nome[70];
//     char professor[70];
//     float credito;
//     int i = 0, step = 4;
//     while(!feof(f)){
//         for(int j = 0; j< 4; j++){
//             fscanf(f,"%d",&codigo[j]);
//         }
//         for(int j=0;j<30;j++){

//         }
//         i+=step;
//     }
// }

// node_aluno* create_student(Aluno a){
//     node_aluno* new_node = (Aluno*)malloc(sizeof(Aluno));
//     new_node -> al = a;
//     new_node -> next = NULL;
//     return new_node;
// }

// list_aluno* create_student_list(){
//     list_aluno* lista = (list_aluno*)malloc(sizeof(list_aluno));
//     lista -> head = lista -> tail = NULL;
//     return lista;
// }

// void free_student_list(list_aluno* lista){
//     node_aluno* aux = lista -> head;
//     if(aux == NULL)
//         return;
//     node_aluno* prox = aux -> next;
//     while(prox != NULL){
//         free_discipline_list(aux->al.disciplinas_cursadas);
//         free(aux);
//         aux = prox;
//         prox = aux -> next;
//     }
// }

// list_aluno* append_aluno(list_aluno* lista, Aluno aluno){
//     node_aluno* aux = lista->head;
//     if (aux == NULL){
//         node_aluno* new = create_student(aluno);
//         lista->tail->next = new;
//         lista -> tail = new;
//         return lista;
//     }
//     do{
//         if(!strcmp(aux->al.cpf,aluno.cpf)){
//             printf("\nAluno já matriculado\n");
//             return lista;
//         }
//     } while(aux->next != NULL);
//     node_aluno* new = create_student(aluno);
//     lista->tail->next = new;
//     lista -> tail = new;
//     return lista;
// }


// node_disciplina* create_discipline(Disciplina d){
//     node_disciplina* new_node = (Disciplina*)malloc(sizeof(Disciplina));
//     new_node -> dis = d;
//     new_node -> next = NULL;
//     return new_node;
// }

// list_disciplina* create_discipline_list(){
//     list_disciplina* lista = (list_disciplina*)malloc(sizeof(list_disciplina));
//     lista -> head = lista -> tail = NULL;
//     return lista;
// }

// void free_discipline_list(list_disciplina* lista){
//     node_disciplina* aux = lista -> head;
//     if(aux == NULL)
//         return;
//     node_disciplina* prox = aux -> next;
//     while(prox != NULL){
//         free(aux->dis.alunos_matriculados);
//         free(aux);
//         aux = prox;
//         prox = aux -> next;
//     }
// }