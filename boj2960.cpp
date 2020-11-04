#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int main(){
	cin>>N>>K;
	int count = 0;
	bool isprime[N+1];
	fill(isprime, isprime+N+1, true);
	for(int i=2;i<=N;i+=2){
		isprime[i] = false;
		count+=1;
		if(count == K){
			cout<<i<<endl;
			return 0;
		}
	}
	for(int i=3;i<=N;i++){
		if(isprime[i]){	
			isprime[i] = false;
			count+=1;
			if(count==K){
				cout<<i<<endl;
				return 0;
			}
			for(int j = i*i;j<=N;j+=i*2){
				if(isprime[j]){	
					isprime[j] = false;
					count+=1;
					if(count==K){
						cout<<j<<endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}