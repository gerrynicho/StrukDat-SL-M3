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
    int n; cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    set<pii> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] ==  '+') {
                s.insert({i, j});
            }
        }
    }

    queue<pii> st;
    vector<pii> direction = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    int cnt = 0;
    while(!s.empty()) { // traverse all disjointed graph
        pii start = *s.begin();
        st.push(start);
        s.erase(start);
        arr[start.fi][start.se] = '#';
        
        while(!st.empty()) { // bfs
            auto top = st.front();
            st.pop();
            for(auto dir:direction) {
                auto i = top.first + dir.first;
                auto j = top.second + dir.second;
                if(i >= 0 && i < n) { // klo accessable secara vertikal
                    if(j >= 0 && j < n) { // klo accessable secara horizontal
                        if(arr[i][j] == '+') { // adalah sebuah vertex
                            arr[i][j] = '#'; // mark visited
                            s.erase({i, j}); // dont traverse again
                            st.push({i, j});
                        }
                    }
                }
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