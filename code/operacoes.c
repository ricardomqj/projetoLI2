
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

//// Inicio do Guiao 1 ////

/**
 * @brief A funcao 'add' vai adicionar dois valores no topo da Stack e guardar o resultado final. Na funcao vai ser verificado o tipo de variaveis que estao a ser usadas (inteiros ou reais).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x1 e a variavel que ao caso em que x corresponde a um double.
 * @param y1 e a variavel que ao caso em que y corresponde a um long.
 * @param x2 e a variavel que ao caso em que x corresponde a um long.
 * @param y2 e a variavel que ao caso em que y corresponde a um double.
 * @param x3 e a variavel que ao caso em que x corresponde a um double.
 * @param y3 e a variavel que ao caso em que y corresponde a um double.
 * @param x4 e a variavel que ao caso em que x corresponde a um long.
 * @param y4 e a variavel que ao caso em que y corresponde a um long.
 * @param s e o apontador para Stack.
 */

void add(STACK *s)
{
  tipo x = pop(s), y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long

    pushDouble(s, y1 + x1);
  }

  else if (x.t == Long && y.t == Double)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double

    pushDouble(s, y2 + x2);
  }

  else if (x.t == Long && y.t == Long)
  {
    long x3 = x.l, y3 = y.l; // x e um long e y e um long

    pushLong(s, y3 + x3);
  }

  else if (x.t == Double && y.t == Double)
  {
    double x4 = x.d, y4 = y.d; // x e um double e y e um double

    pushDouble(s, y4 + x4);
  }

  else if (x.t == Char && y.t == Char)
  {
    char c = x.c, c1 = y.c;

    long x5 = converteChartoInt(c);
    long y5 = converteChartoInt(c1);

    pushLong(s, y5 + x5);
  }

  else
  {
    int size = strlen(x.s) + strlen(y.s);
    char *aux = malloc((size + 1) * (sizeof(char)));

    strcpy(aux, y.s);
    strcat(aux, x.s);

    pushString(s, aux);
  }
}

/**
 * @brief A funcao 'sub' vai subtrair dois valores no topo da Stack e guardar o resultado final. Na funcao vai ser verificado o tipo de variaveis que estao a ser usadas (inteiros ou reais).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x1 e a variavel que ao caso em que x corresponde a um double.
 * @param y1 e a variavel que ao caso em que y corresponde a um long.
 * @param x2 e a variavel que ao caso em que x corresponde a um long.
 * @param y2 e a variavel que ao caso em que y corresponde a um double.
 * @param x3 e a variavel que ao caso em que x corresponde a um double.
 * @param y3 e a variavel que ao caso em que y corresponde a um double.
 * @param x4 e a variavel que ao caso em que x corresponde a um long.
 * @param y4 e a variavel que ao caso em que y corresponde a um long.
 * @param s e o apontador para Stack.
 */

void sub(STACK *s)
{
  tipo x = pop(s), y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long

    pushDouble(s, y1 - x1);
  }

  else if (x.t == Long && y.t == Double)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double

    pushDouble(s, y2 - x2);
  }

  else if (x.t == Double && y.t == Double) // x e um double e y e um double
  {
    double x3 = x.d, y3 = y.d;

    pushDouble(s, y3 - x3);
  }

  else
  {
    long x4 = x.l, y4 = y.l; // x e um long e y e um long

    pushLong(s, y4 - x4);
  }
}

/**
 * @brief A funcao 'multi' vai multiplicar dois valores no topo da Stack e guardar o resultado final.Na funcao vai ser verificado o tipo de variaveis que estao a ser usadas (inteiros ou reais).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x1 e a variavel que ao caso em que x corresponde a um double.
 * @param y1 e a variavel que ao caso em que y corresponde a um long.
 * @param x2 e a variavel que ao caso em que x corresponde a um long.
 * @param y2 e a variavel que ao caso em que y corresponde a um double.
 * @param x3 e a variavel que ao caso em que x corresponde a um double.
 * @param y3 e a variavel que ao caso em que y corresponde a um double.
 * @param x4 e a variavel que ao caso em que x corresponde a um long.
 * @param y4 e a variavel que ao caso em que y corresponde a um long.
 * @param s Apontador para a stack.
 */

