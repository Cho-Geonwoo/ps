#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll;

#define N_MAX 32

using namespace std;

int N, L;
string ans = "";
ll K;

ll dp[N_MAX][N_MAX];

ll binary(int n, int m){ //길이가 n이고 사용된 1의 개수가 m 이하인 이진수의 개수
	ll &ret = dp[n][m];
	if(ret!=-1) return ret;
	if(n==0 || m==0){
		return ret = 1;
	}
	ret = binary(n-1, m);
	if(m>0) ret += binary(n-1, m-1);
	return ret;
}

void skip(int n, int l, ll k){
	if(n==0){
		return;
	}
	if(l==0){
		for(int i=0;i<n;i++){
			ans += '0';
		}
		return;
	}
	int pivot = binary(n-1, l); //길이가 n-1이고 사용된 1의 개수가 l 이하인 이진수의 개수
	if(k<=pivot){
		ans+='0';
		skip(n-1,l,k);
	}
	else{
		ans+='1';
		skip(n-1,l-1,k-pivot);
	}
}

int main(){
	cin>>N>>L>>K; //L개 이하의 비트가 1인 N자리 이진수중 k번째로 큰 수
	memset(dp, -1, sizeof(dp));
	skip(N, L, K);
	cout<<ans<<endl;
	return 0;
}