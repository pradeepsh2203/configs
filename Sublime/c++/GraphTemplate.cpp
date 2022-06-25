#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T, typename T1>
class wtGraph {
public:
	map<T, list<pair<T, T1>>> graph;
	void addEdge(T x, T y, T1 weight, bool bidir) {
		graph[x].push_back({y, weight});
		if (bidir) graph[y].push_back({x, weight});
	}

};

template<typename T>
class Graph {
public:
	map<T, list<T>> graph;
	void addEdge(T x, T y) {
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	void addEdge(T x, T y, bool bidir) {
		graph[x].push_back(y);
		if (bidir) graph[y].push_back(x);
	}
	bool dfs_helper(T node, map<T, int> &visited, T end) {
		bool cond = false;
		for (T nbr : graph[node]) {
			if (nbr == end) {
				return true;
			}
			if (!visited[nbr]) {
				//add the neigbhour to the visited array;
				visited[nbr] = 1;
				cond = dfs_helper(nbr, visited, end);
			}
		}
		return cond;
	}
	void dfs(T src) {
		map<T, int> visited;
		dfs_helper(src, visited);
	}

	vector<T> bfs(T src, T end) {
		map<T, T> parent;
		map<T, bool> visited;
		queue<T> q;
		q.push(src);
		visited[src] = 1;
		parent[src] = src;

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			for (T nbr : graph[node]) {
				if (nbr == end) {
					parent[nbr] = node;
					break;
				}
				if (visited[nbr] == 0) {
					q.push(nbr);
					visited[nbr] = 1;
					parent[nbr] = node;
				}
			}
			if (visited[end] == 1) {
				break;
			}

		}
		vector<T> answ;
		T node = end;
		while (node != src) {
			answ.push_back(node);
			node = parent[node];
		}
		answ.push_back(src);
		return answ;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*---code---*/

}