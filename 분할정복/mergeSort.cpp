#include <iostream>
#include <vector>
#include <algorithm>

void merge(int st, int mi, int end, std::vector<int>& v) {
    std::vector<int> tmp(end - st + 1);
    int i = st;
    int j = mi + 1;
    int t = 0;
    
    while(i <= mi && j <= end) {
        if(v[i] <= v[j]) {
            tmp[t++] = v[i++];
        } else {
            tmp[t++] = v[j++];
        }
    }
    
    while(i <= mi) {
        tmp[t++] = v[i++];
    }
    
    while(j <= end) {
        tmp[t++] = v[j++];
    }
    
    t = 0;
    for(int i = st; i <= end; i++) {
        v[i] = tmp[t++];
    }
}

void mergeSort(int st, int end, std::vector<int>& v) {
    if(st < end) {
        int mid = (st + end) / 2;
        mergeSort(st, mid, v);
        mergeSort(mid + 1, end, v);
        merge(st, mid, end, v);
    }
}



int main(void) {
    using namespace std;
    
    vector<int> v(100);
    int i = 100;
    generate(v.begin(), v.end(), [&i]() {
        return i--;
    });
    
    
    for(auto a : v) {
        std::cout << a << " ";
    }
    
    std::cout << '\n';
    
    mergeSort(0, int(v.size()) - 1, v);
    
    for(auto a : v) {
        std::cout << a << " ";
    }
    
    return 0;
}
