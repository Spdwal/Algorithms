#include<regex>
#include<string>
#include<iostream>
using namespace std;

class Domain{
public:
    Domain() = default;
    Domain(const string &str): myStr(str){
        init();
    }

    bool operator<(const Domain &rhs){
        reverse < rhs.reverse;
    }

    friend ostream& operator<<(ostream &os, const Domain &rhs);
    friend istream& operator>>(istream &is, Domain &rhs);
private:
    void init(){
        std::regex email_reg("^([a-zA-Z0-9_-])+@([a-zA-Z0-9])+\\.([a-zA-Z0-9])+$");
        std::smatch matchResult;
        if(std::regex_match(myStr, matchResult, email_reg)){
            for(int i = matchResult.size() - 1; i >=1; i--){
                reverse += matchResult[i];
            }
        }else{
            myStr += " is not a email adress.";
        }
    }
    string myStr;
    string reverse;
};

ostream& operator << (ostream &os, const Domain &rhs){
    os << rhs.myStr;
    return os;
}

istream& operator >> (istream &is, Domain &rhs){
    is >> rhs.myStr;
    rhs.init();
    return is;
}
