
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

/**
 * @brief A funcao 'ope_aritm' vai verificar qual das funcoes vai ser aplicada.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void ope_aritm(STACK *s, char *token)
{
    if (strcmp(token, "+") == 0)
        add(s);
    else if (strcmp(token, "-") == 0)
        sub(s);
    else if (strcmp(token, "*") == 0)
        multi(s);
    else if (strcmp(token, "/") == 0)
        division(s);
    else if (strcmp(token, "#") == 0)
        expo(s);
    else if (strcmp(token, "%") == 0)
        modulo(s);
    else if (strcmp(token, "(") == 0)
        decre(s);
    else if (strcmp(token, ")") == 0)
        incre(s);
}

/**
 * @brief A funcao 'ope_bina' vai verificar qual das funcoes vai ser aplicada.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void ope_bina(STACK *s, char *token)
{

    if (strcmp(token, "&") == 0)
        and(s);
    else if (strcmp(token, "|") == 0)
        or (s);
    else if (strcmp(token, "^") == 0)
        xor(s);
    else if (strcmp(token, "~") == 0)
        not(s);
}

/**
 * @brief A funcao 'ope_bina' vai verificar qual das funcoes vai ser aplicada.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void ope_stack(STACK *s, char *token)
{

    if (strcmp(token, "_") == 0)
        duplicar(s);
    else if (strcmp(token, "\\") == 0)
        swap_dois(s);
    else if (strcmp(token, "@") == 0)
        swap_tres(s);
    else if (strcmp(token, ";") == 0)
        pop(s);
    else if (strcmp(token, "$") == 0)
        copy_top(s);
}

/**
 * @brief A funcao 'ope_bina' vai verificar qual das funcoes vai ser aplicada.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

void ope_logic(STACK *s, char *token)
{

    if (strcmp(token, "?") == 0)
        ifThenElse(s);
    else if (strcmp(token, "=") == 0)
        igual(s);
    else if (strcmp(token, ">") == 0)
        maior(s);
    else if (strcmp(token, "<") == 0)
        menor(s);
    else if (strcmp(token, "!") == 0)
        negacao(s);
}

/**
 * @brief A funcao 'ope_bina' vai verificar qual das funcoes vai ser aplicada.
 * @param token e a variavel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para a Stack.
*/

void ope_inOn(STACK *s, char *token)
{

    if (strcmp(token, "l") == 0)
        ler_linha(s);

    else if (strcmp(token, "i") == 0)
        converterInteiro(s);

    else if (strcmp(token, "f") == 0)
        converterReal(s);

    else if (strcmp(token, "c") == 0)
        converterChar(s);

    else if (strcmp(token, "s") == 0)
        converterString(s);
}

void ope_array(STACK *s, char *token)
{

    if (strcmp(token, ",") == 0)
        range(s);
}

/**
 * @brief A funcao 'check_string' vai verificar qual das funcoes vai ser aplicada.
 * @param token e a varievel que corresponde ao caratere que representa uma operacao.
 * @param s e o apontador para Stack.
 */

bool check_string(char *token, char *chars) // verifica se o token esta numa string
{
    int i = 0;

    while (chars[i] != '\0')
    {
        char r = chars[i];
        if (token[0] == r)
            return true;
        i++;
    }
    return false;
}

/**
 * @brief A fun��o 'chegada' vai verificar qual das funcoes vai ser aplicada.
 * @param token � a vari�vel que corresponde ao caratere que representa uma opera��o.
 * @param s � o apontador para Stack.
 */

void chegada(STACK *s, char *token)
{

    if (check_string(token, "+-*/#%()"))
        ope_aritm(s, token);
    else if (check_string(token, "&|^~"))
        ope_bina(s, token);
    else if (check_string(token, "_\\@;$"))
        ope_stack(s, token);
    else if (check_string(token, "=<>!?"))
        ope_logic(s, token);
    else if (check_string(token, "lptifcs"))
        ope_inOn(s, token);
    else if (check_string(token, ","))
        ope_array(s, token);
    else if (strcmp(token, "e<") == 0)
        pequeno(s);
    else if (strcmp(token, "e>") == 0)
        grande(s);
    else if (strcmp(token, "e&") == 0)
        shortAnd(s);
    else if (strcmp(token, "e|") == 0)
        shortOr(s);
    else if (token[0] == '\"') criarString (s, token);
    else
    {
        long l;
        double d;
        char *p;
        char *proc = strstr(token, "."); // a funcao strstr vai procurar a posicao em que se encontra o caracter '.' e copiar esse valor para ela, caso nao encontre da NULL .

        d = strtod(token, &p);    //a funcao strtod vai procurar a posicao em que se encontra o caracter p e copiar esse valor para ela, caso nao encontre da NULL (converte o char para double).
        l = strtol(token, &p, 0); //a funcao strtol vai procurar a posicao em que se encontra o caracter p e copiar esse valor para ela, caso nao encontre da NULL (converte o char para a base indicada).

        if (proc)
            pushDouble(s, d);

        else if (l != 0)
            pushLong(s, l);
        else
            pushChar(s, token[0]);
    }
}
