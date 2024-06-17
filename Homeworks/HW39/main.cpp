#include "tree.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    bstree<int> tree(1);
    tree.root()->set(new bstree<int>::Node(2), new bstree<int>::Node(3));
    tree.root()->left()->set(new bstree<int>::Node(4), new bstree<int>::Node(5));
    tree.root()->right()->set(nullptr, new bstree<int>::Node(6));

    std::cout << "Inorder: \n";
    auto path = inorder<int>(tree.root());
    for (auto& node : path)
        std::cout << node << " ";

    std::cout << "\n";

    std::cout << "Preorder: \n";
    path = preorder<int>(tree.root());
    for (auto& node : path)
        std::cout << node << " ";

    std::cout << "\n";

    std::cout << "Postorder: \n";
    path = postorder<int>(tree.root());
    for (auto& node : path)
        std::cout << node << " ";

    std::cout << "\n";

    std::cout << "BFS: \n";
    path = bfs<int>(tree.root());
    for (auto& node : path)
        std::cout << node << " ";
    
    return 0;
}
