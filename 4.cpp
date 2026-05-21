#include <bits/stdc++.h>
#define endl "\n"
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define sep << " " <<
#define space << " "
#define tc           \
    int TESTCASE;    \
    cin >> TESTCASE; \
    while (TESTCASE--)
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
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next : adj[cur]) {
            if(vis[next]) {
                continue;
            }
            vis[next] = true;
            q.push(next);
        }
    }

    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            flag = false;
            break;
        }
    }

    if(flag) {
        cout << "Para peserta LBH berhasil keluar!";
    } else {
        cout << "Para peserta LBH terjebak selamanya.";
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
