/* ************************************************
 * summer 
 * 2023/3/1
 * 
 * ************************************************/
#include<iostream> // cout endl
#include<vector> // vector

using std::vector;
using std::cout;
using std::endl;
typedef vector<vector<int>> twoDimVec ;

int hungarian(twoDimVec Map);

int main()
{
  twoDimVec Map{
    {0, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 0, 1, 0},
    {0, 0, 0, 1}
  };
  cout<<hungarian(Map)<<endl;
  return 0;
}

bool match(int i, vector<int>& vis, vector<int>& p, const twoDimVec& Map)
{ 
  int N = vis.size();

  for(int j = 0; j < N; j++)
  {
    if(Map[i][j] && !vis[j])
    {
      vis[j] = true;
      if(p[j] == -1 || match(p[j], vis, p, Map))
      {
        p[j] = i;
        return true;
      }
    }
  }
  return false;
}

int hungarian(twoDimVec Map)
{
  int M = Map.size();
  int N = Map[0].size();
  int cnt = 0;
  vector<int> vis(N, 0);
  vector<int> p(M, -1);

  for(int i = 0; i < M; i++)
  {
    vis = vector<int>(N, 0);
    if(match(i, vis, p, Map))
      cnt++;
  }
  return cnt;
}
