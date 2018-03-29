#include "Stack.h"

void main(){

    struct Stack __stack__;
    struct MemoryCell NewCell;

    int IntDatas[] = {0,1,2,3,4,5,6,7,8,9};
    char CharDatas[] = {'a','b','c','d','e','f','g','h','i','j'};
    int Contador;

    NewStack( &__stack__ );

// Push and Pop Int Datas---------------------------------------------
    for( Contador = 0; Contador < 10; Contador++ ){

        NewCell = NewMemoryCell( &IntDatas[Contador] );
        PushStack( &__stack__, NewCell );

    }

    enum Bool check = CheckEmptyStack( __stack__ );
    printf("Empty Stack >> %d\n\n", check);
    
    for( Contador = 0; Contador < 10; Contador++ ){

        ShowIntTop( __stack__ );
        PopStack( &__stack__ );

    }

    check = CheckEmptyStack( __stack__ );
    printf("\nEmpty Stack >> %d\n\n", check);

// Push and Pop Char Datas---------------------------------------------
    for( Contador = 0; Contador < 10; Contador++ ){

        NewCell = NewMemoryCell( &CharDatas[Contador] );
        PushStack( &__stack__, NewCell );

    }

    check = CheckEmptyStack( __stack__ );
    printf("Empty Stack >> %d\n\n", check);
    
    for( Contador = 0; Contador < 10; Contador++ ){

        ShowCharTop( __stack__ );
        PopStack( &__stack__ );

    }
    
}