
// .Fibonacci Series Using Recursion 
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 2;
    cout << "Input: n = " << n << endl;
    cout << "Output: " << fibonacci(n) << endl;
    return 0;
}       
//     Reverse Linked List
 #include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);
    cout << "Reversed List: ";
    printList(head);

    return 0;
}
//Add Two Numbers
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
    }

    if (carry > 0) {
        temp->next = new ListNode(carry);
    }

    return head->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = addTwoNumbers(l1, l2);
    cout << "Result: ";
    printList(result);

    return 0;
}
// Wildcard Matching
#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    cout << isMatch("aa", "a") << endl;           // Output: 0 (false)
    cout << isMatch("aa", "*") << endl;           // Output: 1 (true)
    cout << isMatch("cb", "?a") << endl;          // Output: 0 (false)
    cout << isMatch("adceb", "*a*b") << endl;     // Output: 1 (true)
    cout << isMatch("acdcb", "a*c?b") << endl;    // Output: 0 (false)
    return 0;
}
// Special Binary String
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string makeLargestSpecial(string s) {
    vector<string> specials;
    int count = 0, start = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') count++;
        else count--;

        if (count == 0) {
            string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
            specials.push_back("1" + inner + "0");
            start = i + 1;
        }
    }

    sort(specials.rbegin(), specials.rend());

    string result;
    for (const string& special : specials) {
        result += special;
    }

    return result;
}

int main() {
    cout << makeLargestSpecial("11011000") << endl; // Output: "11100100"
    cout << makeLargestSpecial("10") << endl;       // Output: "10"
    return 0;
}
