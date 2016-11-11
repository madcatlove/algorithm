
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct _st {
    int weight;
    int height;
    int rank;
} person;

int n;
person p[55];

int main() {
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].weight, &p[i].height);
        p[i].rank = 1;
    }
    
    // i 보다 덩치가 큰 놈을 찾는다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if( i == j ) continue;
            if( p[i].weight < p[j].weight && p[i].height < p[j].height) {
                p[i].rank++;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        printf("%d ", p[i].rank);
    
    
    return 0;
}
