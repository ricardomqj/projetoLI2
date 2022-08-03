#ifndef operacoes_h
#define operacoes_h

/**
 * @brief Neste Header vao ser chamadas as funcoes que serao usadas para realizar as varias operacoes da stack.
 */

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
void copy_top(STACK *s);
void duplicar(STACK *s);
void swap_dois(STACK *s);
void swap_tres(STACK *s);
void copy_top(STACK *s);
void ler_linha(STACK *s);
void to_int(STACK *s);
void igual(STACK *s);
void menor(STACK *s);
void maior(STACK *s);
void ifThenElse(STACK *s);
void negacao(STACK *s);
void pequeno(STACK *s);
void grande(STACK *s);
void shortAnd(STACK *s);
void shortOr(STACK *s);
void range(STACK *s);
void criarString(STACK *s, char *token);

#endif
