#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int x,n, m[1001111];

int bisearch(int s, int e, int value) {
    
    int mid = 0;
    while(s <= e) {
        mid = (s+e)/2;
        if(m[mid] == value) {
            return mid;
        }
        else if(m[mid] < value) {
            s = mid+1;
        }
        else if(m[mid] > value) {
            e = mid-1;
        }
    }
    
    return -1;
}

int main() {
    
    int x;
    while(scanf("%d", &x) == 1) {
        
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", m+i);
        }
        
        sort(m,m+n);
        
        int res = -1;
        for(int i = 0; i < n; i++) {
            int target = (x*10000000) - m[i];
            res = bisearch(i+1, n-1, target);
            
            if(res != -1) {
                printf("yes %d %d\n", m[i], target);
                break;
            }
        }
        
        if(res == -1) printf("danger\n");

    }
    
    return 0;
}
