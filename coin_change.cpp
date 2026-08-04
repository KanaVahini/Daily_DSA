#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of coins: ";
    cin>>n;

    vector<int>coins(n);
    cout<<"Enter coin values: ";
    for(int i=0;i<n;i++)
        cin>>coins[i];

    int sum;
    cout<<"Enter target sum: ";
    cin>>sum;

    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));

    for(int i=0;i<=n;i++)
        dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1] > j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
            }
        }
    }
     cout << "\nDP Table:\n\n";

    cout << "      ";
    for(int j = 0; j <= sum; j++)
        cout << setw(4) << j;

    cout << "\n";

    for(int i = 1; i <= n; i++)
    {
        if(i == 0)
            cout << "0    ";
        else
            cout << coins[i - 1] << "    ";

        for(int j = 0; j <= sum; j++)
            cout << setw(4) << dp[i][j];

        cout << endl;
    }

    cout << "\nNumber of Ways = " << dp[n][sum];

    return 0;

}