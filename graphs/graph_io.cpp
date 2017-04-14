#ifndef GRAPH_IO_H
#define GRAPH_IO_H

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
	out << "Adjacency list: " << endl;

	for (auto it : map) {
		string vertex = it.first;
		int vertex_i = it.second;

		out << vertex << ": ";

		for (auto edge_i : edges[vertex_i]) {
			out << rev_map[edge_i] << " ";
		}

		out << "(indegree " << in_degs[vertex_i] << ", ";
		out << "outdegree " << out_degs[vertex_i] << ")";

		out << endl;
	}
}

#endif
