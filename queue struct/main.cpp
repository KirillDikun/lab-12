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

struct queue
{
    note value;
    queue  *next;
};

queue* create();
void enqueue(queue*, string, string, int, int, int);
void dequeue(queue*);
void print(queue*);
void del(queue*);

int main()
{
    int flag=0;
    int choice;
    queue *head=nullptr;
    head=create();
    do{
        cout<<"Choice\n1.Add an element to the end of the queue.\n2.Remove an element from the beginning of the queue.\n3.Print all elements.\n0.Exit."<<endl;
        cin>>choice;
        cin.get();
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
                    enqueue(head, name, phone, date_1, date_2, date_3);
                }
                break;

                case 2:
                dequeue(head);
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

queue* create()
{
    queue *head=nullptr;
    head=new queue;
    head->next=nullptr;
    return head;
}

void enqueue(queue *head, string name, string phone, int date_1, int date_2, int date_3)
{
    queue *l=nullptr, *p=nullptr;
    l=new queue;
    p=head->next;
    head->next=l;
    l->next=p;
    l->value.name=name;
    l->value.phone=phone;
    l->value.date[0]=date_1;
    l->value.date[1]=date_2;
    l->value.date[2]=date_3;
}

void dequeue(queue *head)
{
    queue *buf=nullptr;
    bool flag=0;
    if(head->next==nullptr)
        {
        cout<<"Elements missing"<<endl<<endl;
        flag=1;
        }
    if(flag==0)
        {
        while(head->next->next!=nullptr)
            head=head->next;
        buf=head->next;
        head->next=head->next->next;
        delete buf;
        }
}

void print(queue *head)
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

void del(queue *head)
{
    queue *next=nullptr, *buf=nullptr;
    next=head->next;
    head->next=nullptr;
    while(next!=nullptr)
        {
        buf=next->next;
        delete next;
        next=buf;
        }
}
