#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class HuffmanCode {
public:
	char ch;
	int freq;
	HuffmanCode* left;
	HuffmanCode* right;
	string code;
	HuffmanCode(char c, int f) :ch(c), freq(f), left(nullptr), right(nullptr), code("") {};
	HuffmanCode(char c, int f, HuffmanCode* l, HuffmanCode* r) :ch(c), freq(f), left(l), right(r), code("") {};
};

HuffmanCode* root;//哈夫曼树根

class Compare {
public:
	bool operator()(HuffmanCode* a, HuffmanCode* b) {
		return a->freq > b->freq;
	}
};//优先队列排序规则


void BuildHuffmanTree(priority_queue<HuffmanCode*, vector<HuffmanCode*>, Compare>& q) {
	HuffmanCode* temp1;
	HuffmanCode* temp2;
	while (!q.empty()) {
		temp1 = q.top();
		q.pop();
		temp2 = q.top();
		q.pop();
		root = new HuffmanCode('0', temp1->freq + temp2->freq, temp1, temp2);
		if (q.empty())return;
		q.push(root);
	}

}

void code() {
	HuffmanCode* temp;
	queue<HuffmanCode*>q;
	q.push(root);
	temp = root;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp->left != nullptr) {
			q.push(temp->left);
			temp->left->code += temp->code;
			temp->left->code += "0";
		}
		if (temp->right != nullptr) {
			q.push(temp->right);
			temp->right->code += temp->code;
			temp->right->code += "1";
		}
	}
}

string searchCode(HuffmanCode* root, char c) {
	HuffmanCode* temp;
	queue<HuffmanCode*>q;
	q.push(root);
	temp = root;
	while (!q.empty() || temp != nullptr) {
		temp = q.front();
		q.pop();
		if (temp->ch == c)return temp->code;
		if (temp->left != nullptr) {
			q.push(temp->left);
		}
		if (temp->right != nullptr) {
			q.push(temp->right);
		}
	}

}
int main() {
	char c;
	int freq;
	int n;
	cin >> n;
	while (n--) {
		string result = "";
		string ans;
		priority_queue<HuffmanCode*, vector<HuffmanCode*>, Compare> q;
		int num;
		cin >> num;
		while (num--) {
			cin >> c;
			cin >> freq;
			q.push(new HuffmanCode(c, freq));
		}
		BuildHuffmanTree(q);
		code();
		cin >> ans;
		for (char c : ans) {
			result += searchCode(root, c);
		}
		cout << result.size() << endl;
	}
	return 0;
}