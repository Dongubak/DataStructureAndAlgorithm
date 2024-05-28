#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[4] = {13, 79, 45, 29};
int target = 58;

void rec(int i, vector<int> s, vector<vector<vector<int>>>& all) {
   int sum = 0;
   for(auto n: s) {
      sum += n;
   }

   if(i == 4) {
      if(sum == target) {
         cout << "있음";
      }
      
      return;
   }

   if(sum > target) {
      return;
   }
   
   rec(i + 1, s, all);
   s.push_back(arr[i]);
   rec(i + 1, s, all);
}

void sol() {
   vector<vector<vector<int>>> all(5);
   rec(0, {}, all);
}

int main(void) {
   sol();

   return 0;
}