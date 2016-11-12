nclude <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[50011],n, q;
inline int abs(int a) { return a<0?-a:a;}


struct BIT {
    int first = 0;
    int INF = 0;
    vector<int> tree;
    int (*compare)(int ,int) = nullptr;
    
    BIT(int n, int INF, int (*fp)(int,int)) {
        for(first=1; first<n; first = first*2);
        tree = vector<int>(n<<2, INF);
        compare = fp;
        this->INF = INF;
    }
    
    void update(int pos, int val) {
        pos = first + pos;
        tree[pos] = val;
        while(pos/2) {
            tree[pos/2] = compare(tree[pos/2], tree[pos]);
            pos = pos /2;
        }
    }
    
    int query(int l, int r) {
        l = l + first;
        r = r + first;
        int ret = INF;
        while(l <= r) {
            ret = compare(ret, compare(tree[l], tree[r]));
            l = (l+1) / 2;
            r = (r-1) / 2;
        }
        return ret;
    }
};


int main() {
    scanf("%d %d", &n, &q);
    
    BIT small(n, 987654321, [](int a, int b) {
        return min(a,b);
    });
    
    BIT big(n, -987654321, [](int a, int b) {
        return max(a,b);
    });
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        small.update(i+1, a[i]);
        big.update(i+1,a[i]);
    }
    
    
    
    for(int i = 0; i < q; i++) {
        int s, e; scanf("%d %d", &s, &e);
        int vMin = small.query(s,e);
        int vMax = big.query(s,e);
        printf("%d\n", abs(vMin-vMax));
    }
    
}
