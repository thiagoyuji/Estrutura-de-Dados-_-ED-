#include "DoubleChainedList.h"

void NewDoubleChainedList( struct DoubleChainedList * DCList ){

    DCList->Begin = NULL;

    DCList->ThreadedListSize = ZERO;

}// Create New Empty DoubleChainedList

struct MemoryCell * NewMemoryCell( void * Element ){

    struct MemoryCell * NewMCell;

    NewMCell = ( struct MemoryCell * )malloc( 1 * sizeof( struct MemoryCell ) );

    NewMCell->Reference = Element;

    NewMCell->Next = NULL;

    NewMCell->Previous = NULL;

    return NewMCell;

}// Create New Memory Cell Double Chained List

void DeleteDoubleChainedList( struct DoubleChainedList * DCList ){

    struct MemoryCell * MCell;

    while( DCList->Begin != NULL ){

        MCell = DCList->Begin;

        DCList->Begin = MCell->Next;

        free( MCell );

    }

    free( DCList->Begin );

    DCList->ThreadedListSize = ZERO;

}// Delete Double Chained List, Free the Memory's Cell's

void DeleteMemoryCell( struct MemoryCell * MCell ){

    free( MCell );

}// Delete Memory Cell, Free a Memory Cell

size_t GetDoubleChainedListSize( struct DoubleChainedList DCList ){

    return DCList.ThreadedListSize;

}// Return the Size of Double Chained List 

enum Bool CheckEmptyList( struct DoubleChainedList DCList ){

    enum Bool Check = FALSE;

    if( DCList.Begin == NULL ){

        Check = TRUE;

    }

    return Check;

}// Return True if Double Chained List is Empty

int SearchElementFromDoubleChainedList( struct DoubleChainedList DCList, void * Element ){

    struct MemoryCell * Auxiliar = DCList.Begin;
    int count = 1;

    if( DCList.Begin != NULL ){

        while( Auxiliar != NULL && Auxiliar->Reference != Element ){

            Auxiliar = Auxiliar->Next;
            count++;

        }

    }

    return count;
    
}// Search some Element and Return the Position in List

void InsertInTheBeginOfDoubleChainedList( struct DoubleChainedList * DCList, struct MemoryCell * MCell ){

    struct MemoryCell * Auxiliar = DCList->Begin;

    if( DCList->Begin == NULL ){

        MCell->Next = DCList->Begin;  
        DCList->Begin = MCell;        

    }else{

        MCell->Next = DCList->Begin;
        Auxiliar->Previous = MCell;  
        DCList->Begin = MCell;

    }

    DCList->ThreadedListSize++;

}// Insert in the Begin of The Double Chained List

void InsertInTheFinalOfDoubleChainedList( struct DoubleChainedList * DCList, struct MemoryCell * MCell ){

    struct MemoryCell * Auxiliar;

    if( DCList->Begin == NULL ){

        DCList->Begin = MCell;

    }else{

        Auxiliar = DCList->Begin;

        while( Auxiliar->Next != NULL ){

            Auxiliar = Auxiliar->Next;

        }

        Auxiliar->Next = MCell;
        MCell->Previous = Auxiliar;

    }

    DCList->ThreadedListSize++;

}// Insert in the Final of the Double Chained List

void InsertInALocalOfDoubleChainedList( struct DoubleChainedList * DCList, struct MemoryCell * MCell, int Position ){

    struct MemoryCell * Previous;
    struct MemoryCell * Auxiliar;
    int count = 1;


    if( Position >= 1 && Position <= (DCList->ThreadedListSize + 1) ){

        Auxiliar = DCList->Begin;

        if( Position == 1 && DCList->Begin == NULL){

            MCell->Next = DCList->Begin;
            DCList->Begin = MCell;

        }else if( Position == 1 && DCList->Begin != NULL ){

            MCell->Next = DCList->Begin;
            Auxiliar->Previous = MCell;
            DCList->Begin = MCell;

        }else{

            while( count != Position ){

                count++;
                Previous = Auxiliar;
                Auxiliar = Auxiliar->Next;

            }

            MCell->Next = Auxiliar;
            MCell->Previous = Previous;

            Previous->Next = MCell;

            if(Auxiliar != NULL)    Auxiliar->Previous = MCell;
        
        }

        DCList->ThreadedListSize++;
    
    }

}// Insert in a Especific Local of the Double Chained List

void RemoveInTheBeginOfDoubleChainedList( struct DoubleChainedList * DCList ){

    struct MemoryCell * MCell = DCList->Begin;

    if( DCList->Begin != NULL ){

        DCList->Begin = MCell->Next;
        MCell->Previous = NULL;

        DCList->ThreadedListSize--;

        DeleteMemoryCell( MCell );

    }

}// Remove in the Begin of the Double Chained List

void RemoveInTheFinalOfDoubleChainedList( struct DoubleChainedList * DCList ){

    struct MemoryCell * Previous;
    struct MemoryCell * Auxiliar = DCList->Begin;

    if( DCList->Begin != NULL ){

        while( Auxiliar->Next != NULL ){

            Previous = Auxiliar;
            Auxiliar = Auxiliar->Next;

        }

        Previous->Next = NULL;

        DCList->ThreadedListSize--;

        DeleteMemoryCell( Auxiliar );

    }

}// Remove in the Final of the Double Chained List

void RemoveInALocalOfDoubleChainedList( struct DoubleChainedList * DCList , int Position ){

    struct MemoryCell * Previous;
    struct MemoryCell * Auxiliar = DCList->Begin;
    int count = 1;

    if( DCList->Begin != NULL ){

        if( Position >= 1 && Position <= ( DCList->ThreadedListSize + 1) ){

            if( Position == 1 && Auxiliar->Next == NULL ){

                DCList->Begin = Auxiliar->Next;

            }else if( Position == 1 && Auxiliar->Next != NULL ){
            
                DCList->Begin = Auxiliar->Next;
                Auxiliar->Previous = NULL;

            }else{

                while( count != Position ){

                    count++;
                    Previous = Auxiliar;
                    Auxiliar = Auxiliar->Next;

                }

                Previous->Next = Auxiliar->Next;

                if( Auxiliar->Next != NULL )    Auxiliar->Next->Previous = Previous;

            }

            DeleteMemoryCell( Auxiliar );

            DCList->ThreadedListSize--;

        }

    }

}// Remove in a Especific Local of the Double Chained List

void ShowIntDoubleChainedList( struct DoubleChainedList DCList ){

    struct MemoryCell * MCell = DCList.Begin;
    int * Element;

    printf("\nList[ %d ] :: ", DCList.ThreadedListSize);
    while( MCell != NULL ){

        Element = ( int * )MCell->Reference;

        printf("| %d | ", *Element);

        MCell = MCell->Next;

    }

    printf("\n\n");

}// Show Double Chained List in the Video