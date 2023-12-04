

#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
// https://cp-algorithms.com/data_structures/disjoint_set_union.html

/// @brief Disjoint Set Uninon Data Structure
class DSU {
    vector<int> rank;
    vector<int> parent;

   public:

	// start two ways of DSU Initialization
	#if 1
    /// @brief DSU Initialization with each node being a set
    /// @param n number of nodes
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
	#endif
	#if 0
	/// @brief DSU Initialization with no node is set
    /// @param n number of nodes
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n, -1);
    }

	/// @brief makes given node as set
	/// @param x given node
	void makeSet(int x) {
		parent[x] = x;
	}

	/// @brief tells weather given node is set
	/// @param x given node
	void isSet(int x) {
		return parent[x]!=-1;
	}
	#endif
	// end two ways of DSU Initialization

    /// @brief finds set which set x belongs (represented in terms of root node)
    /// @param x any node in set
    /// @return the set x belongs
    int findSet(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = findSet(parent[x]);
    }

    /// @brief Does union of two sets (if sets are different)
    /// @param x first set (any node in set1)
    /// @param y second set (any node in set2)
    void unionSets(int x, int y) {
        int xset = findSet(x);
        int yset = findSet(y);

        if (xset == yset) return;

        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

/// @brief Driver Code
int main() {
    DSU ds(7);
    ds.unionSets(1, 2);
    ds.unionSets(2, 3);
    ds.unionSets(4, 5);
    ds.unionSets(6, 7);
    ds.unionSets(5, 6);
    // if 3 and 7 same or not
    if (ds.findSet(3) == ds.findSet(7)) {
        cout << "Same\n";
    } else
        cout << "Not same\n";

    ds.unionSets(3, 7);

    if (ds.findSet(3) == ds.findSet(7)) {
        cout << "Same\n";
    } else
        cout << "Not same\n";
    return 0;
}
