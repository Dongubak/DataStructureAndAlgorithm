#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

int N;
vector<int> O; ///operator
vector<int> A;

long long min = 10e8;
long long max = -10e8;

void rec(int i, vector<int> selected, vector<int> curOper) {
   if(i >= N - 1) {

      long long res = A[0];
      for(int j = 1; j < N; j++) {
         if(selected[j - 1] == 1) {
            res = res + A[j];
         } else if(selected[j - 1] == 2) {
            res = res - A[j];
         } else if(selected[j - 1] == 3) {
            res = res * A[j];
         } else {
            res = res / A[j];
         }
      }
      max = std::max(max, res);
      min = std::min(min, res);

      return ;
   }

   for(int j = 0; j < 4; j++) {
      auto copyS = selected;
      auto copyO = curOper;

      if(curOper[j] > 0) {
         copyS[i] = j + 1;
         copyO[j] -= 1;

         rec(i + 1, copyS, copyO);
      }
   }
}

void sol() {
   rec(0, vector<int>(N - 1, 0), O);
}

int main(void) {
   cin >> N;
   
   A.resize(N);
   O.resize(4);

   for(int i = 0; i < N; i++) {
      cin >> A[i];
   }

   for(int i = 0; i < 4; i++) {
      cin >> O[i];
   }

   sol();

   cout << max << '\n' << min;
   return 0;
}