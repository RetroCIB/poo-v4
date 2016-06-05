#pragma once
// clasa de baza matrice

#include <iostream>
using namespace std;

template <class T>
class matrice{
	private:
		int nr_linii;
		int nr_coloane;
		T *elemente;
	public:
		matrice();
		matrice(int, int);
		matrice(const matrice<T> &mX);
		~matrice();

		T& operator()(int,int);
		matrice<T> operator+(const matrice<T> mX);
		matrice<T> operator*(const matrice<T> mX);

		matrice<T> operator=(matrice<T> mX);
		matrice<T> operator++();
		matrice<T> operator++(int);
		matrice<T> operator--();
		matrice<T> operator--(int);

		template <class T>
		friend istream& operator>>(istream &input, const matrice<T> &mX);
		template <class T>
		friend ostream& operator<<(ostream& output, const matrice<T> &mX);
		
		int get_linii(){ return nr_linii; };
		int get_coloane(){ return nr_coloane; };
		void set_linii(int nr_linii){ this->nr_linii = nr_linii; };
		void set_coloane(int nr_coloane){ this->nr_coloane = nr_coloane; };

};

//*****************************************************************************

//constructor
template <class T> 
matrice<T>::matrice(){
	nr_linii = 1;
	nr_coloane = 1;
	elemente = new T[nr_linii * nr_coloane];
	if(!elemente) exit(1001);
}
//constructor cu parametri
template <class T> 
matrice<T>::matrice(int numar_coloane, int numar_linii){
	nr_linii = numar_linii;
	nr_coloane = numar_coloane;
	elemente = new T[numar_linii * numar_coloane];
	if(!elemente) exit(1002);
}
//constructor de copiere
template <class T> 
matrice<T>::matrice(const matrice<T> &mX){
	nr_coloane = mX.nr_coloane;
	nr_linii = mX.nr_linii;
	elemente = new T[nr_linii * nr_coloane];
	if(!elemente) exit(1003);

	int i;
	for(i = 0; i < (nr_linii * nr_coloane); i++){
		elemente[i] = mX.elemente[i];
	};
}
//destructor
template <class T> 
matrice<T>::~matrice(){
	delete[] elemente;
}

//*****************************************************************************

//operatorul () - pentru referinta la elementele din matrice
template <class T> 
T& matrice<T>::operator()(int numar_coloana, int numar_linie){
	return elemente[numar_linie * nr_coloane + numar_coloana];
}

//operatorul de adunare +
template <class T> 
matrice<T> matrice<T>::operator+(const matrice<T> mX){
	matrice<T> mTemp;
	T scalar;

	if((nr_linii==1 && nr_coloane==1) || (mX.nr_linii==1 && mX.nr_coloane==1)){
	//matrice si scalar
		if(nr_linii==1 && nr_coloane==1){
			scalar = elemente[0];
			mTemp.nr_linii = mX.nr_linii;
			mTemp.nr_coloane = mX.nr_coloane;

			mTemp.elemente = new T[mX.nr_linii * mX.nr_coloane];
			if(!mTemp.elemente) exit(2101);

			int i,j;
			for(i=0; i< mX.nr_linii; i++){
				for(j=0; j< mX.nr_coloane; j++){
					mTemp.elemente[(i * mX.nr_coloane) + j] = 
						scalar + mX.elemente[(i * mX.nr_coloane) + j];
				}
			}

		}else if(mX.nr_linii==1 && mX.nr_coloane==1){	
			scalar = mX.elemente[0];
			mTemp.nr_linii = nr_linii;
			mTemp.nr_coloane = nr_coloane;

			mTemp.elemente = new T[nr_linii * nr_coloane];
			if(!mTemp.elemente) exit(2201);

			int i,j;
			for(i=0; i< nr_linii; i++){
				for(j=0; j< nr_coloane; j++){
					mTemp.elemente[(i * nr_coloane) + j] = 
						elemente[(i * nr_coloane) + j] + scalar;
				}
			}
		}

	}else{
	//doua matrici
		if(nr_linii != mX.nr_linii) exit(2001);
		if(nr_coloane != mX.nr_coloane) exit(2002);

		mTemp.nr_linii = nr_linii;
		mTemp.nr_coloane = nr_coloane;

		mTemp.elemente = new T[nr_linii * nr_coloane];
		if(!mTemp.elemente) exit(2003);

		int i,j;
		for(i=0; i< nr_linii; i++){
			for(j=0; j< nr_coloane; j++){
				mTemp.elemente[(i * nr_coloane) + j] = 
					elemente[(i * nr_coloane) + j] + mX.elemente[(i * nr_coloane) + j];
			}
		}
	}
	return mTemp;
}

