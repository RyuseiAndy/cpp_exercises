#include <iostream>
#include <vector>

namespace PL4{
  template <class FwdIt>
  void sort(FwdIt begin, FwdIt end){
      for(auto i = begin; i != end - 1; i++){
          for(auto j = i + 1; j != end; j++){
              if(i < j) 
              std::swap(i, j);
            }
          }
    }
  void swap (int x, int y) {
  int temp;

  temp = x;
  x = y;
  y = temp;
  }

}

int main(){
  std::vector<int> v{4, 6, 5, 3, 9};

  sort(v.begin(),v.end());
  for(int i = 0; i < 5 ; i++){
    std::cout << v[i] << std::endl;
  }
  return 0;
}