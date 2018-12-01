#ifndef OUI
#define OUI

#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>

namespace ml
{
	class vector
	{
		public:
			double* tableau;
			std::size_t THEsize;
			
			vector(const std::size_t); //construction a partir d'une taille
			~vector();
			
			std::size_t size() const; // accesseur a la taille
			
			double& operator[](const std::size_t); //accesseurs aux coeficients
			const double& operator[](const std::size_t) const;
			
			vector& operator=(const vector&); //operateurs d'affectation
			vector& operator=(double);
			
			vector& operator+=(const vector&); //operateur d'affectation compsé
			vector& operator-=(const vector&);
			
			vector operator-(const vector&); //operateurs algebrique
			vector operator+(const vector&);
			vector operator*(double);
			
			auto dot(const vector&) const; //operateurs numeriques
			double squaredNorm() const;
			double sum() const;
			
		private:
	};
	
ml::vector operator*(double, const vector&);
std::ostream& operator<<(std::ostream&, const vector&); //operateur d'affichage

}



#endif
