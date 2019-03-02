// CSCI 335 Steven Santana
#include "BST.h"
#include<iostream>

template<class Type>
BST<Type>::BST():root(nullptr), size(0) { }


template<class Type>
void BST<Type>::prune(BinNode<Type> *&t)
{
	if(t == nullptr)
		return;

	prune(t->left);
	prune(t->right);

	delete t;
	t = nullptr;
}

template<class Type>
BST<Type>::~BST() 
{
	prune(root);
	size = 0;
}

template<class Type>
void BST<Type>::clear()
{
	prune(root);
	size = 0;
}

// private recursive height
template<class Type>
int BST<Type>::Height(BinNode<Type> *t) const 
{
	if (t == nullptr)
		return 0;
	
	int lh = Height(t->left);
	int rh = Height(t->right);

	if(lh > rh) 
		return lh + 1;
	else if(lh <= rh) 
		return rh + 1;
	
}

// public height 
template<class Type>
int BST<Type>::Height()
{ 
	int h = Height(root);
	return h;
}


// public size 
template<class Type>
int BST<Type>::Size() 
{
	return size;
}	

// private recursive print
template<class Type>
void BST<Type>::Print(BinNode<Type> *t) const
{
	if(t == nullptr)
		return;
	Print(t->left);
	std::cout << t->element << "\n";
	Print(t->right);
}
// public print 
template<class Type>
void BST<Type>::Print() 
{ 
	Print(root);
}

template<class Type>
Type& BST<Type>::subscriptSearch(BinNode<Type> *t, Type &target)
{	
	Type ret; 
	if (t == nullptr)
		return ret; // return undefined garbage
	if (target < t->element) 
		ret = subscriptSearch(t->left, target);
	if (t->element == target) 
		return t->element;
	if(target > t->element) 
		ret = subscriptSearch(t->right, target);
	return ret;
}
template<class Type>
Type& BST<Type>::operator[](Type target) 
{ 
	return subscriptSearch(root, target);
}

template<class Type>
BST<Type>::BinNode<Type>* BST<Type>::copyAssignHelper(BinNode<Type> *rhs)
{
	if (rhs == nullptr) return nullptr;

	// copy node
	BinNode<Type>* newNode = new BinNode<Type>{ rhs->element, nullptr, nullptr };

	newNode->left = copyAssignHelper(rhs->left);
	newNode->right = copyAssignHelper(rhs->right);

	return newNode;
}

template<class Type>
BST<Type>& BST<Type>::operator=(const BST<Type> &rhs) 
{
	BST<Type>* b = new BST<Type>;
	root = copyAssignHelper(rhs.root);
	return *this;
}

template<class Type>
BST<Type>::BinNode<Type>* BST<Type>::findMin(BinNode<Type> *t)
{
	if(t == nullptr) return nullptr;
	if(t->left == nullptr) return t;
	
	return findMin(t->left);
}

template<class Type>
BST<Type>::BinNode<Type>* BST<Type>::findMax(BinNode<Type> *t)
{
	if(t == nullptr) return nullptr;
	if(t->right == nullptr) return t;
	
	return findMax(t->right);
}

template<class Type>
void BST<Type>::insert(const Type &nElem) 
{
	insert(nElem, root);
}

template<class Type>
void BST<Type>::insert(const Type &x, BinNode<Type> *&t) 
{
		// Found case
		if(t == nullptr)
		{
			t = new BinNode<Type>{ x, nullptr, nullptr };
			size += 1;
		}
		else if(x < t->element)
			insert(x, t->left);
		else if(x > t->element)
			insert(x, t->right);
		else { }
			// do nothing, duplicate
}

template<class Type>
void BST<Type>::remove(const Type &target) 
{
	remove(target, root);
}

template<class Type>
void BST<Type>::remove(const Type &x, BinNode<Type>*&t) 
{
	if (t == nullptr)
	{
		return;
	}
	if(x < t->element)
		remove(x, t->left);
	else if(x > t->element)
		remove(x, t->right);
	else if((t->left != nullptr) && (t->right != nullptr))
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
	
}

template class BST<int>;