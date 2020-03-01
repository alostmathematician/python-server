#include "hash_map.h"

bool is_occupied(Hash hash)
{
    return hash.occupied;
}

int map_hash(int value)
{
    while (value >= KEYWORD_SIZE)
    {
        value %= KEYWORD_SIZE;
    }
    return value;
}
void hash_append(struct HashNode* node,Map map)
{
    while (node->next_node != NULL)
    {
        node=node->next_node;
    }
    struct HashNode* last_node=(struct HashNode*)malloc(sizeof(struct HashNode));
    last_node->current_map=map;
    last_node->next_node=NULL;
    node->next_node=last_node;
}

void init_hashmap(void)
{
    int i;
    for (i=0;i<KEYWORD_SIZE;i++)
    {
        nodes[i].occupied=false;
    }

    for (i=0;i<KEYWORD_SIZE;i++)
    {
        Map map;
        map.keyword=keyword[i];
        map.tag=tag[i];
        int j;
        int temp=0;
        for (j=0;j<strlen(map.keyword);j++)
        {
            temp+=map.keyword[j];
        }
        map.hash_value=map_hash(temp);
        if (!is_occupied(nodes[map.hash_value]))
        {
            nodes[map.hash_value].occupied=true;
            nodes[map.hash_value].node.current_map=map;
            nodes[map.hash_value].node.next_node=NULL;
        }
        else
        {
            hash_append(&nodes[map.hash_value].node,map);
        }
        
    }
}

Tag hash_find(const char* str)
{
    int temp=0;
    int i;
    for (i=0;i<strlen(str);i++)
    {
        temp+=str[i];
    }
    int hash_value=map_hash(temp);
    if (nodes[hash_value].occupied)
    {
        struct HashNode* node=&nodes[hash_value].node;
        do
        {
            if (strcmp(node->current_map.keyword,str) == 0)
                return node->current_map.tag;
            node=node->next_node;
        } while (node != NULL);
        return ID;
    }
    else
    {
        return ID;
    }
    
}