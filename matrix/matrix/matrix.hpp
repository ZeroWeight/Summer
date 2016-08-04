#pragma once
#include<iostream>
namespace zw {
	inline void swap(int& a, int& b) { int temp = a;a = b;b = temp; }
	inline void fill(int* ptr, int& r) { for (;r--;) ptr[r] = r; }
	template<class T>
	class op_out {
		virtual const T& operator()(const T& elem) = 0;
	};
	template<class T>
	class op_in {
		virtual void operator()(T& elem) = 0;
	};
	template<class T>
	class matrix {
	private:
		T** data;
		int* row_rank;
		int* col_rank;
		int rows;
		int cols;
		bool col_row;
	public:
		//constructor
		matrix<T>(const T** data, int row, int col);
		matrix<T>(const matrix<T>& mat);
		matrix<T>(const int row, const int col, const T& k = 0);
		matrix<T>(const int row_col);//I
		~matrix<T>();
		//props
		inline int get_col() { return cols; }
		inline int get_row() { return rows; }
		inline const T& operator()(int row, int col) {
			if (col_row)
				return data[col_rank[col]][row_rank[row];
			else
				return data[row_rank[row]][col_rank[col]];
		}
		inline T* operator[](int row, int col) {
			if (col_row)
				return data[col_rank[col]] + row_rank[row];
			else
				return data[row_rank[row]] + col_rank[col];
		}
		//operator
		const matrix<T>& operator+(const matrix<T>& mat);
		const matrix<T>& operator-(const matrix<T>& mat);
		const matrix<T>& operator*(const matrix<T>& mat);
		const matrix<T>& operator+(const T& k);// A+kI
		const matrix<T>& operator*(const T& k);
		const matrix<T>& operator-(const T& k);
		const matrix<T>& operator/(const T& k);
		const matrix<T>& operator-();
		bool operator==(const matrix<T>& mat);
		void operator=(const matrix<T>& mat);
		//traverse
		const matrix<T>& traverse(const op_out& op);
		void traverse(const op_in& op);
		//trn
		inline void trn() { col_row ^= 1; }
		static const matrix<T>& trn(const matrix<T> mat) {
			matrix<T> res = mat;
			res.trn();
			return res;
		}
		//elementary transformation
		//det
		const T& det();//ele_tran to upper_case
		static const T& det(const matrix<T> mat) {
			matrix<T> res = mat;
			return res.det();
		}
		//output
		friend std::ostream& operator<< (std::ostream& os, const matrix<T> mat);
	};
	//func body
	//constructor
	template<class T>
	matrix<T>::matrix(const T ** data, int row,int col){
		this->data = data;
		this->cols = col;
		this->rows = row;
		this->col_row = 0;
		this->col_rank = new int[col];
		this->row_rank = new int[row];
		fill(this->col_rank, col);
		fill(this->row_rank, row);
	}
	template<class T>
	matrix<T>::matrix(const matrix<T>& mat){
		this->rows = mat.get_row();
		this->cols = mat.get_col();
		this->data = new (T*)[this->rows];
		this->col_rank = new int[this->cols];
		this->row_rank = new int[this->rows];
		fill(this->col_rank, this->cols);
		fill(this->row_rank, this->rows);
		this->col_row = 0;
		for (int i = this->rows;i--;) {
			data[i] = new T[this->cols];
			for (int j = this->cols;j--;)
				data[i][j] = mat(i, j);
		}	
	}
	template<class T>
	matrix<T>::matrix(const int row, const int col, const T & k){
		this->cols = col;
		this->rows = row;
		this->col_row = 0;
		this->data = new (T*)[this->rows];
		this->col_rank = new int[this->cols];
		this->row_rank = new int[this->rows];
		fill(this->col_rank, this->cols);
		fill(this->row_rank, this->rows);
		for (;row--;) {
			data[row] = new T[col];
			for (int i = col;i--;)
				data[row][i] = k;
		}
	} 
	template<class T>
	inline matrix<T>::matrix(const int row_col){
		this->cols = row_col;
		this->rows = row_col;
		this->col_row = 0;
		this->data = new (T*)[this->rows];
		this->col_rank = new int[this->cols];
		this->row_rank = new int[this->rows];
		fill(this->col_rank, this->cols);
		fill(this->row_rank, this->rows);
		for (;row_col--;) {
			data[row_col] = new T[this->cols];
			for (int i = this->cols;i--;)
				if (i == row_col) data[i][row_col] = 1;
				else data[i][row_col] = 0;
		}
	}
	template<class T>
	matrix<T>::~matrix(){
		for (int i = this->rows;i--;) delete data[i] [];
		delete data [];
	}
	template<class T>
	const matrix<T>& matrix<T>::operator+(const matrix<T>& mat)
	{
		matrix res(this->rows, this->cols);

	}

}