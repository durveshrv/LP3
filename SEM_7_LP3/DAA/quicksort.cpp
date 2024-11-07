#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// Function to perform deterministic Quick Sort
int deterministicPartition(vector<int> &arr, int low, int high) {
  int pivot = arr[low]; // Pivot is the first element
  int left = low + 1;
  int right = high;

  while (true) {
    while (left <= right && arr[left] <= pivot) {
      left++;
    }
    while (left <= right && arr[right] >= pivot) {
      right--;
    }
    if (left > right) {
      break;
    }
    swap(arr[left], arr[right]);
  }
  
  swap(arr[low], arr[right]); //if left and right crossed then swap right and pivot.
  return right;
}

void deterministicQuickSort(vector<int> &arr, int low, int high,
                            int &comparisons, int &swaps) {
  //if has more than one element
  if (low < high) {
    int pivotIndex = deterministicPartition(arr, low, high);
    comparisons += (high - low); // Count comparisons made during partition
    swaps += 2;                  // Count the swaps made during partition

    deterministicQuickSort(arr, low, pivotIndex - 1, comparisons, swaps);
    deterministicQuickSort(arr, pivotIndex + 1, high, comparisons, swaps);
  }
}

// Function to perform randomized Quick Sort
int randomizedPartition(vector<int> &arr, int low, int high) {
  int pivotIndex = low + rand() % (high - low + 1);
  swap(arr[low], arr[pivotIndex]); // Swap pivot with the first element
  int pivot = arr[low];
  int left = low + 1;
  int right = high;

  while (true) {
    while (left <= right && arr[left] <= pivot) {
      left++;
    }
    while (left <= right && arr[right] >= pivot) {
      right--;
    }
    if (left > right) {
      break;
    }
    swap(arr[left], arr[right]);
  }
  swap(arr[low], arr[right]);
  return right;
}

void randomizedQuickSort(vector<int> &arr, int low, int high, int &comparisons,
                         int &swaps) {
  if (low < high) {
    int pivotIndex = randomizedPartition(arr, low, high);
    comparisons += (high - low); // Count comparisons made during partition
    swaps += 2;                  // Count the swaps made during partition

    randomizedQuickSort(arr, low, pivotIndex - 1, comparisons, swaps);
    randomizedQuickSort(arr, pivotIndex + 1, high, comparisons, swaps);
  }
}

// Function to print the array
void printArray(const vector<int> &arr) {
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  srand(time(0)); // Seed for random number generation

  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  vector<int> arr1(n);
  cout << "Enter elements: \n";
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  vector<int> arr2 = arr1;
  int ch;
  while (1) {

    int comparisonsDet = 0, swapsDet = 0;
    int comparisonsRand = 0, swapsRand = 0;

    cout << "1.Deterministic Quick Sort\n2.Randomized Quick Sort\n3.Exit\n";
    cout << "Enter your choice: ";
    cin >> ch;
    switch (ch) {
    case 1:
      cout << "Original array for deterministic quick sort:\n";
      printArray(arr1);

      deterministicQuickSort(arr1, 0, arr1.size() - 1, comparisonsDet,
                             swapsDet);

      cout << "Sorted array (Deterministic):\n";
      printArray(arr1);
      cout << "Deterministic Quick Sort Comparisons: " << comparisonsDet
           << endl;
      cout << "Deterministic Quick Sort Swaps: " << swapsDet << endl;
      break;
    case 2:
      // Perform randomized quick sort
      cout << "\nOriginal array for randomized quick sort:\n";
      printArray(arr2);

      randomizedQuickSort(arr2, 0, arr2.size() - 1, comparisonsRand, swapsRand);

      cout << "Sorted array (Randomized):\n";
      printArray(arr2);
      cout << "Randomized Quick Sort Comparisons: " << comparisonsRand << endl;
      cout << "Randomized Quick Sort Swaps: " << swapsRand << endl;
      break;
    case 3:
      exit(0);
      break;
    }
  }

  return 0;
}

/*
In QuickSort, each partition divides the array around a pivot element, ensuring all elements on the left are smaller (or equal) and all on the right are greater (or equal) to the pivot. 
Then, the process recursively sorts the left and right subarrays.


Case	Time Complexity	Space Complexity
Best case	O(n log n)	O(log n)
Average case	O(n log n)	O(log n)
Worst case	O(n^2)	O(n)

FOR SPACE COMPLEXITY:
1)In the best case (when the pivot splits the array evenly), the recursion depth is O(log n). This is because each partition splits the array into two halves.
2)In the worst case (when the pivot selection leads to unbalanced partitions), the recursion depth is O(n), since one partition may have only one element,
and the recursion proceeds linearly.


FOR TIME COMPLEXITY:
1)BEST CASE
What happens: When QuickSort picks a good pivot, it divides the array roughly into two equal halves.

How many steps: At each level of recursion, the array is split into two parts. So, at each level, you process half of the array.

First level: n elements.
Second level: n/2 elements (for each of the two subarrays).
Third level: n/4 elements (for each of the four subarrays).
And so on...
How deep is the recursion: It keeps dividing in half, so the number of levels is log2n (logarithmic depth).

2) WORST CASE
What happens: If QuickSort always picks the worst possible pivot (e.g., the smallest or largest element), it divides the array poorly, resulting in one large subarray and one small subarray.

How many steps:

First level: n elements.
Second level: n-1 elements (since one side has only one element, and the other has n-1).
Third level: n-2 elements, and so on...
How deep is the recursion: The recursion depth will be n because you’re reducing the size of the array by only 1 at each step.

Time spent at each level: Since you are still processing all the elements at each level, time at each level is O(n).

Total Time in Worst Case:

There are O(n) levels (since each level only reduces the array by 1).
At each level, you spend O(n) time.
So, total time = O(n²).


*/

