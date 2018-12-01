#include "matrix.hpp"
#include "vector.hpp"

//Construction à partir de tailles :
ml::matrix::matrix(const std::size_t lgn, const std::size_t col)
{
  matrice = new double*[lgn];
  for (int i = 0; i < lgn; i++)
  {
    matrice[i] = new double[col];
  }
  ligne = lgn;
  colonne = col;
};

ml::matrix::~matrix()
{
  for (int i = 0; i < ligne; i++)
  {
    delete [] matrice[i];
  }
  delete [] matrice;
};

//Accesseurs à la taille :
std::size_t ml::matrix::size_x() const
{
  return ligne;
};
std::size_t ml::matrix::size_y() const
{
  return colonne;
};

//Accesseurs aux coefficients :
double& ml::matrix::operator()(const std::size_t x, const std::size_t y)
{
  return matrice[x][y];
};

const double& ml::matrix::operator()(const std::size_t x, const std::size_t y) const
{
  return matrice[x][y];
};

//Opérateurs d’affectation :
ml::matrix& ml::matrix::operator=(double val)
{
  for (int i = 0; i < ligne; i++)
  {
    for (int j = 0; j < colonne; j++)
	{
      (*this)(i, j) = val;
	}
	
  }
  return *this;
};

//Opérateurs algébriques :
ml::vector ml::matrix::operator*(const ml::vector& v) const
{
  vector temp(colonne);
  temp = 0;
  for (int i = 0; i < ligne; i++)
  {
    for (int j = 0; j < colonne; j++)
	{
      temp[i] += (*this)(j, i)*v[j];		//ou peux etre l'inverse pour matrice (i, j) a la place de (j, i)
	}
	
  }
  return temp;
};

/*
//Opérateur d’affichage :
std::ostream& ml::matrix::operator<<(std::ostream&, const ml::matrix::xmatrix&)

//Accesseur à la transposée :
ml::matrix::matrix ml::matrix::transpose() const*/
