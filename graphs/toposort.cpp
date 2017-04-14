#include "graph.cpp"
#include "graph_io.cpp"

#include <queue>

// Topological sort
void Graph::toposort() {
	queue<int> q; // candidates with indegree 0
	int counter = 0;
	int sorted[V];

	// for each vertex v
	for (int v = 0; v < V; v++) {
		if (in_degs[v] == 0) { q.push(v); } // enqueue
	}

	while (!q.empty()) {
		int v = q.front(); q.pop(); // dequeue
		sorted[counter++] = v;

		// for each vertex w adjacent to v
		for (int w : edges[v])  {
			if (--in_degs[w] == 0) { // remove edge (v, w) and check if w is a candidate
				q.push(w); // enqueue
			}
		}
	}

	if (counter != V) {
		throw; // Cycle found
	}

	// print topo-sorted vertices
	cout << "Topo sort:" << endl;
	for (int i = 0; i < V; i++) {
		cout << rev_map[sorted[i]] << " ";
	}
}
