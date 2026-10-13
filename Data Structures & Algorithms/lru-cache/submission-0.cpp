class LRUCache {
    struct Node{
        int key,value;
        Node *prev,*next;
        Node(int k, int v) : key(k),value(v),prev(nullptr),next(nullptr) {}
    };
    int cap;
    unordered_map<int,Node*> mpp;
    Node *head=new Node(-1,-1), *tail=new Node(-1,-1);
public:
    LRUCache(int capacity) :cap(capacity){
        head->next=tail;
        tail->prev=head;
    }
    void insertAfterHead(Node* newNode){
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node* delNode){
        Node* prevNode=delNode->prev;
        Node* nextNode=delNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        mpp.erase(key);
        deleteNode(node);
        insertAfterHead(node);
        mpp[key]=head->next;
        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            mpp.erase(key);
            deleteNode(node);
        }
        if(mpp.size()==cap){
            Node* node=tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
        }
        insertAfterHead(new Node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */