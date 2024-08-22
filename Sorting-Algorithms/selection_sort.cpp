#include <iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr){
  for(int i = 0; i < arr.size(); i++){
    // Stores the current index as minimum index and compares further
    int currMinIndex = i;
    for(int j = i + 1; j < arr.size(); j++){
      // Compares with further indices and update the currMinIndex with the 
      // smallest index in the range i + 1 to size - 1 index.
      if(arr[currMinIndex] > arr[j]){
        currMinIndex = j;
      }
    }
    // Swapping the current index with the minimun index 
    swap(arr[currMinIndex], arr[i]);
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
  selectionSort(arr);
  printArray(arr);

  return 0;
}
