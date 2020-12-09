#define MaxSize 50
typedef char ElemType;
typedef struct Stack
{
    ElemType data[MaxSize];
    int top;
} Stack;


void initStack(Stack * & stack);
bool isEmpty(Stack * & stack);
bool upOverflow(Stack * & stack);
bool downOverflow(Stack * & stack);
void destroyStack(Stack * & stack);
bool push(Stack * & stack,ElemType e);
bool pop(Stack * & stack,ElemType e);
bool getTop(Stack * & stack,ElemType e);
void printStack(Stack *&s);