#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// It's a undirected weighted graph
template<typename T, typename T1>
class Graph {
public:
	unordered_map<T, list<pair<T, T1>>> graph;
	int size = 0;
	void print() {
		for (auto itr = graph.begin(); itr != graph.end(); itr++) {
			cout << itr->first << ": ";
			for (auto ele : itr->second) {
				cout << "(" << ele.first << "," << ele.second << "), ";
			}
			cout << "\n";
		}
	}

	void addEdge(T x, T y, T1 wieght) {
		if (graph.find(x) == graph.end()) {size++;}
		if (graph.find(y) == graph.end()) {size++;}
		graph[x].push_back({y, wieght});
		graph[y].push_back({x, wieght});
	}
// I have assumed all the nodes are from 1 to N;
	map<T, T> dijkstra(T start, T end, T1 inf) {
		priority_queue<pair<T1, T>, vector<pair<T1, T>>, greater<pair<T1, T>>> q;
		// Setting every distance to infinty;
		vector<T1> dist(26, inf);
		dist[start - 'a'] = 0;
		q.push({0, start});
		map<T, bool> visited;
		map<T, T> parent;
		parent[start] = start;

		while (!q.empty()) {
			T curr;
			T1 wieght;
			tie(wieght, curr) = q.top();
			q.pop();
			if (curr == end) {
				return parent;
			}
			visited[curr] = 1;
			for (auto ele : graph[curr]) {
				if (visited[ele.first]) {continue;}
				if (dist[ele.first - 'a'] > wieght + ele.second) {
					parent[ele.first] = curr;
					dist[ele.first - 'a'] = wieght + ele.second;
					q.push({wieght + ele.second, ele.first});
				}
			}
		}
		return parent;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Graph<char, int> g;

	int t;
	cin >> t;
	while (t--) {
		char a, b; int c;
		cin >> a >> b >> c;
		// cout << a << b << c << "\n";
		g.addEdge(a, b, c);
	}

	// g.print();

	char start = 'a';
	char end = 't';

	map<char, char> parent = g.dijkstra(start, end, INT_MAX);

	if (parent.find(end) == parent.end()) {
		cout << "End not found";
		return 0;
	}

	while (end != start && end != parent[end]) {
		cout << end << ",";
		end = parent[end];
	}

	cout << start;

}