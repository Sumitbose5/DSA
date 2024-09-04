#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr, int low, int high){
  int pivot = arr[low];
  int i = low;
  int j = high;

  while(i < j){
    while(arr[i] <= pivot && i <= high - 1){
      i++;
    }
    while(arr[j] > pivot && j >= low + 1){
      j--;
    }
    if(i < j) swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int>&arr, int low, int high){
  if(low < high){
    int pIndex = partition(arr, low, high);
    quickSort(arr, low, pIndex-1);
    quickSort(arr, pIndex+1, high);
  }
}

void printArr(vector<int>&arr){
  for(int i=0; i<arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){
  vector<int> arr = {2,5,3,1,7,6,9,2};
  printArr(arr);
  quickSort(arr, 0, arr.size() - 1);
  printArr(arr);
}
