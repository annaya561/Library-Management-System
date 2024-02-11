#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
class node
{
public:
    node();
    node *next;
    char title[50];
    char author[50], publisher[50];
    int no_copies;
    char rack[50];
};
node ::node()
{
    next = NULL;
}
class Library
{
private:
    node *head;
    node *head1;

public:
    Library();
    void records();
    void search(char abc[50]);
    void issue(char title[50]);
    void return_book(char title[50]);
    void display();
};

Library::Library()
{
    head = NULL;
    head1 = NULL;
}

void Library::records()
{
    node *temp = new node();
    int numberOfNodes = 8;
    node *nodeSet[numberOfNodes];
    for (int i = 0; i < numberOfNodes; ++i)
    {
        nodeSet[i] = new node();
    }
    temp->next = nodeSet[0];
    for (int i = 0; i < numberOfNodes; ++i)
    {
        if (i != numberOfNodes - 1)
        {
            nodeSet[i]->next = nodeSet[i + 1];
        }
        else
        {
            nodeSet[i]->next = NULL;
        }
    }
    strcpy(temp->author, "J_K_Rowling");
    strcpy(temp->title, "Harry_Potter");
    strcpy(temp->publisher, "Jaico_Publishing_House");
    temp->no_copies = 5;
    strcpy(temp->rack, "1-A");

    strcpy(nodeSet[0]->author, "Narayana_Murthy");
    strcpy(nodeSet[0]->title, "A_Better_India:_A_Better_World");
    strcpy(nodeSet[0]->publisher, "Westland_Publications");
    nodeSet[0]->no_copies = 8,
    strcpy(nodeSet[0]->rack, "2-A");

    strcpy(nodeSet[1]->author, "E._M._Foster");
    strcpy(nodeSet[1]->title, "A_passage_to_India");
    strcpy(nodeSet[1]->publisher, "Westland_Publications");
    nodeSet[1]->no_copies = 2;
    strcpy(nodeSet[1]->rack, "2-B");

    strcpy(nodeSet[2]->author, "Vikram_Seth");
    strcpy(nodeSet[2]->title, "A_Suitable_Boy");
    strcpy(nodeSet[2]->publisher, "Peguin_Random_House_India");
    nodeSet[2]->no_copies = 1;
    strcpy(nodeSet[2]->rack, "1-B");

    strcpy(nodeSet[3]->author, "Charles_Darwin");
    strcpy(nodeSet[3]->title, "Oliver_Twist");
    strcpy(nodeSet[3]->publisher, "Peguin_Random_House_India");
    nodeSet[3]->no_copies = 6;
    strcpy(nodeSet[3]->rack, "1-C");

    strcpy(nodeSet[4]->author, "Louis_Fisher");
    strcpy(nodeSet[4]->title, "A_week_with_Gandhi");
    strcpy(nodeSet[4]->publisher, "Rupa_Publications");
    nodeSet[4]->no_copies = 10;
    strcpy(nodeSet[4]->rack, "2-C");

    strcpy(nodeSet[5]->author, "Charles_Darwin");
    strcpy(nodeSet[5]->title, "Origin_of_species");
    strcpy(nodeSet[5]->publisher, "Rupa_Publications");
    nodeSet[5]->no_copies = 2;
    strcpy(nodeSet[5]->rack, "3-A");

    strcpy(nodeSet[6]->author, "Amrita_Pritam");
    strcpy(nodeSet[6]->title, "Death_of_a_city");
    strcpy(nodeSet[6]->publisher, "Rupa_Publications");
    nodeSet[6]->no_copies = 0;
    strcpy(nodeSet[6]->rack, "3-B");

    strcpy(nodeSet[7]->author, "Amrita_Pritam");
    strcpy(nodeSet[7]->title, "A_Revenue_Stamp");
    strcpy(nodeSet[7]->publisher, "Rupa_Publications");
    nodeSet[7]->no_copies = 1;
    strcpy(nodeSet[7]->rack, "3-B");

    head = temp;
}

void Library ::display()
{
    node *ptr;
    ptr = head;
    std::cout << setw(30) << "TITLE"
              << setw(30) << "AUTHOR "
              << setw(30) << "PUBLICATION"
              << setw(20) << "NO. OF COPIES"
              << setw(15) << "POSITION" << endl;
    while (ptr != NULL)
    {
        cout << setw(30) << ptr->title << setw(30) << ptr->author << setw(30) << ptr->publisher << setw(15) << ptr->no_copies << setw(15) << ptr->rack << endl;

        ptr = ptr->next;
    }
}

void Library::search(char title[50])
{
    node *ptr = head;
    bool flag = 0;
    int data;
    while (ptr != NULL)
    {
        if (strcmp(ptr->title, title) == 0)
        {
            flag = 1;
            if (ptr->no_copies > 0)
            {
                cout << "TITLE: " << ptr->title << "\t\tAUTHOR: " << ptr->author << "\t\tPOSITION:  " << ptr->rack << endl;

                issue(title);
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

void Library::issue(char title[50])
{
    node *ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(ptr->title, title) == 0)
        {
            ptr->no_copies--;
            cout << title << " is issued." << endl;
        }
        ptr = ptr->next;
    }
}
void Library::return_book(char title[50])
{
    node *ptr = head;

    while (ptr != NULL)
    {
        if (strcmp(ptr->title, title) == 0)
        {
            ptr->no_copies++;
            cout << "Thank you! for returning the book ." << endl;
        }
        ptr = ptr->next;
    }
}
int main()
{
    class Library lib;
    lib.records();
    int Choice;
    cout << "1- Search and issue the book" << endl;
    cout << "2- Return the book" << endl;
    cout << "3- Show the books in the library." << endl;
    cout << "4- End the program" << endl;
    do
    {
        char title[50], author[50];
        cout << "Enter your choice." << endl;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            cout << "Enter the title ." << endl;
            cin >> title;
            lib.search(title);
            break;
        case 2:
            cout << "Please provide the title of the book." << endl;
            cin >> title;
            lib.return_book(title);
            break;
        case 3:
            lib.display();
            break;
        case 4:
            exit;
        }

    } while (Choice != 4);
    return 0;
}
