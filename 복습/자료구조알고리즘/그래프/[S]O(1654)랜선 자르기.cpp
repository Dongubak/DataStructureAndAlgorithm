#include <iostream>
#include <vector>
#include <cmath>

///5 24: 탐색범위가 1부터 입력받은 값 중 최댓값 사이임 tm - 1로 하니까 틀림;
///탐색 범위를 조정하는 변수값의 타입은 long형이어야 함

using namespace std;

int main(void) {
   long K, N, t;
   cin >> K >> N;

   vector<long> L(K);

   long tm = -1;

   for(int i = 0; i < K; i++) {
      cin >> t;
      L[i] = t;
      tm = max(tm, t);
   }

   long left = 1, right = tm;
   long optL = 1;

   while(left <= right) {
      long m = (left + right) / 2;
      
      long long sum = 0;

      for(int i = 0; i < K; i++) {
         sum += (L[i] / m);
      }
      
      if(sum < N) { ///조각의 수가 기준에 못 미침 -> 더 작게 잘라야 함
         right = m - 1;
      } else {
         left = m + 1;
         optL = m;
      }
   }

   cout << optL;

   return 0;
}