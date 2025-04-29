/*
Program: Rock, Paper, Scissors - Part 3
Programmer: Montavius Spratley Burford
Date: 4/29/2025
Requirments: Revise your original Rock, Paper, Scissors game so that after each completed session save the results in a 
file. Each line should contain the name and the best score of each person that has played the game.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

std::string getComputerChoice() {
    int number = (std::rand() % 3) + 1;
    if (number == 1) return "rock";
    if (number == 2) return "paper";
    return "scissors";
}

std::string getUserChoice() {
    std::string choice;
    std::cout << "Enter rock, paper, or scissors: ";
    std::cin >> choice;
    return choice;
}

void displayChoices(std::string user, std::string computer) {
    std::cout << "You chose: " << user << std::endl;
    std::cout << "Computer chose: " << computer << std::endl;
}

std::string determineWinner(std::string user, std::string computer) {
    if (user == computer) return "tie";
    if ((user == "rock" && computer == "scissors") ||
        (user == "scissors" && computer == "paper") ||
        (user == "paper" && computer == "rock")) {
        return "user";
    }
    return "computer";
}

void showScores() {
    std::ifstream file("scores.txt");
    std::string line;
    std::cout << "\n-- Previous Scores --\n";
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    std::cout << "---------------------\n\n";
}

void deleteScores() {
    std::ofstream file("scores.txt", std::ofstream::trunc);
    file.close();
    std::cout << "Scores deleted.\n\n";
}

void startGameSession() {
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    int winCount = 0;
    std::string playAgain = "yes";

    while (playAgain == "yes") {
        std::string userChoice, computerChoice, winner;

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

    std::ofstream file("scores.txt", std::ios::app);
    file << playerName << " " << winCount << std::endl;
    file.close();

    std::cout << playerName << ", your final score: " << winCount << "\n\n";
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int choice = 0;
    do {
        std::cout << "\n--- Rock Paper Scissors Menu ---\n";
        std::cout << "1. Show previous scores\n";
        std::cout << "2. Start a new game\n";
        std::cout << "3. Delete all scores\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            showScores();
        }
        else if (choice == 2) {
            startGameSession();
        }
        else if (choice == 3) {
            deleteScores();
        }
        else if (choice == 4) {
            std::cout << "Goodbye!\n";
        }
        else {
            std::cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
