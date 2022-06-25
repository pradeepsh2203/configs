#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// It's a directed graph.........
template<typename T>
class Graph {
private:
	map<T, list<T>> graph;
public:
	void addEdge(T x, T y) {
		graph[x].push_back(y);
	}
// This dfs function return the number of nodes reachable from
// the current node including itself.
	int dfs(T start, map<T, bool> &visited) {
		int child = 1;
		visited[start] = 1;

		for (T nbr : graph[start]) {
			if (visited[nbr] == 0) {
				child += dfs(nbr, visited);
			}
		}

		return child;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph<int> g = Graph<int>();

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 3);
	g.addEdge(3, 2);
	g.addEdge(4, 5);

	map<int, bool> visited;

	cout << "The child of 4 are " << g.dfs(4, visited) - 1;

}