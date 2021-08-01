#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long int ull;

int N;
ull B;
int matrix[6][6], ans[6][6];

void multiply(int matrixA[][6], int matrixB[][6]){
  int temp[6][6] = {0};
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      temp[i][j] = 0;
      for(int k=0;k<N;k++){
        temp[i][j] += matrixA[i][k]*matrixB[k][j];
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      matrixA[i][j] = temp[i][j]%1000;
    }
  }
}

int main(){
  scanf("%d %lld", &N, &B);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j) ans[i][j] = 1;
      scanf("%d", &matrix[i][j]);
    }
  }
  while(B){
    if(B&1) multiply(ans, matrix);
    multiply(matrix, matrix);
    B /= 2;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("%d ", ans[i][j]);
    }
    putchar('\n');
  }
  return 0;
}