//operatorul de inmultire *
template <class T> 
matrice<T> matrice<T>::operator*(const matrice<T> mX){
	matrice<T> mTemp;
	T scalar;

	if((nr_linii==1 && nr_coloane==1) || (mX.nr_linii==1 && mX.nr_coloane==1)){
	//matrice si scalar
		if(nr_linii==1 && nr_coloane==1){
			scalar = elemente[0];
			mTemp.nr_linii = mX.nr_linii;
			mTemp.nr_coloane = mX.nr_coloane;

			mTemp.elemente = new T[mTemp.nr_linii * mTemp.nr_coloane];
			if(!mTemp.elemente) exit(3101);

			int i,j;
			for(i=0; i< mX.nr_linii; i++){
				for(j=0; j< mX.nr_coloane; j++){
					mTemp.elemente[(i * mX.nr_coloane) + j] = 
						scalar * mX.elemente[(i * mX.nr_coloane) + j];
				}
			}

		}else if(mX.nr_linii==1 && mX.nr_coloane==1){	
			scalar = mX.elemente[0];
			mTemp.nr_linii = nr_linii;
			mTemp.nr_coloane = nr_coloane;

			mTemp.elemente = new T[nr_linii * nr_coloane];
			if(!mTemp.elemente) exit(3201);

			int i,j;
			for(i=0; i< nr_linii; i++){
				for(j=0; j< nr_coloane; j++){
					mTemp.elemente[(i * nr_coloane) + j] = 
						elemente[(i * nr_coloane) + j] * scalar;
				}
			}
		}

	}else{
	//doua matrici
		if(nr_coloane != mX.nr_linii) exit(3001);
	if(nr_linii != mX.nr_coloane) exit(3002);

		mTemp.nr_linii = nr_linii;
		mTemp.nr_coloane = nr_coloane;

		mTemp.elemente = new T[mTemp.nr_linii * mTemp.nr_coloane];
		if(!mTemp.elemente) exit(2003);

		int i, j, k;

		for(i=0; i< mTemp.nr_linii * mTemp.nr_coloane; i++){
			mTemp.elemente[i]=0;
		}

		for(i = 0; i < nr_linii; i++){
			for(j = 0; j < mX.nr_coloane; j++){
				for(k = 0; k < mX.nr_linii; k++){

					mTemp.elemente[(i * mTemp.nr_coloane) + j] +=
						elemente[(i * nr_coloane) + k] 
						* 
						mX.elemente[(k * mX.nr_coloane) + j];
				}		

			}
		}
	}
	
	return mTemp;
}


//operatorul de atribuire =
template <class T> 
matrice<T> matrice<T>::operator=(const matrice<T> mX){
	nr_linii = mX.nr_linii;
	nr_coloane = mX.nr_coloane;
	for(int i = 0 ; i < nr_linii * nr_coloane ; i++)
	{
		elemente[i] = mX.elemente[i];
	}
	return *this;
}

//operatorul de incrementare ++  prefix 
template <class T> 
matrice<T> matrice<T>::operator++(){
	int i;
	for(i=0; i< nr_linii*nr_coloane; i++){
		++elemente[i];
	}
	return *this;
}

//operatorul de incrementare ++  post 
template <class T> 
matrice<T> matrice<T>::operator++(int){
	matrice<T> M = *this;
	operator++();
	return M;
}

//operatorul de decrementare -- prefix 
template <class T> 
matrice<T> matrice<T>::operator--(){
	int i;
	for(i=0; i< nr_linii+nr_coloane; i++){
		elemente[i]--;
	}
	return *this;
}

//operatorul de decrementare -- post 
template <class T> 
matrice<T> matrice<T>::operator--(int){
	matrice<T> M = *this;
	operator--();
	return M;
}

//*****************************************************************************

//operatorul de citire >> (util cin)
template <class T>
istream& operator >> (istream &input, const matrice<T> &mX){
	int i,j;
	for(i = 0; i < mX.nr_linii ; i++){
		cout << "\n\t\t randul " << i+1 << "\n";
		for(j = 0; j < mX.nr_coloane; j++){
			cout << "\t\t\t coloana " << j+1 << " : ";
			input >> mX.elemente[(i * mX.nr_coloane) + j]; 
		}
	}
	return input;
};
//operatorul de afisare << (util cout)
template <class T>
ostream& operator << (ostream& output, const matrice<T> &mX){
	int i,j;
	for(i = 0; i < mX.nr_linii ; i++){
		output << "\n\t\t randul " << i+1 << "\n";
		for(j = 0; j < mX.nr_coloane; j++){
			output << "\t\t\t coloana " << j+1 << " : " << mX.elemente[(i * mX.nr_coloane) + j] << 

"\n"; 
		}
	}
	return output;
};