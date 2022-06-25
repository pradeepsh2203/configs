#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// It's a undirected graph.........
template<typename T>
class Graph {
private:
	map<T, list<T>> graph;
public:
	void addEdge(T x, T y) {
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
// This bfs function helps to find the shortest path between
// start and end and returns parent map which could be used
// to backtrack and find the path.

// If end is not present in the graph then it would reutrn
// an empty hashmap......
	map<T, T> bfs(T start, T end) {
		queue<T> q;
		map<T, T> parent;
		map<T, bool> visited;
		q.push(start);

		while (!q.empty()) {
			T src = q.front();
			q.pop();
			for (T nbr : graph[src]) {
				if (visited[nbr] == 0) {
					visited[nbr] = 1;
					parent[nbr] = src;
					q.push(nbr);
				}
				if (nbr == end) {
					return parent;
				}
			}
		}

		return map<T, T> ();
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	Graph<int> g = Graph<int>();
	cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		g.addEdge(a, b);
	}
	int start = 8;
	int end = 4;

	map<int, int> parent = g.bfs(start, end);

	cout << end << ", ";

	while (end != start) {
		cout << parent[end] << ", ";
		end = parent[end];
	}

}