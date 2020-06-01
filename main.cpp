#include <iostream>
#include <fstream> //file stuff
#include <string>
#include <stdlib.h>   //srand and rand
#include <time.h> //time
#include "board.hpp"
#include "guess.hpp"
#include "emptyboard.hpp"
#include "man.hpp"
#include "fullboard.hpp"
#include <algorithm>

using namespace std;

//chooses random word from test file based on the category chosen by user
string chooseword() { 
    std::string choice;
    std::cout << "Please choose a Category: Harry | CS | Fruit" << std::endl;
    std::cin >> choice;
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
    while (choice != "harry" && choice != "cs" && choice != "fruit") {
        std::cout << "Please choose a Category: Harry Potter | CS" << std::endl;
        std::cin>>choice;
    }
    
    //opening correct file for category
    std::ifstream myfile;
    if(choice == "harry") {
        myfile.open("HarryPotter.txt");
    }
    else if (choice == "cs") {
        myfile.open("CS.txt");
    }
    else if (choice == "fruit") {
        myfile.open("food.txt");
    }
    if(!myfile.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        std::exit(1);
    }  
   
    
    //generating rand number to choose word
    int number = 0;
    std::string line;
    while (std::getline(myfile, line)) {
        ++number;
    }
    
    myfile.clear();
    myfile.seekg(0, ios::beg);
    
    int wordnum = 0;
    srand(time(NULL));
    wordnum = rand() % number + 1;
    
    //retrieving word from file
    std::string word;
    for(int i = 0; i <= wordnum; i++) {
        getline(myfile,word);
    }
    
    myfile.close();
    return word;
    
}

int main(){
    
    std::cout << "This is a HANGMAN game. Guess the word before the man is fully drawn." <<std::endl;
   
    std::string word = chooseword(); //retrieving word
    transform(word.begin(), word.end(), word.begin(), ::tolower); //casting to lowercase
    
    emptyboard* newboard = new emptyboard(word); //creates empty board with blanks based on word
    newboard->draw_board();
 
    std::string userguess;
    std::cout << "Guess: " <<std::endl;
    std::cin >> userguess;
    
    std::vector<std::string> holding = newboard->returnvec(); //storing guess as vec 
    fullboard* newboard2 = new fullboard(word, userguess, holding); 
    Man* newman = new Man();
    
    int count = 0; // to count wrong guesses	
    
    Guess* newguess = new Guess(word, userguess); 
    if(newguess->guess_correct() == true){
        newboard2->draw_board(); //adds quess to baord if correct
    }
    else{
        newman->draw();  //draws part of man if incorrect
     	newboard2->draw_board();
	count++;
    }
    
    holding = newboard2->returnvec(); 
    bool done = false;
 
    //checsk guesses until game is won, or man is fully drawn   
    while(done == false){
        std::cout << "  Guess: " << std::endl;
        std::cin >>userguess;
        transform(userguess.begin(), userguess.end(), userguess.begin(), ::tolower);
        
        
        Guess* newguess2 = new Guess(word, userguess);
        fullboard* newboard3 = new fullboard(word, userguess, holding);
        if(newguess2->guess_correct() == true){
            newboard3->draw_board();
        }
        else{
        
            newman->draw();
            newboard3->draw_board();
	    count++;
        }
        holding = newboard3->returnvec();
        
        if(count == 6) { //checking if man is fully drawn, lose if yes
            std::cout << endl;
            std::cout << "The word was " << word << endl;
            std::cout << "You lost :( Play Again Later!" << endl;
            return 0;
        }
        
        done = true;
        for(int j = 0; j <holding.size(); j++) { //checking for game being won; yes if no more blanks
            if(holding.at(j) == " _ "){
                done = false;
            }
        }
        
        if(done == true){
            std::cout << std::endl << "You won!" << std::endl;
        }
    }
}


