#include<bits/stdc++.h>
using namespace std;

void minor(float b[100][100],float a[100][100],int i,int n)
{

    int j,l,h=0,k=0;
    for(l= 1; l < n; l++)
        for( j = 0; j < n; j++)
        {
            if(j == i)
                continue;
            b[h][k] = a[l][j];
            k++;
            if(k == (n-1))
            {
                h++;
                k=0;
            }
        }
}

float det(float a[100][100],int n)
{
    int i;
    float b[100][100],sum=0;
    if (n == 1)
        return a[0][0];
    else if(n == 2)
        return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    else
        for(i=0; i<n; i++)
        {
            minor(b,a,i,n);
            sum = (float) (sum+a[0][i]*pow(-1,i)*det(b,(n-1)));
        }
    return sum;
}

void transpose(float c[100][100],float d[100][100],int n,float det)
{
    int i,j;
    float b[100][100];
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            b[i][j] = c[j][i];
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            d[i][j] = b[i][j]/det;
}

void cofactor(float a[100][100],float d[100][100],int n,float determinte)
{
    float b[100][100],c[100][100];
    int l,h,m,k,i,j;
    for (h=0; h<n; h++)
        for (l=0; l<n; l++)
        {
            m=0;
            k=0;
            for (i=0; i<n; i++)
                for (j=0; j<n; j++)
                    if (i != h && j != l)
                    {
                        b[m][k]=a[i][j];
                        if (k<(n-2))
                            k++;
                        else
                        {
                            k=0;
                            m++;
                        }
                    }
            c[h][l] = (float) pow(-1,(h+l))*det(b,(n-1));
        }
    transpose(c,d,n,determinte);
}

void inverse(float a[100][100],float d[100][100],int n,float det)
{
    if(det == 0)
    {
        cout << "\nInverse of Entered Matrix is not possible\n";

    }
    else
    {
        cout << "Inverse matrix is possible" << endl;
        if(n == 1)
            d[0][0] = 1;
        else
            cofactor(a,d,n,det);

        cout<<"\n\n The Inverse Of Matrix Is : " << endl << endl;
        for (int i=0; i < n; i++)
        {
            for (int j=0; j < n; j++)
                cout<<" "<< d[i][j]<<" \t";
            cout<<"\n";
        }
    }
}

int main(void)
{
    int i,j,n;
    float a[100][100],d[100][100],deter;
    cout << "enter the value of n : ";
    cin >> n;
    cout << "The order of the matrix : " << n << " * " << n << endl;
    cout << "Enter the elements of the matrix" << endl;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            cin >> a[i][j];
        }

    deter = (float) det(a,n);
    inverse(a,d,n,deter);
    return 0;
}
