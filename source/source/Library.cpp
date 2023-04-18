#include "../headers/Library.h"
#include <cstring>
#include <cassert>

Library::Library(const std::size_t capacity)
{
    this->capacity = capacity;
    this->usedSpace = 0;
    this->booksCount = 0;
    this->books = new Book *[capacity];

    for (std::size_t i = 0; i < this->capacity; ++i)
    {
        this->books[i] = nullptr;
    }

    std::cout << "Your library has been created successfully!" << std::endl;
}
Library::Library(const Library &other)
{
    this->copy(other);
}
Library::~Library()
{
    this->deallocateBooks();
}

std::size_t Library::size() const
{
    return this->usedSpace;
}
void Library::clear()
{
    for (std::size_t i = 0; i < this->capacity; ++i)
    {
        this->books[i] = nullptr;
    }

    this->booksCount = 0;
    this->usedSpace = 0;

    std::cout << "Library is now cleared!" << std::endl;
}
void Library::deallocateBooks()
{
    for (std::size_t i = 0; i < this->capacity; ++i)
    {
        this->books[i] = nullptr;
    }
    delete[] this->books;
}
bool Library::empty() const
{
    return !this->capacity && !this->booksCount;
}
bool Library::ISBNinUse(const char *isbn) const
{
    if (this->find(isbn))
    {
        std::cout << "Sorry, book with ISBN:" << isbn << "is already in the book list." << std::endl;
        return true;
    }
    return false;
}
void Library::copy(const Library &other)
{
    Book **buffer = new Book *[other.capacity];
    if (buffer)
    {
        for (std::size_t i = 0; i < other.capacity; ++i)
        {
            buffer[i] = other.books[i];
        }

        this->books = buffer;
        this->capacity = other.capacity;
        this->usedSpace = other.usedSpace;
        this->booksCount = other.booksCount;
    }
    else
    {
        std::cout << "Failed to copy library!" << std::endl;
        return;
    }
}

const Book *Library::find(const char *isbn) const
{
    for (std::size_t i = 0; i < this->booksCount; ++i)
    {
        if (strcmp(this->books[i]->getISBN(), isbn) == 0)
            return this->books[i];
    }
    return nullptr;
}
const int Library::findAtIndex(const char *ISBN) const
{
    for (std::size_t i = 0; i < this->booksCount; ++i)
    {
        if (strcmp(this->books[i]->getISBN(), ISBN) == 0)
            return i;
    }
    return -1;
}

void Library::addNewBook(Book &book)
{
    try
    {
        if (!this->ISBNinUse(book.getISBN()))
        {
            const std::size_t remaining = this->capacity - this->usedSpace;
            const std::size_t bookSpace = book.getSpace();
            if (bookSpace <= remaining)
            {
                this->books[this->booksCount++] = new Book(book);
                this->usedSpace += book.getSpace();
            }
            else
            {
                throw(bookSpace);
            }
        }
    }
    catch (const std::size_t bs)
    {
        std::cout << "New book " << book.getTitle() << " can't be added, because book's space is " << bs << " and available space is " << this->capacity - this->usedSpace << std::endl;
    }
}
void Library::removeBook(const char *ISBN)
{
    try
    {
        int foundIndex = this->findAtIndex(ISBN);
        if (foundIndex > -1)
        {
            this->usedSpace -= this->books[foundIndex]->getSpace();

            this->books[foundIndex] = this->books[this->booksCount - 1];
            this->books[this->booksCount - 1] = nullptr;
            this->booksCount--;
            std::cout << "Book with ISBN: " << ISBN << " was successfully removed!" << std::endl;
        }
        else
        {
            throw(ISBN);
        }
    }
    catch (const char *ISBN)
    {
        std::cout << "No book with ISBN: " << ISBN << std::endl;
    }
}

const Book &Library::operator[](std::size_t index) const
{
    assert(index < this->booksCount);
    return *(this->books[index]);
}

Library &Library::operator=(Library const &other)
{

    if (this != &other)
    {

        this->clear();
        this->copy(other);
    }

    return *this;
}
std::ostream &operator<<(std::ostream &out, const Library &other)
{
    for (std::size_t i = 0; i < other.booksCount; ++i)
    {
        out << std::endl;
        out << "Book " << i + 1 << ": " << std::endl;
        out << *(other.books[i]);
    }
    return out;
}
