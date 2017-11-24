#include<iostream>

using namespace std;

template<typename T>
class Queue{
public:
    Queue(int num = 10):Count{0}, head{0}, tail{0}
    {
        if(num < 10)
        {
            num = 10;
        }
        data = new T[num];
        Size = num;
    }

    Queue(const Queue &rhs):data{new T[rhs.Size]}, Size(rhs.Size), Count(0),head{0}, tail{0}
    {
        int pos = rhs.head;
        for(int i = 0; i < rhs.Count; ++i)
        {
            push_back(rhs.data[pos++ % rhs.Size]);
        }
    }

    Queue(Queue &&rhs)
    {
        std::swap(*this, rhs);
    }

    ~Queue()
    {
        if(data)
        {
            delete[] data;
        }
        data = nullptr;
    }

    bool empty()
    {
        return Count == 0;
    }

    int length()
    {
        return Count;
    }

    void push_back(const T& val)
    {
        if(Count == Size)
        {
            Resize();
        }
        Count ++;
        data[tail] = val;
        tail = (tail + 1) % (Size);
    }

    T front()
    {
        return data[head];
    }

    T back()
    {
        if(tail!= 0)
        {
            return data[tail];
        }else{
            return data[Size - 1];
        }
    }
    void pop_front()
    {
        if(Count > 0)
        {
            head = (head + 1) % Size;
            Count--;
        }
        else
            cout << "empty queue" << endl;
    }

    void Resize()
    {
        T *tmp = new T[Size * 2];
        for(int i = 0; i < Size; ++i)
        {
            tmp[i] = data[i];
        }
        std::swap(tmp, data);
        delete[] tmp;
        Size *= 2;
    }
private:
    T * data;
    int  head;
    int  tail;
    int Size;
    int Count;
};
