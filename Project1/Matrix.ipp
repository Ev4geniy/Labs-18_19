
template <typename T>
Matrix_templ<T>::Matrix_templ(size_t row, size_t column) : rw(row), col(column) {
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

template <typename T>
Matrix_templ<T>::Matrix_templ(Matrix_templ& other) {
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

template <typename T>
Matrix_templ<T>& Matrix_templ<T>::operator= (const Matrix_templ& other) {
	if (this == &other) {
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
	}
	return *this;
}

template <typename T>
void Matrix_templ<T>::set(size_t r, size_t c, T dt) {
	if (r > rw || c > col) throw std::exception("Out of range!");
	mat[r][c] = dt;
}

template <typename T>
T Matrix_templ<T>::get(size_t r, size_t c) const {
	if (r > rw || c > col) throw std::exception("Out of range!");
	return mat[r][c];
}

template <typename T>
size_t Matrix_templ<T>::rows() const { return rw; }

template <typename T>
size_t Matrix_templ<T>::columns() const { return col; }

template <typename T>
Matrix_templ<T> Matrix_templ<T>::operator*(const Matrix_templ& other) {
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