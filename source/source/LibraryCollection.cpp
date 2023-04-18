#include "../headers/LibraryCollection.h"
#include <cstring>
#include <cassert>

LibraryCollection::LibraryCollection(std::size_t capacity)
{
    this->count = capacity;
    this->libraries = createCollection(capacity);

    std::cout << "Library collection is now created!" << std::endl;
}
LibraryCollection::LibraryCollection(const LibraryCollection &other)
{
    this->count = other.count;
    for (std::size_t i = 0; i < this->count; i++)
    {
        this->libraries[i] = other.libraries[i];
    }
}
LibraryCollection::~LibraryCollection()
{
    this->deallocateLibrary();
}
void LibraryCollection::deallocateLibrary()
{
    for (std::size_t i = 0; i < this->count; ++i)
    {
        this->libraries[i]->deallocateBooks();
    }
    delete[] this->libraries;
}
bool LibraryCollection::empty() const
{
    return this->count == 0;
}
void LibraryCollection::copy(const LibraryCollection &other)
{
    Library **buffer = new Library *[other.count];
    if (buffer)
    {
        for (std::size_t i = 0; i < other.count; i++)
        {
            buffer[i] = other.libraries[i];
        }
        this->libraries = buffer;
        this->count = other.count;
    }
    else
    {
        std::cout << "Failed to copy library!" << std::endl;
        return;
    }
}
const std::size_t LibraryCollection::size() const
{
    return this->count;
}

Library **LibraryCollection::createCollection(const std::size_t count)
{
    Library **buff = new Library *[count];
    if (buff)
    {
        for (std::size_t i = 0; i < count; ++i)
        {
            std::size_t librarySize;
            std::cout << "Please, input current library size: ";
            std::cin >> librarySize;
            buff[i] = new Library(librarySize);
        }
    }
    else
    {
        std::cout << "Collection not created" << std::endl;
        return nullptr;
    }
    return buff;
}
LibraryCollection &LibraryCollection::operator=(LibraryCollection const &other)
{

    if (this != &other)
    {

        this->clear();
        this->copy(other);
    }

    return *this;
}
void LibraryCollection::clear()
{
    for (std::size_t i = 0; i < this->count; i++)
    {
        this->libraries[i]->clear();
    }
}
void LibraryCollection::clearLibrary(const std::size_t i)
{
    if (this->libraries[i]->empty())
    {
        std::cout << "Library is empty already!" << std::endl;
        return;
    }
    this->libraries[i]->clear();
}
const Library &LibraryCollection::operator[](std::size_t index) const
{
    assert(index < this->count);
    return *(this->libraries[index]);
}
void LibraryCollection::addBook(Library &other)
{
    std::cout << "-----Please, enter book info----" << std::endl;
    MyString buffAuthor = MyString();
    MyString buffTitle = MyString();
    MyString buffISBN = MyString();
    std::size_t space = 0;

    while (space <= 0)
    {
        std::cout << "Book space: ";
        std::cin >> space;
    }
    std::cin.ignore();
    std::cout << "Book author: ";
    std::cin >> buffAuthor;
    std::cout << "Book title: ";
    std::cin >> buffTitle;
    std::cout << "Book ISBN: ";
    std::cin >> buffISBN;

    Book book = Book(buffISBN, buffAuthor, buffTitle, space);
    other.addNewBook(book);
}
void LibraryCollection::removeBook(Library &other, const char *isbn)
{
    if (!other.empty())
    {
        other.removeBook(isbn);
    }
    else
    {
        std::cout << "This library is empty! You can't remove a book from it!" << std::endl;
    }
}

Library &LibraryCollection::operator[](std::size_t index)
{
    assert(index < this->count);
    return *(this->libraries[index]);
}

std::ostream &operator<<(std::ostream &out, const LibraryCollection &other)
{
    std::cout << "Printing library collection... ";
    for (std::size_t i = 0; i < other.count; ++i)
    {
        out << std::endl;
        out << "Library " << i + 1 << ": " << std::endl;
        out << *(other.libraries[i]);
    }
    return out;
}
