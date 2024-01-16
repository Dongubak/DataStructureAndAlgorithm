#include <iostream>
#include <vector>

void swap(int &a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(std::vector<int>& v, int p, int r) {
    int i = p - 1;
    int q = v[r]; ///pivot
    int j = p;
    while(j != r) {
        if(v[j] < q) {
            swap(v[++i], v[j]);
        }
        j++;
    }
    std::cout << "pivot : " << q << '\n';
    for(auto& a: v) {
        std::cout << a << " ";
    }
    std::cout << '\n';
    swap(v[i + 1], v[r]);
    
    
    return i + 1;
}

void quickSortRecursive(std::vector<int>& v, int p, int r) {
    if(p < r) {
        int q = partition(v, p, r); ///index of pivot
        quickSortRecursive(v, p, q - 1);
        quickSortRecursive(v, q + 1, r);
    }
}

void quickSort(std::vector<int>& v) {
    quickSortRecursive(v, 0, int(v.size()) - 1);
}

int main(void) {
    using namespace std;
    vector<int> v(10, -1);
    int t = 10;
    for(auto& a: v) {
        a = t--;
    }
    
    for(auto& a: v) {
        cout << a << " ";
    }
    cout << '\n';
    
    quickSort(v);
    
    for(auto& a: v) {
        cout << a << " ";
    }
    cout << '\n';
    
    
    return 0;
}
