#include<bits/stdc++.h>
using namespace std;

template<class dpType>
class Stack{

public:

  dpType Array[100];
  dpType Top(void);
  void Push(dpType val);
  void Pop(void);
  bool isEmpty(void);
  int top,top_idx;
  int Size();
  Stack(){top = -1;top_idx = -1;}
};

template<class dpType> dpType Stack<dpType> :: Top(){

    if(!isEmpty())
    return Array[top_idx];
}

template <class dpType> void Stack<dpType> :: Push(dpType value){
   Array[++top] = value;
   top_idx = top;
}

template<class dpType> void Stack<dpType> :: Pop(){

   if(!isEmpty()){
    --top;
    top_idx = top;
   }
   else printf("Stack is Empty\n");

}

template <class dpType> bool Stack<dpType> :: isEmpty(){
   return (top == -1);
}

template <class dpType> int Stack<dpType> :: Size(){
  return top_idx + 1;
}

int main(){

  Stack<string> S,P;
  S.Push("Bangladesh");
  S.Push("Brazil");
  S.Push("Argentina");
  S.Push("India");
  cout << P.Size() << endl;
  S.Pop();
  S.Pop();
  S.Pop();
  cout << S.Top() << endl;
  return 0;
}

