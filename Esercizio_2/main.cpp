#include "SortingAlgorithm.hpp"
#include <iostream>
#include <vector>
#include <chrono>

using namespace SortLibrary;
using namespace std;
using namespace chrono;

int main(int argc, char *argv[])
{
    cout << "Number of vectors: " << argc - 1 << endl;
    cout << endl;

    double avgTimeMerge = 0;
    double avgTimeBubble = 0;

    for(int i = 1; i < argc; i++)
    {
        int n = stoi(argv[i]);
        vector<double> vMerge(n);
        vector<double> vBubble(n);

        srand(time(NULL));

        for(int i = 0; i < n; i++)
        {
            vMerge[i] = double(rand()) / RAND_MAX;
            vBubble[i] = double(rand()) / RAND_MAX;
        }

        steady_clock::time_point t_beginMerge = steady_clock::now();
        MergeSort(vMerge);
        steady_clock::time_point t_endMerge = steady_clock::now();

        steady_clock::time_point t_beginBubble = steady_clock::now();
        BubbleSort(vBubble);
        steady_clock::time_point t_endBubble = steady_clock::now();

        double durationMerge = duration_cast<microseconds>(t_endMerge - t_beginMerge).count();
        double durationBubble = duration_cast<microseconds>(t_endBubble - t_beginBubble).count();

        cout << "Size of the vector number " << i << ": " << n << endl;
        cout << "MergeSort has finished in " << durationMerge << " microseconds." << endl;
        cout << "BubbleSort has finished in " << durationBubble << " microseconds." << endl;

        cout << endl;

        avgTimeMerge += durationMerge;
        avgTimeBubble += durationBubble;
    }

    avgTimeMerge = avgTimeMerge / (argc - 1);
    avgTimeBubble = avgTimeBubble / (argc - 1);

    cout << "Average time of MergeSort: " << avgTimeMerge << " microseconds." << endl;
    cout << "Average time of BubbleSort: " << avgTimeBubble << " microseconds." << endl;

    cout << endl;

    return 0;
}

