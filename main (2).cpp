// Ayan Agayeva Assignment 1
// include the header file and libraries for using the following
#include "function.h" 
#include <fstream> 
#include <iostream> 
#include <vector>
using namespace std;

int main() {
  string fileName; // a string variable to identify the user's file name

  cout << "Enter the name of the text file: ";
  cin >> fileName; // store the input
  ifstream inputFile(fileName);
  if (!inputFile) {
    cout << "Sorry, the file cannot be opened." << endl; // if the file doesnt exist display a message
    return 1;
  }
  vector<int> arr; // declare a vector to store the array, easier to manipulate
  int value;
  while (inputFile >> value) { // read the ints from the file into the vector
    arr.push_back(value); // store the ints ino the vector
  }
  inputFile.close();
  int choice; // users choice from menu
  do { // a loop for the main menu to continue until the user chooses to ext
    cout << "Choose an operation:" << endl;
    cout << "1. Check if integer is in array" << endl;
    cout << "2. Modify value at index" << endl;
    cout << "3. Add integer to array" << endl;
    cout << "4. Replace/Remove value at index" << endl;

    cout << "5. Exit" << endl;
    cin >> choice; // store the user's menu choice
    try {
      switch (choice) { // a switch statemnt handles the user's choice
      case 1: { // check if an int already exists
        int valueToFind;
        cout << "Enter integer to find: ";
        cin >> valueToFind;
        int index = findInteger(arr, valueToFind); // call the function 
        if (index != -1) {
          cout << "Found at index " << index << endl;
        } else {
          cout << "Not found" << endl;
        }
      } 
      break;
      case 2: { // modifying a value @ a specific index
        int index, newValue;
        cout << "Enter index to modify: ";
        cin >> index;
        cout << "Enter new value: ";
        cin >> newValue;
        auto [oldValue, modifiedValue] = modifyInteger(arr, index, newValue); // calling the function
        cout << "Modified value " << oldValue << " to " << modifiedValue
             << endl;
      } break;
      case 3: { // adding an int to the end
        int valueToAdd;
        cout << "Enter integer to add: ";
        cin >> valueToAdd;

        addInteger(arr, valueToAdd); //calling the function
        cout << valueToAdd << " added." << endl;
      } break;
      case 4: { // removing or replacing a val at an index
        int index; // user's chosen index
        char choice; // user's chosen value
        cout << "Enter index to replace/remove: ";
        cin >> index;
        cout << "Do you want to remove (R) or replace (P)? ";
        cin >> choice;
        if (choice == 'R' || choice == 'r') { // calling the function to remove
          removeReplace(arr, index, true);
          cout << "Removed value at index " << index << endl;
        } else if (choice == 'P' || choice == 'p') {
          removeReplace(arr, index, false); // calling the function to replace
          cout << "Replaced value at index " << index << endl;
        } else {
          cout << "Invalid choice" << endl;
        }
      } break;
      case 5: // exiting the program
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice" << endl;
        break;
      }
    } catch (const out_of_range &e) {
      cerr << "Error: " << e.what() << endl;
    }
  } while (choice != 5);
  ofstream outputFile(fileName); // an output file for writing back o the original file
  for (int value : arr) {
    outputFile << value << " "; // writing the modified array bacck to the file
  }
  outputFile.close();
  cout << "Modified Array: ";
  for (int value : arr) {
    cout << value << " "; //displaying the new array
  }
  cout << endl;
  return 0;
}
