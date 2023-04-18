#ifndef LIBRARYCOLL_H
#define LIBRARYCOLL_H
#include "Library.h"
class LibraryCollection
{
private:
    std::size_t count;
    Library **libraries;

    void clear();
    bool empty() const;
    void deallocateLibrary();
    void copy(const LibraryCollection &other);
    Library **createCollection(std::size_t cap);

public:
    LibraryCollection(const std::size_t capacity);
    LibraryCollection(const LibraryCollection &other);
    ~LibraryCollection();

    const std::size_t size() const;

    void addBook(Library &);
    void removeBook(Library &, const char *ISBN);
    void clearLibrary(const std::size_t i);

    const Library &
    operator[](std::size_t index) const;
    Library &operator[](std::size_t index);
    LibraryCollection &operator=(LibraryCollection const &other);
    friend std::ostream &operator<<(std::ostream &out, const LibraryCollection &other);
};
#endif
