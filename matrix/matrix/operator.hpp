#pragma once
#include"matrix.h"
using namespace zw;
template<class T>
matrix<T>& matrix<T>::operator+(const matrix<T>& mat)
{
	matrix<T> res(rows, cols);
	for (int i = rows;i--;)
		for (int j = cols;j--;)
			res(i, j) = (*this)(i, j) + mat(i, j);
	return res;
}
template<class T>
matrix<T>& matrix<T>::operator-(const matrix<T>& mat)
{
	matrix<T> res(rows, cols);
	for (int i = rows;i--;)
		for (int j = cols;j--;)
			res(i, j) = (*this)(i, j) - mat(i, j);
	return res;
}
template<class T>
matrix<T>& matrix<T>::operator-()
{
	matrix<T> res(rows, cols);
	for (int i = rows;i--;)
		for (int j = cols;j--;)
			res(i, j) = -(*this)(i, j)
			return res;
}

template<class T>
matrix<T>& matrix<T>::operator*(const T &k)
{
	matrix<T> res(rows, cols);
	for (int i = rows;i--;)
		for (int j = cols;j--;)
			res(i, j) = k*(*this)(i, j);
	return res;
}

template<class T>
matrix<T>& matrix<T>::operator*(const matrix<T>&mat)
{
	matrix<T> res(rows, cols);
	for (int i = rows;i--;)
		for (int j = mat.get_col();j--;) {
			res(i, j) = 0;
			for (int k = cols;k--)
				res(i, j) += mat(k, j)*(*this)(i, k);
		}
	return res;
}
template<class T>
matrix<T>& zw::matrix<T>::operator/(const T &)
{
	return (*this)*(1 / k);
}