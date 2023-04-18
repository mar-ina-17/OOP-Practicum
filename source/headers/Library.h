#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
class Library
{
private:
    std::size_t usedSpace;
    std::size_t capacity;
    std::size_t booksCount;
    Book **books;

    bool ISBNinUse(const char *ISBN) const;
    void copy(const Library &other);

public:
    Library(const std::size_t capacity);
    Library(const Library &other);
    ~Library();

    std::size_t size() const;
    bool empty() const;
    void clear();
    void deallocateBooks();

    void addNewBook(Book &book);
    void removeBook(const char *ISBN);

    const Book *find(const char *ISBN) const;
    const int findAtIndex(const char *ISBN) const;
    const Book &operator[](std::size_t index) const;

    Library &operator=(Library const &other);
    friend std::ostream &operator<<(std::ostream &out, const Library &other);
};
#endif