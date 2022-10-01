#include <iostream>
#include <stdlib.h>
#define mx 100 ///max size of queue

using namespace std;

class Queue{
private:
    int item[mx], left, right;

public:
    Queue(){
        left = -1;
        right= -1;
    }

    bool isFull(){
        if(right-left+1 == mx)
            return true;
        else
            return false;
    }

    bool isEmpty(){
        if(left == right)
            return true;
        else
            return false;
    }

    void Enqueue(int element){
        if(isFull()){
            cout << "Queue is full!" << endl;
        }else{
            if(left == -1)
                left = 0;
            right++;
            item[right]=element;
        }
    }

    void Dequeue(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
        }else{
            if(left == right){
                left = -1;
                right = -1;
            }else left++;
        }
    }

    void Display(){
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
        }else{
            for(int i = left; i <= right; ++i){
                cout << item[i] << ' ';
            }
            cout << endl;
        }
    }
};

int main(){
    Queue qe;

    qe.Dequeue();

    qe.Enqueue(6);
    qe.Enqueue(7);
    qe.Enqueue(1);
    qe.Enqueue(3);
    qe.Enqueue(10);

    qe.Display();

    qe.Dequeue();
    qe.Dequeue();

    qe.Display();

    return 0;
}
