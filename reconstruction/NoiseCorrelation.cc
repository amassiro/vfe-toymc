#include <iostream>
#include "Pulse.h"


void print_pulse(Pulse pSh) {
  std::cout.precision(5);
  std::cout << std::fixed;
  std::cout << "tau: " << pSh.tau() << std::endl;
  std::cout << "pSh.corr(0...9): " << std::endl;
  for (int k = 0; k < 10; k++) {
    std::cout << pSh.corr(k) << "   ";
  }
  std::cout << std::endl;
  std::cout << "pSh.cholesky(0,0...9,9) (main diagonal): " << std::endl;
  for (int l = 0; l < 10; l++) {
    std::cout << pSh.cholesky(l, l) << "   ";
  }
  std::cout << std::endl;
  std::cout << "pSh.cholesky(0,0...9,9): " << std::endl;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << pSh.cholesky(i, j) << "     ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
}


int main(int argc, char** argv) {
  Pulse pSh;
  pSh.Init();
  //std::vector<float> v = {0, 0.1, 1, 10, 100, 1000, 1000000};
  std::vector<float> v;
  for (int i = 1; i < argc; i ++) {
    v.push_back(atof(argv[i]));
  }
  for (float tau: v) {
    pSh.SetTAU(tau);
    pSh.NoiseInit();
    print_pulse(pSh);
  }
  return 0;
}
