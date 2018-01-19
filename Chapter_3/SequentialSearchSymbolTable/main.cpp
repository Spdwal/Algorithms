#include"SequentialSearchST.hpp"
#include<iostream>
#include<string>

using namespace std;


int main()
{
    SequentialSearchST<string ,int> st;

    st.put("1", 1);
    st.put("2", 2);
    st.put("3", 3);

    cout << st.get("2") << endl;
    int i = st.get("4");

    return 0;
}
