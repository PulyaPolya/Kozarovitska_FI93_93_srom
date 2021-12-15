#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <chrono>
int s = pow(2, 16);
using namespace std;

const int GLOBAL_SIZE = 300;
unsigned int cero[GLOBAL_SIZE];
unsigned int two[GLOBAL_SIZE];
unsigned int one[GLOBAL_SIZE];
void zero_arr(unsigned int a[])
{
	for (int i = 0; i < GLOBAL_SIZE; i++)
		a[i] = 0;
}
void init_arr()
{
	zero_arr(cero);
	zero_arr(two);
	zero_arr(one);
	two[GLOBAL_SIZE - 1] = 2;
	one[GLOBAL_SIZE - 1] = 1;
}
int hexadecimalToDecimal(string hexVal)
{
	int len = hexVal.size();
	int base = 1;

	int dec_val = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (hexVal[i] >= '0' && hexVal[i] <= '9')
		{
			dec_val += (int(hexVal[i]) - 48) * base;
			base = base * 16;
		}
		else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
		{
			dec_val += (int(hexVal[i]) - 55) * base;

			base = base * 16;
		}
	}
	return dec_val;
}
char getHexCharacter(std::string str)
{
	if (str.compare("1111") == 0)
		return 'F';
	else if (str.compare("1110") == 0)
		return 'E';
	else if (str.compare("1101") == 0)
		return 'D';
	else if (str.compare("1100") == 0)
		return 'C';
	else if (str.compare("1011") == 0)
		return 'B';
	else if (str.compare("1010") == 0)
		return 'A';
	else if (str.compare("1001") == 0)
		return '9';
	else if (str.compare("1000") == 0)
		return '8';
	else if (str.compare("0111") == 0)
		return '7';
	else if (str.compare("0110") == 0)
		return '6';
	else if (str.compare("0101") == 0)
		return '5';
	else if (str.compare("0100") == 0)
		return '4';
	else if (str.compare("0011") == 0)
		return '3';
	else if (str.compare("0010") == 0)
		return '2';
	else if (str.compare("0001") == 0)
		return '1';
	else if (str.compare("0000") == 0)
		return '0';
	else if (str.compare("111") == 0)
		return '7';
	else if (str.compare("110") == 0)
		return '6';
	else if (str.compare("101") == 0)
		return '5';
	else if (str.compare("100") == 0)
		return '4';
	else if (str.compare("011") == 0)
		return '3';
	else if (str.compare("010") == 0)
		return '2';
	else if (str.compare("001") == 0)
		return '1';
	else if (str.compare("000") == 0)
		return '0';
	else if (str.compare("11") == 0)
		return '3';
	else if (str.compare("10") == 0)
		return '2';
	else if (str.compare("01") == 0)
		return '1';
	else if (str.compare("00") == 0)
		return '0';
	else if (str.compare("1") == 0)
		return '1';
	else if (str.compare("0") == 0)
		return '0';
}
int size(int s)
{
	if (s % 4 != 0)
		return s / 4 + 1;
	else
		return s / 4;
}


string int2hex(unsigned int n)
{
	stringstream stream;
	stream << hex << n;
	return stream.str();
}
string normal_to_hex(unsigned int k)
{
	string temp = int2hex(k);
	int falta = 4 - temp.length();
	if (falta <= 0)
		return temp;
	else
	{
		string new_str = string(falta, '0') + temp;
		return new_str;
	}
}
string to_str_bin(unsigned int a[])
{
	string s = "";
	int i = 0;
	while (a[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE; i++)
		s.append(to_string(a[i]));
	return s;
}
unsigned int* one_arr()
{
	unsigned int* one = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE - 1; i++)
		one[i] = 0;
	one[GLOBAL_SIZE - 1] = 1;
	return one;
}
unsigned int* two_arr()
{
	unsigned int* one = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE - 1; i++)
		one[i] = 0;
	one[GLOBAL_SIZE - 1] = 2;
	return one;
}
unsigned int* cero_arr()
{
	unsigned int* one = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE; i++)
		one[i] = 0;
	return one;
}
string to_binary(int a)
{
	string r;
	while (a != 0)
	{
		r = (a % 2 == 0 ? "0" : "1") + r;
		a /= 2;
	}
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
		if (i == x.length())
			;
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
		if (i == x.length())
			;
		return x;
	}
	else
		return y;
}

