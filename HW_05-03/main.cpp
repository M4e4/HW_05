#include <iostream>
#include <vector>

class Functor
{
public:
	Functor() : sum(), count() {}

	void operator()(int num)
	{
		sum += !(num % 3) ? (++count, num) : 0;
	}

	int get_sum() const
	{
		return sum;
	}

	int get_count() const
	{
		return count;
	}

private:
	int sum;
	int count;
};

int main()
{
	std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };

	Functor func;

	std::cout << "[IN]: ";
	for (auto a : vec)
	{
		std::cout << a << ' ';
		func(a);
	}
	std::cout << std::endl;

	std::cout << "[OUT]: get_sum() = " << func.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << func.get_count() << std::endl;

	return EXIT_SUCCESS;
}