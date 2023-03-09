#define STRUCT_FUNCTIONS

#ifndef STRUCTS
#define STRUCTS

#include "structs.h"

#endif


Aluno generate_student();
node_aluno* create_student(Aluno a);
list_aluno* create_student_list();
void free_student_list(list_aluno*);
list_aluno* append_aluno(list_aluno* lista, Aluno aluno);
void search_aluno(list_aluno*);
list_aluno* remove_student(list_aluno*);
int student_is_in(list_aluno*, int);
list_aluno* edit_student(list_aluno*);
list_aluno* insert_disciplina(list_aluno*, list_disciplina*);
void mostrar_disciplinas(list_aluno*,int);

Disciplina generate_discipline();
node_disciplina* create_discipline();
list_disciplina* create_discipline_list();
void free_discipline_list();
list_disciplina* append_discipline(list_disciplina* lista, Disciplina dis);
void print_disciplinas(list_disciplina*);
list_disciplina* remove_discipline(list_disciplina*);
int discipline_is_in(list_disciplina*, node_disciplina*);
list_disciplina* edit_discipline(list_disciplina*);
