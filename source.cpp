#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <fstream>
#include <sstream>
int s = pow(2, 16);
using namespace std;
const int GLOBAL_SIZE = 1000;
string int2hex(unsigned int n)
{
	stringstream stream;
	stream << hex << n;
	return stream.str();
}
unsigned int* one_arr()
{
	unsigned int* one = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE - 1; i++)
		one[i] = 0;
	one[GLOBAL_SIZE - 1] = 1;
	return one;
}
string to_binary(int a)
{
	string r;
	while (a != 0) { r = (a % 2 == 0 ? "0" : "1") + r; a /= 2; }
	return r;
}
string max(string x, string y)
{
	if (x.length() > y.length())
		return x;
	else if (x.length() == y.length())
	{
		int i = 0;
		for (i; i < x.length();)
		{
			if (x[i] == y[i])
				i++;
			else if (x[i] > y[i])
				return x;
			else
				return y;
		}
		if (i == x.length());
		return x;
	}
	else
		return y;
}
string min(string x, string y)
{
	if (x.length() < y.length())
		return x;
	else if (x.length() == y.length())
	{
		int i = 0;
		for (i; i < x.length();)
		{
			if (x[i] == y[i])
				i++;
			else if (x[i] < y[i])
				return x;
			else
				return y;
		}
		if (i == x.length());
		return x;
	}
	else
		return y;
}
int size(int s)
{
	if (s % 4 != 0)
		return s / 4 + 1;
	else
		return s / 4;
}

string to_bin(unsigned int a[], int size)
{
	string bin = "";
	unsigned int* res = new unsigned int[GLOBAL_SIZE];
	string temp = "";
	int k = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		temp = to_binary(a[i]);
		bin.append(temp);
	}
	k = 0;
	int size_bin = bin.size();
	return bin;

}

