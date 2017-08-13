#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

// Graph implemeted using an adjacency list
struct Graph {
	const int V;
	const int E;
	int curr_size;

	map<string, int> map; // hashmap of vertex name -> index
	vector<string> rev_map; // reverse mapping of vertex name -> index
	vector<list<int>> edges; // array of linked lists
	vector<int> in_degs; // indegrees array
	vector<int> out_degs; // outdegrees array

public:
	// Constructor
	Graph(const int V, const int E) :
		V(V), E(E), curr_size(0),
		map(),
		rev_map(V),
		edges(E),
		in_degs(V), out_degs(V)
	{
		// Set to zero
		fill_n(in_degs.begin(), V, 0);
		fill_n(out_degs.begin(), V, 0);
	}

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
		for (auto& it : map) {
			graph_t.add_vertex(it.first);
		}

		// Add edges
		for (auto& it : map) {
			int vertex_i = it.second;

			// Loop over edges
			for (auto& edge_i : edges[vertex_i]) {
				graph_t.add_edge(rev_map[edge_i], rev_map[vertex_i]);
			}
		}

		return graph_t;
	}

	// Return a copy of the graph
	Graph copy() const {
		Graph graph_copy(V, E);

		graph_copy.map = map;
		graph_copy.rev_map = rev_map;
		graph_copy.edges = edges;
		graph_copy.in_degs = in_degs;
		graph_copy.out_degs = out_degs;

		return graph_copy;
	}

	void toposort();

	void dijkstra(const int source);

	void dfs(int);
	void bfs(int);

	void print();
};

#endif // GRAPH_CPP
