#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void merge(vector<T> &arr, vector<T> &temp_arr,
           int left_pos, int right_pos, int right_end) {
  int start = left_pos;
  int temp_pos = left_pos;
  int left_end = right_pos - 1;
  while (left_pos <= left_end && right_pos <= right_end) {
    if (arr[left_pos] < arr[right_pos]) {
      temp_arr[temp_pos++] = arr[left_pos++];
    } else {
      temp_arr[temp_pos++] = arr[right_pos++];
    }
  }

  while (left_pos <= left_end) {
    temp_arr[temp_pos++] = arr[left_pos++];
  }
  while (right_pos <= right_end) {
    temp_arr[temp_pos++] = arr[right_pos++];
  }

  for (int i = start; i <= right_end; ++i) {
    arr[i] = temp_arr[i];
  }
}

template <typename T>
void merge_sort(vector<T> &arr, vector<T> &temp_arr,
               int left, int right) {
  if (left >= right) return;
  int center = left + (right - left) / 2;
  merge_sort(arr, temp_arr, left, center);
  merge_sort(arr, temp_arr, center + 1, right);
  merge(arr, temp_arr, left, center + 1, right);
}

template <typename T>
void MergeSort(vector<T> &arr) {
  vector<T> temp_arr(arr);
  merge_sort(arr, temp_arr, 0, arr.size() - 1);
}

template <typename T>
int partition(vector<T>& arr, int left, int right) {
  T& pivot = arr[left];
  left++;
  while (left < right) {
    while (left < right && arr[left] <= pivot) ++left;
    while (left < right && arr[right] >= pivot) --right;
    if (left < right) {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }
  if (left == right && arr[right] > pivot) right--;
  swap(pivot, arr[right]);
  return right;
}

template <typename T>
void quick_sort(std::vector<T> &arr, int left, int right) {
  if (left >= right) return;
  int pi = partition(arr, left, right);
  quick_sort(arr, left, pi - 1);
  quick_sort(arr, pi + 1, right);
}

template <typename T>
void QuickSort(std::vector<T> &arr) {
  quick_sort(arr, 0, arr.size() - 1);
}

int main() {
  vector arr{3, 2, 4, 7, 9, 1};

  auto test1 = arr;
  //MergeSort(test1);
  QuickSort(test1);
  for (auto num : test1) {
    cout << num << ", ";
  }
  cout << endl;
}
