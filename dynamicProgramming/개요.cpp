#include <iostream>
#include <vector>

using namespace std;

const int UNKNOWN = -1;
const int MAX_SIZE = 100;

vector<long long> memo(MAX_SIZE, UNKNOWN);

long long fibo_memo(long long n) {
   if(n < 2) {
      return n;
   }

   if(memo[n] != UNKNOWN) { ///cache에 저장되어 있는 경우
      return memo[n];
   }

   long long res = fibo_memo(n - 1) + fibo_memo(n - 2);
   memo[n] = res;

   return res;
}

int fibo_tabul(int n) {
   vector<int> dp(n + 1, 0);
   dp[1] = 1;

   for(int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
   }
   ///이처럼 1차원으로 표현되는 경우는 거의 없으며 대부분 다차원으로 표현한다. 상태 전환방식을 여러개의 조건식 으로 표현해야 하기 도한다.
   ///창의력이 필요하며 상당한 이해가 필요하다.

   ///타뷸레이션은 메모리 사용량 관점에서 매우 효율적이다. 또한 가능한 모든 상태를 기록하는 룩업테이블을 기록할 수 있다.
   return dp[n];
}

int main(void) {
   /*
   메모이제이션과 타뷸레이션 기법이 있다.
   점진적으로 최적화 알고리즘을 사ㅇ하여 주어진 문제를 분석할 수 있음


   동적 계획법은 분할 정복 패러다임 개념을 확장한 것이다.
   
   동적 계획법을 사용하는 문제들의 예시
   1. 조합(특정 기준을 만족하는 시퀀스의 조합 또는 순열의 개수 구하기)
   2. 문자열과 시퀀스(편집거리, 최장 공통 부분 시퀀스, 최장 증가 부분 시퀀스)
   3. 그래프(최단 거리 문제)
   4. 머신러닝


   동적 계획법이란,

   f(0) = 0
   f(1) = 1 일때 피보나치 수열의 점화식은

   f(n) = f(n - 1) + f(n - 2)이다.

   이로서 피보나치 수열은 재귀적인 관계를 갖는다는 것을 확인할 수 있음
   이때 f(0)과 f(1)은 기저조건이라고 한다.

   하향식(top-down)해법:
   f(5) = f(4) + f(3)이며
   f(4) = f(3) + f(2) 이고 f(3) = f(2) + f(1)이며
   f(2) = f(1) + f(0) 이다.
   
   재귀트리 맨 꼭대기 부터 시작하여 기저 조건에 닿을 때까지 아래 가지로 이동하는 해법을 하향식(top-down)해법이라고 한다.
   여기서 확인할 수 있는 것은 최종 해답을 찾기위해 부분문제의 해답을 찾아야하며 부분문제에 대한 해답을 찾기 위해 부분문제의 부분문제의 해답을 찾아야한다.

   이는 중복되는 부분문제특성을 갖는다고 할 수 있다.

   또한 f(2)를 구하는 과정이 f(3)을 위한 과정이든 f(4)를 위한 과정이든 상관이 없으며 이를 최적부분구조특정을 갖는다고 할 수 있다.

   중복되는 부분문제들에 대해서 반복계산을 피하기 위해 캐시에 저장하는 것은 시간복잡도를 줄이는 데 사용할 수 있다.


   메모이제이션(하향식 접근법(top-down))
   f(n) = f(n - 1) + f(n - 2)를 구하는 과정에서 n값이 캐시에 저장되어 있는지 확인한다.
   저장되어 있다면 캐시에서 값을 꺼내 반환하면 된다.


   상향식 접근 방법(타뷸레이션(tabulation))

   메모이제이션과 반대 방식이다. 메모이제이션 보다 타뷸레이션을 더 많이 의식해서 사용한다고 한다.

   메모이제이션은 주어진 문제에서 시작하지만 타뷸레이션은 기저조건에 시작하는 특징이 있다.
   기저조건해답부터 시작하여 테이블에 저장한 후 재사용하는 방식이다.
   각각의 부분문제들을 재귀적으로 표현할 수 있어야하므로 메모이제이션 보다 어렵다고 느껴진다.

   
   */

  printf("%lld", fibo_memo(60));


   return 0;
}