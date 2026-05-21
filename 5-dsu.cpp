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

int find_parent(vector<int>& parent, int v) {
    if(v == parent[v]) {
        return v;
    }

    return parent[v] = find_parent(parent, parent[v]);
}

void union_set(vector<int>& parent, int v1, int v2) {
    int p1 = find_parent(parent, v1);
    int p2 = find_parent(parent, v2);

    if(p1 != p2) {
        parent[p2] = p1;
    }
}

void solve()
{
    int n; cin >> n;
    vector<int> v(n+5);
    vector<int> parent(n+5);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        parent[i] = i;
    }
    vector<pii> el;
    int c; cin >> c;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = v[i] ^ v[j];
            if(sum % c == 0) {
                el.push_back({i, j});
            }
        }
    }

    int cnt = n;
    for(auto edge:el) {
        int v1 = edge.first;
        int v2 = edge.second;

        if(find_parent(parent, v1) != find_parent(parent, v2)) {
            union_set(parent, v1, v2);
            cnt--;
        }
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
