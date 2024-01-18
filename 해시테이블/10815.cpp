// #include <cstdio>
// #include <vector>
// #include <map>

// int main(void) {
//    int n, tmp;
//    scanf("%d", &n);

//    std::map<int, bool> m;
//    for(int i = 0; i < n; i++) {
//       scanf("%d", &tmp);
//       m[tmp] = true;
//    }
//    int l;
   
//    scanf("%d", &l);
//    std::vector<int> t;
//    for(int i = 0; i < l; i++) {
//       scanf("%d", &tmp);
//       t.push_back(tmp);
//    }

//    for(std::vector<int>::iterator ptr = t.begin(); ptr != t.end(); ptr++) {
//       printf("%d ", m[*ptr]);
//    }
   

// }

#include <iostream>
#include <map>

int main(void) {
   int n, tmp;
   scanf("%d", &n);
   std::map<int, bool> m;
   for(int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      m[tmp] = true;
   }

   int k;
   scanf("%d", &k);
   for(int i = 0; i < k; i++) {
      scanf("%d", &tmp);
      printf("%d ", m[tmp]);
   }

}