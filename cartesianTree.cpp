#include <bits/stdc++.h> 
#include <cstdlib>
#include <iostream>
using namespace std;

template < typename T >
struct Node 
{
  T key;
  long long prior;
  Node* left;
  Node* right;
};

long genRand()
{  
   return rand() * 32768 + rand();
}

template < typename T >
Node<T>* newNode(const T& k)
{
	Node<T>* newNode = new Node<T>{k, genRand(), nullptr, nullptr};
   	
   	return newNode;
}

Node<int> *root = 0;

template < typename T >
bool searchIterative(Node<T>* froot, const T& key)
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
pair< Node<T>* , Node<T>* > split(Node<T>* froot, const T& k) 
{
	if(froot == nullptr)
	{
		return make_pair(nullptr, nullptr);
	}
	if(froot->key <= k)
	{
		
		pair< Node<T>*, Node<T>* > p = split(froot->right, k);
		froot->right = p.first;
		return make_pair(froot, p.second);
	}
	else
	{
		pair< Node<T>*, Node<T>* > p = split(froot->left,k);
		froot->left = p.second;
		return make_pair(p.first, froot);
	}
}

template < typename T > 
void printTree(Node<T>* froot)
{
	if(froot != nullptr)
    {
		printTree<T>(froot->left);
		cout << froot->key << " " ;
		printTree<T>(froot->right);
	}
}

template < typename T >
Node<T>* mergeNodes(Node<T>* leftTree, Node<T>* rightTree)
{
	if(leftTree == nullptr)
	{
		return rightTree;
	}
	
	if(rightTree == nullptr)
	{
		return leftTree;
	}
	
	if(leftTree->prior < rightTree-> prior)
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
Node<T>* insert(Node<T>* froot, const T& k)
{
	pair< Node<T>*, Node<T>* > p = split(froot, k);
	Node<T>* node = newNode<T>(k);
	return mergeNodes<T>(mergeNodes<T>(p.first, node), p.second);
} 

template < typename T>
Node<T>* erase(Node<T>* froot, const T& k)
{
               pair< Node<T>*, Node<T>* > p = split(froot, k);
    pair< Node<T>*, Node<T>* > p2 = split(p.first, k - 1); //
    
    delete p2.second;
    
    return mergeNodes(p2.first, p.second);
}


int main()
{	
    for(int i = 0; i < 1000; i++)
    {
		root = insert(root, i);
	}
    //printTree(root);
   
    for(int i = 0; i < 1000; i++)
    {
		root = erase(root, i);
	}
	printTree(root);
   
	return 0;
}