void multi(STACK *s)
{
  tipo x = pop(s), y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long

    pushDouble(s, y1 * x1);
  }

  else if (x.t == Long && y.t == Double)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double

    pushDouble(s, y2 * x2);
  }

  else if (x.t == Double && y.t == Double)
  {
    double x3 = x.d, y3 = y.d; // x e um double e y e um double

    pushDouble(s, y3 * x3);
  }

  else if (x.t == Long && y.t == Long)
  {
    long x4 = x.l, y4 = y.l; // x e um long e y e um long

    pushLong(s, y4 * x4);
  }

  else if (x.t == Long && y.t == STR)
  {
    char string[BUFSIZ];

    for (; x.l > 0; x.l--)
      strcat(string, y.s);

    pushString(s, string);
  }
}

/**
 * @brief A funcao 'division' vai dividir dois valores no topo da Stack e guardar o resultado final (apenas a parte inteira da divisao).Na funcao vai ser verificado o tipo de variaveis que estao a ser usadas (inteiros ou reais).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x1 e a variavel que ao caso em que x corresponde a um double.
 * @param y1 e a variavel que ao caso em que y corresponde a um long.
 * @param x2 e a variavel que ao caso em que x corresponde a um long.
 * @param y2 e a variavel que ao caso em que y corresponde a um double.
 * @param x3 e a variavel que ao caso em que x corresponde a um double.
 * @param y3 e a variavel que ao caso em que y corresponde a um double.
 * @param x4 e a variavel que ao caso em que x corresponde a um long.
 * @param y4 e a variavel que ao caso em que y corresponde a um long.
 */

void division(STACK *s)
{
  tipo x = pop(s), y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long

    pushDouble(s, y1 / x1);
  }

  else if (x.t == Long && y.t == Double)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double

    pushDouble(s, y2 / x2);
  }

  else if (x.t == Double && y.t == Double)
  {
    double x3 = x.d, y3 = y.d; // x e um double e y e um double

    pushDouble(s, y3 / x3);
  }

  else
  {
    long x4 = x.l, y4 = y.l; // x e um long e y e um long

    pushLong(s, y4 / x4);
  }
}

/**
 * @brief A funcaoo 'decre' vai decrementar o valor no topo da Stack e guardar o resultado final.Na funcao vai ser verificado o tipo de variaveis que estao a ser usadas (inteiros ou reais).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x1 e a variavel que ao caso em que x corresponde a um double.
 * @param x2 e a variavel que ao caso em que x corresponde a um long.
 * @param s e o apontador para Stack.
 */

void decre(STACK *s)
{
  tipo x = pop(s);

  if (tipov(x, Long))
  {
    double x1 = x.d; // x e um double

    pushDouble(s, x1 - 1);
  }

  else if (tipov(x, Double))
  {
    long x2 = x.l; // x e um long

    pushLong(s, x2 - 1);
  }
}

/**
 * @brief A funcaoo 'incre' vai decrementar o valor no topo da Stack e guardar o resultado final.Na funcao vai ser verificado o tipo de variaveis que estao a ser usadas (inteiros ou reais).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x1 e a variavel que ao caso em que x corresponde a um double.
 * @param x2 e a variavel que ao caso em que x corresponde a um long.
 * @param s e o apontador para Stack.
 */

void incre(STACK *s)
{
  tipo x = pop(s);

  if (tipov(x, Long))
  {
    long x1 = x.l; // x e um long

    pushLong(s, x1 + 1);
  }

  else if (tipov(x, Double))
  {
    double x2 = x.d; // x e um double

    pushDouble(s, x2 + 1);
  }
}

/**
 * @brief A fun  o 'expo' vai calcular o valor da variavel y elevado ao valor da vriavel x no topo da Stack e guardar o resultado final. Na funcao vai ser verificado o tipo de variaveis que estao a ser usadas (inteiros ou reais).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x1 e a variavel que ao caso em que x corresponde a um double.
 * @param y1 e a variavel que ao caso em que y corresponde a um long.
 * @param x2 e a variavel que ao caso em que x corresponde a um long.
 * @param y2 e a variavel que ao caso em que y corresponde a um double.
 * @param x3 e a variavel que ao caso em que x corresponde a um double.
 * @param y3 e a variavel que ao caso em que y corresponde a um double.
 * @param x4 e a variavel que ao caso em que x corresponde a um long.
 * @param y4 e a variavel que ao caso em que y corresponde a um long.
 * @param s e o apontador para Stack.
 */

