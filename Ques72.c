/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node* cloneGraph(struct Node* s) {
    if (!s) return NULL;
    struct Node** map = (struct Node**)calloc(101, sizeof(struct Node*));
    struct Node** q = (struct Node**)malloc(101 * sizeof(struct Node*));
    int front = 0, rear = 0;
    struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
    copy->val = s->val;
    copy->numNeighbors = s->numNeighbors;
    copy->neighbors = (struct Node**)malloc(s->numNeighbors * sizeof(struct Node*));
    map[s->val] = copy;
    q[rear++] = s;
    while (front < rear) {
        struct Node* node = q[front++];
        struct Node* nodeCopy = map[node->val];
        nodeCopy->numNeighbors = node->numNeighbors;
        nodeCopy->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));
        for (int i = 0; i < node->numNeighbors; i++) {
            struct Node* nei = node->neighbors[i];
            if (!map[nei->val]) {
                struct Node* neiCopy = (struct Node*)malloc(sizeof(struct Node));
                neiCopy->val = nei->val;
                neiCopy->numNeighbors = nei->numNeighbors;
                neiCopy->neighbors = (struct Node**)malloc(nei->numNeighbors * sizeof(struct Node*));
                map[nei->val] = neiCopy;
                q[rear++] = nei;
            }
            nodeCopy->neighbors[i] = map[nei->val];
        }
    }
    free(q);
    return copy;
}
