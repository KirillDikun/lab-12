#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct note
{
    string name;
    string phone;
    int date[3];
};

struct stack
{
    note value;
    stack  *next;
};

stack* create();
void enstack(stack*, string, string, int, int, int);
void destack(stack*);
void print(stack*);
void del(stack*);

int main()
{
    int choice, flag=0;
    stack *head=nullptr;
    head=create();
    do{
        cout<<"Choice\n1.Add an element to the stack.\n2.Remove an element from the stack.\n3.Print all elements.\n0.Exit."<<endl;
        cin>>choice;
        switch(choice)
            {
                case 1:
                {
                string name, phone;
                int date_1, date_2, date_3;
                cin.get();
                cout<<"Enter name: ";
                getline(cin, name);
                cout<<"Enter phone: ";
                getline(cin, phone);
                cout<<"Enter date: ";
                cin>>date_1>>date_2>>date_3;
                enstack(head, name, phone, date_1, date_2, date_3);
                }
                break;

                case 2:
                destack(head);
                break;

                case 3:
                print(head);
                break;

                case 0:
                del(head);
                delete head;
                flag=1;
                break;

                default:
                cout<<"Incorrect value"<<endl;
                break;
            }

    }while(flag!=1);
}

stack* create()
{
    stack *head=nullptr;
    head=new stack;
    head->next=nullptr;
    return head;
}

void enstack(stack *head, string name, string phone, int date_1, int date_2, int date_3)
{
    while (head->next!=nullptr)
        head=head->next;
    stack *l=nullptr, *p=nullptr;
    l=new stack;
    p=head->next;
    head->next=l;
    l->next=p;
    l->value.name=name;
    l->value.phone=phone;
    l->value.date[0]=date_1;
    l->value.date[1]=date_2;
    l->value.date[2]=date_3;
}

void destack(stack *head)
{
    if(head->next!=nullptr)
        {
        while (head->next->next!=nullptr)
            head=head->next;
        stack *buf=nullptr;
        buf=head->next;
        head->next=head->next->next;
        delete buf;
        }
    else
        cout<<"Elements missing"<<endl<<endl;
}

void print(stack *head)
{
    int count=1;
    head=head->next;
    while(head!=nullptr)
        {
        cout<<"Number: "<<count<<endl;
        cout<<"Name: "<<head->value.name<<endl;
        cout<<"Phone: "<<head->value.phone<<endl;
        cout<<"Date: "<<head->value.date[0]<<head->value.date[1]<<head->value.date[2]<<endl<<endl;
        count++;
        head=head->next;
        }
    if(count==1)
        cout<<"Elements missing"<<endl<<endl;
}

void del(stack *head)
{
    stack *next=nullptr, *buf=nullptr;
    next=head->next;
    head->next=nullptr;
    while(next!=nullptr)
        {
        buf=next->next;
        delete next;
        next=buf;
        }
}


