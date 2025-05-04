// simple dnd dice roller for your needs.
#include <iostream>
#include <algorithm>
#include <ctime>

int main()
{
    using string = std::string;
    srand(time(NULL));
    
    int diceType;
    int result;
    int diceTypes[] = { 4, 6, 8, 10, 12, 20, 100 };
    int n = sizeof(diceTypes) / sizeof(diceTypes[0]); // gives us the number of elements in the raw array by pointing the size of the full raw array at bites we know that a single index is 4 bytes so our array is 28 bytes and the first index will be 4 bytes that means dividing the total by a single index gives us the number of the elements in this array. 28 / 4 = 7.
    
    std::cout << "************ - DICE ROLLER - ************\n";

    std::cout << "Enter your dice type in numbers [4, 6, 8, 10, 12, 20, 100]: ";
    std::cin >> diceType;
    
    if (std::find(diceTypes, diceTypes + n, diceType) == diceTypes + n) // look for the valid dice type from the first element of array to the last as it looks inclusive at first index but exclusive at last index [indexOne, indexTwo) so it does not reaches + n and + n actually gives us the last index of the array + 1 and if std::find function is equal to it, it means that the number is outside of this array so we write it is invalid. diceTypes => diceTypes + n
    {
        std::cout << "Invalid dice type.\n";
        std::cout << "Press a key to exit.\n";
        std::cout << "*********** - madeby barlas - ***********";
        
        std::cin.ignore();
        std::cin.get();
        return 1;
    }
    else if (diceType == 100)
    {
        result = ((rand() % diceType) / 10) * 10;
        std::cout << "The result is: " << '%' << result << '\n';
    }
    else if (diceType == 10)
    {
        result = rand() % diceType;
        std::cout << "The result is: " << result << '\n';
    }
    else
    {
        result = (rand() % diceType) + 1;
        std::cout << "The result is: " << result << '\n';
    }
    std::cout << "Press enter key to exit.\n";
    std::cout << "*********** - madeby barlas - ***********";
    
    std::cin.ignore();
    std::cin.get();
    return 0;
}