void expo(STACK *s)
{
  tipo x = pop(s), y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long

    pushDouble(s, pow(y1, x1));
  }

  else if (y.t == Double && x.t == Long)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double

    pushDouble(s, pow(y2, x2));
  }

  else if (x.t == Double && y.t == Double)
  {
    double x3 = x.d, y3 = y.d; // x e um double e y e um double

    pushDouble(s, pow(y3, x3));
  }

  else
  {
    long x4 = x.l, y4 = y.l; // x e um long e y e um long

    pushLong(s, pow(y4, x4));
  }
}

/**
 * @brief A funcao 'modulo' vai dividir dois valores e guardar o resultado final (resto da divisao inteira). Na funcao vai ser verificado o tipo de variaveis que estao a ser usadas (inteiros ou reais).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x2 e a variavel obtem o valor de x correspondente a um long.
 * @param y2 e a variavel obtem o valor de y correspondente a um long.
 * @param s e o apontador para Stack.
 */

void modulo(STACK *s)
{
  tipo x = pop(s), y = pop(s);

  long x2 = x.l, y2 = y.l; // x e um long e y e um long

  pushLong(s, (y2 % x2));
}

/**
 * @brief A funcaoo 'and' aplica a operacao logica da conjuncao.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x2 e a variavel obtem o valor de x correspondente a um long.
 * @param y2 e a variavel obtem o valor de y correspondente a um long.
 * @param s e o apontador para Stack.
 */

void and (STACK * s)
{
  tipo x = pop(s), y = pop(s);

  long x2 = x.l, y2 = y.l; // x e um long e y e um long

  pushLong(s, (y2 & x2));
}

/**
 * @brief A funcao 'or' vai aplica a operacao logica da dijuncao.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x2 e a variavel obtem o valor de x correspondente a um long.
 * @param y2 e a variavel obtem o valor de y correspondente a um long.
 * @param s e o apontador para Stack.
 */

void or (STACK * s)
{
  tipo x = pop(s), y = pop(s);

  long x2 = x.l, y2 = y.l; // x e um long e y e um long

  pushLong(s, (y2 | x2));
}

/**
 * @brief A funcao 'xor' vai aplica a operacao logica da dijuncao exclusiva.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x2 e a variavel obtem o valor de x correspondente a um long.
 * @param y2 e a variavel obtem o valor de y correspondente a um long.
 * @param s  eo apontador para Stack.
 */

void xor (STACK * s)
{
  tipo x = pop(s), y = pop(s);

  long x2 = x.l, y2 = y.l; // x e um long e y e um long

  pushLong(s, (y2 ^ x2));
}

    /**
* @brief A funcao 'not' vai inverter os bits representantes do elemento no topo da stack.
* @param x e a variavel que corresponde ao primeiro elemnto da Stack.
* @param x2 e a variavel obtem o valor de x correspondente a um long.
* @param s e o apontador para Stack.
*/

    void not(STACK * s)
{
  tipo x = pop(s);

  if (x.t == Long)
  {
    long x2 = x.l;

    pushLong(s, ~x2);
  }
}

//// Fim do guiao 1////

//// Funcoes usadas no guiao 2////

/**
 * @brief A funcao 'duplicar' vai duplicar um numero.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param s e o apontador para Stack.
 */

void duplicar(STACK *s)
{
  tipo x = pop(s);

  push(s, x);
  push(s, x);
}

/**
 * @brief A funcao 'swap_dois'trocar a ordem de dois elementos.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param s e o apontador para Stack.
 */

void swap_dois(STACK *s)
{
  tipo x = pop(s), y = pop(s);

  push(s, x);
  push(s, y);
}

/**
 * @brief A funcao 'swap_tres' trocar a ordem de tres elementos.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param z e a variavel que corresponde ao terceiro elemento da Stack.
 * @param s e o apontador para Stack.
 */

void swap_tres(STACK *s)
{
  tipo x = pop(s), y = pop(s), z = pop(s);

  push(s, y);
  push(s, x);
  push(s, z);
}

