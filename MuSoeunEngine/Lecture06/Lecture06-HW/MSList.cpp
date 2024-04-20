#pragma once
#include "MSList.h"
template <typename T>
void MSList<T>::add(T data) //add 識情
{
    MSNode<T>* new_node = new MSNode<T>(data);
    if (!_head)
    {
        _head = new_node;
    }
    else
    {
        MSNode<T>* current = _head;
        while (current->next_node)
        {
            current = current->next_node;
        }
        current->next_node = new_node;
    }
    _size++;
}

template <typename T>
T& MSList<T>::operator[](int index) //oper 識情
{
    MSNode<T>* current = _head;
    for (int i = 0; i < index; ++i)
    {
        current = current->next_node;
    }
    return current->data;
}
template <typename T>

void MSList<T>::clear()
{
    while (_head)
    {
        MSNode<T>* temp = _head;
        _head = _head->next_node;
        delete temp;
    }
    _size = 0;
}


