#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "../__BoolType/Bool.h"

#define ZERO 0

struct MemoryCell{

    void * Reference;

    struct MemoryCell * Next;

};

struct Queue{

    struct MemoryCell * Init;

    struct MemoryCell * End;

};

void NewQueue( struct Queue * );
// Create new Queue

struct MemoryCell * NewMemoryCell( void * );
// Create a Memory Cell

void DeleteQueue( struct Queue * );
// Delete Queue

void DeleteMemoryCell( struct MemoryCell * );
// Delete Memory Cell

void PushQueue( struct Queue *, struct MemoryCell * );
// Push, put in Queue

void PopQueue( struct Queue * );
// Pop, Remove of Queue

void * AccessInitQueue( struct Queue * );
// Access Queue and Return the top

enum Bool CheckEmptyQueue( struct Queue );
// Check if Queue is Empty

void ShowIntInit( struct Queue );
// Show Int Queue For Tests

void ShowCharInit( struct Queue );
// Show Char Stack For Tests

#endif