#pragma once
#include"point.h"
#include<iostream>
template <typename T>
class Matrix_templ
{
protected:
	T** mat;
	size_t rw;
	size_t col;
public:

	Matrix_templ(size_t row, size_t column) : rw(row), col(column) {
		mat = new T * [column];
		mat[0] = new T[col * rw];
		//mat[0] = { 0 };
		for (size_t i = 1; i < col; i++)
		{
			mat[i] = mat[0] + i * rw;
		}
		for (size_t i = 0; i < col; i++)
		{
			for (size_t j = 0; j < rw; j++)
			{
				mat[i][j] = 0;
			}
		}
	}

	Matrix_templ(Matrix_templ& other) {
		rw = other.rw, col = other.col;
		mat = new T * [col];
		mat[0] = new T[col * rw];
		for (size_t i = 0; i < col; i++)
		{
			if (i)
				mat[i] = mat[0] + i * rw;
			for (size_t k = 0; k < rw; k++)
			{
				mat[i][k] = other.mat[i][k];
			}
		}
	}

	Matrix_templ& operator= (const Matrix_templ& other) {
		delete[] mat[0];
		delete[] mat;
		rw = other.rw, col = other.col;
		mat = new T * [col];
		mat[0] = new T[col * rw];
		for (size_t i = 0; i < col; i++)
		{
			if (i)
				mat[i] = mat[0] + i * rw;
			for (size_t k = 0; k < rw; k++)
			{
				mat[i][k] = other.mat[i][k];
			}
		}
		return *this;
	}

	void set(size_t r, size_t c, T dt) {
		if (r > rw || c > col) throw std::exception("Out of range!");
		mat[r][c] = dt;
	}

	T get(size_t r, size_t c) const {
		if (r > rw || c > col) throw std::exception("Out of range!");
		return mat[r][c];
	}

	size_t rows() const { return rw; }

	size_t columns() const { return col; }

	Matrix_templ operator*(const Matrix_templ& other) {
		if (col != other.rw) throw std::exception("Matrixes cannot be multiplied!");
		Matrix_templ tmp(rw, col);
		for (size_t i = 0; i < col; i++)
		{
			for (size_t j = 0; j < other.rw; j++)
			{
				for (size_t k = 0; k < rw; k++)
				{
					tmp.mat[i][j] += mat[i][k] * other.mat[k][j];
				}
			}
		}
		return tmp;
	}

};

template < typename T>
std::ostream& operator<< (std::ostream& out, Matrix_templ<T> obj) {
	for (size_t i = 0; i < obj.columns(); i++)
	{
		for (size_t j = 0; j < obj.rows(); j++)
		{
			out << obj.get(i, j) << "\t";
		}
		out << std::endl;
	}
	return out;
}