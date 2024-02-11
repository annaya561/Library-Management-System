#include <bits\stdc++.h>
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
node::node()
{
    next = NULL;
}

class Library
{
private:
    node *head;

public:
    Library();
    void login(string, int);
    void login(string, string);
    void sign_up();
    void after_login(string);
    void after_login_admin();
    void student();
    void extract();
    void records_ll(string title, string author, string publisher, int no);
    void display();
    void search(string);
    void search(string, string);
};

Library::Library()
{
    head = NULL;
}
/*********************************** Library functions **********************************/
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
void Library::search(string title)
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
                break;
            }
            else
                cout << "Sorry! We are out of copies of the book." << endl;
        }
        ptr = ptr->next;
    }
    if (flag != 1)
    {
        cout << "Couldn't find the book, please add the name to requested books." << endl;
    }
}
void Library::search(string username, string title)
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
                cout << "Book is available. " << endl;
                break;
            }
            else
                cout << "Sorry! We are out of copies of the book." << endl;
        }
        ptr = ptr->next;
    }
    if (flag != 1)
        cout << "Not available. " << endl;
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
/************************************* Log in / Sign up for user*****************************************/
void Library::login(string username, int password)
{
    ifstream in;
    string name, change;
    int passcode;
    bool flag = true;
    in.open("student_user.txt");
    while (in.eof() == 0)
    {
        getline(in, name);
        getline(in, change);
        stringstream obj;
        obj << change;
        obj >> passcode;
        if (name == username && passcode == password)
        {
            after_login(username);
            flag = false;
        }
        else if (name == username || passcode == password)
        {
            cout << "Incorrect username or password\n";
        }
    }
    in.close();
    if (!flag)
    {
        cout << "Since you didn't have a account. Sign up to issue the book. \n";
        sign_up();
    }
}

void Library::sign_up()
{
    ifstream in;
    string name, username;
    int passcode;
    bool flag = true;
    cout << "Enter username" << endl;
    cin >> username;
    in.open("student_user.txt");
    while (in.eof() == 0)
    {
        getline(in, name);
        if (name == username)
        {
            cout << "You are alredy sign up! \n";
            flag = false;
        }
    }
    in.close();
    if (flag)
    {
        cout << "Enter password (only integers). \n";
        cin >> passcode;
        ofstream out;
        out.open("student_user.txt");
        out << username << endl;
        out << passcode << endl;
        out.close();
    }
}
/******************************* Log in for admin ********************************/
void Library::login(string username, string password)
{
    ifstream fin;
    string name, passcode;
    bool flag = true;
    fin.open("admin_user.txt");
    while (fin.eof() == 0)
    {
        getline(fin, name);
        getline(fin, passcode);
        if (name == username && passcode == password)
        {
            after_login_admin();
            flag = false;
        }
        else if (name == username || passcode == password)
        {
            cout << "Incorrect username or password\n";
        }
    }
    fin.close();
}
/********************************* After log in  *************************************/
void Library::after_login(string username)
{
    int Choice;
    string book_name;
    cout << "1- Search the book. " << endl;
    cout << "2- Issue the book. " << endl;
    cout << "2- Return the book. " << endl;
    cout << "0- Exit" << endl;
    do
    {
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
        {
            cout << "Enter the name of the book.\n";
            cin >> book_name;
            search(username, book_name);
        }
        break;
        break;
        default:
            cout << "Wrong input.\n";
            break;
        case 0:
            exit;
        }

    } while (Choice != 0);
}
void Library::after_login_admin()
{

    int Choice;
    string book_name;
    cout << "1- Search the book. " << endl;
    cout << "2- Issue the book. " << endl;
    cout << "2- Return the book. " << endl;
    cout << "0- Exit" << endl;
    do
    {
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
        {
            cout << "Enter the name of the book.\n";
            cin >> book_name;
            search(book_name);
        }
        break;
        case 2:
            display();
            break;
        case 3:
        {
        }
        break;
        default:
            cout << "Wrong input.\n";
            break;
        case 0:
            exit;
        }

    } while (Choice != 0);
}

void Library::student()
{
    int Choice;
    cout << "1- Sign up. " << endl;
    cout << "2-.Log in" << endl;
    cout << "0- Exit" << endl;
    do
    {
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            sign_up();
            break;
        case 2:
        {
            string username;
            int password;
            cout << "Enter username and password respectively. " << endl;
            cin >> username >> password;
            login(username, password);
        }
        break;
        default:
            cout << "Wrong input.\n";
            break;
        case 0:
            exit;
        }

    } while (Choice != 0);
}
/************************************ main **************************************/
int main()
{
    Library lib;
    lib.extract();
    int Choice;
    cout << "1- Student " << endl;
    cout << "2-.Admin" << endl;
    cout << "0- End the program" << endl;
    do
    {
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            lib.student();
            break;
        case 2:
        {
            string username;
            string password;
            cout << "Enter username and password respectively. " << endl;
            cin >> username >> password;
            lib.login(username, password);
        }
        break;
        default:
            cout << "Wrong input.\n";
            break;
        case 0:
            exit;
        }

    } while (Choice != 0);
    return 0;
}
