#include "function.h" // include the header file
#include <stdexcept> // necessary for exception handling
using namespace std;

//function to find an int + return its index 
int findInteger(const vector<int> &arr, int value) {
  for(int i = 0; i < arr.size(); i++) {
    if (arr[i] == value) {
      return i; // return the index where the val is found
    }
  }
  return -1; // not found 
}

// function to modify the value at an int
pair<int, int> modifyInteger(vector<int> & arr, int index, int newVal) {
    if (index < 0 || index >= arr.size()) {
      throw out_of_range("Index out of range"); // throw this exception if the index is invalid
    }
    int oldVal = arr[index]; // store the old val before modifying
    arr[index] = newVal; // update the val at the user's chosen index
    return {oldVal, newVal}; // return a pair containing the old and new val
  }
// function to remove or replace the val @ a speicif index
void addInteger(vector<int> & arr, int value) { arr.push_back(value); 
              }
  void removeReplace(vector<int> & arr, int index, bool remove) {
    if (index < 0 || index >= arr.size()) {
      throw out_of_range("Index out of range"); // throw his exception if the index is invalid
    }
    if (remove) {
      arr.erase(arr.begin() + index); // erase the element at the index
    } else {
      arr[index] = 0; // replace the element at the specific index w/ 0
    }
  }
