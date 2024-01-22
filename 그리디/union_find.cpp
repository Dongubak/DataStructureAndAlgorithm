#include <iostream>

int parent[10];

int find(int u) { ///find함수는 집합을 구분할 수 있는 루트값을 찾는 함수이다.
   ///루트노드의 부모는 자기 자신이므로 u가 반환된다.
   if(u == parent[u]) {
      return u;
   }

   return find(parent[u]);
}

void merge(int u, int v) {
   u = find(u); ///u의 부모를 찾아냄
   v = find(v); ///v의 부모를 찾아냄
   if(u == v) { ///서로의 부모가 같으면 합칠 수 없음
      parent[u] = v; ///서로의 부모가 다르면 합칠 수 있으며 이때 u의 부모를 v의 부모로 설정함
   }
}



int main(void) {
   using namespace std;

   /*
   disjoint set이란
   서로 중복되지 않는 부분 집합들로 나눠진 원소들에 대한 정보를 저장하고 조작하는 자료구조
   즉, 공통 원소가 없는, 즉 "상호 배타적"인 부분 집합들로 나눠진 원소들에 대한 자료구조이다.
   Disjoint set = 서로소 집합 자료구조

   union-find개념
   disjoint set을 표현할 때 사용하는 알고리즘
   
   make-set(x)
   초기화, x를 유일한 원소로 하는 새로운 집합을 만든다.

   union(x, y)
   합하기, x가 속한 집합과 y가 속한 집합을 합친다. 즉 x와 y가 속한 두 집합을 합치는 연산

   find(x)
   찾기
   x가 속한 집합의 대표값(루트 노드 값)을 반환한다. 즉 x가 어떤 집합에 속해있는지 찾는 연산


   */
   
   

   return 0;
}