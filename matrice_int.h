// clasa utila pentru operatiile pe matrici de tip intreg
#include <iostream>
#include "matrice.h"

using namespace std;

class matrice_int : protected matrice<int>{
	public:
		matrice<int> matrice_int::add(matrice<int> &A, matrice<int>&B);
		matrice<int> matrice_int::mul(matrice<int> &A, matrice<int>&B);
};

// aduna doua matrici
matrice<int> matrice_int::add(matrice<int> &A, matrice<int>&B){
	//matrice<int> C = A + B;
	return A + B;
}

//inmulteste doua matrici
matrice<int> matrice_int::mul(matrice<int> &A, matrice<int>&B){
	//matrice<int> C = A * B;
	return A * B;
}