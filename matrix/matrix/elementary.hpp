#pragma once
#include"matrix.h"
using namespace zw;
template<class T>
const matrix<T>& matrix<T>::trn()
{
	matrix<T> res(cols, rows);
	for (int i = rows;i--;)
		for (int j = cols;j--;)
			res(j, i) = (*this)(i, j);
	return res;
}
template<class T>
const matrix<T>& matrix<T>::traverse(const operate<T>& op)
{
	matrix<T> res(rows, cols);
	for (int i = rows;i--;)
		for (int j = cols;j--;)
			res(i, j) = op((*this)(i, j));
	return res;
}
template<class T>
void matrix<T>::k_row(int row, const T & k) {
	for (int i = cols;i--;)
		(*this)(row, i) *= k;
}
template<class T>
void matrix<T>::k_col(int col, const T & k) {
	for (int i = rows;i--;)
		(*this)(i, col) *= k;
}
template<class T>
void matrix<T>::k_row_add(int des_row, int src_row, const T & k) {
	for (int i = cols;i--;)
		(*this)(des_row, i) += k*(*this)(src_row, i);
}

template<class T>
void matrix<T>::k_col_add(int des_col, int src_col, const T & k) {
	for (int i = rows;i--;)
		(*this)(i, des_col) += k*(*this)(i, src_col);
}

template<class T>
void matrix<T>::ele_change() {

}

template<class T>
const matrix<T>& matrix<T>::ele_change(const matrix<T>&)
{
	// TODO: insert return statement here
}