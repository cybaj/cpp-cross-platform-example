#include "MyStandaloneUELibrary/MyLibraryHeader.h"

int main() {
    MyStandaloneUELibrary::MyLibraryClass myLibInstance;
    myLibInstance.MyFunction();  // This should print the platform-specific "Hello World" message.
    return 0;
}

