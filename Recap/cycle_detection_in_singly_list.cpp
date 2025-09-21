#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next = NULL;

    Node(int val)
    {
        this->val = val;
    }
};

int sz = 0;

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        sz++;
        return;
    }

    tail->next = newnode;
    tail = newnode;
    sz++;
}

void detect_cycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    bool flag = false;
    while (slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "Cycle Detected!" << endl;
    else
        cout << "No Cycle" << endl;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL, *tail = NULL;

    int n;
    int val;

    while (cin >> val)
        insert_at_tail(head, tail, val);

    tail->next = head;

    detect_cycle(head);
    // print_list(head);

    return 0;
}