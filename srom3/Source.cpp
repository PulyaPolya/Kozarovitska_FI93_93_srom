#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <cstring>
using namespace std;
const int GLOBAL_SIZE = 1000;
int compare_arr(unsigned int a1[], unsigned int b1[])
{
	for (int i = 0; ; )
	{
		while ((i < GLOBAL_SIZE) && (a1[i] == b1[i]))
		{
			i++;

		}

		if (i == GLOBAL_SIZE)
			return 0;
		else if (a1[i] > b1[i])
		{
			return 1;
		}
		else
			return -1;


	}
}
void zero_arr(unsigned int a1[])
{
	for (int i = 0; i < GLOBAL_SIZE; i++)
	{
		a1[i] = 0;
	}
}
void string_to_arr(string a,unsigned int a1[])
{
	zero_arr(a1);
	int falta = GLOBAL_SIZE - a.length();
	string zero = "";
	for (int i = 0; i < falta; i++)
		zero.append("0");
	zero.append(a);
	a = zero;
	for (int i = 0; i < GLOBAL_SIZE; i++)
	{
		a1[i] =a[i]-'0';
		
	}
}
void show_arr(unsigned int a1[])
{
	cout << endl;
	int i = 0;
	while (a1[i] == 0)
		i++;
	int pow = GLOBAL_SIZE - i - 1;
	if (i == GLOBAL_SIZE - 1)
	{
		cout << 1;
		i++;
		pow--;
	}
	else if (i == GLOBAL_SIZE - 2)
	{
		cout <<  "x";
		i++;
		pow--;
	}
	else if (i == GLOBAL_SIZE)
	{
		cout << 0;
	}
	else
	{
		cout << "x^" << pow;
		i++;
		pow--;
	}
	//cout << pow;
	for (i; i < GLOBAL_SIZE; i++)
	{
		if (a1[i] == 1)
		{
			if (i == GLOBAL_SIZE - 1)
			{
				cout << " + " << 1;
			}
			else if (i == GLOBAL_SIZE - 2)
			{
				cout << " + " << "x";
			}
			else {
				cout << " + " << "x^" << pow;
			}

		}
		pow--;
	}
	cout << endl;
	i = 0;
	while (a1[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE; i++)
	{
		cout << a1[i];
	}
	cout << endl;
}
void coma_to_arr(string a, unsigned int a1[])
{
	zero_arr(a1);
	if (a == "(0)")
	{
		
	}
	else if (a == "(1)")
	{
		a1[GLOBAL_SIZE - 1] = 1;
	}
	else {
		int size_str = a.length();

		int* temp = new int[size_str];
		for (int k = 0; k < size_str; k++)
			temp[k] = -1;

		string delimiter = ",";
		size_t pos = 0;
		string token;
		int i = 0;
		while ((pos = a.find(delimiter)) != std::string::npos) {
			token = a.substr(0, pos);
			//cout << token << endl;
			temp[i] = stoi(token);
			i++;
			a.erase(0, pos + delimiter.length());
		}
		//std::cout << s << std::endl;
		temp[size_str - 1] = stoi(a);
		//for (int j = 0; j < size_str; j++)
			//cout <<temp[j] << " ";
		for (int j = 0; j < size_str; j++)
		{
			if (temp[j] != -1)
			{
				a1[GLOBAL_SIZE - temp[j] - 1] = 1;
			}
		}
		//show_arr(a1);
		delete[] temp;
	}
}



void assign_arr(unsigned int a1[], unsigned int b1[])
{
	for (int i = 0; i < GLOBAL_SIZE; i++)
		a1[i] = b1[i];
}
void sum_arr(unsigned int a1[], unsigned int b1[], unsigned int res[])
{
	unsigned int res1[GLOBAL_SIZE];
	zero_arr(res1);
	for (int i = 0; i < GLOBAL_SIZE; i++)
	{
		res1[i] = a1[i] ^ b1[i];
	}
	assign_arr(res, res1);
}


void mulN_arr(unsigned int a1[], int n, unsigned int res[])
{
	zero_arr(res);
	if (n == 1)
	{
		assign_arr(res, a1);
	}

}
void shift_arr(unsigned int a1[], int k)
{

	int i = 0;
	while (a1[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE; i++)
	{
		a1[i - k] = a1[i];
	}
	for (int j = GLOBAL_SIZE - k; j < GLOBAL_SIZE; j++)
		a1[j] = 0;
}
void mult_arr(unsigned int a1[], unsigned int b1[], unsigned int res[])
{
	unsigned int temp[GLOBAL_SIZE];
	unsigned int mult1[GLOBAL_SIZE];
	zero_arr(mult1);
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		
		mulN_arr(a1, b1[i], temp);
		shift_arr(temp, GLOBAL_SIZE - 1 - i);
		sum_arr(mult1, temp, mult1);
	}
	//mod_arr(mult1, mod, mult1);
	assign_arr(res, mult1);
}
int deg_arr(unsigned int a1[])
{
	int i = 0;
	while (a1[i] == 0)
		i++;
	return  GLOBAL_SIZE - i - 1;
}
int size_arr(unsigned int a1[])
{
	int i = 0;
	while (a1[i] == 0)
		i++;
	return  i;
}
void mod_arr(unsigned int a1[], unsigned int mod[], unsigned int res[])
{
	/*int i = 0;
	while (a1[i] == 0)
		i++;
	//cout << endl << "this is a1(mult)" << endl;
	//show_arr(a1);
	int deg_a1 = GLOBAL_SIZE - i - 1;
	i = 0;
	while (mod[i] == 0)
		i++;
	int deg_mod = GLOBAL_SIZE - i - 1;
	int falta;*/
	int deg_mod = deg_arr(mod);
	unsigned int diff_sft_mod_and_a1[GLOBAL_SIZE];
	zero_arr(diff_sft_mod_and_a1);
	assign_arr(diff_sft_mod_and_a1, a1	);
	while ((compare_arr(diff_sft_mod_and_a1, mod)==1)|| (compare_arr(diff_sft_mod_and_a1, mod) == 0))
	{
		unsigned int falta_arr[GLOBAL_SIZE];
		zero_arr(falta_arr);
		int deg_diff = deg_arr(diff_sft_mod_and_a1);
		int falta = deg_diff - deg_mod;
		falta_arr[GLOBAL_SIZE - 1 - falta] = 1;
		//cout << endl << "this is falta_arr " << endl;
		//show_arr(falta_arr);
		unsigned int mod_shifted[GLOBAL_SIZE];
		zero_arr(mod_shifted);
		assign_arr(mod_shifted, mod);
		shift_arr(mod_shifted, falta);
		//cout << "this is mod_shifted";
		//show_arr(mod_shifted);
		//zero_arr(diff_sft_mod_and_a1);
		sum_arr(diff_sft_mod_and_a1, mod_shifted, diff_sft_mod_and_a1);
		//cout << "this is mod_shifted- a1(mult)";
		//show_arr(diff_sft_mod_and_a1);
	}
	assign_arr(res, diff_sft_mod_and_a1);
}
void sum_arr_mod(unsigned int a1[], unsigned int b1[], unsigned int mod[], unsigned int res[])
{
	unsigned int sum[GLOBAL_SIZE];
	zero_arr(sum);
	unsigned int temp_res[GLOBAL_SIZE];
	zero_arr(temp_res);
	sum_arr(a1, b1, sum);
	mod_arr(sum, mod, temp_res);
	assign_arr(res, temp_res);
}
void mult_arr_mod(unsigned int a1[], unsigned int b1[], unsigned int mod[], unsigned int res[])
{
	unsigned int mult[GLOBAL_SIZE];
	zero_arr(mult);
	unsigned int temp_res[GLOBAL_SIZE];
	zero_arr(temp_res);
	mult_arr(a1, b1, mult);
	mod_arr(mult, mod, temp_res);
	assign_arr(res, temp_res);
}
void square_arr(unsigned int a1[], unsigned int res[])
{
	zero_arr(res);
	int j = GLOBAL_SIZE-1;
	for (int i = GLOBAL_SIZE-1; i >= 0; i--)
	{
		res[j] = a1[i];
		j = j - 2;
		if (j <= 2)
			break;
	}
}
void square_arr_mod(unsigned int a1[], unsigned int mod[], unsigned int res[])
{
	unsigned int square[GLOBAL_SIZE];
	zero_arr(square);
	unsigned int temp_res[GLOBAL_SIZE];
	zero_arr(temp_res);
	square_arr(a1, square);
	mod_arr(square, mod, temp_res);
	assign_arr(res, temp_res);
}
void pow_arr_mod(unsigned int a1[], unsigned int b1[], unsigned int mod[], unsigned int res[])
{
	
	res[GLOBAL_SIZE - 1] = 1;
	unsigned int c1[GLOBAL_SIZE];
	zero_arr(c1);
	unsigned int a1_copy[GLOBAL_SIZE];
	zero_arr(a1_copy);
	assign_arr(a1_copy, a1);
	c1[GLOBAL_SIZE - 1] = 1;
	cout << endl<<"this is b1";
	show_arr(b1);
	for (int i = GLOBAL_SIZE - 1; i >=size_arr(b1); i--)
	{
		if (b1[i] == 1)

		{
			mult_arr_mod(c1, a1_copy,mod, c1);// added c

		}
		mult_arr_mod(a1_copy, a1_copy, mod, a1_copy);/// added c

	}
	mod_arr(c1, mod, c1);
	assign_arr(res, c1);
	
}
void minus_arr(unsigned int a1[], unsigned int deg[], unsigned int mod[], unsigned int res[])
{
	cout << endl << "this is deg";
	show_arr(deg);
	unsigned int pow[GLOBAL_SIZE];
	zero_arr(pow);
	unsigned int temp_res[GLOBAL_SIZE];
	zero_arr(temp_res);
	pow_arr_mod(a1,deg,mod, pow);
	mod_arr(pow, mod, temp_res);
	assign_arr(res, temp_res);
}
void trace_arr(unsigned int a1[], unsigned int mod[], unsigned int res[])
{
	string q = "10";
	unsigned int two [GLOBAL_SIZE];
	zero_arr(two);
	string_to_arr(q, two);
	unsigned int trace[GLOBAL_SIZE];
	zero_arr(trace);
	unsigned int pow[GLOBAL_SIZE];
	zero_arr(pow);
	assign_arr(pow, a1);
	cout << endl << "this is a1 ";
	show_arr(a1);
	cout << endl << "this is pow ";
	show_arr(pow);
	//sum_arr_mod(a1, trace, mod, trace);
	//square_arr_mod(a1, two, mod);
	sum_arr_mod(pow, trace, mod, trace);
	cout << endl << "this is trace ";
	show_arr(trace);
	for (int n = 2; n < 280; n++)
	{
		square_arr_mod(pow,mod, pow);
		cout << endl << "this is n " << n;
		cout << endl << "this is pow " ;
		show_arr(pow);
		//cout << endl << "this is q^n ";
		//shift_arr(two, 1);
		//show_arr(two);
		//pow_arr_mod(a1, two, mod, pow);

		sum_arr_mod(pow, trace, mod, trace);
		cout << endl << "this is trace ";
		show_arr(trace);
	}
	assign_arr(res, trace);
}
int trace_arr1(unsigned int a1[], unsigned int mod[], unsigned int res)
{
	if (a1[GLOBAL_SIZE - 1] == 1)
		return 1;
	else
		return  0;
}
int main()
{

	ifstream file;
	file.open("file.txt");
	string a, b,c,d, m;
	getline(file, a);
	getline(file, b);
	getline(file, c);
	getline(file, d);
	getline(file, m);
	a.erase(remove_if(a.begin(), a.end(), isspace), a.end());
	b.erase(remove_if(b.begin(), b.end(), isspace), b.end());
	c.erase(remove_if(c.begin(), c.end(), isspace), c.end());
	d.erase(remove_if(d.begin(), d.end(), isspace), d.end());
	m.erase(remove_if(m.begin(), m.end(), isspace), m.end());
	unsigned int a1[GLOBAL_SIZE];
	zero_arr(a1);
	string_to_arr(a, a1);
	unsigned int b1[GLOBAL_SIZE];
	zero_arr(b1);
	string_to_arr(b, b1);
	unsigned int c1[GLOBAL_SIZE];
	zero_arr(c1);
	string_to_arr(c, c1);
	unsigned int deg[GLOBAL_SIZE];
	zero_arr(deg);
	string_to_arr(d, deg);
	unsigned int mod[GLOBAL_SIZE];
	zero_arr(mod);
	coma_to_arr(m, mod);
	cout << endl << a;
	cout << endl << b;
	cout << endl << c;
	cout << endl << d;
	cout << endl << m;
	cout << endl<<"these are arrays";
	show_arr(a1);
	show_arr(b1);
	show_arr(c1);
	show_arr(deg);
	show_arr(mod);
	unsigned int sum[GLOBAL_SIZE];
	zero_arr(sum);
	auto t1 = std::chrono::high_resolution_clock::now();
	sum_arr_mod(a1, b1,mod, sum);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
	cout << endl << "this is sum";
	show_arr(sum);
	cout << endl << "sum time gone " << int_ms.count() << "[mcs]" << endl;
	unsigned int mult[GLOBAL_SIZE];
	zero_arr(mult);
	auto t5 = std::chrono::high_resolution_clock::now();
	mult_arr_mod(a1, b1,mod, mult);
	auto t6 = std::chrono::high_resolution_clock::now();
	auto int_ms2 = std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5);
	cout << endl << "this is mult";
	show_arr(mult);
	cout << endl << "mult time gone " << int_ms2.count() << "[mcs]" << endl;
	/*unsigned int mult_mod[GLOBAL_SIZE];
	zero_arr(mult_mod);
	mod_arr(mult, mod, mult_mod);
	cout << endl << "this is mult_mod";
	show_arr(mult_mod);*/
	/*string a_coma;
	getline(file, a_coma);
	unsigned int a2[GLOBAL_SIZE];
	zero_arr(a2);
	coma_to_arr(a_coma,a2);
	cout << endl<<"this is a2";
	show_arr(a2);
	cout << a_coma;*/
	unsigned int square[GLOBAL_SIZE];
	zero_arr(square);
	auto t3 = std::chrono::high_resolution_clock::now();
	square_arr_mod(a1,mod, square);
	auto t4 = std::chrono::high_resolution_clock::now();
	auto int_ms1 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3);
	cout << endl << "this is square";
	show_arr(square);
	cout << endl << "square time gone " << int_ms1.count() << "[mcs]" << endl;
	unsigned int pow[GLOBAL_SIZE];
	zero_arr(pow);
	auto t9 = std::chrono::high_resolution_clock::now();
	pow_arr_mod(a1, c1,mod, pow);
	auto t10 = std::chrono::high_resolution_clock::now();
	auto int_ms4 = std::chrono::duration_cast<std::chrono::microseconds>(t10 - t9);
	cout << endl << "this is pow";
	show_arr(pow);
	cout << endl << "pow time gone " << int_ms4.count() << "[mcs]" << endl;
	unsigned int minus[GLOBAL_SIZE];
	zero_arr(minus);
	auto t11 = std::chrono::high_resolution_clock::now();
	minus_arr(a1, deg, mod, minus);
	auto t12 = std::chrono::high_resolution_clock::now();
	auto int_ms5 = std::chrono::duration_cast<std::chrono::microseconds>(t12 - t11);
	cout << endl << "this is minus";
	show_arr(minus);
	cout << endl << "minus time gone " << int_ms5.count() << "[mcs]" << endl;
	unsigned int trace[GLOBAL_SIZE];
	zero_arr(trace);
	int trace1 = 0;
	auto t13 = std::chrono::high_resolution_clock::now();
	trace1=trace_arr1(a1,  mod, trace1);
	auto t14 = std::chrono::high_resolution_clock::now();
	auto int_ms6 = std::chrono::duration_cast<std::chrono::microseconds>(t14 - t13);
	cout << endl << "this is trace";
	show_arr(trace);
	cout << endl << "trace time gone " << int_ms6.count() << "[mcs]" << endl;
	/*unsigned int square_mod[GLOBAL_SIZE];
	zero_arr(square_mod);
	mod_arr(square, mod, square_mod);
	cout << endl << "this is square_mod";
	show_arr(square_mod);*/
	return 0;
}