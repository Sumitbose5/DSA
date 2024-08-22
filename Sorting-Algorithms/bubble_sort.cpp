#include <iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr){
  for(int i=0; i<arr.size(); i++){
    for(int j=1; j<arr.size()-i; j++){
      if(arr[j] < arr[j-1]){
        swap(arr[j], arr[j-1]);
      }
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
  bubbleSort(arr);
  printArray(arr);


  return 0;
}
