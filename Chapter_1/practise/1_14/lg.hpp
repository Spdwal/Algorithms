#pragma once
#include<limits>
#include<stdexcept>
int lg(int num)
{
    if(num < 0)
    {
        throw length_error("the num in lg() should >0");
    }else
        for(int i = 1; i <= std::numeric_limits<int>::max(); ++i)
        {
            if(i*i > num)
            {
                return i-1;
            }else
                continue;
        }
}
