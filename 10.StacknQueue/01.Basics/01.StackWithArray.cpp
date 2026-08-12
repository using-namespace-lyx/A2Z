#include<bits/stdc++.h>
using namespace std;

class ArrayStack {
public:
int topp;
int stack[20];
    ArrayStack() {
        topp=-1;
    }
    
    void push(int x) {

        if(topp==20)
        {
            return;
        }

        stack[++topp]=x;
   
    }
    
    int pop() {

        if(topp==-1) return -1;

        return stack[topp--];
  
    }
    
    int top() {

        if(topp==-1) return -1;
        return stack[topp];
    
    }
    
    bool isEmpty() {

        return topp==-1;
  
    }
};