// This is the class implementation for a linked list object
// that consists of multiple nodes
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  07/09/2016

#include "LinkedList.h"

using namespace std;
namespace jonathan_deck_of_cards
{
	//CONSTRUCTORS
	//create an empty linked list
	LinkedList::LinkedList()
	{
		head_ptr_ = NULL;
		tail_ptr_ = NULL;
		current_ptr_ = NULL;
		list_length=0;
	}
	//create a linked list with data
	LinkedList::LinkedList(data_type& data)
	{
		head_ptr_ = new node(data);
		tail_ptr_ = head_ptr_;
		current_ptr_ = tail_ptr_;
		list_length=1;
	}
	//DESTRUCTOR
	//ensure all nodes are removed from the heap when a linked list is deleted
	LinkedList::~LinkedList()
	{
		while(head_ptr_!=NULL)
				remove_from_head();
			tail_ptr_=NULL;
	}
	void LinkedList::add_to_head(data_type& data)
	{
		//add node for empty list
		if (list_length==0)
		{
			head_ptr_ = new node(data);
			tail_ptr_ = head_ptr_;
			current_ptr_ = tail_ptr_;
			list_length=1;
		}
		//insert node at head
		else
		{
			// create new node on heap
			node* head_insert = new node(data);
			
			// set the heads "previous" ptr to the new head and set the next nodes "next"
			// ptr to  the node at the current head
			head_ptr_->set_previous(head_insert);
			head_insert->set_next(head_ptr_);
			
			// set the head_ptr_ to the new node
			head_ptr_ = head_insert;
			
			// increment list
			list_length++;
			
			// set temp to null
			head_insert = NULL;
		}
	}
	void LinkedList::add_to_tail(data_type& data)
	{
		//add node for empty list
		if (list_length==0)
		{
			head_ptr_ = new node(data);
			tail_ptr_ = head_ptr_;
			current_ptr_ = tail_ptr_;
			list_length=1;
		}
		//insert node at tail
		else
		{
			// create new node on heap
			node* tail_insert = new node(data);
			
			// set the tails "next" ptr to the new tail and set the next nodes "previous"
			// ptr to  the node at the current tail
			tail_ptr_->set_next(tail_insert);
			tail_insert->set_previous(tail_ptr_);
			
			// set the tail_ptr_ to the new node
			tail_ptr_ = tail_insert;
			
			// increment list
			list_length++;
			
			// set temp to null
			tail_insert = NULL;
		}
	}
	void LinkedList::add_to_current(data_type& data)
	{	
		//add node for empty list
		if (list_length==0)
		{
			head_ptr_ = new node(data);
			tail_ptr_ = head_ptr_;
			current_ptr_ = tail_ptr_;
			list_length=1;
		}
		//insert node before current position
		else if (current_ptr_!=head_ptr_)
		{
			// create new node on heap
			node* current_insert = new node(data);
			// create a temporary node
			node* temp_current_ptr = current_ptr_;
			
			
			//move back one place
			temp_current_ptr = temp_current_ptr->get_previous();
			
			//previous node now links to current_insert
			temp_current_ptr->set_next(current_insert);
			

			//current position now links to the new node
			current_ptr_->set_previous(current_insert);
			

			//link new node to new previous and next
			current_insert->set_previous(temp_current_ptr);
			current_insert->set_next(current_ptr_);
			

			
			//point current @ new node
			current_ptr_ = current_insert;
			

			//increment list
			list_length++;
			
			// set temp and insert to null, as no longer required
			current_insert = NULL;
			temp_current_ptr = NULL;
			
			
			
			
			
		}
		else if (current_ptr_==head_ptr_)
		// ensure that we don't write out of bounds, if trying to insert before head, 
		// just treat like "add to head"
		{
			node* head_insert = new node(data);
			
			head_ptr_->set_previous(head_insert);
			head_insert->set_next(head_ptr_);
			
			head_ptr_ = head_insert;
			current_ptr_ = head_insert;
			
			list_length++;
			
			head_insert = NULL;	
		}
	}
	void LinkedList::remove_from_head()
	{
		// do nothing for empty list
		if (list_length==0)
			return;
		
		// remove final node if only 1 node in list
		else if(list_length==1)
		{
			delete head_ptr_;
			head_ptr_=NULL;
			tail_ptr_=NULL;
			current_ptr_ = NULL;
			list_length--;
			return;
		}
		else
		{
			// make a temp_head_ptr and set it as the current head_ptr_
			node* temp_head_ptr = head_ptr_;
			// rearrange the head_ptr_ for the list
			head_ptr_ = temp_head_ptr->get_next();
			// remove the node, memory management
			delete temp_head_ptr;
			// decrement list
			list_length--;
			// set to ptr to null
			temp_head_ptr = NULL;
		}
	}
	void LinkedList::remove_from_tail()
	{
		// do nothing for empty list
		if (list_length==0)
			return;
		
		// remove final node if only 1 node in list
		else if(list_length==1)
		{
			delete head_ptr_;
			head_ptr_=NULL;
			tail_ptr_=NULL;
			current_ptr_ = NULL;
			list_length--;
			return;
		}
		else
		{
			// make a temp_tail_ptr and set it as the current tail_ptr_
			node* temp_tail_ptr = tail_ptr_;
			// rearrange the tail_ptr_ for the list
			tail_ptr_ = temp_tail_ptr->get_previous();
			// remove the node, memory management
			delete temp_tail_ptr;
			// decrement list
			list_length--;
			// set to ptr to null
			temp_tail_ptr = NULL;
		}
	}
	void LinkedList::remove_current()
	{
		// do nothing for empty list
		if (list_length==0)
			return;
		
		// remove final node if only 1 node in list
		else if(list_length==1)
		{
			delete head_ptr_;
			head_ptr_=NULL;
			tail_ptr_=NULL;
			current_ptr_ = NULL;
			list_length--;
			return;
		}
		else if (current_ptr_!=head_ptr_ && current_ptr_!=tail_ptr_)
		{	
						
			// make a temp_current_ptr and set it as the current current_ptr_
			node* temp_current_ptr = current_ptr_;
			
			// rearrange the appropriate ptrs for the list
			current_ptr_ = temp_current_ptr->get_previous();
			current_ptr_->set_next(temp_current_ptr->get_next());
			current_ptr_ = temp_current_ptr->get_next();
			current_ptr_->set_previous(temp_current_ptr->get_previous());
			
			// remove the node, memory management
			delete temp_current_ptr;
			// decrement list
			list_length--;
			// set to ptr to null
			temp_current_ptr = NULL;
			
		}
		// ensure that we don't select out of bounds, if trying to delete the head, 
		// just treat like "delete from head"
		else if (current_ptr_==head_ptr_)
		{
			node* temp_head_ptr = head_ptr_;
			head_ptr_ = temp_head_ptr->get_next();
			delete temp_head_ptr;
			list_length--;
			temp_head_ptr = NULL;	
		}
		// ensure that we don't select out of bounds, if trying to delete the tail, 
		// just treat like "delete from tail"
		else if (current_ptr_==tail_ptr_)
		{
			node* temp_tail_ptr = tail_ptr_;
			tail_ptr_ = temp_tail_ptr->get_previous();
			delete temp_tail_ptr;
			list_length--;
			temp_tail_ptr = NULL;	
		}
	}
	
