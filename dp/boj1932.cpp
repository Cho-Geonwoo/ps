#include <iostream>
#include <vector>
#define MAX_N 500
#define MAX_NUMBER 9999
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int triangle[MAX_N][MAX_N];
int sum[MAX_N][MAX_N];
int N;
int final=0;

int dp(int level, int position){
  if (level == N-1){
    sum[level][position] = triangle[level][position];
    return triangle[level][position];
  }

  if(sum[level][position] != -1){
    return sum[level][position];
  }

  sum[level][position] = triangle[level][position] + 
    max(dp(level + 1, position), dp(level + 1, position + 1));

  return sum[level][position];
}

int main(){
  scanf("%d", &N);
  FOR(i, N){
    fill(sum[i], sum[i] + MAX_N, -1);
    FOR(j, i+1){
      scanf("%d", &triangle[i][j]);
    }
  }
  final = dp(0, 0);
  printf("%d", final);
  return 0;
}