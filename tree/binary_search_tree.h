#ifndef _Binary_Search_Tree_H

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
void PrintTree(SearchTree T, int method);

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};
#endif
