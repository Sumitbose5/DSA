#include <iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;


void rotate(vector<vector<int>>&arr){
  // Transpose
  for(int i=0; i<arr.size(); i++){
    for(int j=i; j<arr[i].size(); j++){
      swap(arr[i][j], arr[j][i]);
    }
  }

  // Reverse
  for(int i=0; i<arr.size(); i++){
    reverse(arr[i].begin(), arr[i].end());
  }
}

void printArr(vector<vector<int>>&arr){
  for(int i=0; i<arr.size(); i++){
    for(int j=0; j<arr[0].size(); j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {

  vector<vector<int>>arr = {{1,2,3},
                            {4,5,6},
                            {7,8,9}};

  printArr(arr);
  cout << endl << endl;
  rotate(arr);
  printArr(arr);




  return 0;
}
