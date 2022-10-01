#include <iostream>
#include <stdlib.h>
#define mx 100 ///max stack size
using namespace std;

class Stack{
private:
    int item[mx], point;

public:
    Stack(){
        point = -1;
    }

    bool isFull(){
        if(point == mx-1)
            return true;
        else return false;
    }

    bool isEmpty(){
        if(point == -1)
            return true;
        else return false;
    }

    void Push(int element){
        if(isFull()){
            cout << "Stack is full!" << endl;
        }else{
            point++;
            item[point] = element;
        }
    }

    void Pop(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
        }else{
            point--;
        }
    }

    int Top(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
        }else{
            return item[point];
        }

    }

    void Display(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
        }else{
            cout << "Elements on stack:" << endl;
            for (int i = point; i>=0; i--){
                cout << item[i] << endl;
            }
        }
    }
};

int main(){

    Stack st;
    st.Pop();///empty stack

    st.Push(4);
    st.Push(2);
    st.Push(14);
    st.Push(10);
    st.Push(9);

    st.Display();

    st.Pop();///pop last 2 elements
    st.Pop();

    st.Display();

    return 0;
}
