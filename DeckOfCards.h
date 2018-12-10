// This defines a class that represents a deck of playing cards
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  07/09/2016

#ifndef JONATHAN_DECK
#define JONATHAN_DECK

#include <iostream> // outstream
#include <string> 	// provides string type
#include "LinkedList.h"

using namespace std;
namespace jonathan_deck_of_cards
{
	class DeckOfCards
	{
		public:	
			//CONSTRUCTOR
			// Precondition:	N/A
			// Postcondition: 	A full deck of cards is created
			DeckOfCards();
			
			//DESTRUCTOR
			// Precondition:	DeckofCards is initialised with An Linked List also initialised
			// Postcondition:   The linked list object is deleted, calling it's own destructor
			~DeckOfCards();
			
			//MEMBER FUNCTIONS
			// Precondition:	DeckOfCards is initialised and has nodes in it's linked list
			// Postcondition:   the cards are shuffled using the Yates Algorithm, although this
			//					is done by swapping the data in two nodes rather than changing the 
			//					next / previous pointers
			void shuffle();
			
			// Precondition:	DeckofCards is initialised
			// Postcondition:   Returns the number of cards in DeckOfCards
			int length();
			
			// Precondition:	DeckofCards is initialised
			// Postcondition:   Returns whether there are cards in DeckOfCards or not
			//		reminder 0 = false, 1 = true
			bool empty();
			
			// Precondition:	DeckofCards is initialised and a string parameter is passed
			// Postcondition:   the position of the node that matches the search string is returned,
			// 					or if not found, -1 is returned
			int position(string search_value);
			
			// Precondition:	DeckofCards is initialised
			// Postcondition:   returns a string displaying the sequence of cards stored in DeckOfCards
			string value();
			
			// Precondition:	DeckofCards is initialised and a string parameter is passed
			// Postcondition:   If a node with data that matches the search_value is found it 
			// 					is deleted and true (1) is returned. If not found, false (0) is returned
			bool remove(string search_value);
			
		private:
			LinkedList* my_list_;
	};
	
	// FRIEND FUNCTION
	// Precondition:	an initialised DeckOfCards object is passed as a parameter
	// Postcondition:   the content of deck of cards is output in a suitable form for printing
	ostream& operator << (ostream& out, DeckOfCards& card); 
}
#endif