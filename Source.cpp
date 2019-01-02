#include <iostream>
#include <vector>
#include "Matrice.h"

void displayMain();

int main() {
	displayMain();

	Matrix A({ {4, -3}, {2, 9} }), B({ {1, 14}, {-2, 3} });
	Matrix S, M({ {2, 2}, {4, 3} }), K({ {5, 2, 3}, {2, 3, -5}, {3, 4, 0} });
	
	// Operations Basiques
	std::cout << "Operations basiques" << std::endl;
	std::cout << "A.getValues() :" << std::endl;
	A.getValues();
	std::cout << "B.getValues() :" << std::endl;
	B.getValues();

	//Operations Arithmetiques
	std::cout << std::endl << "Operations Arithmetiques" << std::endl;
	std::cout << "S = A + B :" << std::endl;
	S = A + B;
	S.getValues();
	std::cout << "S = A - B :" << std::endl;
	S = A - B;
	S.getValues();
	std::cout << "S = A * B :" << std::endl;
	S = A * B;
	S.getValues();

	//Operations logique
	std::cout << std::endl << "Operations Logiques" << std::endl;
	if (A == B)
		std::cout << "La Matrice A est egal a B" << std::endl;
	else
		std::cout << "La Matrice A n'est pas egal a B" << std::endl;

	//Calcul Matriciels
	std::cout << std::endl << "Calculs Matriciels" << std::endl;
	std::cout << "A.determinant() :" << A.determinant() << std::endl;
	std::cout << "A.transposition() :" << std::endl;
	A.transposition();
	A.getValues();
	std::cout << "A.inverse() :" << std::endl;
	A.inverse();
	return 0;
}



/*
	std::vector <std::vector <int>> v{ {2, 4}, {3, 5, 4}, {3, 5} };
	for (auto i : v) {
		for (auto j : i) {
			std::cout << j << ' ';
		}
		std::cout << std::endl; M2({ {2, 3, 4}, {-2, 3, 5}, {8, 0, 1} }) M2({ {2, 3}, {-2, 3}, {8, 0} })
	}
*/

void displayMain()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "		Gestion de Matrices " << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}
