#include "TList.h"
#include <iostream>
#include <cstdint>

template <class T>
TList<T>::TList()
{
    head = nullptr;
    length = 0;
}

template <class T>
void TList<T>::Push(std::shared_ptr<T> &obj) {
    int32_t index = 0;
    std::cout << "Enter index = ";
    std::cin >> index;
    if (index > this->GetLength()|| index < 0) {
        std::cerr << "This index doesn't exist\n";
        return;
    }
    std::shared_ptr<TListItem<T>> newItem = std::make_shared<TListItem<T>>(obj);

    if (index == 0) {
        newItem->SetNext(head);
        head = newItem;
        ++length;
        return;
    } else {
        std::shared_ptr<TListItem<T>> cur = this->head;
        std::shared_ptr<TListItem<T>> prev = this->head;
        for (int i = 0; i < index; ++i){
            prev = cur;
            cur = cur->GetNext();
        }
        newItem->SetNext(cur);
        prev->SetNext(newItem);
    }
    ++length;
}

template <class T>
uint32_t TList<T>::GetLength()
{
    return this->length;
}

template <class T>
const bool TList<T>::IsEmpty() const
{
    return head == nullptr;
}


template <class T>
std::shared_ptr<T> TList<T>::Pop() {
    int32_t ind = 0;
    std::cout << "Enter index = ";
    std::cin >> ind;
    std::shared_ptr<T> res;
    if (ind > this->GetLength() - 1 || ind < 0 || this->IsEmpty()) {
        std::cout << "Change index" << std::endl;
        return res;
    }

    std::shared_ptr<TListItem<T>> tmp = this->head;
    for(int32_t i = 0; i < ind - 1; ++i) {
        tmp = tmp->GetNext();
    }
    std::shared_ptr<TListItem<T>> removed = tmp->GetNext();
    res = removed->GetFigure();
    std::shared_ptr<TListItem<T>> nextItem = removed->GetNext();
    tmp->SetNext(nextItem);
    //nextItem->SetPrev(tmp);
    //return res;
    --length;
    return res;
}

template <class T>
std::shared_ptr<T> TList<T>::PopFirst()
{
    if (this->GetLength() == 1) {
        std::shared_ptr<T> res = this->head->GetFigure();
        this->head = nullptr;
        return res;
    }
    std::shared_ptr<TListItem<T>> tmp = this->head;
    std::shared_ptr<T> res = tmp->GetFigure();
    this->head = this->head->GetNext();
    return res;
}


template <class T>
TIterator<TListItem<T>,T> TList<T>::begin()
{
    return TIterator<TListItem<T>,T>(head);
}

template <class T>
TIterator<TListItem<T>,T> TList<T>::end()
{
    return TIterator<TListItem<T>,T>(nullptr);
}



template <class T>
std::ostream& operator<<(std::ostream &os, const TList<T> &list)
{
    if (list.IsEmpty()) {
        os << "The list is empty." << std::endl;
        return os;
    }

    std::shared_ptr<TListItem<T>> tmp = list.head;
    for(int32_t i = 0; tmp; ++i) {
        os << "idx: " << i << "   ";
        tmp->GetFigure()->Print();
        os << std::endl;
        tmp = tmp->GetNext();
    }

    return os;
}

template <class T>
TList<T>::~TList()
{
    while(!this->IsEmpty()) {
        this->PopFirst();
        --length;
    }
}

#include "figure.h"
template class TList<Figure>;
template std::ostream& operator <<(std::ostream &out, const TList<Figure> &obj);
