#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
	int x, y;

	Point(int x, int y) : x(x), y(y) {}

	Point operator + (Point a) const 
	{
		Point result = Point(x + a.x, y + a.y);
		return result;
	}

	Point operator - (Point a) const 
	{
		Point result = Point(x - a.x, y - a.y);
		return result;
	}

	int operator * (Point a) const 
	{
		int cross = x*a.y - y*a.x;
		return cross;
	}

	int operator % (Point a) const 
	{
		int dot = x*a.x + y*a.y;
		return dot;
	}

	bool operator < (Point a) const // Define a comparação entre os eventos
	{
		if (x != a.x) 
			return x < a.x;

		return y < a.y;
	}
};

bool clockwise(Point a, Point b, Point c) { return (b - a)*(c - a) < 0; }
bool counterclockwise(Point a, Point b, Point c) { return (b - a)*(c - a) > 0; }

void print(vector<Point> sla){
    for(auto [x, y]:sla) cout << "(" << x << " ," << y << ") ";
    cout << "\n";
}

// Dado um conjunto de pontos, ela retorna o fecho convexo desse set no sentido horário
vector<Point> findConvexHull(vector<Point> S)
{
	sort(S.begin(), S.end()); // Ordena os nossos eventos

	vector<Point> upperHull; // Pilha que armazena o fecho superior

	for (int i = 0; i < (int)S.size(); i++)
	{
		while ((int)upperHull.size() >= 2)
		{
			int p = (int)upperHull.size() - 1; // Índice do último ponto do fecho superior

			if (clockwise(upperHull[p - 1], upperHull[p], S[i])) // Checa se S[i] está a direita da linha dada
				break;
            cout << (clockwise(upperHull[p - 1], upperHull[p], S[i])^1) << " -> "; 
            upperHull.push_back(S[i]); 
            print(upperHull);
			upperHull.pop_back();
			upperHull.pop_back();
		}

		upperHull.push_back(S[i]);
	}

	vector<Point> lowerHull; // Pilha que armazena o fecho inferior

	for (int i = 0; i < (int)S.size(); i++)
	{
		while ((int)lowerHull.size() >= 2)
		{
			int p = (int)lowerHull.size() - 1; // Índice do último ponto do fecho inferior

			if (counterclockwise(lowerHull[p - 1], lowerHull[p], S[i])) // Checa se S[i] está a esquerda da linha dada
				break;

			lowerHull.pop_back();
		}

		lowerHull.push_back(S[i]);
	}

	// Juntando o fecho superior e o fecho inferior
	vector<Point> convexHull = upperHull;

	for (int i = (int)lowerHull.size() - 2; i > 0; i--)
		convexHull.push_back(lowerHull[i]);

	return convexHull;
}

int main()
{
	int n;
	cin >> n;

	vector<Point> S;

	// Lê os n pontos
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		S.push_back(Point(x, y));
	}

	vector<Point> convexHull = findConvexHull(S);

	cout << "Pontos do fecho convexo: ";

	for (int i = 0; i < (int)convexHull.size(); i++)
		cout << "(" << convexHull[i].x << "," << convexHull[i].y << ") ";
    cout << "\n";
        
    cout << counterclockwise(Point(-10, -3), Point(-10, -1), Point(-10, 8)) << "\n";
}
