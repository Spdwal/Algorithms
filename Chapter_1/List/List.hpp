#pragma once
#include<utility>
using namespace std;
template<typename T>
class List{
private:
	struct Node{
        Node() = default;
		Node(const T &item, Node* Prev = nullptr, Node* Next = nullptr): data(item), prev(Prev), next(Next) {}
		Node(T&& item, Node* Prev = nullptr, Node* Next = nullptr):data(std::move(item)), prev(Prev), next(Next){}
		T data;
		Node* next;
		Node* prev;
	};
public:
	class const_iterator;
	class iterator;

	List() { init();}
	List(const List& rhs)
    {
        init();
        for(auto c: rhs)
        {
            push_back(c);
        }
    }
	List(List && rhs):theSize(rhs.size), first(rhs.first), tail(rhs.tail)
    {
        rhs.init();
    }
	~List()
    {
        while(!empty())
        {
            pop_back();
        }
    }

	List& operator=(const List& rhs)
    {
        List tmp = rhs;
        std::swap(tmp, *this);
        return *this;
    }
	List& operator=(List && rhs)
    {
        List tmp = rhs;
        std::swap(tmp, *this);
        return *this;
    }

    int size()
    {
        return theSize;
    }
    bool empty()
    {
        return theSize == 0;
    }
	const_iterator cbegin()const{ return {first->next};};
	const_iterator cend()  const{ return {tail};};
	iterator begin(){ return {first->next};}
	iterator end()  { return {tail};};
    const T& front()const{ return *begin();}
    T& front()           { return *begin();}
    const T& back() const{ return *(--end());}
    const T& back()      { return *(--end());}
    iterator insert(iterator itr, const T & item)
    {
        Node *p = itr.current;
        theSize ++;
        Node * n = new Node(item, p->prev, p);
        p->prev->next = n;
        p->prev = n;
        return n;
    }
    iterator insert(iterator itr, T && item)
    {
        Node *p = itr.current;
        theSize++;
        Node *n = new Node(std::move(item), p->prev, p);
        p->prev->next = n;
        p->prev = n;
    }
    iterator erase(iterator itr)
    {
        Node*p = itr.current;
        iterator retVal{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
        return retVal;
    }
    iterator erase(iterator from, iterator to)
    {
        for(iterator itr = from; itr !=to;)
        {
            itr= erase(itr);
        }
        return to;
    }
    void push_back(const T &item)
    {
        insert(end(), item);
    }
    void push_back(T &&item)
    {
        insert(end(), std::move(item));
    }
    void push_front(const T &item)
    {
        insert(begin(),item);
    }
    void push_front(T &&item)
    {
        insert(begin(), std::move(item));
    }

    void pop_back()
    {
        erase(--end());
    }
    void pop_begin()
    {
        erase(begin());
    }
private:
	int   theSize;
	Node *first;
	Node *tail;
	void init(){
		theSize = 0;
        first = new Node;
        tail = new Node;
		first->next = tail;
		tail->prev = first;
	}
};
#include<utility>
template<typename T>
class List<T>::const_iterator{
public:
	friend class List<T>;
	const_iterator(): current(nullptr){}
	const T &operator*()const { return retrieve();}

	const_iterator& operator++(){
		current = current->next;
		return *this;
	}
    const_iterator& operator--()
    {
        current = current->prev;
        return *this;
    }
    const_iterator& operator--(int)
    {
        const_iterator tmp = *this;
        current = current->prev;
        return tmp;
    }
	const_iterator& operator++(int){
		const_iterator tmp = *this;
		current = current->next;
		return tmp;
	}

	bool operator==(const const_iterator & rhs) const { return current == rhs.current; }
	bool operator!=(const const_iterator & rhs) const { return !(*this == rhs);}
protected:
	Node *current;
	const_iterator(Node * p):current(p){}
	T& retrieve() const { return current->data; }
};


template<typename T>
class List<T>::iterator : public List<T>::const_iterator{
public:
	iterator()= default;
    iterator(Node * p): const_iterator(p){}
    T& operator*(){ return const_iterator::retrieve();}
	const T& operator*() const { return const_iterator::operator*();}

	iterator & operator++(){
		this->current = this->current->next;
		return *this;
	}

	iterator & operator++(int){
		iterator tmp = *this;
		this->current = this->current->next;
		return tmp;
	}
    iterator & operator--()
    {
        this->current = this->current->prev;
        return *this;
    }
    iterator & operator--(int)
    {
        iterator tmp = *this;
        this->current = this->current->prev;
        return tmp;

    }

    friend class List<T>;
};

