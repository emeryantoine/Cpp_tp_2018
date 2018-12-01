#include "vector.hpp"

//construction a partir d'une taille
ml::vector::vector(const std::size_t size){
	tableau = new double[size];
	THEsize = size;
	};
		
ml::vector::~vector(){
	delete [] tableau;
	};
	
// accesseur a la taille	
std::size_t ml::vector::size() const {
	return THEsize;
	};
		
//accesseurs aux coeficients
double& ml::vector::operator[](const std::size_t endroit){
	return tableau[endroit];
	};

const double& ml::vector::operator[](const std::size_t endroit) const{
	return tableau[endroit];
	};

//operateurs d'affectation
ml::vector& ml::vector::operator=(const ml::vector& vect){
	assert(this->THEsize == vect.THEsize);
	for (int i = 0; i < THEsize; i++)
	{
		tableau[i] = vect[i];
	}
	return *this;
		};
	
ml::vector& ml::vector::operator=(double val){
	for (int i = 0; i < THEsize; i++)
	{
		tableau[i] = val;
	}
	return *this;
	};

//operateur d'affectation compsé	
ml::vector& ml::vector::operator+=(const ml::vector& vect){
	assert(this->THEsize == vect.THEsize);
	for (int i = 0; i < THEsize; i++)
	{
		tableau[i] += vect[i];
	}
	return *this;
	};
ml::vector& ml::vector::operator-=(const ml::vector& vect){
	assert(this->THEsize == vect.THEsize);
	for (int i = 0; i < THEsize; i++)
	{
		tableau[i] -= vect[i];
	}
	return *this;
	};

//operateurs algebrique
ml::vector ml::vector::operator-(const ml::vector& vect){
	assert(this->THEsize == vect.THEsize);
	ml::vector temp(THEsize);
	for (int i = 0; i < THEsize; i++)
	{
		temp[i] = tableau[i] + vect[i];
	}
	
	return temp;
	};
ml::vector ml::vector::operator+(const ml::vector& vect){
	assert(this->THEsize == vect.THEsize);
	ml::vector temp(THEsize);
	for (int i = 0; i < THEsize; i++)
	{
		temp[i] = tableau[i] + vect[i];
	}
	
	return temp;
	};
	
ml::vector ml::vector::operator*(double val){
	ml::vector temp(THEsize);
	for (int i = 0; i < THEsize; i++)
	{
		temp[i] = tableau[i]*val;
	}
	return temp;
	};


//operateurs numeriques		
auto ml::vector::dot(const ml::vector& vect) const{
	assert(this->THEsize == vect.THEsize);
	auto res = 0.0;
	for (int i = 0; i < THEsize; i++)
	{
		res += tableau[i]*vect[i];
	}
	return res;
	};
	
double ml::vector::squaredNorm() const{
	double res = 0.0;
	for (int i = 0; i < THEsize; i++)
	{
		res += tableau[i]*tableau[i];
	}
	return sqrt(res);
	};
	
double ml::vector::sum() const{
	double res = 0.0;
	for (int i = 0; i < THEsize; i++)
	{
		res += tableau[i];
	}
	return res;
	};
	

std::ostream& ml::operator<<(std::ostream& nout, const ml::vector& vect){
	nout << "Voilou la taille du vecteur : "<<vect.size()<<std::endl;
	nout << "[ ";
	for (int i = 0; i < vect.THEsize; i++)
	{
		nout << vect[i]<<" ";
	}
	nout <<"]"<<std::endl;
	return nout;
};

ml::vector ml::operator*(double val, const ml::vector& vect){
	ml::vector temp(vect.THEsize);
	for (int i = 0; i < vect.THEsize; i++)
	{
		temp[i] = vect.tableau[i]*val;
	}
	return temp;
	};
