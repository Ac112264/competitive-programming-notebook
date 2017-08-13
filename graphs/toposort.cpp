#include "graph.cpp"
#include <queue>

/* Topological sort
 * This function is destructive: it modifies in_degs and out_degs.
 * Make a copy if you wish to preserve them.
 */
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
		printf("Cycle found\n");
		return;
	}

	// print topo-sorted vertices
	printf("Topo sort:\n");
	for (int i = 0; i < V; i++) {
		const char* vertex = rev_map[sorted[i]].c_str();
		printf("%s ", vertex);
	}
	printf("\n");
}
