// Copyright (c) 2008 CareerMonk Publications and others.
// E-Mail           : info@careermonk.com
// Creation Date    : 2008-01-10 06:15:46
// Created by       : Narasimha Karumanchi
// Book Title       : Data Structures And Algorithms Made Easy
// Warranty         : This software is provided "as is" without any
//                    warranty; without even the implied warranty of
//                    merchantability or fitness for a particular purpose.

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>

struct ListNode {
  int vertex;
  struct ListNode *next;
};

struct edge{
    int source;
    int destination;
};

struct graph{
    int V;                        // number of vertices
    int E;                        // number of edges
    struct ListNode *adjList[];   // adjacency matrix
};

void rand_init(void){
    // Initializes the random generator rand()
    time_t t;
    srand((unsigned) time(&t));
}


int insertEdge(struct graph* G, const struct edge E) {
  int n, from, to;
  n = G->V;
  from = E.source;
  to = E.destination;

  if (0 > from || from > n || 0 > to || to > n) return -1;

  struct ListNode *prev = NULL, *ptr = G->adjList[from];
  while (ptr != NULL) {
    if (ptr->vertex == to) return 0;
    else {
      prev = ptr;
      ptr = ptr->next;
    }
  }
  if (ptr==NULL) {
    struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    newNode->vertex = to;
    newNode->next = NULL;

    if (prev == NULL) {
      G->adjList[from] = newNode;
    } else {
      prev->next = newNode;
    }
  }
  return 1;
}

int removeEdge(struct graph* G, const struct edge E) {
  int n, from, to;
  n = G->V;
  from = E.source;
  to = E.destination;
  if (0 > from || from > n || 0 > to || to > n) return -1;
  struct ListNode *prev = NULL, *ptr = G->adjList[from];
  while (ptr != NULL) {
    if (ptr->vertex == to) {
      if (prev == NULL) {
        G->adjList[from] = ptr->next;
        free(ptr);
      } else {
        prev->next = ptr->next;
        free(ptr);
      }
      return 1;
    } else {
      prev = ptr;
      ptr = ptr->next;
    }
  }
  return 0;
}

struct graph* createGraph(const int numVertices) {
    assert(numVertices >= 0);
    // Create an empty graph with numVertices
    int i, j;
    struct graph* G =  (struct graph *) malloc(sizeof( struct graph));
    assert(G != NULL);
    G->V = numVertices;
    G->E = 0;

    // allocate memory for each column and initialise with 0
    struct ListNode *newNode, *last;
    for (int i = 0; i < G->V; i++) {
        G->adjList[i] = (struct ListNode *) malloc(sizeof(struct ListNode));
        assert(G->adjList[i] != NULL);
        G->adjList[i]->vertex = i;
        G->adjList[i]->next = NULL;
    }
    return G;
}

struct edge newEdge(int x, int y){
    // return an edge with ends x and y
    struct edge e;
    e.source = x;
    e.destination = y;
    return e;
}

struct graph* randomGraph(const int N, const float p){
    // A random graph with N vertices and probability p for each edge
    int i, j;
    struct edge E;
    struct graph* G = createGraph(N);
    rand_init();
    for (i=0; i < N; i++) for(j=i+1; j < N; j++) {
        if (rand() < p * RAND_MAX) {  // rand() returns an integer between 0 and RAND_MAX
            E = newEdge(i,j);
            insertEdge(G, E);
        }
    }
    return G;
}

void displayGraph(struct graph* G) {
  struct ListNode *ptr;
  int i;
  for (i = 0; i < G->V; i++) {
    ptr = G->adjList[i];
    printf("\nnode %d neighbors:", i);
    while (ptr != NULL) {
      printf(" %d", ptr->vertex);
      ptr = ptr->next;
    }
  }
}

void destroyGraph(struct graph* G) {
  int i;
  struct ListNode *temp, *ptr;
  for (i = 0; i < G->V; i++) {
    ptr = G->adjList[i];
    while (ptr != NULL) {
      temp = ptr;
      ptr = ptr->next;
      free(temp);
    }
    G->adjList[i] = NULL;
  }
  printf("\nGraph is deleted");
}

void DFS_iterative(struct graph* G, int visited[], int start){
  int stack[G->V];
  int top = -1, i;
  visited[start] = 1;
  stack[++top] = start;
  struct ListNode *p = NULL;
  while (top != -1) {
    start = stack[top--];
    printf("%d ", start);
    p = G->adjList[start];
    while (p) {
      i = p->vertex;
      if (visited[i] == 0) {
        stack[++top] = i;
        visited[i] = 1;
      }
      p = p->next;
    }
  }
}

void DFS_recursive(struct graph* G, int visited[], int start){
  int i;
  struct ListNode *p = NULL;
  visited[start] = 1;
  printf("%d ", start);
  p = G->adjList[start];
  while (p) {
    i = p->vertex;
    if (visited[i] == 0) {
      DFS_recursive(G, visited, i);
    }
    p = p->next;
  }
}

int main(int argc, char *args[]) {
    // Test code
    struct edge E;
    int n = 10;
    struct graph* G = randomGraph(n, 0.15);
    displayGraph(G);

    // initialization of visited array
    int i;
    int visited[n];
    for (i = 0; i < n; i++) visited[i] = 0;
    printf("\nDFS recursive order:\n");
    // DFS start from 0
    DFS_recursive(G, visited, 0);
    printf("\nvisited by DFS:\n");
    for (i=0; i<n; i++) {
       if (visited[i] == 1) printf("%d ", i);
    }

    // initialization of visited array
    for (i = 0; i < n; i++) visited[i] = 0;
    printf("\nDFS iterative order:\n");
    // DFS start from 0
    DFS_iterative(G, visited, 0);
      printf("\nvisited by DFS:\n");
    for (i=0; i<n; i++) {
       if (visited[i] == 1) printf("%d ", i);
    }
    return 0;
}
