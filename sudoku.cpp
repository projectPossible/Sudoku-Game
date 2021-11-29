#include <iostream>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#define UNASSIGNED 0
#define N 9
class sudoku{
    int grid[N][N],a[N][N],c[N][N];
    public:
    void l_Lvl(){
        int b[N][N]=  {{0,0,0,6,7,0,0,1,3},
        {0,1,0,0,4,0,8,0,2},
        {0,0,0,0,3,0,0,9,0},
        {3,0,8,0,1,5,0,0,6},
        {4,0,0,7,6,0,0,5,8},
        {0,0,1,9,0,0,0,0,7},
        {0,0,0,0,9,0,2,0,0},
        {8,3,2,1,5,7,0,0,9},
        {0,9,0,2,0,4,7,3,5}};
                      for (int i = 0; i < N; i++)
                      {
                         for (int j = 0; j < N; j++)
                         {
                            a[i][j]=b[i][j];
                            grid[i][j]=b[i][j];
                            c[i][j]=b[i][j];
                         }
                         
                      }
                      
                    
                      
    }
    void m_Lvl(){
        int b[N][N] =  {{7,0,8,9,0,6,5,0,0},
        {4,0,3,8,0,0,0,0,7},
        {0,0,0,4,0,3,0,0,8},
        {0,0,4,0,0,0,0,0,9},
        {0,0,0,3,0,0,0,8,0},
        {8,0,0,0,9,0,0,5,2},
        {0,2,0,6,8,0,0,0,4},
        {0,0,5,0,0,4,0,6,1},
        {0,0,7,0,0,0,0,0,5}};
                      for (int i = 0; i < N; i++)
                      {
                         for (int j = 0; j < N; j++)
                         {
                            a[i][j]=b[i][j];
                            grid[i][j]=b[i][j];
                            c[i][j]=b[i][j];
                         }
                         
                      }
                     
    }
    void h_Lvl(){
        int b[N][N] =  {{0,0,7,9,1,0,5,0,0},
        {0,0,1,0,0,0,0,0,3},
        {0,0,9,0,4,0,0,0,2},
        {0,4,0,0,0,8,3,0,0},
        {0,0,0,3,0,1,0,0,0},
        {0,6,0,0,5,0,0,0,8},
        {0,2,0,0,9,0,0,0,5},
        {0,0,0,0,0,0,0,0,0},
        {0,0,4,0,8,0,0,7,0}};
                      for (int i = 0; i < N; i++)
                      {
                         for (int j = 0; j < N; j++)
                         {
                            a[i][j]=b[i][j];
                            grid[i][j]=b[i][j];
                            c[i][j]=b[i][j];
                         }
                         
                      }
                      
    }
    bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
    bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}
    bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
    bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
    bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
    bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 , col - col % 3, num);
}
    void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++){
            if(c[row][col]!=0){
            SetConsoleTextAttribute(hConsole,4);
            cout<<grid[row][col]<<" ";}
            else{            
            cout<<grid[row][col]<<" ";}
            SetConsoleTextAttribute(hConsole,7);
        if((col+1)%3==0)
        cout<<"| ";
        }
        cout<<endl;
        if((row+1)%3==0)
        cout<<"-----------------------"<<endl;
    }
    
    cout<<endl;
}
    void creategrid(){
        cout<<"Enter the sudoku Row-by-Row "<<endl;
        for (int i = 0; i < N; i++)
        {cout<<"Row"<<i+1<<": ";
            for (int j = 0; j < N; j++)
            {
                cin>>grid[i][j];
                a[i][j]=grid[i][j];
                c[i][j]=grid[i][j];
            }
            
        }}
    bool fullsudoku(){
    for (int i = 0; i < N; i++)
    {
    for (int j = 0; j < N; j++)
    {
        if(a[i][j]==0)
        return true; 
         
        
    }
    
    }
   return false;
}
    bool playsudoku(){
    char ch='0';
    int i,j,num;
     if (SolveSudoku(grid)){
        cout<<"Sudoku has valid solution"<<endl;
        do{
        printGrid(a);
        cout<<"Do You Want SOLUTION(Y/N): ";
        cin>>ch;
        if(ch=='Y'||ch=='y'){
        printGrid(grid);
        break;
        }
        cout<<"Enter the slot you want to change:(row,col) ";
        cin>>i>>j;
        if(c[i][j]==0){
        cout<<"Enter the number: ";
        cin>>num;        
        a[i][j]=num;
        }
        else
        cout<<"This position is already full. "<<endl;
        }while(ch!='Y'||ch!='y');
     }
    else
        cout<<"No solution exists"<<endl;
        cout<<"DO You Want A REMATCH(Y/N)";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        return true;
        else 
        return false;
}

};

int main()
{   int ch;
    sudoku s;
do
{
    cout<<"-----------1 FOr LEVel 1"<<endl;
    cout<<"-----------2 FOr LEVel 2"<<endl;
    cout<<"-----------3 FOr LEVel 3"<<endl;
    cout<<"-----------4 FOr CREATing YUor OWn SUDOKU"<<endl;
    cout<<"Enter The Difficulty LVL : ";
    cin>>ch;
    switch(ch){
    case 1: s.l_Lvl();
            break;
    case 2: s.m_Lvl();
            break;
    case 3: s.h_Lvl();
            break;
    case 4: s.creategrid();
            break;
    
    default: 
        break;
    }
    } while (s.playsudoku());
   
    return 0;
    }