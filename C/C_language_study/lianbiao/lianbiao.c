#include<stdio.h>
#include<stdlib.h>

//定义结构体作为链表的结点
typedef struct node {
	int data;                                          //存储的数据：data
	struct node * next;                                 //链表指向下个结点的地址
} 
Node;

//初始化链表：
//在链表的创建时，首先要创建链表的头结点
Node * IntList() {
	Node * head = (Node * )malloc(sizeof(Node));    //首先用malloc函数取内存
	head->next = NULL;                              //把head（头结点）指向的下个结点设为NULL
	return head;                                    //返回head结点
}

//插入链表：从后插入
void CreatTail(Node *head) {
	Node * r, * newNode;                            //定义临时结点r，定义新结点newNode
	r = head;                                       //先将结点r定义为头结点
	int data;                   
	scanf("%d", &data);                             //存入数据
	while (data != -1) {
		newNode = (Node * )malloc(sizeof(Node));    //新结点用malloc函数取内存
		newNode->data = data;                       //将新结点的data设置为data
		newNode->next = r->next;                    //将新结点的下一个结点设置为临时结点r的下一个结点（就是尾巴接上后面的）
		r->next = newNode;                          //将结点r的下一个结点设置为newNode
		r = newNode;                                //再将r设置为newNode
		scanf("%d", &data);                         //循环，一直存
	}
	r->next = NULL;                                 //最后，将结点r的下一个结点设为Null
}
//插入链表：从前插入
void CreatHead(Node *head) {
	Node *newNode;                                  //定义新结点newNode
	int data;
	scanf("%d", &data);                             //存入数据
	while (data != -1) {
		newNode = (Node*)malloc(sizeof(Node));      //给新结点用malloc函数取内存
		newNode->data = data;                       //将新结点的data设置为data
		newNode->next = head->next;                 //将新结点的下一个结点设置为head后面的结点
		head->next = newNode;                       //head的下一个结点设为新结点
		scanf("%d", &data);                         //循环
	}
}

//链表的输出
void print(Node *head) {
	Node *p;                                        //定义指向链表的指针
	p = head->next;                                 //将指针指向head的下一个
	while (p) {                                     //不到最后一个（NULL），会一直循环
		printf(" %d\t ", p->data);                  //打印出来
		p = p->next;                                //往下指
	}
}

//链表的查找
Node* FindNode(Node *head, int x) {                 //输入的x表示要查询的结点位置
	Node *p = head;                                 //定义指向链表的指针，并指向head
	while (p && x >= 1) {                           //当p没到最后一个（NULL），并且查询的x要大于1
		p = p->next;                                //把p指向下一个
		x--;                                        //
	}
	if (!p) {                                       //判定：    找到值后p为真，！真变成假，不执行   没找到p为假，！假为真。执行
		printf("该节点不存在");
		return NULL;
	}
	else {
		return p;
	}
}

//在指定的位置插入链表
void Insert(Node *head, int x, int data) {

	Node *pre = FindNode(head, x - 1);              //调用查找
	if (pre == NULL) {
		printf("请输入正确的插入点");
	}
	Node *pNew = (Node *)malloc(sizeof(Node));      //给查找到的结点位置腾出空间
	pNew->data = data;                              
	pNew->next = pre->next;                         //开始插入
	pre->next = pNew;
}

//删除指定位置的结点
void Delete(Node *head, int x) {
    x--;
	Node *pre = FindNode(head, x);                  //先调用查找
	pre->next = pre->next->next;                    //链接下一个结点
}

int main()
{
    Node * test=IntList();          //创建链表head
    CreatHead(test);                //从head开始插入
    print(test);                
    printf("\n");
    Insert(test,3,10);              //从第三个开始插入10
    printf("\n");
    print(test);                
    Delete(test,3);                 //删除第三个
    printf("\n\n");
    print(test);

}