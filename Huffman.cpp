#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
	char ch;
	int freq;
	Node* left, * right;
};

Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

struct comp
{
	bool operator()(Node* l, Node* r)
	{
		return l->freq > r->freq;
	}
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right)
	{
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int& index, string str)
{
	if (root == nullptr)
	{
		return;
	}

	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] == '0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

void buildHuffmanTree(string text)
{
	int count2 = 0;
	for (int i = 0; i < text.length(); i++)
	{
		count2 += 8;
	}

	cout << "Count of the bits of the original string in the memory is : " << count2 << endl;
	unordered_map<char, int> freq;
	for (char ch : text)
	{
		freq[ch]++;
	}

	priority_queue<Node*, vector<Node*>, comp> pq;

	for (auto pair : freq)
	{
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	while (pq.size() != 1)
	{
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top();	pq.pop();

		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	Node* root = pq.top();

	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes are :\n" << '\n';
	int count = 0;
	int cnt = 0;
	for (auto pair : huffmanCode)
	{
		cout << pair.first << " " << pair.second << '\n';
		for (auto i : pair.second)
		{
			count++;
		}
		cnt += 8;
	}
	cout << "Count of Huffman Codes is : " << count + cnt << endl;

	cout << "\nOriginal string was :\n" << text << '\n';

	string str = "";
	for (char ch : text)
	{
		str += huffmanCode[ch];
	}

	cout << "\nEncoded string is :\n" << str << '\n';
	int count1 = 0;
	for (int i = 0; i < str.length(); i++)
	{
		count1++;
	}
	cout << "Count of Encoded string is : " << count1 << endl;

	int index = -1;
	cout << "\nDecoded string is: \n";
	while (index < (int)str.size() - 1)
	{
		decode(root, index, str);
	}
	cout << endl;
	float ans = count2 - (count + cnt + count1);
	cout << "The data is compressed by : " << ans << " Bits" << endl;
	float ratio = float((ans / count2) * 100);
	cout << "The compression ratio is : " << ratio << "%" << endl;
}

int main()
{
	string text;
	cout << "Enter a string : " << endl;
	getline(cin, text);
	buildHuffmanTree(text);

	/* Data set : BCCABBDDAECCBBAEDDCC*/
}
