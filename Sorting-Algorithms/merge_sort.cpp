#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high){
  vector<int>temp;

  int left = low;
  int right = mid + 1;

  // This loop runs while there are elements on both the arrays
  while(left <= mid && right <= high){
    if(arr[left] <= arr[right]){
      temp.push_back(arr[left]);
      left++;
    }
    else{
      temp.push_back(arr[right]);
      right++;
    }
  }

  // This is executed when there are some elements left on the left Array
  while(left <= mid){
    temp.push_back(arr[left]);
    left++;
  }

  // This is executed when there are some elements left on the right Array
  while(right <= high){
    temp.push_back(arr[right]);
    right++;
  }

  // Copies the elements from the temp Array to the original Array
  for(int i = low; i <= high; i++){
    arr[i] = temp[i - low];
  }
}

void mergeSort(vector<int>& arr, int low, int high){
  if(low >= high)
    return;

  int mid = (low + high)/2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  merge(arr, low, mid, high);
}

void printArray(vector<int>arr){
  for(auto i : arr){
    cout << i << " ";
  }
  cout << endl;
}

int main() {

  vector<int> arr = {2,5,3,1,7,6,9,2};
  mergeSort(arr, 0, arr.size() - 1);
  printArray(arr);

  return 0;
}
