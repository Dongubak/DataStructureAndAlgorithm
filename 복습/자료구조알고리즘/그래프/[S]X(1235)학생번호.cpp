#include <iostream>
#include <vector>

// 6월 20일 slice 사용해야 할 듯
// 현재 문제점
// 각 자리수만 다르면 될거라고 판단 했지만
// 이전에 조사했던 자리의 수들을 포함하여 다음 자릿수를 검사해야함
// 이 과정에서 만약 j번째 열을 조사한다고 가정하면
// m - 1 to j까지의 수를 i번 조사해야하는 데 이거 좀 빡셀 듯

// nlogn으로 처리하는 방법을 고민해보자

using std::cin;
using std::cout;
using std::vector;
using std::string;

int n, m;

vector<string> in;

void sol() {
   vector<string> A;
   cout << in[0][0] << '\n';
   // for(int j = m - 1; j >= 0; j--) {
   //    vector<int> B(10, 0);
   //    int allP = true;
      
   //    for(int i = 0; i < n; i++) {
   //       A[i].push_back(in[i][j]);

   //       if(B[in[i][j] - '0']) {
   //          allP = false;
   //       }

   //       B[in[i][j] - '0'] = 1;
   //       cout << in[i][j] << '\n';
   //    }

   //    if(allP) {
   //       cout << j + 1;
   //       return;
   //    }
   // }
}

int main(void) {
   cin >> n;

   in.resize(n);

   for(int i = 0; i < n; i++) {
      cin >> in[i];
   }

   ::m = in[0].size();

   sol();

   return 0;
}