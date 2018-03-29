#include "Queue.h"

void NewQueue( struct Queue * __queue__ ){

    __queue__->Init = NULL;
    __queue__->End = NULL;

}// Create new Queue

struct MemoryCell * NewMemoryCell( void * Element ){

    struct MemoryCell * MCell;

    MCell = ( struct MemoryCell * )malloc( 1 * sizeof( struct MemoryCell ) );

    MCell->Reference = Element;

    MCell->Next = NULL;

    return MCell;

}// Create a Memory Cell

void DeleteQueue( struct Queue * __queue__ ){

    struct MemoryCell * MCell = __queue__->Init;

    while( MCell->Next != __queue__->Init ){

        __queue__->Init = MCell->Next;
        __queue__->End = MCell->Next;

        DeleteMemoryCell( MCell );

        MCell = __queue__->Init;

    }

    DeleteMemoryCell( MCell );

    free( __queue__ );

}// Delete Queue

void DeleteMemoryCell( struct MemoryCell * MCell ){

    free( MCell );

}// Delete Memory Cell

void PushQueue( struct Queue * __queue__, struct MemoryCell * NewCell ){

    struct MemoryCell * Auxiliar;

    if( __queue__->Init == NULL ){

        __queue__->Init = NewCell;
        NewCell->Next = __queue__->Init;

    }else{

        Auxiliar = __queue__->End;

        Auxiliar->Next = NewCell;

        NewCell->Next = __queue__->Init;

    }

    __queue__->End = NewCell;

}// Push, put in Queue

void PopQueue( struct Queue * __queue__ ){

    struct MemoryCell * Auxiliar = __queue__->Init;

    if( __queue__->Init != NULL ){

        if( __queue__->Init == __queue__->End ){

            __queue__->Init = NULL;
            __queue__->End = NULL;

        }else{

            __queue__->Init = Auxiliar->Next;

            __queue__->End->Next = __queue__->Init;

        }

        DeleteMemoryCell( Auxiliar );
    
    }

}// Pop, Remove of Queue

void * AccessInitQueue( struct Queue * __queue__ ){

    void * Element;

    if( __queue__->Init != NULL ){

        Element = __queue__->Init->Reference;

    }

    return Element;

}// Access Queue and Return the top

enum Bool CheckEmptyQueue( struct Queue __queue__ ){

    enum Bool Check = FALSE;

    if( __queue__.Init == NULL ){

        Check = TRUE;

    }

    return Check;

}// Check if Queue is Empty

void ShowIntInit( struct Queue __queue__ ){

    if( __queue__.Init != NULL ){

        int * Element = ( int * )AccessInitQueue( &__queue__ );

        printf("Init >> %d\n", *Element);

    }

}// Show Int Queue For Tests

void ShowCharInit( struct Queue __queue__ ){

    if( __queue__.Init != NULL ){

        char * Element = ( char * )AccessInitQueue( &__queue__ );

        printf("Init >> %c\n", *Element);

    }

}// Show Char Stack For Tests