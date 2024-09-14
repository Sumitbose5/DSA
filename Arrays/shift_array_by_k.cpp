#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


// BRUTEFORCE APPROACH --->
void solve(vector<int>&arr, int k){
  vector<int>temp = arr;
  int i = arr.size() - k, j = 0;
  while(i < arr.size()){
    arr[j] = temp[i];
    i++; 
    j++;
  }
  i = 0;
  while(i < arr.size() - k){
    arr[j] = temp[i];
    i++;
    j++;
  }
}


// OPTIMISED APPROACH --->
void rightShiftArray(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // In case k is larger than the size of the array

    // Step 1: Reverse the whole array
    reverse(arr.begin(), arr.end());

    // Step 2: Reverse the first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Step 3: Reverse the remaining n-k elements
    reverse(arr.begin() + k, arr.end());
}

void printArr(vector<int>&arr){
  for(auto i : arr){
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  
  // PRogram TO shift array by k
  vector<int>arr = {10,20,30,40,50,60,70};
  // op -> 40 50 60 10 20 30 (here k is 3)
  printArr(arr);
  // solve(arr, 4);
  
  rightShiftArray(arr, 3);
  printArr(arr);

  return 0;
}
