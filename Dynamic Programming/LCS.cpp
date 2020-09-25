#include<bits/stdc++.h>
#define mx 100
using namespace std;
string s1,s2;
int lcs_matrix[mx][mx];
int s1_len,s2_len;
int lcs()
{
    s1_len =s1.size();
    s2_len =s2.size();
    for(int i=0; i<=s1_len; i++)
    {
        for(int j=0; j<=s2_len; j++)
        {
            if(i==0 || j==0)
            {
                lcs_matrix[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                lcs_matrix[i][j]=lcs_matrix[i-1][j-1]+1;
            }
            else
            {
                lcs_matrix[i][j]=max(lcs_matrix[i-1][j],lcs_matrix[i][j-1]);
            }
        }
    }
    int n = lcs_matrix[s1_len][s2_len];

    return n;
}
void printLcs(int n)
{
    char lcs[n+1];
    for(int i=s1_len,j=s2_len;j>0 && i>0 ;)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs[n-1]=s1[i-1];
            i--;
            j--;
            n--;

        }
        else if(lcs_matrix[i-1][j]>lcs_matrix[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<"The lcs is = "<<lcs<<endl;

}
int main()
{

    cin>>s1>>s2;
    int n = lcs();
    cout<<"The lenght of lcs is = "<<n<<endl;
    printLcs(n);

}
