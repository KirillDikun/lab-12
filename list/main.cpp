#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct list
{
    int value;
    list *next;
};

list* create();
void print(const list*);
void add_new(list*, int, int);
void del(list*);
int counting(list*);
int findmax(list*);
int findmin(list*);
void delcopy(list*, int);
void delall(list*, int);

int main()
{
    list* list_1=nullptr;
    int choice, value, number, flag=0;
    list_1=create();
    do
        {
    cout<<"Choice:\n1.Create new element\n2.Counting elements\n3.Search for the maximum value\n4.search for the minimum value\n5.Delete all copy of element\n6.Delete all defined elements\n7.Print all elements\n8.Delete all elements\n0.Exit"<<endl;
    cin>>choice;
    switch (choice) {
        case 1:
//            cout<<"Enter element number: ";
//            cin>>number;
//            cout<<"Enter element value: ";
//            cin>>value;
            for(int i=1; i<10;i++)
                {
                cin>>value;
                add_new(list_1, i, value);
                }
            print(list_1);
            break;

        case 2:
            cout<<"Element count: "<<counting(list_1)<<endl;
            break;

        case 3:
            if(list_1->next!=nullptr)
                cout<<"Maximum element: "<<findmax(list_1)<<endl;
            else
                cout<<"Elements missing"<<endl<<endl;
            break;

        case 4:
            if(list_1->next!=nullptr)
                cout<<"MInimum element: "<<findmin(list_1)<<endl;
            else
                cout<<"Elements missing"<<endl<<endl;
            break;

        case 5:
            cout<<"Enter element value: "<<endl;
            cin>>value;
            delcopy(list_1, value);
            break;

        case 6:
            cout<<"Enter element value: "<<endl;
            cin>>value;
            delall(list_1, value);
            break;

        case 7:
            cout<<"List elements: ";
            print(list_1);
            break;

            case 8:
            del(list_1);
            break;

        case 0:
            del(list_1);
            delete list_1;
            flag=1;
            break;

        default:
            cout<<"Incorrect value"<<endl;
            break;
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

void add_new(list *head,int number, int val)
{
    int count=0;
    while(head!=nullptr)
        {
        if(count==number-1)
            {
            list *l=nullptr, *p=nullptr;
            l=new list;
            p=head->next;
            head->next=l;
            l->next=p;
            l->value=val;
            }
        head=head->next;
        count++;
        }
}

int counting(list *head)
{
    head=head->next;
    int count=0;
    while(head!=nullptr)
        {
        head=head->next;
        count++;
        }
    return count;
}

int findmax(list *head)
{
    head=head->next;
    int max=head->value;
    while(head!=nullptr)
        {
        if(max<head->value)
            max=head->value;
        head=head->next;
        }
    return max;
}

int findmin(list *head)
{
    head=head->next;
    int min=head->value;
    while(head!=nullptr)
        {
        if(min>head->value)
            min=head->value;
        head=head->next;
        }
    return min;
}

void print(const list *head)
{
    head=head->next;
    while (head!=nullptr)
        {
        cout<<head->value<<" ";
        head=head->next;
        }
    cout<<endl;
}

void delcopy(list *head, int val)
{
    int flag=0;
    list *buf=nullptr;
    if(head->value==val)
        flag=1;
    while(head!=nullptr && head->next!=nullptr)
        {
        if(head->next->value==val && flag==0)
            {
            flag=1;
            head=head->next;
            continue;
            }
        if(head->next->value==val && flag==1)
            {
            buf=head->next;
            head->next=head->next->next;
            delete buf;
            }
        else
            head=head->next;
        }
}

void delall(list *head, int val)
{
    list *buf=nullptr;
    while(head!=nullptr && head->next!=nullptr)
        {
        if(head->next->value==val)
            {
            buf=head->next;
            head->next=head->next->next;
            delete buf;
            }
        else
            head=head->next;
        }
}

void del(list *head)
{
    list *next=nullptr, *buf=nullptr;
    next=head->next;
    head->next=nullptr;
    while(next!=nullptr)
        {
        buf=next;
        delete next;
        next=buf->next;
        }
}


