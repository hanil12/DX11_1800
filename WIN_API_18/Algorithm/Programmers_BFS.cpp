#include<vector>
#include<queue>
using namespace std;

struct Vector2
{
    Vector2() {}
    Vector2(int x, int y) : x(x), y(y) {}

    Vector2 operator+(const Vector2& other)
    {
        return Vector2(x + other.x, y + other.y);
    }

    bool operator==(const Vector2& other)
    {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Vector2& other)
    {
        return !(*this == other);
    }

    int x = 0;
    int y = 0;
};

vector<vector<bool>> discovered;
vector<vector<int>> distances; // 시작점으로 부터의 거리... (발견이 안되었다면 -1)
vector<vector<int>> myMaps;

Vector2 dir[4] =
{
    Vector2(1,0),
    Vector2(0,1),
    Vector2(-1,0),
    Vector2(0,-1)
};

bool CanGo(Vector2 here, const vector<vector<int>>& maps)
{
    if (here.x < 0 || here.y < 0)
        return false;
    if (here.x >= maps[0].size() || here.y >= maps.size())
        return false;
    if (maps[here.y][here.x] == 0)
        return false;

    return true;
}

void BFS(Vector2 start, Vector2 end, const vector<vector<int>>& maps)
{
    discovered[start.y][start.x] = true;
    distances[start.y][start.x] = 1;
    queue<Vector2> q; // 중요
    q.push(start);

    while (true)
    {
        if (q.empty() == true)
            break;
        Vector2 here = q.front();

        if (here == end)
            break;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            // 다음 지점
            Vector2 there = here + dir[i];

            // 갈 수 있는지 검사
            if (!CanGo(there, maps))
                continue;
            // 발견이 되었는지
            if (discovered[there.y][there.x] == true)
                continue;

            // 갈수도 있고, 발견이 안되어있으면 q에 삽입
            q.push(there);
            discovered[there.y][there.x] = true;
            distances[there.y][there.x] = distances[here.y][here.x] + 1;
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int mapSizeX = maps[0].size();
    int mapSizeY = maps.size();
    myMaps = maps;
    discovered = vector<vector<bool>>(mapSizeY, vector<bool>(mapSizeX, false));
    distances = vector<vector<int>>(mapSizeY, vector<int>(mapSizeX, -1));

    BFS(Vector2(0, 0), Vector2(mapSizeY, mapSizeX), maps);

    return distances[mapSizeY - 1][mapSizeX - 1];
}