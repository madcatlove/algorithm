
#include <cstdio>
#include <stack>
using namespace std;

int n;
char buff[100011];

int main() {
    
    stack<char> s;
    scanf("%d",&n);
    int ans = 0;
    while(n--) {
        scanf("%s",buff);
        
        while(!s.empty())s.pop();
        s.push(buff[0]);
        for(int i = 1; buff[i]; i++) {
            if(s.empty()) {
                s.push(buff[i]);
                continue;
            }
            
            if(s.top() == buff[i]) {
                s.pop();
            }
            else {
                s.push(buff[i]);
            }
        }
        
        ans = ans + (s.empty());
    }
    printf("%d\n",ans);
    
    return 0;
}
