#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int N, M;

vector<int> n;

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

void rec(int i, int s) {
   if(s == M || i >= N + 1) {
      if(s == M) {
         for(auto a: n) {
            cout << a << " ";
         }
         cout << '\n';
      }

      return;
   }

   for(int j = 1; j <= N; j++) {
      n[s] = j;
      rec(j, s + 1);
   }
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> M;
   n.resize(M);

   rec(1, 0);

   return 0;
}