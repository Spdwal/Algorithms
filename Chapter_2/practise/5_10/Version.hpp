#include<utility>
#include<string>
using namespace std;

class Version{
public:
    Version(int a, int b, int c): first(a), second(b), third(c){}
    string get(){
        return to_string(first) + '.' + to_string(second) + '.' + to_string(third);
    }

    bool operator==(const Version &rhs){
        return first == rhs.first && second == rhs.second && third == rhs.third;
    }

    bool operator<(const Version &rhs){
        if(first > rhs.first){
            return false;
        }else if(first < rhs.first){
            return true;
        }else{
            if(second > rhs.second){
                return false;
            }else if(second < rhs.second){
                return true;
            }else{
                if(third > rhs.third){
                    return false;
                }else if(third < rhs.third){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }

    bool operator>(const Version &rhs){
        return !((*this < rhs || *this == rhs));
    }
private:
    int first;
    int second;
    int third;
};
