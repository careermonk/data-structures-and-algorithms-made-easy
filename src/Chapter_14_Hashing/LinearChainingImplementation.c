/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

/* elements */
struct element {
  int key;			   /* key */
  int value;			 /* data */
};
typedef struct element* element;

struct list {
  element data;
  struct list* next;
};
typedef struct list* list;
/* linked lists may be NULL (= end of list) and we do not check for circularity */

struct chain {
  list list;
};

/* Chains, implemented as linked lists */
typedef struct chain* chain;

struct table {
  int capacity;
  int size;
  chain* buckets;
};

/* Hash table interface */
typedef struct table* table;
table newHashTable (int capacity);
element put(table H, element e);
element get(table H, int key);
void deleteHashTable(table H);
chain newChain ();
element insertInChain(table H, chain C, element e);
element searchInChain(table H, chain C, int key);
void deleteChain(chain C);

void* xmalloc(size_t capacity) {
  void* p = malloc(capacity);
  if (p == NULL) {
    fprintf(stderr, "allocation failed\n");
    abort();
  }
  return p;
}

void* xcalloc(size_t nobj, size_t capacity) {
  void* p = calloc(nobj, capacity);
  if (p == NULL) {
    fprintf(stderr, "allocation failed\n");
    abort();
  }
  return p;
}

void deleteList(list p) {
  list q;
  while (p != NULL) {
    if (p->data != NULL)
      /* free element, if such a function is supplied */
      free(p->data);
    q = p->next;
    free(p);
    p = q;
  }
}

chain newChain(){
  chain C = xmalloc(sizeof(struct chain));
  C->list = NULL;
  return C;
}

// findInChain(p, key) returns list element whosecdata field has key key, or NULL if none exists
list findInChain(table H, chain C, int key){
  list p = C->list;
  while (p != NULL) {
    if (key == p->data->key)
      return p;
    p = p->next;
  }
  return NULL;
}

element insertInChain(table H, chain C, element e){
  list p = findInChain(H, C, e->key);
  if (p == NULL) {
    /* insert new element at the beginning */
    list new_item = xmalloc(sizeof(struct list));
    new_item->data = e;
    new_item->next = C->list;
    C->list = new_item;
    return NULL;		/* did not overwrite entry */
  } else {
    /* overwrite existing entry with given key */
    element oldElement = p->data;
    p->data = e;
    return oldElement;		/* return old entry */
  }
}

element searchInChain(table H, chain C, int key){
  list p = findInChain(H, C, key);
  if (p == NULL) return NULL;
  else return p->data;
}

void deleteChain(chain C){
  deleteList(C->list);
  free(C);
}

/* hash function */
int hash(int key, int capacity){
  return key % capacity;
}

/* Hash table implementation */
table newHashTable(int capacity){
  chain* A = xcalloc(capacity, sizeof(chain));
  table H = xmalloc(sizeof(struct table));
  H->capacity = capacity;
  H->size = 0;
  H->buckets = A;			/* all initialized to NULL; */
  return H;
}

element put(table H, element e){
  element oldElement;
  int key = e->key;
  int h = hash(key, H->capacity);
  if (H->buckets[h] == NULL)
    H->buckets[h] = newChain();
  oldElement = insertInChain(H, H->buckets[h], e);
  if (oldElement != NULL) return oldElement;
  H->size++;
  return NULL;
}

element get(table H, int key){
  int h = hash(key, H->capacity);
  if (H->buckets[h] == NULL) return NULL;
  element e = searchInChain(H, H->buckets[h], key);
  return e;
}

void deleteHashTable(table H){
  int i;
  for (i = 0; i < H->capacity; i++) {
    chain C = H->buckets[i];
    if (C != NULL) deleteChain(C);
  }
  free(H->buckets);
  free(H);
}

void deleteElement(element e) {
  free(e);
}

int main () {
  int n = 100;
  int capacity = 5;
  int num_tests = 5;
  int i; int j;

  printf("Testing buckets of capacity %d with %d values, %d times\n", capacity, n, num_tests);
  for (j = 0; j < num_tests; j++) {
    table H = newHashTable(capacity);
    for (i = 0; i < n; i++) {
      element e = xmalloc(sizeof(struct element));
      e->key = j*n+i;
      e->value = j*n+i;
      put(H, e);
    }
    for (i = 0; i < n; i++) {
      int key = j*n+i;
      assert(((element)get(H, key))->value == j*n+i); /* "missed existing element" */
    }
    for (i = 0; i < n; i++) {
      int key = (j+1)*n+i;
      assert(get(H, key) == NULL); /* "found nonexistent element" */
    }
    deleteHashTable(H);
  }
  printf("All tests passed!\n");
  return 0;
}
