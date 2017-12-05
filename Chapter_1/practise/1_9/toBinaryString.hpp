#pragma once
#include<string>

std::string toBinaryString(int num)
{
    std::string str{""};
    int mod = 0;
    while(num != 0)
    {
        mod = num % 2;
        if(mod == 0)
        {
            str = '0' + str;
        }else{
            str = '1' + str;
        }
        num /= 2;
    }

    return str;
}
