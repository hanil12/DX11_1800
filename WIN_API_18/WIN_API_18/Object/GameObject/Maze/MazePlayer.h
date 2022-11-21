#pragma once
class Maze;

class MazePlayer
{
public:

	// 다익스트라
	struct Vertex_Dijkstra
	{
		Vertex_Dijkstra() {}
		Vertex_Dijkstra(Vector2 pos, float g) : pos(pos), g(g) {}

		Vector2 pos = Vector2(0,0);
		float g = 0.0f;

		bool operator<(const Vertex_Dijkstra& other) const
		{
			if (g < other.g)
				return true;

			return false;
		}

		bool operator>(const Vertex_Dijkstra& other) const
		{
			if (g > other.g)
				return true;

			return false;
		}
	};

	// 에이스타
	struct Vertex
	{
		Vertex() {}
		Vertex(Vector2 pos, float g, float h) : pos(pos), g(g), h(h) { f = g + h; }

		Vector2 pos = Vector2(0,0);
		float g = 0;
		float h = 0; // 휴리스틱 -> 
		float f = 0;

		bool operator<(const Vertex& other) const
		{
			if (f < other.f)
				return true;

			return false;
		}

		bool operator>(const Vertex& other) const
		{
			if (f > other.f)
				return true;

			return false;
		}
	};

	MazePlayer(shared_ptr<Maze> maze);
	~MazePlayer();

	void Init();

	void RightHand();
	void BFS();
	void Dijkstra();
	void AStar();

	void Update();
	void SetPos(Vector2 pos) { _pos = pos; }

	const Vector2& GetPos() { return _pos; }
	bool Cango(const Vector2& pos);

private:
	Vector2 _pos = Vector2();
	vector<Vector2> _path;
	Dir _dir = Dir::UP;

	float _time = 0.0f;
	int _pathIndex = 0;

	shared_ptr<Maze> _maze;
};

