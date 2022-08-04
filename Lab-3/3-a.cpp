#include <iostream>
using namespace std;

#include <vector>
#include <ctime>

void combine(vector<int> &toBeSorted, int left, int mid, int right) {
    vector<int> left_arr, right_arr;
    int size_l = mid - left + 1, size_r = right - mid;
    int l_pointer = 0, r_pointer = 0; 
    int n = left;

    for (int i = 0; i < size_l; i++) left_arr.push_back(toBeSorted[left + i]);
    for (int i = 0; i < size_r; i++) right_arr.push_back(toBeSorted[mid + i + 1]);

    while ((l_pointer < size_l) && (r_pointer < size_r)) {
        if (left_arr[l_pointer] < right_arr[r_pointer]) toBeSorted[n++] = left_arr[l_pointer++];
        else toBeSorted[n++] = right_arr[r_pointer++];
    }

    while (l_pointer < size_l) toBeSorted[n++] = left_arr[l_pointer++];
    while (r_pointer < size_r) toBeSorted[n++] = right_arr[r_pointer++];
}

void merge(vector<int> &toBeSorted, int left, int right) {
    int mid;
    if (left == right) return;
    mid = (left + right) / 2;
    merge(toBeSorted, left, mid);
    merge(toBeSorted, mid + 1, right);
    combine(toBeSorted, left, mid, right);
}

int main() {
    int n, element;
    vector<int> toBeSorted;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> element;
        toBeSorted.push_back(element);
    }

    clock_t tStart = clock();
	merge(toBeSorted, 0, n - 1);
	double time1 = (double) (clock() - tStart)/CLOCKS_PER_SEC;
	cout << n << ", " << time1 * 1000 << ", " << n << endl;

    // for (int i = 0; i < n; i++) cout << toBeSorted[i] << " ";
}

