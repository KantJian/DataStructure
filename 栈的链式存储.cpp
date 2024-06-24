#include <iostream>
using namespace std;
//栈的链式存储
typedef int ElemType;
typedef struct ChainStack ChainStack;
//栈的链式存储结构
struct ChainStack {
	ElemType data;
	ChainStack* top;
};
//初始化
void InitChainStack(ChainStack*& S) {
	S = nullptr;
}
//判断栈是否为空
bool IsEmpty(ChainStack* S) {
	return S == nullptr;
}
//压栈
void Push(ChainStack*& S, ElemType e) {
	ChainStack* newNode = new ChainStack;
	newNode->data = e;
	newNode->top = S;
	S = newNode;
}
//出栈
bool Pop(ChainStack*&S,ElemType &e) {
	return !(IsEmpty(S) || (e = S->data, S = S->top, delete S, false));
}
//主函数
int main() {
	ChainStack* S;
	InitChainStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	ElemType e;
	if (Pop(S, e)) {
		cout << "Popped element: " << e << endl;
	}
	else {
		cout << "Failed to pop element, stack might be empty." << endl;
	}
	return 0;
}