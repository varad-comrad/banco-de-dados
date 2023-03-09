#define STRUCTS
typedef struct Aluno Aluno;
typedef struct Disciplina Disciplina;

typedef struct node_aluno node_aluno;
typedef struct list_aluno list_aluno;

typedef struct node_disciplina node_disciplina;
typedef struct list_disciplina list_disciplina;



struct Aluno{
    int codigo;
    char nome[70];
    char cpf[12];
    node_disciplina* disciplinas_cursadas[30];
};

struct Disciplina{
    int codigo;
    char nome[30];
    char professor[70];
    node_aluno* alunos_matriculados[100]; 
    float credito;
};

struct node_aluno{
    Aluno al;
    node_aluno *next;
};

struct list_aluno{
    node_aluno *head;
    node_aluno *tail;
};

struct node_disciplina{
    Disciplina dis;
    node_disciplina *next;
};

struct list_disciplina{
    node_disciplina *head;
    node_disciplina *tail;
};
