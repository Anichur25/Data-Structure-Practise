#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack
{

private:
  struct node
  {
    T data;
    node *next;
  };

  int Stacksize;

  public:
  T Top();
  int Size();
  void Pop();
  void Push(T data);
  bool isEmpty();

public:
  node *top;

  Stack()
  {
    Stacksize = 0;
    top = NULL;
  }
};

template <class T> T Stack<T> :: Top()
{
   if(!isEmpty())
   return top -> data;
   else exit(0);
}

template<class T> void Stack<T> :: Pop(){

   if(!isEmpty()){
    node* del = top;
    top = top -> next;
    --Stacksize;
    delete del;
   }
   else printf("Stack is Empty\n");
}

template<class T> void Stack<T> :: Push(T data){
   node* newNode = new node();
   newNode -> data = data;
   newNode -> next = top;
   top = newNode;
   ++Stacksize;
}
template<class T> int Stack<T> :: Size(){
  return Stacksize;
}

template<class T> bool Stack<T> :: isEmpty(){
  if(Stacksize > 0)
    return false;
  else return true;
}

int main(){
   Stack<int> S;
   S.Push(1233);
   S.Push(4664);
   S.Push(6776);
   S.Pop();
   cout << S.Size() << endl;
   cout << S.Top() << endl;
   S.Pop();
   cout << S.Size() << endl;
   return 0;
}
