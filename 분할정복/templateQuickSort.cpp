#include <iostream>
#include <vector>

template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
int partition(std::vector<T>& v, int p, int r) {
    int i = p - 1;
    int j = p;
    T q = v[r]; ///pivot
    while(j != r) {
        if(v[j] < q) {
            swap<T>(v[++i], v[j]);
        }
        j++;
    }
    swap<T>(v[i + 1], v[r]);
    
    return i + 1;
}

template<typename T>
void quickSortRecursive(std::vector<T>& v, int p, int r) {
    if(p < r) {
        int q = partition<T>(v, p, r);
        quickSortRecursive<T>(v, p, q - 1);
        quickSortRecursive<T>(v, q + 1, r);
    }
}

template<typename T>
void quickSort(std::vector<T>& v) {
    quickSortRecursive<T>(v, 0, int(v.size()) - 1);
}

int main(void) {
    using namespace std;
    
    vector<float> v = {11.4, 0.3, 9.5, 4.6, 6.9, 20.3};
    for(auto k: v) {
        cout << k << " ";
    }
    
    cout << '\n';
    
    quickSort<float>(v);
    
    for(auto k: v) {
        cout << k << " ";
    }
    
    cout << '\n';
    
}
