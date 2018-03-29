#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "../__BoolType/Bool.h"

#define ZERO 0

#define MAX_SIZE 51

#define SIGNAL -1

struct MemoryCell{

    void * Reference;

};

struct Stack{

    int Top;

    struct MemoryCell ArrayStack[ MAX_SIZE ];

};

void NewStack( struct Stack * );
// Create new Stack

struct MemoryCell NewMemoryCell( void * );
// Create a Memory Cell

void PushStack( struct Stack *, struct MemoryCell );
// Push, put in Stack

void PopStack( struct Stack * );
// Pop, Remove of Stack

void * AccessTopStack( struct Stack * );
// Access Stack and Return the top

enum Bool CheckEmptyStack( struct Stack );
// Check if Stack is Empty

void ShowIntTop( struct Stack );
// Show Int Stack For Tests

void ShowCharTop( struct Stack );
// Show Char Stack For Tests

#endif