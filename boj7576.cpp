#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int T, l, start_x, start_y, end_x, end_y;
int board[301][301];

int dir[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int bfs(){
	queue<pair<int, int > > q;
	int count = 0;
	q.push(make_pair(start_x, start_y));
	board[start_x][start_y] = 1;
	while(!q.empty()){
		count++;
		int si = q.size();
		for(int k=0;k<si;k++){
			int curr_x = q.front().first;
			int curr_y = q.front().second;
			if(curr_x==end_x&&curr_y==end_y){
				return count-1;
			}
			q.pop();
			for(int i=0;i<8;i++){
				int tmp_x = curr_x + dir[i][0];
				int tmp_y = curr_y + dir[i][1];
				if(tmp_x<0||tmp_x>=l) continue;
				if(tmp_y<0||tmp_y>=l) continue;
				if(board[tmp_x][tmp_y]==0){
					board[tmp_x][tmp_y] = 1;
					q.push(make_pair(tmp_x,tmp_y));
				}
			}
		}
	}
	return count;
}

int main(){
	cin>>T;
	for(int t=0;t<T;t++){
		memset(board, 0, sizeof(board));
		cin>>l>>start_x>>start_y>>end_x>>end_y;
		cout<<bfs()<<endl;
	}
	return 0;
}
