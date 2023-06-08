#include <stdio.h>

int main(void)
{
    //antes, estava escrito char *s; e, na hora de dar make, deu erro, pois não reservamos um espaço na memória para receber
    //a string digitada pelo usuário. Abaixo, alocamos 4bytes. Poderíamos usar malloc também, sem esquercer de dar free.
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}

//No início do curso, não foi apresentado o scanf porque precisávamos aprender outros fundamentos antes do scanf. Algumas
//funções foram construídas na biblioteca CS50 para nos proteger de alguns erros iniciais como alocação de memória que
//ainda não tínhamos aprendido para não bagunçar muito a cabeça. Então, na biblioteca do CS50 tem as funções: get_char,
//get_int, get_float, etc...que, por trás de tudo, existe uma proteção usando malloc que prevê que o usuário pode digitar
//uma quantidade de caracteres que devem ser alocadas de forma correta.