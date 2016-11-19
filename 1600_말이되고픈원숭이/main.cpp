#include <cstdio>
#include <queue>
#define INF 987654321
using namespace std;

int k, w, h;
int matrix[205][205];
int visited[205][205][33];

typedef struct {
	int y, x, k;
} POINT;

bool inrange(int y, int x) {
	return (y >= 1 && y <= h) && (x >= 1 && x <= w) && matrix[y][x];
}

void bfs() {
	// 나이트
	static int dx1[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	static int dy1[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	// 동서남북
	static int dx2[] = { 1, -1, 0, 0 };
	static int dy2[] = { 0, 0, -1, 1 };

	queue<POINT> q;
	q.push(POINT{ 1, 1, k });
	visited[1][1][k] = 0;

	while (!q.empty()) {
		POINT cur = q.front(); q.pop();
		int curCost = visited[cur.y][cur.x][cur.k];

		if (cur.x == w && cur.y == h) {
			printf("%d", curCost);
			return;
		}

		// 동서남북
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx2[dir];
			int ny = cur.y + dy2[dir];

			if (inrange(ny, nx) && curCost + 1 < visited[ny][nx][cur.k]) {
				q.push(POINT{ ny, nx, cur.k });
				visited[ny][nx][cur.k] = curCost + 1;
				//printf("push (%d,%d)\n", ny, nx);
			}
		}

		
		// 나이트 이동
		if (cur.k > 0) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.x + dx1[dir];
				int ny = cur.y + dy1[dir];

				if (inrange(ny, nx) && curCost + 1 < visited[ny][nx][cur.k-1]) {
					q.push(POINT{ ny, nx, (cur.k-1) });
					visited[ny][nx][cur.k-1] = curCost + 1;
					//printf("push (%d,%d)2\n", ny, nx);
				}
			}
		}
	}

	printf("-1\n");
}

int main() {
	scanf("%d", &k);
	scanf("%d %d", &w, &h);

	for (int y = 0; y < 205; y++) for (int x = 0; x < 205; x++) for(int z = 0; z < 33; z++) visited[y][x][z] = INF;

	for (int y = 1; y <= h; y++) {
		for (int x = 1; x <= w; x++) {
			scanf("%d", &matrix[y][x]);
			if (matrix[y][x]) matrix[y][x] = 0;
			else matrix[y][x] = 1;
		}
	}

	bfs();


	return 0;
}


