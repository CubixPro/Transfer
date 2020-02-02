
#include <bits/stdc++.h>
#define x first
#define y second
 
using namespace std;
 
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 

    int n, m, p;
   // scanf("%d %d %d", &n, &m, &p);
   cin >> n >> m >> p;
    int speed[p];
    int count[p];
    for (int i = 0; i < p; i++)
    {
       cin >> speed[i];
        speed[i] = min(speed[i], max(n, m));
        count[i] = 0;
    }
    queue<pair<int, int>> cells[p];
    char maze[n][m];
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = str[j];
            if (maze[i][j] != '#' && maze[i][j] != '.')
            {
                cells[maze[i][j] - 48 - 1].push(make_pair(i, j));
                count[maze[i][j] - 48 - 1]++;
                maze[i][j] = '-';
            }
        }
    }
    //int can_continue = pow(2, p) - 1;
    bool can_continue = true;
    while (can_continue)
    {
      can_continue = false;
        for (int i = 0; i < p; i++)
        {
            if (!cells[i].empty())
            {
              can_continue = true;
            }
 
            for (int ii = 1; ii <= speed[i] && cells[i].size() != 0; ii++)
            {
                int s = cells[i].size();
                while (s-- != 0)
                {
                    pair<int, int> coordinate = cells[i].front();
                    cells[i].pop();
 
                    //count[p]++;
                    //maze[coordinate.first][coordinate.second] = '-';
                    //cout << "Popped : " << coordinate.x << " " << coordinate.y << '\n';
                    if (((coordinate.x + 1) < n) && maze[coordinate.x + 1][coordinate.y] != '#' && maze[coordinate.x + 1][coordinate.y] != '-')
                    {
                        cells[i].push(make_pair(coordinate.x + 1, coordinate.y));
                        //cout << "Pushed : " << coordinate.x + 1 << " " << coordinate.y << '\n';
                        count[i]++;
                        maze[coordinate.first + 1][coordinate.second] = '-';
                    }
 
                    if (((coordinate.x - 1) >= 0) && maze[coordinate.x - 1][coordinate.y] != '#' && maze[coordinate.x - 1][coordinate.y] != '-' && ((coordinate.x - 1) >= 0))
                    {
                        cells[i].push(make_pair(coordinate.x - 1, coordinate.y));
                        //cout << "Pushed : " << coordinate.x - 1 << " " << coordinate.y << '\n';
                        count[i]++;
                        maze[coordinate.first - 1][coordinate.second] = '-';
                    }
 
                    if (((coordinate.y + 1) < m) && maze[coordinate.x][coordinate.y + 1] != '#' && maze[coordinate.x][coordinate.y + 1] != '-')
                    {
                        cells[i].push(make_pair(coordinate.x, coordinate.y + 1));
                        //cout << "Pushed : " << coordinate.x << " " << coordinate.y + 1 << '\n';
                        count[i]++;
                        maze[coordinate.first][coordinate.second + 1] = '-';
                    }
 
                    if (((coordinate.y - 1) >= 0) && maze[coordinate.x][coordinate.y - 1] != '#' && maze[coordinate.x][coordinate.y - 1] != '-')
                    {
                        cells[i].push(make_pair(coordinate.x, coordinate.y - 1));
                        //cout << "Pushed : " << coordinate.x << " " << coordinate.y - 1 << '\n';
                        count[i]++;
                        maze[coordinate.first][coordinate.second - 1] = '-';
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < p; i++)
    {
        cout << count[i] << ' ';
    }
}