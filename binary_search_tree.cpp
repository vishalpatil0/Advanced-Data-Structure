#include<iostream>

using namespace std;

class node
{
	private:
		int data;
		node *left,*right;
	public:
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
		friend class btree;
};
class btree
{
	private:
		node *root;
	public:
		btree()
		{
			root=NULL;
		}
		void create()
		{
			int val,insert=0;
			char dir;
			cout<<"Enter the value to insert"<<endl;
			cin>>val;
			node *nn=new node(val);
			node *parent,*temp;
			if(root==NULL)
			{	
				root=nn;
			}
			else
			{
				temp=root;
				while(insert!=1)
				{
					cout<<"current node data :"<<temp->data<<endl;
					if(temp->data>val)
					{
						parent=temp;
						temp=temp->left;
						dir='l';
					}
					else if(temp->data<val)
					{
						parent=temp;
						temp=temp->right;
						dir='r';
					}
					else
					{
						cout<<"Repeated value"<<endl;
					}
					if(temp==NULL && dir=='r')
					{
						parent->right=nn;
						insert=1;
					}
					else if(temp==NULL && dir=='l')
					{
						parent->left=nn;
						insert=1;
					}
				}
			}
		}
		void mirror(node *temp)
		{
			node *t=temp;
			while(temp!=NULL)
			{
				t=temp->left;
				temp->left=temp->right;
				temp->right=temp->left;
				mirror(temp->left);
				mirror(temp->right);
			}
		}
		void swap()
		{
			mirror(root);
			cout<<"Mirror image of BST is "<<endl;
			display();
		}
		int maxnodes(node *temp)
		{
			if(temp==NULL)
			{
				return 0;
			}
			else
			{
				int ldep=maxnodes(temp->left);
				int rdep=maxnodes(temp->right);
				if(ldep>rdep)
				return (ldep+1);
				else
				return (rdep+1);
			}
		}
		void height()
		{
			int h;
			h=maxnodes(root);
			cout<<"\nLength of the longest root in the bst is :"<<h;
		}
		void search()
		{
			int val,flag=0;
			node *temp;
			cout<<"Enter the value to search"<<endl;
			cin>>val;
			if(root==NULL)
			{
				cout<<"Tree is empty"<<endl;
			}
			else
			{
				temp=root;
				if(temp->data==val)
					{
						flag=1;
						break;
					}
					else if(temp->data>val)
					{
						temp=temp->left;
					}
					else if(temp->data<val)
					{
						temp=temp->right;
					}
					else
					{
						flag=0;
					}
				}
				if(flag==1)
				cout<<val<<" : Value found...";
				else
				cout<<val<<" : Value not found...";
			}
		}
		void minvalue()
		{
			node *temp;
			if(root==NULL)
			{
				cout<<"\nTree is empty...";
			}
			else
			{
				temp=root;
				while(temp->left!=NULL)
				{
					temp=temp->left;
				}
				cout<<"\nMin Value In BST :"<<temp->data;
			}
		}	
		void inOrder(node *n)
		{
			if(n)
			{
			inOrder(n->left);
			cout<<"\t"<<n->data;
			inOrder(n->right);
			}
		}
		void postOrder(node *n)
		{	
			if(n)
			{
			postOrder(n->left);
			postOrder(n->right);
			cout<<"\t"<<n->data;
			}
		}
		void preOrder(node *n)
		{
			if(n)
			{
			cout<<"\t"<<n->data;
			preOrder(n->left);
			preOrder(n->right);
			}
		}
		void display()
		{
			cout<<"\nInOrder Display : ";
			inOrder(root);
  			cout<<"\nPreOrder Display : ";
			preOrder(root);
  			cout<<"\nPostOrder Display : ";
			postOrder(root);
		}
		
};

int main()
{
	btree b;
	while(true)
	{
	cout<<"\n-------------------------------------------------------------------------------"<<endl;
cout<<"\n1create \n2:Display \n3:Search\n4:Min Value\n5:Length of longest path \n6:Mirror Image\n7:Exit\nEnter your choice"<<endl<<endl;	
	int ch;
	cin>>ch;
	switch(ch)
	{
			case 1:
				b.create();
				break;
			case 2:
				b.display();
				break;
			case 3:
				b.search();
				break;
			case 4:
				b.minvalue();
				break;
			case 5:
				b.height();
				break;
			case 6:
				b.swap();
				break;
			case 7:
				exit(0);
		default:
			cout<<"Enter valid choice"<<endl;
	}
	}
	return 1;
}	
