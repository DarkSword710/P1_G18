class Map
{
public:
	Map(int difficulty, char c);
	void UpdateCell(int x, int y, char c);
	void PrintMap();
	int getHeight();
	int getWidth();
	~Map();

private:
	char** map_array;
	int width;
	int height;
};