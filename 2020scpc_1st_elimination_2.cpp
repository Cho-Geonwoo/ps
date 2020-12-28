#include <iostream>
#include <stdio.h>

using namespace std;

int Answer_a, Answer_b;

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k;
	int T, test_case;
	int tmp_x, tmp_y;
	int sum;
	int big;
	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
        Answer_a = 1;
        Answer_b = 2;
        cin >> n >> k;
        int mat[n+1][n+1];
        int x_card[n];
        int y_card[n];
        for(int i=0;i<n;i++){
            cin >> x_card[i];
        }
        for(int i=0;i<n;i++){
            cin >> y_card[i];
        }
        mat[0][0] = 0;
        mat[1][0] = 1;
        mat[0][1] = 1;
        //모든 경우의 수에 대해 1번 케이슨지 2번 케이슨지 판단하는 코드
        for(int i=2;i<=2*n;i++){
            big = max(i-n, 0);
            for(int j=big; j<=i; j++){
                sum = 0;
                tmp_x = i-j;
                tmp_y = j;
                if((tmp_x>n)||(tmp_y>n)){
                    continue;
                }
                //각각 case에 대해 case1인지 2인지 판단
                mat[tmp_x][tmp_y] = 1;
                for(int t=1;t<(tmp_x+1);t++){
                    sum+=x_card[tmp_x-t];
                    if(mat[tmp_x-t][tmp_y]==1){
                        mat[tmp_x][tmp_y] = 0;
                        break;
                    }
                    if(sum>=k){
                        break;
                    }
                }
                sum = 0;
                if(mat[tmp_x][tmp_y]){
                    for(int t=1;t<(tmp_y+1);t++){
                        sum+=y_card[tmp_y-t];
                        if(mat[tmp_x][tmp_y-t]==1){
                            mat[tmp_x][tmp_y] = 0;
                            break;
                        }
                        if(sum>=k){
                            break;
                        }
                    }
                }
                if(mat[tmp_x][tmp_y]){
                    Answer_b++;
                }
                else{
                    Answer_a++;
                }
            }
        }
		cout << "Case #" << test_case+1 << endl;
		cout << Answer_a << endl;
		cout << Answer_b << endl;
	}
	return 0;
}
