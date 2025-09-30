#include <iostream>
using namespace std ;

#define MAXLENGTH 100
typedef int ElementType;
typedef int Position;

struct List {
    ElementType elements[MAXLENGTH];
    Position last;
};
Position first(List *pL){
    return 1;
}
Position end(List *pL){
    return pL->last + 1;
}
Position next(Position p,List *pL){
    if( p < 1 || p > pL->last){
        return 0;
    }
    return p + 1;
}
Position makeNull(List *pL){
    pL->last = 0;
    return end(pL);
}
Position previous(Position p,List *pL){
    if(p < 2 || p > pL-> last)  return 0;
    return p-1;
}
ElementType *retrieve(Position p ,List *pL){
    return &(pL->elements[p-1]);
}
Position locate(ElementType x,List *pL){
    for(Position p = 1 ; p <= pL->last ; p++){
        if(pL->elements[p-1] == x){
            return p;
        }
    }
    return end(pL);
}
void printList(List *pL){
    for(int i = 0 ; i < pL->last; i++){
        cout << pL->elements[i] << " ";
    }
}
void insert(ElementType x, Position p , List *pL){
    if(p < 1 || p > pL->last + 1)   return;
    for(int i = pL->last ; i >= p ; i--){
        pL->elements[i] = pL->elements[i-1];
    }
    pL->elements[p-1] = x ;
    pL->last++;
}
void Delete(Position p , List *pL){
    if(p < 1 || p > pL->last)   return;
    for(int i = p ; i < pL->last ; i++){
        pL->elements[i-1] = pL->elements[i];
    }
    pL->last--;
}
int main(){
    List L;
    makeNull(&L);

    cout << "= Test insert =" << endl;
    insert(10,1,&L);
    insert(20,2,&L);
    insert(30,3,&L);
    insert(40,4,&L);
    printList(&L);
    cout << endl << "= Test Delete =" << endl;
    Delete(1,&L);
    printList(&L);
    cout << endl << "= Test Locate =" << endl;
    Position p = locate(30,&L);
    if(p != end(&L)){
        cout << "Find " << p ;
    }else   
        cout << "No";
    cout << endl << "= Test Retrieve =" << endl;
    ElementType *val = retrieve(2,&L);
    if(val)  
        cout << "In position 2 is " << *val << endl ;
    cout << "= Test next & previous =" << endl;
    cout << "next(1) = " << next(1, &L) << endl;       
    cout << "previous(3) = " << previous(3, &L) << endl; 


    return 0;
}