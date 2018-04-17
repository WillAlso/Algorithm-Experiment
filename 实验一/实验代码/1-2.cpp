#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void grey(int **a,int n,int num)
{
    if(n == 1)
    {
        a[0][n - 1] = 0;
        a[1][n - 1] = 1;
        return;
    }
    for(int i = 0; i < num / 2; i++)
    {
        a[i][n - 1] = 0;
        a[num - i - 1][n - 1] = 1;
    }
    grey(a,n - 1,num / 2);
    for(int i = num / 2; i < num; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            a[i][j] = a[num - i - 1][j];
        }
    }
}
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n = 0;
    fin >> n;
    int num = pow(2,n);
    int **a = new int*[num];
    for(int i = 0; i < num; i++)
    {
        a[i] = new int[n];
    }
    grey(a,n,num);
    for(int i = 0;i < num;i++)
    {
        for(int j = n - 1;j >= 0;j--)
        {
            fout << a[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}
/*#include <iostream>

using namespace std;

void print_bit_model( int len, int n ){
    for( int i=len-1; i>=0; --i )
        cout<<((n>>i)&1);
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    const int M=1<<n;
    for( int i=0; i<M; ++i )
        print_bit_model( n, i^(i>>1) );
    return 0;
}*/
