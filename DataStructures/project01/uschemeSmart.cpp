// uschemeSmart.cpp
// Angel Rodriguez && Thomas Plummer
// 2/7/2018


#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unistd.h>
#include <ctype.h>
#include <memory>
using namespace std;

// Globals ---------------------------------------------------------------------

bool BATCH = false;
bool DEBUG = false;

// Structures ------------------------------------------------------------------

struct Node {
    Node(string value, shared_ptr<Node> l =nullptr, shared_ptr<Node> r =nullptr);
    ~Node();

    string value;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    friend ostream &operator<<(ostream &os, const Node &n);
};

Node::Node(string v, shared_ptr<Node> l, shared_ptr<Node> r){
    value = v;
    left = l;
    right = r;  
}

Node::~Node(){}

ostream &operator<<(ostream &os, const Node &n) {
    os << "(Node: value=" << n.value;
	if (n.left){
		cout << ", left=" << *n.left << ")";
	}
	if (n.right){
		cout << ", right=" << *n.right << ")";
	}
	return os;
}

// Parser ----------------------------------------------------------------------

string parse_token(istream &s) {
    string token;
    // Continue inputting until the next character
    // It is not the empty space
    while(s.peek() == ' '){
         s.get();
    }

    // IF the next character is a paranthesis or an operator
    // Assign token to this value. 
    if(s.peek() == '(' || s.peek() == ')' ||
       s.peek() == '+' || s.peek() == '-' ||
       s.peek() == '*' || s.peek() == '/'){
       token = s.get();
    }

    // If next character is a digit assign token to this value
            else if (isdigit(s.peek()))
            {
                token = s.get();
                while(s.peek() != ' ' && s.peek() != ')' && s.peek() !=EOF)
                {
                    if(isdigit(s.peek()))
                    token += s.get();
                }

        }
	return token;
}

shared_ptr<Node> parse_expression(istream &s) {
    string token = parse_token(s);
	shared_ptr<Node> left = nullptr;
	shared_ptr<Node> right = nullptr;

	if(token == " " || token == ")"){
		return nullptr;
	}
   if(token == "("){
        token = parse_token(s);
        left = parse_expression(s);
        if(left){
            right = parse_expression(s);
        }
        if (right){
        parse_token(s);
    }
   }

    return shared_ptr<Node>(new Node(token, left, right));
}

// Interpreter -----------------------------------------------------------------

void evaluate_r(const shared_ptr<Node> n, stack<int> &s) {
    // Base Case
    if(!n){
        return;
    }
    // Recursive Calls
    if(n->left){
        evaluate_r(n->right, s);
    }
    if(n->right){
        evaluate_r(n->left, s);
    }

    // Calculation
    char firstChar = n->value[0];
    if (isdigit(firstChar)) {
        s.push( stoi(n->value));
    } else
    {
      int operand1 = s.top();
      s.pop();
      int operand2 = s.top();
      s.pop();

    if ( firstChar == '+')
      s.push(operand1 + operand2);

    else if ( firstChar == '-')
      s.push(operand1 - operand2);
    else if ( firstChar == '*')
      s.push(operand1 * operand2);
    else
      s.push(operand1 / operand2);
    }
}


int evaluate(const shared_ptr<Node> n) {
    stack<int> s;
	evaluate_r(n,s);
	return s.top();
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    string line;
    int c;

    while ((c = getopt(argc, argv, "bdh")) != -1) {
        switch (c) {
            case 'b': BATCH = true; break;
            case 'd': DEBUG = true; break;
            default:
                cerr << "usage: " << argv[0] << endl;
                cerr << "    -b Batch mode (disable prompt)"   << endl;
                cerr << "    -d Debug mode (display messages)" << endl;
                return 1;
        }
    }

    while (!cin.eof()) {
        if (!BATCH) {
            cout << ">>> ";
            cout.flush();
        }

        if (!getline(cin, line)) {
            break;
        }

        if (DEBUG) { cout << "LINE: " << line << endl; }

        stringstream s(line);
        shared_ptr<Node> n = parse_expression(s);
        if (DEBUG) { cout << "TREE: " << *n << endl; }

        cout << evaluate(n) << endl;
    }

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
