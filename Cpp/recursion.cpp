#include <bits/stdc++.h>
#include <string>
using namespace std;

void reverse(string s, int index, string &ans)
{
    // base case
    if (index == s.size())
    {
        return;
    }
    // fxn call
    reverse(s, index + 1, ans);
    // preprocessing
    ans += s[index];
}
void revString(string &s, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(s[start], s[end]);
    revString(s, start + 1, end - 1);
}
bool checkPal(string s, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (s[i] != s[j])
        return false;
    return checkPal(s, i + 1, j - 1);
}

int power(int x, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return x;

    int ans = power(x, p / 2);

    if (p % 2 == 0)
    {
        // even
        return ans * ans;
    }
    else
    {
        // odd
        return x * ans * ans;
    }
}

void BubbleSort(int *arr, int i, int n)
{
    // base case(Number of round reach)
    if (i == n - 1)
    {
        return;
    }
    // place ith largest to right most place in array
    bool isswap = false;
    for (int j = 0; j < n - i - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            isswap = true;
        }
    }
    // optimization(Puraa array  sorted hai)
    if (isswap == false)
        return;
    // recursive call
    BubbleSort(arr, i + 1, n);
}
void SelctionSort(int *arr, int i, int n)
{
    // (base case)for last element
    if (i == n - 1)
    {
        return;
    }
    // find min and swap with ith index element
    int mn_index = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[mn_index])
        {
            mn_index = j;
        }
    }
    swap(arr[i], arr[mn_index]);
    // recursive call
    SelctionSort(arr, i + 1, n);
}
void insertSionSort(int *arr, int n, int i)
{
    // base case
    if (i == n)
    {
        return;
    }
    // place ith element to left as if less then i-1 th elements
    int j = i;
    int ele = arr[i];
    while (j > 0 && ele < arr[j - 1])
    {
        arr[j] = arr[j - 1];
        j--;
    }
    arr[j] = ele;
    // recusive call
    insertSionSort(arr, n, i + 1);
}
int main()
{

    string s, rs;
    cin >> s;

    reverse(s, 0, rs);
    cout << "Reverse of string -> " << rs << endl;
    revString(s, 0, s.size() - 1);
    cout << "Reverse of string -> " << s << endl;

    cout << "Is palindrom = " << (checkPal(s, 0, s.size() - 1) ? "Yes" : "NO") << endl;

    int x, p;
    cin >> x >> p;

    int ans = power(x, p);

    cout << x << " to power " << p << " = " << ans << endl;

    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before sorting -> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // BubbleSort(arr,0,n);
    // SelctionSort(arr,0,n);
    insertSionSort(arr, n, 1);
    cout << "Array After sorting -> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
