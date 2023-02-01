
// DataStructureAssignment.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class Element {

public:

    int data;
    Element* next;

};

class Stack {

public:

    Stack();
    ~Stack();

    void push(int);
    void pop();
    void reverse();
    void print();
    int size();
    int top();
    void stackSort(Stack A, Stack B);
    bool empty(Element*);


private:

    Element* tail;
    Element* head;

};

Stack::Stack() {

}

Stack:: ~Stack() {

    tail = NULL;
    head = NULL;
}

void Stack::push(int value) {

    Element* newE = new Element();
    newE->data = value;
    newE->next = NULL;

    if (head == NULL) {

        head = newE;
        tail = newE;
    }
    else {

        while (newE->next->next != NULL) {

            newE = newE->next;
            tail = newE;

        }

    }



}

void Stack::pop() {

    if (tail == NULL) {

        cout << "Stack is empty!";
    }
    else {

        Element* temp = head;
        Element* node = head;
        while (node->next != NULL) {
            node = node->next;
            temp = node->next;
        }

        delete(temp);
        node = NULL;

    }

}
int Stack::size() {

    int count = 0;
    Element* temp = head;
    while (temp != NULL) {

        count++;
        temp = temp->next;
    }
    return count;
}

int Stack::top() {

    Element* temp = new Element();
    int x;

    if (tail == NULL) {

        cout << "There is not top";

    }
    else {

        while (temp->next != NULL) {

            temp = temp->next;
        }

        x = temp->data;


    }

    return x;

}
bool Stack::empty(Element* e) {
    bool answer;
    e = head;
    if (e->next == NULL) {
        answer = true;
    }
    else {
        answer = false;
    }
    return answer;
}
void Stack::reverse() {

    Element* e = head;
    Element* prev = NULL;
    Element* next = NULL;

    while (e != NULL) {

        next = e->next;
        e->next = prev;
        prev = e;
        e = next;

    }

    head = prev;

}

void Stack::stackSort(Stack A, Stack B) {

    Stack a = A;
    Stack b = B;
    Stack C;

    int x;

    while (a.size() != 0 || b.size() != 0) {

        a.reverse();
        b.reverse();

        if (a.top() < b.top()) {

            x = a.top();
            a.pop();
            C.push(x);
            cout << x;
        }
        else {
            x = b.top();
            b.pop();
            C.push(x);
            cout << x;
        }

    }
}



void Stack::print() {

    Element* temp = head;

    while (temp != NULL) {

        temp = temp->next;
    }

    cout << temp->data;
}

int main()
{
    Stack a;
    Stack b;


    a.push(20);
    a.push(15);
    a.push(10);
    a.push(5);


    b.push(16);
    b.push(12);
    b.push(8);
    b.push(4);

    a.size();
    b.size();

    a.top();
    b.top();

    a.print();
    b.print();

    
    stackSort(Stack a, Stack b);



}

