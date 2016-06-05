//*****************************************************************************
// Proiect POO -  ( variatie nr.3 - respectare conditii generale )
// Adunarea si inmultirea a doi/doua scalari/matrici
//
// -constructor fara argumente
// -constructor de copiere
// -cel puţin inca un constructor
// -destructor 
// -metode de citire a datelor de la consola
//
// -supraîncărcarea mai multor funcţii şi operatori
// -dintre care operatorul de atribuire şi cel puţin încă 2 operatori;
// -se utilizează clase generice sau clase abstracte şi moştenire.
//*****************************************************************************

#include <iostream>
#include "matrice.h"
#include "matrice_int.h"
#include "matrice_float.h"

using namespace std;

//*****************************************************************************
//definire variabile
matrice_int		calculator_intregi;
matrice_float	calculator_reale;

int nr_linii_A, nr_coloane_A; 
int nr_linii_B, nr_coloane_B;

char tip_date;
//definire matrici maxim de 10x10 int si float
matrice<int>	mAi(10,10);
matrice<float>	mAf(10,10);

matrice<int>	mBi(10,10);
matrice<float>	mBf(10,10);


//*****************************************************************************
// declarare functii
int arata_meniu_principal();
void asteapta_apasare_tasta();

void citeste_tip_date();

void citeste_scalar_A();
void citeste_scalar_B();
void citeste_matrice_A();
void citeste_matrice_B();

void operatii_intre_doi_scalari();
void operatii_intre_scalar_matrice();
void operatii_intre_doua_matrici();

//*****************************************************************************
// program principal
int main(){
	do{
		switch(arata_meniu_principal()){
			case '1':{
				//operatii intre doi scalari
					operatii_intre_doi_scalari();
					break;
				 }
			case '2':{
				//operatii intre un scalar si o matrice
					operatii_intre_scalar_matrice();
					break;
				 }
			case '3':{
				//operatii intre doua matrici
					operatii_intre_doua_matrici();
					break;
				 }
			case '9':{
					return 0;
					break;
				 }
		}
	}while(true);
	return 0;
}


