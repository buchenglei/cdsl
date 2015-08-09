/*
 * 将后缀式转换成二叉树的结构
 * 编译命令：
 * gcc binary_tree.c -std=c99
 */
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的数据类型
typedef char ElementType;
typedef struct TreeNode* PtrToNode;
typedef PtrToNode Tree;

// 二叉树基本结构
struct TreeNode {
	ElementType Element;
	Tree Left;
	Tree Right;
};

#define LEN 5

// 定义表达式: 
// 中缀式  5-6+9
// 后缀式  56-9+
char Expr[LEN] = {'5','6','-','9','+'};

// 保存二叉树结点的栈
Tree NodeStack[LEN];

// 创建一个新的节点并返回
PtrToNode CreateNewNode(char c)
{
	PtrToNode node = (PtrToNode)malloc((sizeof(struct TreeNode)));
	node->Element = c;
	node->Left = NULL;
	node->Right = NULL;
	return node;
}

int PushStack(PtrToNode node)
{
	// 当栈顶不为空时，则栈满
	if(NodeStack[LEN - 1] != NULL)
		return 0;
	// 从栈底开始寻找一个空的节点，并将新的节点入栈
	for(int i = 0; i < LEN; i++)
		if(NodeStack[i] == NULL)
		{
			NodeStack[i] = node;
			break;
		}

	return 1;

}

// 将栈顶的节点返回并从栈中删除
// 并不需要释放被返回节点的
PtrToNode PopStack()
{
	// 栈为空时，返回空
	if(NodeStack[0] == NULL)
		return NULL;

	// 从栈顶开始，向下知道遇到一个不为空的节点
	for(int i = LEN - 1; i >= 0; i--)
		if(NodeStack[i] != NULL)
		{
			PtrToNode tmp;
			tmp = NodeStack[i];
			NodeStack[i] = NULL;
			return tmp;
		}
}

// 后序遍历二叉树，依次将每一个节点输出为后缀式
void PrintBinaryTree(PtrToNode root)
{
	if(root->Left != NULL)
		PrintBinaryTree(root->Left);

	if(root->Right != NULL)
		PrintBinaryTree(root->Right);

	printf("%c", root->Element);
}

void main() 
{
	// 初始化节点栈
	for(int i = 0; i < LEN; i++)
		NodeStack[i] = NULL;

	for(int i = 0; i < LEN; i++)
	{
		// 如果遇到的是数字
		// 不能使用Expr[i] != '-' || Expr[i] != '+'来识别除了-+以外的字符
		// 因为当字符为 '-' 时，前一条规则不满足但后一条满足，所以整个表达式还是返回true
		// '+'同上
		if(Expr[i] == '-' || Expr[i] == '+')
		{
			// 以下则是处理 + - 的情况
			// 创建一个符号节点
			PtrToNode newnode = CreateNewNode(Expr[i]);
			newnode->Right = PopStack();
			newnode->Left = PopStack();
			PushStack(newnode);
		}
		else
			// 将非运算符的的字符入栈
			PushStack(CreateNewNode(Expr[i]));


	}

	// 输出结果
	// 使用后序遍历，遍历二叉树
	PrintBinaryTree(NodeStack[0]);
}
