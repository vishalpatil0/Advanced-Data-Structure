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
					cout<<"current node data :"<<temp->data;
					cout<<"Enter the direction (left/right) to insert data l/r"<<endl;
					cin>>dir;
					if(dir=='l')
					{
						parent=temp;
						temp=temp->left;
					}
					else if(dir=='r')
					{
						parent=temp;
						temp=temp->right;
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
	cout<<"1-Create\n2-Display\n3-Exit\n\nEnter your choice"<<endl<<endl;		
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
			exit(0);
		default:
			cout<<"Enter valid choice"<<endl;
	}
	}
	return 1;
}	