int compare_strings(string x, string y)
{
	if (x.length() > y.length())
		return 1;
	else if (x.length() == y.length())
	{
		int i = 0;
		for (i; i < x.length();)
		{
			if (x[i] == y[i])
				i++;
			else if (x[i] > y[i])
				return 1;
			else
				return -1;
		}
		if (i == x.length())
			;
		return 1;
	}
	else
		return -1;
}
string to_bin(unsigned int a[])
{
	string bin = "";
	//unsigned int* res = new unsigned int[GLOBAL_SIZE];
	string temp = "";
	int sz;
	int k = 0;
	int i = 0;
	while (a[i] == 0)
		i++;
	temp = to_binary(a[i]);
	bin.append(temp);
	i++;
	//cout <<endl<< "first is " << bin;
	for (i; i < GLOBAL_SIZE; i++)
	{
		temp = to_binary(a[i]);
		int falta = 16 - temp.length();
		if (falta > 0)
		{
			temp = string(falta, '0') + temp;
		}
		//cout << endl << "temp is " << temp;
		bin.append(temp);
	}
	k = 0;
	int size_bin = bin.size();
	return bin;
}
unsigned int* from_str_to_arrr(string c)
{
	unsigned int* res;
	res = cero_arr();
	int k = 0;
	for (int i = GLOBAL_SIZE - c.length(); i < GLOBAL_SIZE; i++)
	{
		res[i] = c[k] - '0';
		k++;
	}
	return res;
}
void from_str_to_arrr1(string c, unsigned int res[])
{
	zero_arr(res);
	int k = 0;
	for (int i = GLOBAL_SIZE - c.length(); i < GLOBAL_SIZE; i++)
	{
		res[i] = c[k] - '0';
		k++;
	}
}
unsigned int* pow_2(unsigned int a[], unsigned int n)
{
	a[GLOBAL_SIZE - 1 - n] = 1;
	return a;
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
	//	cout<<"this is i" <<i;
	if (i >= GLOBAL_SIZE)
	{
		cout << 0;
		cout << endl;
	}
	else
	{
		for (i; i < GLOBAL_SIZE; i++)
			//cout << a[i]<<" ";
			cout << to_Hex_Elem(a[i]) << " ";
		cout << endl;
	}
}
unsigned int* to_arr(string A_16)
{
	for (int i = 0; i < A_16.length(); i++)
		A_16[i] = toupper(A_16[i]);
	string temp_string;
	int size_A = A_16.length();
	if (size_A == 1)
	{
		string zeroo = "000";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if (size_A == 2)
	{
		string zeroo = "00";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if (size_A == 3)
	{
		string zeroo = "0";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	size_A = A_16.length();
	int size_a = A_16.length() / 4;
	int size_a1 = size(A_16.length()); // mistake
	unsigned int* a = new unsigned int[size_a1];
	string t;
	for (int k = 0; k < size_a1; k++) // all elements =0
	{
		a[k] = 0;
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
	unsigned int* a1 = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE - size_a1; i++)
		a1[i] = 0;
	for (int i = GLOBAL_SIZE - size_a1; i < GLOBAL_SIZE; i++)
		a1[i] = a[i - GLOBAL_SIZE + size_a1];
	////cout <<endl<< "this is a1 ";
	//show_arr(a1);
	return a1;
}
void to_arr2(string A_16, unsigned int a1[])
{
	zero_arr(a1);
	for (int i = 0; i < A_16.length(); i++)
		A_16[i] = toupper(A_16[i]);
	string temp_string;
	int size_A = A_16.length();
	if (size_A == 1)
	{
		string zeroo = "000";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if (size_A == 2)
	{
		string zeroo = "00";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if (size_A == 3)
	{
		string zeroo = "0";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	size_A = A_16.length();
	int size_a = A_16.length() / 4;
	int size_a1 = size(A_16.length()); // mistake
	unsigned int* a = new unsigned int[size_a1];
	string t;
	for (int k = 0; k < size_a1; k++) // all elements =0
	{
		a[k] = 0;
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

	for (int i = 0; i < GLOBAL_SIZE - size_a1; i++)
		a1[i] = 0;
	for (int i = GLOBAL_SIZE - size_a1; i < GLOBAL_SIZE; i++)
		a1[i] = a[i - GLOBAL_SIZE + size_a1];
	delete[] a;
}
void assign(unsigned int a[], unsigned int b[])
{
	for (int i = 0; i < GLOBAL_SIZE; i++)
		a[i] = b[i];
}
int compare(unsigned int a[], unsigned int b[])
{
	for (int i = 0;;)
	{
		while (a[i] == b[i])
		{
			i++;
		}

		if (i == GLOBAL_SIZE)
			return 1;
		else if (a[i] > b[i])
			return 1;
		else
			return -1;
	}
}
int compare1(unsigned int a[], unsigned int b[])
{
	for (int i = 0;;)
	{
		while ((i < GLOBAL_SIZE) && (a[i] == b[i]))
		{
			i++;
		}

		if (i == GLOBAL_SIZE)
			return 0;
		else if (a[i] > b[i])
		{
			return 1;
		}
		else
			return -1;
	}
}
unsigned int* sum_arr(unsigned int a[], unsigned int b[], unsigned int res[])
{
	unsigned int res1[GLOBAL_SIZE];
	zero_arr(res1);
	int carry = 0;
	int temp = 0;
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		temp = a[i] + b[i] + carry;
		res1[i] = (temp & (s - 1));
		carry = temp / s;
	}
	assign(res, res1);
	return res;
}
unsigned int* bin_diff_arr(unsigned int a[], unsigned int b[], unsigned int res[])
{
	unsigned int borrow = 0;
	int temp;
	int i;
	for (i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		temp = a[i] - b[i] - borrow;

		if (temp >= 0)
		{
			res[i] = temp;
			borrow = 0;
		}
		else
		{
			res[i] = 2 + temp;
			borrow = 1;
		}
	}

	return res;
}
void bin_diff_arr1(unsigned int a[], unsigned int b[], unsigned int res[])
{
	unsigned int borrow = 0;
	int temp;
	int i;
	for (i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		temp = a[i] - b[i] - borrow;

		if (temp >= 0)
		{
			res[i] = temp;
			borrow = 0;
		}
		else
		{
			res[i] = 2 + temp;
			borrow = 1;
		}
	}
}
unsigned int* diff_arr(unsigned int a[], unsigned int b[], unsigned int res[])
{
	unsigned int res1[GLOBAL_SIZE];
	zero_arr(res1);
	unsigned int borrow = 0;
	int temp;
	int i;
	for (i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		temp = a[i] - b[i] - borrow;

		if (temp >= 0)
		{
			res1[i] = temp;
			borrow = 0;
		}
		else
		{
			res1[i] = s + temp;
			borrow = 1;
		}
	}
	assign(res, res1);
	return res;
}
unsigned int* mulN_arr(unsigned int a[], int n, unsigned int res[])
{
	unsigned int carry = 0;
	unsigned int temp = 0;
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		temp = a[i] * n + carry;
		res[i] = temp & (s - 1);
		carry = (temp >> 16);
	}
	return res;
}
unsigned int* shift_arr(unsigned int a[], int k)
{
	int i = 0;
	while (a[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE; i++)
	{
		a[i - k] = a[i];
	}
	for (int j = GLOBAL_SIZE - k; j < GLOBAL_SIZE; j++)
		a[j] = 0;
	return a;
}
void mult_arr(unsigned int a[], unsigned int b[], unsigned int mult[])
{
	unsigned int temp[GLOBAL_SIZE];
	unsigned int mult1[GLOBAL_SIZE];
	zero_arr(mult1);
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		mulN_arr(a, b[i], temp);
		shift_arr(temp, GLOBAL_SIZE - 1 - i);
		sum_arr(mult1, temp, mult1);
	}
	assign(mult, mult1);
	//return mult;
}
void pow_arr(unsigned int a[], unsigned int b[], unsigned int c[])
{
	c[GLOBAL_SIZE - 1] = 1;
	unsigned int c1[GLOBAL_SIZE];
	zero_arr(c1);
	c1[GLOBAL_SIZE - 1] = 1;
	string b_bin = to_bin(b);
	//unsigned int* temp = new unsigned int[GLOBAL_SIZE];
	unsigned int b_size = b_bin.size();
	for (int i = b_size - 1; i >= 0; i--)
	{
		if (b_bin[i] == '1')

		{
			mult_arr(c1, a, c1); // added c
		}
		mult_arr(a, a, a); /// added c
	}
	assign(c, c1);
}
string shift_string(string a, int n)
{
	for (int i = 0; i < n; i++)
		a.append("0");
	return a;
}
int bit_lngth(unsigned int a[])
{
	int i = 0;
	while (a[i] == 0)
		i++;
	return GLOBAL_SIZE - i;
}
void show_bin(unsigned int a[])
{
	cout << endl;
	int i = 0;
	while (a[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE; i++)
		cout << a[i] << " ";
	cout << endl;
}

string solve(int num)
{
	long int hexa_val = 0, i = 1, r;
	while (num != 0)
	{
		r = num % 10;
		hexa_val = hexa_val + r * i;
		i = i * 2;
		num = num / 10;
	}
	string temp = int2hex(hexa_val);
	//cout << "Equivalent hexadecimal value: " << temp;
	return temp;
}
string binarr_tohex(unsigned int q[])
{
	string temp;
	int i = GLOBAL_SIZE - 1;
	while (q[i] == 0)
	{
		i--;
	}
	string A_16 = "";
	for (i; i >= 0; i--)
	{
		temp = to_string(q[i]);
		A_16.append(temp);
	}
	//cout << "A_16 is"<<endl;
	//cout << A_16;
	string result = "";
	//cout <<endl<< "a 16 " << A_16<<endl;
	int size = A_16.length();
	for (int i = 0; i < A_16.length(); i++)
		A_16[i] = toupper(A_16[i]);
	int size_A = A_16.length();
	if ((size_A == 1) || (size_A % 4 == 1))
	{
		string zeroo = "000";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if ((size_A == 2) || (size_A % 4 == 2))
	{
		string zeroo = "00";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if ((size_A == 3) || (size_A % 4 == 3))
	{
		string zeroo = "0";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	size_A = A_16.length();
	string B_16 = "";
	string t = "";
	string tmp = "";
	for (int i = 0; i < size_A / 4; i++)
	{
		t = A_16.substr(size_A - 4 - 4 * i, 4);
		int num;
		num = std::stoi(t);
		string res = solve(num);
		tmp = res.append(B_16);
		B_16 = tmp;
		string t = "";
	}
	//cout << endl << "b 16 is " << B_16;
	return B_16;
}
string binarr_tohex2(unsigned int q[])
{
	string temp;
	int i = 0;
	while (q[i] == 0)
	{
		i++;
	}
	string A_16 = "";
	for (i; i < GLOBAL_SIZE; i++)
	{
		temp = to_string(q[i]);
		A_16.append(temp);
	}
	string result = "";
	int size = A_16.length();
	for (int i = 0; i < A_16.length(); i++)
		A_16[i] = toupper(A_16[i]);
	int size_A = A_16.length();
	if ((size_A == 1) || (size_A % 4 == 1))
	{
		string zeroo = "000";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if ((size_A == 2) || (size_A % 4 == 2))
	{
		string zeroo = "00";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if ((size_A == 3) || (size_A % 4 == 3))
	{
		string zeroo = "0";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	size_A = A_16.length();
	string B_16 = "";
	string t = "";
	string tmp = "";
	for (int i = 0; i < size_A / 4; i++)
	{
		t = A_16.substr(size_A - 4 - 4 * i, 4);
		int num;
		num = std::stoi(t);
		string res = solve(num);
		tmp = res.append(B_16);
		B_16 = tmp;
		string t = "";
	}
	//cout << endl << "b 16 is " << B_16;
	return B_16;
}
void div_arr2(unsigned int a[], unsigned int b[], unsigned int q[])
{
	string b_bin = to_bin(b);
	b = from_str_to_arrr(b_bin);
	string a_bin = to_bin(a);
	a = from_str_to_arrr(a_bin);
	unsigned int k = b_bin.length();
	unsigned int r[GLOBAL_SIZE];
	unsigned int c[GLOBAL_SIZE];
	assign(r, a);
	int q1 = 0;
	unsigned int t;
	unsigned int temp;
	string help;
	while (compare(r, b) == 1)
	{
		t = bit_lngth(r);
		assign(c, b);
		shift_arr(c, t - k);

		if (compare(r, c) == -1)
		{
			t--;
			assign(c, b);
			shift_arr(c, t - k);
		}
		bin_diff_arr(r, c, r);
		temp = pow(2, t - k);
		string s = normal_to_hex(t - k);
		q1 = q1 + pow(2, t - k);
		q[t - k] = 1;
	}
	//cout <<endl<< "this is q" << endl;
	int i = GLOBAL_SIZE - 1;
	while (q[i] == 0)
	{
		i--;
	}
	//for (i; i>=0; i--)
	//{

	//cout << q[i]<<" ";

	//}
	string temp1 = binarr_tohex(q);
	//cout << endl << "this is str " << temp1;
	unsigned int* q2;
	q2 = to_arr(temp1);
	//cout << endl << "this is qqqq";
	//show_arr(q2);
	assign(q, q2);
	delete[] q2;
}
void div_arr4(unsigned int a[], unsigned int b[], unsigned int q[], unsigned int res2[])
{
	unsigned int b1[GLOBAL_SIZE];
	zero_arr(b1);
	unsigned int a1[GLOBAL_SIZE];
	zero_arr(a1);
	string b_bin = to_bin(b);
	from_str_to_arrr1(b_bin, b1);
	string a_bin = to_bin(a);
	from_str_to_arrr1(a_bin, a1);
	unsigned int k = b_bin.length();
	unsigned int r[GLOBAL_SIZE];
	unsigned int c[GLOBAL_SIZE];
	assign(r, a1);
	int q1 = 0;
	unsigned int t;
	unsigned int temp;
	string help;
	while (compare(r, b1) == 1)
	{
		t = bit_lngth(r);
		assign(c, b1);
		shift_arr(c, t - k);

		if (compare(r, c) == -1)
		{
			t--;
			assign(c, b1);
			shift_arr(c, t - k);
		}
		bin_diff_arr(r, c, r);
		temp = pow(2, t - k);
		string s = normal_to_hex(t - k);
		q1 = q1 + pow(2, t - k);
		q[t - k] = 1;
	}
	//cout << "this is r(div4)";
	//show_arr(r);
	int i = GLOBAL_SIZE - 1;
	while (q[i] == 0)
	{
		i--;
	}
	string temp1 = binarr_tohex(q);
	unsigned int* q2;
	q2 = to_arr(temp1);
	assign(q, q2);
	i = 0;
	unsigned int r2[GLOBAL_SIZE];
	zero_arr(r2);
	unsigned int r3[GLOBAL_SIZE];
	zero_arr(r3);
	mult_arr(b, q, r2);
	diff_arr(a, r2, r3);
	/*while (r[i] == 0)
	{
		i++;
	}
	string temp2 = binarr_tohex(r);
	unsigned int* r2;
	r2 = to_arr(temp2);*/
	assign(res2, r3);
	delete[] q2;
	//delete[] r2;
}

int check_even(unsigned int a[])
{
	if (a[GLOBAL_SIZE - 1] % 2 == 0)
		return 1;
	else
		return 0;
}
unsigned int size_arr(unsigned int a[])
{
	int i = 0;
	while (a[i] == 0)
		i++;
	int size = GLOBAL_SIZE - i;
	return size;
}
void kill_last_digits(unsigned int a[], unsigned int k)
{
	int i = 0;
	int size = size_arr(a);
	unsigned int kill[GLOBAL_SIZE];
	zero_arr(kill);
	while (a[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE - k; i++)
	{
		kill[i + k] = a[i];
	}
	assign(a, kill);
}
void to_arr1(string A_16, unsigned int u[])
{
	for (int i = 0; i < A_16.length(); i++)
		A_16[i] = toupper(A_16[i]);
	string temp_string;
	int size_A = A_16.length();
	if (size_A == 1)
	{
		string zeroo = "000";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if (size_A == 2)
	{
		string zeroo = "00";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	else if (size_A == 3)
	{
		string zeroo = "0";
		string temp = zeroo.append(A_16);
		A_16 = temp;
	}
	size_A = A_16.length();
	int size_a = A_16.length() / 4;
	int size_a1 = size(A_16.length()); // mistake
	unsigned int* a = new unsigned int[size_a1];
	string t;
	for (int k = 0; k < size_a1; k++) // all elements =0
	{
		a[k] = 0;
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
	unsigned int a1[GLOBAL_SIZE];
	zero_arr(a1);
	for (int i = 0; i < GLOBAL_SIZE - size_a1; i++)
		a1[i] = 0;
	for (int i = GLOBAL_SIZE - size_a1; i < GLOBAL_SIZE; i++)
		a1[i] = a[i - GLOBAL_SIZE + size_a1];
	assign(u, a1);
	delete[] a;
	////cout <<endl<< "this is a1 ";
	//show_arr(a1);
}
void count_u(unsigned int n[], unsigned int u[])
{
	zero_arr(u);
	int size = size_arr(n);
	unsigned int betta[GLOBAL_SIZE];
	zero_arr(betta);
	to_arr1("10000", betta);
	string k = normal_to_hex(2 * size);
	unsigned int* upper_k = to_arr(k);
	unsigned int powr[GLOBAL_SIZE];
	zero_arr(powr);
	pow_arr(betta, upper_k, powr);
	div_arr2(powr, n, u);
}
void barret_arr(unsigned int x[], unsigned int n[], unsigned int res[], unsigned int u[])
{
	unsigned int q[GLOBAL_SIZE]; //n is b1, x is a1
	unsigned int x1[GLOBAL_SIZE];
	unsigned int r[GLOBAL_SIZE];
	unsigned int temp[GLOBAL_SIZE];
	//cout << "this is x";
	//show_arr(x);
	zero_arr(q);
	zero_arr(x1);
	zero_arr(r);
	zero_arr(temp);
	assign(x1, x);
	int k = size_arr(n);
	kill_last_digits(x1, k - 1);
	assign(q, x1);
	mult_arr(q, u, q);

	kill_last_digits(q, k + 1);
	mult_arr(q, n, temp);
	diff_arr(x, temp, temp);
	assign(r, temp);
	while (compare(r, n) == 1)
	{
		diff_arr(r, n, r);
	}
	assign(res, r);
}
void min_arr(unsigned int a[], unsigned int b[], unsigned int min[])
{
	if (compare1(a, b) == 1)
		assign(min, b);
	else if (compare1(a, b) == 0)
		assign(min, b);
	else
	{
		assign(min, a);
	}
}
void max_arr(unsigned int a[], unsigned int b[], unsigned int max[])
{
	if (compare1(a, b) == 1)
		assign(max, a);
	else if (compare1(a, b) == 0)
		assign(max, b);
	else
	{
		assign(max, b);
	}
}
void barret_sum_arr(unsigned int a[], unsigned int b[], unsigned int mod[], unsigned int u[], unsigned int res[])
{
	unsigned int res1[GLOBAL_SIZE];
	zero_arr(res1);
	int carry = 0;
	int temp = 0;
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		temp = a[i] + b[i] + carry;
		res1[i] = (temp & (s - 1));
		carry = temp / s;
	}
	//cout << "this is res1(sum)";
	//show_arr(res1);
	barret_arr(res1, mod, res1, u);
	//cout << "this is res1";
	//show_arr(res1);
	assign(res, res1);
}
void barret_diff_arr(unsigned int a[], unsigned int b[], unsigned int mod[], unsigned int u[], unsigned int res[])
{
	unsigned int res1[GLOBAL_SIZE];
	zero_arr(res1);
	unsigned int borrow = 0;
	int temp;
	int i;
	for (i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		temp = a[i] - b[i] - borrow;

		if (temp >= 0)
		{
			res1[i] = temp;
			borrow = 0;
		}
		else
		{
			res1[i] = s + temp;
			borrow = 1;
		}
	}
	barret_arr(res1, mod, res1, u);
	assign(res, res1);
}
void barret_mulN_arr(unsigned int a[], unsigned int n, unsigned int mod[], unsigned int u[], unsigned int res[])
{
	unsigned int res1[GLOBAL_SIZE];
	zero_arr(res1);
	unsigned int carry = 0;
	unsigned int temp = 0;
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		temp = a[i] * n + carry;
		res1[i] = temp & (s - 1);
		carry = (temp >> 16);
	}
	barret_arr(res1, mod, res1, u);
	assign(res, res1);
}
void barret_mult_arr1(unsigned int a[], unsigned int b[], unsigned int mod[], unsigned int u[], unsigned int mult[])
{
	unsigned int temp[GLOBAL_SIZE];
	unsigned int mult1[GLOBAL_SIZE];
	zero_arr(mult1);
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		barret_mulN_arr(a, b[i], mod, temp, u);
		shift_arr(temp, GLOBAL_SIZE - 1 - i);
		barret_sum_arr(mult1, temp, mod, mult1, u);
	}
	barret_arr(mult1, mod, mult1, u);
	assign(mult, mult1);
}
void barret_mult_arr(unsigned int a[], unsigned int b[], unsigned int mod[], unsigned int u[], unsigned int mult[])
{
	//cout << endl<<"this is a";
	//show_arr(a);
	//cout << endl << "this is b";
	//show_arr(b);
	unsigned int temp[GLOBAL_SIZE];
	unsigned int mult1[GLOBAL_SIZE];
	zero_arr(mult1);
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{
		mulN_arr(a, b[i], temp);
		shift_arr(temp, GLOBAL_SIZE - 1 - i);
		sum_arr(mult1, temp, mult1);
	}
	barret_arr(mult1, mod, mult1, u);
	assign(mult, mult1);
	//return mult;
}
void show_bin_arr(unsigned int a[])
{
	int i = 0;
	while (a[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE; i++)
		cout << a[i];
}
int deg_arr(unsigned int a1[])
{
	int i = 0;
	while (a1[i] == 0)
		i++;
	return  GLOBAL_SIZE - i - 1;
}
void barret_pow_arr(unsigned int a[], unsigned int b[], unsigned int mod[], unsigned int u[], unsigned int c[])
{
	c[GLOBAL_SIZE - 1] = 1;
	unsigned int c1[GLOBAL_SIZE];
	zero_arr(c1);
	c1[GLOBAL_SIZE - 1] = 1;
	string b_bin = to_bin(b);
	unsigned int b_size = b_bin.size();
	for (int i = b_size - 1; i >= 0; i--)
	{
		if (b_bin[i] == '1')

		{
			barret_mult_arr(c1, a, mod, u, c1); // added c
		}
		barret_mult_arr(a, a, mod, u, a); /// added c
										  //cout << endl << "this is c1";
										  //show_arr(c1);
										  //cout << endl << "this is a";
										  //show_arr(a);
	}
	assign(c, c1);
}
void sum_arr_polinom(unsigned int a1[], unsigned int b1[], unsigned int res[])
{
	unsigned int res1[GLOBAL_SIZE];
	zero_arr(res1);
	for (int i = 0; i < GLOBAL_SIZE; i++)
	{
		res1[i] = a1[i] ^ b1[i];
	}
	assign(res, res1);
}
void mod_arr(unsigned int a1[], unsigned int mod[], unsigned int res[])
{

	int deg_mod = deg_arr(mod);
	unsigned int diff_sft_mod_and_a1[GLOBAL_SIZE];
	zero_arr(diff_sft_mod_and_a1);
	assign(diff_sft_mod_and_a1, a1);
	while ((compare1(diff_sft_mod_and_a1, mod) == 1) || (compare1(diff_sft_mod_and_a1, mod) == 0))
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
		assign(mod_shifted, mod);
		shift_arr(mod_shifted, falta);
		//cout << "this is mod_shifted";
		//show_arr(mod_shifted);
		//zero_arr(diff_sft_mod_and_a1);
		sum_arr_polinom(diff_sft_mod_and_a1, mod_shifted, diff_sft_mod_and_a1);
		//cout << "this is mod_shifted- a1(mult)";
		//show_arr(diff_sft_mod_and_a1);
	}
	assign(res, diff_sft_mod_and_a1);
}
void sum_arr_mod(unsigned int a1[], unsigned int b1[], unsigned int mod[], unsigned int res[])
{
	unsigned int sum[GLOBAL_SIZE];
	zero_arr(sum);
	unsigned int temp_res[GLOBAL_SIZE];
	zero_arr(temp_res);
	sum_arr_polinom(a1, b1, sum);
	mod_arr(sum, mod, temp_res);
	assign(res, temp_res);
}
const int m =281;
void show_arr_m(unsigned int a[m][m])
{
	for (int i = 0; i < m; i++) {
		
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
	}
}
void pow_matrix()
{
	
	unsigned  int res[m][m];
	unsigned int temp_arr[m][GLOBAL_SIZE];
	for (int i = 0; i < m; i++)
	{
		zero_arr(temp_arr[i]);
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res[i][j] = 0;
		}
	}
	string mod = "7";//233
	unsigned int* mod1 = to_arr(mod);
	unsigned int u[GLOBAL_SIZE];
	zero_arr(u);
	count_u(mod1, u);
	unsigned int uno[GLOBAL_SIZE];
	zero_arr(uno);
	uno[GLOBAL_SIZE - 1] = 1;
	unsigned int cero[GLOBAL_SIZE];
	zero_arr(u);
	unsigned int barr_mult[GLOBAL_SIZE];
	zero_arr(barr_mult);
	unsigned int two2[GLOBAL_SIZE];
	zero_arr(two2);
	two2[GLOBAL_SIZE - 1] = 2;
	unsigned int uno2[GLOBAL_SIZE];
	zero_arr(uno2);
	uno2[GLOBAL_SIZE - 1] = 1;
	assign(barr_mult, two2);
	assign(temp_arr[1], two2);
	assign(temp_arr[0], uno2);
	for (int i = 2; i < m; i++)
	{
		unsigned int two1[GLOBAL_SIZE];
		zero_arr(two1);
		two1[GLOBAL_SIZE - 1] = 2;
		
		unsigned int temp[GLOBAL_SIZE];
		zero_arr(temp);
		
		barret_mult_arr(two1, barr_mult, mod1, u, barr_mult);
			//barret_pow_arr(two1, k, mod1, u, barr_pow1);
		
		assign(temp_arr[i], barr_mult);
		//delete[] k;
	}
	for (int i = 0; i < m; i++)
	{
		//cout << i << " ";
		for (int j = i; j < m; j++)
		{
			
			/*unsigned int two1[GLOBAL_SIZE];
			zero_arr(two1);
			two1[GLOBAL_SIZE - 1] = 2;
			unsigned int two2[GLOBAL_SIZE];
			zero_arr(two2);
			two2[GLOBAL_SIZE - 1] = 2;
			unsigned int temp[GLOBAL_SIZE];
			zero_arr(temp);
			unsigned int barr_pow1[GLOBAL_SIZE];
			zero_arr(barr_pow1);
			//cout << "i is " << i << endl;
			string tmp=int2hex(i);
			//stringstream ss;
			//ss << i;
			//ss >> tmp;

			unsigned int* k = to_arr(tmp);
			if (i == 0)
			{
				assign(barr_pow1, uno);
			}
			else {
				barret_pow_arr(two1, k, mod1, u, barr_pow1);
			}
			//cout << "this is po1w bar ";
			//show_arr(barr_pow1);
			unsigned int barr_pow2[GLOBAL_SIZE];
			zero_arr(barr_pow2);
			//cout << "j is " << j << endl;
			string tmp1=int2hex(j);
			//stringstream ss1;
			//ss1 << j;
			//ss1 >> tmp1;
			unsigned int* k1 = to_arr(tmp1);
			if (j == 0)
			{
				assign(barr_pow2, uno);
			}
			else {
				barret_pow_arr(two2, k1, mod1, u, barr_pow2);
			}
			//cout << "this is po2w bar ";
			//show_arr(barr_pow2);*/
			unsigned int barr_pow1[GLOBAL_SIZE];
			zero_arr(barr_pow1);
			unsigned int barr_pow2[GLOBAL_SIZE];
			zero_arr(barr_pow2);
			unsigned int barr_sum[GLOBAL_SIZE];
			zero_arr(barr_sum);
			assign(barr_pow1, temp_arr[i]);
			assign(barr_pow2, temp_arr[j]);
			//barret_sum_arr(barr_pow1, barr_pow2, mod1, u, barr_sum);
			barret_sum_arr(barr_pow1, barr_pow2, mod1, u, barr_sum);
			//cout << endl
				//<< "this is sum bar ";
			//show_arr(barr_sum);
			unsigned int sum2[GLOBAL_SIZE];
			zero_arr(sum2);
			while (compare(sum2, barr_sum) != 1)
			{
				sum_arr(mod1, mod1, sum2);
				//cout << endl
					//<< "this is sum2 ";
				//show_arr(sum2);
			}

			unsigned int minus[GLOBAL_SIZE];
			zero_arr(minus);
			barret_diff_arr(sum2, barr_sum, mod1, u, minus);
			//cout << endl
				//<< "this is minus ";
			//show_arr(minus);
			unsigned int barr_diff1[GLOBAL_SIZE];
			zero_arr(barr_diff1);
			if (compare(barr_pow1, barr_pow2) == 1)
			{
				
				barret_diff_arr(barr_pow1, barr_pow2, mod1, u, barr_diff1);
				//cout << endl
					//<< "this is diff bar1 ";
				//show_arr(barr_diff1);
			}
			else
			{
				unsigned int sum1[GLOBAL_SIZE];
				zero_arr(sum1);
				sum_arr(barr_pow1, mod1, sum1);
				while (compare(sum1, barr_pow2) != 1)
				{
					sum_arr(barr_pow1, mod1, sum1);
					//cout << endl
						//<< "this is sum1 ";
					//show_arr(sum1);
				}

				//cout << endl
					//<< "this is sum1 ";
				//show_arr(sum1);
				unsigned int barr_diff1[GLOBAL_SIZE];
				zero_arr(barr_diff1);
				barret_diff_arr(sum1, barr_pow2, mod1, u, barr_diff1);
				//cout << endl
					//<< "this is diff bar1 ";
				//show_arr(barr_diff1);
			}
			unsigned int barr_diff2[GLOBAL_SIZE];
			zero_arr(barr_diff2);
			if (compare(barr_pow2, barr_pow1) == 1)
			{
				
				
				barret_diff_arr(barr_pow2, barr_pow1, mod1, u, barr_diff2);
				//cout << endl
					//<< "this is diff bar2 ";
				//show_arr(barr_diff2);
			}
			else
			{
				unsigned int sum2[GLOBAL_SIZE];
				zero_arr(sum2);
				sum_arr(barr_pow2, mod1, sum2);
				while (compare(sum2, barr_pow1) != 1)
				{
					//	unsigned int sum1[GLOBAL_SIZE];
					//	zero_arr(sum1);
					//	cout << endl<<"this is mod1 ";
					//show_arr(mod1);
					//cout << endl<<"this is barr_pow1 in sum1";
					//show_arr(barr_pow1);
					sum_arr(barr_pow2, mod1, sum2);
					cout << endl
						<< "thi is sum2 ";
					show_arr(sum2);
				}

				//cout << endl
					//<< "this is sum2 ";
				//show_arr(sum2);
				unsigned int barr_diff2[GLOBAL_SIZE];
				zero_arr(barr_diff2);
				barret_diff_arr(sum2, barr_pow1, mod1, u, barr_diff2);
				//cout << endl
					//<< "this is diff bar2 ";
				//show_arr(barr_diff2);
			}
			//delete[] k1;
			//delete[] k;
			if( (compare1(uno, barr_sum) == 0) || (compare1(uno, minus) == 0) || (compare1(uno, barr_diff2) == 0) || (compare1(uno, barr_diff1) == 0))
			{
				//cout <<endl<< "result is 1"<< endl;
				res[i][j] = 1;
				res[j][i] = 1;
			}
			else {
				//cout <<endl<< "result is 0"<< endl;
				res[i][j] = 0;
				res[j][i] = 0;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		
		
		for (int j = 0; j < m; j++)
		{
			
			
				cout << res[i][j] ;
				
			
		}
		
		//cout << endl;
	}
	
}
void assign_diff_size(unsigned int a[], unsigned int b[])
{
	for (int i = 0; i < m; i++)
		a[i] = b[i];
}
void mulMat(unsigned int u[m], unsigned int lambda[m][m], unsigned int result[]) {
	unsigned int rslt[m];

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < m; j++) {
			rslt[j] = 0;

			for (int k = 0; k < m; k++) {
				rslt[j] += u[k] * lambda[k][j];
			}
			if (rslt[j] % 2 == 0)
				rslt[j] = 0;
			else
			{
				rslt[j] = 1;
			}
			//cout << rslt[j] << "\t";
		}

		//cout << endl;
	}
	assign_diff_size(result, rslt);
}
unsigned int MulVect(unsigned int  u[m], unsigned int v[m])
{
	unsigned int rslt=0;

	
	for (int i = 0; i < m; i++)
	{
		rslt += u[i] * v[i];
	}
	if (rslt % 2 == 0)
		rslt = 0;
	else
	{
		rslt = 1;
	}
	//cout << "result is " << rslt;
	return rslt;
}
void shift_m(unsigned int  u[m])
{
	unsigned int temp = u[0];
	for (int i=1; i < m; i++)
	{
		u[i - 1] = u[i];
	}
	u[m - 1] = temp;
	
	//return a;
}
void zero_arr_m(unsigned int a[])
{
	for (int i = 0; i < m; i++)
		a[i] = 0;
}

void mult_onb(unsigned int  u1[m], unsigned int  v1[m], unsigned int  lambda[m][m], unsigned int  res1[m])
{
	unsigned int temp_res[m];
	unsigned int res[m];
	unsigned int u[m];
	unsigned int v[m];
	zero_arr_m(temp_res);
	zero_arr_m(res);
	zero_arr_m(u);
	zero_arr_m(v);
	assign_diff_size(u, u1);
	assign_diff_size(v, v1);
	mulMat(u, lambda, temp_res);
	res[0] = MulVect(temp_res, v);
	for (int i = 1; i < m; i++)
	{
		shift_m(u);
		shift_m(v);
		mulMat(u, lambda, temp_res);
		res[i] = MulVect(temp_res, v);
	}
	//for (int i = 0; i < m; i++)
		//cout << res[i];
	assign_diff_size(res1, res);
}
void string_to_arr(string a, unsigned int a1[])
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
		a1[i] = a[i] - '0';

	}
}
void show_arr_polinom(unsigned int a1[])
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
		cout << "x";
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
string square_polinom(string a, unsigned int a1[])
{
	string res = a;
	int size = a.length();
	res.pop_back();
	string temp = string(1, a[size - 1]);
	temp = temp + res;
	res = temp;
	zero_arr(a1);
	//string_to_arr(res, a1);
	
	return res;
}
int trace_polinom(string a)
{

	int sum = 0;
	for (int i = 0; i < a.length(); i++)
	{
		sum+= a[i] - '0';
	}
	cout << endl << "sum is " << endl;
	if (sum % 2 == 0)
	{
		sum = 0;

	}
	else
	{
		sum = 1;
	}
	return sum;
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
void shift_arr_polinom(unsigned int a1[], int k)
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

int size_arr_polinom(unsigned int a1[])
{
	int i = 0;
	while (a1[i] == 0)
		i++;
	return  i;
}

void show_arr_polinom_m(unsigned int a1[m])
{
	cout << endl;
	for (int i = 0; i < m; i++)
		cout << a1[i];
	cout << endl;
}
void pow_arr_mod(unsigned int a1[], unsigned int b1[], unsigned int  lambda[m][m], unsigned int res[])
{
	//res[m - 1] = 1;
	cout << endl << "a1	 is";
	show_arr_polinom_m(a1);
	cout << endl << "b1	 is";
	show_arr(b1);
	unsigned int c1[m];
	zero_arr_m(c1);
	for (int i=0; i<m; i++)
		c1[i] = 1;
	unsigned int a1_copy[m];
	zero_arr_m(a1_copy);
	assign_diff_size(a1_copy, a1);
	for (int i = GLOBAL_SIZE - 1; i >= size_arr_polinom(b1); i--)
	{
		if (b1[i] == 1)
			
		{
			//cout << endl << "c1	 is";
			//show_arr_polinom_m(c1);
			//cout << endl << "a1	 is";
			//show_arr_polinom_m(a1_copy);
			mult_onb(c1, a1_copy,  lambda, c1);// added c
			//cout <<endl<<"c1	 is";
			//show_arr_polinom_m(c1);
		}
		mult_onb(a1_copy, a1_copy,  lambda, a1_copy);/// added c
		//cout << endl << "a1	 is";
		//show_arr_polinom_m(a1_copy);

	}
	//mod_arr(c1, mod, c1);
	assign_diff_size(res, c1);

}
void minus_arr(unsigned int a1[], unsigned int deg[], unsigned int mod[], unsigned int  lambda[m][m], unsigned int res[])
{

	unsigned int pow[GLOBAL_SIZE];
	zero_arr(pow);
	unsigned int temp_res[GLOBAL_SIZE];
	zero_arr(temp_res);
	//pow_arr_mod(a1, deg, mod, lambda, pow);
	mod_arr(pow, mod, temp_res);
	assign(res, temp_res);
}
int main()
{
	/*	//ifstream file;
	//file.open("file1.txt");
	string A_16, B_16;
	cin>>A_16;
	cin>>B_16;
//	getline(file, A_16);
//	getline(file, B_16);
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
	int size_a1 = size(A_16.length());// mistake
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
	unsigned int* a1 = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE - size_a1; i++)
		a1[i] = 0;
	for (int i = GLOBAL_SIZE - size_a1; i < GLOBAL_SIZE; i++)
		a1[i] = a[i - GLOBAL_SIZE + size_a1];
	cout << endl;
	cout << A_16;
	cout << endl << "a1 is ";
	show_arr(a1);
	cout << endl;
	int k1 = 0;
	while (a1[k1] == 0)
		k1++;
	for (k1; k1 < GLOBAL_SIZE; k1++)
		cout << a1[k1] << " ";
	cout << endl;
	unsigned int* b1 = new unsigned int[GLOBAL_SIZE];
	for (int i = 0; i < GLOBAL_SIZE - size_a1; i++)
		b1[i] = 0;
	for (int i = GLOBAL_SIZE - size_a1; i < GLOBAL_SIZE; i++)
		b1[i] = b[i - GLOBAL_SIZE + size_a1];
	cout << "b1 is ";
	show_arr(b1);
	unsigned int sum[GLOBAL_SIZE];
	zero_arr(sum);
	sum_arr(a1, b1, sum);
	cout << "sum is ";
	show_arr(sum);
	unsigned int diff[GLOBAL_SIZE];
	zero_arr(diff);
	diff_arr(a1, b1, diff);
	cout << "diff is ";
	show_arr(diff);
	unsigned int mulN[GLOBAL_SIZE];
	zero_arr(mulN);
	mulN_arr(a1, 0x11, mulN);
	cout << "mulN is ";
	show_arr(mulN);
	unsigned int mult[GLOBAL_SIZE];
	zero_arr(mult);
	mult_arr(a1, b1, mult);
	cout << "mult is ";
	show_arr(mult);
	cout << endl;
	int i = 0;
	while (mult[i] == 0)
		i++;
	for (i; i < GLOBAL_SIZE; i++)
		//cout << a[i]<<" ";
		cout << mult[i] << " ";
	cout << endl;
	unsigned int pow[GLOBAL_SIZE];
	zero_arr(pow);
	//pow_arr(a1, b1, pow);
//	cout << "pow is ";
	//show_arr(pow);
	cout << endl;
	i = 0;
	//while (pow[i] == 0)
	//	i++;
	//for (i; i < GLOBAL_SIZE; i++)
		//cout << a[i]<<" ";
		//cout << pow[i] << " ";
	cout << endl;
	unsigned int div2[GLOBAL_SIZE];
	zero_arr(div2);
	div_arr2(a1, b1,div2);
	cout << "this is div ";
	show_arr(div2);
	unsigned int div3[GLOBAL_SIZE];
	zero_arr(div3);
	unsigned int rrr1[GLOBAL_SIZE];
	zero_arr(rrr1);
	div_arr4(mult, b1, div3, rrr1);
	cout << "this is div3 ";
	show_arr(div3);
	unsigned int div4[GLOBAL_SIZE];
	unsigned int rrr[GLOBAL_SIZE];
	zero_arr(div4);
	zero_arr(rrr);
	div_arr4(a1, b1, div4,rrr);
	cout << "this is div4 ";
	show_arr(div4);
	cout << "this is a (mod)b ";
	show_arr(rrr);
	//barret_arr(a1, b1, barret,u);
	string mod;
	//cout<<"insert mod";
	//getline(file, mod);
/*	cin>>mod;
	unsigned int* mod1 = to_arr(mod);
	unsigned int u[GLOBAL_SIZE];
	zero_arr(u);
	count_u(mod1, u);
	unsigned int barret[GLOBAL_SIZE];
	zero_arr(barret);
	unsigned int barr_sum[GLOBAL_SIZE];
	zero_arr(barr_sum);
	barret_sum_arr(a1, b1,mod1, u,barr_sum);
	cout << endl<<"this is sum bar ";
	show_arr(barr_sum);
	unsigned int barr_diff[GLOBAL_SIZE];
	zero_arr(barr_diff);
	barret_diff_arr(a1, b1, mod1,u, barr_diff);
	cout << endl << "this is diff bar ";
	show_arr(barr_diff);
	unsigned int barr_mulN[GLOBAL_SIZE];
	zero_arr(barr_mulN);
	//barret_mulN_arr(a1, 0xffff, mod1,u, barr_mulN);
	//cout << endl << "this is mulN bar ";
	//show_arr(barr_mulN);
	unsigned int barr_mult[GLOBAL_SIZE];
	zero_arr(barr_mult);
	barret_mult_arr(a1, b1, mod1,u, barr_mult);
	cout << endl << "this is mult bar ";
	show_arr(barr_mult);

	/*unsigned int gcd[GLOBAL_SIZE];
	zero_arr(gcd);
	unsigned int lcm[GLOBAL_SIZE];
	zero_arr(lcm);
	evkl_arr(a1, b1,gcd,lcm);
	cout << "this is gcd ";
	show_arr(gcd);
	cout << "this is lcm ";
	show_arr(lcm);
	unsigned int barr_pow[GLOBAL_SIZE];
	zero_arr(barr_pow);
	barret_pow_arr(a1, b1, mod1, u, barr_pow);
	cout << endl << "this is pow bar ";
	show_arr(barr_pow);*/
ifstream file2;
file2.open("file2.txt");
string a, b,c;
string m1 = "281,9,4,1,0";
string d = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110";
getline(file2, a);
getline(file2, b);
getline(file2, c);
unsigned int a1[GLOBAL_SIZE];
zero_arr(a1);
string_to_arr(a, a1);
unsigned int b1[GLOBAL_SIZE];
zero_arr(b1);
string_to_arr(b, b1);
unsigned int c1[GLOBAL_SIZE];
zero_arr(c1);
string_to_arr(c, c1);
unsigned int mod[GLOBAL_SIZE];
zero_arr(mod);
coma_to_arr(m1, mod);
unsigned int deg[GLOBAL_SIZE];
zero_arr(deg);
string_to_arr(d, deg);
file2.close();
ifstream file;
file.open("file.txt");
unsigned int a_m[m];
	for (int i = 0; i < m; i++)
	{
		char c;
		file.get(c);
		a_m[i] = c - '0';
	}
cout << endl<<"this is a"<< endl;

for (int i = 0; i < m; i++)
{

	cout << a_m[i];
}
unsigned int b_m[m];
for (int i = 0; i < m; i++)
{
	char c;
	file.get(c);
	b_m[i] = c - '0';
}
cout <<endl<< "this is b"<< endl;
for (int i = 0; i < m; i++)
{

	cout << b_m[i];
}
	unsigned int a_temp[GLOBAL_SIZE];
	zero_arr(a_temp);
	
	unsigned int res[m];
	zero_arr_m(res);
	file.close();
	ifstream file1;
	file1.open("file11.txt");
	
	unsigned int arr[m][m];
	
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < m; i++)
		{
			char ch;
			file1.get(ch);
			arr[i][j] = ch - '0';
		}
	}
	/*unsigned int sum[GLOBAL_SIZE];
	zero_arr(sum);
	auto t1 = std::chrono::high_resolution_clock::now();
	sum_arr_mod(a1, b1, mod, sum);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
	cout << endl << "this is sum";
	show_arr_polinom(sum);
	cout << endl << "sum time gone " << int_ms.count() << "[mcs]" << endl;
	cout << endl << "this is mult"<<endl;
	auto t5 = std::chrono::high_resolution_clock::now();
	mult_onb(a_m, b_m, arr, res);
	auto t6 = std::chrono::high_resolution_clock::now();
	auto int_ms2 = std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5);
	for (int i = 0; i < m; i++)
		cout << res[i];
	cout << endl << "mult time gone " << int_ms2.count() << "[mcs]" << endl;
	auto t3 = std::chrono::high_resolution_clock::now();
	string square = square_polinom(a, a1);
	auto t4 = std::chrono::high_resolution_clock::now();
	auto int_ms1 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3);
	cout << endl << "this is square";
	cout << endl << square;
	cout << endl << "square time gone " << int_ms1.count() << "[mcs]" << endl;
	cout<< endl << "this is trace";
	auto t13 = std::chrono::high_resolution_clock::now();
	int trace_value = trace_polinom(a);
	auto t14 = std::chrono::high_resolution_clock::now();
	auto int_ms6 = std::chrono::duration_cast<std::chrono::microseconds>(t14 - t13);
	cout << endl << trace_value<<endl;
	cout << endl << "trace time gone " << int_ms6.count() << "[mcs]" << endl;
	unsigned int pow[m];
	zero_arr_m(pow);
	auto t9 = std::chrono::high_resolution_clock::now();
	pow_arr_mod(a_m, c1, arr, pow);
	auto t10 = std::chrono::high_resolution_clock::now();
	auto int_ms4 = std::chrono::duration_cast<std::chrono::microseconds>(t10 - t9);
	cout << endl << "this is pow"<<endl;
	for (int i = 0; i < m; i++)
		cout << pow[i];
	cout << endl << "pow time gone " << int_ms4.count() << "[mcs]" << endl;
	
	*/unsigned int minus[GLOBAL_SIZE];
	zero_arr(minus);
	auto t11 = std::chrono::high_resolution_clock::now();
	
	pow_arr_mod(a_m, deg, arr, minus);
	auto t12 = std::chrono::high_resolution_clock::now();
	auto int_ms5 = std::chrono::duration_cast<std::chrono::microseconds>(t12 - t11);
	cout << endl << "this is minus"<<endl;
	for (int i = 0; i < m; i++)
		cout << minus[i];
	cout << endl << "minus time gone " << int_ms5.count() << "[mcs]" << endl;
	//minus_arr(a1, deg, mod, minus);
	//cout << endl << "this is minus";
	//show_arr_polinom(a_temp);
	return 0;
}