/**
 * @brief A funcao 'copy_top' vai copiar o elemento da posicao x para o inicio da stack.
 * @param x e a variavel que corresponde ao indice do elemento da stack que queremos copiar para o topo.
 * @param j e a variavel que corresponde ao indice do elemento da stack que queremos copiar para o topo.
 * @param k e a variavel que corresponde ao indice para criar a lista aux.
 * @param g e a variavel que corresponde ao elemnto que queremos adicionar ao topo da stack.
 * @param aux e a variavel que corresponde a lista para onde vao ser copiados os elementos introduzidos.
 * @param s e o apontador para Stack.
 */

/**
 * It copies the top element of the stack and pushes it back on the stack
 * 
 * @param s the stack
 */
void copy_top(STACK *s)
{
  tipo x = pop(s);
  tipo aux[100];

  int j = (int)x.l;
  int k;

  for (k = 0; k <= j; k++)
    aux[k] = pop(s);

  k--;
  tipo g = aux[k];

  for (; k >= 0; k--)
    push(s, aux[k]);

  push(s, g);
}

/**
 * @brief A funcao 'ler_linha' vai ler uma linha.
 * @param aux e a variavel que corresponde a string que vai guardar os elementos.
 * @param le e a variavel que vai guardar a informacao que esta na string aux.
 * @param x1 e a variavel que ao caso em que x corresponde a um double.
 * @param s e o apontador para Stack.
 */

void ler_linha(STACK *s)
{
  char aux[10000];
  char *le = strdup(fgets(aux, 10000, stdin));
  pushString(s, le);
}

//// Fim do guiao 2////

//// Funcnoes usadas no guiao 3////

/**
 * @brief A funcao 'add' vai adicionar dois valores no topo da Stack e guardar o resultado final. Na funcao vai ser verificado o tipo de variaveis que estao a ser usadas (inteiros ou reais).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemento da Stack.
 * @param x1 e a variavel que ao caso em que x corresponde a um double.
 * @param y1 e a variavel que ao caso em que y corresponde a um long.
 * @param x2 e a variavel que ao caso em que x corresponde a um long.
 * @param y2 e a variavel que ao caso em que y corresponde a um double.
 * @param x3 e a variavel que ao caso em que x corresponde a um double.
 * @param y3 e a variavel que ao caso em que y corresponde a um double.
 * @param x4 e a variavel que ao caso em que x corresponde a um long.
 * @param y4 e a variavel que ao caso em que y corresponde a um long.
 * @param s e o apontador para Stack.
 */

void igual(STACK *s)
{
  tipo x = pop(s);
  tipo y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long
    if (y1 == x1)
      pushDouble(s, 1);
    else
      pushDouble(s, 0);
  }

  else if (x.t == Long && y.t == Double)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double
    if (y2 == x2)
      pushDouble(s, 1);
    else
      pushDouble(s, 0);
  }

  else if (x.t == Long && y.t == Long)
  {
    long x3 = x.l, y3 = y.l; // x e um long e y e um long

    if (y3 == x3)
      pushLong(s, 1);
    else
      pushLong(s, 0);
  }

  else if (x.t == Double && y.t == Double)
  {
    double x4 = x.d, y4 = y.d; // x e um double e y e um double
    if (y4 == x4)
      pushLong(s, 1);
    else
      pushLong(s, 0);
  }

  else
  {
    if (strcmp(x.s, y.s) == 0)
      pushLong(s, 1);
    else
      pushLong(s, 0);
  }
}

/**
 * @brief A funcao 'menor' vai verificar se o o ultimo numero colocado e menor que o anterior.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segunda elemnto da Stack.
 * @param s e o apontador para Stack.
 */

