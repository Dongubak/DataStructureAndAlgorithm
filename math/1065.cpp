#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   string input;
   cin >> input;
   int size = input.length();
   int n = 0;

   for(int i = 0; i < size; i++) {
      n += input[i] - 48;
   }
   // -48
   
   int c = 0;
   for(int k = 0; k < n; k++) {
      for(int i = 0; i < size - 1; i++) {
         for(int j = i + 1; j < size; j++) {
            if(input[i] < input[j] < input[])
         }
      }
   }
   

   return 0;
}