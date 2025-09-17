#include <bits/stdc++.h>

using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

Student get_student()
{
    string name;
    int roll, marks;
    cin >> name >> roll >> marks;
    Student stdnt(name, roll, marks);
    return stdnt;
}

class cmp
{
public:
    bool operator()(Student l, Student r)
    {
        if (l.marks < r.marks)
            return true;
        else if (l.marks > r.marks)
            return false;
        else
            return l.roll > r.roll;
    }
};

int main()
{

    int n;
    cin >> n;

    priority_queue<Student, vector<Student>, cmp> pq;
    while (n--)
    {
        Student st = get_student();
        pq.push(st);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 0)
        {
            Student st = get_student();
            pq.push(st);
            Student mx = pq.top();
            cout << mx.name << " " << mx.roll << " " << mx.marks << endl;
        }
        else if (cmd == 1)
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
            {
                Student mx = pq.top();
                cout << mx.name << " " << mx.roll << " " << mx.marks << endl;
            }
        }
        else
        {
            if (!pq.empty())
                pq.pop();

            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                Student mx = pq.top();
                cout << mx.name << " " << mx.roll << " " << mx.marks << endl;
            }
        }
    }

    return 0;
}
