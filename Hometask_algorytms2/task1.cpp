#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int64_t> heap;
    
    for (int i = 0; i < n; i++) 
    {
        int64_t x;
        std::cin >> x;
        heap.push_back(x);
        push_heap(heap.begin(), heap.end(), std::greater<int64_t>());
    }
    
    int64_t result = 0;
    
    while (heap.size() > 1) 
    {

        pop_heap(heap.begin(), heap.end(), std::greater<int64_t>());
        int64_t a = heap.back(); 
        heap.pop_back();
        
        pop_heap(heap.begin(), heap.end(), std::greater<int64_t>());
        int64_t b = heap.back(); 
        heap.pop_back();
        
        int64_t sum = a + b;
        result += sum;
        
        heap.push_back(sum);
        push_heap(heap.begin(), heap.end(), std::greater<int64_t>());
    }
    
    std::cout << result << "\n";
    
    return 0;
}
