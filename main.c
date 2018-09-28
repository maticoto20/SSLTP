#include <stdio.h>
#include <stdlib.h>

int columna(char c);
int transicion(int estado, char c);
void append(char* s, char c);

int main(){
    printf("Escribir cadena: ");
    char c;
    c = getc(stdin);
    char cadena[100] = "0100100010B%a%%0.98";
    char token[100] = "";
    int i;
    int estado = 0;
    for(i=0; c!='\0'; i++){
        c = cadena[i];
        append(token, c);
        estado = transicion(estado, c);
        accionTransicion(estado, token);
    }
    return 0;
}

void append(char* s, char c){
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

int transicion(int estado, char c){
    int afd[10][7] = {{1,6,6,6,0,6,8},
                      {2,6,3,4,0,6,8},
                      {2,6,3,6,0,6,8},
                      {6,6,6,6,7,6,9},
                      {5,5,6,6,0,6,8},
                      {3,3,6,6,0,6,8},
                      {6,6,6,6,0,6,8},
                      {1,6,6,6,0,6,8},
                      {10,10,10,10,10,10,10}, //pongo 10 porque hay no tienen transiciones (se podrian sacar las filas)
                      {10,10,10,10,10,10,10}};
    return afd[estado][columna(c)];
}

int columna(char c){
    switch(c)
    {
        case '0': return 0;
        case '1': return 0;
        case '2': return 1;
        case '3': return 1;
        case '4': return 1;
        case '5': return 1;
        case '6': return 1;
        case '7': return 1;
        case '8': return 1;
        case '9': return 1;
        case 'B': return 2;
        case '.': return 3;
        case '%': return 4;
        case 0: return 6;
        default: return 5;
    }
}

void accionTransicion(int estado, char* token){
    int len = strlen(token);
    switch (estado){
    case 0:
        token[len-1]='\0';
        printf("error: %s\n", token);
        token[0] = '\0';
        break;
    case 8:
        printf("error: %s\n", token);
        token[0] = '\0';
        break;
    case 7:
        token[len-1]='\0';
        printf("ok: %s\n", token);
        token[0] = '\0';
        break;
    case 9:
        printf("ok: %s\n", token);
        token[0] = '\0';
        break;
    }
}
