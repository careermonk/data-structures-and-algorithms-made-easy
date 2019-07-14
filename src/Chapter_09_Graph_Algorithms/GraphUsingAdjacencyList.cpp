/*
   Author : Shivam Chauhan
   Date   : March 28 , 2019
   Graph using Adjacency List
*/
#include <bits/stdc++.h>
using namespace std ;
class Graph
{
public :
	int V ;
	list<int> *adj ;
	Graph(int V);
	void add_edge( int u , int v);
	void print_graph();
};

Graph::Graph( int V )
{
	this -> V = V ;
	this -> adj = new list <int> [V] ; 
}

void Graph::add_edge( int u , int v) 
{
	this -> adj[u].push_back(v);
}

void Graph::print_graph()
{
	cout << "The Graph formed is : " << endl ;
	for ( int i = 0 ; i < this -> V ; i++ )
	{
		cout << i << " -> " ; 
		for ( auto it = this -> adj[i].begin() ; it != this -> adj[i].end() ; it++ )
		{
			cout << *it << " " ;
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