	void LinkedList::forward()
	{
		// boundary to prevent selecting outside of list
		if (current_ptr_!=tail_ptr_)
		{
			current_ptr_ = current_ptr_->get_next();
		}
		else
		{
			return;
		}
	}
	void LinkedList::backwards()
	{
		// boundary to prevent selecting outside of list
		if (current_ptr_!=head_ptr_)
		{
			current_ptr_ = current_ptr_->get_previous();
		}
		else
		{
			return;
		}
	}
	void LinkedList::move_to_head()
	{
		current_ptr_ = head_ptr_;
	}
	void LinkedList::move_to_tail()
	{
		current_ptr_ = tail_ptr_;
	}
	LinkedList::data_type LinkedList::get_current()
	{
		return current_ptr_->get_data();
	}
	std::size_t LinkedList::size()
	{
		return list_length;
	}
	void LinkedList::swap(int jpos, int ipos)
	{
		// create two temporary nodes
		node* temp_j_ptr;// = current_ptr_;
		node* temp_i_ptr;// = current_ptr_;
		
		// select j node
		// reset current node to head
		current_ptr_ = head_ptr_;
		
		// move current node to position j
		// loop until on correct position
		for(int j=0; j!=jpos; j++)
		{
			current_ptr_ = current_ptr_->get_next();
		}
		temp_j_ptr = current_ptr_;
		
		// select i node
		// reset current node to head
		current_ptr_ = head_ptr_;
		
		// move current node to position i
		// loop until on correct position
		for(int i=0; i!=ipos; i++)
		{
			current_ptr_ = current_ptr_->get_next();
		}
		temp_i_ptr = current_ptr_;
		
		//extract data out of j
		string j_data = temp_j_ptr->get_data();
		// change j data to i data
		temp_j_ptr->set_data(temp_i_ptr->get_data());
		// change i data to saved j data
		temp_i_ptr->set_data(j_data);
		
		// set both pointers to null as we no longer need them
		temp_j_ptr = NULL;
		temp_i_ptr = NULL;
		
	}
}