#include <iostream>
#include <cmath>

using namespace std;

int N;

int t_num(int n){
    return (n*(n+1)/2);
}

int can_be_expressed(int num){
    int range = (-1+sqrt(1+8*num))/2;
    for(int i=1;i<=range;i++){
        for(int j=1;j<=range;j++){
            for(int k=1;k<=range;k++){
                if((t_num(i)+t_num(j)+t_num(k))==num){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    cin>>N;

    int testcase[N];
    for(int i=0;i<N;i++){
        cin>>testcase[i];
    }
    for(int j=0;j<N;j++){
        cout<<can_be_expressed(testcase[j])<<endl;
    }
    return 0;
}
