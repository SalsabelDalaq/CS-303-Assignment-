#include "myfunctions.h"

bool check(int arr[], int size, int num) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == num) {
      return true;
    }
  }
  return false;
}

void modify(int arr[], int index, int &num, int &old) {
  old = arr[index];
  arr[index] = num;
}

void add(int arr[], int &size, int num) {
  arr[size++] = num;
}

void remove(int arr[], int &size, int index) {
  for (int i = index; i < size; i++) {
    arr[i] = arr[i + 1];
  }
  size--;
}
