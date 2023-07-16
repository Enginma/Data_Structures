
#include "Graph.hpp"

//Destructor to dismantle the graph
Graph::~Graph()
{

	// clear vertexes
	for(auto& x : vertexes) { 
		delete x; 
	}
	// clear edges
	for(auto& x : edges) { 
		delete x; 
	}

    vertexes.clear();
	edges.clear();
}


// Creates and adds a vertex to the graph with a element. No two vertexes have the same element.
void Graph::addVertex(string label)
{

	// If the element is empty then throw an exception and return. 
	if (label.empty())
		throw ("The string are empty!\n");


	// Create new vertex node variable. 
	Vertex *new_vertex = new Vertex;

	// Setting initial distance to infinite with numeric_limits class from standard library.
	new_vertex->vertex = label;
	new_vertex->minimum_distance = numeric_limits<unsigned long>::max();

	// Set shortest path to nothing and boolean function to false until seen. 
	new_vertex->shortest_path = { "" };
	new_vertex->seen = false;

	// Push back in the double end queue with vertex.
	vertexes.push_back(new_vertex); 
}


// Removes the vertex with element from the graph and the edges between that vertex and
// the other vertices of the graph. 
void Graph::removeVertex(string label)
{

	// Throws the exception if the given a is empty. 
	if (label.empty())
		throw ("The string are empty!\n");

	// We first set ver_start to the beginning variable, and it will go until it reaches the end. 
	for (deque<Vertex*>::iterator ver_start = vertexes.begin(); ver_start != vertexes.end(); ++ver_start) {
		// We check if the current vertex is equal the the given a and if it is we erase it to delete it. 
		if ((*ver_start)->vertex == label) {
			vertexes.erase(ver_start);
		}
	}

	// We do the same for the edges as we do for the vertex. 
	for (deque<Edge*>::iterator edge_start = edges.begin(); edge_start != edges.end(); ++edge_start) {
		// We check both edges and as long as one of them is equaling to the a we delete the edge. 
		if (((*edge_start)->edge_a == label) || ((*edge_start)->edge_b == label)) {
			edges.erase(edge_start);
		}
	}
}


// Adds an edge of value weight to the graph between the vertex with "a" and the vertex with "b".
void Graph::addEdge(string label1, string label2, unsigned long weight)
{
	if (label1.empty()) {
		throw ("The string are empty!\n");
	}
	else if (label2.empty()) {
		throw ("The string are empty!\n");
	}
	else if (label1.empty() && label2.empty()) {
		throw ("The strings are empty!\n");
	}

	//Add an edge between a and b. 
	Edge *new_edge1 = new Edge(label1, label2, weight);
	Edge* new_edge2 = new Edge(label2, label1, weight);

	edges.push_back(new_edge1);
	edges.push_back(new_edge2);
}



// Removes the edge from the graph between the vertex equals to a and the vertex equals to b.
void Graph::removeEdge(string label1, string label2)
{
	if (label1.empty()) {
		throw ("The string are empty!\n");
	}
	else if (label2.empty()) {
		throw ("The string are empty!\n");
	}
	else if (label1.empty() && label2.empty()) {
		throw ("The strings are empty!\n");
	}

	// We will remove the edge if both element match with a and b.

	// We set an edge variable to the first and it will go through once it finds the edge with both a and b as its edges and then
	// we delete it. 
	for (deque<Edge*>::iterator edge_start = edges.begin(); edge_start != edges.end(); ++edge_start) {
		if (((*edge_start)->edge_a == label1) && ((*edge_start)->edge_b == label2)) {
			edges.erase(edge_start);
		}
	}
}


//	Find the shortest path between the vertex with start and the vertex with end using greedy Dijkstra's Algorithm. 

unsigned long Graph::shortestPath(string startLabel, string endLabel, vector<string>& path)
{

	//Check if the given vertex is empty and throw exceptions. 
	if (startLabel.empty()) {
		throw ("The string are empty!\n");
	}
	else if (endLabel.empty()) {
		throw ("The string are empty!\n");
	}
	else if (startLabel.empty() && endLabel.empty()) {
		throw ("The strings are empty!\n");
	}

	// Select the start node. 
	path_start(startLabel);

	// Makes the list in the priority queue in ascending order of nodes by their distances (using edge/weight))
	construct_path(startLabel);

	// Lay path function finds the shortest distance in the priority queue from vector A to vector B. 
	lay_path(endLabel, path); 

	// Clears the vertex container by resetting everything to its default values.
	path_reset(); 

	// Returns the shortest distance. 
	return shortest_distance;
}


