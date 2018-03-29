#include "Stack.h"

void NewStack( struct Stack * __stack__ ){

    __stack__->Top = SIGNAL;

}// Create new Stack

struct MemoryCell NewMemoryCell( void * Element ){

    struct MemoryCell MCell;

    MCell.Reference = Element;

    return MCell;

}// Create a Memory Cell

void PushStack( struct Stack * __stack__, struct MemoryCell MCell ){

    int top = __stack__->Top + 1;

    if( top < ( MAX_SIZE + 1) ){

        __stack__->ArrayStack[ top ].Reference = MCell.Reference;

        __stack__->Top = top;

    }

}// Push, put in Stack

void PopStack( struct Stack * __stack__ ){

    int top = __stack__->Top;

    if( top > SIGNAL ){

        __stack__->Top = top - 1;

        __stack__->ArrayStack[ top ].Reference = ZERO;

    }

}// Pop, Remove of Stack

void * AccessTopStack( struct Stack * __stack__ ){

    void * Element;

    int top;

    if( __stack__->Top != SIGNAL ){

        top = __stack__->Top;

        Element = __stack__->ArrayStack[ top ].Reference;

    }

    return Element;

}// Access Stack and Return the top

enum Bool CheckEmptyStack( struct Stack __stack__ ){

    enum Bool Check = FALSE;

    if( __stack__.Top == SIGNAL ){

        Check = TRUE;

    }

    return Check;

}// Check if Stack is Empty

void ShowIntTop( struct Stack __stack__ ){

    int top = __stack__.Top;

    if( top >= ZERO ){

        int * Element = ( int * )AccessTopStack( &__stack__ );

        printf("Top >> %d\n", *Element);

    }

}// Show Int Stack For Tests

void ShowCharTop( struct Stack __stack__ ){

    int top = __stack__.Top;

    if( top >= ZERO ){

        char * Element = ( char * )AccessTopStack( &__stack__ );

        printf("Top >> %c\n", *Element);

    }

}// Show char Stack For Tests