#include <queue>
#include <time.h>
#include <vector>
#include <random>
#include <iostream>

struct Node
{
    int value;
    std::vector<Node*> children;
};

Node* createRandomTree()
{
    Node* root = new Node();
    root->value = rand() % 100;
    int nChildren = rand() % 11;
    
    for (size_t i = 0; i < nChildren; i++)
    {
        root->children.push_back(new Node());
        root->children[i]->value = rand() % 100;

        int nChildrenChildren = rand() % 11;
    
        for (size_t j = 0; j < nChildrenChildren; j++)
        {
            root->children[i]->children.push_back(new Node());
            root->children[i]->children[j]->value = rand() % 100;
        }
    }
    
    return root;
}

template<typename Iterator, typename UnaryPredicate>
void my_for_each(Iterator begin, Iterator end, UnaryPredicate pred)
{
    if (end > begin)
        for (Iterator it = begin; it != end; it++)
            pred(*it);
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    Node* root = createRandomTree();
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        std::cout << cur->value << " ";

        for (auto& c : cur->children)
            q.push(c);
    }

    std::cout << "\n\n----------------------------------\n\n";

    std::vector<int> vec{1, 2, 3, 4, 5, 6};
    my_for_each(vec.begin(), vec.end(), [](int el){std::cout << el << " ";});

    return 0;
}
