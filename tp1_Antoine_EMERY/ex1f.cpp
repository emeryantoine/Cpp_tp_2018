#include <iostream>
#include <fstream>
#include <math.h>

// jeu de données (poids, taille) 
// pour un ensemble de 50 femmes 
double data[] = {
  149.633,46.3073,
  165.684,64.0963,
  160.957,59.4404,
  163.779,58.1386,
  156.954,58.8688,
  167.559,71.1254,
  159.64,52.15,
  166.756,74.8816,
  157.201,50.6563,
  161.742,47.2431,
  172.977,75.5587,
  156.969,48.1876,
  160.964,58.1144,
  149.596,46.1232,
  148.433,44.5402,
  154.457,57.5689,
  178.127,68.6089,
  158.134,52.5257,
  156.807,48.9284,
  160.171,66.0396,
  158.209,63.2875,
  157.042,55.6867,
  168.523,71.388,
  165.914,65.789,
  167.904,67.4255,
  163.899,60.184,
  143.632,38.498,
  159.358,62.8374,
  156.426,62.3361,
  157.542,56.5203,
  165.891,63.625,
  155.461,49.1204,
  170.244,68.1394,
  152.936,53.9954,
  162.408,63.2754,
  160.929,56.9782,
  161.76,60.0036,
  153.134,59.168,
  161.055,58.4456,
  154.004,49.7689,
  171.129,66.2362,
  169.857,72.0567,
  152.52,51.9842,
  162.952,60.3916,
  161.193,58.4922,
  170.799,69.8823,
  168.183,63.0509,
  164.32,62.9056,
  168.146,81.9648,
  167.268,67.6402
};

const auto m = 50;

auto hypothesis(double x, double theta[2])
{
	auto h_theta = theta[0] + theta[1]*x;
	
	return h_theta;
}

auto computeCost(double x[m], double y[m], double theta[2]) 
{
  auto J = 0.0;
  for (int i = 0; i < m; i++)
  {		J += pow((hypothesis(x[i], theta) - y[i]), 2)/(2*m);
  }
  return J;
}

void gradientDescent(double x[m], double y[m], double theta[2], double alpha, int iteration)
{	auto c = alpha/m;
	//std::ofstream file("costm.txt");
	
	for (double k = 0; k < iteration; k++)
	{	
		double U0 = 0, U1 = 0;
		
		for (int i = 0; i < m; i++)
	{
			auto h = hypothesis(x[i], theta) - y[i];
			U0 += c*h;
			U1 += c*h*x[i];
		
			//file <<k<<" "<<computeCost(x, y, theta)<<std::endl;
	}
	theta[0] -= U0;
	theta[1] -= U1;
	}
	std::cout<<theta[0]<<" "<<theta[1]<<std::endl;
}

int main()
{int m = 50;
  double x[m], y[m];
  
  for (int i = 0; i < m; i++)
  {x[i] = data[i*2];
   y[i] = data[i*2+1];
  }
  
  std::cout << "recopie de data dans les vecteurs x et y" << std::endl;

  std::cout << "recherche des paramètres theta optimaux" << std::endl;
  
  std::cout << "recopie de data dans les vecteurs x et y" << std::endl;

  std::cout << "recherche des paramètres theta optimaux" << std::endl<<std::endl;
  
  double theta[] = {1.0, 2.0};

  std::cout<<"hypothèse avec theta["<<theta[0]<<","<<theta[1]<<"] = "<<hypothesis(x[11], theta)<<std::endl;
  std::cout<<"computeCost : "<<computeCost(x, y, theta)<<std::endl<<std::endl;
  theta[0] = 2.0;
  theta[1] = 2.5;
  std::cout<<"hypothèse avec theta["<<theta[0]<<","<<theta[1]<<"] = "<<hypothesis(x[22], theta)<<std::endl;
  std::cout<<"computeCost : "<<computeCost(x, y, theta)<<std::endl<<std::endl;
  theta[0] = 0.5;
  theta[1] = 2.9;
  std::cout<<"hypothèse avec theta["<<theta[0]<<","<<theta[1]<<"] = "<<hypothesis(x[33], theta)<<std::endl;
  std::cout<<"computeCost : "<<computeCost(x, y, theta)<<std::endl<<std::endl;
  theta[0] = 4.9;
  theta[1] = 2.2;
  std::cout<<"hypothèse avec theta["<<theta[0]<<","<<theta[1]<<"] = "<<hypothesis(x[44], theta)<<std::endl;
  std::cout<<"computeCost : "<<computeCost(x, y, theta)<<std::endl<<std::endl;
  theta[0] = 0.0;
  theta[1] = 0.0;

  auto iterations = 20;
  auto alpha = 0.00001;
  
  gradientDescent(x, y, theta, alpha, iterations); 
    
  std::cout << "paramètre theta obtenu avec l'application de la fonction du gradient descendant:"<<std::endl<< "["<< theta[0] << ","<< theta[1] << "]" << std::endl<<std::endl;

  
  std::cout<<"Pour une femme d’une taille de 150cm, on predit un poids de : "<<std::endl<<hypothesis(150, theta)<<"kg"<<std::endl<<std::endl;
  std::cout<<"Pour une femme d’une taille de 175cm, on predit un poids de : "<<std::endl<<hypothesis(175, theta)<<"kg"<<std::endl<<std::endl;


  std::ofstream file("dataf.txt");
  for(auto i = 0; i < m; ++i) {
    file << x[i] << " " << y[i] << std::endl;
  }

  return 0;
}
