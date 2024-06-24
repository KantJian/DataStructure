#include<iostream>
using namespace std;
//线性表的顺序存储
#define InitSize 10 //默认表的内存
typedef int ElemType; 
struct List
{
	ElemType* data;
	int	MaxSize;
	int length;//线性表的当前长度
};
//初始化表
void InitList(List &L) {
	L.data=new ElemType[InitSize];//开辟一块儿内存空间
	L.length = 0;//初始化表长
	L.MaxSize = InitSize;//表内存大小
	cout << "初始化顺序表内存空间:" << L.MaxSize << endl;
}
//增加顺序表内存空间
void IncreaseSize(List& L, int addlength) {
	int* p = L.data;//定义指针指向原表起点
	L.data = new ElemType[InitSize + addlength];//开辟一段更长的内存空间
	//将原表数据存入新表
	for (int i = 0; i < L.MaxSize; i++) {
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + addlength;
	delete(p);//销毁旧表释放内存空间
	cout << "增加后的内存大小：" << L.MaxSize << endl;
}
//线性表顺序存储插入元素
bool ListInsert(List& L,int i,ElemType e) {//第i个位置插入元素e
	if (i > L.length+1 || i < 1) {
		return false;
	}
	if (L.length >= L.MaxSize) {
		return false;
	}
	//将插入元素位置后的元素都往后移一位
	for (int j = L.length; j >= i;j--) {
		L.data[j] = L.data[j-1]; 
	}
	L.data[i - 1] = e;
	L.length++;//表长+1
	return true;
}
//线性表顺序存储删除元素
bool ListDelete(List& L,int i,int &e) {
	if (i<1||i>L.length+1) {
		return false;
	}
	if (L.length == 0) {
		return false;
	}
	e = L.data[i - 1];//将指定位置的元素传给e带出来
	//删除元素位置之后的元素向前覆盖一位
	for (int j = i; j <= L.length;j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}
//线性表顺序存储查找元素
//---按位置查找元素
ElemType ListFind_Position(List &L,int i) {
	cout << L.data[i - 1] << endl;
	return L.data[i - 1];
}
//---按值查找元素
ElemType LisFind_Value(List &L,int e) {
	for (int j = 0; j <= L.length;j++) {
		if (L.data[j] == e) {
			cout << "第几个？：" << j + 1 << "个" << endl;
			return j + 1;
		}
	}
	return 0;
}
//主函数
int main() {
	List SeqList;//生成一个结构体
	InitList(SeqList);//初始化
	IncreaseSize(SeqList, 1);//增加内存空间
	//输出顺序表元素
	ListInsert(SeqList, 1, 333);
	ListInsert(SeqList, 2, 666);
	ListInsert(SeqList, 3, 999);
	int e;
	ListDelete(SeqList, 1,e);
	for (int i = 0; i < SeqList.length;i++) {
		cout<<"输出顺序表元素："<< SeqList.data[i]<<endl;
	}
	ListFind_Position(SeqList,3);
	LisFind_Value(SeqList, 666);
	return 0;
}