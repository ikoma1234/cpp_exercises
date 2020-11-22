#include <iostream>
#include <functional>
using namespace std;
using ReturnType = double (*)(double);

double deriv_fd(std::function<double(double)> f, double x) {
  double epsilon = 0.00000095367431640625;
  return (f(x+epsilon) - f(x-epsilon))/(2.0*epsilon);
}

ReturnType deriv(ReturnType f){
    ReturnType res = bind(deriv_fd, placeholders::_2, 1.0);
    return res;
}

int main(void) {
  auto df = deriv([](double x) { return x; });
  cout << df(1.0) << endl; // should be 1
  cout << df(2.0) << endl; // should be 1
  return 0;
}