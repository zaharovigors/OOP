#include "TList.h"
#include <iostream>
#include <cstdint>

TList::TList()
{
    head = nullptr;
    length = 0;
}

void TList::Push(std::shared_ptr<Figure> &obj) {
    int32_t index = 0;
    std::cout << "Enter index = ";
    std::cin >> index;
    if (index > this->GetLength()|| index < 0) {
        std::cerr << "This index doesn't exist\n";
        return;
    }
    std::shared_ptr<TListItem> newItem = std::make_shared<TListItem>(obj);

    if (index == 0) {
        newItem->SetNext(head);
        head = newItem;
        ++length;
        return;
    } else {
        std::shared_ptr<TListItem> cur = this->head;
        std::shared_ptr<TListItem> prev = this->head;
        for (int i = 0; i < index; ++i){
            prev = cur;
            cur = cur->GetNext();
        }
        newItem->SetNext(cur);
        prev->SetNext(newItem);
    }
    ++length;
}

uint32_t TList::GetLength()
{
    return this->length;
}

const bool TList::IsEmpty() const
{
    return head == nullptr;
}

std::shared_ptr<Figure> TList::Pop()
{
    int32_t ind = 0;
    std::cout << "Enter index = ";
    std::cin >> ind;
    std::shared_ptr<Figure> res;
    if (ind > this->GetLength() - 1 || ind < 0 || this->IsEmpty()) {
        std::cout << "Change index" << std::endl;
        return res;
    }

    if (ind == 0) {
        res = this->PopFirst();
    } else if (ind == this->GetLength() - 1) {
        res = this->PopLast();
    } else {
        res = this->PopAtIndex(ind);
    }
    --length;
    return res;
}

std::shared_ptr<Figure> TList::PopAtIndex(int32_t ind)
{
    std::shared_ptr<TListItem> tmp = this->head;
    for(int32_t i = 0; i < ind - 1; ++i) {
        tmp = tmp->GetNext();
    }
    std::shared_ptr<TListItem> removed = tmp->GetNext();
    std::shared_ptr<Figure> res = removed->GetFigure();
    std::shared_ptr<TListItem> nextItem = removed->GetNext();
    tmp->SetNext(nextItem);
    nextItem->SetPrev(tmp);
    return res;
}

std::shared_ptr<Figure> TList::PopFirst()
{
    if (this->GetLength() == 1) {
        std::shared_ptr<Figure> res = this->head->GetFigure();
        this->head = nullptr;
        return res;
    }
    std::shared_ptr<TListItem> tmp = this->head;
    std::shared_ptr<Figure> res = tmp->GetFigure();
    this->head = this->head->GetNext();
    this->head->SetPrev(nullptr);
    return res;
}

std::shared_ptr<Figure> TList::PopLast()
{
    if (this->GetLength() == 1) {
        std::shared_ptr<Figure> res = this->head->GetFigure();
        this->head = nullptr;
        return res;
    }
    std::shared_ptr<TListItem> tmp = this->head;
    while(tmp->GetNext()->GetNext()) {
        tmp = tmp->GetNext();
    }
    std::shared_ptr<TListItem> removed = tmp->GetNext();
    std::shared_ptr<Figure>res = removed->GetFigure();
    tmp->SetNext(removed->GetNext());
    return res;
}


std::ostream& operator<<(std::ostream &os, const TList &list)
{
    if (list.IsEmpty()) {
        os << "The list is empty." << std::endl;
        return os;
    }

    std::shared_ptr<TListItem> tmp = list.head;
    for(int32_t i = 0; tmp; ++i) {
        os << "idx: " << i << "   ";
        tmp->GetFigure()->Print();
        os << std::endl;
        tmp = tmp->GetNext();
    }

    return os;
}

void TList::Del()
{
    while(!this->IsEmpty()) {
        this->PopFirst();
        --length;
    }
}

TList::~TList()
{
/*    while(!this->IsEmpty()) {
        this->PopFirst();
        --length;
    }*/
}
