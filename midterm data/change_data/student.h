#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::stack<std::vector<std::queue<int>>> b;
    while(!a.empty()){ //stack ใช้จนกว่าจะempty
        auto current_vector = a.top(); //vector
        a.pop();
        
        for(auto &current_queue : current_vector){ //queue
            
            auto queuesize = current_queue.size(); //ใช้จนกว่าจะเท่าขนาดqueue
            while(queuesize--){ //element in queue
                auto temp = current_queue.front();
                current_queue.pop();
                if(temp==from)temp=to;
                current_queue.push(temp);
            }

        }
        b.push(current_vector);
    }
    while(!b.empty()){ 
        a.push(b.top());
        b.pop();
    }
    // your code here
}


void change_2(std::map<string, std::pair<std::priority_queue<int>, int> > &a, int from, int to)
{
    for(auto &p : a){
        std::priority_queue<int> newpq;
        if(p.second.second==from){p.second.second = to;}
        auto pq = p.second.first;
        while(!pq.empty()){
            if(pq.top()==from){newpq.push(to);}
            else{newpq.push(pq.top());}
            pq.pop();
        }
        p.second.first = newpq;
    }
    // your code here
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string> > > > &a, int from, int to)
{
    // your code here
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string> > > > newa;
    for(auto &p:a){
        std::list<int> tl;
        for(auto &l:p.first){
            if(l == from)tl.push_back(to);
            else tl.push_back(l);
        }
        std::map<int, std::pair<int, string> > newmap;
        for(auto &m:p.second){
            std::pair<int, string> newpair;
            if(m.second.first == from){
                newpair = make_pair(to, m.second.second);
            }
            else{
                newpair = make_pair(m.second.first, m.second.second);
            }

            if(m.first == from){
                newmap[to] = newpair;
            }
            else{
                newmap[m.first] = newpair;
            }

        }
        newa.insert(make_pair(tl,newmap));

    }
    a = newa;
}

#endif
