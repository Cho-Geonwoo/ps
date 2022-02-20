#include <iostream>
#include <algorithm>
using namespace std;

#define n 11
struct problem{
    int time;
    int incorrect;
};

bool compare(problem a, problem b){
    return(a.time<b.time);
}

int main(){
    problem p[11];
    for(int i=0;i<11;i++){
        cin>>p[i].time>>p[i].incorrect;
    }
    sort(p,p+11,compare);
    int penalty = 0;
    int time = 0;
    for(int i=0;i<11;i++){
        time+=p[i].time;
        penalty += (time+p[i].incorrect*20);
    }
    cout<<penalty;
    return 0;
}
