// This is the class implementation for a deck of cards object
// that uses a linked list
// Programmer:  Jonathan Godley - c3188072
// Course: SENG1120
// Last modified:  08/09/2016

#include "DeckOfCards.h"
#include <string> // provides string class
#include <cstdlib>

using namespace std;
namespace jonathan_deck_of_cards
{
	//CONSTRUCTOR
	//create a deck of cards with data
	DeckOfCards::DeckOfCards()
	{
		// create new linked list object
		LinkedList* new_list_ = new LinkedList;
		// now save it as the private list object
		my_list_ = new_list_;
		// not entirely sure why I had to do this, but it kept de-referencing 
		// without making a new pointer point at it. 		
		
		// generate deck
		// declare strings
		string card;
		string suite;
		
		// loop through all 4 suits
		for(int i=0; i<4; i++)
		{
			if (i == 0){ suite = "S";}
			if (i == 1){ suite = "H";}
			if (i == 2){ suite = "C";}
			if (i == 3){ suite = "D";}
			// loop through all 13 cards in each suite
			for(int ii=0; ii<13; ii++)
			{
				// easier to use "if / else if" rather than trying to convert the int i into a string
				if (ii==0){ card = "2-" + suite;}
				else if (ii==1){ card = "3-" + suite;}	
				else if (ii==2){ card = "4-" + suite;}	
				else if (ii==3){ card = "5-" + suite;}	
				else if (ii==4){ card = "6-" + suite;}
				else if (ii==5){ card = "7-" + suite;}	
				else if (ii==6){ card = "8-" + suite;}	
				else if (ii==7){ card = "9-" + suite;}	
				else if (ii==8){ card = "10-" + suite;}
				else if (ii==9){ card = "J-" + suite;}	
				else if (ii==10){ card = "Q-" + suite;}	
				else if (ii==11){ card = "K-" + suite;}	
				else if (ii==12){ card = "A-" + suite;}
				// add to list
				my_list_->add_to_tail(card);
			}
		}
	}
	//DESTRUCTOR
	// manually call destructor on linked list, before deleting and de-referencing the linked list object
	DeckOfCards::~DeckOfCards()
	{
		delete my_list_;
		my_list_ = NULL;

	} 
	void DeckOfCards::shuffle()
	{
		// shuffle
		// -- To shuffle an array a of n elements (indices 0..n-1):
		// for i from n−1 downto 1 do
		int j;
		// using i>-1 
		for(int i = (my_list_->size()-1); i>-1; i--){
			// j ← random integer such that 0 ≤ j ≤ i
			// j = (rand() % (i)) = between 0 and i-1, adding 1 to i means it's between 0 and i 
			j = (rand() % (i+1));
			// exchange a[j] and a[i]
			my_list_->swap(j,i);
		}	
		

	}
	int DeckOfCards::length()
	{
		return my_list_->size();
	}
	bool DeckOfCards::empty()
	{
		// create an empty boolean
		bool empty;
		// check size of list
		if(my_list_->size()>=1){
			// if list is size 1 or larger than it's not empty
			empty = false;
		}
		else{
			empty = true;
		}
		// reminder false = 0
		return empty;
	}
	int DeckOfCards::position(string search_value)
	{
		// loop through entire linked list, find data that matches with the search_value,
		// 		then return the position in the list with the first occurence of the input
 		//		input parameter, -1 if the card is not in the deck. 
		
		// reset to beginning of list
		my_list_->move_to_head();
		// use unsigned int to avoid comparison between signed and unsigned integer expressions
		for(unsigned int i=0; i<my_list_->size(); i++){
			// if search mateches node data return it's location
			if(search_value==my_list_->get_current()){
				return i;
			}
			// if not found move to next node
			my_list_->forward();
		}		
		// if not found return -1
		return -1;
	}
	string DeckOfCards::value()
	{		
		// make sure we start at head of list
		my_list_->move_to_head();
		
		// create a string to hold our list
		string value;
				
		// combine the list into one string
		// use unsigned int to avoid comparison between signed and unsigned integer expressions
		for(unsigned int i=0; i<my_list_->size(); i++){
			// append each piece of data to our string
			value = value + my_list_->get_current() + " ";
			my_list_->forward();
		}	
		// returns a string displaying rthe sequence of cards
		return value;
	}
	bool DeckOfCards::remove(string search_value)
	{
		// remove node with data matching the parameter search_value from the list

		// reset to beginning of list
		my_list_->move_to_head();
		
		// loop through until we find search term
		// use unsigned int to avoid comparison between signed and unsigned integer expressions
		for(unsigned int i=0; i<my_list_->size(); i++){
			if(search_value==my_list_->get_current()){
				// if search mateches node data remove the currently selected node
				my_list_->remove_current();
				// if deleted, return true
				return true;
			}
			// if not found move to next node
			my_list_->forward();
		}		
		// if not found & deleted return false
		return false;
	}
	ostream& operator << (ostream& out, DeckOfCards& card)
	{
		// overloaded << so that it outputs the card.value() string when called
		
		out << card.value();
		return out;
	}
}