#include <iostream>
#include <cstring>
#include <vector>
#define P pair<int, int>

using namespace std;
const int MAX = 100001;
const int MAX_D = 17;

vector<P> graph[MAX];

int n, ant[MAX], Next[MAX][MAX_D], Cost[MAX][MAX_D];
bool visited[MAX];

void DFS(int curr){
	visited[curr] = true;
	for(auto& next: graph[curr]){
		if(visited[next.first]) continue;
		Next[next.first][0] = curr;
		Cost[next.first][0] = next.second;
		DFS(next.first);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	memset(Next, 0, sizeof(Next));
	memset(Cost, 0, sizeof(Cost));

	int a,b,c;

	//개미 에너지
	for(int i=1;i<=n;i++){
		cin>>ant[i];
	}
	for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	DFS(1);
	//1은 방문 안되니까 초기화 필요
	Next[1][0] = 1;
	Cost[1][0] = 0;
	
	//sparse table 구축
	for(int j=1;j<MAX_D;j++){
		for(int i=1;i<=n;i++){
			Next[i][j] = Next[Next[i][j-1]][j-1];
			Cost[i][j] = Cost[i][j-1] + Cost[Next[i][j-1]][j-1];
		}
	}

	for(int i=1;i<=n;i++){
		int x = i;
		for(int j = MAX_D-1;j>=0;j--){
			if(Cost[x][j]>ant[i]) continue;
			ant[i] -= Cost[x][j];
			x = Next[x][j];
		}
		cout<<x<<"\n";
	}

	return 0;
}