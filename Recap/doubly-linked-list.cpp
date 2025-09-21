#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev = NULL;
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

    if (!head)
    {
        head = newnode;
        tail = newnode;
        sz++;
        return;
    }

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
    sz++;
}

void insert_at_any_pos(Node *&head, Node *&tail, int val, int pos)
{
    Node *newnode = new Node(val);

    if (sz <= pos)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *temp = head;

    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
    sz++;
}

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    sz++;

    if (!head)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void delete_at_head(Node *&head, Node *&tail)
{
    if (!head)
        return;

    Node *delete_node = head;
    head = head->next;
    head->prev = NULL;
    delete delete_node;
    sz--;
}

void delete_at_any_pos(Node *&head, int pos)
{
    if (!head)
        return;

    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    Node *delete_node = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete delete_node;
    sz--;
}

void delete_at_tail(Node *&tail)
{
    if (!tail)
        return;

    Node *delete_node = tail;
    tail = tail->prev;
    tail->next = tail->next->next;
    delete delete_node;
    sz--;
}

void reverse_list(Node *&head, Node *&tail)
{
    for (Node *i = head, *j = tail; i != j && i->next != j; i = i->next, j = j->prev)
        swap(i->val, j->val);
}

void print_list(Node *head)
{
    cout << sz << " => ";
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

    int val;

    while (cin >> val)
        insert_at_tail(head, tail, val);

    print_list(head);
    // insert_at_any_pos(head, tail, 10, 1);
    // print_list(head);
    // insert_at_tail(head, tail, 100);
    // print_list(head);
    // delete_at_head(head, tail);
    // print_list(head);
    // delete_at_any_pos(head, 3);
    // print_list(head);
    // delete_at_tail(tail);
    reverse_list(head, tail);
    print_list(head);

    return 0;
}