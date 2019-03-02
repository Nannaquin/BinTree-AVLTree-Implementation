// CSCI 335 Steven Santana
#include"BST.h"

#ifndef AVL_H
#define AVL_H

/**	INHERITED FUNCTIONS
		Insertion <Replaced/Overloaded>
		Removal <Replaced/Overloaded>
		Print 
		Size	
		Height 
		operator= 
		operator[] 
*/

template<class Type>
class AVL :public BST<Type>
{
protected:


	// From textbook.
	/** Returns height of given node/subtree*/
	int nodeHeight(BinNode<Type> *t) const;


	
	//Insertion helper, overloaded to include rebalancing stuff.
	void insert(const Type &x, BinNode<Type> *&t);
	// Removal helper, overloaded to include rebalancing.
	void remove(const Type &x, BinNode<Type> *&t);

	/** Rebalances the tree/node. 
	@pre: An insertion or deletion has occured,
		and that t is balanced or within 1 level of
		being balanced.
	@post: The tree will retain its balance property.
	@param: t  The node/subtree to be rebalanced, if needed. */
	void balance(BinNode<Type> *&t);


	/* Rotation functions */

	// Left Child Rotations

	void rotateWithLeftChild(BinNode<Type> *&k2);
	void doubleWithLeftChild(BinNode<Type> *&k3);

	// Right Child Rotations

	void rotateWithRightChild(BinNode<Type> *&k2);
	void doubleWithRightChild(BinNode<Type> *&k3);

public:

	// overriding.
	void insert(const Type &nElem);
	// overriding
	void remove(const Type &target);

};

#endif 
