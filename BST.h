// CSCI335 Steven Santana
#include<utility>

#ifndef BST_H
#define BST_H


template<class Type>
class BST
{
	protected:
		// node declaration stuff
		// textbook's node, with its name shortened.
		template<class Type>
		class BinNode
		{
		public:
			Type element;
			BinNode<Type> *left;
			BinNode<Type> *right;
			int height;

			BinNode<Type>(const Type &theElement, BinNode<Type> *lt, BinNode<Type> *rt, int h = 0)
				: element(theElement), left(lt), right(rt), height(h) { }

			BinNode<Type>(Type &&theElement, BinNode<Type> *lt, BinNode<Type> *rt, int h = 0)
				: element(std::move(theElement)), left(lt), right(rt), height(h) { }

			// Not from the textbook.
			BinNode<Type>* operator=(const BinNode<Type> *rhs)
			{
				BinNode<Type>* newNode = new BinNode<Type>(rhs->element, rhs->left, rhs->right, rhs->height );
				return newNode;
			}
		};
		
		BinNode<Type> *root;
		int size;
		
		// Private Recursive Remove
		void remove(const Type &x, BinNode<Type> *&t);
		
		// Private Recursive Insert
		void insert(const Type &x, BinNode<Type> *&t);

		
		/* find minmax functions, from the textbook.*/
		BinNode<Type>* findMin(BinNode<Type> *t);
		BinNode<Type>* findMax(BinNode<Type> *t); 
		
		/** Recursive height function to calculate height.
		@pre  Public height function has been called.
		@post The height of the tree shall be returned.
		@param  t  The node of the (sub)tree to be checked. 
		@return  The height of the current (sub)tree. */
		int Height(BinNode<Type> *t) const;
		
		
		/** Recursive print function that prints in ascending order. Does NOT print
		in the shape of a tree.
		@pre  Public Print has been called.
		@post Current node's contents as well as its children's will be displayed.
		@param  t  The root of the (sub)tree to be printed. */
		void Print(BinNode<Type> *t) const;
		
		/** Recursive function to facilitate destruction of the container.
		@pre  Destructor has been called.
		@post  Current node and its children will be deleted.
		@param  t  The root of the (sub)tree to free from memory. */
		void prune(BinNode<Type> *&t);
		
		/** Helper function for subscripting operator.
		@pre  Subscripting operator has been called.
		@post  A reference to the element being searched for will be
				returned, granted it exists in the tree. 
		@param  t  The root of the (sub)tree to traverse. 
				target  The element we are looking for.
		@return  The item stored at the ith node, should such node exist.
					Otherwise, return garbage value. */
		Type& subscriptSearch(BinNode<Type> *t, Type &target);

		/** Helper function for copy assignment operator.
		@pre  Copy assignment op has been called.
		@post  Entire (subtree) will be copied.
		@param  rhs  The node/root to be copied.
		@return  The node with all proper children attached. */
		BinNode<Type>* copyAssignHelper(BinNode<Type> *rhs);

	public:
		BST();
		
		~BST();
		
		// Calls other internal functions.
		int Height();
		int Size();
		void Print();

		/** Triggers destructor level node deletion.
		@post:  All nodes in the tree will be deleted. */
		void clear();
		
		/** Inserts a new item into the container. 
		@pre: The datatype has a comparison operators <, and ==
		@post: Item will be inserted into the container.
		@param: nElem  The new item to be inserted. */
		void insert(const Type &nElem);
		

		/** Removes an item from the container.
		@pre: The data type of the item has comparison operators <. and ==
		@post: The target item will be removed from the container.
		@param: target  The desired item to be removed. */
		void remove(const Type &target);
		
		/**Copy assignment operator. */ 
		BST<Type>& operator=(const BST<Type> &rhs);

		/** Essentially a search function, not a sequential thing function.
		@post  If target is present, a reference to it will be returned.
		@param  target  The element to be located.
		@return  A reference to said element if it exists within the container. */
		Type& operator[](Type target); 
	
};

#endif