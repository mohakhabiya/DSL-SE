#include<iostream>
#define true 1
#define false 0
using namespace std;


class node
{
	public:

	int data;
	node *left,*right;


	node * create(node *root);
	void insert(node *root,node *temp);
	void recdisplvr(node *root);
	void recdispvlr(node *root);
	void recdisplrv(node *root);

};

node * node::create(node *root)
{
	node *temp;
	char c;
	root=NULL;
	do
	{

		temp=new node;
		temp->left=NULL;
		temp->right=NULL;
		cout<<"\nEnter the data : ";
		cin>>temp->data;
		if(root==NULL)
			root=temp;
		else
			insert(root,temp);
		cout<<"\n\n want to enter more nodes(y/n)";
		cin>>c;
	}while(c=='Y' || c=='y');

	return root;
	}
//=--------------------------------------------------=//


void node::insert(node *root,node *temp)
{
	char ch;
	cout<<"Insert data to left(l) or right(r) of "<<root->data;

	cin>>ch;
	if(ch=='l'||ch=='L')
	{

		if(root->left==NULL)
		{
			root->left=temp;

		}
		else
			insert(root->left,temp);
	}
	if(ch=='r'||ch=='R')
	{
		if(root->right==NULL)
		{
			root->right=temp;

		}
		else
			insert(root->right,temp);
	}
	return;
}

void node :: recdisplvr(node *root)
{
	if(root)
	{
		recdisplvr(root->left);
		cout<<"\t"<<root->data;
		recdisplvr(root->right);
	}
}


void node :: recdispvlr(node *root)
{
	if(root)
	{   cout<<"\t"<<root->data;
		recdispvlr(root->left);
	    recdispvlr(root->right);
	}
}


void node :: recdisplrv(node *root)
{
	if(root)
	{
		recdisplrv(root->left);
		recdisplrv(root->right);
		cout<<"\t"<<root->data;

	}
}


int main()
{
	int ch;
	char ans;

	node p1,*root=new node;
	root->left=root->right=NULL;
	do
	{
		cout<<"1:Create binary tree \n2:DISPLAY \n3:EXIT "<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:

			root=p1.create(root);
			break;

		case 2:

			p1.recdisplvr(root);
			break;


		default:
			cout<<"invalid choice\n"<<endl;

		}

	}while(ch<3);

}





