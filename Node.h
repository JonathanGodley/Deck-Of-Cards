// This defines and implements a class for a node object
// Kept together due to how tiny a class it is
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  06/09/2016

#ifndef JONATHAN_NODE
#define JONATHAN_NODE

#include <string> // provides string type
#include <cstdlib> // provides NULL

using namespace std;
namespace jonathan_deck_of_cards
{
	class node
	{
		public:
			//TYPEDEF
			typedef string data_type;
			
			//CONSTRUCTOR
			
			// Precondition : N/A
			// Postcondition:  A new instance of node is created and its
			// 	instance data initialsed to the parameter provided value, 
			// 	as well as pre-determined NULL values
			node(const data_type& init_data = data_type(), node* init_next = NULL, node* init_previous = NULL)
			{
				data = init_data;
				next = init_next;
				previous = init_previous;
			}
			//DESTRUCTOR
			// Precondition:	A node instance has been initialsed
			// Postcondition:   The nodes data and pointers are cleared
			~node()	{data = "";next = NULL;previous = NULL;}
			
			//MODIFICATION MEMEBER FUNCTIONS
			// Precondition : data has been initialsed
			// Postcondition: the provided paramater is set as the data value
			void set_data(const data_type& new_data) 	{ data = new_data; }
			
			// Precondition : next_link has been initialsed
			// Postcondition: the provided paramater is set as the next value
			void set_next(node* next_link) 				{ next = next_link; }
			
			// Precondition : previous_link has been initialsed
			// Postcondition: the provided paramater is set as the previous value
			void set_previous(node* previous_link) 		{ previous = previous_link; }
			
			//CONSTANT MEMBER FUNCTIONS
			// Precondition : data has been initialsed
			// Postcondition: the value of data is returned
			data_type get_data() const					{ return data; }
			
			//NOTE:Compiler chooses which instance of the following to use based on
			// 	whether function was activated by a constant or ordinary pointer
			
			// Precondition : previous has been initialsed
			// Postcondition: the value of previous is returned
			const node* get_previous() const			{ return previous; }
			node* get_previous()						{ return previous; }
			
			// Precondition : next has been initialsed
			// Postcondition: the value of next is returned
			const node* get_next() const				{ return next; }
			node* get_next()							{ return next; }
		
		private:
			data_type data;
			node* next;
			node* previous;
	};
}

#endif