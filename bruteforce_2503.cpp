#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<string, pair<int, int> > > v;
bool successful(vector<int> &temp)
{
        bool flag = true;
        for (int i = 0; i < v.size(); i++)
        {
                 int s = 0, b = 0;
                 for(int j=0; j<temp.size(); j++)
                         for (int k = 0; k < 3; k++)
                         {
                                 if (temp[j] == (v[i].first[k] - '0'))
                                 {
                                          if (j == k)
                                                  s++;
                                          else
                                                  b++;
                                          break;
                                 }
                         }
                 if ((s != v[i].second.first) || (b != v[i].second.second))
                 {
                         flag = false;
                         break;
                 }
        }
        return flag;
}

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> N;
        for (int i = 0; i < N; i++)
        {
                 string num;
                 int s, b;
                 cin >> num >> s >> b;
                 v.push_back({ num, {s, b} });
        }
        long long result = 0;
        for (int i = 1; i <= 9; i++)
        {
                 vector<int> baseball;
                 baseball.push_back(i);
                 for (int j = i + 1; j <= 9; j++)
                 {
                         baseball.push_back(j);
                         for (int k = j + 1; k <= 9; k++)
                         {
                                 baseball.push_back(k);
                                 do
                                 {
                                          if (successful(baseball))
                                                  result++;
                                 } while (next_permutation(baseball.begin(), baseball.end()));
                                 baseball.pop_back();
                         }
                         baseball.pop_back();
                 }
                 baseball.pop_back();
        }
        cout << result << "\n";
}

