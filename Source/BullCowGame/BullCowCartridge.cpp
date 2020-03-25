// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome"));
    PrintLine(TEXT("Guess the 4 letter word"));
    PrintLine(TEXT("Press Enter to continue ..."));
    hiddenWord = TEXT("cake");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (Input == hiddenWord) 
    {
        PrintLine(TEXT("You Win!!!"));
    }
    else 
    {
        PrintLine(TEXT("You Lose!!!"));
    }
}