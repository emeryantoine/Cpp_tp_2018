#include <iostream>
#include "vector.hpp"
#include "matrix.hpp"

int main()
{
  std::cout << "test de ml::vector" << std::endl;
  
  // EXEMPLES
  
  ml::vector v(3);
  v[0] = 1.0;
  v[1] = 2.0;
  v[2] = 3.0;

  std::cout << "v = " << v << std::endl;
  std::cout << "v.sum() = " << v.sum() << std::endl;
  std::cout << "v.squaredNorm() = " << v.squaredNorm() << std::endl;

  ml::vector u(3);
  u[0] = 10.0;
  u[1] = 20.0;
  u[2] = 30.0;
  std::cout << "u + v = " << (u+v) << std::endl;
  u += v;
  std::cout << "u = " << u << std::endl;
  
  std::cout << "test de ml::version::matrix" << std::endl;
  
  ml::matrix A(3, 3);
  A = 1.0;
  std::cout << "matrice A : "<<std::endl<<A<<std::endl;

  ml::matrix B(3, 3);
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      B(i, j) = i+j;
    }
  }

  ml::matrix C(3, 3);

  ml::vector X(3);
  X = 2;

  //C = A * X;

  std::cout<<"element centrale de la matrice B : "<<B(1, 1)<<std::endl;

  std::cout << "matrice B : "<<std::endl<<B<<std::endl;
  std::cout << "matrice C : "<<std::endl<<C<<std::endl;
  
  return 0;
}
