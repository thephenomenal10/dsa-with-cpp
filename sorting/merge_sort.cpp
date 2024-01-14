#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int k = low;
    int temp[20];
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k] = arr[left];
            left++;
        }
        else
        {
            temp[k] = arr[right];
            right++;
        }
        k++;
    }

    while (left <= mid)
    {
        temp[k] = arr[left];
        left++, k++;
    }
    while (right <= high)
    {
        temp[k] = arr[right];
        right++, k++;
    }

    // copy sorted array stored in temp to actual array
    for (int i = low; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    // int mid = low + (high - low) / 2;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[7] = {23, 9, 5, 11, 2, 72, 44};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Given unsorted array" << endl;
    displayArray(arr, size);
    mergeSort(arr, 0, size - 1);
    cout << endl
         << "Sorted array" << endl;
    displayArray(arr, size);
    return 0;
}