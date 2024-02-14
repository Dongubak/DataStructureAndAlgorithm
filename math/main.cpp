#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string n1, n2;
    string result;
    cin >> n1 >> n2;

    int i = n1.size() - 1;
    int j = n2.size() - 1;
    int up = 0;

    while (i >= 0 || j >= 0 || up > 0) {
        int l = (i >= 0) ? n1[i] - '0' : 0;
        int r = (j >= 0) ? n2[j] - '0' : 0;
        int s = l + r + up;

        if (s > 9) { /// Carry exists
            s -= 10;
            up = 1;
        } else { /// No carry
            up = 0;
        }

        result = char(s + '0') + result;

        i--, j--;
    }

    cout << result;

    return 0;
}
