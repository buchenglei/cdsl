#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

void main()
{
	// 创建二叉搜索树的根节点
	SearchTree T;
	T = Insert(20, NULL);
	
	// 一系列的插入操作
	T = Insert(15, T);
	T = Insert(16, T);
	T = Insert(25, T);
	T = Insert(21, T);
	T = Insert(27, T);
	T = Insert(5, T);
	T = Insert(2, T);

	printf("后序遍历：");
	PrintTree(T, 0);
	printf("\n");

	// 查看插入的节点是否正确
	Position TmpCell;
	TmpCell = FindMin(T);
	printf("最小值为 %d \n", TmpCell->Element);
	TmpCell = FindMax(T);
	printf("最大值为 %d \n", TmpCell->Element);
	TmpCell = Find(15, T);
	printf("想要查询的值为15，实际结果为%d \n", TmpCell->Element);

	// 删除原本最大值和最小值后
	T = Delete(2, T);
	T = Delete(27, T);
	TmpCell = FindMin(T);
	printf("==删除最大值和最小值后==\n最小值为 %d \n", TmpCell->Element);
	TmpCell = FindMax(T);
	printf("最大值为 %d \n", TmpCell->Element);
	TmpCell = Find(15, T);
	// 清空树，释放所有节点所占用的空间
	MakeEmpty(T);
}

// 清空树，释放其所占用的空间
SearchTree MakeEmpty(SearchTree T)
{
	if(T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		// 当遇到了一个叶节点，意味着其左右子树都为空
		// 则将当前节点释放掉
		free(T);
	}

	// 我觉得不加返回值也行
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if(T == NULL)
		return NULL;
	// 待查找的元素小于当前节点的值
	// 沿着左子树查找
	if(X < T->Element)
		Find(X, T->Left);
	// 待查找的元素大于当前节点的值
	// 沿着右子树查找
	else if (X > T->Element)
		Find(X, T->Right);
	else
		// 相等时则返回找到的节点
		return T;
}

/*
 * 这个函数在最后是用了递归
 * 尾递归都可以通过循环消除，以提高效率
 * 所以该函数仅供参考
 *
 * Position FindMin(SearchTree T)
 * {
 *		if(T == NULL)
 *			return NULL;
 *		if(T->Left == NULL)
 *			return T;
 *		else
 *			return FindMin(T->Left);
 *}
*/

// 最小值就是数最左边的节点
Position FindMin(SearchTree T)
{
	if(T != NULL)
		while(T->Left != NULL)
			T = T->Left;
	
	return T;
}

// 最大值就是树最右边的节点
Position FindMax(SearchTree T)
{
	if(T != NULL)
		while(T->Right != NULL)
			T = T->Right;

	return T;
}

/*
 * 这是按照书上的写法(包含了创建根节点的情况)
 * 在插入新的节点的时候，并不改变原先树的结构
 * 而是将新的节点作为叶节点插入树的底部
 * 这里用的是递归处理插入过程的
 * 不过我觉得不用递归可能更方便
 */
SearchTree Insert(ElementType X, SearchTree T)
{
	// 如果树为空则创建树
	if(T == NULL)
	{
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if(T == NULL)
		{
			printf("Out of space!!!");
			exit(1);
		} else {
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	} else {
		if(X < T->Element)
			T->Left = Insert(X, T->Left);
		else if(X > T->Element)
			T->Right = Insert(X, T->Right);
	}

	return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;

	if(T == NULL)
	{
		printf("Element not found!!!");
		exit(1);
	}
	if(X < T->Element)
		T->Left = Delete(X, T->Left);
	else if(X > T->Element)
		T->Right = Delete(X, T->Right);
	// 下面则是找到了值相等的情况，判断值相等的节点有几个子节点
	else if(T->Left && T->Right)
	{
		// 用当前节点子树中最小的节点值代替当前节点的值
		// 再递归删除值最小的节点
		// 这个节点只能存在于其右子树中
		// 因为当当前的根节点被替换掉的时候，根节点要大于所有左子树的节点
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		// 接下来要删除值最小的那个节点
		T->Right = Delete(TmpCell->Element, T->Right);
	} else {
		// 当只有一个或0个子节点的情况
		TmpCell = T;
		
		if(T->Left == NULL)
			T = T->Right;
		else if(T->Right == NULL)
			T = T->Left;

		// 不理解这里的TmpCell赋值后也没有用
		// 干嘛要多此一举？？？？？
		free(TmpCell);
	}

	return T;
}

// 这是按照后序遍历的方式输出二叉树的元素
void PrintTree(SearchTree T, int method)
{
	switch(method)
	{
		// 后序遍历
		case 0 :
			if(T->Left != NULL)
				PrintTree(T->Left, 0);
			if(T->Right != NULL)
				PrintTree(T->Right, 0);

			printf("%d  ", T->Element);
			break;
		// 中序遍历
		case 1 :

			break;
		// 前序遍历
		case 2 :
			
			break;
		default:
			printf("未知的排序方式！！！\n");
	}
}
