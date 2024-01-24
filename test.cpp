#include <iostream>
#include <queue>

int main(void) {
   using namespace std;

   // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

   // pq.push(make_pair(1, 2));
   // pq.push(make_pair(2, 2));
   // pq.push(make_pair(3, 2));
   // pq.push(make_pair(4, 2));
   // pq.push(make_pair(5, 2));
   // pq.push(make_pair(6, 2));

   // cout << pq.top().first;

   vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
   sort(v.begin(), v.end(), greater<int>());

   for(auto a : v) {
      cout << a << " ";
   }

   cout << '\n';

   priority_queue<int, vector<int>, greater<int>> pq;
   pq.push(9);
   pq.push(8);
   pq.push(7);
   pq.push(6);
   pq.push(5);
   pq.push(4);
   pq.push(3);
   pq.push(2);
   pq.push(1);

   cout << pq.top();


   return 0;
}