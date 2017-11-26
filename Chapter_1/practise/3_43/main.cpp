#include <iostream>
#include <experimental/filesystem>
#include <string>
namespace fs = std::experimental::filesystem;

void recurPrintPath(const char* str)
{
    fs::path p = str;
    if(!fs::is_directory(p))
    {
        std::cerr << p.filename() << " is not a directory" << std::endl;
        exit(1);
    }
    for(auto&c : fs::directory_iterator(p.c_str()))
    {
        if(fs::is_directory(c.path()))
        {
            recurPrintPath(c.path().c_str());
        }else
        {
             std::cout << c << std::endl;
        }
    }
}
    
int main(int argc, char *argv[])
{
    recurPrintPath(argv[1]);
    return 0;
}
