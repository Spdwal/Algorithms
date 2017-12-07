#include"PathCompression.hpp"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string filename;
    cout << "Please enter the file name: ";
    cin >> filename;
    fstream fs(filename);
    if(!fs.is_open()){
        cerr << "fail to open the file " << filename << endl;
        return 1;
    }
    int p, q;
    UF uf(11);
    while(fs >>p >> q){
        if(uf.connected(p, q))
            continue;
        uf.Union(p, q);
        cout << p << '-' << q << endl;
    }
    cout << uf.count() << endl;
    return 0;
}
