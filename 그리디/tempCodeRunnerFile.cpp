for(auto ptr = v.begin(); ptr != v.end() - 1; ptr++) {
      if(!(ptr->end < (ptr + 1)->st)) {
         v.erase(ptr + 1);
      }
   }