#include <bits/stdc++.h>
using namespace std;

void fifoPageReplacement(vector<int>& pages, int frames) {
    unordered_set<int> s;
    queue<int> pageQueue;
    vector<int> frameContents(frames, -1);
    int pageFaults = 0;
    int pageHits = 0;

    for (int page : pages) {
        if (s.find(page) == s.end()) {
            if (s.size() < frames) {
                s.insert(page);
                pageQueue.push(page);
                frameContents[s.size() - 1] = page;
            } else {
                int oldPage = pageQueue.front();
                pageQueue.pop();
                s.erase(oldPage);

                s.insert(page);
                pageQueue.push(page);

                for (int i = 0; i < frames; i++) {
                    if (frameContents[i] == oldPage) {
                        frameContents[i] = page;
                        break;
                    }
                }
            }
            pageFaults++;
        } else {
            pageHits++;
        }
    }
    cout << "\nPage Faults: " << pageFaults << "\nPage Hits: " << pageHits << endl;
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
    fifoPageReplacement(pages, frames);
    return 0;
}
