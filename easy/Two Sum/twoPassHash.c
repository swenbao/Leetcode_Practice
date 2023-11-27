//
//  Created by 筍包 on 2023/11/24.
//  Time : O(n)
//  Space: O(n)
//  best run time: 3ms

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TABLE_SIZE 44721

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
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int hash_func(int key);
void map_insert(Map* map, int key, int value);
int map_search(Map* map, int key);
void free_map(Map* map);

int main(void){
    int nums[] = {-3,4,3,90};
    int numSize = sizeof(nums)/sizeof(int);
    int returnSize;
    int target = 0;
    int* ans = twoSum(nums, numSize, target, &returnSize);

    printf("(");
    for(int i = 0; i < returnSize; i++){
        if(i != returnSize-1)
            printf("%d, ", ans[i]);
        else
            printf("%d", ans[i]);
    }
    printf(")");
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Map* map = create_hash_table(TABLE_SIZE);
    for(int i = 0; i < numsSize; i++){
        map_insert(map, nums[i], i);
    }
    for(int i = 0; i < numsSize; i++){
        int complement = target - nums[i];
        int comp_index = map_search(map, complement);
        if(comp_index != INT_MIN && comp_index != i){
                int *ans;
                ans = malloc(2*sizeof(int));
                ans[0] = i;
                ans[1] = comp_index;
                *returnSize = 2;
                return ans;
        }
    }
    free_map(map);
    *returnSize = 0;
    return 0;
}

Map* create_hash_table(int size){
    Map *map = malloc(sizeof(Map));
    map->size = size;
    map->nodes = (Node**)calloc(size, sizeof(Node*)); // calloc initialize it to zero by default
    return map;
}

int hash_func(int key){
    int index = key % TABLE_SIZE;
    return index < 0 ? index + TABLE_SIZE : index; // Ensure non-negative index
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
    if(new_node == NULL){
        printf("new node fail to malloc");
        exit(-1);
    }
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
