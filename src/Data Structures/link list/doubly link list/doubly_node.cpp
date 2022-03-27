#include"./headers/doubly_node.h"

template<typename X>Node<X>::Node(X value){
    data = value;
    next = previous = NULL;
};

template class Node<int>;
template class Node<float>;
template class Node<char>;
template class Node<long>;
template class Node<double>;
template class Node<bool>;
template class Node<string>;