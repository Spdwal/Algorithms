#include<utility>
using namespace std;

template<typename T>
class Queue{
private:
    /*     Node      */
    struct Node{
        Node():data(T{}), next{nullptr} {}
        Node(const T& n, Node* p = nullptr): data(n), next(p){}
        Node(T&& n, Node* p = nullptr): data(std::move(n)), next(p) {}
        T data;
        Node * next;
    };


public:
    /*  const iterator */
    class const_iterator{
    public:
        const_iterator() = default;
        const_iterator(Node* p): current(p){}
        const_iterator& operator++()
        {
            current = current->next;
            return *this;
        }
        const_iterator operator++(int)
        {
            Node* tmp = current;
            current = current->next;
            return {tmp};
        }
        T& operator*()
        {
            return retrieve();
        }
        bool operator==(const const_iterator & rhs)
        {
            return current == rhs.current;
        }
        bool operator!=(const const_iterator & rhs)
        {
            return !(*this == rhs);
        }
    protected:
        T& retrieve()const
        {
            return current->data;
        }
        Node* current;
        friend class Queue<T>;
    };


    /*        iterator derived from const iterator     */
    class iterator :public const_iterator{
    public:
        iterator(Node* ptr = nullptr): const_iterator(ptr){}

        T& operator*()
        {
            return const_iterator::retrieve();
        }
        iterator& operator++()
        {
            this->current = this->current->next;
            return *this;
        }
        iterator operator++(int)
        {
            Node* tmp = this->current;
            this->current = this->current->next;
            return {tmp};
        }

        bool operator==(const iterator & rhs)
        {
            return this->current == rhs.current;
        }
        bool operator!=(const iterator & rhs)
        {
            return !(*this == rhs);
        }
    };

    /*     constructor    */
    Queue()
    {
        init();
    }

    Queue(const Queue & rhs)
    {
        init();
        for(auto itr = rhs.begin(); itr!= rhs.end(); itr++)
        {
            push_back(*itr);
        }
    }

    Queue(Queue &&rhs)
    {
        head = rhs.head;
        tail = rhs.tail;
        Size = rhs.Size;
        rhs.init();
    }
    Queue& operator=(const Queue & rhs)
    {
        Queue copy = rhs;
        std::swap(*this, copy);
        return *this;
    }
    Queue& operator=(Queue &&rhs)
    {
        std::swap(Size, rhs.Size);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
    }


    /*  begin cbegin  end cend iterators */

    iterator begin()
    {
        return {head->next};
    }
    const iterator begin() const
    {
        return {head->next};
    }
    const iterator end() const
    {
        return {tail};
    }
    const const_iterator cbegin() const
    {
        return {head->next};
    }
    iterator end()
    {
        return {tail};
    }
    const const_iterator cend() const
    {
        return {tail};
    }

    iterator before_end()
    {
        return {tail->next};
    }
    const const_iterator before_end() const
    {
        return {tail->next};
    }

    
    /* some methods */
    void push_back(const T& item)
    {
        Node *p = new Node(item, tail);
		Size ++;
        tail->next->next = p;
		tail->next = p;
    }
    T pop_front()
    {
        Node *p = head->next;
        head->next = head->next->next;
        T tmp = p->data;
        delete p;
		Size --;
        return tmp;
    }
    int size() const
    {
        return Size;
    }

    bool empty()
    {
        return Size == 0;
    }
    
private:
    Node* head;
    Node* tail;
    int Size;
    void init()
    {
        Size = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->next = head;
    }

    void clear()
    {
        while(!empty())
        {
            pop_front();
        }
    }
};
