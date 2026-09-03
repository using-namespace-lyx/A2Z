#include<bits/stdc++.h>
using namespace std;

int findElement(int row, int col)
{
    // It is same as (row-1)C (col-1)
    int n=row-1;
    int r=col-1;

    // we now need to find nCr;

    // int nCr=fact(n)/(fact(n-r)*fact(r)) O(n)
    int nCr=0;

    // 5C3 = 5/1 *4/2 *3/3
    //
    for(int i=0;i<r;i++)
    {
        nCr*=(n-i)/(i+1);

    }

    return nCr; // O(r);

}

vector<int> findNthRow(int row)
{
    int n=row-1;
    vector<int> res;

    // we need to find nC0 till nCn

    /*
    for(int i=0;i<=n;i++)
    res.push_back(findElement(row=n+1,col=i+1)); // nCi i runs from 0 to n

    O(n+1 *r)
    */
   
        int n=row-1;

        vector<int> res;
        int ans=1;
        res.push_back(ans);

        for(int i=0;i<n;i++)
        {
           
            ans= ans*(n-i)/(i+1);
            res.push_back(ans);
        }

       
        return res;

    
}

vector<vector<int>> generatePascal(int rows)
{
    // 1 based rows
    vector<vector<int>> res;

    for(int i=1;i<=rows;i++)
    {
        res.push_back(findNthRow(i));
    }
}

vector<vector<int>> generate(int numRows) {
        // Result vector to hold all rows
        vector<vector<int>> triangle;

        // Loop for each row
        for (int i = 0; i < numRows; i++) {
            // Create a row with size (i+1) and initialize all elements to 1
            vector<int> row(i + 1, 1);

            // Fill elements from index 1 to i-1 (middle values)
            for (int j = 1; j < i; j++) {
                // Each element = sum of two elements above it
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // Add current row to the triangle
            triangle.push_back(row);
        }
        return triangle;
    }