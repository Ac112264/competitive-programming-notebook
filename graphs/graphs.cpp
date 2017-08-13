#include <iostream>
#include <stdio.h>
#include "graph.cpp"
#include "toposort.cpp"

/* Input:
 * First line is number of vertices and number of edges (|V|, |E|)
 * Second line is list of edges E_0, E_1, E_2, ..., E_|V|
 * Next |E| lines represent an edge from u to v (u v)
 */
Graph read_graph() {
	// Read V, E
	int V, E;
	scanf("%i%i", &V, &E);

	Graph graph(V, E);

	// Read vertices
	for (int i = 0; i < V; i++) {
		string v;
		cin >> v;

		graph.add_vertex(v);
		// cerr << "Adding vertex " << v << '\n';
	}

	// Read edges
	for (int i = 0; i < E; i++) {
		string from, to;
		cin >> from >> to;

		graph.add_edge(from, to);
		// cerr << "Adding edge from " << from << " to " << to << '\n';
	}

	return graph;
}

void Graph::print() {
	printf("Graph G(%i, %i)\n", V, E);
	printf("Adjacency list:\n");

	// Loop through vertices
	for (auto it : map) {
		const char* vertex = it.first.c_str();
		int vertex_i = it.second;

		printf("%s: ", vertex);

		// Loop through edges
		for (auto edge_i : edges[vertex_i]) {
			const char* edge = rev_map[edge_i].c_str();
			printf("%s ", edge);
		}

		printf("(indegree %i, outdegree %i)\n",
				in_degs[vertex_i],
				out_degs[vertex_i]);
	}
}

int main() {
	Graph graph = read_graph();
	Graph graph_t = graph.transpose();

	printf("Original graph:\n");
	graph.print();
	printf("\n");

	printf("Inverse graph:\n");
	graph_t.print();
	printf("\n");

	graph.toposort();
}
