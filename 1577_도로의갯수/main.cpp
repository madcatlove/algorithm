#include <cstdio>
#include <vector>
#define lld long long int
using namespace std;


typedef struct {
	int x, y;
} POINT;

vector<vector<POINT>> deny[111];
int n, m, k;
lld memo[111][111];

bool inrange(int x, int y) {
	return (x >= 0 && x <= n) && (y >= 0 && y <= m);
}

lld sol(int x, int y) {

	static int dx[] = { 0, 1 };
	static int dy[] = { 1, 0 }; 

	if (x == n && y == m) return 1;
	if (memo[x][y] != -1) return memo[x][y];

	lld ret = 0;
	for (int dir = 0; dir < 2; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (!inrange(nx, ny)) continue;

		bool checked = true;
		for (int j = 0; j < deny[x][y].size(); j++) {
			if (deny[x][y][j].x == nx && deny[x][y][j].y == ny) {
				checked = false;
				break;
			}
		}
		if(checked) ret += sol(nx, ny);
	}

	return memo[x][y] = ret;
}

int main() {

	scanf("%d %d", &n, &m);
	scanf("%d", &k);

	for (int i = 0; i < 111; i++) {
		deny[i].resize(101);
		for (int j = 0; j < 111; j++) memo[i][j] = -1;
	}

	for (int i = 0; i < k; i++) {
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		POINT f = { a, b };
		POINT s = { c, d };

		deny[a][b].push_back(s);
		deny[c][d].push_back(f);
	}

	printf("%lld\n", sol(0, 0));

	return 0;
}
