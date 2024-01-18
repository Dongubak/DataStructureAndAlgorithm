#include <iostream>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <algorithm>


int main(void) {
   using namespace std;
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;
   cin.get();

   map<string, set<string> > ma;
   set<string> s1, s2;

   string tmp;
   for(int i = 0; i < n; i++) {
      cin >> tmp;
      s1.insert(tmp);
      s2.insert(tmp);
   }

   int m;
   cin >> m;
   cin.get();
   string tmp2;
   for(int i = 0; i < m; i++) {
      cin >> tmp >> tmp2;
      cin.get(); 
      ma[tmp2].insert(tmp);


      auto ptr1 = s1.find(tmp);
      if(ptr1 != s1.end()) {
         s1.erase(ptr1);
      }
   }

   // for(auto ptr = ma.begin(); ptr != ma.end(); ptr++) {
   //    cout << "key : " << ptr->first << ", value : " << ptr->second << '\n';
   // }
   // cout << "--------" << '\n';
   // for(auto ptr = s.begin(); ptr != s.end(); ptr++) {
   //    cout << *ptr << " ";
   // }
   // cout << '\n';

   cout << s1.size() << '\n';
   for(auto ptr = s1.begin(); ptr != s1.end(); ptr++) {
      cout << *ptr << " ";
   }
   cout << '\n';
   ///tmp2는 부모 tmp는 자식
      ///key는 부모, value는 자식
      /*
         맵에 부모꺼에 여러 자손이 있다고 저장됨
         입력 받을 때 마다 자손이 직계자손인지 확인할 필요가 있음
         직계자손인지 확인하는 방법으로 현재 입력받은 자손이
         부모가 존재한다면 직계자손이 아닐거임

         만약 직계자손에 대한 정보가 간접적으로 주어진 경우
         tmp2의 자손들 중에 2개를 커트해야하는 경우
      */
   for(auto ptr = s2.begin(); ptr != s2.end(); ptr++) {      
      cout << *ptr << " " << ma[*ptr].size() << " ";
      for(auto ptr2 = ma[*ptr].begin(); ptr2 != ma[*ptr].end(); ptr2++) {
         cout << *ptr2 << " ";
      }
      cout << '\n';
   }

   // for(auto ptr1 = ma.begin(); ptr1 != ma.end(); ptr1++) {
   //    cout << "key : " << ptr1->first <<  ", value : ";
   //    for(auto ptr2 = ptr1->second.begin(); ptr2 != ptr1->second.end(); ptr2++) {
   //       cout << *ptr2 << " ";
   //    }

   //    cout << '\n';
   // }

   for(auto ptr = s2.begin(); ptr != s2.end(); ptr++) {      
      // cout << *ptr << " " << ma[*ptr].size() << " ";
      for(auto ptr2 = ma[*ptr].begin(); ptr2 != ma[*ptr].end(); ptr2++) {
         
      }
      cout << '\n';
   }

   
}