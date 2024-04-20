#pragma once
#include "MObject.h" 

template <typename T>
class MSNode
{
public:
    MSNode(T data) : data(data), next_node(nullptr) {}
    ~MSNode() {}

    T data;
    MSNode* next_node;
};

template <typename T>
class MSList
{
public:
    MSList() : _head(nullptr), _size(0) {}
    ~MSList() {}

    int get_size() const { return _size; }
    void add(T data); //add 사용 없으면 오류뜸
    T& operator[](int index);
    void clear();

public:
    MSNode<T>* _head;
    int _size;
};

