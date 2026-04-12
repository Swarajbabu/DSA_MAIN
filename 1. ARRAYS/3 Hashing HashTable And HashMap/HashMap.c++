// C++ program to demonstrate the use of map (which is a type of hash map in C++)
// This program creates a map that associates integers with strings and then prints 
// the values associated with specific keys.

// Basic operations on a map include inserting key-value pairs, accessing values using keys,
#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int,string> mp;
    mp[1] = "swaraj";
    mp[2] = "Jayanth";
    mp[3] = "Sunny";
    mp.insert({4,"Rahul"});           // another way to insert key-value pair into the map
    
    
    cout<< mp[1] << "\n";
    cout<< mp[2] << "\n";
    cout<< mp[3] << "\n";
    cout<< mp[4] << "\n";
}
// Output:
//      swaraj
//      Jayanth
//      Sunny


// printing all the key-value pairs in the map
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int,string> mp;
    mp[1] = "swaraj";
    mp[2] = "Jayanth";
    mp[3] = "Sunny";
    mp.insert({4,"Rahul"});
    
    for(auto it : mp){
        cout<<it.first << "->";
        cout<<it.second << " , ";
    }
}
// Output:
//      1->swaraj , 2->Jayanth , 3->Sunny , 4->Rahul 


// Some more operations on the map
#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,string> mp;
    
    mp[1] = "Swaraj";
    mp.insert({2,"Babu"});
    mp[3] = "Vecha";
    mp[4] = "Vecha";
    
    // Printing All Values in the map
    for(auto it : mp){
        cout << it.first << "->" << it.second << "\n";
    }
    
    // Printing the Size of the map
    cout<<"Size of the Map: "<<mp.size()<<"\n\n";
    
    //Checking the Map Is Empty or Not
    cout<<"Empty or not of the Map: "<<mp.empty()<<"\n\n";
    
    //Max Size if an Map
    cout <<"Max Size of the Map: "<<mp.max_size()<<"\n\n";
    
    // Finding the Value
    auto it = mp.find(8);
    if(it != mp.end()){
        cout << "Element Is Found\n\n";
    }else{
        cout<< "Element Is Not Found\n\n";
    }
    
    cout << "Count of key 3: " << mp.count(3) << "\n\n";

    //After Deleting The Value 
    mp.erase(3);
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

}
// Output:
//      #include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,string> mp;
    
    mp[1] = "Swaraj";
    mp.insert({2,"Babu"});
    mp[3] = "Vecha";
    mp[4] = "Vecha";
    
    // Printing All Values in the map
    for(auto it : mp){
        cout << it.first << "->" << it.second << "\n";
    }
    
    // Printing the Size of the map
    cout<<"Size of the Map: "<<mp.size()<<"\n\n";
    
    //Checking the Map Is Empty or Not
    cout<<"Empty or not of the Map: "<<mp.empty()<<"\n\n";
    
    //Max Size if an Map
    cout <<"Max Size of the Map: "<<mp.max_size()<<"\n\n";
    
    // Finding the Value
    auto it = mp.find(8);
    if(it != mp.end()){
        cout << "Element Is Found\n\n";
    }else{
        cout<< "Element Is Not Found\n\n";
    }
    
    cout << "Count of key 3: " << mp.count(3) << "\n\n";

    //After Deleting The Value 
    mp.erase(3);
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}
// Output:
//      1->Swaraj
//      2->Babu
//      3->Vecha
//      4->Vecha
//      Size of the Map: 4

//      Empty or not of the Map: 0

//      Max Size of the Map: 128102389400760775

//      Element Is Not Found

//      Count of key 3: 1

//      1 Swaraj
//      2 Babu
//      4 Vecha

// sum of Repeated Values in an Array using Map   tc: o(n) and sc: o(n)
#include <iostream>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    for(auto it : mp){
        cout << it.first << "->" <<it.second << "\n";
    }
    
    int sum = 0;
    for(auto it : mp){
        if(it.second > 1){
            sum = sum + it.first;
        }
    }
    cout<<"Sum Of the Repereted values is: "<<sum;
}
// Input: n = 6, arr[] = {1,1,2,3,2,4}
// Output:
//      1->2
//      2->2
//      3->1
//      4->1
//      Sum Of the Repereted values is: 3
// Explanation: The only repeated value in the array is 1 and 2, and their sum is 3.


// Unordered maps are implemented using hash tables, which provide average-case O(1) time complexity for insertion and access operations. 
// However, in the worst case (when there are many hash collisions), the time complexity can degrade to O(n). The space complexity is O(n) 
// because it may need to store all the key-value pairs in the map.

// The key are stored in an unordered manner.

// Unordered Map in C++ (which is a hash map) tc: o(1) for insertion and access and sc: o(n)
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int,string> mp;
    
    mp[5] = "Swaraj";
    mp.insert({3,"Babu"});
    mp[1] = "Vecha";
    mp[4] = "Vecha";
    
    for(auto it : mp){
        cout << it.first << "->" << it.second << "\n";
    }
}
// Output:
//      5->Swaraj
//      3->Babu
//      1->Vecha
//      4->Vecha

// Multimap in C++ (which is a hash map that allows duplicate keys) tc: o(log n) for insertion and access and sc: o(n)
// Multimap is a type of associative container in C++ that allows multiple key-value pairs with the same key.
#include <iostream>
#include <map>
using namespace std;

int main(){
    multimap<int,string> mp;
    
    mp.insert({3,"Babu"});
    mp.insert({1,"Swaraj"});
    mp.insert({5,"Laxmi"});
    mp.insert({3,"Mohan"});
    
    for(auto it:mp){
        cout << it.first << "->" << it.second << "\n";
    }
    
    cout<<"Number Of keys Present: "<<mp.count(3);
}
// Output:
//      1->Swaraj
//      3->Babu
//      3->Mohan
//      5->Laxmi
//      Number Of keys Present: 2