void menor(STACK *s)
{
  tipo x = pop(s);
  tipo y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long
    if (y1 < x1)
      pushDouble(s, 1);
    else
      pushDouble(s, 0);
  }

  else if (x.t == Long && y.t == Double)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double
    if (y2 < x2)
      pushDouble(s, 1);
    else
      pushDouble(s, 0);
  }

  else if (x.t == Long && y.t == Long)
  {
    long x3 = x.l, y3 = y.l; // x e um long e y e um long
    if (y3 < x3)
      pushLong(s, 1);
    else
      pushLong(s, 0);
  }

  else if (x.t == Double && y.t == Double)
  {
    double x4 = x.d, y4 = y.d; // x e um double e y e um double
    if (y4 < x4)
      pushDouble(s, 1);
    else
      pushDouble(s, 0);
  }

  else if (x.t == STR && y.t == STR)
  {
    char sx[BUFSIZ], sy[BUFSIZ];
    int cx = 0, cy = 0, i;

    strcpy(sx, x.s);
    strcpy(sy, y.s);

    for (i = 0; sx[i] != '\0'; i++)
      cx += (int)sx[i];

    for (i = 0; sy[i] != '\0'; i++)
      cy += (int)sy[i];

    if (cy < cx)
      pushLong(s, 1);
    else
      pushLong(s, 0);
  }
}

