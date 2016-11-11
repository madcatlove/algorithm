
#include <cstdio>
#define SMAX(a,b) ( ((a)>(b)) ? (a):(b))
#define INF 987654321

int leftCard[2022];
int rightCard[2022];
int n;
int memo[2022][2022];

// 왼쪽카드가 lpos번째, 오른쪽카드가 rpos일때
// 최종 점수의 최대값 반환
int sol(int lpos, int rpos) {
    
    if(lpos == n || rpos == n) return 0;
    if(memo[lpos][rpos] != -1) return memo[lpos][rpos];
    
    
    int ret = -INF;
    
    // 왼쪽카드만 버린다.
    ret = SMAX(ret, sol(lpos+1,rpos));
    
    // 둘다 버린다.
    ret = SMAX(ret, sol(lpos+1,rpos+1));
    
    // 왼쪽>오른쪽이면 오른쪽을 버린다.
    if(leftCard[lpos]>rightCard[rpos])
        ret = SMAX(ret, rightCard[rpos] + sol(lpos,rpos+1));
    
    return memo[lpos][rpos] = ret;
}

int main() {
    
    for(int i = 0; i < 2022; i++)
        for(int j = 0; j < 2022; j++)
            memo[i][j] = -1;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d",leftCard+i);
    for(int i = 0; i < n; i++) scanf("%d",rightCard+i);
    
    printf("%d\n", sol(0,0));
    
    
    return 0;
}
