// defining a doubly linked list node data structure

class ListNode {
public:
      // defining variables of a doubly linked list that we need
      int key;
      int val;
      ListNode* prev;
      ListNode* next;

      // defining constructor of the doubly linked list for how variables updated by default
      ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {} 
};

class LRUCache{
private:
    
    // variables of cache class. capacity, hashmap, doubly linked list for lru (left), mru (right)
    int cap;
    unordered_map<int, ListNode*> cache;
    ListNode* left;
    ListNode* right;

    // separate functions for remove a node
    void removeNode(ListNode* node)
    {
        cout << "\n removing node: " << node->val <<"\n";
        /*       a - b - c 
                 remove b , goal is a - c 
                 next of a is c 
                 prev of c is a             */

        // details of existing node's previous node
        ListNode* prev = node->prev; 

        // details of existing node's next node
        ListNode* nxt = node->next; 

        // updating next node of existing previous as existing next node
        prev->next = nxt;

        // updating previous node of existing next node as existing previous node.
        nxt->prev = prev;

        
    }

    // separate function for inserting a node
    void insertNode(ListNode* node)
    {
        cout << "\n inserting node: " << node->val <<"\n";
        /* a - c, where a is least recently used... in case of capacity, we remove a and add c
           add c, goal a - b - c        */ 
        
        ListNode* prev = right->prev;
        //  prev of c is b
        prev->next = node;

        // prev of b is a
        node->prev = prev;

        //  next of b is c
        node->next = right;
        
        // next of a is b
        right->prev = node;
        
    }


public:
    LRUCache(int capacity) 
    {

    // initialize the size of the cache... 
    cap = capacity; 

    // hashmap better for storing key value pair - easy to finding value of key
    cache.clear();

    // need doubly linked list for cache -- need to remove and add , also find lru
    // defined in above struct
    left = new ListNode(0,0);
    right = new ListNode(0,0);
    left->next = right;
    right->prev = left;

    }

    int get(int key) {

    cout << "\n ==== get node called \n";

    // check if the key value already exits -- if yes, return value , else -1 

    if(cache.find(key) != cache.end())
        {
        cout << "============= \n entering if \n";
        // store pointer value in hashmap as node to find value of the node
        ListNode* node = cache[key];

        // key is considered used in this function -- so not lru
        // therefore, remove node whereever it is  (middle,etc)
        removeNode(node);

        // insert same node to right end -- coz most recently used
        insertNode(node);

        // find value of node and return that
        return node->val;

        }
    else
    {
        cout << "============= \n entering else \n";
        return -1;
    }
    }
    
    void put(int key, int value) {

        cout << "\n ==== put node called \n";

    
     // if key exists, update value
    if(cache.find(key) != cache.end())
        removeNode(cache[key]);
        
    // else add this pair as new node 
    ListNode* newNode = new ListNode(key, value);
    
    // insert this node to doubly linked list
    insertNode(newNode);
    
    // add node to hashmap
    cache[key] = newNode;

    // if capacity exceeds, find lru, delete lru 
    if(cache.size() > cap)
    {
        ListNode* lru = left->next;
        removeNode(lru);
        cache.erase(lru->key);
        delete lru;
    }
        
    }

};
