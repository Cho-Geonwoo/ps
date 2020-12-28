#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 50;
string candy[MAX];
int N;

int num_of_candy(){
    int result = 1;
    for(int i=0;i<N;i++){
        int tmp = 1;
        for(int j=0;j<N-1;j++){
            if(candy[i][j]==candy[i][j+1]){
                tmp++;
            }
            else{
                result = max(result,tmp);
                tmp = 1;
            }
        result = max(result,tmp);
        }
    }
    for(int i=0;i<N;i++){
        int tmp = 1;
        for(int j=0;j<N-1;j++){
            if(candy[j][i]==candy[j+1][i]){
                tmp++;
            }
            else{
                result = max(result,tmp);
                tmp = 1;
            }
        result = max(result,tmp);
        }
    }
    return result;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>candy[i];
    }
    int result = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            swap(candy[i][j], candy[i][j+1]);
            result = max(result, num_of_candy());
            swap(candy[i][j], candy[i][j+1]);
            swap(candy[j][i], candy[j+1][i]);
            result = max(result, num_of_candy());
            swap(candy[j][i], candy[j+1][i]);
        }
    }
    cout<<result<<endl;
    return 0;
}
