#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     int N, K;
     cin >> N >> K;
     vector<int> v(N);
     for (int i = 0; i < N; i++) {
        cin >> v[i];
     } // 예외 처리
     if (K >= N) {
        cout << "0";
        return 0;
     }
     sort(v.begin(), v.end());
     vector<int> diff(N - 1);
     for (int i = 0; i < N - 1; i++) {
        diff[i] = v[i + 1] - v[i];
    }
    sort(diff.begin(), diff.end());
    int result = 0;
    for (int i = 0; i < N - K; i++) {
        result += diff[i];
    }
    cout << result << "\n";
    return 0;
}
