#include <iostream>
int main()
{
    int n, input_data;
    std::cin >> n;
    int A[10000], B[10000];
    for (int i = 0; i < n; i ++)
    {
        std::cin >> input_data;
        A[i] = input_data;
        B[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (B[A[i]] == 1)
        {
            std::cout << A[i] << "\n";
            return 0;
        }
        B[A[i]] = 1;
    }
    std::cout << 0 << "\n";
    return 0;
}
