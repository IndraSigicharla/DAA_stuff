#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> a(20, 0);
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min = a[0];
    int max = a[0];

    cout << "ITERATOR VALUES: " << endl;
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << endl;
        if (*it < min) {
            min = *it;  
        }
        if (*it > max) {
            max = *it;
        }
    }

    cout << "Min is " << min << " and max is " << max;

}
