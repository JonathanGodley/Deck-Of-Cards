// This defines a class that implements a linked list object
// that consists of multiple nodes
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  06/09/2016

#ifndef JONATHAN_LINKED_LIST
#define JONATHAN_LINKED_LIST

#include <cstdlib> 	// provides size_t
#include <string> 	// provides string type
#include "Node.h"

using namespace std;
namespace jonathan_deck_of_cards
{
	class LinkedList
	{
		public:
			//TYPEDEF
			typedef string data_type;
			
			//CONSTRUCTOR
			// Precondition:	N/A
			// Postcondition: 	An Empty Linked List instance is createed
			LinkedList();
			
			// Precondition:	N/A
			// Postcondition:  	An Linked List instance is created, with a starting node 
			// 		generated using the data passed in the parameter 
			LinkedList(data_type& data);
			
			//DESTRUCTOR
			// Precondition:	An Linked List Instance containts node instances
			// Postcondition:   Each node is deleted from the head of the list, leaving an empty linked list
			~LinkedList();
			
			//MEMBER FUNCTIONS
			// Precondition:	An Linked List has been initialised
			// Postcondition:   A new node instance is generated at the head of the list
			void add_to_head(data_type& data);
			
			// Precondition:	An Linked List has been initialised
			// Postcondition:   A new node instance is generated at the tail of the list
			void add_to_tail(data_type& data);
			
			// Precondition:	An Linked List has been initialised
			// Postcondition:   A new node instance is generated before the current position of the list
			void add_to_current(data_type& data);
			
			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   The first node in the list is removed
			void remove_from_head();
			
			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   The last node in the list is removed
			void remove_from_tail();
			
			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   The selected node in the list is removed
			void remove_current();
			
			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   The next node in the list from the currently selected node is selected
			void forward();
			
			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   The previous node in the list from the currently selected node is selected
			void backwards();
			
			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   The node at the head (or beginning) of the list is selected
			void move_to_head();
			
			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   The node at the tail (or end) of the list is selected
			void move_to_tail();
			
			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   The data value in the selected node is returned
			data_type get_current();
			
			// Precondition:	A linked list is initialised with nodes containing data
			// Postcondition:   the number of nodes in the linked list is returned
			std::size_t size();
			
			// Precondition:	An Linked List has been initialised & parameters are passed
			// Postcondition:   the two nodes at the positions specified in the parameters have their data swapped
			void swap(int jpos, int ipos);
		private:
			node* head_ptr_;
			node* tail_ptr_;
			node* current_ptr_;
			std::size_t list_length;
	
	};
}

#endif