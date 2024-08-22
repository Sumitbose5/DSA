#include <iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr){
  for(int i=1; i<arr.size(); i++){
    int j = i;
    while(j > 0 && arr[j] < arr[j-1]){
      swap(arr[j], arr[j-1]);
      j--;
    }
  }
}

void printArray(vector<int>arr){
  for(auto i : arr){
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  
  vector<int> arr = {2,8,5,3,9,4,1};
  insertionSort(arr);
  printArray(arr);
  
  return 0;
}
