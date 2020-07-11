#include "FCatDog.h"
#define TMap std::map
#include <time.h>

using FText = std::string;

FCatDog::FCatDog()
{
    Reset();
}
// with the length of the word, the count of tries increases
    int32 FCatDog::GetMaxTries() const {
    TMap<int32, int32> WordLengthToMaxTries{ {3, 5}, {4, 7}, {6, 10}, {15, 32}};
    return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FCatDog::Reset()
{    
    srand(time(NULL));

    FString Words_Array[4] = { "goku", "lum", "totoro", "jonathanjoestar" };
    // get a random word from the array
    MyHiddenWord = Words_Array[rand() % 4];

    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}



int32 FCatDog::GetCurrentTry() const {
    return MyCurrentTry;
}

int32 FCatDog::GetHiddenWordLength() const {
    return MyHiddenWord.length();
    
}

bool FCatDog::IsGameWon() const {
    return bGameIsWon;
    
}

bool FCatDog::IsIsogram(FString Word) const
{
    //treat 0 and 1 letter word as isograms
    if (Word.length() <= 1) { return true; }
       
    // iterate through letters to see if any is reapeated. (we don't need this)
    TMap<char, bool> LetterSeen;
    for (auto Letter : Word)
    {
        Letter = tolower(Letter);
            if (LetterSeen[Letter])
            {
                return false;
            }
            else
            {
                LetterSeen[Letter] = true;
            }

    }
    return true;
}

bool FCatDog::IsLowercase(FString String) const 
{   
    // verify if word is in lowercase
    for (auto Letter : String)
    {
        if (!islower(Letter))
        {
            return false;
       }

    }
    return true;

}

EGuessStatus FCatDog::CheckGuessValidity(FString Guess) const
{
  //  if (!IsIsogram(Guess))
  // {
  //     return EGuessStatus::Not_Isogram;
 //  }
    if (!IsLowercase(Guess))
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
}




FCatDogCount FCatDog::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    
    FCatDogCount CatDogCount;
    
        // compare all letters with the word
    int32 HiddenWordLength = MyHiddenWord.length();
    for (int32 i = 0; i < HiddenWordLength; i++) {
        if (Guess[i] == MyHiddenWord[i])
        {
            CatDogCount.Dogs++;
        }
        else
        {  
        for (int32 j = 0; j < HiddenWordLength; j++) {
            if (Guess[i] == MyHiddenWord[j]) {
                    CatDogCount.Cats++;
                }
            }
        }
    }
    
    if (CatDogCount.Dogs == HiddenWordLength) {
        bGameIsWon = true;
    }
    else
    {
        bGameIsWon = false;
    }

    return CatDogCount;
}