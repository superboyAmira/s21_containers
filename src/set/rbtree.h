/*
\author superboy
\date 26.01.2024
*/

#ifndef S21_CONTAINER_SRC_SET_RBTREE_H_
#define S21_CONTAINER_SRC_SET_RBTREE_H_

#include <limits>

/***********************  rbnode ***********************/

template <typename Key, typename T>
struct RBNode {
    using value_type =  std::pair<const Key, T>>; 
    
    value_type value;
    RBNode* parent;
    RBNode* left;
    RBNode* right;
    bool isRed;
    RBNode(Key k, T t, bool color, RBNode* p, RBNode* l, RBNode* r) :
        value(std::make_pair<const_cast<const Key>(k), t>), isRed(color), parent(p), left(l), right(r) { };
};

/***********************  rbtree iterator ***********************/

template<typename Key, typename T, bool is_const>
class RBIterator {
    public:
        friend class RBTree<Key, T>;
        using value_type = std::pair<const Key, T>>;
        using node_type = RBNode<Key, T>;
        using tree_type = RBTree<Key, T>;

        using conditional_node_ptr = std::conditional_t<IsConst, const node_type*, node_type*>;
        using conditional_node_ref = std::conditional_t<IsConst, const node_type&, node_type&>;
        using conditional_tree_ptr = std::conditional_t<is_const, const tree_type*, tree_type*>;
        using conditional_tree_ref = std::conditional_t<is_const, const tree_type&, tree_type&>;



    private:
        conditional_tree_ptr itr_tree_;
        conditional_node_ptr itr_node_;

    
};

/***********************  rbtree ***********************/

template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<T>>
class  RBTree
{
public:
    using value_type = std::pair<const Key, T>;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using NodeAlloc = typename std::allocator_traits<
        Alloc>::template rebind_alloc<RBNode<Key, T>>;
    using DataAlloc = typename std::allocator_traits<
        Alloc>::template rebind_alloc<std::pair<const Key, T>>;
    using iterator = RBIterator<Key, T, false>;
    using const_iterator = TreeCommonIterator<Key, T, true>;
    using size_type = size_t;

	RBTree()
      : alloc_(),
        alloc_node_(),
        compare_(),
        root_(nullptr),
        min_node_(nullptr),
        max_node_(nullptr),
        fake_node_(nullptr),
        size_(0) {};
    
	~RBTree();

	void insert(T key);    // Вставляем узел, ключ это значение ключа, внешний интерфейс
	void remove(T key); // Удалить ключевой узел
	RBNode<T>* search(T key);
	void print();
	void preOrder();    // Предзаказ обхода печати красного черного дерева
	void inOrder();    // Обход последовательности
	void postOrder();    // пост-заказ обхода		
	


private:
	void leftRotate(RBNode<T>* &root, RBNode<T>* x);// левая рука
	void rightRotate(RBNode<T>* &root, RBNode<T>* y);// правая рука

	void insert(RBNode<T>* &root, RBNode<T>* node);// Вставляем узел, внутренний интерфейс
	void InsertFixUp(RBNode<T>* &root, RBNode<T>* node);
	void destory(RBNode<T>* &node);

	void remove(RBNode<T>*& root, RBNode<T>*node);// Удалить узел как KEY
	void removeFixUp(RBNode<T>* &root, RBNode<T>* node, RBNode<T>*parent);

	RBNode<T>* search(RBNode<T>*node, T key) const;
	void print(RBNode<T>* node)const;
	void preOrder(RBNode<T>* tree)const;
	void inOrder(RBNode<T>* tree)const;
	void postOrder(RBNode<T>* tree)const;
private:
	DataAlloc alloc_;
    NodeAlloc alloc_node_;
    Compare compare_;
    RBNode<Key, T> *root_;
    RBNode<Key, T> *min_node_;
    RBNode<Key, T> *max_node_;
    RBNode<Key, T> *fake_node_;
    size_t size_;
};


#endif  // S21_CONTAINER_SRC_SET_RBTREE_H_
