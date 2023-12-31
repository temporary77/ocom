#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int visited[100001];
int mode;
int knot;
stack<int> stck;

void dfs(int node) {
	visited[node] = 1;
	// printf("%d %d\n",node,t);
	// printf("%d\n",node);
	for (auto it : graph[node]) {
		if (visited[it] == 2)continue;
		if (visited[it] == 1) {
			knot = it;
			stck.push(knot);
			stck.push(node);
			mode = 1;
			return;
		}
		dfs(it);
		if (mode == 1) {
			stck.push(node);
			if (node == knot)mode = 2;
			return;
		}
		if (mode == 2) {
			return;
		}
	}
	visited[node] = 2;
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
		if (mode == 2)goto g;
	}
	printf("IMPOSSIBLE");
	return 0;
	g:;
	printf("%d\n",stck.size());
	for (;!stck.empty();) {
		printf("%d ",stck.top());
		stck.pop();
	}
	return 0;
}