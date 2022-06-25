#include <iostream>
using namespace std;

int main()
{
    //declaration of the sender and receiver message
    int* sarr = NULL; //sender array
    int* rarr = NULL; //receiver array
    int* result = NULL; // result array
    int size,flag=0;
    
    
    //total chunks of message
    cout<<"Enter Size of the array?\n";
    cin>>size;
    
    //initalization of sender and receiver message
    sarr = new int [size];
    rarr = new int [size];
    result = new int [size];
    
    //take input values of message of sender and receiver
    cout<<"Enter values of sender message in byte?\n";
    for(int i=0;i<size;i++)
    {
        cin>>sarr[i];
    }
    cout<<"Enter values of receiver message in byte?\n";
    for(int i=0;i<size;i++)
    {
        cin>>rarr[i];
    }
    
    //printing sender values
    cout<<"\nYour sender message:";
    for(int i=0;i<size;i++)
    {
        cout<<sarr[i]<<" ";
    }
    
    //printing receiver values
    cout<<"\nYour receiver message:";
    for(int i=0;i<size;i++)
    {
        cout<<rarr[i]<<" ";
    }
    
    //Main logic starts here
    
    
    //complement sender message to get checksum
    
    for(int i =0;i<size;i++)
    {
        if(sarr[i] == 0)
        {
            sarr[i] = 1;
        }
        else if(sarr[i] == 1)
        {
            sarr[i] = 0;
        }
        else
        {
            cout<<"You had entered other than 0 and 1 so re-run the program.";
        }
    }
    
    //printing checksum
    cout<<"\nYour checksum:";
    for(int i=0;i<size;i++)
    {
        cout<<sarr[i]<<" ";
    }
    
    //Addition of checksum and receiver message
    int carry = 0;

    for(int i = 0; i < size; i++)
    {
    if(sarr[i] + rarr[i] + carry == 0)
    {
        result[i] = 0;
        carry = 0;
    }
    else if(sarr[i]+rarr[i]+carry==1)
    {
        result[i]=1;
        carry=0;
    }
    else if(sarr[i] + rarr[i] + carry == 2)
    {
        result[i] = 0;
        carry = 1;
    }
    else if(sarr[i] + rarr[i] + carry > 2)
    {
        result[i] = 1;
        carry = 1;
    }
    }
    
    
    //check for messages
    for(int i=0;i<size;i++)
    {
        if(result[i] == 1)
        {
            flag=0;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"\nData loss";
    }
    else{
         cout<<"\nData successfully received";
    }

    return 0;
}   