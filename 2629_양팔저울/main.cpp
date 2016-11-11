#include <cstdio>

int n;
int arr[30];
bool weight[150001];
bool tmp[150001];

inline int abs(int a) { return a<0?-a:a; }

int main() {
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", arr+i);
    
    weight[arr[0]] = true;
    weight[0] = true;
    for(int i = 1; i < n; i++) {
        
        for(int j = 0; j <= 15000; j++) {
            if(weight[j]) {
                if(j+arr[i] <= 15000) tmp[j+arr[i]] = true;
                if(abs(j-arr[i]) <= 15000) tmp[abs(j-arr[i])] = true;
            }
        }
        tmp[arr[i]] = true;
        for(int j = 0; j <= 15000; j++) if(tmp[j]) weight[j] = tmp[j];
        
    }
    
    
    int q; scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        int num; scanf("%d", &num);
        printf("%c ", (num <= 15000 && weight[num] )?'Y':'N');
    }
    
    
    return 0;
}
