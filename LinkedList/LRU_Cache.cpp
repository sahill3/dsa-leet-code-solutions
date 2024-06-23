class Node{
    public:
    int key;
    int value;
    Node* next;

    Node(){
        this -> key = 0;
        this -> value = 0;
        this -> next = nullptr;
    }
    
    Node(int key, int value){
        this -> key = key;
        this -> value = value;
        this -> next = nullptr;
    }
};

void insertAtHead(Node* &head, int key, int value){

    if (head == nullptr){
        Node* node = new Node(key, value);
        head = node;
        return;
    }

    Node* node = new Node(key, value);
    node -> next = head;
    head = node;
}

void deleteAndInsert(Node* &head, int key, int value){
    Node* node = new Node(key, value);
    Node* curr = head;
    
    if (curr->next == nullptr){
        head = node;
        return;
    }

    while(curr -> next -> next != nullptr)
        curr = curr -> next;

    curr -> next = nullptr;

    node -> next = head;
    head = node;
}

class LRUCache {
public:
    int capacity;
    int size;
    Node* head;

    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> size = 0;
        this -> head = nullptr;
    }
    
    int get(int key) {
        if (this->head == nullptr)
            return -1;

        Node* temp = this->head;
        int data;
        bool flag = false;

        if (temp -> key == key)
            return temp -> key;

        while(temp->next != nullptr){
            if (temp-> next-> key == key){
                data = temp-> next-> value;
                cout << "data: "<< data << endl;
                flag = true;
                break;
            }
            temp = temp -> next;
        }   

        Node* used = temp -> next;
        temp -> next = used -> next;
        used -> next = head;
        head = used;   

        if (flag)   
            return data;
    
        return -1;
    }
    
    void put(int key, int value) {
        if (this->size < this->capacity){
            insertAtHead(this->head, key, value);
            this -> size++;
            // cout << this->head -> value <<endl;
        }
        else{
            deleteAndInsert(this->head, key, value);
        }
    }   
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */