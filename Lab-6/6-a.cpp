#include <iostream>
#include <cstdint>
#include <map>
using namespace std;
 
uint64_t do_thing(uint32_t n) {
    map <int, uint64_t> storage;
    storage[0] = storage[1] = 1;
    for (int i = 2; i <= n; i++) for (int j = 0; j < i; j++) storage[i] += storage[j] * storage[i - j - 1];
    return storage[n - 1];
}
 
int main() {
    int n;
    cin >> n;
    cout << do_thing(n);
}
