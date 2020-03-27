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
        if (Input == hiddenWord)
        {
            PrintLine(TEXT("You Win!!!"));
            EndGame();
        }
        else
        {
            if (hiddenWord.Len() != Input.Len())
            {
                PrintLine(TEXT("Hidden word is %i letters! You Lose!"), hiddenWord.Len());
                EndGame();
            }           
        }
    }
}

void UBullCowCartridge::SetUpGame() 
{
    PrintLine(TEXT("Welcome"));

    gameOver = false;
    hiddenWord = TEXT("cakes");
    lives = 3;

    PrintLine(TEXT("Guess the %i letter word"), hiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press Enter to continue ..."));
}

void UBullCowCartridge::EndGame() 
{
    gameOver = true;
    PrintLine(TEXT("Press Enter to play again"));
}