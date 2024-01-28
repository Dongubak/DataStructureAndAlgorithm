#include <cstdio>
#include <vector>
#include <algorithm>

int main(void) {
   using namespace std;

   int n, k;
   int tmp;
   std::vector<int> v;
   scanf("%d %d", &n, &k);

   for(int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      v.push_back(tmp);
   }

   sort(v.begin(), v.end());
   printf("%d", v[k - 1]);


   return 0;
}