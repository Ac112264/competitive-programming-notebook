#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

// Graph implemeted using an adjacency list
struct Graph {
	const int V;
	const int E;
	int curr_size;

	map<string, int> map; // hashmap of vertex name -> index
	string* rev_map; // reverse mapping of vertex name -> index
	list<int>* edges; // array of linked lists
	int* in_degs; // indegrees
	int* out_degs; // outdegrees

public:
	// Constructor
	Graph(const int V, const int E) :
		V(V), E(E), curr_size(0),
		// map(V)
		map() {
			rev_map = new string[V];
			edges = new list<int>[E];
			in_degs = new int[V];
			out_degs = new int[V];

			// Set to zero
			fill_n(in_degs, V, 0);
			fill_n(out_degs, V, 0);
	}

	// Destructor is not explicitly defined.
	// If it were, it would delete rev_map, edges, in_degs, out_degs
	// and the rule of three/five would have to be followed

	// Add vertex
	void add_vertex(const string v) {
		if (map.count(v) == 0) { // not found
			map[v] = curr_size;
			rev_map[curr_size] = v;
			curr_size++;
			edges[map[v]] = list<int>();
		}
	}

	// Add edge
	void add_edge(const string from, const string to) {
		edges[map[from]].push_front(map[to]);
		out_degs[map[from]]++;
		in_degs[map[to]]++;
	}

	// Return transpose graph
	Graph transpose() const {
		Graph graph_t(V, E);

		// Add vertices
		for (auto it : map) {
			graph_t.add_vertex(it.first);
		}

		// Add edges
		for (auto it : map) {
			int vertex_i = it.second;

			// Loop over edges
			for (auto edge_i : edges[vertex_i]) {
				graph_t.add_edge(rev_map[edge_i], rev_map[vertex_i]);
			}
		}

		return graph_t;
	}

	void toposort();

	void dijkstra(const int source);

	void dfs(int);
	void bfs(int);

	static Graph read_graph(istream& in = cin);
	void print(ostream& out = cout) const;

};

#endif // GRAPH_CPP
