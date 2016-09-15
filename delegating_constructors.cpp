#include <iostream>

class sample
{
public:
	sample();
	sample(int i);
private:
	int in;
};

sample::sample() : sample(0)
{
	std::cout << "sample()" << in << std::endl;
}

sample::sample(int i) : in(i)
{
	std::cout << "sample(int i)" << in <<  std::endl;
}

int main()
{
	sample s;
	
	return 0;
}
