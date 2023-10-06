#include <iostream>

template<typename T>
class CNode
{
    T m_Data;
    CNode* m_pNode;
    public:
    
    CNode(T value) : m_Data(value), m_pNode(NULL){};
    ~CNode(){}

    T get() const { return m_Data; }
    CNode<T>* getNode() const { return m_pNode; }
    void nextNode(CNode* pNode){
        m_pNode = pNode;
    }
};


template<typename T>
class CLinkedlist
{
    CNode<T>* m_pStartingNode;
    
    public:
        CLinkedlist() : m_pStartingNode(NULL){}
        void addNode(T);
        void deleteNode(int); 
        void insertNode(T, int); 
        //after pos
        void printList();
};



template<typename T> void CLinkedlist<T>::addNode(T value){

    if(m_pStartingNode == NULL){
        m_pStartingNode = new CNode<T>(value);
    }
    else{
        CNode<T>* pNode = new CNode<T>(value);
        CNode<T>* tempNode = m_pStartingNode;

        while(tempNode->getNode() != NULL)
            tempNode = tempNode->getNode();
        tempNode->nextNode(pNode);
    }
}

template<typename T> void CLinkedlist<T>::deleteNode(int pos){
    int i = 0;
    
    CNode<T>* tempNode = m_pStartingNode;
    
    for(i; i < pos - 1; i++){
        if(tempNode != NULL)
            tempNode = tempNode->getNode();
    }

    if(tempNode == NULL || tempNode->getNode() == NULL)
        return;

    CNode<T>* beforeNode = tempNode->getNode();
    delete tempNode;
    //tempNode = tempNode->getNode();
    tempNode->nextNode(beforeNode);
    //delete beforeNode;
    
}

template<typename T> void CLinkedlist<T>::insertNode(T value, int pos){
    CNode<T>* tempNode = m_pStartingNode;
    /* for(int i = 0; i < pos; i++){
        if(i == pos - 1){
            CNode<T>* newNode = new CNode<T>(value);
            newNode->nextNode(tempNode->getNode());
            tempNode = newNode;
        }
        else
            tempNode = tempNode->getNode();
    } */
    for(int i = 0; i < pos - 1; i++){
        tempNode = tempNode -> getNode();
    }
    CNode<T>* newNode = new CNode<T>(value);
    newNode->nextNode(tempNode->getNode());
    tempNode = newNode->getNode();
}

template<typename T> void CLinkedlist<T>::printList(){
    CNode<T>* tempNode = m_pStartingNode;
    while(tempNode != NULL){
        std::cout << "\n" << tempNode->get() << std::endl;
        tempNode = tempNode->getNode();
    }
}

int main(){

    CLinkedlist<int> intList;
	intList.addNode(112);
	intList.addNode(22);
	intList.addNode(13);
	intList.printList();
    intList.deleteNode(2);
    std::cout << "\nAfter delete: \n";
    intList.printList();
    intList.insertNode(2, 2);
    std::cout << "\nAfter insert: \n";
    intList.printList();

    return 0;
}
