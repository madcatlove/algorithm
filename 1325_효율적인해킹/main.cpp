#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[10011];
bool isvisited[10011];
int L[10011];

int dfs(int node) {

	isvisited[node] = true;
	int len = 1;

	for (int next = 0; next < adj[node].size(); next++) {
		if (!isvisited[adj[node][next]]) {
			len += dfs(adj[node][next]);
		}
	}

	return L[node] = len;
}

void init() {
	for (int i = 1; i <= n; i++) isvisited[i] = false;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int s, e; scanf("%d %d", &s, &e);
		adj[e].push_back(s);
	}

	int maxLen = 0, maxNode = 0;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		init();
		int l = dfs(i);
		if (maxLen < l) maxLen = l;

		ans.push_back(l);
	}
    
	for (int i = 0; i < ans.size(); i++)
		if (ans[i] == maxLen) printf("%d ", i + 1);
    
	return 0;
}
