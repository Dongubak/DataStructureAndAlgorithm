for(auto ptr = s2.begin(); ptr != s2.end(); ptr++) {      
      cout << *ptr << " " << ma[*ptr].size() << " ";
      for(auto ptr2 = ma[*ptr].begin(); ptr2 != ma[*ptr].end(); ptr2++) {
         cout << *ptr2 << " ";
      }
      cout << '\n';
   }