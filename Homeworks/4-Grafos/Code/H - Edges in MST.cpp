#include <bits/stdc++.h>

#define iii tuple<int, int, int>

using namespace std;

struct DSU {
    int n;
    vector<int> p, sz;

    DSU(int nodes) {
        n = nodes;
        p.resize(n);
        sz.resize(n,1);
        iota(begin(p), end(p), 0);
    }

    int size(int a) {return sz[root(a)];}

    int root(int a) {return p[a] = (p[a] == a ? a:root(p[a]));}

    bool unite(int a, int b) {
        int ra = root(a), rb = root(b);
        if (ra != rb) {
            if(sz[ra] < sz[rb]) swap(ra,rb);
            p[rb] = ra;
            sz[ra] += sz[rb];
            return 1;
        }
        return 0;
    }
};

int kruskal(int n, vector<iii> &edges) {
    DSU dsu(n);

    // int mst_cost = 0, comp = 0;
    sort(edges.begin(), edges.end());

    for (const auto& edge : edges) {
            // Declare variables before using them
            int vertex1 = get<0>(edge);
            int vertex2 = get<1>(edge);
            int weight = get<2>(edge);

            // Do something with the elements (for example, print them)
            cout << "Edge: " << vertex1 << " - " << vertex2 << ", Weight: " << weight << endl;
        }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int vertex, edge_number;

    cin >> vertex >> edge_number;

    vector<iii> edges(edge_number);

    int a, b, weight;

    for (int i = 0; i < edge_number; i++) {
        cin >> a >> b >> weight;

        edges.push_back({a, b, weight});
    }

    
    


    return 0;
}