## 2단계 전수조사과정

### 전수 조사방식으로 부분집합의 합 문제 풀기

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets) {
   ///getAllSubset함수는 재귀적으로 부분집합을 찾아 나선다.
   if(index == set.size()) { ///모든 부분집합을 생성하였음
      allSubsets[subset.size()].push_back(subset);
      return;
   }
   ///세번째 매개변수로 입력받은 인덱스가 원래 집합의 크기와 같다면 모든 부분집합들을 확인 한 것으로
   ///부분집합을 모든 부분집합을 저장한 allSubsets에 저장한다.

   getAllSubsets(set, subset, index + 1, allSubsets);
   ///만약 모든 원소에 대해서 추가와 삭제경우를 따지지 않은 경우에 인덱스를 1늘려 진행한다.
   ///이것이 의미하는 것은 부분집합에 index에 해당하는 값을 추가하지 않은 경우 다음원소에 대해서 
   ///부분집합들을 구하기 위해 재귀호출한다.


   subset.push_back(set[index]);
   getAllSubsets(set, subset, index + 1, allSubsets);
   ///이 경우는 두번째 매개변수로 받은 인덱스값에 해당하는 원래집합의 원소값을 추가한 경우에 대해서 index + 1 원소를 추가하거나 추가하지 않은경우 부분집합을 구하기위해서 재귀호출한다.

}

bool subsetSumBruteForce(vector<int> set, int target) {
   vector<vector<vector<int>>> allSubset(set.size() + 1);
   // 원소의 개수가 size개인 부분집합들도 저장해야 하므로 set.size() + 1을 해준다
   ///allSubset은 부분집합들을 저장할 3차원 벡터이다.
   왜 3차원 벡터로 했는지는 잘 모르겠다.


   getAllSubsets(set, {}, 0, allSubset);
   ///getAllSubsets함수는 첫번째 매개변수로 원래 집합이 주어진다.
   ///두번째 매개변수로는 부분집합이 주어지는 데 초기 집합은 공집합이다.
   ///세번째 매개변수로는 인덱스를 입력받는데 이는 원래 집합의 첫 원소부터 마지막 원소까지
   ///포함된 경우와 포함되지 않은 경우에 대해서 부분집합들을 각각 생성하기 때문에 마지막 원소까지
   ///도달한 경우 탈출한다.

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

   bool found = subsetSumBruteForce(set, target); ///집합과 목표값을 함수에 전달해준다

   if(found) {
      cout << "원소 합이" << target << "인 부분집합이 있습니다." << '\n';
   } else {
      cout << "원소 합이" << target << "인 부분집합이 없습니다." << '\n';
   }


   return 0;
}
```

아직까지 allSubset이 3차원 벡터인 이유는 모르겠다.



## 백트래킹

### 최적화 적용하기
전수조사 방식은 성능 면에서 가장 비효율적인 방법이다.
가능한 모든 부분집합을 무차별적으로 확인하기 때문에 더 이상 해답이 나올수 없는 경우에 대해서도 모든 조사를 수행해야 한다. 백트래킹 기법을 사용하여 모든 부분 문제중에서 유효하지 않은 모든 경우를 제거한다.

### 백트래킹 구현을 위해 주어진 문제의 기저 조건과 상태의 재귀적 표현 결정
기저 조건이란 추가적인 재귀호출을 수행하지 않고 해를 구할 수 있는 경우를 의미한다. 가령 팩토리얼 계산을 한다고 하자
```cpp
factorial(int n) {
   if(n is 1)
      return 1
   
   return n * factorial(n - 1)
}
```

이 경우에 기저 조건은 n이 1인 경우이며 이때 추가적인 재귀호출을 하지 않고 해를 구할 수 있는 n = 1경우가 있다.

### 부분집합의 합 문제에서의 기저조건과 재귀적 표현 방법은?

기저 조건 정하기
```cpp
if(Sum of subset is target or
   Sum of subset is smaller than target
) {
   return true
} else {
   if(Sum of subset is bigger than target or
      index == size(set)
   ) {
      return false;
   }
}
```

