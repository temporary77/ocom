#include <bits/stdc++.h>
using namespace std;

int arr[20];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		long long n;
		int s;
		scanf("%lld%d",&n,&s);
		int r;
		long long ni = n;
		for (int i = 0; i < 20; ++i) {
			arr[i] = ni%10;
			ni /= 10;
			if (ni == 0) {
				r = i;
				arr[i+1] = 0;
				break;
			}
		}
		int ttl = 0;
		int idx = r;
		for (;idx >= 0;) {
			ttl += arr[idx];
			if (ttl > s)break;
			--idx;
		}
		for (int i = idx-1; i >= 0; --i) {
			arr[i] = 0;
		}
		for (;ttl > s;) {
			ttl += 10-arr[idx];
			arr[idx] = 10;
			for (;arr[idx] == 10;) {
				ttl -= 10;
				arr[idx] = 0;
				++idx;
				++ttl;
				++arr[idx];
			}
		}
		long long trgt = 0;
		for (int j = max(r,idx); j >= 0; --j) {
			trgt *= 10;
			trgt += arr[j];
		}
		printf("%lld\n",trgt-n);
	}
	return 0;
}