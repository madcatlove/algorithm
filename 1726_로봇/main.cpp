#include <cstdio>
#include <queue>
#define INF 987654321
using namespace std;

int row, col;
int matrix[111][111];
int visited[111][111][5];
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int sy, sx, sd;
int ey, ex, ed;

typedef struct {
	int y;
	int x;
	int dir;
} DT;

int outofrange(int y, int x) {
	return (y < 0 || y >= row || x < 0 || x >= col || matrix[y][x] != 0);
}

int rotate(int a, int b) {
	a++; b++;

	if (a == b) return 0;
	if (a == 1 && b == 2) return 2;
	if (a == 2 && b == 1) return 2;
	if (a == 3 && b == 4) return 2;
	if (a == 4 && b == 3) return 2;
	return 1;

}

int main() {

	scanf("%d %d", &row, &col);
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			scanf("%d", &matrix[y][x]);

			for (int k = 0; k < 5; k++) visited[y][x][k] = INF;
		}
	}
	
	scanf("%d %d %d", &sy, &sx, &sd);
	scanf("%d %d %d", &ey, &ex, &ed);

	sy--; sx--; sd--;  ey--; ex--; ed--;

	queue<DT> q;
	q.push(DT{ sy, sx, sd });
	visited[sy][sx][sd] = 0;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cdir = q.front().dir;
		q.pop();

		//printf("cy : %d cx  :%d , cdir :%d\n", cy, cx, cdir);
		if (cy == ey && cx == ex) {
			printf("%d\n",visited[cy][cx][cdir] + rotate(cdir,ed) );
			break;
		}
		
		// 방향 전환
		for (int dir = 0; dir < 4; dir++) {
			int rotatePrice = rotate(cdir, dir);
			int nx = cx;
			int ny = cy;

			// 그때마다 점프뜀
			for (int k = 1; k <= 3; k++) {
				nx = nx + dx[dir];
				ny = ny + dy[dir];


				if (outofrange(ny, nx)) break;
				// if (outofrange(ny, nx)) continue; (이부분을 하면 왜 안될까 )

				if (visited[cy][cx][cdir] + 1 + rotatePrice < visited[ny][nx][dir]) {
					q.push(DT{ ny, nx, dir });
					visited[ny][nx][dir] = visited[cy][cx][cdir] + 1 + rotatePrice;
				}
			}


		}
		
	}

	return 0;
}
