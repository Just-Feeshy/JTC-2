#include <iostream>

using namespace std;

#include <stdio.h>

namespace boyfriend {
  struct test {
      bool get_bool_from_value(int value) {
          if(value % 2 == 0)
              return false;
          else
              return true;
      }
  };
}

using namespace shaders;

int main() {
  struct test Loli;

  if(Loli.get_bool_from_value(1) == true)      
    cout << "OH NO!" << endl;
  else
    cout << "oh ok" << endl;
}