#define CATCH_CONFIG_MAIN
#include <cstring>

#include "catch2/catch2.hpp"
#include "../headers/Library.h"
#include "../headers/Book.h"
#include "../headers/MyString.h"

TEST_CASE("Test Constructors")
{
    SECTION("Constructor with params")
    {
        SECTION("capacity param")
        {
            Library lib(3);

            REQUIRE_FALSE(lib.empty());
        }

        SECTION("library param")
        {
            Library libCopy(2);
            Library lib(libCopy);

            REQUIRE_FALSE(lib.empty());
        }
    }
}

TEST_CASE("add books")
{
    SECTION("add books within space")
    {
        Library lib(4);

        Book book1("ISBN123", "IT", "Steven King", 3);
        Book book2("ISBN124", "The dark half", "Steven King", 1);

        REQUIRE_NOTHROW(lib.addNewBook(book1));
        REQUIRE_NOTHROW(lib.addNewBook(book2));
        REQUIRE(lib.size() == 4);
    }
    SECTION("add books within possible space")
    {
        Library lib(4);

        Book book1("ISBN123", "IT", "Steven King", 3);
        Book book2("ISBN124", "The dark half", "Steven King", 2);
        REQUIRE_NOTHROW(lib.addNewBook(book1));
        REQUIRE_THROWS(lib.addNewBook(book2), "Exceeding lib space");

        REQUIRE(lib.size() == 3);
    }

    SECTION("add books within possible space")
    {
        Library lib(4);

        Book book1("ISBN123", "IT", "Steven King", 1);
        Book book2("ISBN124", "The dark half", "Steven King", 2);
        Book book3("ISBN123", "IT", "Steven King", 1);

        REQUIRE_NOTHROW(lib.addNewBook(book1));
        REQUIRE_NOTHROW(lib.addNewBook(book2));

        REQUIRE_THROWS(lib.addNewBook(book3), "ISBN already in use");

        REQUIRE(lib.size() == 3);
    }
}

TEST_CASE("removing books")
{
    Library lib(3);
    Book book1("ISBN123", "IT", "Steven King", 1);
    Book book2("ISBN124", "The dark half", "Steven King", 2);

    lib.addNewBook(book1);
    lib.addNewBook(book2);

    lib.removeBook("isbn");
    REQUIRE(lib.size() == 2);

    lib.removeBook("ISBN123");
    REQUIRE(lib.size() == 1);

    lib.removeBook("ISBN124");
    REQUIRE(lib.size() == 0);
}

TEST_CASE("test find")
{
    Library lib(6);
    Book book1("ISBN123", "IT", "Steven King", 1);
    Book book2("ISBN124", "The dark half", "Steven King", 2);
    Book book3("ISBN125", "Green mile", "Steven King", 3);
    lib.addNewBook(book1);
    lib.addNewBook(book2);
    lib.addNewBook(book3);

    REQUIRE(lib.find("ISBN126") == nullptr);

    REQUIRE(strcmp(lib.find("ISBN124")->getISBN(), "ISBN124") == 0);
}