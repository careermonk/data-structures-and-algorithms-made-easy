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
#include <time.h>
#include <assert.h>
#define MAX_VERTICES 50   // max number of vertices for our graph
#define MAX_DEGREE 50     // max degree for a vertex

struct graph{
    int V;            // number of vertices
    int E;            // number of edges
    int **adjMatrix;  // adjacency matrix
};

struct edge{
    int source;
    int destination;
};

void rand_init(void){
    // Initializes the random generator rand()
    time_t t;
    srand((unsigned) time(&t));
}

struct graph* createGraph(const int numVertices){
     assert(numVertices >= 0);
    // Create an empty graph with numVertices
    int i, j;
    struct graph* G =  (struct graph *) malloc(sizeof( struct graph));
    G->V = numVertices;
    G->E = 0;
    // allocate memory for each row
    G->adjMatrix = malloc(numVertices * sizeof(int *));
    assert(G != NULL);
    // allocate memory for each column and initialise with 0
    for (i = 0; i < numVertices; i++) {
       G->adjMatrix[i] = calloc(numVertices, sizeof(int));
       assert(G->adjMatrix[i] != NULL);
    }
    return G;
}

void displayGraph(const struct graph* G){
    // Display the graph (adjMatrix)
    int i,j, v;
    v = G->V;
    printf("%d vertices; %d edges.\n", G->V, G->E);
    for(i=0; i< v; i++){
        for(j=0; j < v; j++) printf("%3d ",(G->adjMatrix)[i][j]);
        printf("\n");
    }
}

void displayEdges(const struct graph* G){
    int v,i,j;
    v = G->V;
    for(i=0; i < v; i++){
        for(j=i+1; j < v; j++){
            if(G->adjMatrix[i][j]==1) printf("%d-%d ",i,j);
        }
    }
}

void insertEdge(struct graph* G, const struct edge E){
    int v, x, y;
    v = G->V;
    x = E.source;
    y = E.destination;
    if(x >= v || y >= v) {
        printf("Error when adding edge.");
        exit(EXIT_FAILURE);
    }
    if (G->adjMatrix[x][y] == 0){ // For undirected graphs set both the bits
        G->adjMatrix[x][y] = 1;
        G->adjMatrix[y][x] = 1;
        (G->E)++;
    }
}

void removeEdge(struct graph* G, const struct edge E){
    int v, x, y;
    v = G->V;
    x = E.source;
    y = E.destination;
    if(x >= v || y >= v) {
        printf("Error when deleting edge.");
        exit(EXIT_FAILURE);
    }
    if (G->adjMatrix[x][y] == 1){
        G->adjMatrix[x][y] = 0;
        G->adjMatrix[y][x] = 0;
        (G->E)--;
    }
}

void destroyGraph(struct graph* G){ // to free memory
    if (G){
      if (G->adjMatrix){
          int i;
          for (i = 0; i < G->V; i++)
             free(G->adjMatrix[i]);
          free(G->adjMatrix);
      }
      free(G);
    }
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



void main(void){
    // Test code
    struct edge E;
    struct graph* G = randomGraph(10, 0.15);
    displayGraph(G);
    E = newEdge(5,6);
    insertEdge(G, E);
    displayGraph(G);
    printf("\n");
    displayEdges(G);
    removeEdge(G, E);
    displayGraph(G);
    printf("\n");
    displayEdges(G);
    destroyGraph(G);
}
