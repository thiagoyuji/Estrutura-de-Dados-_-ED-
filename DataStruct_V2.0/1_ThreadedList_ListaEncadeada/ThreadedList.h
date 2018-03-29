#ifndef THREADED_LIST_H_INCLUDED
#define THREADED_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "../__BoolType/Bool.h"

#define ZERO 0

struct MemoryCell{

	void * Reference;

	struct MemoryCell * Next;

};

struct ThreadedList{

	struct MemoryCell * Begin;

	size_t ThreadedListSize;

};


void NewThreadedList( struct ThreadedList * );
// Create New Empty Threaded List

struct MemoryCell * NewMemoryCell( void * );
// Create New Memory Cell Threaded List

void DeleteThreadedList( struct ThreadedList * );
// Delete Threaded List, Free the Memory's Cell's

void DeleteMemoryCell( struct MemoryCell * );
// Delete Memory Cell, Free a Memory Cell

size_t GetThreadedListSize( struct ThreadedList );
// Return the Size of Threaded List 

enum Bool CheckEmptyList( struct ThreadedList );
// Return True if Threaded List is Empty

int SearchElementFromThreadedList( struct ThreadedList, void * );
// Search some Element and Return the Position in List

void InsertInTheBeginOfThreadedList( struct ThreadedList *, struct MemoryCell * );
// Insert in the Begin of The Threaded List

void InsertInTheFinalOfThreadedList( struct ThreadedList *, struct MemoryCell * );
// Insert in the Final of the Threaded List

void InsertInALocalOfThreadedList( struct ThreadedList *, struct MemoryCell *, int );
// Insert in a Especific Local of the Threaded List

void RemoveInTheBeginOfThreadedList( struct ThreadedList * );
// Remove in the Begin of the Threaded List

void RemoveInTheFinalOfThreadedList( struct ThreadedList * );
// Remove in the Final of the Threaded List

void RemoveInALocalOfThreadedList( struct ThreadedList *, int );
// Remove in a Especific Local of the Threaded List

void ShowIntThreadedList( struct ThreadedList );
// Show Threaded List in the Video

#endif
