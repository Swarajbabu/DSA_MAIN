// pattern 1
#include <iostream>
using namespace std;
int main()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<"*"<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// Output: 
//         * * * *
//         * * * *
//         * * * *
//         * * * *

// pattern 2

#include <iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*"<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// Output (for n=4):
//         *
//         * *
//         * * *
//         * * * *

// pattern 3

#include <iostream>
using namespace std;
int main()
{   
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// Output (for n=4):
//         1
//         1 2
//         1 2 3
//         1 2 3 4

// pattern 4

#include <iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j =1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// Output (for n=4):
//         1
//         2 2
//         3 3 3
//         4 4 4 4

// pattern 5

#include <iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
    return 0;
}
// Output (for n=4):
//         * * * *
//         * * *
//         * *
//         *

// pattern 6

#include <iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// Output (for n=4):
//         1 2 3 4
//         1 2 3
//         1 2
//         1

// pattern 7
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// Output (for n=5):
//             *
//            ***
//           *****
//          *******
//         *********

// pattern 8
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// Output (for n=5):
//         *********
//          *******
//           *****
//            ***
//             *