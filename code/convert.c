#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stack.h"
#include "operacoes.h"
#include "distribuidor.h"
#include "convert.h"

int tipov(tipo elem, int val)
{
    return (elem.t & val);
}

void converterInteiro(STACK *s)
{
    tipo x = pop(s);
    long l;
    double d;

    if (tipov(x, STR))
    {
        l = atoi(x.s); // a funcao atoi() vai converter a string introduzida numinteiro
        pushLong(s, l);
    }

    else if (tipov(x, Double))
    {
        d = x.d;
        l = (long)d;
        pushLong(s, l);
    }

    else if (tipov(x, Char))
    {
        l = x.c - '0';
        pushLong(s, l);
    }

    else
        pushLong(s, x.l);
}

void converterChar(STACK *s)
{
    tipo x = pop(s);

    if (x.t == Long)
    {
        long l = x.l;
        char c = (char)l; //converte o long num char
        x.t = Char;

        pushChar(s, c);
    }

    if (x.t == Double)
    {
        double d = x.d;
        char c1 = (char)d;
        x.t = Char;

        pushChar(s, c1);
    }

    else
        pushChar(s, x.c);
}

void converterReal(STACK *s)
{
    tipo x = pop(s);

    double d;
    long l;
    char c;

    if (tipov(x, Char))
    {
        c = x.c;

        d = (double)c;
        pushDouble(s, d);
    }

    if (tipov(x, STR))
    {
        d = atof(x.s);

        pushDouble(s, d);
    }

    if (tipov(x, Long))
    {
        l = x.l;
        d = (double)l;
        pushDouble(s, d);
    }
}

void converterString(STACK *s)
{
    tipo x = pop(s);
    char buffer[50];

    if (tipov(x, Char))
    {
        sprintf(buffer, "%c", x.c);
        pushString(s, buffer);
    }
    else if ((tipov(x, Long)))
    {
        sprintf(buffer, "%ld", x.l);
        pushString(s, buffer);
    }
    else if ((tipov(x, Double)))
    {
        sprintf(buffer, "%lf", x.d);
        pushString(s, buffer);
    }
    else
        pushString(s, x.s);
}

int converteChartoInt(char x)
{
    int y = 0;

    if (x == 'A')
        y = 10;
    else if (x == 'B')
        y = 11;
    else if (x == 'C')
        y = 12;
    else if (x == 'D')
        y = 13;
    else if (x == 'E')
        y = 14;
    else if (x == 'F')
        y = 15;
    else if (x == 'X')
        y = 0;
    else if (x == 'Y')
        y = 1;
    else if (x == 'Z')
        y = 2;
    //else converteChartoChar (x);

    return y;
}

/* nao funciona
char converteChartoChar (char x)
{
    char c;

    if (x == 'N') c = '\n';
    else if (x == 'S') c=' ';

    return c;
}
*/
