/*
This is a simple guess game based on Mastermind where you have to guess the anime character.
Thanks to https://ascii.co.uk/ for sharing all the great ASCII art.
*/

#ifndef __CatDog_Game
#define __CatDog_Game
#include <iostream>
#include <string>
#include <map>

using FString = std::string;
using int32 = int;

struct FCatDogCount
{
    int32 Dogs = 0;
    int32 Cats = 0;
    
};

enum class EGuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Not_Lowercase,
    Wrong_Length
};


class FCatDog {
public:
    FCatDog();

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    
    EGuessStatus CheckGuessValidity(FString) const;
    FString MyHiddenWord;

    bool IsGameWon() const;
    
    void Reset();
    FCatDogCount SubmitValidGuess(FString);
    
    
private:
    int32 MyCurrentTry = 1;
    bool bGameIsWon;
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;  
};





#endif
