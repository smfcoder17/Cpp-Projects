#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

class Matrix
{
private:
	int rows;
	int cols;
	std::vector <std::vector <double>> values;
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(std::vector <std::vector <double>> entries);
	int getRows();
	int getCols();
	void getValues();
	int getValue(int row, int col);
	void setValue(int row, int col, double value);
	void setValues(std::vector <std::vector <double>> entries);

	/*Fonctions pour les calculs*/
	void transposition();
	double determinant();
	void inverse();
	
	/*Operator interne*/
	bool operator==(Matrix &M);
	//~Matrix();
};

Matrix operator+(Matrix &M1, Matrix &M2);
Matrix operator-(Matrix &M1, Matrix &M2);
Matrix operator*(Matrix &M1, Matrix &M2); 
Matrix operator*(double nb, Matrix &M1);