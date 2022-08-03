#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"
#include "convert.h"
#include "operacoes.h"
#include "array.h"
#include "distribuidor.h"

/*
void iniciar_Array(STACK *s)
{

    tipo array;                                                 
    array.t = STR;                                         
    array.s = (STACK *)malloc(sizeof(STACK)); 

    if (array.s == NULL)
    {
        STACK *aux = (STACK *)realloc(array.s,(2 * sizeof(STACK)));

        if (aux == NULL) printf("Limite de memória excedido.\n"); 
        else array.s= aux;
    }

    pushString(s,array.s);
}
*/