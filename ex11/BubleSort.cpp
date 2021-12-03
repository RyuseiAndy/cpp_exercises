#include <iostream>
#include <vector>

namespace PL4{
    template <class FwdIt>
    void sort(FwdIt begin, FwdIt end) {
        for(auto i=begin; i!=end; ++i){
            for(auto j=begin; j<i; ++j){
                if(*i < *j){
                    iter_swap(i, j);
                }
            }
        }
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