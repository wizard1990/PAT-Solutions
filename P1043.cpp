#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int a[1010];
struct Node
{
	Node *left;
	Node *right;
	int value;
};

bool makeTree(Node **root, int start, int num, bool isMirror)
{
	if (num == 0){
		root = NULL;
		return true;
	}

	*root = (Node *)malloc(sizeof(Node));
	(*root)->left = (*root)->right = NULL;
	(*root)->value = 0;

	(*root)->value = a[start];
	if (num == 1) return true;

	int divide = -1;
	bool leftRet, rightRet;
	for (int i = 1; i < num; i++){
		if(isMirror){
			if(a[start + i]<(*root)->value){
				divide = i;
				break;
			}
		}
		else{
			if(a[start + i]>=(*root)->value){
				divide = i;
				break;
			}
		}
	}

	if(divide == -1){
		(*root)->right = NULL;
		leftRet = makeTree(&(*root)->left, start+1, num-1, isMirror);
		rightRet = true;
	}
	else {
		leftRet = makeTree(&(*root)->left, start+1, divide - 1, isMirror);
		rightRet = makeTree(&(*root)->right, start+divide, num - divide, isMirror);
	}

	if (leftRet && rightRet){
		int leftMost = 0, rightMost = 0;
		Node* tmp = (*root)->left;
		while(tmp && tmp->right != NULL) tmp = tmp->right;
		if(tmp) leftMost = tmp->value;
		tmp = (*root)->right;
		while(tmp && tmp->left != NULL) tmp = tmp->left;
		if(tmp) rightMost = tmp->value;

		if(isMirror){
			if(leftMost != 0 && leftMost < (*root)->value) return false;
			if(rightMost != 0 && rightMost >= (*root)->value) return false;
			return true;
		}
		else{
			if((*root)->left != 0 && leftMost >= (*root)->value) return false;
			if((*root)->right != 0 && rightMost < (*root)->value) return false;
			return true;
		}
	}
	else return false;
}

void postOrder(Node *root)
{
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->value);
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	Node *root = NULL;
	bool ret = makeTree(&root, 0, n, true);
	if(!ret){
		ret = makeTree(&root, 0, n, false);
	}
	if (ret){
		printf("YES\n");
		postOrder(root->left);
		postOrder(root->right);
		printf("%d",root->value);
	}
	else printf("NO");
}