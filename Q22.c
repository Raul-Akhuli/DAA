#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h> // Include the regex header

typedef struct Node {
    char *word;
    struct Node *next;
    char **documents;
    int num_documents;
} Node;

typedef struct HashTable {
    Node **table;
    int size;
} HashTable;

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

HashTable *create_hash_table(int size) {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (Node **)calloc(size, sizeof(Node *));
    return ht;
}

void add_document(HashTable *ht, char *document) {
    regex_t regex;
    regcomp(&regex, "\\w+", REG_EXTENDED); // Compile the regular expression

    regmatch_t match;
    char *str = document;
    while (!regexec(&regex, str, 1, &match, 0)) {
        char *word = (char *)malloc(match.rm_eo - match.rm_so + 1);
        strncpy(word, str + match.rm_so, match.rm_eo - match.rm_so);
        word[match.rm_eo - match.rm_so] = '\0';

        unsigned long hash_value = hash(word) % ht->size;
        Node *node = ht->table[hash_value];
        Node *prev = NULL;

        while (node != NULL) {
            if (strcmp(node->word, word) == 0) {
                node->documents = (char **)realloc(node->documents, (node->num_documents + 1) * sizeof(char *));
                node->documents[node->num_documents] = strdup(document);
                node->num_documents++;
                break;
            }
            prev = node;
            node = node->next;
        }

        if (node == NULL) {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->word = strdup(word);
            new_node->documents = (char **)malloc(sizeof(char *));
            new_node->documents[0] = strdup(document);
            new_node->num_documents = 1;
            new_node->next = NULL;

            if (prev != NULL) {
                prev->next = new_node;
            } else {
                ht->table[hash_value] = new_node;
            }
        }

        free(word);
        str += match.rm_eo;
    }

    regfree(&regex); // Free the regular expression resources
}

void check_for_plagiarism(HashTable *ht, char *document) {
    regex_t regex;
    regcomp(&regex, "\\w+", REG_EXTENDED); // Compile the regular expression

    regmatch_t match;
    char *str = document;
    while (!regexec(&regex, str, 1, &match, 0)) {
        char *word = (char *)malloc(match.rm_eo - match.rm_so + 1);
        strncpy(word, str + match.rm_so, match.rm_eo - match.rm_so);
        word[match.rm_eo - match.rm_so] = '\0';

        unsigned long hash_value = hash(word) % ht->size;
        Node *node = ht->table[hash_value];

        while (node != NULL) {
            if (strcmp(node->word, word) == 0) {
                for (int i = 0; i < node->num_documents; i++) {
                    if (strcmp(node->documents[i], document) != 0) {
                        printf("Found plagiarism: %s copied from %s\n", document, node->documents[i]);
                    }
                }
                break;
            }
            node = node->next;
        }

        free(word);
        str += match.rm_eo;
    }

    regfree(&regex); // Free the regular expression resources
}

int main() {
    HashTable *ht = create_hash_table(100);

    add_document(ht, "This is the first document.");
    add_document(ht, "This is the second document.");

    check_for_plagiarism(ht, "This is the first document.");
    check_for_plagiarism(ht, "This is the second document.");

    return 0;
}
