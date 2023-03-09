#define FUNCTIONS

void set_rng();
float rng_f();
int rng_a();
int rng_d();
int array_comparator(int* a, int* b);

void menu(int*);
void print_data();
void free_data();
void store_data(FILE*);
list_aluno* retrieve_student_data(char*);
list_disciplina* retrieve_discipline_data(char*);
