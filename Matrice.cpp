#include "Matrice.h"



Matrix::Matrix() { }

Matrix::Matrix(int row, int col)
{
	if (row > 0 && col > 0) {
		rows = row;
		cols = col;
		for (int i = 0; i < rows; i++) {
			values.push_back(std::vector<double>());
			for (int j = 0; j < cols; j++) {
				values[i].push_back(0);
			}
		}
	}
}

Matrix::Matrix(std::vector<std::vector<double>> entries)
{
	values = entries;
	rows = values.size();
	cols = (*values.begin()).size();
}

int Matrix::getRows()
{
	return rows;
}

int Matrix::getCols()
{
	return cols;
}

void Matrix::getValues() {
	std::cout << std::endl;
	for (auto i = 0; i != rows; i++) {
		for (auto j = 0; j != cols; j++) {
			std::cout << values[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	//std::cout << values.size() << " " << (*values.begin()).size();
}

int Matrix::getValue(int row, int col)
{
	return values[row][col];
}

void Matrix::setValue(int row, int col, double value)
{
	values[row][col] = value;
}

void Matrix::setValues(std::vector<std::vector<double>> entries)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			values[i][j] = entries[i][j];
		}
	}
}

/*Fonctions pour les calculs*/

void Matrix::transposition()
{
	Matrix M(cols, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			M.setValue(j, i, getValue(i, j));
		}
	}
	*this = M;
}

double Matrix::determinant()
{
	if (cols != rows) {
		throw "The Matrix must to be square";
	}
	else {
		double det(0);

		if (cols == 1) {
			det = getValue(0, 0);
		}
		else if (cols == 2) {
			det = (this->getValue(0, 0) * this->getValue(1, 1)) - (this->getValue(0, 1) * this->getValue(1, 0));
		}
		else {
			bool sign(false);
			for (int i = 0; i < cols; i++) {
				sign = !sign;
				std::vector<std::vector<double>> V;
				for (int n = 0; n < rows - 1; n++) {
					V.push_back(std::vector<double>());
					for (int m = 0; m < cols - 1; m++) {
						int val(0);
						V[n].push_back(0.0);
						for (int j = 0; j < rows; j++) {
							if (j != i) {
								if (val <= m) {
									V[n][m] = getValue(n + 1, j);
									val++;
								}
								else {
									break;
								}
							}
						}
					}
				}
				if (sign == true)
					det += getValue(0, i) * Matrix(V).determinant();
				else
					det -= getValue(0, i) * Matrix(V).determinant();
			}
		}
		return det;
	}
}

void Matrix::inverse()
{
	std::cout << std::endl << "In maintenance " << std::endl;
}

/* Operateurs surcharger a l'interieur */

bool Matrix::operator==(Matrix & M)
{
	if (cols == M.cols && rows == M.rows) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				if (getValue(row, col) != M.getValue(row, col))
					return false;
			}
		}
		return true;
	}
	else
		throw "The both Matrix must be have the same size";
}


/* Operateurs surcharger a l'exterieur */

Matrix operator+(Matrix &M1, Matrix & M2)
{
	if ((M1.getCols() != M2.getCols()) || (M1.getRows() != M2.getRows())) {
		throw std::logic_error("Both Matrice need to have same dimensions for addition");
	}
	else {
		Matrix M(M2.getRows(), M2.getCols());
		for (int i = 0; i < M.getRows(); i++) {
			for (int j = 0; j < M.getCols(); j++) {
				M.setValue(i, j, M1.getValue(i, j) + M2.getValue(i, j));
			}
		}
		return M;
	}
}

Matrix operator-(Matrix &M1, Matrix & M2)
{
	if ((M1.getCols() != M2.getCols()) || (M1.getRows() != M2.getRows())) {
		throw std::logic_error("Both Matrice need to have same dimensions for addition");
	}
	else {
		Matrix M(M2.getRows(), M2.getCols());
		for (int i = 0; i < M.getRows(); i++) {
			for (int j = 0; j < M.getCols(); j++) {
				M.setValue(i, j, M1.getValue(i, j) - M2.getValue(i, j));
			}
		}
		return M;
	}
}

Matrix operator*(Matrix & M1, Matrix & M2)
{
	if (M1.getCols() != M2.getRows()) {
		throw "Number of columns of left_Matrix have to be equal at the number of lines of the right_Matrix";
	}
	else {
		Matrix M(M1.getRows(), M2.getCols());
		for (int i = 0; i < M.getRows(); i++) {
			for (int j = 0; j < M.getCols(); j++) {
				double coord(0);
				for (int y = 0; y < M2.getRows(); ++y) {
					coord += M1.getValue(i, y) * M2.getValue(y, j);
				}
				M.setValue(i, j, coord);
			}
		}
		return M;
	}
}

Matrix operator*(double nb, Matrix & M1)
{
	Matrix M(M1.getRows(), M1.getCols());
	for (int i = 0; i < M.getRows(); i++) {
		for (int j = 0; j < M.getCols(); j++) {
			M.setValue(i, j, M1.getValue(i, j) * nb);
		}
	}
	return M;
}

