#define CATCH_CONFIG_MAIN
#include <cstring>

#include "catch2/catch2.hpp"
#include "../headers/MyString.h"

TEST_CASE("Test Constructors")
{
    SECTION("Default constructor")
    {
        MyString test;

        REQUIRE(test.getSize() == 0);
        REQUIRE(test.c_str() == nullptr);
        REQUIRE(test == test);
    }

    SECTION("Constructor with params")
    {
        SECTION("String param")
        {
            MyString test("Hello");

            REQUIRE(test.getSize() == 5);
            REQUIRE(strcmp(test.c_str(), "Hello") == 0);
            REQUIRE(test == test);
        }

        SECTION("nullptr param")
        {
            MyString test(nullptr);

            REQUIRE(test.getSize() == 0);
            REQUIRE(test.c_str() == nullptr);
            REQUIRE(test == test);
        }

        SECTION("empty string param")
        {
            MyString test("");

            REQUIRE(test.getSize() == 0);
            REQUIRE(strcmp(test.c_str(), "") == 0);
            REQUIRE(test == test);
        }
    }

    SECTION("Copy constructor")
    {
        MyString test("Hello");
        MyString testCopy(test);

        REQUIRE(test.getSize() == testCopy.getSize());
        REQUIRE(strcmp(test.c_str(), testCopy.c_str()) == 0);
        REQUIRE(test == testCopy);
    }
}

TEST_CASE("Test front(), back()")
{
    SECTION("string")
    {
        MyString test = "Hello";
        REQUIRE(test.front() == 'H');
        REQUIRE(test.back() == 'o');
    }

    SECTION("one letter string")
    {
        MyString letter = "M";
        REQUIRE(letter.front() == 'M');
        REQUIRE(letter.back() == 'M');
        REQUIRE(letter.front() == letter.back());
    }
}

TEST_CASE("Test getSize()")
{
    SECTION("Non-empty string")
    {
        MyString test = "Hello";
        REQUIRE(test.getSize() == 5);
    }
    SECTION("Empty string")
    {
        MyString test = "";
        REQUIRE(test.getSize() == 0);
    }
}

TEST_CASE("Test capacity()")
{
    SECTION("Non-empty string")
    {
        MyString test = "Hello";
        REQUIRE(test.capacity() == 5);
    }
    SECTION("Empty string")
    {
        MyString test = "";
        REQUIRE(test.capacity() == 0);
    }
}

TEST_CASE("Test pop_back()")
{
    SECTION("Non-empty string")
    {
        MyString test = "Hello";
        test.pop_back();
        REQUIRE(strcmp(test.c_str(), "Hell") == 0);
    }
}
TEST_CASE("Test push_back()")
{
    SECTION("Non-empty string")
    {
        MyString test = "Hell";
        test.push_back('o');
        REQUIRE(strcmp(test.c_str(), "Hello") == 0);
    }
}

TEST_CASE("Test operator[]")
{
    SECTION("Non-empty string")
    {
        MyString test = "Hello";
        REQUIRE(test[2] == 'l');
    }
}
TEST_CASE("Test operator=")
{
    SECTION("with string")
    {
        MyString str1("Hello");
        MyString str2;
        str1 = str2;

        REQUIRE(str1.getSize() == str2.getSize());
        REQUIRE(strcmp(str1.c_str(), str2.c_str()) == 0);
        REQUIRE(str1 == str2);
    }
}
TEST_CASE("Test operator+=")
{
    SECTION("Two non-empty strings")
    {
        MyString str1 = "Hello";
        MyString str2 = " world!";
        str1 += str2;
        REQUIRE(str1.getSize() == 12);
        REQUIRE(strcmp(str1.c_str(), "Hello world!") == 0);
    }
    SECTION("One-empty string")
    {
        MyString str1 = "Hello";
        MyString str2 = "";
        str1 += str2;
        REQUIRE(str1.getSize() == 5);
        REQUIRE(strcmp(str1.c_str(), "Hello") == 0);
    }
    SECTION("Two-empty strings")
    {
        MyString str1 = "";
        MyString str2 = "";
        str1 += str2;
        REQUIRE(str1.getSize() == 0);
        REQUIRE(strcmp(str1.c_str(), "") == 0);
    }
}
TEST_CASE("Test operator+")
{
    SECTION("Two non-empty strings")
    {
        MyString str1 = "Hello";
        MyString str2 = " world!";
        MyString str3 = str1 + str2;
        REQUIRE(str3.getSize() == 12);
        REQUIRE(strcmp(str3.c_str(), "Hello world!") == 0);
    }
    SECTION("One-empty string")
    {
        MyString str1 = "Hello";
        MyString str2 = "";
        MyString str3 = str1 + str2;
        REQUIRE(str3.getSize() == 5);
        REQUIRE(strcmp(str3.c_str(), "Hello") == 0);
    }
    SECTION("Two-empty strings")
    {
        MyString str1 = "";
        MyString str2 = "";
        MyString str3 = str1 + str2;
        REQUIRE(str3.getSize() == 0);
        REQUIRE(strcmp(str3.c_str(), "") == 0);
    }
}
TEST_CASE("Test operator==")
{
    SECTION("Two non-empty equal strings")
    {
        MyString str1 = "Hello";
        MyString str2 = " Hello";
        REQUIRE(str1.getSize() == str2.getSize());
        REQUIRE(strcmp(str1.c_str(), str2.c_str()) == 0);
    }
    SECTION("Two non-empty non equal strings")
    {
        MyString str1 = "Hello!";
        MyString str2 = " Hello";
        REQUIRE_FALSE(str1.getSize() == str2.getSize());
        REQUIRE_FALSE(strcmp(str1.c_str(), str2.c_str()) == 0);
    }
}

TEST_CASE("Test operator<")
{
    SECTION("Non-empty strings")
    {
        MyString str1 = "Hello", str2 = "HelloWorld";

        REQUIRE(str1 < str2);
        REQUIRE_FALSE(str2 < str1);
    }

    SECTION("Non-empty string with empty string")
    {
        MyString str1 = "Hello", str2 = "";

        REQUIRE(str2 < str1);
        REQUIRE_FALSE(str1 < str2);
    }
}
TEST_CASE("Test operator>")
{
    SECTION("Non-empty strings")
    {
        MyString str1 = "HelloWorld", str2 = "Hello";

        REQUIRE(str1 > str2);
        REQUIRE_FALSE(str2 > str1);
    }

    SECTION("Non-empty string with empty string")
    {
        MyString str1 = "Hello", str2 = "";

        REQUIRE(str1 > str2);
        REQUIRE_FALSE(str1 < str2);
    }
}
TEST_CASE("test empty()`")
{
    SECTION("nullstr")
    {
        MyString test;
        REQUIRE(test.empty());
    }

    SECTION("empty string")
    {
        MyString test("");
        REQUIRE(test.empty());
    }

    SECTION("string")
    {
        MyString test("Hello");
        REQUIRE_FALSE(test.empty());
    }
}