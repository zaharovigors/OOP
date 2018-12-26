#include "TNode.h"
#include <iostream>

TNode::TNode(const Octagon& octagon) {
    this->octagon = octagon;
    this->next = nullptr;
    std::cout << "List item: created" << std::endl;
}

TNode::TNode(const TNode& orig) {
    this->octagon = orig.octagon;
    this->next = orig.next;
    std::cout << "List item: copied" << std::endl;
}

TNode* TNode::SetNext(TNode* next) {
    TNode* old = this->next;
    this->next = next;
    return old;
}

Octagon TNode::GetOctagon() const {
    return this->octagon;
}

TNode* TNode::GetNext() {
    return this->next;
}

TNode::~TNode() {
    std::cout << "List item: deleted" << std::endl;
    delete next;

}

std::ostream& operator<<(std::ostream& os, const TNode& obj) {
    os << "[ " << obj.octagon << "]" << std::endl;
    return os;
}
