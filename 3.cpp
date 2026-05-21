#include <bits/stdc++.h>
#define endl "\n"
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define sep << " " <<
#define space << " "
#define tc int TESTCASE; cin >> TESTCASE; while(TESTCASE--)
#define pushb push_back
#define popb pop_back
#define milestone cout << "tes";
#define YES cout << "YES\n"
#define MAYBE cout << "MAYBE\n"
#define NO cout << "NO\n"
#define pii pair<int, int>
using namespace std;

void solve()
{
    int n, m, y, x;
    int cnt = 0;
    queue<pii> q;
    cin >> n >> m >> y >> x;
    y--; x--;
    vector<vector<ll>> arr(n, vector<ll>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    q.push({y, x});
    vis[y][x] = true;
    pii directions[] = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };
    while(!q.empty()) { // bfs
        auto top = q.front();
        q.pop();
        for(auto dir:directions) {
            auto ny = top.first + dir.first;
            auto nx = top.second + dir.second;
            if(ny < 0 || ny >= n) {
                continue;
            } else if (nx < 0 || nx >= m) {
                continue;
            }
            if(vis[ny][nx]) {
                continue;
            }
            if(arr[ny][nx] <= arr[top.first][top.second]) {
                vis[ny][nx] = true;
                q.push({ny, nx});
            }
        }
        cnt++;
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(NULL);
    solve();
    return 0;
}
