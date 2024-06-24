#include<iostream>
using namespace std;
//单链表创建
typedef int ElemType;
typedef struct LNode LNode;//重命名结构体数据类型
typedef struct LNode* LinkList;//表示一个指向 LNode 结构体的指针。
//定义结构体表示节点
struct LNode
{
	ElemType data;
	LNode* next;
};
//初始化一个不带头指针的单链表
bool InitLinkList_NoHead(LinkList &L) {
	L = NULL;
	printf("初始化不带头指针单链表成功\n");
	return true;
}
//初始化带头指针的单链表
bool InitLinkList_Head(LinkList& L) {
	L = new LNode;//为头节点分配内存
	if (L == NULL) {//如果分配失败
		return false;
	}
	L->next = NULL;
	printf("初始化带头指针单链表成功");
	return true;
}
//单链表的几种插入方式
//带头结点 在第i个节点插入元素e(尾插法）
bool LinkList_Insert_One(LinkList& L, int i, ElemType e) {
	if (i < 1) {//插入位置在头结点之后
		return false;
	}
	LNode* p = L;//创建指针p指向头结点
	int j = 0;
	while (p != NULL && j < i-1) {//当P指向的不是空地址 第i个元素存在 j表示指针P指向第几个结点 要<第i个结点
		p = p->next;
		j++;
	}
	if (p==NULL){
		return false;
	}
	LNode* s = new LNode;//创建新结点
	s->data = e;//将传入的值赋值给新结点的数据域
	s->next = p->next;//将新结点的指针域指向当前结点的下一结点
	p ->next = s;//当前结点的指针域指向新结点
	return true;
}
//头插法
bool LinkList_Insert_Two(LinkList& L, int i, ElemType e) {
	if (i < 1) return false;//插入位置在头结点之后
	LNode* p = L->next;//创建指针P指向头结点后的
	int j = 0;
	while (p != NULL && j < i-1) {
		p = p->next;
		j++;
	}
	if (p == NULL) return false;
	LNode* s = new LNode;
	s->data = p->data;//将当前结点的数据赋给新结点
	p->data = e;//将插入数据赋值给当前结点
	s->next = p->next;//新结点指针域指向当前结点的下一结点
	p->next = s;//当前结点的下一结点指向新结点
	return true;
}
//单链表的删除操作
//按位删除元素 删除表L中第i个位置的元素，并用e返回删除元素的值。
bool DeleteList_Position(LinkList &L, int i,int &e) {
	cout << "按位置删除的方法，将要删除第" << i << "个元素" << endl;
	if (i < 1) return false;
	LNode* t = L;
	int j = 0;
	while (t != NULL && j < i-1 ) {
		t = t->next;
		j++;
	}
	if (t == NULL) return false;//避免异常
	if (t->next == NULL) return false;//避免异常
	LNode* d = t->next;//创建结点指向删除结点位置
	e = d->data;// 删除的值传出
	cout << "删除的值为" << e << endl;
	t->next = d->next;
	free(d);
	return true;
}
//按值删除元素
bool DeleteList_Value(LinkList& L, int e) {
	cout << "按值删除的方法，将要删除数据域为" << e << "的元素" << endl;
	LNode* temp = L;
	LNode* prev = nullptr;
	while (temp != NULL && temp->data != e) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) return false; // 未找到目标值
	if (temp == L) { // 如果要删除的是头节点
		L = L->next;
		delete temp;
	}
	else {
		prev->next = temp->next;
		delete temp;
	}
	return true;
}
// 打印链表
void PrintList(LinkList L) {
	LNode* p = L->next; // 跳过头结点
	if (p == NULL) {
		cout << "链表为空" << endl;
	}
	else {
		cout << "链表中的数据为: ";
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}
//主函数 
int main() {
	LinkList List;
	//InitLinkList_NoHead(List);
	InitLinkList_Head(List);
	LinkList_Insert_One(List, 1, 111);
	LinkList_Insert_One(List, 2, 222);
	LinkList_Insert_One(List, 3, 333);
	LinkList_Insert_One(List, 4, 444);
	LinkList_Insert_One(List, 5, 555);
	LinkList_Insert_Two(List, 3, 686);
	LinkList_Insert_Two(List, 6, 999);
	LinkList_Insert_One(List, 7, 666);
	int e;
	DeleteList_Position(List,3,e);
	DeleteList_Value(List,222);
	DeleteList_Value(List, 111);
	PrintList(List);
	return 0;
}