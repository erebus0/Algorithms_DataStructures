#include <bits/stdc++.h>
#define NO_OF_ALPHABET 26

using namespace std;

struct trie_node {
	int node_value;
	int is_end_of_word;
	struct trie_node *children[NO_OF_ALPHABET];
};

struct trie_node *get_node() {
	struct trie_node *new_node = new trie_node;
	new_node->is_end_of_word = 0;
	for(int i = 0; i < NO_OF_ALPHABET; i++)
		new_node->children[i] = NULL;
	return new_node;
}

void insert(struct trie_node *root, char* key, int value) {
	struct trie_node *temp_node = root;
	for(int i = 0; key[i] != '\0'; i++) {
		int index = key[i] - 'a';
		if(!temp_node->children[index])
			temp_node->children[index] = get_node();
		temp_node = temp_node->children[index];
	}
	temp_node->node_value = value;
	temp_node->is_end_of_word = 1;
}

int get_value(struct trie_node *root, char *key) {
	struct trie_node *temp_node = root;
	for(int i = 0; (key[i] != '\0') && temp_node; i++)
		temp_node = temp_node->children[key[i] - 'a'];
	if( (!temp_node) || !(temp_node->is_end_of_word) )
		throw "Key Not Found Exception";
	return temp_node->node_value;
}

int main(int argc, char const *argv[]) {
	struct trie_node *trie = get_node();
	char key[] = "this";
	char key2[] = "ankit";
	char key3[] = "not_present";
	insert(trie, key, 2);
	insert(trie, key2, 100);
	printf("%d %d\n", get_value(trie, key), get_value(trie, key2));
	try{
		printf("%d\n", get_value(trie, key3));
	} catch(const char* s) {
		printf("%s\n", s);
	}
	return 0;
}
