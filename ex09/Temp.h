template <typename T1, typename T2>
class Temp{
 public:
  T1 first;
  T2 second;
  inline Temp(const T1& a1, const T2& b1){
    first = a1;
    second = b1;
  }
};
