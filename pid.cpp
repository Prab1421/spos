#include <iostream> 
#include <unistd.h>  // For fork(), getpid(), and getppid() 
#include <sys/types.h>  // For pid_t 
#include <sys/wait.h>  // For wait() 
 
using namespace std; 
 
int main() { 
    // Creating a child process using fork() 
    pid_t pid = fork(); 
 
    if (pid < 0) { 
        // Error occurred during fork() 
        cerr << "Fork failed!" << endl; 
        return 1; 
    }  
    else if (pid == 0) { 
        // Child process code 
        cout << "Child Process:" << endl; 
        cout << "PID (Child): " << getpid() << endl;    // Get Process ID of child 
        cout << "PPID (Parent of Child): " << getppid() << endl;  // Get Parent Process ID (Parent of child) 
    }  
    else { 
        // Parent process code 
        cout << "Parent Process:" << endl; 
        cout << "PID (Parent): " << getpid() << endl;   // Get Process ID of parent 
        cout << "PPID (Parent of Parent): " << getppid() << endl; 
 
        // Wait for the child process to finish 
wait(NULL); 
cout << "Child process has completed." << endl; 
} 
return 0; 
}