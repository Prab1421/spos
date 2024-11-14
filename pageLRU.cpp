#include <bits/stdc++.h>
using namespace std;

void LRUPageReplacement(vector<int>& pages, int frames){
          unordered_set<int> s;
          unordered_map<int, int> indexes;
          list<int> memory;
          int pageFaults =0;

          for(int i=0; i<pages.size(); i++){
                    int currentPage = pages[i];

                    if(s.size() < frames){
                              if(s.find(currentPage) == s.end()){
                                        s.insert(currentPage);
                                        memory.push_back(currentPage);
                                        pageFaults++;
                              }
                              indexes[currentPage] = i;
                    }else{
                              if(s.find(currentPage) == s.end()){
                                        int lru = INT_MAX, val =1;

                                        for(auto it: s){
                                                  if(indexes[it] < lru){
                                                            lru = indexes[it];
                                                            val = it;
                                                  }
                                        }

                                        s.erase(val);
                                        memory.remove(val);
                                        s.insert(currentPage);
                                        memory.push_back(currentPage);
                                        pageFaults++;
                              }
                              indexes[currentPage] = i;
                    }

                    
                    cout<<"page faults: "<<pageFaults;
                    cout << endl;
          }
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
   LRUPageReplacement(pages, frames);
    return 0;
}

