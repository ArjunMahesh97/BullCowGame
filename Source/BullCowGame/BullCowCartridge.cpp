// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetUpGame();

    PrintLine(TEXT("The hidden word is : %s. It is %i characters long"), *hiddenWord, hiddenWord.Len());
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (gameOver == true) 
    {
        ClearScreen();
        SetUpGame();
    }
    else 
    {        
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if (Guess == hiddenWord)
    {
        PrintLine(TEXT("You Win!!!"));
        EndGame();
        return;
    }

    if (hiddenWord.Len() != Guess.Len())
    {
        PrintLine(TEXT("The hidden word is %i letetrs long"), hiddenWord.Len());
        PrintLine(TEXT("Try again! You have %i lives remaining"), lives);
        return;
    }

    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters! Try again!"));
        return;
    }

    PrintLine(TEXT("You have lost a life"));

    if (--lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left"));
        PrintLine(TEXT("The hidden word is : %s"), *hiddenWord);
        EndGame();
        return;
    }

    PrintLine(TEXT("Guess again! You have %i lives remaining"), lives);
    
}

void UBullCowCartridge::SetUpGame() 
{
    PrintLine(TEXT("Welcome"));

    gameOver = false;
    hiddenWord = TEXT("cakes");
    lives = hiddenWord.Len();

    PrintLine(TEXT("Guess the %i letter word"), hiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), lives);
    PrintLine(TEXT("Type in your guess and press Enter to continue ..."));
}

void UBullCowCartridge::EndGame() 
{
    gameOver = true;
    PrintLine(TEXT("Press Enter to play again"));
}

bool UBullCowCartridge::IsIsogram(FString word) const
{
    return true;
}