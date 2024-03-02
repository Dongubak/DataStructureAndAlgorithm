#include <bits/stdc++.h>
using namespace std;

int ucgcd(int a, int b) {
   while(a && b) {
      if(a > b) {
         a = a % b;
      } else {
         b = b % a;
      }
   }

   return a ? a : b;
}

int ucgcd_rec(int a, int b) {
   if(a == 0) {
      return b;
   }

   if(b == 0) {
      return a;
   }

   if(a > b) {
      return ucgcd_rec(a % b, b);
   } else {
      return ucgcd_rec(a, b % a);
   }
}

void swap(int& a, int& b) {
   int tmp = a;
   a = b;
   b = tmp;
}

void merge(vector<int>& a, int p, int q, int r) {
   int t = 0;
   vector<int> tmp(r - p + 1);
   int i = p;
   int j = q + 1;

   while(i <= q && j <= r) {
      if(a[i] <= a[j]) {
         tmp[t++] = a[i++];
      } else {
         tmp[t++] = a[j++];
      }
   }
   
   while(i <= q) {
      tmp[t++] = a[i++];
   }

   while(j <= r) {
      tmp[t++] = a[j++];
   }
   t = 0;
   for(int k = p; k <= r; k++) {
      a[k] = tmp[t++];
   }
}

void mergeSort(vector<int>& a, int p, int r) {
   if(p < r) {
      int q = (p + r) / 2;
      mergeSort(a, p, q);
      mergeSort(a, q + 1, r);
      merge(a, p, q, r);
   }
}

int main(void) {
   int a = 777, b = 123;

   cout << ucgcd(a, b) << '\n';
   cout << ucgcd_rec(a, b) << '\n';

   vector<int> v = {13, 34, 50, 75, 11, 20, 28, 62};
   mergeSort(v, 0, v.size() - 1);

   for(int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
   }

   return 0;
}