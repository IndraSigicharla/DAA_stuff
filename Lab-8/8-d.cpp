#include <iostream>
#include <queue>
#include <set>
using namespace std;

class activity {
public:
    string name;
    int start;
    int finish;
    friend istream &operator>>(istream &, activity &);
    friend ostream &operator<<(ostream &, const activity &);
    bool operator<(const activity &) const;
};

istream &operator>>(istream &in, activity &a) {
    in >> a.name >> a.start >> a.finish;
    return in;
}

ostream &operator<<(ostream &out, const activity &a) {
    out << a.name << " ";
    return out;
}

bool activity::operator<(const activity &a) const {
    if (a.start == start) return a.finish > finish;
    return a.start > start;
}

void recursive_activity_selector(priority_queue<activity> &pq, vector<activity> &v) {
    activity a;
    a = pq.top();
    pq.pop();
    cout << a.name << endl;
    v.push_back(a);
    while (!pq.empty() && pq.top().finish > a.start) pq.pop();
    if (!pq.empty()) recursive_activity_selector(pq, v);
    else return;
}

int main() {
    priority_queue<activity> pq;
    int n, i;
    activity a;
    vector<activity> v;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }
    recursive_activity_selector(pq, v);
    for (auto a = v.rbegin(); a != v.rend(); a++) cout << *a;
}
