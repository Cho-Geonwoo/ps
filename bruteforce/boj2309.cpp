#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;
int series[MAX];
int main(){
    int m = 0;
    int sum = 0;
    for(int i=0;i<MAX;i++){
        cin>>series[i];
        sum+=series[i];
    }
    sum-=100;
    for(int a=0;a<8;a++){
        for(int b=a+1;b<9;b++){
            if((series[a]+series[b])==sum){
                series[a]=0;
                series[b]=0;
                m = 1;
                break;
            }
        }
        if(m==1){
            break;
        }
    }
    sort(series,series+9);
    for(int j=2;j<9;j++){
        cout<<series[j]<<endl;
    }
    return 0;
}
