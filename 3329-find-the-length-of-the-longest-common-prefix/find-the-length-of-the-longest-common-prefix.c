typedef struct TrieNode {
    struct TrieNode *child[10];
} TrieNode;

TrieNode* createNode() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));

    for (int i = 0; i < 10; i++) {
        node->child[i] = NULL;
    }

    return node;
}

void insert(TrieNode *root, int num) {
    char str[12];
    sprintf(str, "%d", num);

    TrieNode *curr = root;

    for (int i = 0; str[i] != '\0'; i++) {
        int digit = str[i] - '0';

        if (curr->child[digit] == NULL) {
            curr->child[digit] = createNode();
        }

        curr = curr->child[digit];
    }
}

int getPrefixLength(TrieNode *root, int num) {
    char str[12];
    sprintf(str, "%d", num);

    TrieNode *curr = root;
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        int digit = str[i] - '0';

        if (curr->child[digit] == NULL) {
            break;
        }

        len++;
        curr = curr->child[digit];
    }

    return len;
}

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    TrieNode *root = createNode();

    for (int i = 0; i < arr1Size; i++) {
        insert(root, arr1[i]);
    }

    int ans = 0;

    for (int i = 0; i < arr2Size; i++) {
        int len = getPrefixLength(root, arr2[i]);

        if (len > ans) {
            ans = len;
        }
    }

    return ans;
}