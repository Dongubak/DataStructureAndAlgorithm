// to_string: int값을 string값으로 변환시켜준다.
// string::stoi: string값을 int값으로 변환시켜준다.
// string.find: string에서 부분문자열 substring을 찾는다.

#include <iostream>
#include <string>

using namespace std;

bool containsTripleSix(int number) {
    string s = to_string(number);
    return s.find("666") != string::npos;  // '666'이 포함되어 있는지 확인
}

void sol(int n) {
    int currentNumber = 666;
    int count = 0;

    while (count < n) {
        if (containsTripleSix(currentNumber)) {
            count++;
        }
        if (count < n) {
            currentNumber++;  // n번째를 찾을 때까지 숫자 증가
        }
    }
    cout << currentNumber;
}

int main(void) {
    int n;
    cin >> n;
    sol(n);
    return 0;
}
