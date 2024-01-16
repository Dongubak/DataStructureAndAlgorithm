#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <ctime>

bool linear_search(int n, std::vector<int>& s) {
    for(auto i : s) {
        if(i == n) {
            return true;
        }
    }
    
    return false;
}

bool binarySearchRecursive(int n, int st, int end, std::vector<int>& s) {
    if(st > end) {
        return false;
    } else {
        int mid = (st + end) / 2;
        if(n == s[mid]) {
            return true;
        } else if(n < s[mid])  {
            return binarySearchRecursive(n, st, mid - 1, s);
        } else {///}(n > s[i])
            return binarySearchRecursive(n, mid + 1, end, s);
        }
    }
}

bool binarySearch(int N, std::vector<int>& s) {
    return binarySearchRecursive(N, 0, int(s.size()) - 1, s);
}

int main(void) {
    srand(unsigned(time(0)));
    using namespace std;
    
    vector<int> a(100);
    generate(a.begin(), a.end(), []() {
        return rand() % 100;
    });
    sort(a.begin(), a.end());
    
    for(auto i : a) {
        cout << i << " ";
    }
    cout << '\n';
    cout << binarySearch(10, a);
    
    
    
    
    return 0;
}
