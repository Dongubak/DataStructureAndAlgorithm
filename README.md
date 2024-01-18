# TEAM Algorithm
ktc동아리 알고리즘 팀 김혁중

## 🕰️ 발표날짜 : 1월 22일 월요일

## 🖥️ 분할정복 소개
분할 정복(Divide and Conquer)은 여러 알고리즘의 기본이 되는 해결방법으로, 기본적으로는 엄청나게 크고 방대한 문제를 조금씩 조금씩 나눠가면서 용이하게 풀 수 있는 문제 단위로 나눈 다음 그것들을 다시 합쳐서 해결하자는 개념에서 출발하였다

## ⏳ 여러 형태의 시간복잡도
- NP
- EXPTIME
- PSPACE

## 1️⃣ 특정 값을 검색하기
정렬된 목록에서 특정 값을 검색할 때
1.	시퀀스 전체 원소를 방문하면서 해당 원소가 N과 같은지를 확인하는 것
이는 입력시퀀스의 정렬여부와 상관없이 항상 잘 작동한다. 하지만 시간 복잡도가 O(n)며 주어진 배열이 정렬되어 있다는 것을 이용하지 않는다. 
2.	이진 검색을 사용한다. 이진 검색은 정렬된 시퀀스에 대해서 가운데 원소와 찾고자 하는 값을 비교한 뒤 그 원소가 존재할 수 있는 작은 부분으로 축소하여 앞에 작업을 반복한다.



---
### 🧑‍🏭 이진 검색의 예

**주어진 배열, 찾으려는 값 : 9**

| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |


1️⃣ **주어진 배열에서 중앙값을 찾는다.**

| 1 | 2 | 3 | 4 | <style>p{color:red;}</style><p><em>5</em></p> | 6 | 7 | 8 | 9 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |


2️⃣ **중앙값과 찾으려는 값을 비교하여 찾으려는 값이 크다면 범위를 좁혀서 1번을 반복한다.**

| 1 | 2 | 3 | 4 | <p><em>5</em></p> | 6 | 7 | 8 | 9 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |

3️⃣ **6에서 9사이의 수 중에서 중앙값을 찾아 9와 비교한다**

| 1 | 2 | 3 | 4 | 5 | <span style="color:blue">6</span> | <span style="color:red"><p>7</p><em></span> | <span style="color:blue">8</span> |<span style="color:blue">9</span> |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |

4️⃣ **찾으려는 값이 7보다 크므로 8과 9로 범위를 좁혀서 1번을 반복한다**

| 1 | 2 | 3 | 4 | 5 | 6 | 7 | <span style="color: blue"><p>8</p></span> | <span style="color: blue">9</span> |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |

5️⃣ **8보다 9가 크므로 범위를 좁혀 9부터 9까지의 중앙값과 9를 비교한다**

중앙값이 9이므로 값이 같아 검색을 성공한다.
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | <span style="color: blue"><p>9</p></span> |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |


## 👨‍💻 이진탐색 수도코드
```C++
BinarySearch(A[0..N-1], value, p, r) {
  if (p < r)
    return -1
  q = (p + r) / 2 // 중간 요소 설정(floor)
  if (A[q] > value)
    return BinarySearch(A, value, p, q - 1) //[low, mid)
  else if (A[q] < value)
    return BinarySearch(A, value, q + 1, r) // (mid, high)
  else
    return q
}
```

## 🎱 이진탐색 구현
```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <ctime>

bool linear_search(int n, std::vector<int>& s) {
    for(auto i : s) {
        if(i == n) {
            return true;
        }
    }
    
    return false;
}

bool binarySearchRecursive(int n, int st, int end, std::vector<int>& s) {
    if(st > end) {
        return false;
    } else {
        int mid = (st + end) / 2;
        if(n == s[mid]) {
            return true;
        } else if(n < s[mid])  {
            return binarySearchRecursive(n, st, mid - 1, s);
        } else {///}(n > s[i])
            return binarySearchRecursive(n, mid + 1, end, s);
        }
    }
}

bool binarySearch(int N, std::vector<int>& s) {
    return binarySearchRecursive(N, 0, int(s.size()) - 1, s);
}

int main(void) {
    srand(unsigned(time(0)));
    using namespace std;
    
    vector<int> a(100);
    generate(a.begin(), a.end(), []() {
        return rand() % 100;
    });
    sort(a.begin(), a.end());
    
    for(auto i : a) {
        cout << i << " ";
    }
    cout << '\n';
    cout << binarySearch(10, a);
    
    
    
    
    return 0;
}

```
### 출력결과
![Alt text](image.png)

