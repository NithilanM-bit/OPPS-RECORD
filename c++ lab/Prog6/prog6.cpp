
#include <iostream>
#include <memory>
using namespace std;

// Resource class
class Resource
{
public:
    Resource()
    {
        cout << "Resource acquired" << endl;
    }

    ~Resource()
    {
        cout << "Resource released" << endl;
    }

    void use()
    {
        cout << "Resource is being used" << endl;
    }
};

// Manual Smart Pointer using RAII
class MySmartPointer
{
private:
    Resource* ptr;

public:
    MySmartPointer(Resource* p)
    {
        ptr = p;
    }

    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual smart pointer destroyed" << endl;
    }

    Resource* operator->()
    {
        return ptr;
    }

    // Disable copying to avoid double deletion
    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;
};

int main()
{
    cout << "----- Manual RAII Smart Pointer -----" << endl;
    {
        MySmartPointer smartPtr(new Resource());
        smartPtr->use();
    }

    cout << "\n----- unique_ptr -----" << endl;
    {
        unique_ptr<Resource> uniquePtr =
        make_unique<Resource>();

        uniquePtr->use();

        // Additional feature: Check ownership
        cout << "Unique Pointer Owns Resource: "
             << (uniquePtr != nullptr ? "Yes" : "No")
             << endl;
    }

    cout << "\n----- shared_ptr -----" << endl;
    {
        shared_ptr<Resource> sharedPtr1 =
        make_shared<Resource>();

        shared_ptr<Resource> sharedPtr2 = sharedPtr1;

        sharedPtr1->use();

        cout << "Shared Pointer Count: "
             << sharedPtr1.use_count() << endl;

        // ADDITIONAL FEATURE 1: REFERENCE COUNT DEMONSTRATION

        cout << "\nReference Count Demonstration:" << endl;

        cout << "Initial Shared Pointers: "
             << sharedPtr1.use_count() << endl;

        {
            shared_ptr<Resource> sharedPtr3 = sharedPtr1;

            cout << "After creating third pointer: "
                 << sharedPtr1.use_count() << endl;
        }

        cout << "After third pointer is destroyed: "
             << sharedPtr1.use_count() << endl;
    }

    // ADDITIONAL FEATURE 2: MEMORY MANAGEMENT COMPARISON

    cout << "\n----- Memory Management Comparison -----" << endl;

    cout << "Manual RAII: Memory released by destructor." << endl;

    cout << "unique_ptr: Exclusive ownership." << endl;

    cout << "shared_ptr: Shared ownership using reference counting." << endl;

    cout << "\nProgram completed successfully." << endl;

    return 0;
}
