#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "MyString.h"
class Book
{
private:
    MyString ISBN;
    MyString title;
    MyString author;
    std::size_t space;

    void free();
    void destroy();
    void copyBook(Book const &other);

public:
    Book(MyString &ISBN, MyString &title, MyString &author, std::size_t space);
    Book(const char *ISBN, const char *title, const char *author, std::size_t space);
    Book(const Book &other);
    ~Book();

    const char *getISBN() const;
    const char *getTitle() const;
    const char *getAuthor() const;
    std::size_t getSpace() const;

    Book &operator=(Book const &other);
    friend std::ostream &operator<<(std::ostream &out, const Book &other);
};
#endif