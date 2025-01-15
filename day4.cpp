// 1. Sum of First N Numbers
#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << sum(n);
    return 0;
}

// 2. Factorial
#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}

// 3. Print Array Elements
#include <iostream>
using namespace std;

void printArray(int arr[], int n, int i)
{
    if (i == n)
        return;
    cout << arr[i] << " ";
    printArray(arr, n, i + 1);
}

int main()
{
    int n;
    cout << "Number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArray(arr, n, 0);
    return 0;
}

// 4. Reverse a String
#include <iostream>
using namespace std;

void reverse(string &str, int i, int j)
{
    if (i >= j)
        return;
    swap(str[i], str[j]);
    reverse(str, i + 1, j - 1);
}

int main()
{
    string str;
    cin >> str;
    reverse(str, 0, str.size() - 1);
    cout << str;
    return 0;
}

// 5. Fibonacci Series
#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << fibonacci(i) << " ";
    return 0;
}

// 6. Power of a Number
#include <iostream>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main()
{
    int a, b;
    cout << "Enter Base: ";
    cin >> a;
    cout << "Enter Power: ";
    cin >> b;
    cout << power(a, b);
    return 0;
}

// 7. GCD of Two Numbers
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    cout << "Enter two elements: ";
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}

// 8. Check Palindrome
#include <iostream>
using namespace std;

bool isPalindrome(string str, int i, int j)
{
    if (i >= j)
        return true;
    if (str[i] != str[j])
        return false;
    return isPalindrome(str, i + 1, j - 1);
}

int main()
{
    string str;
    cin >> str;
    cout << (isPalindrome(str, 0, str.size() - 1) ? "true" : "false");
    return 0;
}

// 9. Towers of Hanoi
#include <iostream>
using namespace std;

void hanoi(int n, char source, char target, char auxiliary)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    hanoi(n - 1, auxiliary, target, source);
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}

// 10. Subset Sum Problem
#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (arr[n - 1] > sum)
        return subsetSum(arr, n - 1, sum);
    return subsetSum(arr, n - 1, sum) || subsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int n, sum;
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the set: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the sum to check: ";
    cin >> sum;
    if (subsetSum(arr, n, sum))
        cout << "Found a subset with the given sum";
    else
        cout << "No subset with the given sum";
    return 0;
}
