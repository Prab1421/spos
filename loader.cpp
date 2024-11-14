#include <iostream>
#include <vector>
#include <string>

// Structure to represent a memory segment
struct MemorySegment {
    std::string segmentName;
    int baseAddress;
    int size;
};

// Class representing the Loader
class Loader {
private:
    std::vector<MemorySegment> memorySegments;
    int totalMemorySize;

public:
    // Constructor to initialize the Loader
    Loader(int memorySize) : totalMemorySize(memorySize) {}

    // Method to load a segment into memory
    bool loadSegment(const std::string& name, int baseAddress, int size) {
        if (baseAddress + size > totalMemorySize) {
            std::cout << "Error: Segment " << name << " exceeds memory limits.\n";
            return false;
        }

        // Check for overlapping segments
        for (const auto& segment : memorySegments) {
            if ((baseAddress >= segment.baseAddress && baseAddress < segment.baseAddress + segment.size) ||
                (baseAddress + size > segment.baseAddress && baseAddress + size <= segment.baseAddress + segment.size)) {
                std::cout << "Error: Segment " << name << " overlaps with segment " << segment.segmentName << ".\n";
                return false;
            }
        }

        // Add the segment to memory
        MemorySegment newSegment = {name, baseAddress, size};
        memorySegments.push_back(newSegment);
        std::cout << "Segment " << name << " loaded successfully.\n";
        return true;
    }

    // Method to display loaded memory segments
    void displayMemoryLayout() const {
        std::cout << "\nMemory Layout:\n";
        for (const auto& segment : memorySegments) {
            std::cout << "Segment: " << segment.segmentName 
                      << ", Base Address: " << segment.baseAddress 
                      << ", Size: " << segment.size << " units\n";
        }
    }
};

int main() {
    // Create a Loader with 1000 units of memory
    Loader loader(1000);

    // Load some segments into memory
    loader.loadSegment("Code", 0, 400);
    loader.loadSegment("Data", 400, 300);
    loader.loadSegment("Stack", 800, 200);

    // Try to load a segment that exceeds memory size
    loader.loadSegment("LargeSegment", 900, 200);

    // Try to load an overlapping segment
    loader.loadSegment("OverlapSegment", 350, 100);

    // Display the memory layout
    loader.displayMemoryLayout();

    return 0;
}
