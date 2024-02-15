#include "../s21_containers.h"

using val_t = RBNode<int, int>;

// void print(val_t)

int main() {
    // s21::set<int> tr;
    RBTree<int, int> tr;
 tr.insert(10, 1);
 tr.insert(5, 2);
tr.insert(12, 3);
tr.insert(20, 4);
tr.insert(1, 5);


// tr.insert(10);
// tr.insert(5);
// tr.insert(12);
// tr.insert(20);
// tr.insert(1);


    

    // for (auto i = tr.begin(); i != tr.end(); ++i) {
    //     if (i.node()->parent == nullptr) {
    //         std::cout << "[" << (*i).first << "," << (*i).second << "]" << "(" << i.node()->color << ")" << "->" << "[" << "root_(null)" << "] ";
    //     } else
    //         std::cout << "[" << (*i).first << "," << (*i).second << "]" << "(" << i.node()->color << ")" << "->" << "[" << i.node()->parent->value->first << "] ";
        
    // }
    tr.erase(tr.begin());
    tr.erase(tr.begin());
    tr.erase(tr.begin());
    // std::cout << std::endl;
    // for (auto i = tr.begin(); i != tr.end(); ++i) {
    //     if (i.node()->parent == nullptr) {
    //         std::cout << "[" << (*i).first << "," << (*i).second << "]" << "(" << i.node()->color << ")" << "->" << "[" << "root_(null)" << "] ";
    //     } else
    //         std::cout << "[" << (*i).first << "," << (*i).second << "]" << "(" << i.node()->color << ")" << "->" << "[" << i.node()->parent->value->first << "] ";
        
    // }
    // auto f = tr.find(12);
    // bool t = tr.contains(0);

    
    
    return 0;
}