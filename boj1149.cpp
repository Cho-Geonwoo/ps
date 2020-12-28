#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define INF 1e9

int N, cost[1000][3], dp[1001][4];

int RGB(int pos, int prev){
	int &ret = dp[pos][prev];
	if(ret!=-1) return ret; //이미 계산되어 있는 경우
	if(pos == N) return ret = 0; //끝에 도착
	ret = INF;
	for(int i=0;i<3;i++){
		if(prev!=i) ret = min(ret, RGB(pos+1,i)+cost[pos][i]); //이전 것의 색깔과 같으면 안되니까
	}
	return ret;
}

void trackAnswer(int pos, int prev){
	if(pos==N) return;
	for(int i=0;i<3;i++){
		if(i!=prev&&RGB(pos+1, i)+cost[pos][i]==RGB(pos,prev)){
			printf("%dth color is %d\n", pos+1, i);
			trackAnswer(pos+1,i);
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			cin>>cost[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", RGB(0, 3));
	trackAnswer(0, 3);
	return 0;
}