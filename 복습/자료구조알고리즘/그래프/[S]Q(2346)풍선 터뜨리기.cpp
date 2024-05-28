#include <iostream>
#include <vector>

using namespace std;

int main() {
   int N;
   cin >> N;
   vector<int> moves(N);
   vector<bool> popped(N, false);
   vector<int> result;

   for (int i = 0; i < N; ++i) {
      cin >> moves[i];
   }

   int current = 0; 
   int steps, next;

   for (int i = 0; i < N; ++i) {
      result.push_back(current + 1); 
      popped[current] = true; 
      steps = moves[current]; 

      if (i == N - 1) break; 

      // 다음 풍선 위치 찾기
      while (steps != 0) {
         if (steps > 0) {
               current = (current + 1) % N;
               if (!popped[current]) steps--;
         } else { // 왼쪽 이동
               current = (current - 1 + N) % N;
               if (!popped[current]) steps++;
         }
      }
   }

   // 결과 출력
   for (int num : result) {
      cout << num << " ";
   }

   return 0;
}
