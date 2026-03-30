#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) 
    {
        std::cin >> arr[i];
    }
    
    int k;
    std::cin >> k;
    
    std::vector<std::pair<int, int>> heap;
    
    auto comparator = [](const std::pair<int, int>& a, const std::pair<int, int>& b) 
    {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    };
    
    std::vector<int> result;
    

    for (int i = 0; i < k; i++) 
    {
        heap.push_back({arr[i], i});

        push_heap(heap.begin(), heap.end(), comparator);
    }

    result.push_back(heap[0].first);
    
    for (int i = k; i < n; i++) 
    {

        heap.push_back({arr[i], i});

        push_heap(heap.begin(), heap.end(), comparator);
        
        while (!heap.empty() && heap[0].second <= i - k) 
        {
            pop_heap(heap.begin(), heap.end(), comparator);

            heap.pop_back();
        }
        
        result.push_back(heap[0].first);
    }


    for (auto i = 0; i < result.size(); i++) 
    {
        std::cout << result[i];
        if (i != result.size() - 1) 
        {
            std::cout << " ";
        }
    }

    std::cout << "\n";
    
    return 0;
}
