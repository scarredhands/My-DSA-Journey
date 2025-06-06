#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    pair<int, int> first = {-1, -1}, last = {-1, -1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'A') first = {i, j};
            if (a[i][j] == 'B') last = {i, j};
        }
    }

    if (first == make_pair(-1, -1) || last == make_pair(-1, -1)) {
        cout << "NO" << endl;
        return 0;
    }

    queue<pair<int, pair<int, int>>> pq;
    pq.push({0, first});
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[first.first][first.second] = 1;
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    int ans = INT_MAX;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!pq.empty()) {
        auto [steps, cell] = pq.front();
        int r = cell.first, c = cell.second;
        pq.pop();

        if (r == last.first && c == last.second) {
            ans = steps;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nrow = r + drow[i], ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 &&
                (a[nrow][ncol] == '.' || a[nrow][ncol] == 'B')) {
                pq.push({steps + 1, {nrow, ncol}});
                vis[nrow][ncol] = 1;
                parent[nrow][ncol] = {r, c};
            }
        }
    }

    int r = last.first, c = last.second;

    if (ans != INT_MAX) {
        string s = "";
        while (parent[r][c] != make_pair(-1, -1)) {
            int pr = parent[r][c].first, pc = parent[r][c].second;
            if (r == pr + 1) s += 'D';
            else if (r == pr - 1) s += 'U';
            else if (c == pc + 1) s += 'R';
            else if (c == pc - 1) s += 'L';
            r = pr;
            c = pc;
        }
        reverse(s.begin(), s.end());
        cout << "YES" << endl;
        cout << ans << endl;
        cout << s << endl;
    } else {
        cout << "NO" << endl;
    }
}

