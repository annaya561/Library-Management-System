#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
class node
{
public:
    node();
    node *next;
    string title;
    string author, publisher;
    int no_copies;
};
node ::node()
{
    next = NULL;
}
class block
{
public:
    block();
    block *next1;
    int id;
    string title;
    int date;
};
block ::block()
{
    next1 = NULL;
}

class Library
{
private:
    node *head;
    block *head1;

public:
    Library();
    void records_ll(string title, string author, string publisher, int no);
    void extract();
    void students_extract();
    void input();
    void search(int id, string title);
    void issued_student(int id, string title);
    void issued_ll(int, string, int);
    void students_text(int id, string title);
    void return_book(int id, string title);
    int date_com(int id, string title);
    void display();
    void display_issued();
};

Library::Library()
{
    head = NULL;
    head1 = NULL;
}
void Library::records_ll(string title, string author, string publisher, int no)
{
    node *ptr = new node();
    node *p = head;
    ptr->title = title;
    ptr->author = author;
    ptr->publisher = publisher;
    ptr->no_copies = no;
    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
    }
}
void Library::issued_ll(int id, string title, int date)
{
    block *ptr = new block();
    block *p = head1;
    ptr->title = title;
    ptr->id = id;
    ptr->date = date;
    if (head1 == NULL)
    {
        ptr->next1 = NULL;
        head1 = ptr;
    }
    else
    {
        while (p->next1 != NULL)
        {
            p = p->next1;
        }
        p->next1 = ptr;
        ptr->next1 = NULL;
    }
}
void Library::extract()
{
    string title, author, publisher, num;
    int no;
    ifstream in;
    in.open("records.txt");
    while (in.eof() == 0)
    {
        getline(in, title);
        getline(in, author);
        getline(in, publisher);
        getline(in, num);
        stringstream obj;
        obj << num;
        obj >> no;
        records_ll(title, author, publisher, no);
    }
    in.close();
}
void Library::students_extract()
{
    int id, date;
    string s1, s2, title;
    ifstream in;
    in.open("students.txt");
    while (in.eof() == 0)
    {
        getline(in, s1);
        stringstream obj, obj2;
        obj << s1;
        obj >> id;
        getline(in, title);
        getline(in, s2);
        obj2 << s2;
        obj2 >> date;
        issued_ll(id, title, date);
    }
    in.close();
}
void Library ::students_text(int id, string title)
{
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    fstream in;
    in.open("students.txt", fstream::app);
    in << endl
       << id << endl;
    in << title << endl;
    in << t.tm_mday << t.tm_mon + 1 << t.tm_year + 1900;
    in.close();
}
void Library::search(int id, string title)
{
    node *ptr = head;
    bool flag = 0;
    while (ptr != NULL)
    {
        if (ptr->title == title)
        {
            flag = 1;
            if (ptr->no_copies > 0)
            {
                issued_student(id, title);
                break;
            }
            else
                cout << "Sorry! We are out of copies of the book." << endl;
        }
        ptr = ptr->next;
    }
    if (flag != 1)
        cout << "Couldn't find the book, please add the name to requested books." << endl;
}
void Library ::issued_student(int id, string title)
{
    block *ptr = head1;
    bool flag = 0;
    int count = 0, difference;
    while (ptr != NULL)
    {
        if (ptr->id == id && ptr->title == title)
        {
            difference = date_com(id, title);
            if (difference <= 30)
            {
                flag = 1;
                cout << "Sorry! you have issued this book previously also." << endl;
            }
        }
        if (ptr->id == id)
        {
            count++;
        }
        ptr = ptr->next1;
    }
    if (count >= 2)
        cout << "Since you have alredy issued two books. So you can't issue more." << endl;
    else if (flag != 1)
    {
        cout << "Book is isssued." << endl;
        students_text(id, title);
    }
}
void Library::return_book(int id, string title)
{
    int fine;
    block *ptr = head1;
    bool flag = 0;
    while (ptr != NULL)
    {
        if (ptr->id == id && ptr->title == title)
        {
            flag = 1;
            fine = date_com(id, title);
            if (fine > 15)
            {
                cout << "Since you have reurned the book late. Fine will be charged." << endl;
                cout << (fine - 15) << " days late. So you need to pay : " << 10 * (fine - 15) << endl;
            }
            else
                cout << "Thank you for returning the book on time." << endl;
        }
        ptr = ptr->next1;
    }
    if (flag != 1)
        cout << "The details provided are incorrect. Please enter again." << endl;
}
int Library ::date_com(int id, string title)
{
    block *ptr = head1;
    int now, then, rem, rem2, quo;
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    now = (t.tm_year + 1900) * 365 + (t.tm_mon + 1) * 30 + t.tm_mday;
    while (ptr != NULL)
    {
        if (ptr->id == id && ptr->title == title)
        {
            rem = (ptr->date) % 10000;
            quo = (ptr->date) / 10000;
            rem2 = quo % 100;
            then = rem * 365 + rem2 * 30 + quo / 100;
        }
        ptr = ptr->next1;
    }
    return now - then;
}
void Library ::display()
{
    node *ptr;
    ptr = head;
    std::cout << setw(30) << "TITLE"
              << setw(30) << "AUTHOR "
              << setw(30) << "PUBLICATION"
              << setw(20) << "NO. OF COPIES" << endl;
    while (ptr != NULL)
    {
        cout << setw(30) << ptr->title << setw(30) << ptr->author << setw(30) << ptr->publisher << setw(15) << ptr->no_copies << endl;
        ptr = ptr->next;
    }
}
int main()
{
    Library lib;
    lib.extract();
    lib.students_extract();
    int Choice;
    cout << "1- Show books in the library." << endl;
    cout << "2- Search and find whether you can issue the book or not." << endl;
    cout << "3- Return the book" << endl;
    cout << "0- End the program" << endl;
    do
    {
        string title, author, name;
        int id;
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            lib.display();
            break;
        case 2:
            cout << "Enter your id and title of the book ." << endl;
            cin >> id >> title;
            lib.search(id, title);
            break;
        case 3:
            cout << "Please provide your id and title  of the book." << endl;
            cin >> id >> title;
            lib.return_book(id, title);
            break;
        case 0:
            exit;
        }
    } while (Choice != 0);
    return 0;
}
