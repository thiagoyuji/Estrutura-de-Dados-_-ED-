#include "DoubleChainedList.h"

void main(){

    struct DoubleChainedList DCList;
    struct MemoryCell * NewCell;

    int Datas[] = {0,1,2,3,4,5,6,7,8,9};
    int Contador;

    NewDoubleChainedList( &DCList );
    
    for( Contador = 0; Contador < 10; Contador++ ){

        NewCell = NewMemoryCell( &Datas[Contador] );
        InsertInTheBeginOfDoubleChainedList( &DCList, NewCell );

    }

    ShowIntDoubleChainedList( DCList );
    RemoveInTheBeginOfDoubleChainedList( &DCList );
    ShowIntDoubleChainedList( DCList );

    DeleteDoubleChainedList( &DCList );
    ShowIntDoubleChainedList( DCList );

    for( Contador = 0; Contador < 10; Contador++ ){

        NewCell = NewMemoryCell( &Datas[Contador] );
        InsertInTheFinalOfDoubleChainedList( &DCList, NewCell );

    }

    ShowIntDoubleChainedList( DCList );
    RemoveInTheFinalOfDoubleChainedList( &DCList );
    ShowIntDoubleChainedList( DCList );

    DeleteDoubleChainedList( &DCList );
    ShowIntDoubleChainedList( DCList );

    NewCell = NewMemoryCell( &Datas[2] );
    InsertInALocalOfDoubleChainedList( &DCList, NewCell, 1 );

    NewCell = NewMemoryCell( &Datas[1] );
    InsertInALocalOfDoubleChainedList( &DCList, NewCell, 2 );

    NewCell = NewMemoryCell( &Datas[3] );
    InsertInALocalOfDoubleChainedList( &DCList, NewCell, 3 );
    
    NewCell = NewMemoryCell( &Datas[4] );
    InsertInALocalOfDoubleChainedList( &DCList, NewCell, 4 );

    NewCell = NewMemoryCell( &Datas[6] );
    InsertInALocalOfDoubleChainedList( &DCList, NewCell, 2 );

    ShowIntDoubleChainedList( DCList );

    int position = SearchElementFromDoubleChainedList(DCList , &Datas[4] );
    printf("Position %d\n", position);
    
    RemoveInALocalOfDoubleChainedList( &DCList, 2 );
    RemoveInALocalOfDoubleChainedList( &DCList, 4 );
    RemoveInALocalOfDoubleChainedList( &DCList, 1 );
    ShowIntDoubleChainedList( DCList );

    DeleteDoubleChainedList( &DCList );
    ShowIntDoubleChainedList( DCList );

}