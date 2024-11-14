#include <bits/stdc++.h>
using namespace std;

void removeComments(const string& inFile, const string& outFile) {
    ifstream inputFile(inFile);
    ofstream outputFile(outFile);
    
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return;
    }
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return;
    }

    string line;
    bool Comments = false;

    while (getline(inputFile, line)) {
        string nline;
        int len = line.size();
        
        for (int i = 0; i < len; ++i) {
            if (Comments) {
                if (i + 1 < len && line[i] == '*' && line[i + 1] == '/') {
                    Comments = false;
                    i++;
                }
            } else if (i + 1 < len && line[i] == '/' && line[i + 1] == '*') {
                Comments = true;
                i++;
            } else if (i + 1 < len && line[i] == '/' && line[i + 1] == '/') {
                break; // Ignore the rest of the line for single-line comment
            } else {
                nline += line[i];
            }
        }
        
        if (!Comments && !nline.empty()) {
            outputFile << nline << endl;
        }
    }

    inputFile.close();
    outputFile.close();
    cout << "Comments removed successfully. Output saved to " << outFile << endl;
}

int main() {
    string inFile, outFile;
    cout << "Enter input file path: ";
    cin >> inFile;
    cout << "Enter output file path: ";
    cin >> outFile;

    removeComments(inFile, outFile);

    return 0;
}
