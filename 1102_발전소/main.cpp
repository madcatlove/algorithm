#include <cstdio>
#define INF 987654321
#define SETBIT(status, w) ((status) | (1 <<(w)))
#define GETBIT(status,w)  ((status) & (1<<(w)))
#define MIN(a,b) (((a)>(b))?(b):(a))

char buff[17];
int n, cost[17][17], p;
int memo[17][1 << 16];

int bitCount(int i) {
	int cnt = 0;
	while (i) {
		cnt = cnt + (i & 1);
		i >>= 1;
	}
	return cnt;
}

/*
 현재 발전소들의 상태가 plantStatus 일때
 plant번 발전소를 이용하여 발전소를 켤때
 가능한 비용의 최소값 반환.
*/
int sol(const int plant, const int plantStatus) {

	int ret = INF;

	// 내 발전소가 꺼져있다면 남을 켤수가 없으니깐 패스
	if (!GETBIT(plantStatus, plant)) return INF;
	if (bitCount(plantStatus) >= p) return 0;
	if (memo[plant][plantStatus] != -1) return memo[plant][plantStatus];

	for (int next = 0; next < n; next++) {
		// next 발전소가 꺼져있다면 켜본다.
		if (!GETBIT(plantStatus, next)) {
			//printf(" %d make %d on\n", plant, next);
			int tmp = cost[plant][next] + sol(next, SETBIT(plantStatus, next));
			int tmp2 = cost[plant][next] + sol(plant, SETBIT(plantStatus, next));
			ret = MIN(ret, tmp);
			ret = MIN(ret, tmp2);
		}
	}

	return memo[plant][plantStatus] = ret;
}


int sol2(int cnt, int plantStatus) {

	if (cnt >= p) return 0;
	if (memo[cnt][plantStatus] !=-1) return memo[cnt][plantStatus];

	int ret = INF;

	for (int on = 0; on < n; on++) {
		// on번째 발전소가 켜져있다면.
		if (GETBIT(plantStatus, on)) {
			for (int off = 0; off < n; off++) {
				// off 번째 발전소가 꺼져있다면. 켜본다.
				if (!GETBIT(plantStatus, off)) {
					int tmp = cost[on][off] + sol2(cnt + 1, SETBIT(plantStatus,off) );
					//printf("cnt:%d on%d --> off %d ====> %d   (bit:%d   %d)\n",cnt, on, off, tmp, plantStatus, SETBIT(plantStatus, off));
					ret = MIN(ret, tmp);
				}
			}
		}
	}

	return memo[cnt][plantStatus] = ret;
}


int main() {

	for (int i = 0; i < 17; i++)
		for (int j = 0; j < (1 << 16); j++)
			memo[i][j] = -1;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	int plantStatus = 0;
	int onCount = 0;
	scanf("%s", buff);
	for (int i = 0; buff[i]; i++) {
		if (buff[i] == 'Y') {
			plantStatus = SETBIT(plantStatus, i);
			onCount++;
		}
	}

	scanf("%d", &p);

	int ans = sol2(onCount, plantStatus);
	printf("%d\n", ans == INF ? -1 : ans);

	return 0;
}
