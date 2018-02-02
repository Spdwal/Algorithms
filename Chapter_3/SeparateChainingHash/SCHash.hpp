#pragma once
#include<map>
#include<memory>
#include<functional>
#include<vector>
using namespace std;

template<typename Key, typename Value>
class SCHash{
public:
    SCHash(int N = 997): ivec(N), mySize{0}{
        for(int i = 0; i < N; ++i){
            ivec[i] = make_shared<map<Key, Value>>();
        }
    }
    
    const size_t hash_code(Key key) const{
        return (std::hash<Key>{}(key) & 0x7FFFFFFF) % (ivec.size() + 1);
    }

    Value operator[](Key k){
        const size_t i = hash_code(k);
        return (*ivec[i])[k];
    }

    void insert(Key k, Value v){
        if((*ivec[hash_code(k)]).count(k) == 0){
            mySize ++;
        }
        (*ivec[hash_code(k)])[k] = v;
    }

    int size(){
        return mySize;
    }
private:
    vector<shared_ptr<map<Key, Value>>> ivec;
    int mySize;
};
