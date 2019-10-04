#include <iostream>
#include <set>

using namespace std;

//Node with L - R and parent node.
/*
The label of the root is 1/1.
The left child of label p/q is p/(p+q).
The right child of label p/q is (p+q)/q.
*/
class node {

public:
	node* pi;
	node* r;
	node* l;
	int p, q;

	node()
	{
		pi = NULL;
		r = NULL;
		l = NULL;
	}
};


node* findPQ(unsigned long int n) //Solving speed is depth of tree.
{
	unsigned long int temp = n;
	set<unsigned long int> is;

	while (temp != 0)
	{
		is.insert(temp); //Gives a set with the order.
		temp = temp / 2;
	}
	

	//set contains all numbers in order. starting with 1.
	std::set<unsigned long int>::iterator it = is.begin();

	node* tree = new node();
	node* next = tree;
	tree->p = 1;
	tree->q = 1;
	unsigned long int q, p;

	it++;
	while (it != is.end())
	{
		if ((*it % 2) == 0)//LEFT
		{
			next->r = new node();
			next->r->pi = next;
			next->r->p = next->p + next->q;
			next->r->q = next->q;
			next = next->r;
		}
		else //RIGHT
		{
			next->l = new node();
			next->l->pi = next;
			next->l->p = next->p;
			next->l->q = next->p + next->q;
			next = next->l;
		}
		it++;
	}
	return next; //Return n'th node.
}

int main()
{
	int p;
	cin >> p;				//p = number of data sets.
	
	int k;					// k is which data set number we're working with.
	unsigned long int n; 	// n is the index (1 <= n <= 2147483647)

	for (int i = 0; i < p; i++) 
	{
		cin >> k >> n;
		node* result = findPQ(n);
		cout << k << ' ' << result->q << '/' << result->p << endl;
	}
}

