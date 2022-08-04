#include <iostream>
using namespace std;

#include <ctime>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    int arr[n];

    // cout << "Enter the elements: ";

    for (int i = 0; i < n; i++) cin >> arr[i];

    clock_t tStart = clock();
    insertion_sort(arr, n);
	double time1 = (double) (clock() - tStart)/CLOCKS_PER_SEC;
	cout << n << ", " << time1 * 1000 << ", " << n << endl;

}
