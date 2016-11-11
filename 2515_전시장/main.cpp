
#include <cstdio>
#define INF 98765421
#define SMAX(a,b) (((a)>(b))?(a):(b))

typedef struct {
    int height;
    int cost;
} PIC;

int n,s;
PIC arr[300033];
PIC tmp[300033];
int memo[300033];

bool cmp(const PIC& u, const PIC& v) {
    return u.height < v.height;
}

void merge(int s, int e) {
    int mid = (s+e)/2;
    int left = s, right = mid+1, cnt = 0;
    
    while(left<=mid && right<=e) {
        if( cmp(arr[left], arr[right])) tmp[cnt++] = arr[left++];
        else tmp[cnt++] = arr[right++];
    }
    while(left<=mid) tmp[cnt++]=arr[left++];
    while(right<=e) tmp[cnt++]=arr[right++];
    for(int i = 0; i < cnt; i++) arr[s+i] = tmp[i];
}

void mergeSort(int s, int e) {
    int mid = (s+e)/2;
    if(s < e) {
        mergeSort(s, mid);
        mergeSort(mid+1,e);
        merge(s,e);
    }
}

int bs(int s, int e, int value) {
    int mid, sol = 0;
    
    while(s<=e) {
        mid = (s+e)/2;
        if(arr[mid].height < value) {
            sol = mid + 1;
            s = mid + 1;
        }
        else {
            e = mid -1;
        }
    }
    
    return sol;
}


// i~n번째 그림을 배치할때 최대합 반환
int sol(int i) {
    
    if(i >= n) return 0;
    if(memo[i] != -1) return memo[i];
    
    int ret = -INF;
    
    // i번쨰그림을 버린다. 배치하지않음.
    ret = SMAX(ret, sol(i+1));
    
    // i번째 그림을 배치하고 나보다 s만큼 더 크거나 같은 애로 점프한다.
    int it = bs(0,n, arr[i].height+s);
    ret = SMAX(ret, arr[i].cost + sol(it));
    
    return memo[i] = ret;
}

int main() {
    
    for(int i = 0; i < 300033; i++) memo[i] = -1;
    
    scanf("%d %d",&n,&s);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].height, &arr[i].cost);
    }
    
    mergeSort(0, n-1);
    
    printf("%d\n",sol(0));
    
    return 0;
}
