
#include <bits/stdc++.h>
using namespace std;

int checkWinner(char a[3][3], char symbol){
    for(int i=0; i<3; i++){
        //check if any row is equal
        if(a[i][0] == symbol && a[i][1] == symbol && a[i][2] == symbol){
            return 1;
        }
        //check if any column is equal
        if(a[0][i] == symbol && a[1][i] == symbol && a[2][i] == symbol) {
            return 1;
        }
    }
    //diagonal
    if(a[0][0] == symbol && a[1][1] == symbol && a[2][2] == symbol){
        return 1;
    }
    if(a[0][2] == symbol && a[1][1] == symbol && a[2][0] == symbol){
        return 1;
    }
    return 0;
}

void printArray(char a[3][3]){
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int win = 0, turn=1;
    char  a[3][3];
    memset(a, '-', sizeof(a));
    cout<<"\e[1mStart Playing 2 player Tic-Tac-Toe!!!!\e[0m\n\n";
    cout<<"First player will have a 'x' symbol and the second player will have 'o' symbol\n";
    cout<<"Please specify row and column number (1-3)\n\n";
    
    printArray(a);

    
    while(win!=1 && turn<=9){
        int r, c;
        cout<<"Player "<<(turn%2==1? 1: 2)<<"'s turn\nEnter row and column number\n";
        cin>>r>>c;
        if(r>=1 && r<=3 && c>=1 && c<=3){
            if(a[r-1][c-1] == 'x' || a[r-1][c-1] == 'o'){
                cout<<"This is already filled\n";
                continue;
            }
            if(turn%2 == 1){
                a[r-1][c-1]= 'x';
            } else {
                a[r-1][c-1] = 'o';
            }
            printArray(a);
            win = checkWinner(a, a[r-1][c-1]);
            if(win == 1){
                cout<<"Hurray!!!! Player "<<(turn%2==1? 1: 2)<<" won\n";
            }
            if(win!=1 && turn >= 9){
                cout<<"The game is draw!!!\n";
            }
            turn++;
        } else {
            cout<<"Enter a valid row and column number\n";
        }
        
    }
    
    return 0;
}


