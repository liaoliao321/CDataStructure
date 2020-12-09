
#define MaxSize 50
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} List;


void createList(List *&l, ElemType a[], int n);
void initList(List *&l);
void destroyList(List *&l);
bool isEmpty(List *&l);
int length(List *&l);
void printList(List *&l);
bool contains(List *&l, int i, ElemType &e);
int locateElem(List *l, ElemType e);
bool add(List *&l, int i, ElemType e);
bool remove(List *&l, int i, ElemType &e);