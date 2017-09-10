/*
注意三个重要剪枝 
*/ 
#include <cstdlib>
#include <iostream>
#include<algorithm>

using namespace std;

int l[65];          //所有木棍 
int visited[65];    //记录所有木棍是否被访问 
int len;            //木棍 
int n;              //木棍个数 
int sum;            //木棍长和 

bool cmp(int a,int b)
{
  return a>b;
}


bool research(int pos, int res, int cnt)
{   //如果构成了所有，返回 
    if (cnt*len == sum)
        return true;
    for(int i=pos; i<n; i++)
    {
        //如被访问，退出 
        /*if(visited[i] == 1)
            continue;*/
        //1某根木棒的长度不能构成，则之后的相同长度的也不行. 
       if(visited[i] || (i && !visited[i-1] && l[i] == l[i-1])) continue;

        if(res+l[i] == len)
        {
                visited[i] = 1;    
                if(research(0, 0, cnt+1))
                    return true;
                
                visited[i] = 0;
                //2如果把某段拿去构成木棒的最后一截后，剩下的无法完成，那么也不可能.
                return false;
        }
        else if(res+l[i] < len)
        {
            visited[i] = 1;
            if(research(pos+1, res+l[i], cnt))
                return true;
            visited[i] = 0;
            //3如果在构成某根木棒的第一段时最大的无法用上，那么直接不可能.
            if(res == 0) return false;
        }
            
    }        
 
    return false;
}

int solve()
{
            //整数排序
              sort(l,l+n,cmp);
       
              for(len=l[0]; len<sum; len++)
              {     
                    
                    if(sum%len == 0)
                    {
                        memset(visited, 0, sizeof(visited));
                        if(research(0, 0, 0))
                        {
                          break;
                        }  
                                  
                    }
              }
            
            return len;
}
int main(void)
{
    while(cin >> n && n!= 0)
    {   
             sum = 0;
              //memset(l,0,sizeof(l));
              for(int i=0; i<n; i++)
              {        
                       cin >> l[i];
                       sum+=l[i];
              }
              
              cout << solve() << endl;
       
    }
    system("PAUSE");
    return 0;
}

