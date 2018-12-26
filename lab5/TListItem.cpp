#include "TListItem.h"
#include <iostream>

template <class T>
TListItem<T>::TListItem(const std::shared_ptr<T> &obj)
{
    this->item = obj;
    this->next = nullptr;
}

template <class T>
std::shared_ptr<T> TListItem<T>::GetFigure() const
{
    return this->item;
}

template <class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetNext()
{
    return this->next;
}

template <class T>
void TListItem<T>::SetNext(std::shared_ptr<TListItem<T>> item)
{
    this->next = item;
}

template <class T>
std::shared_ptr<T> TListItem<T>::remove() {
  std::shared_ptr<TListItem<T>> removed = this->next;
  std::shared_ptr<T> item = removed->GetFigure();
  this->next = removed->GetNext();  
  return item;
}

template <class T>
std::ostream& operator<<(std::ostream &os, const TListItem<T> &obj)
{
    os << obj.item << std::endl;
    return os;
}

#include "figure.h"
template class TListItem<Figure>;
template std::ostream& operator <<(std::ostream &out, const TListItem<Figure> &obj);