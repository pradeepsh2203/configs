#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T, typename T1>
class wtGraph {
public:
	vector<tuple<T, T, T1>> edges;
	int V;//The number of nodes in the graph;

	wtGraph(int x) {
		V = x;
	}

	void addEdge(T x, T y, T1 wieght) {
		edges.push_back({x, y, wieght});
	}

	vector<T1> bf(T start, T1 inf) {
		vector<T1>dist(V, inf);
		dist[start] = 0;
		for (int i = 0; i < V - 1 ; i++) {
			// cout << i << "---";
			for (tuple<T, T, T1> e : edges) {
				T a; T b; T1 wieght;
				tie(a, b, wieght) = e;
				if (dist[a] + wieght < dist[b]) {
					// cout << "Yes\n";
					dist[b] = dist[a] + wieght;
				}
			}
			// cout << "\n";
		}

		return dist;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	wtGraph<char, int> g(n);

	int t;
	cin >> t;
	while (t--) {
		int a, b; int c;
		cin >> a >> b >> c;
		g.addEdge(a, b, c);
	}

	int inf = 1e7;
	int start = 0;

	vector<int> ans = g.bf(start, inf);

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ", ";
	}
}