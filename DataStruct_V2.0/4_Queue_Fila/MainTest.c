#include "Queue.h"

void main(){

    struct Queue __queue__;
    struct MemoryCell * NewCell;

    int IntDatas[] = {0,1,2,3,4,5,6,7,8,9};
    char CharDatas[] = {'a','b','c','d','e','f','g','h','i','j'};
    int Contador;

    NewQueue( &__queue__ );

// Push and Pop Int Datas---------------------------------------------
    for( Contador = 0; Contador < 10; Contador++ ){

        NewCell = NewMemoryCell( &IntDatas[Contador] );
        PushQueue( &__queue__, NewCell );

    }

    enum Bool check = CheckEmptyQueue( __queue__ );
    printf("Empty Stack >> %d\n\n", check);
    
    for( Contador = 0; Contador < 10; Contador++ ){

        ShowIntInit( __queue__ );
        PopQueue( &__queue__ );

    }

    check = CheckEmptyQueue( __queue__ );
    printf("\nEmpty Stack >> %d\n\n", check);

// Push and Pop Char Datas---------------------------------------------
    for( Contador = 0; Contador < 10; Contador++ ){

        NewCell = NewMemoryCell( &CharDatas[Contador] );
        PushQueue( &__queue__, NewCell );

    }

    check = CheckEmptyQueue( __queue__ );
    printf("Empty Stack >> %d\n\n", check);
    
    for( Contador = 0; Contador < 10; Contador++ ){

        ShowCharInit( __queue__ );
        PopQueue( &__queue__ );

    }
    
}