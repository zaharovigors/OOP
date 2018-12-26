#ifndef TLIST_H
#define TLIST_H

#include <cstdint>
#include "octagon.h"
#include "square.h"
#include "triangle.h"
#include "TListItem.h"

class TList
{
public:
    TList();
    void Push(std::shared_ptr<Figure> &obj);
    const bool IsEmpty() const;
    uint32_t GetLength();
    std::shared_ptr<Figure> Pop();
    friend std::ostream& operator<<(std::ostream &os, const TList &list);
    void Del();
    virtual ~TList();

private:
    uint32_t length;
    std::shared_ptr<TListItem> head;

    std::shared_ptr<Figure> PopFirst();
    std::shared_ptr<Figure> PopLast();
    std::shared_ptr<Figure> PopAtIndex(int32_t ind);
};

#endif
