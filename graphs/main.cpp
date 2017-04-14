#include "graph.cpp"
#include "graph_io.cpp"
#include "toposort.cpp"

// Return transpose graph
Graph Graph::transpose() {
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

int main() {
	Graph graph = Graph::read_graph(cin);
	Graph graph_t = graph.transpose();

	cout << "Original graph: " << endl;
	graph.print();
	cout << endl;

	cout << "Inverse graph: " << endl;
	graph_t.print();
	cout << endl;

	graph.toposort();
}
