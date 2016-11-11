#include <cstdio>
#include <algorithm>


int a[100011], n;

int abs(int a) { return a < 0 ? -a : a; }
int bs(int value, int s, int e) {
	int mid, sol=-1;

	while (s <= e) {
		mid = (s + e) / 2;
		if (a[mid] <= value) {
			s = mid + 1;
			sol = mid;
		}
		else e = mid - 1;
	}

	return sol;
}

int bs2(int value, int s, int e) {
	int mid, sol = -1;

	while (s <= e) {
		mid = (s + e) / 2;
		if (a[mid] >= value) {
			e = mid - 1;
			sol = mid;
		}
		else s = mid + 1;
	}

	return sol;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int maxLeft = 0, maxRight = 0, ans = 2000000022;
	for (int i = 0; i < n; i++) {
		int q = bs(-a[i], i+1, n - 1);
		int q2 = bs2(-a[i], 0, i-1);

		//printf("i:%d, q:%d, q2:%d\n", i, q, q2);

		if (q >= 0) {
			int t = abs(a[i] + a[q]);
			if (t < ans) {
				ans = t;
				maxLeft = i;
				maxRight = q;
			}
		}

		if (q2 >= 0) {
			int t = abs(a[i] + a[q2]);
			if (t < ans) {
				ans = t;
				maxLeft = i;
				maxRight = q2;
			}
		}

		
	}

	if (a[maxLeft] < a[maxRight]) printf("%d %d\n", a[maxLeft], a[maxRight]);
	else printf("%d %d\n", a[maxRight], a[maxLeft]);

	return 0;
}