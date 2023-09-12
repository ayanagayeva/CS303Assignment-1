#define FUNCTIONS_H
#include <vector>
using namespace std;
// all the function declarations are here
// the & is used to indicate that arr is a reference to our array, it is passed by reference
int findInteger(const vector<int>& arr, int value);

pair<int, int> modifyInteger(vector<int>& arr, int index, int newValue); 
// the function returns a pair of integers after modifying the value at the specific index and replacing it with the new value
void addInteger(vector<int>& arr, int value);
// the function does not return anything, it just adds an int to the end of the array 
void removeReplace(vector<int>& arr, int index, bool remove);
// the function takes a bool remove parameter which indicates if it should remove the int at a specific index (true) or replace it with 0 (false)