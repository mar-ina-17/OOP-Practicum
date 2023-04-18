#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
private:
    std::size_t size;
    char *data;

public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &other);
    ~MyString();
    const char *c_str() const;
    void clear();
    void destruct();
    bool empty() const;
    char &back();
    char &front();
    const char &back() const;
    const char &front() const;
    char &operator[](std::size_t index);
    const char &operator[](std::size_t index) const;

    std::size_t getSize() const;
    std::size_t capacity() const;

    void pop_back();
    void push_back(char ch);

    MyString &operator+=(const MyString &other);
    MyString operator+(const MyString &other) const;
    bool operator==(const MyString &other) const;
    bool operator<(const MyString &other) const;
    bool operator<=(const MyString &other) const;
    bool operator>(const MyString &other) const;
    bool operator>=(const MyString &other) const;
    MyString &operator=(MyString const &other);

    friend std::ostream &operator<<(std::ostream &out, const MyString &string);
    friend std::istream &operator>>(std::istream &in, MyString &string);
};

#endif