//
// Created by andre on 27/03/2021.
//


#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

//enum como o stor faz no struct3
//o enum enumera por default, 0, 1, 2 e 3 para testar depois very nice
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} Tipo;

#define INTEGER (LONG | CHAR)
#define NUMBER (INTEGER | DOUBLE)

//tipo para guardar qualquer tipo de valor
typedef struct data {
    Tipo tipo;
    void* value;
}Data;

//tentar fazer uma Stack com um array de operandos
typedef struct stack {
    Data *array;
    int size;
    int sp;
}Stack;

Stack *CreateStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->size = 100;
    s->sp = -1;
    s->array = (Data *) calloc(s->size, sizeof(Data));
    return s;
}

void Push(Data operando, Stack *stack) {
    if(stack->size == (stack->sp)-1) {
        stack->size +=100;
        stack->array = (Data *) realloc(stack->array, stack->size * sizeof(Data));
    }
    stack->sp++;
    stack->array[(stack->sp)] = operando;
}

Data Pop(Stack *stack) {
    return stack->array[(stack->sp)--];
}

Data Top(Stack *stack) {
    return stack->array[stack->sp];
}

void PrintData(Data *data) {
    switch (data->tipo) {
        case LONG: //um pouco estranho isto :\;
            printf("%ld", *(long*)(data->value));
            break;
        case DOUBLE:
            printf("%f", *(double*)(data->value));
            break;
        case CHAR:
            printf("%c", *((char*)(data->value)));
            break;
        case STRING:
            printf("%s", (char*)data->value);
            break;
    }
    putchar('\n');
}

#define CreateDados(_name, _type)                   \
    Data CreateDados##_name(_type val) {            \
        _type *vp = (_type*) malloc(sizeof(_type)); \
        *vp = val;                                  \
        Data op = {_name, vp};                      \
        return op;                                  \
    }

CreateDados(LONG, long)
CreateDados(DOUBLE, double)
CreateDados(CHAR, char)
//CreateDados(STRING, char*)

Data CreateDadosSTRING(char* val) {
    char *vp = strdup(val);
    Data op = {STRING, vp};
    return op;
}




int main () {
    char *teste = "2.4";
    char *resto;
    long val1 = strtol(teste, &resto, 10);
    double val2 = strtod(resto, &resto);
    printf("%d\n", val1);
    printf("%f\n", val2);
    printf("%f\n", val1 + val2);
    printf("%s\n", resto);
    //Stack *stack = CreateStack();
    //Data L = CreateDadosDOUBLE(350.76);
    //Data S = CreateDadosSTRING("jdasiudhasjq");
    //PrintData(&L);
    //PrintData(&S);
}