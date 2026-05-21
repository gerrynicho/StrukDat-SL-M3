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

int find_parent(vector<int> &parent, int v){
    if(v == parent[v]) return v;

    return parent[v] = find_parent(parent, parent[v]);
}  

void union_set(vector<int> &parent, int vertex1, int vertex2)
{
    int parent1 = find_parent(parent, vertex1);
    int parent2 = find_parent(parent, vertex2);

    if (parent1 != parent2)
        parent[parent2] = parent1;
}

void solve()
{
    // vertexCount, edgeCount
    int vc, ec; cin >> vc >> ec;
    vector<pii> el; // edgeList
    vector<int> parent;
    int cnt = vc; // count

    for(int i = 0; i < vc; i++) parent.push_back(i); 

    for(int i = 0; i < ec; i++) {
        int a, b; cin >> a >> b;
        el.push_back({a, b});
    }

    for(auto edge : el) {
        int vertex1 = edge.first;
        int vertex2 = edge.second;

        if(find_parent(parent, vertex1) != find_parent(parent, vertex2)) {
            union_set(parent, vertex1, vertex2);
            cnt--;  
        }
    }

    if(cnt == 1) {
        cout << "Kompleksitas entitas terbentuk";
    } else {
        cout << "Seluruh kosmik tidak berkaitan, butuh " << cnt - 1 << " lagi";
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
