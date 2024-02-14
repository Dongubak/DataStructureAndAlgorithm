#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets) {
   if(index == set.size()) { ///모든 부분집합을 생성하였음
      allSubsets[subset.size()].push_back(subset);
      return;
   }

   getAllSubsets(set, subset, index + 1, allSubsets);
   ///원소를 추가한 후 재귀호출

   subset.push_back(set[index]);
   getAllSubsets(set, subset, index + 1, allSubsets);
   ///원소를 추가하지 않고 재귀호출

}

bool subsetSumBruteForce(vector<int> set, int target) {
   vector<vector<vector<int>>> allSubset(set.size() + 1);

   getAllSubsets(set, {}, 0, allSubset);

   for(int size = 0; size <= set.size(); size++) {
      cout << "부분집합의 원소 개수 : " << size << '\n';

      for(auto subset: allSubset[size]) {
         cout << "\t{ ";

         int sum = 0;
         for(auto number : subset) {
            sum += number;
            cout << number << " ";
         }

         cout << "} = " << sum << '\n';

         if(sum == target) {
            return true;
         }
      }
   }

   return false;
}

int main(void) {

   vector<int> set = {13, 79, 45, 29, 60, 12, 15};
   int target = 58;

   bool found = subsetSumBruteForce(set, target);

   if(found) {
      cout << "원소 합이" << target << "인 부분집합이 있습니다." << '\n';
   } else {
      cout << "원소 합이" << target << "인 부분집합이 없습니다." << '\n';
   }


   /*
      가령 한정된 수량의 지폐, 동전들로 거스름돈을 만드는 경우 직관적으로 풀이가 가능하겠지만

      많은 양수의 지폐, 동전들로 거시름돈을 만드는 경우 직관적 풀이가 불가능하며, 모든 조합을 시도해봐야한다.
      하지만 모든 조합을 시도하면서 금액을 맞추는 것은 너무 복잡하다. 이를 부분집합의 합 문제라고 한다.

      "음수가 아닌 정수로 이루어진 집합 S와 임의의 정수 x가 주어질 때 S의 부분집합 중에서 그 원소의 합이 x와 같은 부분집합이 존재하는가?"

      동적계획법 필요조건 분석하기
      1. 중복되는 부분 문제
      2. 최적 부분 구조

      크기가 n인 부분집합은 크기가 n - 1인 부분집합에 새로운 원소 하나를 추가하여 만들 수 있다.
      부분집합의 합 문제를 최적 부분 구조를 갖는다고 할 수 있다.

      또한 중복되는 부분문제 속성도 갖는다고 할 수 있다.

      3. 기저 조건과 상태 정의하기
      각 부분문제를 다른 부분문제와 다르다고 판단 할 수 있는 기준을 찾아야 한다.
      주어진 문제의 최적해가 어떻게 구성되는지에 대한 명확한 이해없이 상태를 정의하는 것은 쉽지 않다.


      동적 계획법의 4가지 접근 방법이 있다.
         1. 전수조사
         2. 백트래킹
         3. 메모이제이션
         4. 타뷸레이션
   */




   return 0;
}