#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

float time_function(int n, long long m)
{
  int **M = new int *[n];

  for (int i = 0; i < n; i++)
  {
    M[i] = new int[n];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      M[i][j] = 0;
    }
  }
  long long counter = 0;

  auto start = high_resolution_clock::now();
  while (counter < m)
  {
    int i = rand() % n;
    int j = rand() % n;
    int x = rand() % 100 + 1;

    M[i][j] = M[i][j] + x;
    counter++;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  float time = duration.count();

  for (int i = 0; i < n; i++)
  {
    delete[] M[i];
  }
  delete[] M;

  return time / 1000000;
}

int main()
{
  long m1 = 13421772800;
  long m2 = 1677721600;
  int n_values[6] = {16, 64, 256, 1024, 4096, 16384};
  for (int i = 0; i < 6; i++)
  {
    cout << "n =" << n_values[i] << " and m = 13421772800  took " << time_function(n_values[i], m1) << "secdonds" << endl;
    cout << endl;
  }
  for (int i = 0; i < 6; i++)
  {
    cout << "n =" << n_values[i] << " and m = 1677721600  took " << time_function(n_values[i], m2) << "secdonds" << endl;
    cout << endl;
  }
  return 0;
}