#ifndef ah
#define ah

#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include "vector.hpp"

namespace ml
{
  class matrix
  {
    public:
      matrix(const std::size_t, const std::size_t);
      ~matrix();
      double** matrice;
      std::size_t colonne;
      std::size_t ligne;

      std::size_t size_x() const;
      std::size_t size_y() const;

      double& operator()(const std::size_t, const std::size_t);
      const double& operator()(const std::size_t, const std::size_t) const;

      matrix& operator=(double);

      vector operator*(const vector& v) const;
		
    private:
  };

  std::ostream& operator<<(std::ostream&, const matrix&);
  //matrix transpose() const;

}

#endif
