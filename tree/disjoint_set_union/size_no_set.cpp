

#include <bits/stdc++.h>
using namespace std;

// https://en.wikipedia.org/wiki/Disjoint-set_data_structure
// https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
// https://cp-algorithms.com/data_structures/disjoint_set_union.html

/// @brief Disjoint Set Uninon Data Structure (Union by size, all nodes are by default set)
class DSU {
    vector<int> parent;
    vector<int> size;
   public:
    /// @brief DSU Initialization with each node being a set
    /// @param n number of nodes
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

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
        x = findSet(x);
        y = findSet(y);

        if (x == y) {
            return;
        }

        if (size[x] < size[y]) {
            swap(x, y);
        }

        parent[y] = x;

        if (size[x] == size[y]) {
            size[x] += size[y];
        }
        return;
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
