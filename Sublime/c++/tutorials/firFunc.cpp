#include <iostream>

double pow(double base,int exponent){//declaring and definition
  double result=1;
  for(int i=1;i<=exponent;i++){
    result=result*base;
  }
  return result;
}

int main(){
  double base,exponent;
  std :: cout << "What is the base?: ";
  std :: cin >> base;
  std :: cout << "What is the exponent?: ";
  std :: cin >> exponent;
  double result = pow(base,exponent);
  std :: cout << result << std::endl;
  return 0; 
}
