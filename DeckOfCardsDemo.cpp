// This program creates an instance of an deck of cards object
// 		and performs operations on it, including a shuffle 
// 		using a random number generator seeded by command line arguments
//
// Programmer:  Jonathan Godley - c3188072 
// Course: SENG1120
// ASSIGNMENT 1
// Last modified:  09/09/2016

#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"

using namespace std;
using namespace jonathan_deck_of_cards;
 
int main(int argc, char* argv[]) {
	// argc = the number of arguments provided to the main function (this includes the program name itself)
	// argv = an array of strings containing each of the arguments

	// Make sure we have at least two arguments
    // The first argument will be the program name e.g. myCode.exe
    // The second argument will be the seed for the random number generator
    if (argc >= 2) {
        // Use atoi (ascii to integer) to convert our argument to a number
        // note that if the user enters an invalid number this will be 0
        int seed = atoi(argv[1]);

        // Use that number to seed the random number generator
        srand(seed);
    }
    // If we don't have at least two arguments seed the random number generator using the current time
    else {
        // Get the current time as an integer
        int seed = time(NULL);

        // Use that number to seed the random number generator
        srand(seed);
    }

	// create new instance of DeckOfCards storing a full deck of cards
	DeckOfCards* my_deck = new DeckOfCards();
	
	// Print the deck of cards using value(). The card values have to be
	// separated by a single blank space, all in the same line. 
	cout << my_deck->value() << endl;
	
	// Shuffle the deck of cards using shuffle()
	my_deck->shuffle();
	
	// Print the deck of cards again using cout << 
	// *my_deck de-references so it can be passed
	cout << *my_deck << endl; 
	
	// Print the position of cards “4-H”, “10-S”, “Q-C” and “A-D”, separated by a
	//single blank space, all in the same line. 
	cout << my_deck->position("4-H") << " " << my_deck->position("10-S") <<
		" " << my_deck->position("Q-C") << " " << my_deck->position("A-D") << endl;
	
	// Print the total number of cards in DeckOfCards using length()
	cout << my_deck->length() << endl;
	
	// Remove the cards “4-H” and “10-S” 
	my_deck->remove("4-H");
	my_deck->remove("10-S");
	
	// Print the position of cards “4-H”, “10-S”, “Q-C” and “A-D” again 
	cout << my_deck->position("4-H") << " " << my_deck->position("10-S") << " " << my_deck->position("Q-C") << " " << my_deck->position("A-D") << endl;
	
	// Print the total number of cards in DeckOfCards using length()
	cout << my_deck->length() << endl;
	
	// delete my_deck now that we're done with it, to avoid memory leaks
	delete my_deck;
		
	return EXIT_SUCCESS;
}