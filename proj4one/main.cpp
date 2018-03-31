/*  Program:     Hangman game as project 4
 Authors:     T. Vo and your name
 Class:	     CSCI 110
 Date:	     11/14
 Description: Implement a variation of the classic word game Hangman.
 
 I certify that the code below is my own work.
 
	Exception(s): N/A
 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

const int MAX_NUMS = 200;   // Constant for the maximum number of words.
const int MAX_GUESSES = 8;

// not used, I couldn't figure out what to do with it
const string LETTERS = "abcdefghijklmnopqrstuvwxyz";


char   inputLetter();
int    findChar(char letter, string word);
string getGuessedWord(string secretWord, string lettersGuessed);


int main()
{
    string oneWord;					// holds one word from input file
    string secretWord;				// holds secret word to be guessed
    string words[MAX_NUMS];			// holds list of words from input file
    // not used
    // int randomValue;				// holds index of secret word
    int count = 0;					// holds number of words in the file
    
    srand(static_cast<unsigned int>(time(0)));
    
    // Declare an ifstream object named myFile and open an input file
    ifstream myFile;
    myFile.open("P4Words.txt");
    
    // Exit program if cannot open file for input
    if (!myFile)
    {
        cout << "Error: Unable to open file for input" << endl;
        return 0;
    }
    
    // Add your code here ...
    
    myFile >> oneWord;
    while (!myFile.eof())
    {
        // *** Add code below to store one word in the array.
        words[count] = oneWord;
        
        // Read a number from the file.
        myFile >> oneWord;
        count++;
        
        
    }
    
    cout << "Loading word list from a file... " << endl;
    cout << count << " words loaded." << endl;
    
    // Select a secret word
    // Add your code here ...
    secretWord = words[rand() % count + 1];
    
    // check only -- remove later
    // cout << "(remove later) Random word: " << secretWord << endl;
    
    // Possible useful variables the loop
    
    string lettersGuessed = "";	// holds letters guessed so far
    
    string wordGuessed;			// holds current word guessed like ì_ pp_ eî
    
    
    // int incorrectGuesses = 0;	// holds number of incorrect guesses so far
    // used counter instead
    
    char letter;// holds a guessed letter
    
    bool done = false;			// have not guessed the word yet
    
    cout << "Welcome to the game, Hangman V1 by Miguel Bravo!" << endl;
    cout << "I am thinking of a word that is " << secretWord.length()
    << " letters long." << endl;
    
    // Set up a loop to input guesses and process
    // Add your code here ...
    
    int guessCounter = MAX_GUESSES;
    
    while(!done &&  guessCounter > 0){
        
        while(!done &&  guessCounter > 0){
            
            cout << "---------------------------------------------------" << endl;
            cout << "You have " << guessCounter << " guesses left."<< endl;
            
            
            cout << "Letters guessed so far: ";
            cout << lettersGuessed << endl;
            
            letter = inputLetter();
            
            int temp1 = findChar(letter, lettersGuessed);
            
            if(temp1!=-1){
                cout  << "Oops! You've already guessed that letter: " << endl;
                guessCounter--;
            }else{
                lettersGuessed += letter;
                
                int temp2 = findChar(letter, secretWord);
                
                if(temp2!=-1){
                    cout  << "Good guess: ";
                }else{
                    cout  << "Oops! That letter is not in my word: ";
                    guessCounter--;
                }
            }
            
            wordGuessed = getGuessedWord(secretWord, lettersGuessed);
            
            cout << wordGuessed << endl;
            
            
            if(wordGuessed == secretWord){
                
                cout << "Congraulations, you won!" << endl;
                done = true;
            }
        
        }
        
        if(wordGuessed != secretWord){
            cout << "Sorry, you ran out of guesses. The word was " << secretWord << "." << endl;
            done = true;
        }
        
        
    }
    
    // Add your code here ...
    
    // for Mac
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    //system("pause");	// stop program from closing, Windows OS only
    
    return 0;
}



// Add function definitions here ...


int findChar(char letter, string word){
    
    bool found = false;
    
    if(!found){
        
        for(int i = 0; i < word.length(); i++){
            
            if(word[i] == letter){
                found = true;
                return i;
            }
            
        }
        
    }
    
    return -1;
    
}


char inputLetter(){
    
    char userInput = ' ';
    
    cout << "Please guess a letter: ";
    cin >> userInput;
    
    while(userInput < 'a' || userInput > 'z'){
        
        cout << "Input error. Enter letter from lowercase a to lowercase z. " << endl;
        cout << "Please guess a letter: ";
        cin >> userInput;
    }
    
    return userInput;
    
}


string getGuessedWord(string secretWord, string lettersGuessed){
    
    string str = "";
    
    for(int i = 0; i < secretWord.length(); i++){
        
        int x = findChar(secretWord[i], lettersGuessed);
        
        if(x!=-1){
            
            str += secretWord[i];
        }else{
            
            str += " _ ";
        }
    
    }
    
    return str;
    
}








