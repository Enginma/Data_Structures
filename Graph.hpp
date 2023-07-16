
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "GraphBase.hpp"
#include <iterator>
#include <queue>
#include <limits>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

/*
We declare the class called edge to keep in track of the current edge and adjacent edge and 
the weight of the edge for later calculations. 
*/

class Edge {
private:
	// Current edge.
	string edge_a; 

	// Adjacent edge.
	string edge_b; 

	// An edge's weight value.
	unsigned long weight; 
	
public:
	// Give access to the graph class in graph.hpp.
	friend class Graph; 

	// Constructor to set up an edge. 
	Edge(string a = "", string b = "", unsigned long w = 0) {
		edge_a = a;
		edge_b = b;
		weight = w;
	}

	// Destructor for the Edge class but it doesn't do anything since it doesn't allocate any memory. 
	~Edge() {}  
};



//The vertex class is keeping in track of the vertexes and the shortest paths from each vertex to another.


class Vertex{
private:
	// The vertex variable.
	string vertex; 

	// Stores the minimum distance between two edges.
	unsigned long minimum_distance; 

	// Stores the shortest edges path in the vector. 
	vector<string> shortest_path; 

	// Returns true if the given vertex variable is there in the path. 
	bool seen; 

public:
	//Allow graph class from graph.hpp to gain access to Vertex class. 
	friend class Graph;

	// The constructor and deconstructor Vertex class. 
	Vertex() { vertex = ""; }
	~Vertex() {}
};

// The graph class with graphbase defined functions. 

class Graph : public GraphBase {
private:
	// Double-end queue to keep in track of the vertexes, double-end queue make insertion and deletion easier. 
	deque<Vertex*> vertexes; 

	// Double-end queue to keep in track of the edges and their corresponding weight. 
	deque<Edge*> edges;

	// Keeps the shortest distance after each vertex being reached. 
	unsigned long shortest_distance = 0; 

	// Gets the index of the minimum distance vertex. 
	int minimum_vertex_idx = 0; 

	// The minimum element a a vertex. 
	string minimum_element = ""; 

	// Priority queue to store wighted vertxes by distance from starting vertex in ascending order. 
	priority_queue<pair<unsigned long, string>, vector<pair<unsigned long, string>>, greater<pair<unsigned long, string>>> list_of_paths;

protected:
	// Helper functions in the program. 

	// Start traversing the path base on the given vertex node position. 
	void path_start(string a); 

	//*Make the path using the priority queue.
	void construct_path(string start);

	// Get the minimum index for a vertex.
	void find_minimum_vertex_idx(string& minimum_element);

	//  /*put distances in the string*/
	void get_minimum_distance(string element); 

	// Make a path from one vertex to another. 
	void lay_path(string end, vector<string>& path);

	// Reset the path. 
	void path_reset(); 

public:

	// Constructor and destructor. 
	Graph() {} 
	~Graph(); 

	// Add a new vertex to the graph with a given lable. 
	void addVertex(string label);

	// Removes the vertex with the given lable from the graph. 
	void removeVertex(string label);

	// Adds an edge value between two vertexes lable1 and lable2. Weight is the value. 
	void addEdge(string label1, string label2, unsigned long weight);

	// Remove the edge between two vertexes. 
	void removeEdge(string label1, string label2);

	// Calculate the shortest path between startLable vertex and endLable vertex using Dijkstra's Algorithm. 
	unsigned long shortestPath(string startLabel, string endLabel, vector<string> &path);
};
#endif 