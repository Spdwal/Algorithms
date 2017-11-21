#include<limits>
int lg(int num)
{
	for(int i = 1; i <= std::numeric_limits<int>::max(); ++i)
	{
		if(i*i > num)
		{
			return i-1;
		}else
			continue;
	}
}
