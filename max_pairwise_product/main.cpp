#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long result = 0;
    long long n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (((long long)numbers[i]) * numbers[j] > result) {
                result = ((long long)numbers[i]) * numbers[j];
            }
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    long n = numbers.size();
    
    int max_index1 = -1;
    for (int i = 0; i < n; ++i)
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
            max_index1 = i;
    
    int max_index2 = -1;
    for (int j = 0; j < n; ++j)
        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
            max_index2 = j;
    
    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
    while (true){
        // generate the length of the input sequence
        int n = rand() % 5 + 2;
        std::cerr << n << '\n';
        // generate the array
        // 1 create the dinami array
        vector<int> inputSequence;
        // 2 fill up the vector with random numbers
        for (int i = 0; i < n; i++) {
            inputSequence.push_back(rand() % 10);
        }
        for (int j = 0; j < n; j++) {
            std::cerr << inputSequence[j] << ' ';
        }
        std::cerr << "\n";
        // 3 generate output for fast and slow solutions
        long long result1 = MaxPairwiseProduct(inputSequence);
        long long result2 = MaxPairwiseProductFast(inputSequence);
        
        
        if (result1 != result2) {
            std::cerr << "Wrong answer: slow= " << result1 << " fast= " << result2 << '\n';
            break;
        } else {
            std::cerr << "OK \n";
        }
    }
    //Commented to run stress testing
//    int n;
//    cin >> n;
//    vector<int> numbers(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> numbers[i];
//    }
//    
////    long long result1 = MaxPairwiseProduct(numbers);
//    long long result1 = MaxPairwiseProductFast(numbers);
//    cout << result1;

    return 0;
}