//linked list wq
#include<iostream>
using namespace std;

template<typename T>
class List
{
    public:
     List(){
        size =0;
        head = nullptr;   
    }
    private:       //Node


    template<typename U>
    class Node{
        public:
            T data;
            Node* next;
            Node(T data = T(), Node* pnext =nullptr){
                this->data = data;
                this->next =pnext;
            }
    };
Node<T>* head;
int size;
public:
//________________functions
 void push_back(T data){
     
     if (head == nullptr) {
        head = new Node<T>(data);
     }
     else{
         Node<T>* curr = this->head;
         while(curr->next != nullptr){
               curr = curr->next; 
         }
         curr->next = new Node<T>(data);

     }
     size++;
     
}


 int get_size(){return size;}


 T& operator[](int index){
     int count =0 ;
     Node<T>* curr = this->head;
 
    while(curr!=nullptr){
        if(count ==index){
            return curr->data;
        }
        curr = curr->next;
        ++count;
     }
 }


 bool pop_back(){
     if(size>0){
     Node<T>* curr = head;
     int cnt = 0;
     while(cnt!=(size-2)){
         curr =curr->next;
         ++cnt;
     }
     delete curr->next;
     curr->next = nullptr;
    --size;
    return true;
    }
    else return false;
 }

bool pop_front(){
    if(size>0){
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    --size;
    return true;}
    else return false;
}


bool empty(){
    if(size == 0){
        return true;
    }
    else{
        return false;

    }
}


void insert(int index, T data){
    int cnt = 0;
    Node<T>* curr = head;
    while(cnt!=index-1){
        curr = curr->next;
        ++cnt;
    }
    Node<T>* temp2 = curr->next;
    Node<T>* temp  = new Node<T>(data);
    curr->next = temp;
    temp->next = temp2;
    ++size;
}
 void push_front(T data){
     Node<T>* curr = new Node<T>(data);
     curr->next = head;
     head = curr;
     ++size;
 }
};





int main(){
    List<int> l;
    
    for(size_t i = 0; i <10; i++)
    {
        l.push_back(5*(i+3)+4);
    }
    for(size_t i = 0; i < l.get_size(); i++)
    {
        cout<<l[i]<<endl;

    }
    
    cout<<"pop_back--"<<l.pop_back()<<l.empty()<<endl;
    cout<<"pop_front-----"<<l.pop_front()<<endl;
    cout<<"insert ind5_val 12----"<<endl;
    l.insert(5,15);
    cout<<"push_front----20"<<endl;
    l.push_front(20);
    for(size_t i = 0; i < l.get_size(); i++)
    {
        cout<<l[i]<<endl;

    }
    return 0;
}
