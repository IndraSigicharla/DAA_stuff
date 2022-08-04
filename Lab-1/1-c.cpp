#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    public:
        int marks;
        string name, regno;

        friend ostream& operator<<(ostream& os, Student& s);
        friend istream& operator>>(istream& is, Student& s);

        bool operator< (Student& s) {
            Student s1;
            if (s.marks < s1.marks) return true;
            return false;
        }
        
        bool operator> (Student& s) {
            Student s1;
            if (s.marks > s1.marks) return true;
            return false;
        }
};

ostream& operator<<(ostream& os, Student& s) {
    string output = "(" + s.regno + " " + s.name + " " + to_string(s.marks) + ")";
    os << output;
    return os;
}

istream& operator>>(istream& is, Student& s){
    is >> s.regno >> s.name >> s.marks;
    return is;
}

int main() {
    int n;
    Student element;
    vector<Student> a;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        a.emplace_back(element);
    }

    Student min = a[0];
    Student max = a[0];

    cout << "ITERATOR VALUES: " << endl;
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << endl;
        if (*it < min) min = *it;  
        if (*it > max) max = *it;
    }

    cout << "Min is " << min << " and max is " << max;
}

