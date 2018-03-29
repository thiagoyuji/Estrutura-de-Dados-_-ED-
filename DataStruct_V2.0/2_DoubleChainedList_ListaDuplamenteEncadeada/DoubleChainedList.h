#ifndef DOUBLE_CHAINED_LIST_H_INCLUDED
#define DOUBLE_CHAINED_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "../__BoolType/Bool.h"

#define ZERO 0

struct MemoryCell{

	void * Reference;

	struct MemoryCell * Next;

    struct MemoryCell * Previous;

};

struct DoubleChainedList{

	struct MemoryCell * Begin;

	size_t ThreadedListSize;

};


void NewDoubleChainedList( struct DoubleChainedList * );
// Create New Empty Double Chained List

struct MemoryCell * NewMemoryCell( void * );
// Create New Memory Cell Double Chained List

void DeleteDoubleChainedList( struct DoubleChainedList * );
// Delete Double Chained List, Free the Memory's Cell's

void DeleteMemoryCell( struct MemoryCell * );
// Delete Memory Cell, Free a Memory Cell

size_t GetDoubleChainedListSize( struct DoubleChainedList );
// Return the Size of Double Chained List 

enum Bool CheckEmptyList( struct DoubleChainedList );
// Return True if Double Chained List is Empty

int SearchElementFromDoubleChainedList( struct DoubleChainedList, void * );
// Search some Element and Return the Position in List

void InsertInTheBeginOfDoubleChainedList( struct DoubleChainedList *, struct MemoryCell * );
// Insert in the Begin of The Double Chained List

void InsertInTheFinalOfDoubleChainedList( struct DoubleChainedList *, struct MemoryCell * );
// Insert in the Final of the Double Chained List

void InsertInALocalOfDoubleChainedList( struct DoubleChainedList *, struct MemoryCell *, int );
// Insert in a Especific Local of the Double Chained List

void RemoveInTheBeginOfDoubleChainedList( struct DoubleChainedList * );
// Remove in the Begin of the Double Chained List

void RemoveInTheFinalOfDoubleChainedList( struct DoubleChainedList * );
// Remove in the Final of the Double Chained List

void RemoveInALocalOfDoubleChainedList( struct DoubleChainedList *, int );
// Remove in a Especific Local of the Double Chained List

void ShowIntDoubleChainedList( struct DoubleChainedList );
// Show Double Chained List in the Video

#endif