/**
 * @brief A funcao 'maior' vai verificar se o o ultimo numero colocado e maior que o anterior.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void maior(STACK *s)
{
  tipo x = pop(s);
  tipo y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long
    if (y1 > x1)
      pushDouble(s, 1);
    else
      pushDouble(s, 0);
  }

  else if (x.t == Long && y.t == Double)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double
    if (y2 > x2)
      pushDouble(s, 1);
    else
      pushDouble(s, 0);
  }

  else if (x.t == Long && y.t == Long)
  {
    long x3 = x.l, y3 = y.l; // x e um long e y e um long
    if (y3 > x3)
      pushLong(s, 1);
    else
      pushLong(s, 0);
  }

  else if (x.t == Double && y.t == Double)
  {
    double x4 = x.d, y4 = y.d; // x e um double e y e um double
    if (y4 > x4)
      pushDouble(s, 1);
    else
      pushDouble(s, 0);
  }

  else if (x.t == STR && y.t == STR)
  {
    char sx[BUFSIZ], sy[BUFSIZ];
    int cx = 0, cy = 0, i;

    strcpy(sx, x.s);
    strcpy(sy, y.s);

    for (i = 0; sx[i] != '\0'; i++)
      cx += (int)sx[i];

    for (i = 0; sy[i] != '\0'; i++)
      cy += (int)sy[i];

    if (cy > cx)
      pushLong(s, 1);
    else
      pushLong(s, 0);
  }
}
/**
 * @brief A funcao 'ifThenElse' vai verificar se z e uma condicao verdadeira caso se verifique vai guardar o valor de y, caso contrario guarda o valor de x na stack.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemnto da Stack.
 * @param z e a variavel que corresponde ao terceiro elemnto da Stack.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void ifThenElse(STACK *s)
{
  tipo x = pop(s);
  tipo y = pop(s);
  tipo z = pop(s);

  if (z.l == -1)
    pushLong(s, x.l);

  if (z.l)
    pushLong(s, y.l);
  else
    pushLong(s, x.l);
}

/**
 * @brief A funcao 'negacao' vai "trocar" o valor logico de uma certa operacao.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void negacao(STACK *s)
{
  tipo x = pop(s);

  if (x.t == Long)
  {
    if (x.l != 0)
      pushLong(s, 0);
    else
      pushLong(s, 1);
  }
  else if (x.t == Double)
  {
    if (x.d != 0.0)
      pushLong(s, 0);
    else
      pushLong(s, 1);
  }
}

/**
 * @brief A funcao 'pequeno' vai verificar qual e o menor valor entre dois numeros e devolve-lo a stack.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemnto da Stack.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void pequeno(STACK *s)
{
  tipo x = pop(s);
  tipo y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long
    if (y1 < x1)
      pushDouble(s, y1);
    else
      pushDouble(s, x1);
  }

  else if (x.t == Long && y.t == Double)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double
    if (y2 < x2)
      pushDouble(s, y2);
    else
      pushDouble(s, x2);
  }

  else if (x.t == Long && y.t == Long)
  {
    long x3 = x.l, y3 = y.l; // x e um long e y e um long
    if (y3 < x3)
      pushLong(s, y3);
    else
      pushLong(s, x3);
  }

  else if (x.t == Double && y.t == Double)
  {
    double x4 = x.d, y4 = y.d; // x e um double e y e um double
    if (y4 < x4)
      pushDouble(s, y4);
    else
      pushDouble(s, x4);
  }

  else if (x.t == STR && y.t == STR)
  {
    char sx[BUFSIZ], sy[BUFSIZ];
    int cx = 0, cy = 0, i;

    strcpy(sx, x.s);
    strcpy(sy, y.s);

    for (i = 0; sx[i] != '\0'; i++)
      cx += (int)sx[i];

    for (i = 0; sy[i] != '\0'; i++)
      cy += (int)sy[i];

    if (cy < cx)
      pushString(s, sy);
    else
      pushString(s, sx);
  }
}

/**
 * @brief A funcao 'grande' vai verificar qual e o maior valor entre dois elementos e devolve-lo a stack.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemnto da Stack.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void grande(STACK *s)
{
  tipo x = pop(s);
  tipo y = pop(s);

  if (x.t == Double && y.t == Long)
  {
    double x1 = x.d, y1 = y.l; // x e um double e y e um long
    if (y1 > x1)
      pushDouble(s, y1);
    else
      pushDouble(s, x1);
  }

  else if (x.t == Long && y.t == Double)
  {
    double x2 = x.l, y2 = y.d; // x e um long e y e um double
    if (y2 > x2)
      pushDouble(s, y2);
    else
      pushDouble(s, x2);
  }

  else if (x.t == Long && y.t == Long)
  {
    long x3 = x.l, y3 = y.l; // x e um long e y e um long
    if (y3 > x3)
      pushLong(s, y3);
    else
      pushLong(s, x3);
  }

  else if (x.t == STR && y.t == STR)
  {
    char sx[BUFSIZ], sy[BUFSIZ];
    int cx = 0, cy = 0, i;

    strcpy(sx, x.s);
    strcpy(sy, y.s);

    for (i = 0; sx[i] != '\0'; i++)
      cx += (int)sx[i];

    for (i = 0; sy[i] != '\0'; i++)
      cy += (int)sy[i];

    if (cy > cx)
      pushString(s, sy);
    else
      pushString(s, sx);
  }

  else
  {
    double x4 = x.d, y4 = y.d; // x e um double e y e um double
    if (y4 > x4)
      pushDouble(s, y4);
    else
      pushDouble(s, x4);
  }
}

/**
 * @brief A funcao 'shortAnd' vai verificar se y e verdade, caso afirmativo devolve o valor de y, caso contraio devolve zero.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemnto da Stack.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void shortAnd(STACK *s)
{
  tipo y = pop(s);
  tipo x = pop(s);

  if (x.l == 0)
    pushLong(s, y.l);

  else if (y.l == 0)
    pushLong(s, x.l);

  else if (x.t && y.t)
    push(s, y);

  else if (x.t == STR && y.t == STR)
  {
    char sx[BUFSIZ], sy[BUFSIZ];
    int cx = 0, cy = 0, i;

    strcpy(sx, x.s);
    strcpy(sy, y.s);

    for (i = 0; sx[i] != '\0'; i++)
      cx += (int)sx[i];

    for (i = 0; sy[i] != '\0'; i++)
      cy += (int)sy[i];

    if (cy && cx)
      pushString(s, sy);
  }

  else
    pushLong(s, 0);
}

/**
 * @brief A funcao 'shortOr' vai verificar se y e verdade, caso afirmativo devolve o valor de x, caso contraio devolve zero.
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param y e a variavel que corresponde ao segundo elemnto da Stack.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void shortOr(STACK *s)
{
  tipo y = pop(s);
  tipo x = pop(s);

  if (x.t | y.t)
    push(s, x);
}

//// Fim do guiao 3 ////

//// Inicio das funcoes usadas no guiao 4 ////

/**
 * @brief A funcao 'range' vai criar um segmento de numeros de 0 ate x-1 (posicoes de um array).
 * @param x e a variavel que corresponde ao primeiro elemnto da Stack.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void range(STACK *s)
{
  int i = 0;
  tipo x = pop(s);

  for (; i < x.l; i++)
    pushLong(s, i);
}

void criarString(STACK *s, char *token)
{
  char *str = malloc(sizeof(char *));
  int i;

  for (i = 1; token[i] != '\"'; i++)
    str[i - 1] = token[i];

  str[i - 1] = '\0';

  pushString(s, str);
}