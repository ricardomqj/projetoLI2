#ifndef STACK_
#define STACK_

/**
 * @brief definicao da tipovar que corresponde ao tamanho de cada tipo de variavel.
 */

typedef enum {
  Long,
  Double,
  Int,
  Char,
  STR
} tipovar;

/**
 * @brief definicao da estrutura tipovar que corresponde ao tamanho de cada tipo de variavel.
 */

typedef struct Tipo{
  tipovar t;
    long l;
    int i;
    char c;
    double d;
    char *s;
} tipo;

/**
 * @brief Tamanho m�ximo da stack.
 */
#define Max_Stack 1000

/**
 * @brief Defeni��o da estrutura da stack;
 * @param stack Array com os elementos da stack;
 * @param sp Apontador para um elemento da stack.
 */
typedef struct {
    int tamanho;
    tipo stack[Max_Stack];
    int sp;
} STACK;

/**
 * @brief Cria��o de uma stack vazia;
 * @param s Apontador para a Stack;
 * @param elem Elemento a ser guardado na stack;
 * @return STACK* Stack criada.
 */
STACK *new_stack();
void push(STACK *s, tipo elem);
tipo pop(STACK *s);
tipo non_pop(STACK *s);

/*Funcoes para o guiao 1*/


void add(STACK *s);
void sub(STACK *s);
void multi(STACK *s);
void division(STACK *s);
void decre(STACK *s);
void incre(STACK *s);
void expo(STACK *s);
void modulo(STACK *s);
void and (STACK * s);
void or (STACK * s);
void xor (STACK * s);
void not(STACK * s);

/*Funcoes para o guiao 2*/

void swap_dois(STACK *s);
void swap_tres(STACK *s);
void copy_top(STACK *s);
void duplicar(STACK *s);
void ler_linha(STACK *s);
void converteChar (STACK *s);

/*Funcoes para o guiao 3*/

void igual(STACK *s);
void menor (STACK *s);
void maior (STACK *s);
void ifThenElse(STACK *s);
void negacao(STACK *s);
void pequeno(STACK *s);
void grande(STACK *s);
void shortAnd(STACK *s);
void shortOr(STACK *s);

/*Funcoes usadas para Conversoes*/

int tipov (tipo elem, int bytes);
void pushLong (STACK *s, long elem);
void pushChar (STACK *s, long elem);
void pushDouble (STACK *s, double elem);
void pushString (STACK *s, char *elem);
void converterInteiro(STACK *s);
void converteReal(STACK *s);
void converteChar(STACK *s);

#endif
