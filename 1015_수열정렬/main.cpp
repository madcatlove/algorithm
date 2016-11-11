
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
typedef struct {
    int num, idx, pos;
} NUMBER;

NUMBER a[1011];

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int v; scanf("%d", &v);
        a[i].num = v;
        a[i].idx = i;
    }
    
    /*
     stable_sort(a,a+n,[](const NUMBER&u, const NUMBER&v) {
     return u.num < v.num;
     });
     */
    
    sort(a,a+n,[](const NUMBER&u, const NUMBER&v) {
        if(u.num == v.num) return u.idx < v.idx;
        return u.num < v.num;
    });
    
    for(int i = 0; i<n; i++) a[i].pos = i;
    
    stable_sort(a,a+n,[](const NUMBER&u, const NUMBER&v) {
        return u.idx < v.idx;
    });
    
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i].pos);
    }
    
    return 0;
}
