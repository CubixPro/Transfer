#include<bits/stdc++.h>
#define max_wt 200001

using namespace std;

vector<int> weights[max_wt];
int comb(int val){
    return val*(val - 1)/2;
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    vector<pair<int, int>> graph[n + 1];
    for(int i = 1 ; i < n ; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
        weights[z].push_back(x);
        weights[z].push_back(y);
    }
    while(q-- != 0){
        int max_val;
        scanf("%d", &max_val);
        set<int> vertices;
        for(int i = 1 ; i <= max_val; i++){
            for(int j = 0 ; j < weights[i].size() ; j++)
                vertices.insert(weights[i][j]);
        }
        bool visited[n + 1];
        memset(visited, false, sizeof(visited));
        int count = 1;
        int total  = 0;
        set<int> :: iterator it = vertices.begin();
        while(!vertices.empty()){
            stack<int> temp123;
            temp123.push(*(vertices.begin()));
            while(! temp123.empty()){
                int val = temp123.top();
                temp123.pop();
                visited[val] = true;
                for(int k = 0 ; k < graph[val].size() ; k++){
                    if(!visited[graph[val][k].first])
                    {
                        if(graph[val][k].second  <= max_val){
                            count++;
                            temp123.push(graph[val][k].first);
                            vertices.erase(graph[val][k].first);
                        }
                    }
                }
                vertices.erase(val);
            }
            total += comb(count);
            count = 1; 


        }
        cout << total << " \n";
    }

}

//use dsu to keep track of all the connected components

#include <bits/stdc++.h>

using namespace std;

vector<int> p, rk;

int getp(int v) {
	if (v == p[v]) return v;
	return p[v] = getp(p[v]);
}

long long res;

long long get(int cnt) {
	return cnt * 1ll * (cnt - 1) / 2;
}

void merge(int u, int v) {
	u = getp(u);
	v = getp(v);
	
	if (rk[u] < rk[v]) swap(u, v);
	
	res -= get(rk[u]);
	res -= get(rk[v]);
	
	rk[u] += rk[v];
	
	res += get(rk[u]);
	
	p[v] = u;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	
	res = 0;
	p = rk = vector<int>(n, 1);
	iota(p.begin(), p.end(), 0);
	
	vector<pair<int, pair<int, int>>> e(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> e[i].second.first >> e[i].second.second >> e[i].first;
		--e[i].second.first;
		--e[i].second.second;
	}
	
	vector<pair<int, int>> q(m);
	vector<long long> ans(m);
	for (int i = 0; i < m; ++i) {
		cin >> q[i].first;
		q[i].second = i;
	}
	
	sort(e.begin(), e.end());
	sort(q.begin(), q.end());
	
	int pos = 0;
	for (int i = 0; i < m; ++i) {
		while (pos < n - 1 && e[pos].first <= q[i].first) {
			int u = e[pos].second.first;
			int v = e[pos].second.second;
			merge(u, v);
			++pos;
		}
		ans[q[i].second] = res;
	}
	
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}