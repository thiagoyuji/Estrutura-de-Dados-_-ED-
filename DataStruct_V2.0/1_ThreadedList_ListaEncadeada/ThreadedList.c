#include "ThreadedList.h"

void NewThreadedList( struct ThreadedList * TList ){

    TList->Begin = NULL;

    TList->ThreadedListSize = ZERO;

}// Create New Empty Threaded List

struct MemoryCell * NewMemoryCell( void * Element ){

    struct MemoryCell * MCell;

    MCell = ( struct MemoryCell * )malloc( 1 * sizeof( struct MemoryCell ) );

    MCell->Reference = Element;

    MCell->Next = NULL;

    return MCell;

}// Create New Memory Cell Threaded List

void DeleteThreadedList( struct ThreadedList * TList ){

    struct MemoryCell * MCell;

    while( TList->Begin != NULL ){

        MCell = TList->Begin;

        TList->Begin = MCell->Next;

        free( MCell );

    }

    free( TList->Begin );

    TList->ThreadedListSize = ZERO;

}// Delete Threaded List, Free the Memory's Cell's

void DeleteMemoryCell( struct MemoryCell * MCell ){

    free( MCell );

}// Delete Memory Cell, Free a Memory Cell

size_t GetThreadedListSize( struct ThreadedList TList ){

    return TList.ThreadedListSize;

}// Return the Size of Threaded List 

enum Bool CheckEmptyList( struct ThreadedList TList ){

    enum Bool Check = FALSE;

    if( TList.Begin == NULL ){

        Check = TRUE;

    } 

    return Check;

}// Return True if Threaded List is Empty

int SearchElementFromThreadedList( struct ThreadedList TList, void * Element ){

    struct MemoryCell * Auxiliar = TList.Begin;
    int count = 1;

    if( TList.Begin != NULL ){

        while( Auxiliar != NULL && Auxiliar->Reference != Element ){

            Auxiliar = Auxiliar->Next;
            count++;

        }

    }

    return count;

}// Search some Element and Return the Position in List

void InsertInTheBeginOfThreadedList( struct ThreadedList * TList, struct MemoryCell * MCell ){

    MCell->Next = TList->Begin;
    TList->Begin = MCell;

    TList->ThreadedListSize++;

}// Insert in the Begin of The Threaded List

void InsertInTheFinalOfThreadedList( struct ThreadedList * TList, struct MemoryCell * MCell ){

    struct MemoryCell * Auxiliar;

    if( TList->Begin == NULL ){

        TList->Begin = MCell;

    }else{

        Auxiliar = TList->Begin;

        while( Auxiliar->Next != NULL ){

            Auxiliar = Auxiliar->Next;

        }

        Auxiliar->Next = MCell;

    }

    TList->ThreadedListSize++;

}// Insert in the Final of the Threaded List

void InsertInALocalOfThreadedList( struct ThreadedList * TList, struct MemoryCell * MCell, int Position ){

    struct MemoryCell * Previous;
    struct MemoryCell * Auxiliar;
    int count = 1;


    if( Position >= 1 && Position <= (TList->ThreadedListSize + 1) ){

        if( Position == 1 ){

            MCell->Next = TList->Begin;
            TList->Begin = MCell;

        }else{

            Auxiliar = TList->Begin;

            while( count != Position ){

                count++;
                Previous = Auxiliar;
                Auxiliar = Auxiliar->Next;

            }

            MCell->Next = Auxiliar;
            Previous->Next = MCell;
        
        }

        TList->ThreadedListSize++;
    
    }

}// Insert in a Especific Local of the Threaded List

void RemoveInTheBeginOfThreadedList( struct ThreadedList * TList ){

    struct MemoryCell * MCell = TList->Begin;

    if( TList->Begin != NULL ){

        TList->Begin = MCell->Next;

        TList->ThreadedListSize--;

        DeleteMemoryCell( MCell );

    }

}// Remove in the Begin of the Threaded List

void RemoveInTheFinalOfThreadedList( struct ThreadedList * TList ){

    struct MemoryCell * Previous;
    struct MemoryCell * Auxiliar = TList->Begin;

    if( TList->Begin != NULL ){

        while( Auxiliar->Next != NULL ){

            Previous = Auxiliar;
            Auxiliar = Auxiliar->Next;

        }

        Previous->Next = NULL;

        TList->ThreadedListSize--;

        DeleteMemoryCell( Auxiliar );

    }

}// Remove in the Final of the Threaded List

void RemoveInALocalOfThreadedList( struct ThreadedList * TList, int Position ){

    struct MemoryCell * Previous;
    struct MemoryCell * Auxiliar = TList->Begin;
    int count = 1;

    if( TList->Begin != NULL ){

        if( Position >= 1 && Position <= ( TList->ThreadedListSize + 1) ){

            if( Position == 1 ){

                TList->Begin = Auxiliar->Next;

            }else{

                while( count != Position ){

                    count++;
                    Previous = Auxiliar;
                    Auxiliar = Auxiliar->Next;

                }

                Previous->Next = Auxiliar->Next;

            }

            DeleteMemoryCell( Auxiliar );

            TList->ThreadedListSize--;

        }

    }

}// Remove in a Especific Local of the Threaded List

void ShowIntThreadedList( struct ThreadedList TList ){

    struct MemoryCell * MCell = TList.Begin;
    int * Element;

    printf("\nList[ %d ] :: ", TList.ThreadedListSize);
    while( MCell != NULL ){

        Element = ( int * )MCell->Reference;

        printf("| %d | ", *Element);

        MCell = MCell->Next;

    }

    printf("\n\n");

}// Show Threaded List in the Video