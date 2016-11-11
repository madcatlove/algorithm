#include <cstdio>
#include <queue>
using namespace std;

int h, w, n;
char matrix[1111][1111];
int sy, sx;
bool visited[1111][1111];

typedef struct {
	int y, x, step;
} DT;

bool inrange(int y, int x) {
	return (y >= 1 && y <= h) && (x >= 1 && x <= w);
}

int bfs(const int want) {

	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	queue<DT> q;
	q.push(DT{ sy, sx, 0});
	visited[sy][sx] = true;

	for (int i = 0; i < 1111; i++) for (int j = 0; j < 1111; j++) visited[i][j] = false;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cstep = q.front().step;
		q.pop();

		// 원하는 목적지 도달시 끝.
		if (matrix[cy][cx] - '0' == want) {
			sy = cy;
			sx = cx;
			return cstep;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (!inrange(ny, nx)) continue;
			
			if (matrix[ny][nx] != 'X' && !visited[ny][nx]) {
				q.push(DT{ ny, nx, cstep + 1 });
				visited[ny][nx] = true;
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d %d %d", &h, &w, &n);
	for (int y = 1; y <= h; y++) {
		scanf("%s", matrix[y]+1);
		for (int x = 1; x <= w; x++) {
			if (matrix[y][x] == 'S') {
				sy = y;
				sx = x;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += bfs(i);
	}

	printf("%d\n", ans);

	return 0;
}
