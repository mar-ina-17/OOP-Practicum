#include <iostream>
#include <cstring>
#include "../headers/LibraryCollection.h"

void intro(std::size_t &size)
{
    std::cout << "-------------- Welcome to LibraryCollection program ---------------\n";
    std::cout << "Let's create your Library collection, you need to tell me what is the amount of libraries you want to have: ";
    std::cin >> size;
    std::cout << "Thank you, now you should provide every library with a capacity, then you can continue with the options on the menu...\n";
}

void menuInfo()
{
    std::cout << "---------------- M E N U ----------------\n";
    std::cout << "0) help\n";
    std::cout << "1) Choose a library by providing its index\n";
    std::cout << "2) Add a book to library\n";
    std::cout << "3) Remove a book from library\n";
    std::cout << "4) Clear library\n";
    std::cout << "5) Print library\n";
    std::cout << "6) EXIT\n";
}

void inputIndexOfLib(LibraryCollection &c, std::size_t &index)
{
    do
    {
        std::cout << "Please, enter the index of the library you want to access (indexes must be between 0 and " << c.size() - 1 << ")" << std::endl;
        std::cin >> index;
    } while (index < 0 || index >= c.size());
}

int main()
{
    std::size_t sizeOfCollection = 0, key = 1, indexOfLibrary = 0;
    intro(sizeOfCollection);
    LibraryCollection collection(sizeOfCollection);
    menuInfo();
    inputIndexOfLib(collection, indexOfLibrary);

    while (key < 6 && key >= 0)
    {
        std::cout << "Please, enter an option from the menu: ";
        std::cin >> key;
        switch (key)
        {
        case 0:
            menuInfo();
            break;
        case 1:
            inputIndexOfLib(collection, indexOfLibrary);
            break;
        case 2:
        {
            std::cout << "~~~~ You are currently operating with library with index:" << indexOfLibrary << " ~~~~" << std::endl;
            collection.addBook(collection[indexOfLibrary]);
            break;
        }
        case 3:
        {
            std::cout << "~~~~ You are currently operating with library with index: " << indexOfLibrary << " ~~~~" << std::endl;
            MyString isbn = MyString();
            std::cout << "Please, enter the ISBN of the book you want to be removed: ";
            std::cin.ignore();
            std::cin >> isbn;
            collection.removeBook(collection[indexOfLibrary], isbn.c_str());
            break;
        }

        case 4:
        {
            std::cout << "~~~~ Library with index " << indexOfLibrary << " is being cleared..." << std::endl;
            collection.clearLibrary(indexOfLibrary);

            break;
        }
        case 5:
        {
            std::cout << "~~~~ Library with index " << indexOfLibrary << " printing..." << std::endl;
            std::cout << collection[indexOfLibrary];
            break;
        }
        default:
            std::cout << "Please, select an option from the menu\n";
        }
    }

    return 0;
}