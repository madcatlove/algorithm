#include <cstdio>

int n, a[1000011];
int memo[1000011];
int len = 0;

int bs(int s, int e, int value) {
	int mid, sol;
	while (s <= e) {
		mid = (s + e) / 2;
		if (memo[mid] < value) {
			sol = mid + 1;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return sol; 
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	memo[0] = -2000000000;
	for (int i = 0; i < n; i++) {
		// 뒤에 붙일수있다면.
		if (memo[len] <= a[i]) {
			memo[++len] = a[i];
		}
		else {
			int it = bs(0, len, a[i]);
			memo[it] = a[i];
		}
	}
	printf("%d\n", len);
	


	return 0;
}
