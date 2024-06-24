#include <iostream>
using namespace std;
//栈的顺序存储
#define MAXSIZE 10
typedef int SElemType;
typedef struct SqStack SqStack;
//定义栈的结构体
struct SqStack {
	SElemType data[MAXSIZE];
	int top;
};
//初始化栈
void InitSqStack(SqStack& S) {
	S.top = -1;
}
//判断栈是否为空
bool SqStackIsNull(SqStack & S) {
	if (S.top == -1) {
		return true;
	}
	else
	{
		return false;
	}
}
//顺序存储------入栈操作
bool Push(SqStack& S, SElemType e) {
	if (S.top == MAXSIZE - 1) {//栈满
		return false;
	}
	S.top = S.top + 1;
	S.data[S.top] = e;
	return true;
}
//顺序存储------出栈操作
bool Pop(SqStack& S,SElemType &e) {
	if (S.top == -1) {//已空栈
		return false;
	}
	e=S.data[S.top];
	S.top = S.top - 1;
	return	true;
}
void PrintSqStack(SqStack& S) {
	if (SqStackIsNull(S)) {
		cout << "栈为空" << endl;
		return;
	}
	cout << "栈中的元素为"<<endl;
	for (int i = 0; i <= S.top;++i) {
		cout << S.data[i] << endl;
	}
}
//主函数
int main() {
    SqStack S;
    InitSqStack(S);
	Push(S, 111);
	Push(S, 222);
	Push(S, 333);
	Push(S, 444);
	Push(S, 555);
    if (SqStackIsNull(S)){
        printf("该栈为空");
    }
    else {
        printf("该栈不为空");
    }
	SElemType e;
	Pop(S,e);
	PrintSqStack(S);
    return 0;
}