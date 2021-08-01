#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double LLF;
const int INF = 987654321;
#define FOR(i, n) for(int i = 0; i < n; i++)

// DP에 이용할 array, 평균과 차이값의 합을 저장함, sliding window 기법 사용
int *D[2];

// 입력받은 N개의 숫자를 저장하는 곳
int *N_Num;

// M, N번째 항이 M-1번째의 어떤 항을 골랐는지 저장하는 곳
int **track;


int N, M;
LLF avg;

void print_group(){
  return;
}


LLF cal_diff_between_sum_of_group_and_avg(int begin, int end){
  LLF sum = 0;
  for(int i = begin; i < end; i++){
    sum+=N_Num[i];
  }
  return sum-avg;
}

void find_position_of_pointer(){
  for(int i = M-1; i > 0; i--){
    
  }
}


void initialize(){
  FOR(i, N){
    track[M-1][i] = 0;
  }
  int current_window = (M-1) % 2;
  for(int i = M-1; i < N; i++){
    D[current_window][i] = cal_diff_between_sum_of_group_and_avg(i, N+1);
  }
}

//N개의 숫자를 M으로 나누어줍니다.
LLF cal_avg(){
  LLF total = 0;
  FOR(i, N){
    total += N_Num[i];
  }
  return total/(LLF)M;
}

void input(){
  /* 입력을 받는 곳 
    N: 전체 숫자의 개수
    M: 분리할 그룹의 개수
  */
  printf("N과 M을 입력해주세요: \n");
  scanf("%d %d", &N, &M);
  *track = new int[M];
  FOR(i, 2){
    D[i] = new int[N+1];
    fill(D[i], D[i]+N+1, INF);
  }
  FOR(i, M){
    track[i] = new int[N+1];
  }

  N_Num = new int[N];

  printf("N개의 숫자를 입력해주세요");
  FOR(i, N){
    scanf("%d",N_Num[i]);
    printf("%d", N_Num[i]);
  }
}

int main(){
  input();
  avg = cal_avg();
  initialize();
  if(M>2){
    find_position_of_pointer();
  }
  print_group();
  return 0;
}