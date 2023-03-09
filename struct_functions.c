#include "includes.h"


Aluno generate_student(){
    Aluno aux;
    printf("Insira o nome do aluno: ");
    fflush(stdin);
    gets(aux.nome);
    fflush(stdin);
    printf("\nInsira o CPF: ");
    gets(aux.cpf);
    fflush(stdin);
    aux.codigo = 111;//rng_a();
    aux.disciplinas_cursadas[0] = NULL;
    return aux;
}

node_aluno* create_student(Aluno a){
    node_aluno* new_node = (node_aluno*)malloc(sizeof(node_aluno));
    new_node -> al = a;
    new_node -> next = NULL;
    return new_node;
}

list_aluno* create_student_list(){
    list_aluno* lista = (list_aluno*)malloc(sizeof(list_aluno));
    lista -> head = lista -> tail = NULL;
    return lista;
}

void free_student_list(list_aluno* lista){
    node_aluno* aux = lista -> head;
    if(aux == NULL)
        return;
    node_aluno* prox = aux -> next;
    while(prox != NULL){
        // TODO: free_discipline_list(aux->al.disciplinas_cursadas);
        free(aux);
        aux = prox;
        prox = aux -> next;
    }
    free(lista);
}

list_aluno* append_aluno(list_aluno* lista, Aluno aluno){
    node_aluno* aux = lista->head;
    if (aux == NULL){
        node_aluno* new = create_student(aluno);
        lista -> tail = lista->head = new;
        return lista;
    }
    do{
        if(!strcmp(aux->al.cpf,aluno.cpf)){
            printf("\nAluno ja matriculado\n");
            return lista;
        }
        aux = aux->next;
    } while(aux != NULL);
    node_aluno* new = create_student(aluno);
    lista -> tail = lista->tail->next = new;
    return lista;
}

void search_aluno(list_aluno* lista){
    int i = 0;
    printf("Insira o parametro de busca\n0:Todos\n1:Codigo\n2:Nome\n3:CPF\n4: Disciplina");
    scanf("%d",&i);
    if(i == 0){
        node_aluno* aux = lista->head;
        while(aux != NULL){
            printf("----------------\n%d\n%s\n%s\n", aux->al.codigo, aux->al.nome, aux->al.cpf);
            aux = aux->next;
        }
    } else if(i == 1){
        int sample = 0;
        printf("\nInsira o codigo do aluno ");
        scanf("%d", &sample);
        node_aluno* aux = lista->head;
        while(aux != NULL){
            if(aux->al.codigo == sample)
            printf("----------------\n%s\n", aux->al.nome);
            aux = aux->next;
        }
    } else if(i == 2){
        char nome[70];
        printf("\nInsira o nome do aluno ");
        fflush(stdin);
        gets(nome);
        node_aluno* aux = lista->head;
        while(aux != NULL){
            if(!strcmp(nome,aux->al.nome))
            printf("-----------\n%d\n", aux->al.codigo);
            aux = aux->next;
        }
    } else if(i == 3){
        char cpf[12];
        printf("\nInsira o CPF do aluno ");
        fflush(stdin);
        gets(cpf);
        node_aluno* aux = lista->head;
        while(aux != NULL){
            if(!strcmp(cpf,aux->al.cpf))
            printf("-----------\n%d\n", aux->al.codigo);
            aux = aux->next;
        }
    } else if(i==4){

    } else{

    }
}

