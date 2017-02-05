#include<stack>
#include<queue>
#include<iostream>
#include<string>
#include<utility>
using namespace std;


template <class SIT>

class Stack
{

public:
  Stack();
  ~Stack();
  bool empty() const;
  void push (const SIT & e);
  SIT pop();

private:
    struct StackNode {
      SIT node;
      StackNode * next;
    };

    StackNode *top;
    int size;
};

class TreeNode
{
public:
  TreeNode * left, * right;
  string val;

};

void addToStack(stack<string> & s, string p)
{
	stack<string> a;
    for (int i = 0 ; i < p.length(); i++)
    {
      a.push(p.substr(i,1));
    }

	while (!a.empty())
	{
		s.push(a.top());
		a.pop();
	}
}

void reverseStack(stack<string> & s)
{
	stack<string> a;
    while (!s.empty())
    {
      a.push(s.top());
		s.pop();
    }

	s = a;
}

int compute(int a, int b, string c)
{

	cout << "the ints: " <<  a << " " << b << endl;
    if (c[0] == '+')
      return a + b;
    if (c[0] == '-')
      return a - b;
    if (c[0] == '/')
      return a/b;
    if (c[0] == '*')
      return a*b;
}


inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

//preorder


// postorder
int evaluatePPOS(stack<string>s, bool postFix)
{
  stack<string> container;

  while (!s.empty())
  {
    string elem = s.top();
    s.pop();
    container.push(elem);

    if (!isInteger(elem))
    {
        string op = container.top(); container.pop();
        string second = container.top(); container.pop();
        string first =  container.top(); container.pop();

        if (postFix)
        {
          container.push(to_string(compute(stoi(first), stoi(second), op)));
        }
        else
        {
          container.push(to_string(compute(stoi(second), stoi(first), op)));
        }
    }
  }

  string elem = container.top();
  container.pop();
  return stoi(elem);

}

int evaluateInOS(stack<char>s)
{

}

void testSubtraction()
{
    uint8_t a,b;
    a = 0;
    b = 0;

    for (int i = 0; i < 1000; i++)
    {

    }

}

int my_str2int(const char *s)
{
    int res = 0;
    while (*s) {
        res *= 10;
        res += *s++ - '0';
    }

    return res;
}


void printStack(stack<string>  s)
{
 while (!s.empty())
   {
     cout << (s.top()) << " ";
     s.pop();
   }
	cout << "\n";
}

int evaluatePOS(stack<string> s)
{

bool firstNum, secondNum = false;
stack<string> cont;

while (!s.empty())
{

	string a = s.top();
	s.pop();
	cont.push(a);

	if (isInteger(a))
	{
		if (firstNum)
			secondNum = true;

		if (!firstNum)
			firstNum = true;
	}

	else
	{
		firstNum = false;
	}

	if (secondNum)
	{
		string numT = cont.top(); cont.pop();
		string numO = cont.top(); cont.pop();
		string op =  cont.top(); cont.pop();
		string res = to_string(compute(stoi(numO), stoi(numT), op));
		cout << "res is " << res << endl;
		cont.push(res);
		printStack(cont);
		cout << "The above is const stack at present" << endl;
		printStack(s);
		cout << "The above is s stack at present" << endl;
		secondNum = false;
		firstNum = true;
	}


}



	if (cont.size() != 1)
	{
		cout << "__LINE__" << endl;
		printStack(cont);
		reverseStack(cont);
		printStack(cont);
		return evaluatePOS(cont);
	}
	else
	{
		string elem = cont.top();
		cont.pop();
		return my_str2int(elem.c_str());
	}

}

TreeNode* PostfixToPrefix(string postExpression)
{
  stack<string>s;
  addToStack(s,postExpression);
  stack<pair<string, TreeNode*>> container;
  using x = pair<string, TreeNode*>;

  while(!s.empty())
  {
    string elem = s.top();
    TreeNode * newNode = new TreeNode;
    newNode->val = elem;
    newNode->left = NULL;
    newNode->right = NULL;

    if (!isInteger(elem))
    {
      x second = container.top(); container.pop();
      x first = container.top(); container.pop();

      newNode->left = get<1>(first);
      newNode->right = get<1>(second);
    }

    x ourPair = make_pair(elem, newNode);
    container.push(ourPair);
    s.pop();
  }

  TreeNode * toReturn = get<1>(container.top());
  container.pop();
  return toReturn;

}

TreeNode* PrefixToPostfix(string preExpression)
{

  stack<string>s;
  addToStack(s,preExpression);
  reverseStack(s);

  stack<pair<string, TreeNode*>> container;
  using x = pair<string, TreeNode*>;

  while(!s.empty())
  {
    string elem = s.top();
    TreeNode * newNode = new TreeNode;
    newNode->val = elem;
    newNode->left = NULL;
    newNode->right = NULL;

    if (!isInteger(elem))
    {
      x second = container.top(); container.pop();
      x first = container.top(); container.pop();

      newNode->left = get<1>(second);
      newNode->right = get<1>(first);
    }

    x ourPair = make_pair(elem, newNode);
    container.push(ourPair);
    s.pop();
  }

  TreeNode * toReturn = get<1>(container.top());
  container.pop();
  return toReturn;

}
void makePrefix(TreeNode *root, string & s)
{
  if (root)
  {
    s += root->val;
    makePrefix(root->left, s);
    makePrefix(root->right, s);
  }
}

void makePostfix(TreeNode *root, string & s)
{
  if (root)
  {
    makePostfix(root->left, s);
    makePostfix(root->right, s);
    s += root->val;
  }
}
void levelOrder(TreeNode * root)
{
  queue<TreeNode *> q;
  q.push(root);

  TreeNode * curr = NULL;
  while (!q.empty())
  {

    curr = q.front(); q.pop();

    if (curr)
    {  cout << curr->val << endl;
      q.push(curr->left);
      q.push(curr->right);
    }
  }
}

int main()
{
  stack<string> s;
  string p = "*/+*57-2439";
  addToStack(s ,p);

  stack<string>s2;
  string q = "6312*+-";
  addToStack(s2, q);

  reverseStack(s);

	// cout << evaluatePPOS(s, false) << endl;

  TreeNode * t = PrefixToPostfix(p);
  levelOrder(t);

  // string preFix;
  // makePrefix(t, preFix);
  // cout << preFix << endl;

  string postFix;
  makePostfix(t, postFix);
  cout << postFix << endl;

}
