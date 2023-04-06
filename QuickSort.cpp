#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int medianOf3(int arr[], int left, int right) {
    int mid = (left + right) / 2;
    if (arr[right] < arr[left])
        swap(arr[left], arr[right]);
    if (arr[mid] < arr[left])
        swap(arr[left], arr[mid]);
    if (arr[right] < arr[mid])
        swap(arr[mid], arr[right]);
    return arr[mid];
}

int partition(int arr[], int left, int right) {
    int pivot = medianOf3(arr, left, right);
    int i = left - 1;
    int j = right + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quicksort(arr, left, p);
        quicksort(arr, p + 1, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sorting:" << endl;
    printArray(arr, size);
    quicksort(arr, 0, size - 1);
    cout << "After sorting:" << endl;
    printArray(arr, size);
    return 0;
}
