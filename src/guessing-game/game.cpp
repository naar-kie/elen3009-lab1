/**
 * @file main.cpp
 * @author Naar-Kie (numbat24.04)
 * @brief Lab 1 - Exercise 2.1 Guessing Game
 * @version 3.0
 * @date 2024-07-27
 * 
 * 
 */

#include<iostream>
#include<cstdlib>
#include <time.h>

int main(int arg, char **argv){
    
    srand(time(0));
    std::cout << "Guess a random number between 1 and 100:" << std::endl;
    int n = 0, c = 0, t = 0; // n-input; c-correctAnswer; t-trials
    c = rand() % 101;
    std::cin >> n;
    std::cout << "note the value of C is " << c << std::endl; // delete this test line, lol

    while(n != c && t <5){
        t++;
        if(n<c){
            std::cout<< "Guess higher" << std::endl;
            std::cin >> n;
        }
        else if(n>c){
            std::cout << "Guess lower" << std::endl;
            std::cin >> n;
        }
        else
            break;
    }

    if(n == c){
        std::cout << "You win" << std::endl;
    }
    else
        std::cout << "You lose" <<std::endl;

    return 0;
}