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

void insert_at_head(Node *&head, int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
    sz++;
}

void delete_at_tail(Node *&head, Node *&tail)
{
    if (head == NULL || tail == NULL)
        return;

    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    temp->next = NULL;
    tail = temp;
    sz--;
}

void insert_at_any_pos(Node *&head, Node *&tail, int val, int pos)
{
    if (pos > sz)
        return;

    Node *newnode = new Node(val);
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_at_any_pos(Node *head, int pos)
{
    Node *temp = head;
    for (int i = 0; i < pos; i++)
        temp = temp->next;

    Node *delete_node = temp->next;
    temp->next = delete_node->next;
    delete delete_node;
    sz--;
}

void delete_at_head(Node *&head)
{
    if (head == NULL)
        return;

    Node *delete_node = head;
    head = head->next;
    delete delete_node;
    sz--;
}

void sort_list(Node *head)
{
    for (Node *i = head; i->next != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->val > j->val)
                swap(i->val, j->val);
        }
    }
}

void reverse_print(Node *head)
{
    if (head == NULL)
        return;
    reverse_print(head->next);
    cout << head->val << " ";
}

void reverse_list(Node *&head, Node *curr)
{
    if (!curr->next)
    {
        head = curr;
        return;
    }

    reverse_list(head, curr->next);

    curr->next->next = curr;
    curr->next = NULL;
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert_at_tail(head, tail, val);
    }

    print_list(head);
    // insert_at_any_pos(head, tail, 10, 50);
    // insert_at_head(head, 50);
    // delete_at_any_pos(head, 2);
    // print_list(head);
    // sort_list(head);
    // reverse_print(head);
    reverse_list(head, head);
    print_list(head);

    return 0;
}