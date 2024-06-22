#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

vector<vector<int>> sq;

int max = 0;

int main(void) {
   int n, m;
   cin >> n >> m;

   sq.resize(n, vector<int>(m));
   cin.get();
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         sq[i][j] = cin.get() - '0';
      }
      cin.get();
   }

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         for(int l = 0; l < std::min(n, m); l++) {
            if(j + l < m && i + l < n) {
               if((sq[i][j] == sq[i][j + l]) &&
                  (sq[i + l][j] == sq[i + l][j + l]) &&
                  (sq[i][j] == sq[i + l][j + l])) {
                     
                     max = std::max((l + 1) * (l + 1), max);
                  }
            }
         }
      }
   }

   cout << max;


   return 0;
}