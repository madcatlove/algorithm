
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define INF 987654321

int dirX[] = {1,-1,0,0};
int dirY[] = {0,0,1,-1};
int dirZ[] = {1,-1};

char buff[35];
char m[35][35][35];
int visited[35][35][35];
int L,R,C;
int sz,sy,sx,ez,ey,ex;

bool check(const int z, const int y, const int x) {
    return (m[z][y][x] != '#') && (m[z][y][x] != 0);
}

void init() {
    for(int i = 0; i < 35; i++) {
        for(int j = 0; j < 35; j++) {
            for(int k = 0; k < 35; k++) {
                m[i][j][k] = 0;
                visited[i][j][k] = INF;
            }
        }
    }
}


void bfs() {
    
    queue<int> qx,qy,qz,ql;
    qx.push(sx);
    qy.push(sy);
    qz.push(sz);
    ql.push(0);
    visited[sz][sy][sx] = true;
    
    while(!qx.empty()) {
        int curx = qx.front(); qx.pop();
        int cury = qy.front(); qy.pop();
        int curz = qz.front(); qz.pop();
        int curl = ql.front(); ql.pop();
        
        
        
        if(m[curz][cury][curx] == 'E') {
            printf("Escaped in %d minute(s).\n", curl);
            return;
        }
        
        
        // 상/하
        for(int dir = 0; dir < 2; dir++) {
            int nx = curx;
            int ny = cury;
            int nz = curz + dirZ[dir];
            
            if(check(nz,ny,nx) && curl+1<visited[nz][ny][nx]) {
                qx.push(nx); qy.push(ny); qz.push(nz);
                ql.push(curl+1);
                visited[nz][ny][nx] = curl+1;
            }
            
        }
        
        // 동서남북
        for(int dir = 0; dir < 4; dir++) {
            int nz = curz;
            int nx = curx + dirX[dir];
            int ny = cury + dirY[dir];
            
            if(check(nz,ny,nx) && curl+1<visited[nz][ny][nx]) {
                qx.push(nx); qy.push(ny); qz.push(nz);
                ql.push(curl+1);
                visited[nz][ny][nx] = curl+1;
            }
        }
        
    }
    
    printf("Trapped!\n");
    
}

int main() {
    
    while(true) {
        scanf("%d %d %d",&L,&R,&C);
        if(L == R && R == C && C == 0) break;
        
        init();
        for(int z = 1; z <= L; z++) {
            for(int y = 1; y <= R; y++) {
                scanf("%s", buff+1);
                for(int x = 1; x <= C; x++) {
                    m[z][y][x] = buff[x];
                    
                    if(buff[x] == 'S') {
                        sx = x, sy = y, sz = z;
                    }
                    else if(buff[x] == 'E') {
                        ex = x, ey = y, ez = z;
                    }
                }
            }
        }
        
        bfs();
        
        
    }
    
    return 0;
}
