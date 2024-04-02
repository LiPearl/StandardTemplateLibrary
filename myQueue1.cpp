#include <iostream>
#include <vector>
#include <list>
using namespace std;
class myQueue{
public:
    list<vector<int>> l1;
    int begin =0, end = 0;
    void push(int data){
        if(l1.size() == 0 || end == 4){
            l1.push_back(vector<int> (4));
            end = 0;
        }
        l1.back()[end] = data;
        end++;
    }
    void pop(){
        if(l1.size()==0||(l1.size()==1 && begin == end))
            return;
        cout<<l1.front()[begin]<<endl;
        begin++;
        if(begin==4){
            l1.pop_front();
            begin = 0;
        }
    }
};

int main(){
    myQueue q1;
    for(int i=1;i<6;i++)
        q1.push(i);
    for(int i=0;i<6;i++){
        q1.pop();
    }
}