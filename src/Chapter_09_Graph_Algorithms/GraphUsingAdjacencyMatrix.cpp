/*
   Author : Shivam Chauhan
   Date   : March 28 , 2019
   Graph using Adjacency Matrix
*/
#include <bits/stdc++.h>
using namespace std ;
class Graph
{
public :
  int V ;
  int *adj_mat; 
  Graph(int V);
  void add_edge( int u , int v);
  void print_graph();
};

Graph::Graph( int V )
{
  this -> V = V ;
  /*
    Using 1-D array as 2-D in place of arr[i][j] -> arr[ i * row_size + j ] is used
  */
  adj_mat = new int[V*V](); // default initialise array with 0 , don't use (0)

}

void Graph::add_edge( int u , int v) 
{
  adj_mat[u * V + v] = 1 ;
}

void Graph::print_graph()
{
  cout << "The Graph formed is : " << endl ;
  for ( int i = 0 ; i < this -> V ; i++ )
  {
    for ( int j = 0 ; j < this -> V ; j++ )
    {
      cout << this -> adj_mat[i*V+j] << "  " ;
    }
    cout << endl ;
  }
}

int main ()
{
    Graph graph(4);
    graph.add_edge(0, 1); 
    graph.add_edge(0, 2); 
    graph.add_edge(1, 2); 
    graph.add_edge(2, 0); 
    graph.add_edge(2, 3); 
    graph.add_edge(3, 3);
    graph.print_graph();
    return 0;
}
