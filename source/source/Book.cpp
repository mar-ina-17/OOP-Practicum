#include "../headers/Book.h"

Book::Book(const char *ISBN, const char *title, const char *author, std::size_t space)
    : ISBN(ISBN), title(title), author(author), space(space) {}

Book::Book(MyString &ISBN, MyString &title, MyString &author, std::size_t space)
    : ISBN(ISBN), title(title), author(author), space(space) {}

Book::Book(const Book &other)
{
    this->ISBN = other.ISBN;
    this->title = other.title;
    this->author = other.author;
    this->title = other.title;
    this->space = other.space;
}
Book::~Book()
{
    this->ISBN.clear();
    this->author.clear();
    this->title.clear();
    this->space = 0;
}
void Book::free()
{
    this->title.clear();
    this->author.clear();
    this->ISBN.clear();
    this->space = 0;
}
void Book::destroy()
{
    if (this)
    {
        this->destroy();
    }
}
void Book::copyBook(Book const &other)
{

    this->title = MyString(other.title);
    this->author = MyString(other.author);
    this->ISBN = MyString(other.ISBN);
    this->space = other.space;
}

const char *Book::getISBN() const
{
    return this->ISBN.c_str();
}
const char *Book::getTitle() const
{
    return this->title.c_str();
}
const char *Book::getAuthor() const
{
    return this->author.c_str();
}
std::size_t Book::getSpace() const
{
    return this->space;
}

Book &Book::operator=(Book const &other)
{

    if (this != &other)
    {
        this->free();
        this->copyBook(other);
    }

    return *this;
}
std::ostream &operator<<(std::ostream &out, const Book &other)
{
    out << "Title: " << other.getTitle() << std::endl;
    out << "Author: " << other.getAuthor() << std::endl;
    out << "ISBN: " << other.getISBN() << std::endl;

    return out;
}
