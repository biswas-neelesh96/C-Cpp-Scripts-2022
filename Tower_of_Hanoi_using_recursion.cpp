#include <iostream>
 
using namespace std;
 
void tower(int n, char source, char destination, char auxillary){
if(n == 1){
    cout << "Moved the ring "<< n << " from " << source << " to " << destination << " via " << auxillary << ".\n";
 
}
else{
    tower(n-1,source, auxillary, destination);
    cout << "Moved the ring " << n << " from " << source << " to " << destination << " via " << auxillary<< ".\n";
    tower(n-1,auxillary,destination,source);
}
 
}
 
int main()
{
    int rings;
    char source='A';
    char destination = 'B';
    char auxillary = 'C';
    cout << "Enter the number of rings : "; 
    cin >> rings;
    tower(rings,source,destination,auxillary);
 
    return 0;
}