//*****************************************************************************
// functiile utile pentru operatii
void operatii_intre_doi_scalari(){
	system("cls");
	//afisare antent
	cout	<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+"
			<< "\n +  ADUNAREA SI INMULTIREA A DOI SCALARI                                   +"
			<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+";

	//citeste tip date
	citeste_tip_date();
	
	//citim scalarul A
	citeste_scalar_A();
	
	//citim scalarul B
	citeste_scalar_B();

	//adunam cei doi scalari
	cout << "\n\n [ Scalari - Adunare ] \n";
	cout << "\n Scalarul rezultat din adunarea celor doi scalari este : ";
	if(tip_date=='i' || tip_date=='I'){ 
		cout << mAi(0,0) + mBi(0,0); 
	}else{
		cout << mAf(0,0) + mBf(0,0); 
	}
	cout << "\n .............................................................................";
	
	//inmultim cei doi scalari
	cout << "\n\n [ Scalari - Inmultire ] \n";
	cout << "\n Scalarul rezultat din inmultirea celor doi scalari este : ";
	if(tip_date=='i' || tip_date=='I'){ 
		cout << mAi(0,0) * mBi(0,0); 
	}else{
		cout << mAf(0,0) * mBf(0,0); 
	}
	cout << "\n .............................................................................";

	asteapta_apasare_tasta();
}
void operatii_intre_scalar_matrice(){
	system("cls");
	//afisare antent
	cout	<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+"
			<< "\n +  ADUNAREA SI INMULTIREA INTRE UN SCALAR SI O MATRICE                    +"
			<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+";

	//citeste tip date
	citeste_tip_date();
	
	//citim scalarul A
	citeste_scalar_A();

	//citim matricea B
	citeste_matrice_B();

	//adunam scalar cu matrice
	cout << "\n [ Matricea - Adunare ]\n";
	cout << "\n Matricea rezultata din adunarea scalarului cu matricea este: \n";
	if(tip_date=='i' || tip_date=='I'){ 
		cout << calculator_intregi.add(mAi, mBi); 
	}else{
		cout << calculator_reale.add(mAf, mBf); 
	}
	cout << "\n .............................................................................";
	
	//inmulteste scalar cu matrice
	cout << "\n [ Matricea - Inmultire ]\n";
	cout << "\n Matricea rezultata din inmultirea scalarului cu matricea este: \n";
	if(tip_date=='i' || tip_date=='I'){ 
		cout << calculator_intregi.mul(mAi, mBi); 
	}else{
		cout << calculator_reale.mul(mAf, mBf); 
	}
	cout << "\n .............................................................................";

	asteapta_apasare_tasta();
};
void operatii_intre_doua_matrici(){
	system("cls");
//arata antet
	cout	<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+"
			<< "\n +  ADUNAREA SI INMULTIREA INTRE DOUA MATRICI                              +"
			<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+";
	//citim tip date
	citeste_tip_date();
	
	//citim matricea A
	citeste_matrice_A();

	//citim matricea B
	citeste_matrice_B();

	//aduna cele doua matrici (daca se pot aduna)
	cout << "\n[ Matricea - Adunare ]\n\n";
	if((nr_linii_A == nr_linii_B) && (nr_coloane_A == nr_coloane_B)){	
		cout << " Matricea rezultata din adunarea celor doua matrici este: \n";
		if(tip_date=='i' || tip_date=='I'){ 
			cout << calculator_intregi.add(mAi, mBi); 
		}else{
			cout << calculator_reale.add(mAf, mBf); 
		}
	}else{
		cout << "\t ATENTIE: Cele doua matrici au numarul de linii si/sau numarul coloane diferite, deci nu se pot aduna!";
	}
	
	//inmulteste cele doua matrici (daca se pot inmulti)
	cout << "\n[ Matricea - Inmultire ]\n\n";
	if((nr_linii_A == nr_coloane_B) && (nr_coloane_A == nr_coloane_A)){		
		cout << " Matricea rezultata din inmultirea celor doua matrici introduse este : \n";
		if(tip_date=='i' || tip_date=='I'){ 
			cout << calculator_intregi.mul(mAi, mBi); 
		}else{
			cout << calculator_reale.mul(mAf, mBf); 
		}
	}else{
		cout << "\t ATENTIE: Cele doua matrici au numarul de linii diferit de numarul de coloane si/sau numarul de coloane diferit de numarul de linii, deci nu se pot inmulti!";
	}
	
	// matrice A++
	cout << "\n[ Matricea - A++ ]\n\n";
	cout << " Matricea rezultata A++ : \n";
	if(tip_date=='i' || tip_date=='I'){ 
		cout << mAi++; 
	}else{
		cout << mAf++;
	}

	// matrice ++A
	cout << "\n[ Matricea - ++A ]\n\n";
	cout << " Matricea rezultata ++A : \n";
	if(tip_date=='i' || tip_date=='I'){ 
		cout << ++mAi; 
	}else{
		cout << ++mAf;
	}

	// matrice B--
	cout << "\n[ Matricea - B-- ]\n\n";
	cout << " Matricea rezultata --B : \n";
	if(tip_date=='i' || tip_date=='I'){ 
		cout << mBi--; 
	}else{
		cout << mBf--;
	}

	// matrice --B
	cout << "\n[ Matricea - --B ]\n\n";
	cout << " Matricea rezultata --B : \n";
	if(tip_date=='i' || tip_date=='I'){ 
		cout << --mBi; 
	}else{
		cout << --mBf;
	}


	//exit
	cout << "\n\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ \n\n";
	system("pause");
};

//*****************************************************************************
int arata_meniu_principal(){
	char key;
	system("cls");
	//afisare antet
	cout	<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+"
			<< "\n +  PROIECT POO - ADUNAREA SI INMULTIREA INTRE MARICI SI/SAU SCALARI         +"
			<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+";

	//afisare meniu
	cout	<< "\n\n"
			<< "\n\t 1 - operatii intre doi scalari"
			<< "\n\t 2 - operatii intre un scalar si o matrice"
			<< "\n\t 3 - operatii intre doua matrici"
			<< "\n\t 9 - iesire"
			<< "\n >";
	cin >> key;
	return key;
}
void asteapta_apasare_tasta(){
	cout	<< "\n\n"
			<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+"
			<< "\n                         BADEA Ionut Catalin (Anul I Semestrul II - ID - 2016)"
			<< "\n +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+"
			<< "\n\n";
	system("pause");
}

