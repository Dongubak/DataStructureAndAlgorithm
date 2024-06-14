// 1 ~ 4라고 하면
// 4 / 2개 고르면 나머지가 정해짐

// 고른 후에 만약 (1, 3) 과 (2, 4) 가 골라졌다면
// abs((s[1][3] + s[3][1]) - (s[2][4] + s[4][2])) 를 해줌

// 그러면 3개가 골라진 경우는 어떨까

// 1 ~ 6개 라고 하면
// 6 / 2개 고르면 나머지가 정해짐
// (1, 3, 5) 와 (2, 4, 6) 이 골라졌다면
// (s[1][3] + s[3][1] + s[3][5] + s[5][3] + s[1][5] + s[5][1])
// (s[2][4] + s[4][2] + s[4][6] + s[6][4] + s[2][6] + s[6][2])

// 그러면 팀 1과 팀 2의 각각의 합을 전달하면서 재귀함수를 호출하면 

// rec(현재 순회하고 있는 곳, 팀1의 합, 팀2의 합)

// 만약 1을 골랐다면 아직 못 구하고 이후 2를 골랐다면 [1][2] + [2][1]로 구할 수 있다.
// 이후에 3을 골랐다면 [1][2] + [2][1] + 새로들어온 3에 대해서 1과 2를 골라서 넣으면
// [1][2] + [2][1] + [3][1] + [1][3] + [2][3] + [3][2]

// 그렇다면 팀 1에 속해있는 수들, 팀2에 속해있는 수들, 팀1의 합, 팀2의 합, 현재 순회하고있는 곳의 정보
// 5개의 파라미터가 필요할 것이다.

// n : 행의 수
// min : 차의 최솟값
// s : 주어진 데이터
// rec(T1[], T2[], T1Sum, T2Sum, i) {
//    if(i >= n) {
//       if(T1.size() == 3) {
//          min <- min(T1Sum - T2Sum, min)
//       }
//       return
//    }


//    T1.push(i)
//    T1nextSum <- T1Sum
   
//    for a in T1 {
//       T1nextSum += s[i][a] + s[a][i]
//    }

//    rec(T1, T2, T1nextSum, T2Sum, i + 1)

//    T1.pop();
//    T2.push(i)
//    T2nextSum <- T2Sum

//    for a in T2 {
//       T2nextSum += s[i][a] + s[a][i]
//    }

//    rec(T1, T2, T1Sum, T2nextSum, i + 1)
// }

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cin;
using std::vector;
using std::cout;
using std::find;

vector<vector<int>> s; 
int min = 10e6;
int n;

void rec(vector<int> T1, vector<int> T2,
         int T1Sum, int T2Sum, int i
) {
   if(i >= n) {
      if(T1.size() == n/2) {
         min = std::min(std::abs(T1Sum - T2Sum), min);
      }
      return;
   }

   
   int T1nextSum = T1Sum;
   T1.push_back(i);
   for(auto a: T1) {
      T1nextSum += s[i][a] + s[a][i];
   }
   

   rec(T1, T2, T1nextSum, T2Sum, i + 1);

   T1.pop_back();
   
   int T2nextSum = T2Sum;

   T2.push_back(i);
   for(auto a: T2) {
      T2nextSum += s[i][a] + s[a][i];
   }
   
   rec(T1, T2, T1Sum, T2nextSum, i + 1);
}

void sol() {
   rec(vector<int>(), vector<int>(), 0, 0, 0);
}

int main(void) {
   cin >> n;

   s.resize(n);

   for(int i = 0; i < n; i++) {
      s[i].resize(n);
      for(int j = 0; j < n; j++) {
         cin >> s[i][j];
      }
   }

   sol();

   cout << min;


   return 0;
}

