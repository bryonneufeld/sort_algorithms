#include <iostream>
#include <memory>
#include <vector>

using namespace std;

btree::btree()
{
  root=NULL;
}

btree::~btree()
{
  destroy_tree();
}

void btree::build(const vector <int> & data)
{
	for(int i = 0; i < data.size(); i++)
	{
		insert(data[i]);
	}	
}

void btree::destroy_tree()
{
  destroy_tree(root);
}

void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
	// cout << leaf->key_value << " destroyed" << endl;
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
	root->parent=NULL;
  }
}

void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
  	  leaf->left->parent=leaf;
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
      leaf->right->parent=leaf; //Sets the right child of the child node to null
    }
  }
}

void btree::remove(int key)
{
	//find if there is a key existing:
	node * points_to = search(key);

	if(points_to != NULL)
	{
		//track who the parent is:
		node * up_one = points_to->parent;
		
		vector <int> collection;
		//collect the ints below points_to, skipping points_to:
		collect_for_remove(points_to->left,collection);
		collect_for_remove(points_to->right,collection);
		//now destroy, which goes from top, to down
		destroy_tree(points_to);
		
		//real pain here, ensures parent still points to either NULL or valid branch:
		//probably a smart pointer would help here
		if(key >= up_one->key_value)
		{
			up_one->right=NULL;
		}
		else
		{
			up_one->left=NULL;
		}
		
		//rebuild the collected branches:
		for(int i = 0; i < collection.size(); i++)
		{
			insert(collection[i]);
		}
	}
	else
	{
		cout << "could not remove key, " << key << " was not found" << endl;
	}
}

void btree::collect_for_remove(node *leaf, vector <int> & collect)
{
	if(leaf !=NULL)
	{
		collect_for_remove(leaf->left,collect);
		collect.push_back(leaf->key_value);
		collect_for_remove(leaf->right,collect);
	}
}

void btree::search_key(int key)
{
	node * points_to = search(key);

	if(points_to == NULL)
	{
		cout << "No Match" << endl;
	}
	else
	{
		cout << "Found " << points_to->key_value << endl;
	}	
}

node *btree::search(int key)
{
  return search(key, root);
}

node *btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

void btree::printOrder()
{
	printOrder(root);
	cout << endl;
}

void btree::printOrder(node *leaf)
{
	if(leaf !=NULL)
	{
		printOrder(leaf->left);
		cout << leaf->key_value << " ";
		printOrder(leaf->right);
	}
}

void btree::printQuiet()
{
	printQuiet(root);
}

void btree::printQuiet(node *leaf)
{
	if(leaf !=NULL)
	{
		printQuiet(leaf->left);
		leaf->key_value;
		printQuiet(leaf->right);
	}
}

bool btree::check_sorted()
{
	int tracker = -1;
	bool b1 = true;
	check_sorted(root,tracker,b1);
	return b1;
}

void btree::check_sorted(node *leaf, int & tracker, bool & b1)
{
	if(leaf !=NULL)
	{
		check_sorted(leaf->left,tracker,b1);
		if(leaf->key_value < tracker)
		{
			b1 = false;
			tracker = leaf->key_value;
		}
		else
		{
			tracker = leaf->key_value;
		}
		check_sorted(leaf->right,tracker,b1);
	}	
}

















