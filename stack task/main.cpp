#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct stack
{
    char value;
    stack  *next;
};

stack* create();
bool add_new(stack*, char, int);
void delete_last(stack*);
void print(stack*);
void del(stack*);

int main()
{
    int choice, flag=0, col;
    char standard;
    stack *head=nullptr;
    head=create();
    cout<<"\nEnter number of elements: ";
    cin>>col;
    cout<<"\nEnter standard symbol: ";
    cin>>standard;
    do{
        cout<<"\nChoice\n1.Add an element to the stack.\n2.Remove an element from the stack.\n3.Print all elements.\n4.Сhange number of elements.\n5.Change standard symbol.\n6.Delete all elements.\n0.Exit."<<endl;
        cin>>choice;
                if(choice==1)
                {
                bool rez=0;
                char symbol;
                cin.get();
                cout<<"\nEnter srting: ";
                do{
                    cin>>symbol;
                    if(symbol!=standard)
                        rez=add_new(head, symbol, col);
                    else
                        {
                        cout<<"\nStandard symbol"<<endl<<endl;
                        rez=1;
                        }
                }while(rez==0);
                while(symbol!='\n')
                    symbol=getchar();
                }

                else  if(choice==2)
                    delete_last(head);

                else if(choice==3)
                    print(head);

                else if(choice==4)
                    {
                    cout<<"\nEnter new number of elements: ";
                    cin>>col;
                    }

                else if(choice==5)
                    {
                    cout<<"\nEnter new standard symbol: ";
                    cin>>standard;
                    }

                else if(choice==6)
                    del(head);

                else if(choice==0)
                    {
                    del(head);
                    delete head;
                    flag=1;
                    }
                else
                    cout<<"\nIncorrect value"<<endl;
    }while(flag!=1);
}

stack* create()
{
    stack *head=nullptr;
    head=new stack;
    head->next=nullptr;
    return head;
}

void print(stack *head)
{
    cout<<endl;
    bool flag=0;
    head=head->next;
    while(head!=nullptr)
        {
        cout<<head->value<<" ";
        head=head->next;
        flag=1;
        }
    cout<<endl;
    if(flag==0)
        cout<<"\nElements missing\n"<<endl<<endl;
}

bool add_new(stack *head, char symbol, int col)
{
    int count=0;
    stack *l=nullptr, *p=nullptr;
    while (head->next!=nullptr)
        {
        count++;
        head=head->next;
        }
    if(count<col)
        {
        l=new stack;
        p=head->next;
        head->next=l;
        l->next=p;
        l->value=symbol;
        return 0;
        }
    else
        {
        cout<<"\nMemory is over"<<endl<<endl;
        return 1;
        }
}

void delete_last(stack *head)
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
        cout<<"\nElements missing\n"<<endl<<endl;
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





