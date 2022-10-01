#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//class
class node{
	public:
		int data;
		node* next;
	node(int value)
	{
		data=value;
		next=NULL;
	}
};
//ye function list k end/tail main value insert kare gaa
void insertAtEnd(node* &head, int value)
{
	  node* n=new node(value);
	  if(head==NULL)
	  {
	  	head=n;
	  	return;
	  }
	  node* temp=head;
	  while(temp->next!=NULL){
	  	temp=temp->next;
	  }
	  temp->next=n;
}
//ye function list k head/start main value insert kare ga
void insertAtHead(node* &head, int value)
{
	node* n=new node(value);
	n->next=head;
	head=n;
}
//ye function value search kare ga jo user input de ga or jis index pai value hoga wo return kare ga
void search(node*head, int value)
{
	int  found=0;
	node* temp=head;
if(temp != NULL) {
    while(temp != NULL) {
      if(temp->data == value) {
        found++;
        break;
      }
      temp = temp->next;
    }
    if (found == 1) {
      cout<<value<<" is present in the list..."<<endl;
    } else {
      cout<<value<<" is not present in the list.."<<endl;
    }
  } else {
    
    //4. If the temp node is null at the start, 
    //   the list is empty
    cout<<"The list is empty.\n";
  }
}
//ye function head ki delete kre ga
void deleteHead(node* &head)
{
	node* todelete=head;
	head=head->next;
	delete todelete;
	cout<<"Head is delete"<<endl;
}
//ye function mide or end se value delete kre ga
void deletion(node* &head, int value)
{
	//agar head khali hai
	if(head==NULL)
	{
		cout<<"Head is empty.."<<endl;
		return;
	}
	
	node* temp=head;
	while(temp->next->data!=value)
	{
		temp=temp->next;
	}
	node*todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
	cout<<"Value is deleted from the list.."<<endl;
	cout<<"\n";
}
//ye function list k elements print kare ga
void Display(node* head)
{
	node* temp=head;
	cout<<"DATA IN THE LIST :"<<endl;
	cout<<"\n";
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	cout<<"\n";
}

int main()
{
	cout<<"\t\t\tIMPLEMENTATION OF LINKED LIST\t\t\t"<<endl;
	cout<<"\t\t\t==============================\t\t\t"<<endl;
	cout<<"\n";
	int choice,v;
	node* head=NULL;
	cout<<"\t\t\tPRESS 1 TO INSERT IN LINKED LIST AT THE END.."<<endl;
	cout<<"\t\t\tPRESS 2 TO INSERT IN LINKED LIST AT THE HEAD.."<<endl;
	cout<<"\t\t\tPRESS 3 TO SEARCH ELEMENT IN LINKED LIST.."<<endl;
	cout<<"\t\t\tPRESS 4 TO DELETE ELEMENT FROM LINKED LIST.."<<endl;
	cout<<"\t\t\tPRESS 5 TO DELETE HEAD OF THE LIST.."<<endl;
	cout<<"\t\t\tPRESS 6 TO DISPLAY LINKED LIST.."<<endl;
	cout<<"\t\t\tPRESS 7 TO EXIT..."<<endl;
	cout<<"\n";
    do
    {
    	cout<<"ENTER CHOICE 1 TO 7:"<<endl;
    	cin>>choice;
    	cout<<"\n";
    	switch(choice)
    	{
    		case 1:
    			{
    				cout<<"Enter value to insert at End..: ";
    				cin>>v;
    				cout<<"\n";
    				insertAtEnd(head,v);
    				break;
				}
			case 2:
				{
					cout<<"Enter value to insert at Head..: ";
    				cin>>v;
    				cout<<"\n";
					insertAtHead(head,v);
					break;
				}
		   case 3:
		   	{
		   		cout<<"Enter the value to search from link list:...";
		   		cin>>v;
		   		cout<<"\n";
		   		search(head,v);
		   		break;
		    }
		    case 4:
		    	{
		    	cout<<"Enter the value to delete from link list:...";
		   		cin>>v;
		   		cout<<"\n";
		   		deletion(head,v);
		   		break;
				}
			case 5:
				{
				deleteHead(head);
		   		break;	
				}
			case 6:
				{
					Display(head);
					break;
				}
			case 7:
				{
					cout<<"EXIT"<<endl;
					break;
				}
				default:
				{
					cout<<"INVALID CHOICE.."<<endl;
				}
		}
	}
	while(choice!=7);
 return 0;	
}
