// CSCI 335 Steven Santana
#include "AVL.h"



template<class Type>
int AVL<Type>::nodeHeight(BinNode<Type> *t) const
{
	return t == nullptr ? -1 : t->height;
}

template<class Type>
void AVL<Type>::insert(const Type &nElem)
{
	insert(nElem, root);
}
template<class Type>
void AVL<Type>::insert(const Type &x, BinNode<Type> *&t)
{
	if (t == nullptr) {
		t = new BinNode<Type>{ x, nullptr, nullptr };
		size += 1;
	}
	else if (x < t->element)
		insert(x, t->left);
	else if (x > t->element)
		insert(x, t->right);
	else if (x == t->element)


	balance(t);
}

template<class Type>
void AVL<Type>::remove(const Type &target)
{
	remove(target, root);
}

template<class Type>
void AVL<Type>::remove(const Type &x, BinNode<Type>*&t)
{
	if (t == nullptr)
		return;

	if (x < t->element)
		remove(x, t->left);
	else if (x > t->element)
		remove(x, t->right);
	else if ((t->left != nullptr) && (t->right != nullptr))
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinNode<Type> *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
		size -= 1;
	}

	balance(t);
}

template<class Type>
void AVL<Type>::balance(BinNode<Type> *&t)
{
	if (t == nullptr) return;
	//first left child operations, then right child operations.
	if (nodeHeight(t->left) - nodeHeight(t->right) > 1)
	{
		if (nodeHeight(t->left->left) >= nodeHeight(t->left->right))
			rotateWithLeftChild(t);
		else
			doubleWithLeftChild(t);
	}
	else if(nodeHeight(t->right) - nodeHeight(t->left) > 1)
	{
		if (nodeHeight(t->right->right) >= nodeHeight(t->right->left))
			rotateWithRightChild(t);
		else
			doubleWithRightChild(t);
	}

	if (nodeHeight(t->left) > nodeHeight(t->right))
		t->height = nodeHeight(t->left) + 1;
	else t->height = nodeHeight(t->right) + 1;
}


template<class Type>
void AVL<Type>::rotateWithLeftChild(BinNode<Type> *&k2)
{
	BinNode<Type> *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	if (nodeHeight(k2->left) > nodeHeight(k2->right))
		k2->height = nodeHeight(k2->left) + 1;
	else k2->height = nodeHeight(k2->right) + 1;

	if (nodeHeight(k1->left) > nodeHeight(k1->right))
		k1->height = nodeHeight(k1->left) + 1;
	else k1->height = nodeHeight(k1->right) + 1;

	k2 = k1;
}

template<class Type>
void AVL<Type>::rotateWithRightChild(BinNode<Type> *&k2)
{
	BinNode<Type> *k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	if (nodeHeight(k2->left) > nodeHeight(k2->right))
		k2->height = nodeHeight(k2->left) + 1;
	else k2->height = nodeHeight(k2->right) + 1;

	if (nodeHeight(k1->left) > nodeHeight(k1->right))
		k1->height = nodeHeight(k1->left) + 1;
	else k1->height = nodeHeight(k1->right) + 1;

	k2 = k1;
}

template<class Type>
void AVL<Type>::doubleWithLeftChild(BinNode<Type> *&k3)
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template<class Type>
void AVL<Type>::doubleWithRightChild(BinNode<Type> *&k3)
{
	rotateWithLeftChild(k3->right);
	rotateWithRightChild(k3);
}



template class AVL<int>;