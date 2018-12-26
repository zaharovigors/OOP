#ifndef TLIST_H
#define TLIST_H

#include <cstdint>
#include "octagon.h"
#include "square.h"
#include "triangle.h"
#include "TListItem.h"

template <class T>
class TList
{
public:
    TList();
    void Push(std::shared_ptr<T> &obj);
    const bool IsEmpty() const;
    uint32_t GetLength();
    std::shared_ptr<T> Pop();
    template <class A> friend std::ostream& operator<<(std::ostream &os, const TList<A> &list);
    void Del();
    virtual ~TList();

private:
    uint32_t length;
    std::shared_ptr<TListItem<T>> head;

    std::shared_ptr<T> PopFirst();
    std::shared_ptr<T> PopLast();
    std::shared_ptr<T> PopAtIndex(int32_t ind);
};

#endif
