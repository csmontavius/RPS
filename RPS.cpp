/*
Program: Rock, Paper, Scissors - Part 2
Programmer: Montavius Spratley Burford
Date: 4/29/2025
Requirments: Revise your original Rock, Paper, Scissors game so that it is repeatable. Using a sentinel value, (doAgain) to
end. On each iteration, the game should accept the name of the player, keep count of how many times they have won.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Function to generate computer's choice
std::string getComputerChoice() {
    int number = (std::rand() % 3) + 1;
    if (number == 1) {
        return "rock";
    }
    else if (number == 2) {
        return "paper";
    }
    else {
        return "scissors";
    }
}

// Function to get user's choice
std::string getUserChoice() {
    std::string choice;
    std::cout << "Enter rock, paper, or scissors: ";
    std::cin >> choice;
    return choice;
}

// Function to display choices
void displayChoices(std::string user, std::string computer) {
    std::cout << "You chose: " << user << std::endl;
    std::cout << "Computer chose: " << computer << std::endl;
}

// Function to determine the winner
std::string determineWinner(std::string user, std::string computer) {
    if (user == computer) {
        return "tie";
    }
    else if (user == "rock" && computer == "scissors") {
        return "user";
    }
    else if (user == "scissors" && computer == "paper") {
        return "user";
    }
    else if (user == "paper" && computer == "rock") {
        return "user";
    }
    else {
        return "computer";
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    int winCount = 0;
    std::string playAgain = "yes";

    while (playAgain == "yes") {
        std::string userChoice;
        std::string computerChoice;
        std::string winner;

        do {
            computerChoice = getComputerChoice();
            userChoice = getUserChoice();

            displayChoices(userChoice, computerChoice);

            winner = determineWinner(userChoice, computerChoice);

            if (winner == "tie") {
                std::cout << "It's a tie! Let's play again.\n\n";
            }

        } while (winner == "tie");

        if (winner == "user") {
            std::cout << playerName << ", you win this round!\n";
            winCount++;
        }
        else {
            std::cout << "Computer wins this round!\n";
        }

        std::cout << "Do you want to play again? (yes/no): ";
        std::cin >> playAgain;
    }

    std::cout << playerName << ", you won " << winCount << " time(s)!\n";
    std::cout << "Thanks for playing!\n";

    return 0;
}
