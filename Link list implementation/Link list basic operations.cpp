#include <bits/stdc++.h>
using namespace std;

template <class T>
class LinkList
{

  private:
    struct node
    {

        T data;
        node *next;
    };

    node *head, *tail;
    int ListSize;

  public:
    LinkList()
    {
        head = NULL;
        tail = NULL;
        ListSize = 0;
    }

    void InsertAtBegin(T data);
    void InsertAtEnd(T data);
    void InsertAnyPosition(int position, T data);
    void ShowTotalList();
    T ShowAnyPositionValue(int position);
    void DeleteAtBegin();
    void DeleteAtEnd();
    void DeleteAtAnyPosition(int position);
    int getListSize();
};

template <class T>
void LinkList<T>::InsertAtBegin(T data)
{

    node *temp = new node();

    if (head == NULL)
    {
        temp->data = data;
        temp->next = NULL;
        head = tail = temp;
    }
    else
    {
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    ListSize++;
}

template <class T>
void LinkList<T>::ShowTotalList()
{

    node *temp = head;

    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }

    cout << endl;
}

template <class T>
void LinkList<T>::InsertAtEnd(T data)
{

    node *newNode = new node();

    if (tail == NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        head = tail = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    ListSize++;
}

template <class T>
void LinkList<T>::InsertAnyPosition(int position, T data)
{

    node *visitor = head;
    node *newNode = new node();
    newNode->data = data;

    if (position == 1)
    {

        newNode->next = head;
        head = newNode;
        ListSize++;
        return;
    }

    for (int i = 1; i < position - 1; i++)
    {

        visitor = visitor->next;
    }

    newNode->next = visitor->next;
    visitor->next = newNode;
    ListSize++;
}

template <class T>
T LinkList<T>::ShowAnyPositionValue(int position)
{

    try
    {
        node *Search = head;

        if (position == 1)
            return head->data;
        else
        {
            for (int i = 1; i < position - 1; i++)
            {
                Search = Search->next;
            }

            return Search->next->data;
        }
    }
    catch (exception e)
    {
        cout << "List is empty";
    }
}

template <class T>
void LinkList<T>::DeleteAtBegin()
{

    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        node *delptr = head;
        if (delptr->next == NULL)
        {
            head = NULL;
            tail = NULL;
            delete delptr;
        }
        else
        {
            head = delptr->next;
            delete delptr;
        }
    }

    ListSize--;
}

template <class T>
void LinkList<T>::DeleteAtEnd()
{

    node *delptr = head;

    if (delptr == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (delptr->next == NULL)
    {

        head = tail = NULL;
        delete delptr;
        ListSize--;
        return;
    }
    else
    {
        for (int i = 1; i < ListSize - 1; i++)
        {
            delptr = delptr->next;
        }

        tail = delptr;
        tail->next = NULL;
        delete delptr->next;
        ListSize--;
    }
}

template <class T>
int LinkList<T>::getListSize()
{
    return ListSize;
}

template<class T>
void LinkList<T> :: DeleteAtAnyPosition(int position){

    if(position == 1){
        DeleteAtBegin();
        return;
    }
    else if(position == ListSize){
        DeleteAtEnd();
        return;
    }
    else
    {
        node* traptr = head;

        for(int i = 1; i < position -  1; i++){
            traptr = traptr -> next;
        }

        node* delptr = traptr -> next;
        traptr -> next = traptr -> next -> next;
        delete delptr;
    }
}


int main()
{

    LinkList<int> Mylist;

    Mylist.InsertAtEnd(6);
    Mylist.InsertAtBegin(7);
    Mylist.InsertAtEnd(10);
    Mylist.InsertAtBegin(11);
    Mylist.InsertAnyPosition(3, 67);
    Mylist.InsertAtEnd(89);
    Mylist.InsertAtBegin(88);
    Mylist.ShowTotalList();
    Mylist.DeleteAtBegin();
    Mylist.DeleteAtEnd();
    Mylist.ShowTotalList();
    Mylist.InsertAtEnd(100);
    Mylist.DeleteAtAnyPosition(4);
    Mylist.ShowTotalList();

    return 0;
}
