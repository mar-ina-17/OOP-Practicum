#define CATCH_CONFIG_MAIN
#include <cstring>

#include "catch2/catch2.hpp"
#include "../headers/Book.h"
#include "../headers/MyString.h"

TEST_CASE("Test Constructors")
{
    SECTION("Constructor with params")
    {
        SECTION("MyString params")
        {
            MyString title = MyString("IT");
            MyString author("Steven King");
            MyString ISBN("ISBN123");
            std::size_t space = 2;
            Book book(ISBN, title, author, space);

            REQUIRE(book.getSpace() == 2);
            REQUIRE(strcmp(book.getISBN(), "ISBN123") == 0);
            REQUIRE(strcmp(book.getAuthor(), "Steven King") == 0);
            REQUIRE(strcmp(book.getTitle(), "IT") == 0);
        }

        SECTION("char* param")
        {
            Book book("ISBN123", "IT", "Steven King", 2);

            REQUIRE(book.getSpace() == 2);
            REQUIRE(strcmp(book.getISBN(), "ISBN123") == 0);
            REQUIRE(strcmp(book.getAuthor(), "Steven King") == 0);
            REQUIRE(strcmp(book.getTitle(), "IT") == 0);
        }
    }

    SECTION("Copy constructor")
    {
        Book book("ISBN123", "IT", "Steven King", 2);
        Book bookCopy(book);

        REQUIRE(strcmp(book.getISBN(), bookCopy.getISBN()) == 0);
        REQUIRE(strcmp(book.getAuthor(), bookCopy.getAuthor()) == 0);
        REQUIRE(strcmp(book.getTitle(), bookCopy.getTitle()) == 0);
        REQUIRE(book.getSpace() == bookCopy.getSpace());
    }
}

TEST_CASE("test getters")
{
    SECTION("getSpace()")
    {
        Book book("ISBN123", "IT", "Steven King", 2);
        REQUIRE(book.getSpace() == 2);
    }
    SECTION("getISBN()")
    {
        Book book("ISBN123", "IT", "Steven King", 2);
        REQUIRE(strcmp(book.getISBN(), "ISBN123") == 0);
    }
    SECTION("getAuthor()")
    {
        Book book("ISBN123", "IT", "Steven King", 2);
        REQUIRE(strcmp(book.getAuthor(), "Steven King") == 0);
    }
    SECTION("getTitle()")
    {
        Book book("ISBN123", "IT", "Steven King", 2);
        REQUIRE(strcmp(book.getTitle(), "IT") == 0);
    }
}

TEST_CASE("test operator=")
{
    SECTION("Non-empty book")
    {
        Book book("ISBN123", "IT", "Steven King", 2);
        Book bookop = book;
        REQUIRE(strcmp(book.getISBN(), bookop.getISBN()) == 0);
        REQUIRE(strcmp(book.getAuthor(), bookop.getAuthor()) == 0);
        REQUIRE(strcmp(book.getTitle(), bookop.getTitle()) == 0);
        REQUIRE(book.getSpace() == bookop.getSpace());
    }
}