#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Implement Stack Using Array
class Stack {
    int arr[100], topIdx;
public:
    Stack() : topIdx(-1) {}

    void push(int x) {
        if (topIdx >= 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIdx] = x;
    }

    void pop() {
        if (topIdx == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        topIdx--;
    }

    int top() {
        if (topIdx == -1)
            return -1;
        return arr[topIdx];
    }

    bool empty() {
        return topIdx == -1;
    }
};

void testStack() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
}

// Valid Parentheses
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if (st.empty() || (c == ')' && st.top() != '(') ||
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '['))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

void testValidParentheses() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
}

// Reverse a String Using Stack
string reverseStr(string s) {
    stack<char> st;
    for (char c : s)
        st.push(c);

    string rev = "";
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }
    return rev;
}

void testReverseString() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Reversed: " << reverseStr(s) << endl;
}

// Sort a Stack Using Recursion
void insert(stack<int>& st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insert(st, x);
    st.push(top);
}

void sortStack(stack<int>& st) {
    if (!st.empty()) {
        int x = st.top();
        st.pop();
        sortStack(st);
        insert(st, x);
    }
}

void testSortStack() {
    stack<int> st;
    st.push(30);
    st.push(10);
    st.push(50);
    st.push(20);

    sortStack(st);

    cout << "Sorted Stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Medium Questions

// Next Greater Element
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

void testNextGreaterElement() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> res = nextGreater(arr);

    cout << "Next Greater Elements: ";
    for (int x : res)
        cout << x << " ";
    cout << endl;
}

// Stock Span Problem
vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n, 1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }
        span[i] = (st.empty() ? i + 1 : i - st.top());
        st.push(i);
    }
    return span;
}

void testStockSpan() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stockSpan(prices);

    cout << "Stock Spans: ";
    for (int x : res)
        cout << x << " ";
    cout << endl;
}

// Evaluate Postfix Expression
int evalPostfix(string expr) {
    stack<int> st;

    for (char c : expr) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

void testEvalPostfix() {
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;
    cout << "Postfix Evaluation: " << evalPostfix(expr) << endl;
}

// Min Stack
class MinStack {
    stack<int> st, minSt;

public:
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

void testMinStack() {
    MinStack s;
    s.push(10);
    s.push(20);
    s.push(5);
    cout << "Min: " << s.getMin() << endl;
    s.pop();
    cout << "Min after pop: " << s.getMin() << endl;
}

// Hard Questions

// Largest Rectangle in Histogram
int largestRectangle(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int h = (i == n ? 0 : heights[i]);
        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = (st.empty() ? i : i - st.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

void testLargestRectangle() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangle(heights) << endl;
}

// Trapping Rain Water
int trapWater(vector<int>& heights) {
    int n = heights.size();
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0, water = 0;

    while (left <= right) {
        if (heights[left] < heights[right]) {
            if (heights[left] >= leftMax)
                leftMax = heights[left];
            else
                water += leftMax - heights[left];
            left++;
        } else {
            if (heights[right] >= rightMax)
                rightMax = heights[right];
            else
                water += rightMax - heights[right];
            right--;
        }
    }
    return water;
}

void testTrapWater() {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Water: " << trapWater(heights) << endl;
}

// Remove K Digits
string removeKDigits(string num, int k) {
    stack<char> st;
    for (char c : num) {
        while (!st.empty() && k > 0 && st.top() > c) {
            st.pop();
            k--;
        }
        st.push(c);
    }
    while (k-- > 0)
        st.pop();

    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    while (res[0] == '0' && res.size() > 1)
        res.erase(res.begin());
    return res.empty() ? "0" : res;
}

void testRemoveKDigits() {
    string num;
    int k;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Smallest Number: " << removeKDigits(num, k) << endl;
}

// Longest Valid Parentheses
int longestValid(string s) {
    stack<int> st;
    st.push(-1);
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop
