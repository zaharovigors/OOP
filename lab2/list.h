#ifndef TSTACK_H
#define	TSTACK_H

#include "octagon.h"
#include "TNode.h"

class TList {
public:
    TList();
    TList(const TList& orig);

    void push(Octagon &&octagon, size_t place);
    bool empty();
    Octagon pop(size_t place);
    friend std::ostream& operator<<(std::ostream& os,const TList& list);
    virtual ~TList();
private:

    TNode *head;
    size_t size;
};

#endif	/* TSTACK_H */
