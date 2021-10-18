#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
int s = pow(2, 16);
using namespace std;

const int GLOBAL_SIZE = 3000;
unsigned int cero[GLOBAL_SIZE];
unsigned int two[GLOBAL_SIZE];
unsigned int one[GLOBAL_SIZE];
void zero_arr(unsigned int a[]) {
	for (int i = 0; i < GLOBAL_SIZE; i++)
		a[i] = 0;
}
void init_arr() {
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
char getHexCharacter(std::string str)
{
	if (str.compare("1111") == 0) return 'F';
	else if (str.compare("1110") == 0) return 'E';
	else if (str.compare("1101") == 0) return 'D';
	else if (str.compare("1100") == 0) return 'C';
	else if (str.compare("1011") == 0) return 'B';
	else if (str.compare("1010") == 0) return 'A';
	else if (str.compare("1001") == 0) return '9';
	else if (str.compare("1000") == 0) return '8';
	else if (str.compare("0111") == 0) return '7';
	else if (str.compare("0110") == 0) return '6';
	else if (str.compare("0101") == 0) return '5';
	else if (str.compare("0100") == 0) return '4';
	else if (str.compare("0011") == 0) return '3';
	else if (str.compare("0010") == 0) return '2';
	else if (str.compare("0001") == 0) return '1';
	else if (str.compare("0000") == 0) return '0';
	else if (str.compare("111") == 0) return '7';
	else if (str.compare("110") == 0) return '6';
	else if (str.compare("101") == 0) return '5';
	else if (str.compare("100") == 0) return '4';
	else if (str.compare("011") == 0) return '3';
	else if (str.compare("010") == 0) return '2';
	else if (str.compare("001") == 0) return '1';
	else if (str.compare("000") == 0) return '0';
	else if (str.compare("11") == 0) return '3';
	else if (str.compare("10") == 0) return '2';
	else if (str.compare("01") == 0) return '1';
	else if (str.compare("00") == 0) return '0';
	else if (str.compare("1") == 0) return '1';
	else if (str.compare("0") == 0) return '0';
}
int size(int s)
{
	if (s % 4 != 0)
		return s / 4 + 1;
	else
		return s / 4;
}

std::string getHexRowFails(string rowresult)
{
	std::string endresult = "";
	for (int i = 0; i < rowresult.length(); i = i + 4)
	{
		endresult += getHexCharacter(rowresult.substr(i, 4));
	}
	return endresult;
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
		if (i == x.length());
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
	for (i; i < GLOBAL_SIZE; i++)
		//cout << a[i]<<" ";
		cout << to_Hex_Elem(a[i]) << " ";
	cout << endl;
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
	int size_a1 = size(A_16.length());// mistake
	unsigned int* a = new unsigned int[size_a1];
	string t;
	for (int k = 0; k < size_a1; k++)// all elements =0
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
void assign(unsigned int a[], unsigned int b[])
{
	for (int i = 0; i < GLOBAL_SIZE; i++)
		a[i] = b[i];
}
int compare(unsigned int a[], unsigned int b[])
{
	for (int i = 0; ; )
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
	for (i =GLOBAL_SIZE - 1; i >= 0; i--)
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
		
		mulN_arr(a, b[i],temp);
		shift_arr(temp, GLOBAL_SIZE - 1 - i);
		sum_arr(mult1, temp,mult1);
	}
	assign(mult, mult1);
	//return mult;
}
unsigned int* pow_arr(unsigned int a[], unsigned int b[], unsigned int c[])
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
			mult_arr(c1, a, c1);// added c
			
		}
		mult_arr(a, a,a);/// added c

	}
	assign(c, c1);
	return c;
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
/*unsigned int* div_arr(unsigned int a[], unsigned int b[])
{
	string b_bin = to_bin(b);
	b = from_str_to_arrr(b_bin);
	string a_bin = to_bin(a);
	a = from_str_to_arrr(a_bin);
	unsigned int k = b_bin.length();
	unsigned int* r = a;
	unsigned int* c;
	int q = 0;
	unsigned int t;
	while (compare(r, b) == 1)
	{
		t = bit_lngth(r);
		c = shift_arr(b, t - k);

		if (compare(r, c) == -1)
		{
			t--;
			c = shift_arr(b, t - k);
		}
		r = bin_diff_arr(r, c);
		//cout << endl << "r is ";
		//show_bin(r);
		q = q + pow(2, t - k);
	}
	r[0] = q;
	return r;
}*/
/*unsigned int* div_arr1(unsigned int a[], unsigned int b[])
{
	string b_bin = to_bin(b);
	b = from_str_to_arrr(b_bin);
	string a_bin = to_bin(a);
	//cout << endl << "this is abin " << a_bin;
	a = from_str_to_arrr(a_bin);
	//show_arr(a);
	unsigned int k = b_bin.length();
	unsigned int* r = a;
	unsigned int* c;
	unsigned int* hlp;
	unsigned int* q = cero_arr();
	unsigned int t;
	unsigned int temp;
	string help;
	while (compare(r, b) == 1)
	{
		t = bit_lngth(r);
		c = shift_arr(b, t - k);

		if (compare(r, c) == -1)
		{
			t--;
			c = shift_arr(b, t - k);
		}
		r = bin_diff_arr(r, c);
		temp= pow(2, t - k);
		cout << endl<<"temp is " << temp<<"  "<< t<<" "<<k;
		help = normal_to_hex(temp);
		hlp = to_arr(help);
		show_arr(hlp);
		q = sum_arr(q,hlp,q);///delete q
	}
	//r[0] = q;
	return q;
}*/
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
	if ((size_A == 1)||(size_A%4==1))
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
	for (int i = 0; i <size_A/4; i++)
	{
		t = A_16.substr(size_A - 4 - 4 * i, 4);
		int num;
		num = std::stoi(t);
		string res = solve(num);
		tmp = res.append(B_16);
		B_16=tmp;
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
		bin_diff_arr(r, c,r);
		temp = pow(2, t - k);
		string s = normal_to_hex(t - k);
		q1 = q1 + pow(2, t - k);
		q[t - k] = 1;
	}
	//cout <<endl<< "this is q" << endl;
	int i = GLOBAL_SIZE-1;
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
/*void check_distr(unsigned int a[], unsigned int b[], unsigned int c[])
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
}*/
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
	for (i; i < GLOBAL_SIZE-k; i++)
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
	int size_a1 = size(A_16.length());// mistake
	unsigned int* a = new unsigned int[size_a1];
	string t;
	for (int k = 0; k < size_a1; k++)// all elements =0
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
	unsigned int a1 [GLOBAL_SIZE];
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
	to_arr1("10000",betta);
	string k = normal_to_hex(2 * size);
	unsigned int* upper_k = to_arr(k);
	unsigned int powr[GLOBAL_SIZE];
	zero_arr(powr);
	pow_arr(betta, upper_k,powr);
	//cout << endl << "this is 2^2k " << k;
	//show_arr(powr);
	div_arr2(powr, n, u);
	//cout << "this is u ";
	//show_arr(u);

}
void barret_arr(unsigned int x[], unsigned int n[], unsigned int res[], unsigned int u[])
{
	
	//unsigned int u[GLOBAL_SIZE]; //size n=k, size x=2k
	unsigned int q[GLOBAL_SIZE]; //n is b1, x is a1
	unsigned int x1[GLOBAL_SIZE];
	unsigned int r[GLOBAL_SIZE];
	unsigned int temp[GLOBAL_SIZE];
	zero_arr(q);
	zero_arr(x1);
	zero_arr(r);
	zero_arr(temp);
	assign(x1, x);
	
	//zero_arr(res);
	//cout << endl << "this is x(res1)";
	//show_arr(x);
	//count_u(n, u);
	
	int k = size_arr(n);
	kill_last_digits(x1, k - 1);
	assign(q, x1);
	mult_arr(q, u, q);
	
	kill_last_digits(q, k + 1);
	//cout << "this is q";
	//show_arr(q);
	mult_arr(q, n, temp);
	//cout << "this is q*n";
	//show_arr(temp);
	diff_arr(x, temp, temp);
	//cout << endl << "this is x";
	//show_arr(x);
	//cout << "this is x-q*n";
	//show_arr(temp);
	assign(r, temp);
	//cout << "this is r";
	//show_arr(r);
	while (compare(r, n) == 1)
	{
		//cout <<endl <<"this is r";
		//show_arr(r);
		diff_arr(r, n, r);
		//cout << endl << "this is r";
	}
	assign(res, r);
	//cout << "this is res";
	//show_arr(res);
	
	//mult_arr()

}

