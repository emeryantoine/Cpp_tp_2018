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


//Opérateur d’affichage :

//ICI CA VA PLUS, IL Y A COMME UN PROBLEME.

std::ostream& ml::operator<<(std::ostream& nout, const ml::matrix& mat)
{
  /*std::size_t tx = mat.size_x;
  std::size_t ty = mat.size_y;
  nout << "ton vecteur est : "<<tx<<" x "<<ty<<std::endl;*/
  nout << "[ ";
  for (int i = 0; i < mat.colonne; ++i)
  {
  	nout << std::endl;
  	for (int j = 0; j < mat.ligne; ++j)
  	{
  		nout << mat(i, j)<< " ";
  	}
  }
  nout<<"]"<<std::endl<<std::endl;
}

/*
//Accesseur à la transposée :
ml::matrix::matrix ml::matrix::transpose() const*/
