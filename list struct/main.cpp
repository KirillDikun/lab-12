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

struct list
{
    note value;
    list *next;
};

list* create();
void sort(list*);
void print(const list*);
void add_new(list*, string, string, int, int, int);
void delel(list*, int);
void del(list*);

int main()
{
    list *list_1=nullptr;
    list_1=create();
    int choice, flag=0;
    do{
    cout<<"\nChoice:\n1.Enter element\n2.Delete element\n3.Print all elements\n0.Exit\n\n";
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
            add_new(list_1, name, phone, date_1, date_2, date_3);
            break;
            }

            case 2:
            {
            int num;
            cout<<"Enter number: ";
            cin>>num;
            delel(list_1, num);
            }
            break;

            case 3:
            print(list_1);
            break;

            case 0:
            del(list_1);
            delete list_1;
            flag=1;
            break;

            default:
            cout<<"Incorrect choice"<<endl;
        }
    }while(flag!=1);
}

list* create()
{
    list *l;
    l=new list;
    l->next=nullptr;
    return l;
}

void add_new(list *head, string name , string phone, int date_1, int date_2, int date_3)
{
            {
            list *l=nullptr, *p=nullptr;
            l=new list;
            p=head->next;
            head->next=l;
            l->next=p;
            l->value.name=name;
            l->value.phone=phone;
            l->value.date[0]=date_1;
            l->value.date[1]=date_2;
            l->value.date[2]=date_3;
            }
    sort(head);
}

void sort(list *head)
{
    string Buf;
    note p;
    list *buf=nullptr, *t=nullptr;
    while(head->next!=nullptr)
        {
        t=head;
        buf=head->next;
        Buf=head->next->value.name;
        while(head->next!=nullptr && head!=nullptr)
            {
            if(head->next->value.name<Buf)
                {
                Buf=head->next->value.name;
                buf=head->next;
                }
            head=head->next;
            }
        p=t->next->value;
        t->next->value=buf->value;
        buf->value=p;
        head=t->next;
        }
}

void print(const list *head)
{
    int count=1;
head=head->next;
while (head!=nullptr)
    {
    cout<<"Number: "<<count<<endl;
    cout<<"Name: "<<head->value.name<<endl;
    cout<<"Phone: "<<head->value.phone<<endl;
    cout<<"Date: "<<head->value.date[0]<<" "<<head->value.date[1]<<" "<<head->value.date[2]<<endl<<endl;
    count++;
    head=head->next;
    }
    if(count==1)
        cout<<"Elements missing"<<endl;
}

void delel(list *head, int number)
{
    list *buf=nullptr;
    int count=1;
    while(head!=nullptr && head->next!=nullptr)
        {
        if(number==count)
            {
            buf=head->next;
            head->next=head->next->next;
            delete buf;
            }
        else
            head=head->next;
        count++;
        }
}

void del(list *head)
{
list *next=nullptr, *buf=nullptr;
next=head->next;
head->next=nullptr;
while(next!=nullptr)
    {
    buf=next->next;
    delete next;
    next=buf;
    }
}

