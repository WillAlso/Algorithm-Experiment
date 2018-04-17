#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
struct Point{
    int x;
    int y;
};
int main()
{
    int i,j,n;
    ifstream fin("input.txt");
    Point *p = new Point[n];
    fin >> n;
    string line;
    for(i = 0;i < n;i++)
    {
   //     getline(fin,line);
   //     cout << line << endl;
    }
    return 0;
}
