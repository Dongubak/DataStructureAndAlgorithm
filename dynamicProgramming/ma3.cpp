#include <bits/stdc++.h>
using namespace std;

void recur1(vector<int>& set, vector<int> subset, int index, vector<vector<vector<int>>>& a, int target) {
   if(index == set.size()) {
      if(accumulate(subset.begin(), subset.end(), 0) == target) {
         for(auto a: subset) {
            cout << a << " ";
         }

         cout << '\n';
      }
      a[subset.size()].push_back(subset);
      return;
   }

   recur1(set, subset, index + 1, a, target);
   subset.push_back(set[index]);
   recur1(set, subset, index + 1, a, target);
}

void sol1(vector<int>& set, int target) {
   vector<vector<vector<int>>> a(set.size() + 1);

   recur1(set, {}, 0, a, target);


}

bool recur2(vector<int>& set, int sum, int i) {
   if(sum == 0) { ///sum of current subset is target;
      cout << "subset의 원소들 합과 target이 같음!!\n";
      for(auto a : set) {
         cout << a << " ";
      }

      cout << '\n';
      return true;
   }

   if(i == set.size() || set[i] > sum) {
      cout << "subset의 원소들 합이 target보다 크거나 index가 setsize임!!\n";
      return false;
   }


   
   return recur2(set, sum - set[i], i + 1) || recur2(set, sum, i + 1);
}

void sol2(vector<int> set, int target) {
   cout << "sol2실행" << '\n';
   sort(set.begin(), set.end());
   
   cout << "recur2 : ";
   for(auto a: set) {
      cout << a << " ";
   }

   cout << ", " << target << ", " << 0 << '\n' << "호출\n";
   recur2(set, target, 0);
}

int t[19][7000];

bool recur3(vector<int> set, int sum, int i) {
   if(sum == 0) {
      return true;
   }

   if(i == set.size() || set[i] > sum) {
      return false;
   }

   if(t[i][sum] == -1) {
      bool append = recur3(set, sum - set[i], i + 1);
      bool ignore = recur3(set, sum, i + 1);

      t[i][sum] = append || ignore;
   }

   return t[i][sum];
}

void sol3(vector<int> set, int target) {
   memset(t, -1, sizeof(t));
   cout << recur3(set, target, 0);
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   vector<int> set = {16, 1058, 22, 13, 46, 55, 3, 92, 47, 7, 98, 367, 807, 106, 333, 85, 577, 9, 3059};
   int target = 6076;

   sol1(set, target);
   cout << "------\n";
   sol2(set, target);
   cout << "------\n";
   sol3(set, target);

   return 0;
}

주어진 C++ 코드에서 2D 배열 t는 메모이제이션을 위해 사용됩니다. 이 배열의 행과 열은 순환을 통해 해결되는 부분집합 합 문제의 다른 상태를 나타냅니다. 행과 열의 의미를 자세히 살펴보겠습니다.

행 (t[i][...]): 행 인덱스 i는 정수 집합 (set)에서 현재 인덱스를 나타냅니다. recur3 함수의 맥락에서 i는 알고리즘이 현재 위치에서 원소를 포함하거나 제외하여 목표 합계를 달성하는 결정을 내리고 있는 정수 집합 내의 위치를 나타냅니다.
열 (t[..., sum]): 열 인덱스 sum은 달성해야 할 남은 합계를 나타냅니다. recur3 함수의 맥락에서 sum은 집합에서 원소를 선택하여 달성해야 하는 목표 합계입니다. 현재 부분집합의 원소들의 합입니다.
따라서 메모이제이션 배열의 각 셀 t[i][sum]은 현재 인덱스 i에서의 원소 선택 여부와 달성해야 하는 남은 합계 sum에 기반한 특정 하위 문제의 결과를 나타냅니다.

메모이제이션을 사용함으로써 알고리즘은 t 배열에 이전에 해결한 하위 문제의 결과를 저장하고 필요할 때 이러한 결과를 재사용하여 계산의 중복을 피하며 알고리즘의 전반적인 효율성을 향상시킵니다.