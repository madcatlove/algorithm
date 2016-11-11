#include <cstdio>

char o[11];
char t[101][11];
int n;

// 문자열p의 i번째부터 매치가되는지 확인.
bool match(char*p, int i, int len) {

	for (int k = 0; o[k]; k++) {
		int t = (i + k) % len;
		if (p[t] != o[k]) return false;
	}
	return true;
}

int main() {
	scanf("%s", o);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", t[i]);
	
	int ans = 0;
	for (int i = 0; i < n; i++) {

		int len = 0;
		for (; t[i][len]; len++);

		for (int j = 0; j < len; j++) {
			if (t[i][j] == o[0]) {
				if (match(t[i], j, len)) {
					ans++;
					break;
				}
			}
		}


	}
	printf("%d\n", ans);

	return 0;
}