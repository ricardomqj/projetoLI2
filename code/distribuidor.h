#ifndef distribuidor_h
#define distribuidor_h

/**
 * @brief Neste Header vao ser chamadas as funcoes que serao usadas para identificar qual opecao tem que ser utilizada.
 */


void ope_aritm(STACK *s, char *token);
void ope_bina(STACK *s, char *token);
void ope_stack(STACK *s, char *token);
void ope_logic(STACK *s, char *token);
void ope_inOn(STACK *s, char *token);
void ope_array(STACK *s, char* token);  
bool check_string(char *token, char *chars);
void chegada(STACK *s, char *token);

#endif
