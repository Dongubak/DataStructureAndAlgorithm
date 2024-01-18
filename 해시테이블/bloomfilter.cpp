#include <iostream>
#include <vector>

class bloom_filter {
    std::vector<bool> data;
    int nBits;
public:

    bloom_filter(int n) : nBits(n) {
        data = std::vector<bool>(nBits, false);
    }

    int hash(int num, int key) {
        switch(num) {
            case 0:
            return key % nBits;
            case 1:
            return key % nBits;
            case 2:
            return key % nBits;
            default:
            return -1;
        }
    }

    void lookup(int key) {
        bool result = data[hash(0, key)] && data[hash(1, key)] && data[hash(2, key)];

        if(result) {
            std::cout << key << "값이 있을 수도 있음" << '\n';
        } else {
            std::cout << key << "값은 무조건 존재하지 않음" << '\n';
        }
    }

    void insert(int key) {
        data[hash(0, key)] = true;
        data[hash(1, key)] = true;
        data[hash(2, key)] = true;

        for(auto a : data) {
            std::cout << a << " ";
        }
        std::cout << '\n';
    }

};

int main(void) {
    using namespace std;
    
    bloom_filter bf(7);
    bf.insert(100);
    bf.insert(54);
    bf.insert(82);

    bf.lookup(5);
    bf.lookup(50);
    bf.lookup(20);
    bf.lookup(54);
    
    return 0;
}