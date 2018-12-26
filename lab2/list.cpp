#include "list.h"

TList::TList() : head(nullptr) {
    size = 0;
}

TList::TList(const TList& orig) {
    head = orig.head;
}

std::ostream& operator<<(std::ostream& os, const TList& list) {

    TNode *item = list.head;

    for(int i = 0; i < list.size; ++i)
    {
      os << *item;
      item = item->GetNext();
    }

    return os;
}

void TList::push(Octagon &&octagon, size_t place) {
    if (place > size){
        return;
    }
    TNode *other = new TNode(octagon);

    if (place == 0){
        other->SetNext(head);
        head = other;
        return;
    }

    TNode *cur = head;
    TNode *prev = head;
    for (int i = 0; i < place; ++i){
        prev = cur;
        cur = cur->GetNext();
    }
    other->SetNext(cur);
    prev->SetNext(other);
    size++;
}

bool TList::empty() {
    return size == 0;
}

Octagon TList::pop(size_t place) {
    if (place >= size){
        return head->GetOctagon();
    }

    Octagon result;
    TNode *cur = head;
    TNode *prev = head;
    for (int i = 0; i < place; ++i){
        prev = cur;
        cur = cur->GetNext();
    }
    result = cur->GetOctagon();
    if (place == size - 1){
        return result;
    }
    prev->SetNext(cur->GetNext());
    delete cur;
    size--;

    return result;
}

TList::~TList() {
    delete head;
}
