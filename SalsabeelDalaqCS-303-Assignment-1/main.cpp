#include <iostream>
#include <fstream>
#include "myfunctions.h"

using namespace std;

int main() {
  // File name
  string fileName = "data.txt";
  int arr[1000];
  int size = 0;

  ifstream inputFile;
  inputFile.open(fileName.c_str());
  if (!inputFile) {
    cout << "Unable to open file" << endl;
    exit(1);
  }
  int num;
  while (inputFile >> num) {
    arr[size++] = num;
  }
  inputFile.close();

  // check if a certain integer exists in the array if the number is present return the index where the number is present
  cout << "Enter a number to check if it exists in the array: ";
  cin >> num;
  try {
    if (check(arr, size, num)) {
      cout << "The number exists in the array" << endl;
    } else {
      cout << "The number does not exist in the array" << endl;
    }
  } catch (...) {
    cout << "An error occurred while checking the number." << endl;
  }

  // A function to modify the value of an integer when called with the index of the integer in the array
  // and return the new value and old value back to the user
  int index, newNum, oldNum;
  cout << "Enter the index of the number you want to modify: ";
  cin >> index;
  cout << "Enter the new number: ";
  cin >> newNum;
  try {
    modify(arr, index, newNum, oldNum);
    cout << "The old number was " << oldNum << " and the new number is " << newNum << endl;
  } catch (...) {
    cout << "An error occurred while modifying the number." << endl;
  }

  // A function that adds a new integer to the end of the array
  cout << "Enter a number to add to the array: ";
  cin >> num;
  try {
    add(arr, size, num);
    cout << "The new array is: ";
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  } catch (...) {
    cout << "An error occurred while adding the number." << endl;
  }

  // A function that intakes an index of an array and removes the integer corresponding to that index
  cout << "Enter the index of the number you want to remove: ";
  cin >> index;
  try {
    remove(arr, size, index);
    cout << "The new array is: ";
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
  } catch (...) {
    cout << "An error occurred while removing the number." << endl;
  }

  return 0;
}
