#include <iostream>
#include <fstream>
using namespace std;
double mid(double a[],double b[],int a1,int a2,int b1,int b2)
{
    int pos1 = (a2 + a1) / 2;
    int pos2 = (b2 + b1) / 2;
    int len = a2 - a1 + 1;
    double num1,num2;
    num1 = a[pos1];
    num2 = b[pos2];
    if(len == 1)
    {
        return a[a1] < b[b1] ? a[a1] : b[b1];
    }
    if(len == 2)
    {
        double t = a[a1] > b[b1] ? a[a1] : b[b1];
        if(t == a[a1])
        {
            return t < b[b2] ? t : b[b2];
        }else
        {
            return t < a[a2] ? t : a[a2];
        }
    }
    if(num1 == num2)
    {
        return num1;
    }else if(num1 < num2)
    {
        return mid(a,b,pos1,a2,b1,pos2);
    }else
    {
        return mid(a,b,a1,pos1,pos2,b2);
    }
}
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int i,n;
    fin >> n;
    double *a = new double[n];
    double *b = new double[n];
    for(i = 0;i < n;i++)
    {
        fin >> a[i];
    }
    for(i = 0;i < n;i++)
    {
        fin >> b[i];
    }

    fout << mid(a,b,0,n - 1,0,n - 1) << endl;
    return 0;
}
