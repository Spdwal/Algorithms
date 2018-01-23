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

    vector<pair<string, int>> ivec;
    ivec = st.keys("0", "3");
    for(auto c : ivec){
        cout << c.first << endl;
    }

    st.Delete("2");
    int i = st.get("2");

    cout << i << endl;
    return 0;
}
