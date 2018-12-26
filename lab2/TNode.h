#ifndef TSTACKITEM_H
#define	TSTACKITEM_H

#include "octagon.h"
class TNode {
public:
    TNode(const Octagon& octagon);
    TNode(const TNode& orig);
    friend std::ostream& operator<<(std::ostream& os, const TNode& obj);

    TNode* SetNext(TNode* next);
    TNode* GetNext();
    Octagon GetOctagon() const;

    virtual ~TNode();
private:
    Octagon octagon;
    TNode *next;
};

#endif	/* TSTACKITEM_H */
