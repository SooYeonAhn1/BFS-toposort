#ifndef node_hpp
#define node_hpp

#include <vector>
#include <memory>

template <typename T>
class Node {
    public:
        Node(T data) { this->data = data; }
        ~Node() = default;
        void addChildren(std::shared_ptr<Node<T>> child) { children.push_back(child); child->addInDegree(); }
        const std::vector<std::shared_ptr<Node<T>>>& getChildren() { return children; }
        T getData() { return data; }
        int getInDegree() { return inDegree;}
        void addInDegree() { ++inDegree; }
        void rmInDegree() { --inDegree; }
    private:
        T data;
        std::vector<std::shared_ptr<Node<T>>> children;
        int inDegree = 0;
};

#endif