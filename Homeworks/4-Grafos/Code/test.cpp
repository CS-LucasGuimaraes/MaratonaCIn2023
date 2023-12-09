#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int u, v, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
  return a.weight < b.weight;
}

int findSet(vector<int>& parent, int u) {
    if (parent[u] == -1) {
        return u;
    }
    return parent[u] = findSet(parent, parent[u]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
  int uSet = findSet(parent, u);
  int vSet = findSet(parent, v);

  if (rank[uSet] > rank[vSet]) {
    parent[vSet] = uSet;
  } else if (rank[uSet] < rank[vSet]) {
    parent[uSet] = vSet;
  } else {
    parent[vSet] = uSet;
    ++rank[uSet];
  }
}

vector<tuple<int, int, int>> findMST(vector<Edge>& edges, int n) {
  sort(edges.begin(), edges.end(), compareEdges);

  vector<int> parent(n, -1);
  vector<int> rank(n, 0);

  vector<tuple<int, int, int>> mst;

  for (auto& edge : edges) {
    int u = edge.u;
    int v = edge.v;

    if (findSet(parent, u) != findSet(parent, v)) {
        mst.push_back({u, v, edge.weight});
        unionSet(parent, rank, u, v);
        }
    }

  return mst;
}


// void findAllMSTs(vector<Edge>& edges, int n) {
//   vector<bool> visited(edges.size(), false);
//   vector<tuple<int, int, int>> currentMST;

//   function<void(int)> backtrack = [&](int u) {
//     for (int i = 0; i < edges.size(); ++i) {
//       if (!visited[i] && (edges[i].u == u || edges[i].v == u)) {
//         visited[i] = true;
//         currentMST.push_back(edges[i]);

//         if (currentMST.size() == n - 1) {
//           // Found one MST
//           for (auto& edge : currentMST) {
//             cout << get(edge) << " -- " << get(edge) << " (" << get(edge) << ")" << endl;
//           }
//           cout << endl;
//         } else {
//           int v = edges[i].u == u ? edges[i].v : edges[i].u;
//           backtrack(v);
//         }

//         currentMST.pop_back();
//         visited[i] = false;
//       }
//     }
//   };

//   backtrack(0);
// }

int main() {
  vector<Edge> edges;

  int vertex, n;

    cin >> vertex >> n;

    int a, b, weight;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> weight;

        edges.push_back({a, b, weight});
    }

    vector<tuple<int, int, int>> mst = findMST(edges, n);

    cout << "Minimum Spanning Tree:" << endl;
    for (auto& edge : mst) {
        cout << get<0>(edge) << " -- " << get<1>(edge) << " (" << get<2>(edge) << ")" << endl;
        cout << edge.0;
  }


//   cout << endl << "All Possible MSTs:" << endl;

//   findAllMSTs(edges, n);

  return 0;
}