// We use path start function to do the setup of the traversal with the vertex class.  
void Graph::path_start(string a){

	// We first set start variable to the beginning and we find the node that is equal to "a" and that will be our start point. 
	for (deque<Vertex*>::iterator start = vertexes.begin(); start != vertexes.end(); ++start) {
		
		// Once we find the desired vertex node, we set the minimum distance to 0 and we clear the path in case if there
		// are left over values and we push "a" which is the value into the end.
		if ((*start)->vertex == a) {
			(*start)->minimum_distance = 0;
			(*start)->shortest_path.clear();
			(*start)->shortest_path.push_back(a);
		}
	}

	// Adds a new path to the container in the graphs class in Graph.hpp. Make_pair function combines 0 and a into one single object. 
	list_of_paths.push(make_pair(0, a));
}



// This function finds the minimum index of the given element. 
void Graph::find_minimum_vertex_idx(string& minimum_element){
	// Initialize the index to 0. 
	int vertex_idx = 0;

	// We use a start variable as the beginning and the for loop will run until it reaches the end. 
	for (deque<Vertex*>::iterator start = vertexes.begin(); start != vertexes.end(); ++start) {

		// Once we find the element that matches the vertex, we get its location index. 
		if ((*start)->vertex == minimum_element) {
			minimum_vertex_idx = vertex_idx;
		}
		// Other wise we implement the index by 1 until we find it. 
		else { 
			++vertex_idx;
		}
	}
}


// Using breadth first traversal, traverse through edge and vertex containers and push possible paths into the priority queue.
void Graph::get_minimum_distance(string element){

	// Traverse through edges until we reach the end. 
	for (deque<Edge*>::iterator edge_start = edges.begin(); edge_start != edges.end(); ++edge_start) {

		// If edge_a of the element is the minimum element 
		if ((*edge_start)->edge_a == minimum_element) { 

			// Start iterating over vertex adjacent to that vector from above. 
			for (deque<Vertex*>::iterator ver_start = vertexes.begin(); ver_start != vertexes.end(); ++ver_start) {

				// If going backawrd has a smaller weight and has been not visited
				if (((*edge_start)->edge_b == (*ver_start)->vertex) &&
					((vertexes.at(minimum_vertex_idx)->minimum_distance + (*edge_start)->weight) < (*ver_start)->minimum_distance) &&
					((*ver_start)->seen == false)){

					// Store the vertex's distace + weight. 
					(*ver_start)->minimum_distance = vertexes.at(minimum_vertex_idx)->minimum_distance + (*edge_start)->weight;

					// If the minimum element is equal to the given element, we clear the path and push the given element to the queue. 
					if (minimum_element == element) {
						(*ver_start)->shortest_path.clear();
						(*ver_start)->shortest_path.push_back(element);
					}

					// If the minimum_element is not the element the function received, we push the minimum index's vertex to the queue. 
					else if (minimum_element != element) { 
						(*ver_start)->shortest_path.clear();
						(*ver_start)->shortest_path = vertexes.at(minimum_vertex_idx)->shortest_path;
						(*ver_start)->shortest_path.push_back(vertexes.at(minimum_vertex_idx)->vertex);
					}
					//Make a pair that contains the minimum distance and vertex at this position and push into the priority queue. 
					list_of_paths.push(make_pair((*ver_start)->minimum_distance, (*ver_start)->vertex));
				}
			}
		}
	}
}


// Visit from vertex A to B on all possible paths. 
void Graph::construct_path(string start){

	while (!list_of_paths.empty()) {

		// We set the second element from the top of the queue to be the minimum element. 
		minimum_element = list_of_paths.top().second; 

		// Removes the top element.
		list_of_paths.pop();

		// Gets the index of the minimum element. 
		find_minimum_vertex_idx(minimum_element);

		// Gets the corresponding weight to the given element. 
		get_minimum_distance(start); 

		// Sets the boolean value at minimum index to true. 
		vertexes.at(minimum_vertex_idx)->seen = true;
	}
}


// Put the nodes in the vector with minimum weight and get shortest distances from vector A to B. 
void Graph::lay_path(string end, vector<string>& path){

	for (deque<Vertex*>::iterator ver_start = vertexes.begin(); ver_start != vertexes.end(); ++ver_start) {

		// When our start variable is the end variable, we get the minimum distance and update our shortest distance variable. 
		// We also need to put the least weight in the string and update the path variable with the minimum path. 
		if (end == (*ver_start)->vertex) { 
			shortest_distance = (*ver_start)->minimum_distance; 
			(*ver_start)->shortest_path.push_back(end); 
			path = (*ver_start)->shortest_path; 
		}
	}

}
// Restore all of the vertexes of the current graph to its default value.
void Graph::path_reset(){
	// Set the distance back to infinite.
	for (deque<Vertex*>::iterator ver_start = vertexes.begin(); ver_start != vertexes.end(); ++ver_start) {
		(*ver_start)->minimum_distance = numeric_limits<unsigned long>::max();;
		(*ver_start)->shortest_path = { "" };
		(*ver_start)->seen = false;
	}
}