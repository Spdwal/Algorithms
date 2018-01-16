#pragma once
#include<vector>
#include<string>
#include<utility>
#include<iostream>
#include<queue>
#include<functional>
#include<random>
#include<algorithm>
using namespace std;


class CPU{
public:
    void push_back(const pair<string, int> &P){
        ivec.push_back(P);
    }

    int time_weight(){
        int total = 0;
        for(auto it = ivec.begin(); it != ivec.end(); ++it){
            total += it->second;
        }
        return total;
    }

    void print(){
        for(auto c : ivec){
            cout << c.first << "      " << c.second << endl;
        }
    }
private:
    vector<pair<string, int>> ivec;
};

void LoadBalancing(){
    function<bool(CPU, CPU)> cmp = [](CPU c1, CPU c2){return c1.time_weight() > c2.time_weight();};
    std::priority_queue<CPU, vector<CPU>, function<bool(CPU ,CPU)>> que(cmp);
    for(int i = 0; i < 8; ++i)
    {
        que.push(CPU());
    }

    vector<pair<string ,int>> tasks;
    random_device rd;
    uniform_int_distribution<int> dist(1,100);

    for(int i = 1; i < 50 ;++i){
        tasks.push_back(make_pair("task" + to_string(i), dist(rd)));
    }

    sort(tasks.begin(), tasks.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs) { return lhs.second < rhs.second;});

    cout << "add the task to the priority_queue" << endl;
    for(auto c : tasks){
        CPU tmp = que.top();
        cout << tmp.time_weight() << endl;
        que.pop();
        tmp.push_back(c);
        que.push(tmp);
    }


    int j = 1;

    cout << "print the que" << endl;
    while(!que.empty()){
        auto c = que.top();
        cout << "CPU" << j++ << ":" << c.time_weight() << endl;
        c.print();
        que.pop();
    }

}

