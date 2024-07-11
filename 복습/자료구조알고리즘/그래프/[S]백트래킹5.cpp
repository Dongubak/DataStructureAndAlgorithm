#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int N, M;

template<typename T>
std::vector<T> operator+(const std::vector<T>& lhs, const std::vector<T>& rhs) {
   std::vector<T> result = lhs; // lhs를 복사
   result.insert(result.end(), rhs.begin(), rhs.end()); // rhs를 결합
   return result;
}

// void rec(int i, int s, vector<int> n) {
//    if(i >= N + 1) {
//       if(s == M) {
//          for(auto a: n) {
//             cout << a << " ";
//          }
//          cout << '\n';
//       }
//       return;
//    }
//    rec(i + 1, s + 1, n + vector<int>{i});
//    rec(i + 1, s, n);
// }

void rec(int i, int s, vector<int> n) {
   if(s == M || i >= N + 1) {
      if(s == M) {
         for(auto a: n) {
            cout << a << " ";
         }
         cout << '\n';
      }

      return;
   }

   for(int j = i; j <= N; j++) {
      rec(j + 1, s + 1, n + vector<int>{j});
   }
}

int main(void) {
   cin >> N >> M;

   rec(1, 0, vector<int>());

   return 0;
}