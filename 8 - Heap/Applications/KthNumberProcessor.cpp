#include <iostream>
#include "MinHeap.h"

using namespace std;

/**
 * @brief Processor to find the K-th LARGEST number efficiently using MinHeap.
 */
class KthNumberProcessor {
private:
    int k;
    MinHeap q; 

public:
    KthNumberProcessor(int k) : k(k) {}

    int next(int new_num) {
        if (q.sz() < k) {
            q.push(new_num);
        }
       
        else if (new_num > q.top()) { 
            q.pop(); 
            q.push(new_num); 
        }
        
        return q.top(); 
    }
};


int main() {
    KthNumberProcessor processor(3);
    cout << processor.next(10) << "\n";
    cout << processor.next(20) << "\n";
    cout << processor.next(5) << "\n";
    cout << processor.next(30) << "\n"; 
    return 0;
}