//*****************************************************************************
// functii citire tip_date, scalari, matrici
//citeste tip date
void citeste_tip_date(){
	do{
		cout	<< "\n\n Selectati tipul de date" 
				<< "\n\t i - numere intregi"
				<< "\n\t f - numere reale"
				<< "\n > ";
		cin >> tip_date;
		if((tip_date!='i') && (tip_date!='I') && (tip_date!='f') && (tip_date!='F'))
			cout << "ATENTIE: Tipul de date selectat trebuie sa fie \n 'i' (numere intregi) sau 'f' (numere reale)!";
	}while((tip_date!='i') && (tip_date!='I') && (tip_date!='f') && (tip_date!='F'));

	if((tip_date=='i') || (tip_date=='I')) tip_date = 'i';
	if((tip_date=='f') || (tip_date=='F')) tip_date = 'f';

	cout << "\n +---------------------------------------------------------------------------+";
};
//citeste scalar A
void citeste_scalar_A(){
	cout << "\n [ Scalarul A ]\n";
	cout << "\n Intorduceti valoarea scalarului A : ";
	if(tip_date=='i' || tip_date=='I'){ 
		int scalar;
		cin >> scalar;
		mAi.set_linii(1);
		mAi.set_coloane(1);
		mAi(0,0) = scalar; 
	}else{ 
		float scalar;
		cin >> scalar;
		mAf.set_linii(1);
		mAf.set_coloane(1);
		mAf(0,0) = scalar; 
	}
	cout << "\n .............................................................................";
};
//citeste scalar B
void citeste_scalar_B(){
	cout << "\n [ Scalarul B ]\n";
	cout << "\n Intorduceti valoarea scalarului B : ";
	if(tip_date=='i' || tip_date=='I'){ 
		int scalar;
		cin >> scalar;
		mBi.set_linii(1);
		mBi.set_coloane(1);
		mBi(0,0) = scalar; 
	}else{ 
		float scalar;
		cin >> scalar;
		mBf.set_linii(1);
		mBf.set_coloane(1);
		mBf(0,0) = scalar; 
	}
	cout << "\n .............................................................................";
};
//citeste matrice A
void citeste_matrice_A(){
	//citim matricea A
	cout << "\n [ Matricea A ]\n";

	//citim nr de linii pt A
	do{
		cout << "\n Intorduceti numarul de linii ( intre 1 si 10) : ";
		cin >> nr_linii_A;
		if(nr_linii_A < 1 || nr_linii_A > 10) 
			cout << "\t ATENTIE : Numarul de linii trebuie sa fie cuprins intre 1 si 10! \n";
	}while(nr_linii_A < 1 || nr_linii_A > 10);

	//citim nr de coloane pt A
	do{
		cout << "\n Intorduceti numarul de coloane ( intre 1 si 10) : ";
		cin >> nr_coloane_A;
		if(nr_coloane_A < 1 || nr_coloane_A > 10) 
			cout << "\t ATENTIE : Numarul de coloane trebuie sa fie cuprins intre 1 si 10! \n";
	}while(nr_coloane_A < 1 || nr_coloane_A > 10);

	cout << "\n Intorduceti elementele matricii A: ";
	if(tip_date=='i' || tip_date=='I'){ 
		mAi.set_linii(nr_linii_A);
		mAi.set_coloane(nr_coloane_A);
		cin >> mAi; 
	}else{ 
		mAf.set_linii(nr_linii_A);
		mAf.set_coloane(nr_coloane_A);
		cin >> mAf; 
	}
	cout << "\n .............................................................................";
};
//citeste matrice B
void citeste_matrice_B(){
	cout << "\n[ Matricea B ]\n";

	//citim nr de linii pt B
	do{
		cout << "\n Intorduceti numarul de linii ( intre 1 si 10) : ";
		cin >> nr_linii_B;
		if(nr_linii_B < 1 || nr_linii_B > 10) 
			cout << "\t ATENTIE : Numarul de linii trebuie sa fie cuprins intre 1 si 10! \n";
	}while(nr_linii_B < 1 || nr_linii_B > 10);

	//citim nr de coloane pt B
	do{
		cout << "\n Intorduceti numarul de coloane ( intre 1 si 10) : ";
		cin >> nr_coloane_B;
		if(nr_coloane_B < 1 || nr_coloane_B > 10) 
			cout << "\t ATENTIE : Numarul de coloane trebuie sa fie cuprins intre 1 si 10! \n";
	}while(nr_coloane_B < 1 || nr_coloane_B > 10);

	cout << "\n Intorduceti elementele matricii : ";
	if(tip_date=='i' || tip_date=='I'){ 
		mBi.set_linii(nr_linii_B);
		mBi.set_coloane(nr_coloane_B);
		cin >> mBi; 
	}else{ 
		mBf.set_linii(nr_linii_B);
		mBf.set_coloane(nr_coloane_B);
		cin >> mBf; 
	}
	
	cout << "\n +---------------------------------------------------------------------------+";
};
