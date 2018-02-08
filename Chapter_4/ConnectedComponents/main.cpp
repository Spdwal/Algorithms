#include"CC.hpp"
#include<vector>

int main(){
    Graph G(10);

    cin >> G;

    CC a(G);

    cout << boolalpha << a.connected(1,5)  << endl;
    cout << a.count() << endl;
    return 0;
}
