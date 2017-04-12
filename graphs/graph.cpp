#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <forward_list>
#include <queue>

using namespace std;

// Graph using an adjacency list
class Graph {
private:
	int V;
	int E;
	int curr_size;

	unordered_map<string, int> map; // hashmap of vertex name -> index
	string* rev_map; // reverse mapping of vertex name -> index
	forward_list<int>* edges; // array of linked lists
	int* in_degs; // indegrees
	int* out_degs; // outdegrees

public:
	// Constructor
	Graph(int V, int E) :
		V(V), E(E), curr_size(0),
		map(V) {
			rev_map = new string[V];
			edges = new forward_list<int>[E];
			in_degs = new int[V];
			out_degs = new int[V];

			// Set to zero
			for (int i = 0; i < V; i++) {
				in_degs[i] = out_degs[i] = 0;
			}
	}

	// Destructor is not explicitly defined.
	// If it were, it would delete rev_map, edges, in_degs, out_degs
	// and the rule of three/five would have to be followed

	// Add vertex
	void add_vertex(string v) {
		if (map.count(v) == 0) { // not found
			map[v] = curr_size;
			rev_map[curr_size] = v;
			curr_size++;
			edges[map[v]] = forward_list<int>();
		}
	}

	// Add edge
	void add_edge(string from, string to) {
		edges[map[from]].push_front(map[to]);
		out_degs[map[from]]++;
		in_degs[map[to]]++;
	}

	// Return inverse graph
	// TODO
	/*
	Graph transpose() {
		Graph inverse(V, E);
		return inverse;
	}
	*/

	void toposort();
	void dfs();
	void bfs();

	static Graph read_graph(istream& in = cin);
	void print(ostream& out = cout) const;

};

#endif
