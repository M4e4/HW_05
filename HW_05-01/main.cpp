#include <iostream>
#include <vector>

template<typename T>
T myPow(T a)
{
	return  a * a;
}
template<typename T>
void myPow(std::vector<T> &a)
{
	for (int i{}; i < a.size(); ++i)
	{
		a[i] *= a[i];
	}
}

int main()
{
	int num{ 4 };
	std::vector<int> vec{ -1, 4, 8 };
	auto printVector = [&vec]()
		{
			for (int i{}; i < vec.size(); ++i)
			{
				std::cout << vec[i] << (i + 1 < vec.size() ? ", " : "\n");
			}
		};

	std::cout << "[IN]: " << num << std::endl;
	std::cout << "[OUT]: " << myPow(4) << std::endl;

	std::cout << "[IN]: ";
	printVector();

	myPow(vec);

	std::cout << "[OUT]: ";
	printVector();

	return EXIT_SUCCESS;
}