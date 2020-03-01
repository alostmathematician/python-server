#ifndef _GAME_HASH_MAP_H_
#define _GAME_HASH_MAP_H_
#define KEYWORD_SIZE 15
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../lex/general.h"

static char keyword[KEYWORD_SIZE][10]={"int","char","void","extern","if","else",
                                "switch","default","case","while","do","for",
                                "break","continue","return"};

static Tag tag[KEYWORD_SIZE]={KW_INT,KW_CHAR,KW_VOID,KW_EXTERN,KW_IF,KW_ELSE,
                              KW_SWITCH,KW_DEFAULT,KW_CASE,KW_WHILE,KW_DO,KW_FOR,
                              KW_BREAK,KW_CONTINUE,KW_RETURN};


typedef struct
{
    char* keyword;
    int hash_value;
    Tag tag;
}Map;

struct HashNode
{
    Map current_map;
    struct HashNode* next_node;
};

typedef struct 
{
    bool occupied;
    struct HashNode node;
}Hash;

Hash nodes[KEYWORD_SIZE];

void init_hashmap(void);
bool is_occupied(Hash);
int map_hash(int);
void hash_append(struct HashNode*,Map);
Tag hash_find(const char*);

#endif