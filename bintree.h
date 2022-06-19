/*
	Author: Aatmodhee Goswami
	file: bintree.h
	Purpose and usage: This file is the header file for the BinTree class so it contains BinTree's private attributes and func prototypes.
 */


#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H
#include "data.h"
#include <iostream>
class BinTree{
	private:
	DataNode *root;
	int count;
	void clear(DataNode*);
	bool addNode(DataNode*,DataNode**);
	DataNode* removeNode(int, DataNode*);
	bool getNode(Data*, int, DataNode*);
	bool contains(int, DataNode*);
	int getHeight(DataNode*);
	void displayPreOrder(DataNode*);
	void displayPostOrder(DataNode*);
	void displayInOrder(DataNode*);
	DataNode* minValueNode(DataNode*);
	
	public:
	BinTree();
	~BinTree();
	bool isEmpty();
	int getCount();
	bool getRootData(Data*);
	void displayTree();
	void clear();
	bool addNode(int, const string*);
	bool removeNode(int);
	bool getNode(Data*, int);
	bool contains(int);
	int getHeight();
	void displayPreOrder();
	void displayPostOrder();
	void displayInOrder();
};



#endif /* BINTREE_BINTREE_H */

