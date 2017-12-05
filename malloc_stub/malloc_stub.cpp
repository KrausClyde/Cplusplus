// malloc_stub.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <malloc.h>
#include <stdlib.h>
#include <string> 
#include <iostream>

#include<vector>
#include<stack>

#include "BinTree.h"

using namespace std;

class sample2
{
public:
	sample2(int xx, int zz)
	{
		x = xx;
		z = zz;
	}
	void disp()
	{
		cout << x << y << z << endl;
	}
	static void f1()
	{
		cout <<  y  << endl;
	}
	~sample2()
	{
		cout << "destructing object" << endl;
	}

protected:
	int x;
	const static int y = 100;
	int z;
};

template <class T>
class Stack{
public:
	Stack(int size = 50);
	~Stack();  
	void push(T* data);  
	T* pop();  
	bool isEmpty();  
	T* peek();  
private:  
	int size;  
	int top;  
	bool isFull();  
	T **data;  
};  

template <class T>  
Stack<T>::Stack(int size){  
	if(size <= 0){  
		cout << "分配的内存太小了" << endl;   
	}  

	data = new T*[size];  
	top = -1;  
	this->size = size;   
}

template <class T>
Stack<T>::~Stack(){
	delete[]data;
}

template <class T>
void Stack<T>::push(T* data){
	++top;
	if (isFull()){
		cout << "貌似栈满了耶" << endl;
		exit(1);
	}
	this->data[top] = data;
}

template <class T>
T* Stack<T>::pop(){
	if (isEmpty()){
		cout << "栈为空，不可以再出元素了!" << endl;
		exit(1);
	}

	return data[top--];
}

template <class T>
T* Stack<T>::peek(){
	if (isEmpty()){
		cout << "栈为空" << endl;
		exit(1);
	}

	return data[top];
}

template <class T>
bool Stack<T>::isFull(){
	if (top == size){
		return true;
	}

	return false;
}

template <class T>
bool Stack<T>::isEmpty(){
	if (top < 0){
		return true;
	}

	return false;
}
///////////////////////////////////////////////////////////////////////  
//tree  
template <class T>
class BTree{
public:
	BTree *left;
	BTree *right;
	T data;

	BTree() : left(NULL), right(NULL), data(NULL){};
	~BTree(){};
};

///////////////////////////////////////////////////////////////////////  
template <class T>
void PreOrder(BTree<T> *root){
	if (root != NULL){
		Stack<BTree<T> > stack;
		BTree<T> *ptr = root;
		BTree<T> *temp;
		stack.push(ptr);
		while (!stack.isEmpty()) {
			temp = stack.pop();
			cout << temp->data << " ";
			if (temp->right != NULL){
				stack.push(temp->right);
			}

			if (temp->left != NULL){
				stack.push(temp->left);
			}
		}
		cout << endl;
	}
}

///////////////////////////////////////////////////////////////////////  
template <class T>
void InOrder(BTree<T> *root){
	if (root != NULL){
		Stack<BTree<T> > stack;
		BTree<T> *ptr = root;
		while (!stack.isEmpty() || ptr != NULL){
			while (ptr != NULL){
				stack.push(ptr);
				ptr = ptr->left;
			}

			if (!stack.isEmpty()){
				ptr = stack.pop();
				cout << ptr->data << " ";
				ptr = ptr->right;
			}

		}
		cout << endl;
	}
}

///////////////////////////////////////////////////////////////////////  
template <class T>
void PostOrder(BTree<T> *root){
	if (root != NULL){
		Stack<BTree<T> > stack;
		BTree<T> *ptr = root;
		BTree<T> *temp;
		bool flags;

		do{
			while (ptr != NULL){
				stack.push(ptr);
				ptr = ptr->left;
			}

			temp = NULL;
			flags = true;

			while (flags && !stack.isEmpty()){
				ptr = stack.peek();
				if (ptr->right == temp){
					cout << ptr->data << " ";
					stack.pop();
					temp = ptr;
				}
				else{
					ptr = ptr->right;
					flags = false;
				}
			}
		} while (!stack.isEmpty());
		cout << endl;
	}
}

template <class T>
void PostOrder2(BTree<T> *root){
	if (root != NULL){
		Stack<BTree<T> > stack;
		BTree<T> *ptr = root;
		BTree<T> *temp;
		bool flags;

		do{
			while (ptr != NULL){
				stack.push(ptr);
				if (ptr->right != NULL)
					stack.push(ptr->right);
				if (ptr->left != NULL)
					stack.push(ptr->left);
				ptr = ptr->left;
			}

			temp = NULL;
			flags = true;

			while (flags && !stack.isEmpty()){
				ptr = stack.peek();
				if (ptr->right == temp){
					cout << ptr->data << " ";
					stack.pop();
					temp = ptr;
				}
				else{
					ptr = ptr->right;
					flags = false;
				}
			}
		} while (!stack.isEmpty());
		cout << endl;
	}
}
///////////////////////////////////////////////////////////////////////  
template <class T>
void PreOrder1(BTree<T> * root){
	if (root != NULL){
		cout << root->data << " ";
		PreOrder1(root->left);
		PreOrder1(root->right);
	}
}

