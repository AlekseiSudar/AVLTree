module;

#include <stack>
#include <string>

export module AVL;

//----------------------------------------------------------------------------------------------

export template <typename T>
class AVLTree{
private:
    class Node;
public:
    AVLTree() = default;
    ~AVLTree();

    void insert(const T& key);
    const T& minStat(int i) const;
    int countLess(const T& key) const;

    class itterator;
    itterator begin();
    itterator end();
private:
    Node* root_ = nullptr;
};

template <typename T>
AVLTree<T>::~AVLTree(){
    if(!root_)
        return;

    std::stack<Node*> path({root_});
    while(!path.empty()){
        if(path.top()->left_){
            path.push(path.top()->left_);
        }
        else if(path.top()->right_){
            path.push(path.top()->right_);
        }
        else{
            Node* curr = path.top();
            path.pop();
            if(!path.empty()){
                if(path.top()->left_ == curr)
                    path.top()->left_ = nullptr;
                else
                    path.top()->right_ = nullptr;
            }
            delete curr;
        }
    }
    root_ = nullptr;
}

template <typename T>
void AVLTree<T>::insert(const T& key){
    Node** curr = &root_;
    std::stack<Node**> path;
    while(*curr){
        if((*curr)->key_ == key)
            throw std::string("Value " + std::to_string(key) + " is already exist.\n");
        path.push(curr);
        curr = key < (*curr)->key_ ? &(*curr)->left_ : &(*curr)->right_;
    }
    *curr = new Node(key);
    while(!path.empty()){
        *path.top() = (*path.top())->update();
        path.pop();
    }
}

template <typename T>
const T& AVLTree<T>::minStat(int i) const{
    if(i < 1)
        throw std::string("Value " + std::to_string(i) + " is less than 1\n");
    if(!root_ || root_->size_ < i)
        throw std::string("Value " + std::to_string(i) + " is greater than count " + std::to_string(root_->size_) + "\n");
    const Node* curr = root_;
    int curr_n = curr->left_->size_ + 1;
    while(curr_n != i){
        if(curr_n < i){
            curr = curr->right_;
            curr_n += (curr->left_ ? curr->left_->size_ : 0) + 1;
        }
        else{
            curr = curr->left_;
            curr_n -= (curr->right_ ? curr->right_->size_ : 0) + 1;
        }
    }
    return curr->key_;
}

template <typename T>
int AVLTree<T>::countLess(const T& key) const{
    const Node* curr = root_;
    unsigned count = 0;
    while(curr && curr->key_ != key){
        if(curr->key_ < key){
            count += (curr->left_ ? curr->left_->size_ : 0) + 1;
            curr = curr->right_;
        }
        else{
            curr = curr->left_;
        }
    }
    if(curr){
        count += (curr->left_ ? curr->left_->size_ : 0);
    }
    return count;
}

//----------------------------------------------------------------------------------------------

template <typename T>
class AVLTree<T>::Node{
public:
    Node(const T& k) : key_(k) {}
    const T key_;
    int size_ = 1;
    int height_ = 1;
    Node* left_  = nullptr;
    Node* right_ = nullptr;

    Node* update(){
        int bf = balance_factor();
        if(bf == 2){
            if(left_ && left_->balance_factor() < 0)
                left_ = left_->left_rotation();
            return right_rotation()->update_data();
        }
        else if(bf == -2){
            if(right_ && right_->balance_factor() > 0)
                right_ = right_->right_rotation();
            return left_rotation()->update_data();
        }
        return update_data();
    }
private:
    int balance_factor() const{
        return (left_ ? left_->height_ : 0) - (right_ ? right_->height_ : 0);
    }
    Node* update_data(){
        const int  left_h = left_  ?  left_->height_ : 0,
                  right_h = right_ ? right_->height_ : 0;
        height_ = (left_h < right_h ? right_h : left_h) + 1;
        size_ = (left_ ? left_->size_ : 0) + (right_ ? right_->size_ : 0) + 1;
        return this;
    }
    Node* left_rotation(){
        Node* x = this;
        Node* y = x->right_;
        x->right_ = y->left_;
        y->left_ = x;
        x->update_data();
        return y;
    }
    Node* right_rotation(){
        Node* x = this;
        Node* y = x->left_;
        x->left_ = y->right_;
        y->right_ = x;
        x->update_data();
        return y;
    }
};

//----------------------------------------------------------------------------------------------

template <typename T>
class AVLTree<T>::itterator{
public:
    itterator(std::stack<const Node*>&& path, const Node* root) : root_(root), path_(path) {}

    const T& operator*(){ return path_.top()->key_; }
    bool operator==(const itterator& other);
    bool operator!=(const itterator& other);
    itterator& operator++();
    itterator& operator--();
private:
    const Node* root_;
    std::stack<const Node*> path_;
};

template <typename T>
bool AVLTree<T>::itterator::operator==(const itterator& other){
    return root_ == other.root_ &&
           (
            ((!path_.empty() && !other.path_.empty()) && (path_.top() == other.path_.top())) ||
            (path_.empty() && other.path_.empty())
           );
}
template <typename T>
bool AVLTree<T>::itterator::operator!=(const itterator& other){
    return !(*this == other);
}

template <typename T>
AVLTree<T>::itterator& AVLTree<T>::itterator::operator++(){
    if(path_.top()->right_){
        path_.push(path_.top()->right_);
        while(path_.top()->left_)
            path_.push(path_.top()->left_);
    }
    else{
        const Node* buf = nullptr;
        while(!path_.empty() && path_.top()->right_ == buf){
            buf = path_.top();
            path_.pop();
        }
    }
    return *this;
}

template <typename T>
AVLTree<T>::itterator& AVLTree<T>::itterator::operator--(){
    if(path_.empty()){
        path_.push(root_);
        while(path_.top()->right_)
            path_.push(path_.top()->right_);
    }
    else if(path_.top()->left_){
        path_.push(path_.top()->left_);
        while(path_.top()->right_)
            path_.push(path_.top()->right_);
    }
    else{
        const Node* buf = nullptr;
        while(!path_.empty() && path_.top()->left_ == buf){
            buf = path_.top();
            path_.pop();
        }
    }
    return *this;
}

template <typename T>
AVLTree<T>::itterator AVLTree<T>::begin(){
    if(!root_)
        return AVLTree<T>::end();
    std::stack<const Node*> path;
    path.push(root_);
    while(path.top()->left_)
        path.push(path.top()->left_);
    return itterator(std::move(path), root_);
}
template <typename T>
AVLTree<T>::itterator AVLTree<T>::end(){
    return AVLTree<T>::itterator(std::stack<const Node*>(), root_);
}