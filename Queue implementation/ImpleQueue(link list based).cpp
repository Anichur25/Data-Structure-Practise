#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{

  private:
    int queue_size;

    struct node
    {
        T data;
        node *next;
    };

    node* enqueue;
    node* dequeue;

  public:
    Queue()
    {
        enqueue = NULL;
        dequeue = NULL;
        queue_size = 0;
    }

    void Push(T data);
    void Pop(void);
    int Size(void);
    T Front(void);
};

template<class T> void Queue<T> :: Push(T data){

    node *newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    ++queue_size;

    if (dequeue == NULL)
    {
      dequeue = newNode;
    }
    if (enqueue == NULL)
    {
      enqueue = newNode;
    }
    else
    {
      enqueue->next = newNode;
      enqueue = newNode;
    }
}

template<class T> void Queue<T> :: Pop(){

    if (dequeue == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        node *delptr = dequeue;
        dequeue = dequeue->next;
        --queue_size;
        delete delptr;
    }

    if (dequeue == NULL)
    {
        enqueue = dequeue;
    }
}

template<class T> T Queue<T> :: Front(){

   if(dequeue != NULL){

        return dequeue -> data;
   }
}

template<class T> int Queue<T> :: Size(){
  return queue_size;
}

int main(){

  Queue<pair<int,int> > Q;
  Q.Push(make_pair(3,4));
  Q.Pop();
  Q.Push(make_pair(8,6));
  Q.Push(make_pair(6,7));
  Q.Push(make_pair(10,4));
  Q.Pop();
  cout << Q.Front().second<< endl;
  return 0;
}

