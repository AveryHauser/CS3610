template <class elemType>
int binaryTreeType<elemType>::r_single_parent(binaryTreeNode<elemType> *p) const {
    //base case
    if (p == nullptr) return 0;
    //the total count of single parents
    int count = 0;

    //checks to see if parent only have one child and adds one to the total count
    if ((p -> llink != nullptr && p -> rlink == nullptr) || (p -> llink == nullptr && p -> rlink != nullptr)) {
        count++;
    }
    //returns childs and current count
    return count + recursiveSingleParent(p -> llink) + recursiveSingleParent(p -> rlink);
}

template <class elemType>
int binaryTreeType<elemType>::i_single_parent(binaryTreeNode<elemType> *p) const {
    //stack of node pointers
    std::stack<binaryTreeNode<elemType>*> s;
    // pointer to keep track of position 
    binaryTreeNode<elemType>* current = p;
    //total single parents 
    int count = 0;

    //goes through the tree till finished
    while (current != nullptr || !s.empty()) {
        //goes to most left child
        while (current != nullptr) {
            s.push(current);
            current = current->llink;
        }

        //processes top node
        current = s.top();
        s.pop();

        //see if current is single parent 
        if ((current->llink != nullptr && current->rlink == nullptr) ||
            (current->llink == nullptr && current->rlink != nullptr)) {
            count++;
        }

        //goes to right child to continue 
        current = current->rlink;
    }

    return count;
}
