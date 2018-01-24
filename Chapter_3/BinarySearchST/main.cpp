#include"BinarySearchST.hpp"
#include<iostream>
#include<string>
using namespace std;


int main()
{
    BinarySearchST<int, int> st;


    for(int i = 0; i < 20; ++i){
        st.put(100+i, i);
    }

    cout << st.get(104) << endl;

    cout << st.get(115) << endl;

    vector<int> ivec = st.Keys(102, 111);
    for(auto c : ivec){
        cout << c << endl;
    }

    st.Delete(107);
    cout << boolalpha << st.contains(107) << endl;


    return 0;
    
}
