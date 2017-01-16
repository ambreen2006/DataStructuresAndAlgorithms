//
// Created by ambreen on 1/14/17.
// Solution for question in "Cracking the coding interview"
// Question 2.6
//

#include <iostream>
#include <memory>
#include <stack>

using namespace std;

struct Node {
    int value;
    shared_ptr<Node> next;
    Node(char v) : value(v) {};
};

shared_ptr<Node> head;

void createSampleList(string str)
{
    auto ptr = head;
    for (const char ch : str)
    {
        if(!head) {
            head = make_shared<Node>(ch);
            ptr = head;
        }
        else {
            ptr->next = make_shared<Node>(ch);
            ptr = ptr->next;
        }
    }
}

void printList()
{
    auto ptr = head;
    while(ptr!= nullptr)
    {
        cout << ptr->value;
        ptr = ptr->next;
    }
    cout << endl;
}

bool isPalindrome() {

    auto slow = head;
    auto fast = head;
    stack<int> tempStack;

    while (fast != nullptr && fast->next != nullptr)
    {
        tempStack.push(slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != nullptr)
        slow = slow->next;

    while (slow != nullptr)
    {
       char reverseVal = tempStack.top();
        tempStack.pop();
        if(reverseVal != slow->value)
            return false;
        slow = slow->next;
    }

    return true;
}

int main(int argc, char **argv) {
    createSampleList("s");
    cout << "isPalindrome " << isPalindrome() << endl;
    return 0;
}