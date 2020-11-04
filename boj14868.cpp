#include <iostream>
#include <queue>
using namespace std;
#define N_MAX 2000
#define P pair<int, int>

int N, K, root[N_MAX*N_MAX];
int map[N_MAX][N_MAX];
int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
queue<P> q1, q2;

int find(int num){
	if(root[num]==num){
		return num;
	}
	return root[num] = find(root[num]);
}

bool merge(int num1, int num2){
	int pNum1 = find(num1), pNum2 = find(num2);
	if(pNum1==pNum2){
		return false;
	}
	root[pNum1] = pNum2;
	return true;
}

void Input(){
	cin>>N>>K;
	for(int i=0;i<N*N;i++){
		root[i] = i;
	}
	for(int i=1;i<=K;i++){
		int x, y;
		cin>>x>>y;
		x--; y--;
		map[x][y] = i;
		q1.push({x,y});
	}
}

void Solution(){
	int ans = 0, curC = K;
	while(1){
		//union find
		int qSize = q1.size();
		for(int i=0;i<qSize;i++){
			P cur = q1.front();
			q1.pop();
			q2.push(cur);
			int x = cur.first, y = cur.second;
			for(int j=0;j<4;j++){
				int nx = x+dx[j], ny = y+dy[j];
				if(!(0<=nx&&nx<N && 0<=ny&&ny<N)){
					continue;
				}
				if(map[nx][ny]!=0){
					bool check = merge(map[x][y], map[nx][ny]);
					if(check){
						curC--;
					}
				}
			}
		}
		if(curC==1)
			break;
		for(int i=0;i<qSize;i++){
			P cur = q2.front();
			q2.pop();
			int x = cur.first, y = cur.second;
			for(int j=0;j<4;j++){
				int nx = x+dx[j], ny = y+dy[j];
				if(!(0<=nx&&nx<N && 0<=ny&&ny<N)){
					continue;
				}
				if(map[nx][ny]==0){
					q1.push(P{nx,ny});
					map[nx][ny] = map[x][y];
				}
			}
		}
		ans++;
	}
	cout<<ans<<endl;
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
}