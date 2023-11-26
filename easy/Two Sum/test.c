//
//  test.c
//  Created by 筍包 on 2023/11/26.
//  To Test the Hash Table Function

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// construct a map
// the Node of the map
typedef struct Node{
    int key;
    int value;
    struct Node *next_node;
} Node;

// the Map
typedef struct{
    int size;
    Node **nodes;
} Map;

Map* create_hash_table(int size);
int hash_func(int key);
void map_insert(Map* map, int key, int value);
int map_search(Map* map, int key);
void free_map(Map* map);
void map_print(Map* map);
void node_print(Node* node);

int main(void){
    Map* map = create_hash_table(10);
    printf("%d", -3%100);
    map_insert(map, 3, 4);
    map_insert(map, 9, 99);
    map_print(map);
    printf("---\n");
    map_insert(map, 9, 44);
    map_insert(map, 13, 8);
    map_print(map);
    printf("---\n");
    map_insert(map, 29, 33);
    map_insert(map, 39, 45);
    map_print(map);
    printf("---\n");
    printf("key : 3, value : %d\n", map_search(map, 3));
    printf("key : 39, value : %d\n", map_search(map, 39));
    printf("key : 1, value : %d\n", map_search(map, 1));
    return 0;
}

Map* create_hash_table(int size){
    Map *map = malloc(sizeof(Map));
    map->size = size;
    map->nodes = (Node**)malloc(size*sizeof(Node*)); // calloc initialize it to zero by default
    return map;
}

int hash_func(int key){
    return key % 5;
}

int map_search(Map* map, int key){
    int index = hash_func(key);
    Node* pointer = map->nodes[index];
    if(pointer == NULL)
        return INT_MIN;
    if(pointer->key == key)
        return pointer->value;

    while(pointer->next_node != NULL){
        pointer = pointer->next_node;
        if(pointer->key == key)
            return pointer->value;
    }
    return INT_MIN;
}

void map_insert(Map* map, int key, int value){
    int index = hash_func(key);
    Node* pointer = map->nodes[index];
    Node* last_node_ptr = pointer;
    // Traverse the linked list at the index
    while(pointer != NULL){
        // If the key already exists
        if(pointer->key == key){
            // If the value is the same, do nothing
            if(pointer->value == value)
                return;
            
            // Update the value
            pointer->value = value;
            return;
        }
        last_node_ptr = pointer;
        pointer = pointer->next_node;
    }

    // Create a new node
    Node* new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next_node = NULL;

    // Link the new node to the list
    if(map->nodes[index] == NULL)
        map->nodes[index] = new_node;
    else
        last_node_ptr->next_node = new_node;
}

void free_map(Map* map) {
    // Iterate over the table
    for (int i = 0; i < map->size; i++) {
        Node* node = map->nodes[i];
        // Free the linked list nodes
        while (node != NULL) {
            Node* temp = node;
            node = node->next_node;
            free(temp);
        }
    }
    // Free the nodes array
    free(map->nodes);
    // Free the map
    free(map);
}

void map_print(Map* map){
    int size  = map->size;
    printf("size : %d\n", size);
    for(int i = 0; i < size; i++){
        Node* pointer = map->nodes[i];
        node_print(pointer);
        if(pointer==NULL){
            printf("\n");
            continue;
        }
            
        while(pointer->next_node != NULL){
            pointer = pointer->next_node;
            printf(" -> ");
            node_print(pointer);
        }
        printf("\n");
        
    }
    return;
}

void node_print(Node* node){
    if(node == NULL){
        printf("NULL");
        return;
    }
    printf("%d : %d", node->key, node->value);
    return;
}
