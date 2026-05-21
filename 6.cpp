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
    tc {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<pii> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        queue<pair<int, pii>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char c;
                cin >> c;
                v[i][j] = c - '0';
                if(v[i][j]) {
                    ans[i][j] = 0;
                    q.push({0, {i, j}});
                }
            }
        }
        while(!q.empty()) {
            auto f = q.front();
            int step = f.first;
            pii front = f.second;
            q.pop();
            for(auto dir:directions) {
                int ny = front.first + dir.first;
                int nx = front.second + dir.second;
                if(ny < 0 || ny >= n) {
                    continue;
                } else if (nx < 0 || nx >= m) {
                    continue;
                }
                if (ans[ny][nx] != -1) {
                    continue;
                }
                ans[ny][nx] = step+1;
                q.push({step+1, {ny, nx}});
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(NULL);
    solve();
    return 0;
}