#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. HASH MAP (Separate Chaining)
// ==========================================
struct HashNode {
    int key;
    string value;
    HashNode* next;
};

const int SIZE = 10;
HashNode* hashTable[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = nullptr;
    }
}

int hashFunction(int key) {
    return (key % SIZE + SIZE) % SIZE;
}

void insertHash(int key, string value) {
    int index = hashFunction(key);
    HashNode* newNode = new HashNode{key, value, hashTable[index]};
    hashTable[index] = newNode;
    cout << "Hash Map: Insert (" << key << ", " << value << ") di indeks " << index << "\n";
}

// ==========================================
// 2. STACK (LIFO) menggunakan Array
// ==========================================
const int MAX = 5;
int stackArr[MAX];
int topIdx = -1;

void pushStack(int x) {
    if (topIdx == MAX - 1) {
        cout << "Stack penuh!\n";
        return;
    }
    stackArr[++topIdx] = x;
    cout << "Stack: Push " << x << " berhasil\n";
}

// ==========================================
// 3. QUEUE (FIFO) menggunakan Array
// ==========================================
int queueArr[MAX];
int frontIdx = -1, rearIdx = -1;

void enqueue(int x) {
    if ((rearIdx + 1) % MAX == frontIdx) {
        cout << "Queue penuh!\n";
        return;
    }
    if (frontIdx == -1) frontIdx = rearIdx = 0;
    else rearIdx = (rearIdx + 1) % MAX;
    queueArr[rearIdx] = x;
    cout << "Queue: Enqueue " << x << " berhasil\n";
}

// ==========================================
// 4. BINARY SEARCH TREE (BST)
// ==========================================
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->key) root->left = insertBST(root->left, key);
    else if (key > root->key) root->right = insertBST(root->right, key);
    return root;
}

void inorderBST(TreeNode* root) {
    if (!root) return;
    inorderBST(root->left);
    cout << root->key << " ";
    inorderBST(root->right);
}

// ==========================================
// 5. SORTING & SEARCHING (Vector & Array)
// ==========================================
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {
    cout << "=== PROGRAM INTEGRASI STRUKTUR DATA ===\n\n";

    // 1. Hash Map
    initTable();
    insertHash(101, "Ary Nanda");
    insertHash(205, "Teknik Informatika");

    // 2. Stack
    cout << "\n";
    pushStack(10);
    pushStack(20);

    // 3. Queue
    cout << "\n";
    enqueue(1);
    enqueue(2);

    // 4. BST
    cout << "\nBST: Insert 50, 30, 70\n";
    TreeNode* root = nullptr;
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    cout << "Traversal Inorder BST: ";
    inorderBST(root);
    cout << "\n";

    // 5. Vector, Sorting, and Searching
    cout << "\nVector (Sebelum Sort): 40, 12, 18, 7, 25\n";
    vector<int> data = {40, 12, 18, 7, 25};
    
    bubbleSort(data);
    cout << "Vector (Setelah Bubble Sort): ";
    for (int num : data) cout << num << " ";
    cout << "\n";

    int target = 18;
    int searchIndex = binarySearch(data, target);
    if (searchIndex != -1) {
        cout << "Binary Search: Angka " << target << " ditemukan pada indeks ke-" << searchIndex << "\n";
    } else {
        cout << "Binary Search: Angka " << target << " tidak ditemukan\n";
    }

    return 0;
}