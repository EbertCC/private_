#include <iostream>

using namespace std;


class nodo{

    public:
    int valor;
    nodo *next;
    nodo(int v,nodo* n=nullptr){
        valor = v;
        next = n;
    }
};

class LE{

    nodo *head = nullptr;

    public:

    void print();
    bool find(int v,nodo *&pos);
    void add(int v);
    void del(int v);

    //void merge(nodo *&A,nodo *&B);
    LE merge( LE& lista1, LE& lista2);

    ~LE();
};

void LE::print(){
    for(nodo* p=head; p ; p = p -> next){
        cout<< p-> valor << " -> ";
    }
    cout<<"NULL"<<endl;
}


bool LE::find(int v,nodo *&pos){

    bool encontrado = false;
    pos = nullptr;

    for(nodo *p = head;  p && p-> valor <= v ; p = p -> next){
        if(p -> valor == v){
            encontrado = true;
            break;
        }
        pos = p;
    }
    return encontrado;
}

void LE::add(int v){

    nodo * pos_ant;

    if(!find(v,pos_ant)){

        if(pos_ant){
            pos_ant -> next = new nodo (v,pos_ant -> next);
        }else{
            head = new nodo(v,head);
        }
    }
}

void LE::del(int v){
    nodo *pos_ant,*pos_del;

    if(find(v,pos_ant)){

        if(pos_ant){
            pos_del = pos_ant -> next;
            pos_ant -> next = pos_del -> next;

            delete pos_del;
        }
        else{
            pos_del = head;
            head = pos_del -> next;
            delete pos_del;
        }
    }
}



LE LE::merge( LE& lista1, LE& lista2){
    LE mergelista;
    nodo *p = lista1.head;
    nodo *q = lista2.head;


    while(p && q ){
        if(p->valor < q->valor){
            mergelista.add(p->valor);
            p = p -> next;
        }else{
            mergelista.add(q->valor);
            q = q -> next;
        }

    }

    while(p){
        mergelista.add(p->valor);
        p = p -> next;
    }
    while(q){
        mergelista.add(q->valor);
        q = q -> next;
    }
    return mergelista;
}


LE::~LE(){
    while (head){
        del(head->valor);
    }
}




int main(){

    LE list1;
    LE list2;

    list1.add(3);
    list1.add(5);
    list1.add(18);
    list1.add(21);

    list2.add(15);
    list2.add(17);
    list2.add(23);

    list1.print();
    list2.print();    

    LE mergelista1 = mergelista1.merge(list1,list2);
    mergelista1.print();
    return 0;
}