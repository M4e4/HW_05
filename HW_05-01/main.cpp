#include <iostream>
#include <vector>

template<typename T>
T myPow(T a)
{
	return  a * a;
}
template<typename T>
std::vector<T> myPow(const std::vector<T>& vec)
{
	std::vector<T> temp{ vec };

	for (int i{}; i < vec.size(); ++i)
	{
		temp[i] *= temp[i];
	}
	return temp;
}

int main()
{
	int num{ 4 };
	std::vector<int> vec{ -1, 4, 8 };
	auto printVector = [](std::vector<int> vec)
		{
			for (int i{}; i < vec.size(); ++i)
			{
				std::cout << vec[i] << (i + 1 < vec.size() ? ", " : "\n");
			}
		};

	std::cout << "[IN]: " << num << std::endl;
	std::cout << "[OUT]: " << myPow(4) << std::endl;

	std::cout << "[IN]: ";
	printVector(vec);

	std::vector<int> result{ myPow(vec) };

	std::cout << "[OUT]: ";
	printVector(result);

	return EXIT_SUCCESS;
}