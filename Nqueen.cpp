
#include<stdio.h>
#include<math.h>
 
int sol[20],count;
 
int main()
{
 int n,i,j;
 void NQ(int row,int n);
 
 printf(" - N-Queens Problem Using Backtracking -");
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 NQ(1,n);
 return 0;
}
 
//function for printing the solution
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);
 
 for(i=1;i<=n;++i)
  printf("\t%d",i);
 
 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) //for nxn sol
  {
   if(sol[i]==j)
    printf("\tQ"); //queen at i,j position
   else
    printf("\t-"); //empty slot
  }
 }
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int safe(int row,int col)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  //checking col and digonal conflicts
  if(sol[i]==col)
   return 0;
  else
   if(abs(sol[i]-col)==abs(i-row))
    return 0;
 }
 
 return 1; //no conflicts
}
 
//function to check for proper positioning of queen
void NQ(int row,int n)
{
 int col;
 for(col=1;col<=n;++col)
 {
  if(safe(row,col))
  {
   sol[row]=col; //no conflicts so safe queen
   if(row==n) //dead end
    print(n); //printing the sol configuration
   else //try queen with next position
    NQ(row+1,n);
  }
 }
}
