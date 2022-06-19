/*
	Author: Aatmodhee Goswami
	file: bintree.cpp
	Purpose and usage: This file is the brains of the bintree Class and includes all of its methods
 */

#include "bintree.h"
BinTree::BinTree(){
	root = NULL;
	count = 0;
}
int BinTree::getCount(){
	return count;
}
void BinTree::displayInOrder(){
	displayInOrder(root);
}
void BinTree::displayInOrder(DataNode* temproot){
	if(temproot){
		displayInOrder(temproot->left);
		std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
		displayInOrder(temproot->right);
	
	}
}
void BinTree::displayPostOrder(DataNode* temproot){
	if(temproot){
		displayPostOrder(temproot->left);
		displayPostOrder(temproot->right);
		std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
	}
}

void BinTree::displayPostOrder(){
	displayPostOrder(root);
	return;
}
void BinTree::displayPreOrder(){
	displayPreOrder(root);
	return;
}
void BinTree::displayPreOrder(DataNode* temproot){
	if(temproot){
		displayPreOrder(temproot->left);
		displayPreOrder(temproot->right);
		std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
	}
}
void BinTree::displayTree(){
	std::cout << "Pre-Order Traversal" << std::endl <<"=======================" << std::endl;
	displayPreOrder();
	std::cout << "In-Order Traversal" << std::endl<<"=======================" << std::endl;
	displayInOrder();
	std::cout << "Post-Order Traversal"<<std::endl<<"=======================" << std::endl;
	displayPostOrder();
	std::cout << "Displaying height " << std::endl << "=======================" << std::endl;
	std::cout << getHeight()<<std::endl;
	std::cout << "Displaying Count" << std::endl << "=======================" << std::endl;
	std::cout << getCount()<<std::endl;
}
int BinTree::getHeight(){
	return getHeight(root);
}
int BinTree::getHeight(DataNode* temproot){
	int lh = 0;
	int rh = 0;
	int ret = 0;
	if(temproot){
		int lh = getHeight(temproot->left);
		int rh = getHeight(temproot->right);
		if(rh > lh){
			ret = rh + 1;
		}
		else{
			ret = lh + 1;
		}
	}
	return ret;
}
bool BinTree::contains(int x){
	bool cont = 0;
	if (x > -1){
		cont = contains(x, root);
	}
	return cont;
}
bool BinTree::contains(int x, DataNode* temproot){
	bool ret = 0;
	if(temproot){
		if(temproot->data.id == x){
			ret = 1;
		}
		else if(temproot->data.id > x){
			ret = contains(x, temproot->left);			
		}
		else if(temproot->data.id < x){
			ret = contains(x, temproot->right);
		}
	}
	return ret;
}

bool BinTree::addNode(int x, const string* str){
	bool added = 0;
	if (x > -1 && str->length() > 0){
		DataNode* ndata = new DataNode;
		ndata->data.id = x;
		ndata->data.information = *str;
		added = addNode(ndata, &root);
	}
	return added;
	
}
bool BinTree::addNode(DataNode*  newNode, DataNode** troot){
	bool added = 0;
	if (!(*troot)){
		*troot = newNode;
		(*troot)->left = NULL;
		(*troot)->right = NULL;
		added = 1;
		count++;
	}
	else if((*troot)->data.id > newNode->data.id){
		added = addNode(newNode, &((*troot)->left));
	}
	else if((*troot)->data.id < newNode->data.id){
		added = addNode(newNode, &((*troot)->right));
	}
return added;	 
	
}
bool BinTree::getNode(Data* inDat, int x){
	bool getnode = 0;
	if(x > -1 && inDat->information.length() > 0 ){
		getnode = getNode(inDat, x, root);
	}
	return getnode;
}
bool BinTree::getNode(Data* inDat, int x , DataNode* temproot){
	bool ret = 0;
	if(temproot){
		if(temproot->data.id == x){
			ret = 1;
			inDat->id = temproot->data.id;
			inDat->information = temproot->data.information;
		}
		else if(temproot->data.id > x){
			ret = getNode(inDat, x, temproot->left);			
		}
		else if(temproot->data.id < x){
			ret = getNode(inDat, x, temproot->right);
		}
	}
	return ret;
}

bool BinTree::isEmpty(){
	return(count == 0);}
	
bool BinTree::getRootData(Data* inDat){
	bool added = 0;
	if(root){
		inDat->id = root->data.id;
		inDat->information = root->data.information;
		added = 1;
	}
	else{
		inDat->information = " ";
		inDat->id = -1;
	}
	return added;
}
DataNode* BinTree::minValueNode(DataNode* node) {
DataNode* current = node;
while (current && current->left != NULL) {
current = current->left;
}
return current;
}
BinTree::~BinTree(){
	clear();
}
void BinTree::clear(){
	clear(root);
	root = NULL;
	count = 0;
}
void BinTree::clear(DataNode* root){
	if(root){
		clear(root->left);
		clear(root->right);
		root->right = NULL;
		root->left = NULL;
	}
	delete root;

}

bool BinTree::removeNode(int id){
	int tempcount = count;
	root = removeNode(id, root);
	return (count < tempcount);
}
DataNode* BinTree::removeNode(int x, DataNode* temproot){
	DataNode* retOut;		
	if(temproot){
		
		if(temproot->data.id > x) {
			temproot->left = removeNode(x,temproot->left);	
		}
		else if(temproot->data.id < x){
			temproot->right = removeNode(x, temproot->right);
		}
		else{
			DataNode* temp;
			if(temproot->left == NULL ){
				temp = temproot->right;
				delete temproot;
				temproot = temp;
				count--;

			}
			else if(temproot->right == NULL){
				temp = temproot->left;
				delete temproot;
				temproot = temp;
				count--;

			}
			else{
				temp = minValueNode(temproot->right);
				temproot->data.id = temp->data.id;
				temproot->data.information = temp->data.information;
				temproot->right = removeNode(temp->data.id, temproot->right);
			}
			
		}
	}
	retOut = temproot;
	return retOut;
}
