// clasa utila pentru operatiile pe matrici de tip float
#include <iostream>
#include "matrice.h"

using namespace std;

class matrice_float : protected matrice<float>{
	public:
		matrice<float> matrice_float::add(matrice<float> &A, matrice<float>&B);
		matrice<float> matrice_float::mul(matrice<float> &A, matrice<float>&B);
};

//adunarea a doua matrici
matrice<float> matrice_float::add(matrice<float> &A, matrice<float>&B){
	//matrice<float> C = A + B;
	return A + B;
}

//inmultire a doua matrici
matrice<float> matrice_float::mul(matrice<float> &A, matrice<float>&B){
	//matrice<float> C = A * B;
	return A * B;
}