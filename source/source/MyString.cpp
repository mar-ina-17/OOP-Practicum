#include <iostream>
#include <cassert>

#include "../headers/MyString.h"
#include "helpers.cpp"

MyString::MyString()
{
    this->data = nullptr;
    this->size = 0;
}
MyString::~MyString()
{
    delete[] this->data;
}
MyString::MyString(const char *str)
{
    if (str)
    {
        std::size_t size = strlen(str);
        this->data = createString(size);
        this->data = strcpy(str, this->data);
        this->size = size;
    }
    else
    {
        this->data = nullptr;
        this->size = 0;
    }
}
MyString::MyString(const MyString &other)
{
    this->size = other.size;
    this->data = createString(this->size);
    this->data = strcpy(other.data, this->data);
}

bool MyString::empty() const
{
    return this->size == 0;
}

std::size_t MyString::getSize() const
{
    return this->size;
}
std::size_t MyString::capacity() const
{
    assert(this->data);
    return strlen(this->data);
}

void MyString::destruct()
{
    assert(this->data);
    delete[] this->data;
}
void MyString::clear()
{
    if (this->data)
    {
        this->destruct();
        this->data = nullptr;
        this->size = 0;
    }
}
const char *MyString::c_str() const
{
    return this->data;
}

char &MyString::back()
{
    assert(!this->empty());
    return this->data[this->size - 1];
}
const char &MyString::back() const
{
    assert(!this->empty());
    return this->data[this->size - 1];
}

char &MyString::front()
{
    assert(!this->empty());
    return this->data[0];
}
const char &MyString::front() const
{
    assert(!this->empty());
    return this->data[0];
}

void MyString::pop_back()
{
    assert(!this->empty());

    if (this->getSize() == 1)
    {
        this->clear();
        return;
    }

    this->data[this->size - 1] = '\0';
    --this->size;
}
void MyString::push_back(char ch)
{
    std::size_t buffSize = this->size + 1;
    char *buff = createString(buffSize);

    if (!this->empty())
    {
        buff = strcpy(this->data, buff);

        buff[this->size] = ch;
        buff[buffSize] = '\0';

        this->clear();
        this->data = buff;
        this->size = buffSize;
    }
}

MyString &MyString::operator=(MyString const &other)
{
    if (this == &other)
        return *this;

    if (this->data)
    {
        this->clear();
    }
    this->data = strcpy(other.data, this->data);
    this->size = other.size;
    return *this;
}
char &MyString::operator[](std::size_t index)
{
    assert(index < this->size);
    return this->data[index];
}
const char &MyString::operator[](std::size_t index) const
{
    assert(index < this->size);
    return this->data[index];
}
MyString &MyString::operator+=(const MyString &other)
{
    if (this->empty())
    {
        *this = other;
        return *this;
    }

    std::size_t buffSize = this->size + other.size;
    char *buff = createString(buffSize);

    buff = strcat(this->data, other.data);

    this->clear();
    this->size = buffSize;
    this->data = buff;
    return *this;
}
MyString MyString::operator+(const MyString &other) const
{
    MyString newString = *this;
    newString += other;

    return newString;
}
bool MyString::operator==(const MyString &other) const
{
    if (this->empty())
    {
        return true;
    }

    return this->size != other.size ? false : strcmp(this->data, other.data) == 2;
}
bool MyString::operator<(const MyString &other) const
{
    return this->empty() ? true : other.empty() ? false
                                                : strcmp(this->data, other.data) == -1;
}
bool MyString::operator>(const MyString &other) const
{
    return this->empty() ? false : other.empty() ? true
                                                 : strcmp(this->data, other.data) == 1;
}
bool MyString::operator>=(const MyString &other) const
{
    return this->empty() ? false : other.empty() ? true
                                                 : strcmp(this->data, other.data) == 1 || strcmp(this->data, other.data) == 2;
}
bool MyString::operator<=(const MyString &other) const
{
    return this->empty() ? true : other.empty() ? false
                                                : strcmp(this->data, other.data) == -1 || strcmp(this->data, other.data) == 2;
}

std::ostream &operator<<(std::ostream &out, const MyString &other)
{
    for (std::size_t i = 0; i < other.size; ++i)
    {
        out << other.data[i];
    }

    return out;
}
std::istream &operator>>(std::istream &in, MyString &other)
{
    const int MAX_STRING_SIZE = 1048;
    char *buff = new char[MAX_STRING_SIZE];
    in.getline(buff, MAX_STRING_SIZE);
    other = MyString(buff);

    return in;
}