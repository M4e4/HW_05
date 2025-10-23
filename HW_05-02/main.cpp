#include <iostream>

template<typename T>
class Table
{
public:
	Table(int row, int column) : row(row), column(column), size(row * column), matrix(new T[size]) {}

	Table(const Table& other) : row(other.row), column(other.column), size(other.size), matrix(new T[size])
	{
		for (int i{}; i < size; ++i)
		{
			matrix[i] = other.matrix[i];
		}
	}

	Table& operator=(const Table& other)
	{
		if (this == &other) return *this;

		delete[] matrix;

		row = other.row;
		column = other.column;
		size = other.size;
		matrix = new T[size];

		for (int i{}; i < size; ++i)
		{
			matrix[i] = other.matrix[i];
		}
		return *this;
	}
	T* operator[](int index) 
	{
		if (index < 0 || index >= row) throw std::out_of_range("Index out of range");

		return &matrix[index * column];
	}
	const T* operator[](int index) const
	{
		if (index < 0 || index >= row) throw std::out_of_range("Index out of range");

		return &matrix[index * column];
	}

	int getSize() const
	{
		return size; 
	}

	~Table()
	{
		delete[] matrix;
	}

private:
	int row;
	int column;
	int size;
	T* matrix;
};

int main()
{
	Table<int> matrix(2, 3);

	matrix[0][0] = 4;

	std::cout << matrix[0][0];

	return EXIT_SUCCESS;
}