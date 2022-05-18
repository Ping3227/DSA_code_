#ifndef MATIRX_H 
#define MATIRX_H
#include <utility>
#include <iostream>
#include <vector>

template <typename T>
class Matrix {
private:
	std::vector<std::vector<T>> matrix; // [row][col]
	int Row{};
	int Col{};
public:
	Matrix(int row, int col);
	
	// manipulate
	void transpose();
	void rotate();
	void flip();
	void print_matrix();
	void set_matrix();
};
#endif

template <typename T>
Matrix<T>::Matrix(int row, int col) {
	matrix.resize(row, std::vector<T>(col));
	Row = row;
	Col = col;
};

template <typename T>
void Matrix<T>::transpose() {
	std::vector<std::vector<T>> swapped(Col, std::vector<T>(Row));
	for (int i{}; i < Col; i++) {
		for (int j{}; j < Row; j++) {
			swapped[i][j] = matrix[j][i];

		}
	}
	
	std::swap(swapped, matrix);
	std::swap(Row, Col);
};

template <typename T>
void Matrix<T>::rotate() {
	std::vector<std::vector<T>> swapped(Col, std::vector<T>(Row));
	for (int i{}; i < Col; i++) {
		for (int j{}; j < Row; j++) {
			swapped[i][j] = matrix[Row-1-j][i];

		}
	}

	std::swap(swapped, matrix);
	std::swap(Row, Col);
};

template <typename T>
void Matrix<T>::flip(){
	std::vector<std::vector<T>> swapped(Row, std::vector<T>(Col));
	for (int i{}; i < Row; i++) {
		for (int j{}; j < Col; j++) {
			swapped[i][j] = matrix[Row - 1 - i][j];

		}
	}
	std::swap(swapped, matrix);
};


template <typename T>
void Matrix<T>::print_matrix() {
	std::cout << Row << ' '
		<< Col << std::endl;
	for (int i{}; i < Row; i++) {
		for (int j{}; j < Col; j++) {
			std::cout << matrix[i][j];
			if (j != Col)  std::cout << ' ';
		}
		std::cout << std::endl;
	}
};

template <typename T>
void Matrix<T>::set_matrix() {
	for (int i{}; i < Row; i++) {
		for (int j{}; j < Col; j++) {
			std::cin >> matrix[i][j];
		}
	}
};