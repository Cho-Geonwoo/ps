#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
  string input;
  cin >> input;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string num;
  bool isMinus = false;
  int result = 0;

  for(int i=0; i<=input.size(); i++){
    if(input[i] == '-' || input[i] == '+' || i==input.size()){
      if (isMinus){
        result -= stoi(num);
      }
      else{
        result += stoi(num);
      }
      num = "";
    }
    else{
      num += input[i];
    }
    if(input[i] == '-'){
      isMinus = true;
    }
  }

  cout << result;
  return 0;
}