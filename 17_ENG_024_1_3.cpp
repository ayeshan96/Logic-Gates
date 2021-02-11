//Header files
#include<iostream>

//Declare namespace
using namespace std;

//Declare function to get a outputs and inputs from AND gate
void and1(int **array, int count1, int k, int m, int n, int i, int j,int z)
{
	//consider the logic
	if (i < m && j < n)
	{
		//assigning values for array elements
		array[i][j] = (k) % 2;

		//equal value of elements to its half of value
		k = k / 2;

		//consider the logic
		if (array[i][j] == 0)
		{
			//equal value of elements to its increment value
			count1 = count1 + 1;
		}
		else
		{
			//equal value of elements it self
			count1 = count1;
		}

		//AND function calling it self
		and1(array, count1, k,m, n, i, j + 1,z);
	}

	//consider the logic
	else if (i < m && j == n)
	{
		//consider the logic
		if (count1 > 0)
		{
			//assign values for array elements
			array[i][j] = 0;
		}

		//consider logic gates
		else
		{
			//assign values for array elements
			array[i][j] = 1;
		}
		
		//assign values to variables
		j = 0;
		count1 = 0;
		k = z;

		//AND function calling it self
		and1(array, count1,k-1,m, n, i + 1, j,z-1);

	}
}

//Declare function to get a outputs and inputs from OR gate
void or1(int **array, int count1, int k, int m, int n, int i, int j, int z)
{
	//consider the logic
	if (i < m && j < n)
	{
		//assign value to the array element
		array[i][j] = (k) % 2;

		//equal value of elements to its half of value
		k = k / 2;

		//consider the logic
		if (array[i][j] == 1)
		{
			//equal value of elements to its increment value
			count1 = count1 + 1;
		}
		//consider the logic
		else
		{
			//equal value it self
			count1 = count1;
		}
		//OR function calling it self
		or1(array, count1, k, m, n, i, j + 1, z);
	}
	//consider the logic
	else if (i < m && j == n)
	{
		//consider the logic
		if (count1 > 0)
		{
			//assign value to the array element
			array[i][j] = 1;
		}

		//consider the logic
		else
		{
			//assign value to the array element
			array[i][j] = 0;
		}

		//assign value to variables
		j = 0;
		count1 = 0;
		k = z;

		//OR function calling itself
		or1(array, count1, k - 1, m, n, i + 1, j, z - 1);

	}
}


//Declare function to get a outputs and inputs from XOR gate
void xor1(int **array, int count1, int k, int m, int n, int i, int j, int z)
{
	//consider the logic
	if (i < m && j < n)
	{
		//assign value to the array elements
		array[i][j] = (k) % 2;

		//equal value of elements to its half of value
		k = k / 2;
		
		//consider the logic
		if (array[i][j] == 1)
		{
			//equal value of elements to its increment value
			count1 = count1 + 1;
		}

		//consider the logic
		else
		{
			//equal value itself
			count1 = count1;
		}

		//calling xor1 function itself
		xor1(array, count1, k, m, n, i, j + 1, z);
	}

	//consider the logic
	else if (i < m && j == n)
	{
		//consider the logic
		if (count1 %2== 1)
		{
			//assign value to the array element
			array[i][j] = 1;
		}

		//consider the logic
		else
		{
			//assign value to the array element
			array[i][j] = 0;
		}

		//assign values to the variables
		j = 0;
		count1 = 0;
		k = z;

		//calling xor1 function it self
		xor1(array, count1, k - 1, m, n, i + 1, j, z - 1);

	}
}

//declare a function to get a output values from the array elements
void rec(int **array, int i,int j,int n,int m)
{
	//consider the logic
	if (i<m&&j >= 0)
	{
		//output to the console window
		cout << array[i][j];

		//calling rec function it self
		rec(array, i, j - 1,n,m);
	}

	//consider the logic
	else if (i<m&&j == -1)
	{
		//output to the console window
		cout << " > ";

		//output to thw console window
		cout << array[i][n];

		//getting a new line
		cout << endl;

		//rec function calling it self
		rec(array, i+1, n-1, n, m);
	}
}

//declare a main function
int main()
{
	//declare variables
	int gate, n;

	//output to the console window
	cout << "\t***__________LOGIC GATES__________***\n";
	cout << "\n\n\t\t1 - AND GATE\n\t\t2 - OR GATE\n\t\t3 - XOR GATE\n\nChoose your gate : ";
	
	//getting user input
	cin >> gate;

	//consider the logic
	if (gate == 1 || gate == 2 || gate == 3)
	{
		//output to the console window
		cout << "\n\n\nEnter number of Inputs : ";

		//getting user input
		cin >> n;

		//getting new lines
		cout << endl << endl << endl;

		//declare variables and assign values for it
		int m = pow(2, n);

		//declare a 2D DMA
		int **array = new int*[m];
		for (int i = 0; i < m; i++)
		{
			array[i] = new int[n+1];
		}

		//declare variables and assign values for it
		int count1 = 0;
		int i = 0;
		int j = 0;

		//consider the logic
		if (gate == 1)
		{
			//calling and1 function
			and1(array, count1, m - 1, m, n, i, j,m-1);
		}

		//consider the logic
		else if (gate == 2)
		{
			//calling or1 function
			or1(array, count1, m - 1,m, n, i, j,m-1);
		}

		//consider the logic
		else if (gate == 3)
		{
			//calling xor1 function
			xor1(array, count1, m - 1,m, n, i, j,m-1);
		}

		//assign values to the variable
		i = 0;

		//calling rec function
		rec(array, i, n - 1, n, m);

		//delete DMA value
		delete[] array;
	}

	//consider the logic
	else
	{
		//output to the console window
		cout << "Wrong Input\n\n\n";
	}
	//getting new lines
	cout << endl << endl << endl << endl;

	//waitting for the user input
	system("pause");
	return 0;

}