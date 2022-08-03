#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stack.h"
#include "operacoes.h"
#include "distribuidor.h"
#include "convert.h"

/**
 * @brief Fun��o principal;
 * @param s Apontador para a stack;
 * @param line String que cont�m o conte�do da stack;
 * @param token Lista de carateres que representam as opera��es a serem realizadas;
 * @param i �ndidice da stack;
 * @return 0 Se o comando for executado corretamente.
 */

int main()
{
    STACK *s = new_stack(); //Criar stack
    char line[BUFSIZ];
    char token[BUFSIZ];
    int i;

    if (fgets(line, BUFSIZ, stdin) != NULL)
    {
        while (sscanf(line, "%s%[^\n]", token, line) == 2)
        {
            chegada(s, token);
        }

        chegada(s, token);

        for (i = 0; i < s->sp; i++)
        {
            tipo j = s->stack[i];
            tipovar x = j.t;

            if (x == Long) printf("%ld", j.l);

            else if (x == Double) printf("%g", j.d);

            else if (x == Char) printf("%c", j.c);

            else if (x == STR)
                printf("%s",j.s);
        }
    }
    printf("\n");
    return 0;
}
