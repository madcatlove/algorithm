#include <cstdio>

int n;

// 두 숫자 a,b가 주어지면 최대 수 이어쓰기 길이 반환
int sol(int a, int b) {
	if ( b< 0) return 0;
	return 1 + sol(b, a - b);
}

void track(int a, int b) {

	printf("%d %d ", a, b);
	int r = a - b;
	while (r >= 0) {
		printf("%d ", r);
		a = b;
		b = r;
		r = a - b;
	}
}

int main() {

	scanf("%d", &n);

	int len = -1, v = 0;
	for (int b = 1; b <= n; b++) {
		int r = sol(n, b);
		if (r > len) {
			len = r;
			v = b;
		}

	}
	printf("%d\n", len+1);
	track(n, v);


	return 0;
}
