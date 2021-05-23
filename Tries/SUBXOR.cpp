/*
A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases.
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Sample Input
1
5 2
4 1 3 2 7
Sample Output
3*/
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100005;
const int MAX_BITS = 20;
/*
 x ^ pref[now] < K

 */

struct node {
    int sum;
    node* l;
    node* r;
    node () {

    }
};
typedef node* pnode;

int get(pnode &p) {
    return p ? p->sum : 0;
}
pnode initialize(int value) {
    pnode p = (pnode)malloc(sizeof(node));
    p->sum = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void add(pnode &p, int value) {
    pnode current = p;
    for (int i = MAX_BITS; i >= 0; i --) {
        int bit = (value >> i) & 1;
        if (!bit) {
            if (!current->l) {
                current->l = initialize(0);
            }
            current = current->l;
        }
        else {
            if (!current->r) {
                current->r = initialize(0);
            }
            current = current->r;
        }
        current->sum ++;
    }
}
int get(pnode &p, int prefix, int value) {
    int result = 0;
    pnode current = p;
    for (int i = MAX_BITS; i >= 0; i --) {
        if (!current) {
            break;
        }
        int prefixBit = (prefix >> i) & 1;
        int bit = (value >> i) & 1;
        if (prefixBit == bit) {
            if (prefixBit == 1) {
                result += get(current->r);
            }
            current = current->l;
        }
        else {
            if (prefixBit == 0) {
                result += get(current->l);
            }
            current = current->r;
        }
    }
    return result;
}

int T, N, K;
int data[MAX], prefix[MAX];
pnode root;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T --) {
        cin >> N >> K;
        for (int i = 1; i <= N; i ++) {
            cin >> data[i];
        }
        root = initialize(0);
        add(root, 0);
        long long result = 0;
        for (int i = 1; i <= N; i ++) {
            prefix[i] = prefix[i - 1] ^ data[i];
            result += get(root, prefix[i], K);
            add(root, prefix[i]);
        }
        cout << result << endl;
    }

    return 0;
}