list_aluno* insert_disciplina(list_aluno* lista, list_disciplina* list_dis){
    int codigo=0, pos = 0;
    printf("Insira o codigo do aluno ");
    scanf("%d",&codigo);
    fflush(stdin);
    node_aluno* aux = lista->head;
    while(aux != NULL && aux->al.codigo!=codigo)
        aux = aux->next;
    char nome[30];
    do{
        printf("\nInsira o nome da disciplina (escreva FIM para sair) ");
        gets(nome);
        fflush(stdin);
        if(!strcmp(nome,"FIM"))
            return lista;
        node_disciplina* disciplina = list_dis-> head;
        while(disciplina !=NULL && strcmp(disciplina->dis.nome,nome))
            disciplina = disciplina->next;
        if(disciplina == NULL){
            printf("\nEsta disciplina nao esta cadastrada!\n");
            return lista;
        }
        int i = 0;
        while(aux -> al.disciplinas_cursadas[i] != NULL)
            i++;
        aux->al.disciplinas_cursadas[i] = disciplina;
        aux->al.disciplinas_cursadas[i+1] = NULL;
    } while(1);
}

list_aluno* edit_student(list_aluno* lista){
    int codigo=0, pos = 0;
    printf("Insira o codigo do aluno ");
    scanf("%d",&codigo);
    node_aluno* aux = lista->head;
    while(aux != NULL && aux->al.codigo!=codigo)
        aux = aux->next;
    char nome[30];
    int n = 0;
    printf("O que deseja mudar?\n1:Nome\n2:CPF\n");
    scanf("%d",&n);
    if(n==1){
        char nome[70];
        printf("\nDigite o novo nome");
        gets(nome);
        fflush(stdin);
        strcpy(aux->al.nome,nome);
        return lista;
    } else if(n==2){
        char cpf[12];
        printf("\nDigite o novo CPF");
        gets(cpf);
        fflush(stdin);
        strcpy(aux->al.cpf,cpf);
        return lista;
    } else{
        printf("Valor invalido!\n");
        return lista;
    }

}
void mostrar_disciplinas(list_aluno* lista,int codigo){
    node_aluno* aux = lista->head;
    while(aux!=NULL && aux->al.codigo != codigo)
        aux = aux->next;
    if(aux == NULL){
        printf("Aluno nao encontrado");
        return;
    }
    int i = 0;
    while(aux->al.disciplinas_cursadas[i]!=NULL){
        printf("%s ",aux->al.disciplinas_cursadas[i]->dis.nome);
        i++;
    }
}


Disciplina generate_discipline(){
    Disciplina aux;
    printf("Insira o nome da disciplina: ");
    fflush(stdin);
    gets(aux.nome);
    fflush(stdin);
    printf("\nInsira o nome do professor: ");
    gets(aux.professor);
    fflush(stdin);
    aux.codigo = rng_d();
    aux.credito = rng_f();
    aux.alunos_matriculados[0] = NULL;
    return aux;
}

node_disciplina* create_discipline(Disciplina d){
    node_disciplina* new_node = (node_disciplina*)malloc(sizeof(node_disciplina));
    new_node -> dis = d;
    new_node -> next = NULL;
    return new_node;
}

list_disciplina* create_discipline_list(){
    list_disciplina* lista = (list_disciplina*)malloc(sizeof(list_disciplina));
    lista -> head = lista -> tail = NULL;
    return lista;
}

void free_discipline_list(list_disciplina* lista){
    node_disciplina* aux = lista -> head;
    if(aux == NULL)
        return;
    node_disciplina* prox = aux -> next;
    while(prox != NULL){
        // TODO: free(aux->dis.alunos_matriculados);
        free(aux);
        aux = prox;
        prox = aux -> next;
    }
    free(lista);
}

list_disciplina* append_discipline(list_disciplina* lista, Disciplina dis){
    node_disciplina* aux = lista->head;
    if (aux == NULL){
        node_disciplina* new = create_discipline(dis);
        lista -> tail = lista ->head = new;
        return lista;
    }
    do{
        if(!strcmp(aux->dis.nome,dis.nome)){
            printf("\nDisciplina já matriculada\n");
            return lista;
        }
        aux = aux ->next;
    } while(aux->next != NULL);
    node_disciplina* new = create_discipline(dis);
    lista -> tail = lista->tail->next = new;
    return lista;
}