#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

/**
 * @brief A funcao '*new_stack'cria uma stack;
 * @return STACK* Stack criada na mem�ria com o espa�o necess�rio.
 */

STACK *new_stack(){
    return (STACK *) malloc(sizeof(STACK));
}

/**
 * @brief A funcao 'push' guarda elementos e os coloca na stack;
 * @param s Apontador para a stack;
 * @param x Elemento a ser guardado na stack.
 */

void push(STACK *s, tipo x){
    s->stack[s->sp] = x;
    s->sp++;
}

/**
 * @brief A funcao 'pop' retira um elemento da stack;
 * @param s Apontador para a stack;
 * @return ret Elemento retirado da stack.
 */

tipo pop(STACK *s)
{
    s->sp--;
    return s->stack[s->sp];
}

tipo non_pop(STACK *s){
    
    return s->stack[s->sp];
}

/**
 * @brief A funcao 'pushLong' retira um elemento da stack (pra elementos do tipo long);
 * @param s Apontador para a stack;
 * @return ret Elemento retirado da stack.
 */

void pushLong (STACK *s, long elem){
	s->stack[s->sp].t = Long;
    s->stack[s->sp].l = elem;
    s->sp++;
}

/**
 * @brief A funcao 'pushChar' retira um elemento da stack (pra elementos do tipo char);
 * @param s Apontador para a stack;
 * @return ret Elemento retirado da stack.
 */

void pushChar (STACK *s, long elem){
	s->stack[s->sp].t = Char;
    s->stack[s->sp].c = elem;
    s->sp++;
}

/**
 * @brief A funcao 'pushDouble' retira um elemento da stack (pra elementos do tipo double);
 * @param s Apontador para a stack;
 * @return ret Elemento retirado da stack.
 */

void pushDouble(STACK *s, double elem)
{
	s->stack[s->sp].t = Double;
    s->stack[s->sp].d = elem;
    s->sp++;
}

/**
 * @brief A funcao 'pushString' retira um elemento da stack (pra elementos do tipo string);
 * @param s Apontador para a stack;
 * @return ret Elemento retirado da stack.
 */

void pushString(STACK *s, char *elem){
	s->stack[s->sp].t = STR;
    s->stack[s->sp].s = elem;
    s->sp++;
}
