#include <iostream>
#include <time.h>

using namespace std;

int** Generator(int n) 
{
	
	int** X = new int*[n];
	for (int i = 0; i < n ; ++i)
		X[i] = new int[n];
	for (int i = 0; i < n ; ++i)
	{
		for (int j = 0; j < n; ++j) {
			X[i][j] = 0;
		}
	}
	int k, m;
	k= rand() % n;
	m = (k+1) * (n-k-1);
	for (int i = 0; i < n ; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((i <= k && j > k) || (i > k && j <= k))
				X[i][j] = 1;
			//cout << X[i][j] << " ";
		}
		//cout << endl;
	}
	cout<<"m= "<<m<<endl;
	cout <<"k= "<< k << endl;
	return X;
}
 
bool dfs(int v,bool * used,int * matching, int ** g, int n) {
	
	if (used[v]) {
		return false;
	}
	used[v] = true;	
	int to;
	for (int i=0;i<n;++i){
		{
			if (g[v][i] == 1) {
				to = i;
				if (matching[to] == -1 || dfs(matching[to],used,matching,g,n)) {
					matching[to] = v;
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int n= 500;
	double sec = 0.0;
	for (int i = 0; i < 10; ++i) {

		for (int i = 0; i < 10; ++i) {
			int* matching = new int[n];
			bool* used = new bool[n];
			int** g = new int*[n];
			for (int i = 0; i < n; ++i) {
				g[i] = new int[n];
			}
			g = Generator(n);
			clock_t start = clock();
			for (int i = 0; i < n; ++i) {
				matching[i] = -1;
				used[i] = false;
			}

			for (int i = 0; i < n; ++i) {
				dfs(i, used, matching, g, n);
			}
			clock_t end = clock();

			/*cout << endl << "Maximum matching: " << endl;
			for (int i = 0; i < n; ++i) {
				if (matching[i] != -1) {
					cout << i << " " << matching[i] << endl;
				}
			}*/
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			sec += seconds;
		}

		cout << "The time: " << sec / 10 << " seconds" << endl;
		sec = 0.0;
		n += 50;

	}

	cout << endl<<endl;
	n = 1000;
	for (int i = 0; i < 5; ++i) {
	
		for (int i = 0; i < 10; ++i) {
			int* matching = new int[n];
			bool* used = new bool[n];
			int** g = new int*[n];
			for (int i = 0; i < n; ++i) {
				g[i] = new int[n];
			}
			g = Generator(n);
			clock_t start = clock();
			for (int i = 0; i < n; ++i) {
				matching[i] = -1;
				used[i] = false;
			}

			for (int i = 0; i < n; ++i) {
				dfs(i, used, matching, g, n);
			}
			clock_t end = clock();

			/*cout << endl << "Maximum matching: " << endl;
			for (int i = 0; i < n; ++i) {
				if (matching[i] != -1) {
					cout << i << " " << matching[i] << endl;
				}
			}*/
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			sec += seconds;
		}  
		
		cout << "The time: " << sec/10 << " seconds" << endl;
		sec = 0.0;
		n += 100;

	}
	

	system("pause");
	return 0;
}