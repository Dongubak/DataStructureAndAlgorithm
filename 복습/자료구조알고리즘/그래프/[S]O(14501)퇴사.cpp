#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int tm = -1;
int N;
void rec(vector<int>& t, vector<int>& p, int i, int s) {
   static int count = 0;
   count++;
   if(i >= N) {
      tm = max(s, tm);
      return;
   }

   rec(t, p, i + 1, s);
   if(i + t[i] <= N) {
      rec(t, p, i + t[i], s + p[i]);
   }
}


void sol(vector<int>& t, vector<int>& p) {
   rec(t, p, 0, 0);
}

int main(void) {
   cin >> N;

   vector<int> t(N);
   vector<int> p(N);

   for(int i = 0; i < N; i++) {
      cin >> t[i] >> p[i];
   }

   sol(t, p);

   cout << tm;

   return 0;
}