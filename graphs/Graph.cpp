#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
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
	vector<string> rev_map; // reverse mapping of vertex name -> index
	vector<forward_list<int> > edges; // array of linked lists
	vector<int> in_degs; // indegrees
	vector<int> out_degs; // outdegrees

public:
	// Constructor
	Graph(int V, int E) :
		V(V), E(E), curr_size(0),
		map(V), rev_map(V), edges(E), in_degs(V), out_degs(V) {
	}

	// Add vertex
	void add_vertex(string v) {
		// TODO use static curr_size
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
	Graph inverse() {
		Graph inverse(V, E);
		return inverse;
	}
	*/

	#include "toposort.cpp"
	#include "dfs.cpp"
	#include "bfs.cpp"

	void print() {
		cout << "Graph G(" << V << ", " << E << ")" << endl;

		for (auto it : map) {
			cout << it.first << ": ";

			for (auto list_it : edges[it.second]) {
				cout <<list_it << " ";
			}

			cout << "(indegree " << in_degs[it.second] << ", ";
			cout << "outdegree " << out_degs[it.second] << ")";

			cout << endl;
		}
	}


};

/*
 * Input:
 * First line is number of vertices and number of edges (|V|, |E|)
 * Second line is list of edges E_0, E_1, E_2, ..., E_|V|
 * Next |E| lines represent an edge from u to v (u v)
 */

int main() {
	int V, E;

	// Read V, E
	cin >> V >> E;

	Graph graph(V, E);

	// Read vertices
	for (int i = 0; i < V; i++) {
		string v;
		cin >> v;

		graph.add_vertex(v);
		// cout << "Adding vertex " << v << endl;
	}

	// Read edges
	for (int i = 0; i < E; i++) {
		string from, to;
		cin >> from >> to;


		graph.add_edge(from, to);
		// cout << "Adding edge from " << from << " to " << to << endl;
	}

	graph.print();

	graph.topo_sort();

	return 0;
}