///////////////////////////////////////////////////////////////////////  
template <class T>
void InOrder1(BTree<T> * root){
	if (root != NULL){
		InOrder1(root->left);
		cout << root->data << " ";
		InOrder1(root->right);
	}
}

///////////////////////////////////////////////////////////////////////  
template <class T>
void PostOrder1(BTree<T> * root){
	if (root != NULL){
		PostOrder1(root->left);
		PostOrder1(root->right);
		cout << root->data << " ";
	}
}



extern int PreOrder_NonRecursive(BinTree root);
extern int PostOrder_NonRecursive(BinTree root);



int sum = 0;
int Fibonacci(int n);

extern int textFileRead();
extern int excelFileRead();
extern int quicksort(int arry[], int size, int low, int high);
int _tmain(int argc, _TCHAR* argv[])
{
#if 0
	vector<int> ivec(10,1);

	ivec[5] = 5;
	ivec[6] = 6;
	vector<int>::iterator mid1 = ivec.begin() + ivec.size() / 2;
//	vector<int>::iterator mid2 = (ivec.begin() + ivec.end() )/2;
	cout << "mid1 " /*<< mid1 << */"*mid1 = " << *mid1 << endl;
//	cout << "mid2 " << mid2 << "*mid2 = " << *mid2 << endl;
	ivec.push_back(11);

	for (int index = 0; index < ivec.size(); index++)
		cout << "  ivec[" << index << " ] "<< ivec[index] <<endl;
	    cout<<endl;
		cout << "ivec.end() - ivec.begin() = " << ivec.end() - ivec.begin() << endl;
	vector<int>::iterator iter = ivec.begin();
	for (;iter != ivec.end(); ++iter)
		*iter = 0;
	cout << "iter - ivec.begin() = " << iter - ivec.begin() << endl;
	for (int index = 0; index < ivec.size(); index++)
		cout << ivec[index] << endl;
#endif
	sample2 sam(3, 5);
	sam.disp();
	sam.f1();

	textFileRead();
	excelFileRead();

#if 0
	BTree<int> *root = new BTree<int>;
	BTree<int> *A, *B, *C, *D, *E;
	A = new BTree<int>;
	B = new BTree<int>;
	C = new BTree<int>;
	D = new BTree<int>;
	E = new BTree<int>;

	A->data = 5;
	B->data = 6;
	C->data = 4;
	D->data = 2;
	E->data = 7;

	root = A;
	A->left = B;
	A->right = E;
	B->left = C;
	B->right = D;

	cout << "非递归: " << endl;
	PreOrder(root);
	InOrder(root);
	PostOrder(root);

	cout << "递归: " << endl;
	PreOrder1(root);
	cout << endl;
	InOrder1(root);
	cout << endl;
	PostOrder1(root);
	cout << endl;
	system("pause");
#endif

#if 0
	BinNode *root = new BinNode;
	BinNode *A, *B, *C, *D, *E;
	A = new BinNode;
	B = new BinNode;
	C = new BinNode;
	D = new BinNode;
	E = new BinNode;
	A->data = 5;
	B->data = 6;
	C->data = 4;
	D->data = 2;
	E->data = 7;

	root = A;
	A->lchild = B;
	A->rchild = E;
	B->lchild = C;
	B->rchild = D;
	C->lchild = NULL;
	C->rchild = NULL;
	D->lchild = NULL;
	D->rchild = NULL;
	E->lchild = NULL;
	E->rchild = NULL;

	BinNode *G, *H, *I;
	G = new BinNode;
	H = new BinNode;
	I = new BinNode;
	G->data = 1;
	H->data = 3;
	I->data = 8;
	D->lchild = G;
	D->rchild = H;
	G->lchild = NULL;
	G->rchild = I;
	H->lchild = NULL;
	H->rchild = NULL;
	I->lchild = NULL;
	I->rchild = NULL;

	PreOrder_NonRecursive(A);
	cout << endl;
	PostOrder_NonRecursive(A);

	MGraph g;
	for (int i = 0; i < VertexNum; i++)
		g.vertex[i] = i + 65;
	for (int i = 0; i < VertexNum; i++)
	{
		for (int j = 0; j < VertexNum; j++)
			g.edges[i][j] = 999;
		g.edges[i][i] = 0;
	}
	g.edges[0][1] = 5;
	g.edges[0][3] = 7;
	g.edges[1][2] = 4;
	g.edges[1][3] = 2;
	g.edges[2][0] = 3;
	g.edges[2][1] = 3;
	g.edges[2][3] = 2;
	g.edges[3][2] = 1;
	Floyd(g);

	Fibonacci(5);
#endif

	int a[] = { 57, 68, 59, 52, 72, 28, 96, 33, 24 };
	quicksort(a, sizeof(a) / sizeof(a[0]), 0, sizeof(a) / sizeof(a[0]) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << " ";
	}
	system("pause");

	return 0;
}


int Fibonacci(int n)
{
	printf("Fibonacci called %d\n", n);
	if (n < 0)
		return 0;
	if (n == 0 || n == 1)
		return 1;
	 sum += Fibonacci(n - 1);
	 printf("call n-1 %d\n",n);
	 sum += Fibonacci(n - 2);
	 printf("call n-2 %d\n", n);
	 return sum;
}