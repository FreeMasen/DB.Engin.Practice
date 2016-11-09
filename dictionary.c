#include <stdio.h>
#include <string.h>

#define HASHSIZE 107

typedef struct {
    unsigned key;
    char *value;
} KeyValuePair;

typedef struct {
    KeyValuePair value;
    KeyValuePair *next; 
} Element;

typedef struct {
    Element elements[HASHSIZE];
    int length;
} Dictionary;

unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
    {   
        hashval = *s + 31 * hashval;
    }
    //printf("Return hashval: %d\n", hashval);
    return hashval % HASHSIZE;
}

static Dictionary dict = { .length = 0};

Element createElement(char *key, char *value);

main(void) {
    printf("Enter main\n");
    printf("Static Dict: {pairs: %s length: %i}\n", dict.elements, dict.length);
    printf("creating element\n");
    Element test;
    test = createElement("name", "robert");
    printf("Test Element: value: {%s, %s}\n", test.value.key, test.value.value);
    //printf("Static Dict: {pairs: %s, length: %i}\n", dict.elements, dict.length);
    return 0;
}

Element createElement(char *key, char *value) {
    KeyValuePair newPair;
    newPair.key = hash(key);
    newPair.value = value;
    Element newElement;
    newElement.value = newPair;
    return newElement;
}