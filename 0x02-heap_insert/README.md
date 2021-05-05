#                0x02. Heap Insert

* The following data structures and types for binary trees. 

    - ### Basic Binary Tree

                    ```
                        /**
                    * struct binary_tree_s - Binary tree node
                    *
                    * @n: Integer stored in the node
                    * @parent: Pointer to the parent node
                    * @left: Pointer to the left child node
                    * @right: Pointer to the right child node
                    */
                    struct binary_tree_s
                    {
                        int n;
                        struct binary_tree_s *parent;
                        struct binary_tree_s *left;
                        struct binary_tree_s *right;
                    };```

    - ### Max Binary Heap

                    ```
                    typedef struct binary_tree_s heap_t;
                    ```
    - ## Files 0-binary_tree_node.c:

            * a function that creates a binary tree node:

            * Prototype: ```binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);```
            * parent is a pointer to the parent node of the node to create
            * value is the value to put in the new node
            * When created, a node does not have any children
            * Your function must return a pointer to the new node, or NULL on failure
            * expected output
                    ```
                        .-------(098)-------.
                    .--(012)--.         .--(402)--.
                    (006)     (016)     (256)     (512)
                    ```

    - ## Files 1-heap_insert.c:
            * a function that inserts a value into a Max Binary Heap:

            * Prototype: ```heap_t *heap_insert(heap_t **root, int value);```
            * root is a double pointer to the root node of the Heap
            * value is the value to store in the node to be inserted
            * the function must return a pointer to the inserted node, or NULL on failure
            * If the address stored in root is NULL, the created node must become the root node.
            * We need to respect a Max Heap ordering
            * expected output

                    ```
                    Inserted: 98
                    (098)

                    Inserted: 402
                    .--(402)
                    (098)

                    Inserted: 12
                    .--(402)--.
                    (098)     (012)

                    Inserted: 46
                        .--(402)--.
                    .--(098)     (012)
                    (046)

                    Inserted: 128
                        .-------(402)--.
                    .--(128)--.       (012)
                    (046)     (098)

                    Inserted: 256
                        .-------(402)-------.
                    .--(128)--.         .--(256)
                    (046)     (098)     (012)

                    Inserted: 512
                        .-------(512)-------.
                    .--(128)--.         .--(402)--.
                    (046)     (098)     (012)     (256)

                    Inserted: 50
                                .-------(512)-------.
                        .--(128)--.         .--(402)--.
                    .--(050)     (098)     (012)     (256)
                    (046)
                    ```