string to_Hex_Elem(unsigned int n)
{
	string temp = int2hex(n);
	string my_string = to_string(n);
	int falta = 4 - temp.length();
	if (falta <= 0)
		return temp;
	else
	{

		string new_str = string(falta, '0') + temp;
		return new_str;
	}
}
void show_arr(unsigned int a[])
{
	cout << endl;
	int i = 0;
	while (a[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE; i++)
		cout << to_Hex_Elem(a[i]) << " ";
	cout << endl;
}
int hexadecimalToDecimal(string hexVal)
{
	int len = hexVal.size();
	int base = 1;

	int dec_val = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (hexVal[i] >= '0' && hexVal[i] <= '9') {
			dec_val += (int(hexVal[i]) - 48) * base;
			base = base * 16;
		}
		else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
			dec_val += (int(hexVal[i]) - 55) * base;

			base = base * 16;
		}
	}
	return dec_val;
}
int compare(unsigned int a[], unsigned int b[])
{
	int size = GLOBAL_SIZE;
	for (int i = 0; ; )
	{
		while (a[i] == b[i])
		{
			i++;
		}

		if (i == size - 1)
			return 0;
		else if (a[i] > b[i])
			return 1;
		else
			return -1;


	}
}
unsigned int* sum_arr(unsigned int a[], unsigned int b[])
{
	int size = GLOBAL_SIZE;
	unsigned int* res = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE; i++)
		res[i] = 0;
	int carry = 0;
	int temp = 0;
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{

		temp = a[i] + b[i] + carry;
		res[i] = (temp & (s - 1));
		carry = temp / s;
	}
	return res;
}
unsigned int* diff_arr(unsigned int a[], unsigned int b[])
{
	int size = GLOBAL_SIZE;
	int borrow = 0;
	int temp;
	cout << endl << "a";
	show_arr(a);
	cout << endl << "b";
	show_arr(b);
	unsigned int* res = new unsigned int[size];
	int i;
	for (i = size - 1; i >= 0; i--)
	{
		temp = a[i] - b[i] - borrow;

		if (temp >= 0)
		{
			res[i] = temp;
			borrow = 0;
		}
		else
		{
			res[i] = s + temp;
			borrow = 1;
		}

	}

	//res[size] = borrow;//????
	return res;
}
unsigned int* mulN_arr(unsigned int a[], int n)
{
	int size = GLOBAL_SIZE;
	unsigned int carry = 0;
	unsigned int temp = 0;
	unsigned int* mn = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < size; i++)
		mn[i] = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		temp = a[i] * n + carry;
		mn[i] = temp & (s - 1);
		carry = (temp >> 16);

	}
	return mn;
}
unsigned int* shift_arr(unsigned int a[], int k)
{
	int size = GLOBAL_SIZE;
	int i = 0;
	unsigned int* shft = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE; i++)
		shft[i] = 0;
	while (a[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE; i++)
		shft[i - k] = a[i];
	return shft;
}
unsigned int* mult_arr(unsigned int a[], unsigned int b[])
{
	unsigned int* mult = new unsigned int[GLOBAL_SIZE];
	unsigned int* temp = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE; i++)
		mult[i] = 0;
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		temp = mulN_arr(a, b[i]);
		temp = shift_arr(temp, GLOBAL_SIZE - 1 - i);
		mult = sum_arr(mult, temp);
	}
	return mult;
}
unsigned int* pow_arr(unsigned int a[], unsigned int b[], int size)
{
	string b_bin = to_bin(b, GLOBAL_SIZE);
	std::cout << "b bin is " << b_bin << endl;
	unsigned int* c = one_arr();
	unsigned int* temp = new unsigned int[GLOBAL_SIZE];

	unsigned int b_size = b_bin.size();
	for (int i = b_size - 1; i >= 0; i--)
	{
		if (b_bin[i] == '1')

		{
			c = mult_arr(c, a);
		}
		a = mult_arr(a, a);
		cout << endl;

	}
	return c;
}
void check_distr(unsigned int a[], unsigned int b[], unsigned int c[])
{
	unsigned int* t1 = new unsigned int[GLOBAL_SIZE];
	unsigned int* t2 = new unsigned int[GLOBAL_SIZE];
	unsigned int* t3 = new unsigned int[GLOBAL_SIZE];
	unsigned int* t4 = new unsigned int[GLOBAL_SIZE];
	unsigned int* t5 = new unsigned int[GLOBAL_SIZE];
	unsigned int* t6 = new unsigned int[GLOBAL_SIZE];
	t1 = sum_arr(a, b);
	t2 = mult_arr(t1, c);
	t3 = mult_arr(c, t1);
	t4 = mult_arr(a, c);
	t5 = mult_arr(b, c);
	t6 = sum_arr(t4, t5);
	int i = 0;
	for (i = 0; i < GLOBAL_SIZE; )
	{
		if ((t2[i] == t3[i]) && (t2[i] == t6[i]))
		{
			i++;
		}

		else
			break;
	}
	if (i == GLOBAL_SIZE)
		cout << endl << "first rule is true";
}
void check_sum(unsigned int a[], int n)
{
	unsigned int* t1 = new unsigned int[GLOBAL_SIZE];
	unsigned int* t2 = new unsigned int[GLOBAL_SIZE];
	t1 = mulN_arr(a, n);
	t2 = a;
	for (int i = 0; i < n - 1; i++)
	{
		t2 = sum_arr(a, t2);

	}
	cout << endl;
	show_arr(t2);
	cout << endl;
	show_arr(t1);
	int i = 0;
	for (i = 0; i < GLOBAL_SIZE; )
	{
		if (t1[i] == t2[i])
		{
			i++;
		}

		else
			break;
	}
	if (i == GLOBAL_SIZE)
		cout << endl << "second rule is true";
}
int main()
{
	ifstream file;
	file.open("file1.txt");
	string A_16, B_16;
	getline(file, A_16);
	getline(file, B_16);
	string temp_string;
	temp_string = max(A_16, B_16);// making A>B
	B_16 = min(A_16, B_16);
	A_16 = temp_string;
	int size_A = A_16.length();
	int size_B = B_16.length();
	int falta = size_A - size_B;
	string zero = "";
	for (int i = 0; i < falta; i++)
		zero.append("0");
	zero.append(B_16);
	B_16 = zero;
	size_B = B_16.length();
	int size_a = A_16.length() / 4;
	int size_a1 = size(A_16.length());
	unsigned int* a = new unsigned int[size_a1];
	unsigned int* b = new unsigned int[size_a1];
	string t;
	for (int k = 0; k < size_a1; k++)// all elements =0
	{
		a[k] = 0;
		b[k] = 0;
	}
	int k = 0;
	for (int i = size_a1 - 1; i >= 0; i--)
	{
		t = A_16.substr(size_A - 4 - 4 * k, 4);
		a[i] = hexadecimalToDecimal(t);
		t = "";
		k++;
		if (k > (size_A - 4) / 4)
		{
			if (size_A % 4 == 1)
			{
				t = A_16.substr(0, 1);
				a[i - 1] = hexadecimalToDecimal(t);
				t = "";
				break;
			}
			if (size_A % 4 == 2)
			{
				t = A_16.substr(0, 2);
				a[i - 1] = hexadecimalToDecimal(t);
				t = "";
				break;
			}
			if (size_A % 4 == 3)
			{
				t = A_16.substr(0, 3);
				a[i - 1] = hexadecimalToDecimal(t);
				t = "";
				break;
			}
			if (size_A % 4 == 0)
			{
				break;
			}

		}

	}
	k = 0;
	for (int i = size_a1 - 1; i >= 0; i--)
	{
		t = B_16.substr(size_B - 4 - 4 * k, 4);
		b[i] = hexadecimalToDecimal(t);
		t = "";
		k++;
		if (k > (size_B - 4) / 4)
		{
			if (size_A % 4 == 1)
			{
				t = B_16.substr(0, 1);
				b[i - 1] = hexadecimalToDecimal(t);
				t = "";
				break;
			}
			if (size_A % 4 == 2)
			{
				t = B_16.substr(0, 2);
				b[i - 1] = hexadecimalToDecimal(t);
				t = "";
				break;
			}
			if (size_A % 4 == 3)
			{
				t = B_16.substr(0, 3);
				b[i - 1] = hexadecimalToDecimal(t);
				t = "";
				break;
			}
			if (size_A % 4 == 0)
			{
				break;
			}

		}

	}
	cout << "a is " << endl;
	for (int i = 0; i < size_a1; i++)
		cout << hex << a[i] << " ";
	cout << "b is " << endl;
	for (int i = 0; i < size_a1; i++)
		cout << hex << b[i] << " ";
	unsigned int* a1 = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE - size_a1; i++)
		a1[i] = 0;
	for (int i = GLOBAL_SIZE - size_a1; i < GLOBAL_SIZE; i++)
		a1[i] = a[i - GLOBAL_SIZE + size_a1];
	cout << endl << "a1 is " << endl;
	show_arr(a1);
	unsigned int* b1 = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE - size_a1; i++)
		b1[i] = 0;
	for (int i = GLOBAL_SIZE - size_a1; i < GLOBAL_SIZE; i++)
		b1[i] = b[i - GLOBAL_SIZE + size_a1];
	cout << "b1 is " << endl;
	show_arr(b1);
	unsigned int* sum = new unsigned int[GLOBAL_SIZE];
	sum = sum_arr(a1, b1);
	cout << "sum is " << endl;
	show_arr(sum);
	unsigned int* diff = new unsigned int[GLOBAL_SIZE];
	diff = diff_arr(a1, b1);
	cout << "diff is " << endl;
	show_arr(diff);
	unsigned int* mulN = new unsigned int[GLOBAL_SIZE];
	mulN = mulN_arr(a1, 0xbbbb);
	cout << "mulN is " << endl;
	show_arr(mulN);

	unsigned int* shift = new unsigned int[GLOBAL_SIZE];
	shift = shift_arr(a1, 2);
	cout << "shift is " << endl;
	show_arr(shift);
	unsigned int* mult = new unsigned int[GLOBAL_SIZE];
	mult = mult_arr(a1, b1);
	cout << "mult is " << endl;
	show_arr(mult);

	unsigned int* pow;
	pow = pow_arr(a1, b1, size_a1);
	cout << "pow is " << endl;
	show_arr(pow);
	check_distr(a1, b1, b1);
	check_sum(a1, 0x101);
	return 0;

}
