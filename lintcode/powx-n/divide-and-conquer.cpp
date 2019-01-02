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

    if (n < 0) {
      x = 1.0 / x;
      n = -n;
    }

    double ans = 1.0;
    while (n > 0) {
      if (1 == (n & 1)){
        ans *= x;
      }

      x *= x;
      n >>= 1;
    }

    return ans;
  }
};
/*

int main(){
  Solution s;
  cout << s.myPow(8.88023, 3) << endl;
  cout << s.myPow(0.72348, 2) << endl;
  cout << s.myPow(8.84372, -5) << endl;
  cout << s.myPow(2, -2147483648) << endl;
}
*/
