#include <cstdio>
#include <algorithm>
#define GETBIT(status,w) ((status)&(1<<(w)))
#define SETBIT(status,w) ((status)|(1<<(w)))

using namespace std;

typedef struct {
    char first, last;
    int len;
} WORD;

int n;
char buff[101];
WORD a[17];
int memo[17][1<<16];


/*
 i번째 단어를 선택하였고 상태가 status 일때
 끝말잇기의 최대 길이(점수) 반환
 */
int sol(int i, int status) {
    
    if(memo[i][status]) return memo[i][status];
    
    int ret = 0;
    for(int next = 0; next < n; next++) {
        // next 번째 단어를 선택할수있다면.
        if(!GETBIT(status,next)) {
            if(a[i].last == a[next].first) {
                int t = a[next].len + sol(next, SETBIT(status,next));
                ret = max(ret,t);
            }
        }
    }
    
    return memo[i][status] =ret;
}

int main() {
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%s",buff);
        
        int len = 0;
        for(;buff[len];len++);
        a[i] = { buff[0], buff[len-1], len };
    }
    
    int ans = 0, status = 0;
    for(int i = 0; i < n; i++) ans = max(ans, a[i].len + sol(i, SETBIT(status,i)));
    printf("%d\n",ans);
    
    
    
    return 0;
}
