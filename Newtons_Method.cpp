/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double equation (vector < double >, vector < int >, double);
double derivative (vector < double >, vector < int >, double);
double method (vector < double >, vector < int >, double);

int
main ()
{
  int terms;
  cout << setprecision (10);
  cout << "Enter the amount of terms in your polynomial" << endl;
  cin >> terms;
  vector < double >co (terms);
  vector < int >ex (terms);
  cout << "Now enter your terms in the order coefficient, exponent, etc." <<
    endl;
  for (int i = 0; i < terms; i++)
    {
      cin >> co[i] >> ex[i];
    }
  double starting;
  cout << "Enter your input-value: " << endl;
  cin >> starting;
  int iterations;
  cout << "Enter amount of iterations for Holland's method: " << endl;
  cin >> iterations;
  double newOne;
  newOne = method (co, ex, starting);
  for (int i = 0; i < iterations; i++)
    {
      newOne = method (co, ex, newOne);
      cout << newOne << " | ";
    }

  return 0;
}

double
equation (vector < double >co, vector < int >ex, double x)
{
  double y;
  if (co.size () == ex.size ())
    {
      for (int i = 0; i < co.size (); i++)
	{
	  y += co[i] * pow (x, ex[i]);
	}
    }
  return y;
}

double
derivative (vector < double >co, vector < int >ex, double x)
{
  double y;
  if (co.size () == ex.size ())
    {
      for (int i = 0; i < co.size (); i++)
	{
	  if (ex[i] != 0)
	    {
	      y += (co[i] * ex[i]) * pow (x, (ex[i] - 1));
	    }
	}
    }
  return y;
}

double
method (vector < double >co, vector < int >ex, double starting)
{
  return starting -
    (equation (co, ex, starting) / derivative (co, ex, starting));
}
