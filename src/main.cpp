#include "../includes/Node.hpp"

#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>

struct NodePtrHash {
    std::size_t operator()(const std::shared_ptr<Node<int>>& node) const {
        return std::hash<int>()(node->getData());
    }
};

struct NodePtrEqual {
    bool operator()(const std::shared_ptr<Node<int>>& lhs,
                    const std::shared_ptr<Node<int>>& rhs) const {
        return lhs->getData() == rhs->getData();
    }
};


std::vector<std::shared_ptr<Node<int>>> topoSort(const std::unordered_set<std::shared_ptr<Node<int>>, NodePtrHash, NodePtrEqual>& vertices) {
    std::unordered_map<std::shared_ptr<Node<int>>, int, NodePtrHash, NodePtrEqual> inDegree;
    std::vector<std::shared_ptr<Node<int>>> res;
    std::queue<std::shared_ptr<Node<int>>> q;

    for (auto v : vertices) {
        if (v->getInDegree() == 0) {
            q.push(v);
        }
    }

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        const std::vector<std::shared_ptr<Node<int>>>& children = node->getChildren();
        for (auto child : children) {
            child->rmInDegree();
            if (child->getInDegree() == 0) {
                q.push(child);
            }
        }
        res.push_back(node);
    }
    return res;
}

int main() {
    auto zero = std::make_shared<Node<int>>(0);
    auto one = std::make_shared<Node<int>>(1);
    auto two = std::make_shared<Node<int>>(2);
    auto three = std::make_shared<Node<int>>(3);
    auto four = std::make_shared<Node<int>>(4);
    auto five = std::make_shared<Node<int>>(5);

    four->addChildren(zero);
    four->addChildren(one);

    five->addChildren(zero);
    five->addChildren(two);

    two->addChildren(three);

    three->addChildren(one);

    std::unordered_set<std::shared_ptr<Node<int>>, NodePtrHash, NodePtrEqual> vertices;
    vertices.insert(zero);
    vertices.insert(one);
    vertices.insert(two);
    vertices.insert(three);
    vertices.insert(four);
    vertices.insert(five);

    std::vector<std::shared_ptr<Node<int>>> ts = topoSort(vertices);

    for (const auto& v : ts) {
        std::cout << v->getData() << std::endl;
    }
    return 0;
}