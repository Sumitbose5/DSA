#include <iostream>
#include<vector>
using namespace std;

// Find missing element from range 0-n
int solve(vector<int>&arr){
  int n = arr.size();
  int arrSum = 0;
  for(auto i : arr){
    arrSum += i;
  }

  int actualSum = (n*(n+1)) / 2;
  return actualSum - arrSum;
}

int main() {

  vector<int>arr = {0,1,2,3,4};
  int ans = solve(arr);
  cout << "Missing Number : " << ans << endl;

  return 0;
}
