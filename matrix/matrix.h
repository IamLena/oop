#pragma once
#include "base.h"
template <typename T>
class Matrix : public base::BaseContainer {
public:
	Matrix();
	explicit Matrix(size_t rows, size_t columns);
	explicit Matrix(size_t rows, size_t columns, T* arr);
	explicit Matrix(size_t rows, size_t columns, std::shared_ptr<T> arr);
	explicit Matrix(size_t rows, size_t columns, std::shared_ptr<std::shared_ptr<T>> arr);
	Matrix(std::initializer_list<std::initializer_list<T>> matrix);

	Matrix(const Matrix<T>& another);
	Matrix(Matrix<T>&& another);

	Matrix<T>& operator = (const Matrix<T>& another);
	Matrix<T>& operator = (Matrix<T>&& another);
	Matrix<T>& operator = (std::initializer_list<std::initializer_list<T>> matrix);

	~Matrix();

	friend std::ostream& operator << (const std::ostream& out; const Matrix<T> matrix);

	int number_of_columns() const;
	int number_of_rows() const;

	bool is_square() const;
	bool is_zero() const;
	bool is_unit() const;
	bool is_diagonal() const;
	bool is_uptriangle() const;
	bool is_downtriangle() const;

	Matrix<T>& to_uptriangle();
	Matrix<T>& to_downtriangle();

	T determinant() const;
	int rang() const;

	Matrix<T> transpose() const;
	Matrix<T> reverse() const;

	Matrix<T> operator + (const Matrix<T>& matrix);
	Matrix<T>& operator += (const Matrix<T>& matrix);
	Matrix<T> operator * (const Matrix<T>& matrix);
	Matrix<T>& operator *= (const Matrix<T>& matrix);

	//[][], elementary transformations

private:
	std::shared_ptr<std::shared_ptr<T>> data;
	size_t columns;
};