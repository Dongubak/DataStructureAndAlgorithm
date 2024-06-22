#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

vector<vector<int>> in;
int n;
void rec(const vector<int>& A, const int ai, int i, 
         int n, vector<int> selected, pair<int, int>& max) {
   // A : linear
   // ai : linear index
   // i : index in linear
   // n : the number of selected element
   // sum : current summation of selected vector
   if(i == A.size() || n == 3) {
      if(n != 3) {
         return;
      }
      auto [cMax, index] = max;

      cMax = cMax % 10;

      int sum = 0;
      for(auto a: selected) {
         // cout << a << " ";
         sum += a;
      }
      
      // cout << "\nsum : " << sum << '\n';
      
      sum = sum % 10;

      if(sum > cMax) {
         max = {sum, ai};
      } else if(sum == cMax) {
         if(ai > index) {
            max = {sum, ai};
         }
      }

      return;
   }

   rec(A, ai, i + 1, n, selected, max);
   selected.push_back(A[i]);

   rec(A, ai, i + 1, n + 1, selected, max);
}

void sol() {
   pair<int, int> max(-1, -1);

   for(int i = 0; i < ::n; i++) {
      rec(in[i], i, 0, 0, vector<int>(), max);
   }

   auto [d, index] = max;
   cout << index + 1 << '\n';
}

int main(void) {
   cin >> n;

   in.resize(n, vector<int>(5));

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < 5; j++) {
         cin >> in[i][j];
      }
   }

   sol();

   return 0;
}