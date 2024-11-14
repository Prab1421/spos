#include <bits/stdc++.h>
using namespace std;

void optimalPageReplacement(vector<int>& pages, int frames) {
    unordered_set<int> s;
    vector<int> memory;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int currentPage = pages[i];
        if (s.find(currentPage) == s.end()) {
            pageFaults++;
            if (s.size() < frames) {
                s.insert(currentPage);
                memory.push_back(currentPage);
            } else {
                int farthestIndex = -1, pageToReplace = -1;
                for (int j = 0; j < memory.size(); j++) {
                    int page = memory[j];
                    int nextUseIndex = INT_MAX;
                    for (int k = i + 1; k < pages.size(); k++) {
                        if (pages[k] == page) {
                            nextUseIndex = k;
                            break;
                        }
                    }

                    if (nextUseIndex > farthestIndex) {
                        farthestIndex = nextUseIndex;
                        pageToReplace = j;
                    }
                }

                s.erase(memory[pageToReplace]);
                s.insert(currentPage);
                memory[pageToReplace] = currentPage;
            }
        }

        cout << "Page " << currentPage << " is in the frame. Frame Contents: ";
        for (int f : memory) {
            cout << f << " ";
        }
        cout << endl;
    }

    cout << "Total Page Faults = " << pageFaults << endl;
}

int main() {
    int n, frames;
    cout << "Enter the number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter the pages: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    cout << "Enter the number of frames: ";
    cin >> frames;
    optimalPageReplacement(pages, frames);
    return 0;
}
