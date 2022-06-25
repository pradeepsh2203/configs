#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
class MaxHeap {
private:
	vector<T> tree;
	int size;
	void swap(int ind1, int ind2) {
		tree[ind1] = tree[ind2] + tree[ind1];
		tree[ind2] = tree[ind1] - tree[ind2];
		tree[ind1] = tree[ind1] - tree[ind2];
	}
	void bubble(int index) {
		T curr = tree[index];
// First check if the parent maintains the heap invariant or not.
		if (index != 0) {
			T parent = tree[(index - 1) / 2];
			if (parent < curr) {
				swap(index, (index - 1) / 2);
				bubble((index - 1) / 2);
				return ;
			}
		}
// Then check if the childs maintains the heap invariant or not.
		int big = index;
		if (2 * index + 1 < size && tree[2 * index + 1] > curr) {big = 2 * index + 1;}
		if (2 * index + 2 < size && tree[2 * index + 2] > tree[big]) {big = 2 * index + 2;}

		if (big != index) {
			swap(index, big);
			bubble(big);
		}

	}
public:
	MaxHeap() {
		size = 0;
	}

	void addElement(T val) {
		tree.push_back(val);
		size++;
		bubble(size - 1);
	}

	T peek() {
		return tree[0];
	}

	void poll() {
		// removes the root node;
		tree[0] = tree[size - 1];
		tree.pop_back();
		size--;
		bubble(0);
	}
	bool isMaxHeap(int k) {
		int l = 2 * k + 1;
		int r = 2 * k + 2;

		if (l > size && r > size) { return true;}
		if (l < size && tree[l] > tree[k]) { return false;}
		if (r < size && tree[r] > tree[k]) { return false;}


		return isMaxHeap(l) && isMaxHeap(r);
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	MaxHeap<int> h = MaxHeap<int>();

	h.addElement(10);
	h.addElement(2);
	h.addElement(12);
	h.addElement(6);
	h.addElement(4);
	h.addElement(5);
	h.addElement(4);
	h.addElement(1);
	h.addElement(8);
	h.addElement(7);
	h.addElement(3);
	h.addElement(11);

	cout << "The Heap implementation is ";

	if (h.isMaxHeap(0)) {
		cout << "correct";
	}
	else {
		cout << "incorrect";
	}

}