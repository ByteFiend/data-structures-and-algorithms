/*
#include <iostream>

using namespace std;

*/
class Solution {
public:
  /**
   * @param x: the base number
   * @param n: the power number
   * @return: the result
   */
  double myPow(double x, int n) {
    return helper(x, int64_t(n), 0.0001);
  }

  double helper(double x, int64_t n, double precision) {
    if (-precision < x - 0.0 && x - 0.0 < precision) {
      if (n > 0) { return 0.0; }
    }

    if (0 == n) { return 1.0; }
    if (n < 0) { return 1.0 / helper(x, -n, precision); }
    if (n & 1 == 1) { return x * helper(x * x, n >> 1, precision); }

    return helper(x * x, n >> 1, precision);
  }
};
/*

int main(){
  Solution s;
  cout << s.myPow(0.72348, 2) << endl;
  cout << s.myPow(8.84372, -5) << endl;
  cout << s.myPow(2, -2147483648) << endl;
}
*/
