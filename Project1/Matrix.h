#pragma once
#include<iostream>
template <typename T>
class Matrix_templ
{
protected:
	T** mat;
	size_t rw;
	size_t col;
public:
	Matrix_templ(size_t row, size_t column);
	Matrix_templ(Matrix_templ& other);
	Matrix_templ& operator= (const Matrix_templ& other);
	void set(size_t r, size_t c, T dt);
	T get(size_t r, size_t c) const;
	size_t rows() const;
	size_t columns() const;
	Matrix_templ operator*(const Matrix_templ& other);
};

template < typename T>
std::ostream& operator<< (std::ostream& out, Matrix_templ<T>& obj) {
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

#include"Matrix.ipp"