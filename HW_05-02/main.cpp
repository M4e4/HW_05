#include <iostream>

template<typename T>
class Table
{
public:
	Table(int row, int column) : row(row), column(column), size(row * column), table(new T[size]) {}

	T* operator[](int index) 
	{
		if (index < 0 || index > size) throw::std::out_of_range("Index out of range");

		return &table[index * column];
	}
	const T* operator[](int index) const
	{
		if (index < 0 || index > size) throw::std::out_of_range("Index out of range");

		return &table[index * column];
	}

	int getSize() const
	{
		return size; 
	}

	~Table()
	{
		delete[] table;
	}

private:
	int row;
	int column;
	int size;
	T* table;
};

int main()
{
	Table<int> table(2, 3);

	table[0][0] = 4;

	std::cout << table[0][0];

	return EXIT_SUCCESS;
}