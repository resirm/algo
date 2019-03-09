#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include "heapsort.h"

int heap_min_max(heap A);
int heap_maximum(heap A);
int heap_minimum(heap A);
int heap_extract_min_max(heap *A, MIN_MAX type);
int heap_extract_minimum(heap *A);
int heap_extract_maximum(heap *A);
void heap_inc_dec_key(heap *A, int i, int key, MIN_MAX type);
void heap_increase_key(heap *A, int i, int key);
void heap_decrease_key(heap *A, int i, int key);
void heap_insert(heap *A, int key, MIN_MAX type);
void max_heap_insert(heap *A, int key);
void min_heap_insert(heap *A, int key);
void heap_delete(heap *A, int node, MIN_MAX type);
void max_heap_delete(heap *A, int node);
void min_heap_delete(heap *A, int node);



#endif // !PRIORITY_QUEUE_H
