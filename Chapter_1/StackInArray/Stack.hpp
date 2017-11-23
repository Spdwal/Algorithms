#include<vector>
using namespace std;
template<typename T>
class Stack{
public:
    Stack(int n = 0): data(n){};
    Stack(const Stack &s): data{s.data}{}
    Stack operator=(const Stack &s)
    {
        data = s.data;
        return *this;
    }

    bool empty(){ return data.size() == 0; }

    size_t size(){ return data.size(); }

    void push(T val)
    {
        data.push_back(val);
    }

    T pop()
    {
        T tmp = data.back();
        data.pop_back();
        return tmp;
    }

    void emplace(T item)
    {
        data.back() = item;
    }

    T top()
    {
        return data.back();
    }
private:
    vector<T> data;
};
