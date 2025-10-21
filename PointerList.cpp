#include <iostream>
using namespace std;

typedef int ElementType;

struct Cell{
    ElementType element;
    struct Cell *next;
};

typedef Cell *Position;
typedef Position List;

Position next(Position p,List *pL){
    return p->next;
}
Position first(List *pL){
    return (*pL);
}

Position end(List *pL){
    Position p = *pL;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}

Position makeNull(List *pL){
    (*pL) = new Cell;
    (*pL)->next = NULL;
    (*pL)->element = 0;
    return (*pL);
}

ElementType retrieve(List *pL, Position p){
    //if(p->next == NULL) return;
    return p->next->element;
}

Position locate(ElementType x, List *pL){
    Position p = *pL;
    while(p->next != NULL){
        if(p->next->element == x){
            break;
        }
        p = p->next;
    }
    return p ;
}


void insert(ElementType x, List *pL , Position p){
    Position temp =  p->next;
    p->next = new Cell;
    p->next->element = x;
    p->next->next = temp;
}

void Delete(Position p , List *pL){
    Position temp = p->next;
    p->next = temp->next;
    free(temp);
}

void printList(List *pL){
    Position p = *pL;
    while(p->next != NULL){
        cout << p->next->element << " ";
        p = p->next;
    }
}
int main(){
    List L;
    makeNull(&L);
    insert(10,&L,first(&L));
    insert(20,&L,end(&L));
    insert(30,&L,end(&L));
    printList(&L);
    cout << endl;
    Position p = locate(20,&L);
    cout << "Test retrieve: " ;
    cout << retrieve(&L,p) << endl;
    Delete(p,&L);
    printList(&L); 
    cout << endl;
    p = locate(10,&L); 
    p = p->next;
    insert(101025,&L,p); 
    printList(&L);
    cout << endl;
    return 0;
}