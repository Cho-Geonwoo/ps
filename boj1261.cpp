#include <iostream>
#include <queue>
#include <string>
#define N_MAX 101
#define INF 1e9
#define P pair<int, int>

using namespace std;
int dir_x[4] = {0,1,0,-1}, dir_y[4] = {1,0,-1,0};

int M, N;
int ans = INF;
int maze[N_MAX][N_MAX];
int dist[N_MAX][N_MAX];

void Input(){
	cin>>M>>N;
	for(int i=0;i<N;i++){
		string temp;
		cin>>temp;
		for(int j=0;j<M;j++){
			maze[i][j] = temp[j] - '0';
			dist[i][j] = INF;
		}
	}
}

void BFS(){
	queue<P> Q;
	Q.push(P{0,0});
	dist[0][0] = 0;
	while(Q.empty()==0){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++){
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			//벽으로 가로막혀 있을 때
			if(maze[nx][ny]==1){
				if(dist[nx][ny]>dist[x][y]+1){
					dist[nx][ny] = dist[x][y]+1;
					Q.push(P{nx, ny});
				}
			}
			//뚫려있을 때
			else if(maze[nx][ny]==0){
				if(dist[nx][ny]>dist[x][y]){
					dist[nx][ny] = dist[x][y];
					Q.push(P{nx, ny});
				}
			}
		}
	}
}

void Solution(){
	BFS();
	cout<<dist[N-1][M-1]<<endl;
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		cout<<dist[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
}

void Solve(){
	Input();
	Solution();
}

int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	Solve();
	return 0;
}