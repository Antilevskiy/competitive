#include <bits/stdc++.h> 
#include <cstdlib>
#include <iostream>
using namespace std;

template < typename T >
struct Node 
{
  T key;
  long prior;
  Node* left;
  Node* right;
};

long genRand()
{  
   return rand() * 32786 + rand();
}

template < typename T >
Node<T>* newNode(T key)
{
	Node<T> newNode = new Node{key, genRand(), nullptr, nullptr};
   	
   	return newNode;
}

template < typename T >
bool searchIterative(Node<T>* froot, int key)
{
	while(froot)
	{
		if(froot->key == key)
		{
			return true;
		}
		if(froot->key > key)
		{
			froot = froot->left;
		}
		else
		{
			froot = froot->right;
		}
	}
	
	return false;
}  

template < typename T >
pair< Node<T>*, Node<T>* > split(Node<T>* froot, T key) 
{
	cout << "hello";
}

template < typename T >
Node<T>* mergeNodes(Node<T>* leftTree, Node<T>* rightTree)
{
	if(!leftTree)
	{
		return rightTree;
	}
	
	if(!rightTree)
	{
		return leftTree;
	}
	
	if(leftTree->priority < rightTree-> priority)
	{
		leftTree->right = mergeNodes(leftTree->right, rightTree);
         
        return leftTree; 
	}
	else
	{
		rightTree->left = mergeNodes(rightTree->left, leftTree);
		
		return rightTree;
	}
}

template < typename T > 
Node<T>* insert(Node<T>* froot, T key)
{
	pair< Node<T>*, Node<T>* > p = split(froot, key);
	Node<T>* node = newNode(key);
	return mergeNodes(mregeNodes(p->first, node), p.second);
} 

template < typename T>
Node<T>* erase(Node<T>* froot, T key)
{
    pair< Node<T>*, Node<T>* > p = split(froot, key);
    pair< Node<T>*, Node<T>* > p2 = split(p.first, key - 1); //////////////CONCRETE 
    
    delete p2.second;
    
    return mergeNodes(p2.first, p.second);
}

	Node<int> *root;

int main()
{	

	return 0;
}
