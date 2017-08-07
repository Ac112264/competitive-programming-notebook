#include "graph.cpp"
#include "graph_io.cpp"
#include "toposort.cpp"

int main() {
	#include "../fast_io.hpp"

	Graph graph = Graph::read_graph(cin);
	Graph graph_t = graph.transpose();

	cout << "Original graph: " << '\n';
	graph.print();
	cout << '\n';

	cout << "Inverse graph: " << '\n';
	graph_t.print();
	cout << '\n';

	graph.toposort();
}
