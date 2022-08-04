#include <iostream>
using namespace std;

class Point {
    public:
        int x, y;

        friend ostream& operator<<(ostream& os, Point& p);
        friend istream& operator>>(istream& is, Point& p);

        Point(int i = 0, int j = 0) : x(i), y(j) {}

            bool operator< (Point& p) {
                Point p1;
                if (p.x < p1.x || (p.x == p1.x && p.y < p1.y)) return true;
                else if (p.x == p1.x) {

                }
                return false;
            }
        
            bool operator> (Student& s) {
                Student s1;
                if (s.marks > s1.marks) return true;
                return false;
            }
};

int insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

ostream& operator<<(ostream& os, Point& p) {
    string output = "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
    os << output;
    return os;
}

istream& operator>>(istream& is, Point& p){
    is >> p.x >> p.y;
    return is;
}

void printer(int arr[], int n) {
    // cout << "The elements in the array is: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main() {
    // cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    Point arr[n];

    // cout << "Enter the elements: ";

    for (int i = 0; i < n; i++) cin >> arr[i];

    insertion_sort(arr, n);
}