void barret_sum_arr(unsigned int a[], unsigned int b[],unsigned int mod[], unsigned int u[],unsigned int res[])
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
	barret_arr(res1, mod, res1,u);
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
	barret_arr(res1, mod, res1,u);
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
		barret_arr(res1,mod,res1,u);
		assign(res, res1);
	
}
void barret_mult_arr1(unsigned int a[], unsigned int b[], unsigned int mod[], unsigned int u[],unsigned int mult[])
{
	unsigned int temp[GLOBAL_SIZE];
	unsigned int mult1[GLOBAL_SIZE];
	zero_arr(mult1);
	for (int i = GLOBAL_SIZE - 1; i >= 0; i--)
	{

		barret_mulN_arr(a, b[i],mod, temp,u);
		shift_arr(temp, GLOBAL_SIZE - 1 - i);
		barret_sum_arr(mult1, temp,mod, mult1,u);
	}
	barret_arr(mult1, mod, mult1,u);
	assign(mult, mult1);
}
void barret_mult_arr(unsigned int a[], unsigned int b[], unsigned int mod[], unsigned int u[],unsigned int mult[])
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
	barret_arr(mult1, mod, mult1,u);
	assign(mult, mult1);
	//return mult;
}
/*unsigned int* euler_arr(unsigned int a[], unsigned int b[])
{
	unsigned int* d = one_arr();
	while ((check_even(a) == 1) && (check_even(b) == 1))
	{
		a = div_arr(a, two_arr());
		b = div_arr(b, two_arr());
		d = mult_arr(d, two_arr());
	}
	while (check_even(a) == 1)
	{
		a = div_arr(a, two_arr());
	}
	return a;
}*/
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
	cout << endl << "a1 is ";
	show_arr(a1);
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
	mulN_arr(a1, 0xffff, mulN);
	cout << "mulN is ";
	show_arr(mulN);
	unsigned int mult[GLOBAL_SIZE];
	zero_arr(mult);
	mult_arr(a1, b1, mult);
	cout << "mult is ";
	show_arr(mult);
	/*unsigned int pow[GLOBAL_SIZE];
	zero_arr(pow);
	cout << "pow is ";
	pow_arr(a1, b1, pow);
	show_arr(pow);*/
	unsigned int div2[GLOBAL_SIZE];
	zero_arr(div2);
	div_arr2(a1, b1,div2);
	cout << "this is div ";
	show_arr(div2);
	unsigned int div3[GLOBAL_SIZE];
	zero_arr(div3);
	div_arr2(mult, b1, div3);
	cout << "this is div3 ";
	show_arr(div3);
	unsigned int u[GLOBAL_SIZE];
	zero_arr(u);
	count_u(b1, u);
	unsigned int barret[GLOBAL_SIZE];
	zero_arr(barret);
	barret_arr(a1, b1, barret,u);
	string mod;
	getline(file, mod);
	unsigned int* mod1 = to_arr(mod);
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
	barret_mulN_arr(a1, 0xffff, mod1,u, barr_mulN);
	cout << endl << "this is mulN bar ";
	show_arr(barr_mulN);
	/*unsigned int barr_mult[GLOBAL_SIZE];
	zero_arr(barr_mult);
	barret_mult_arr(a1, b1, mod1,u, barr_mult);
	cout << endl << "this is mult bar ";
	show_arr(barr_mult);*/
	/*nsigned int barr_mult1[GLOBAL_SIZE];
	zero_arr(barr_mult1);
	barret_mult_arr1(a1, b1, mod1, barr_mult1);
	cout << endl << "this is mult bar1 ";
	show_arr(barr_mult1);*/
	
	/*unsigned int* div = new unsigned int[GLOBAL_SIZE];
	div = div_arr(a1, b1);
	cout << endl << "q is " << hex << div[0];
	div[0] = 0;
	cout << endl << "R is ";
	show_arr(div);
	
	//unsigned int* u = count_u(b1);
	//show_arr(u);
	//unsigned int* trying = pow_arr(two, a1);
	//show_arr(trying);
	*/
	return 0;

}
