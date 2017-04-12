#include "graph.cpp"

/*
 * Input:
 * First line is number of vertices and number of edges (|V|, |E|)
 * Second line is list of edges E_0, E_1, E_2, ..., E_|V|
 * Next |E| lines represent an edge from u to v (u v)
 */

Graph Graph::read_graph(istream& in) {
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

	return graph;
}

void Graph::print(ostream& out) const {
	out << "Graph G(" << V << ", " << E << ")" << endl;

	for (auto it : map) {
		out << it.first << ": ";

		for (auto list_it : edges[it.second]) {
			// out << rev_map[list_it] << " ";
			out << list_it << " ";
		}

		out << "(indegree " << in_degs[it.second] << ", ";
		out << "outdegree " << out_degs[it.second] << ")";

		out << endl;
	}
}

