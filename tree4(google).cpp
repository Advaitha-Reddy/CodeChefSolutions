#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if (graph[0].size() <= 2) {
        cout << "Tree can stay rooted at the current root! 1\n";
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (graph[i].size() <= 2) {
            cout << "Tree should be rerooted to " << i + 1 << "\n";
            return 0;
        }
    }

    cout << "No valid root exists\n";
    return 0;
}
