#include <iostream>
using namespace std;

typedef int ElementType;

struct Cell{
    ElementType element;
    struct Cell *next;
};

typedef struct Celltag{
    ElementType element;
    struct CellTag *next;
}Cell;

typedef Cell *Position;
typedef Position List;

Position first(List *pL){
    return (*pL);
}
Position next(Position p,List *pL){
    return p->next;
}
Position end(List *pL){
    Position p = *pL;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}

int main(){

    return 0;
}