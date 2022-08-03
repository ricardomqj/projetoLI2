#ifndef convert_h
#define convert_h

/**
 * @brief Neste Header vao ser chamadas as funcoes que serao usadas para converter variaveis.
 */

int tipov (tipo elem, int val);

void converterInteiro(STACK *s);
void converterChar(STACK *s);
int converteChartoInt (char x);
void converterReal(STACK *s);
void converterString (STACK *s);

#endif
