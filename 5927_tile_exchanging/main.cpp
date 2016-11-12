
#include <cstdio>
#define INF 987654321
#define MIN(a,b) (((a)>(b))?(b):(a))

int n,m, a[11];
int memo[11][10011];

/* 현재 타일 번호가 tileno 이고 남은 면적이 remain 일때
 타일을 교체하거나 그냥사용해봤을때 가장 최소비용 반환 */
int sol(int tileno, int remain) {
    
    if(remain < 0) return INF;
    if(tileno == n) { // 모든 타일을 사용해봤다면.
        if(remain == 0) return 0;
        return INF;
    }
    if(memo[tileno][remain] != -1) return memo[tileno][remain];
    
    int ret = INF;
    
    // 타일을 교환해본다.
    for(int next = 100; next >= 1; next--) {
        int p = (a[tileno]-next) * (a[tileno]-next);
        ret = MIN(ret, p+sol(tileno+1, remain-next*next));
    }
    
    return memo[tileno][remain] = ret;
}

int main() {
    for(int i = 0; i < 11; i++) for(int j = 0; j < 10011; j++) memo[i][j] = -1;
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int ret = sol(0,m);
    printf("%d\n", ret == INF ? -1 : ret);
    
    return 0;
}
