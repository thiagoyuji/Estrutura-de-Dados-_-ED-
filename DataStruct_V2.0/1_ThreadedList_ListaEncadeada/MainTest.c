#include "ThreadedList.h"

void main(){

    struct ThreadedList TList;
    struct MemoryCell * NewCell;

    int Datas[] = {0,1,2,3,4,5,6,7,8,9};
    int Contador;

    NewThreadedList( &TList );

    for( Contador = 0; Contador < 10; Contador++ ){

        NewCell = NewMemoryCell( &Datas[Contador] );
        InsertInTheBeginOfThreadedList( &TList, NewCell );

    }

    ShowIntThreadedList( TList );
    RemoveInTheBeginOfThreadedList( &TList );
    ShowIntThreadedList( TList );

    DeleteThreadedList( &TList );
    ShowIntThreadedList( TList );

    for( Contador = 0; Contador < 10; Contador++ ){

        NewCell = NewMemoryCell( &Datas[Contador] );
        InsertInTheFinalOfThreadedList( &TList, NewCell );

    }

    ShowIntThreadedList( TList );
    RemoveInTheFinalOfThreadedList( &TList );
    ShowIntThreadedList( TList );

    DeleteThreadedList( &TList );
    ShowIntThreadedList( TList );

    NewCell = NewMemoryCell( &Datas[2] );
    InsertInALocalOfThreadedList( &TList, NewCell, 1 );

    NewCell = NewMemoryCell( &Datas[1] );
    InsertInALocalOfThreadedList( &TList, NewCell, 2 );

    NewCell = NewMemoryCell( &Datas[3] );
    InsertInALocalOfThreadedList( &TList, NewCell, 3 );
    
    NewCell = NewMemoryCell( &Datas[4] );
    InsertInALocalOfThreadedList( &TList, NewCell, 4 );

    NewCell = NewMemoryCell( &Datas[6] );
    InsertInALocalOfThreadedList( &TList, NewCell, 2 );

    ShowIntThreadedList( TList );

    int position = SearchElementFromThreadedList(TList , &Datas[4] );
    printf("Position %d\n", position);
    
    RemoveInALocalOfThreadedList( &TList, 2 );
    RemoveInALocalOfThreadedList( &TList, 4 );
    RemoveInALocalOfThreadedList( &TList, 1 );
    ShowIntThreadedList( TList );

    DeleteThreadedList( &TList );
    ShowIntThreadedList( TList );

}