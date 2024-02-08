#include <ctime>
#include <iostream>
#include <vector>
#include <string>

void getUserInput(const char *message, int &value);
void getComputerInput(int &value);
void printOptions(const std::vector<std::string> &options);
int getRandomIntBetween(int min, int max);
void conclusion(int &userInput, int &computerInput);
void showEachInput(const int &userInput, const int &computerInput, const std::vector<std::string> &options);

int main(int argc, char const *argv[])
{
    int userInput, computerInput;
    const std::vector<std::string> options = {
        "1. rock",
        "2. paper",
        "3. scissor",
    };

    printOptions(options);
    getUserInput("You Choose: ", userInput);
    getComputerInput(computerInput);

    showEachInput(userInput, computerInput, options);

    conclusion(userInput, computerInput);

    return 0;
}
void showEachInput(const int &userInput, const int &computerInput, const std::vector<std::string> &options)
{
    std::cout << "Your: " << options[userInput - 1] << std::endl;
    std::cout << "Computer: " << options[computerInput - 1] << std::endl;
}

void conclusion(int &userInput, int &computerInput)
{
    const char *drawMessage = "Draw!";
    const char *winMessage = "You Win!";
    const char *loseMessage = "Computer Win!";

    if (userInput == computerInput)
    {
        std::cout << drawMessage << std::endl;

        return;
    }

    if (userInput > computerInput)
    {
        std::cout << winMessage << std::endl;

        return;
    }

    std::cout << loseMessage << std::endl;
}

void getUserInput(const char *message, int &value)
{
    std::cout << message;
    std::cin >> value;
    std::cout << std::endl;
}

void getComputerInput(int &value)
{
    value = getRandomIntBetween(1, 3);
}

int getRandomIntBetween(int min, int max)
{
    std::srand(std::time(0));

    return (std::rand() % max) + min;
}

void printOptions(const std::vector<std::string> &options)
{
    for (int i = 0; i < options.size(); i++)
    {
        std::cout << options[i] << std::endl;
    }
}