#include <bits/stdc++.h>
using namespace std;

vector<int> vctr[26];
int tree[26][200001];
bool removed[200001];

void update(int x, int t, int val) {
	for (int a = x; a <= vctr[t].size(); a += a&-a) {
		tree[t][a] += val;
	}
	return;
}

void update2(int x, int t, int val) {
	// printf("%d %d %d %d\n",x,t,vctr[t].size(),val);
	for (int a = x; a <= vctr[t].size(); a += a&-a) {
		// printf("%d %d %d %d %d<\n",t,a,tree[t][a],val,tree[t][a]+val);
		printf("%d <<<<\n",tree[t][a]);
		tree[t][a] += -1;
		printf("%d <<<<\n",tree[t][a]);
		return;
	}
	return;
}

int query(int x, int t) {
	int res = 0;
	for (int a = x; a > 0; a -= a&-a) {
		res += tree[t][a];
	}
	return res;
}

int main() {
	cin.tie(NULL);
	int k;
	scanf("%d",&k);
	string str;
	cin >> str;
	for (int i = 0; i < str.size()*k; ++i) {
		vctr[str[i%str.size()]-'a'].push_back(i);
	}
	for (int i = 0; i < k*str.size(); ++i) {
		for (int j = 0; j < 26; ++j) {
			update(i+1,j,i);
		}
	}
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int a;
		char c;
		scanf("%d %c",&a,&c);
		int idx = query(a,c-'a');
		removed[vctr[c-'a'][idx]] = true;
		printf("%d\n",idx);
		if (i <= 0)update2(idx+1,c-'a',-1);
	}
	for (int i = 0; i < str.size()*k; ++i) {
		if (!removed[i]) {
			printf("%c",str[i%str.size()]);
		}
	}
	return 0;
}