#pragma once
using namespace std;
class TreeNode {
private:
	string word;
	TreeNode* left;
	TreeNode* right;
	linklist links;
	int links_count;
	int height;
public:
	TreeNode()
	{
		word = "";
		left = right = nullptr;
		links_count = 0;
		height = 0;
	}
	TreeNode(const string word, const string link)
	{
		this->word = word;
		left = right = nullptr;
		links.insert(link);
		links_count++;
		height = 0;
	}
	int getheight()
	{
		return this->height;
	}
	void setheight(int height)
	{
		this->height = height;
	}
	void setword(const string word)
	{
		this->word = word;
	}
	void setleft(TreeNode* left)
	{
		this->left = left;
	}
	void setright(TreeNode* right)
	{
		this->right = right;
	}
	const string getword()
	{
		return this->word;
	}
	TreeNode* getleft()
	{
		return this->left;
	}
	TreeNode* getright()
	{
		return this->right;
	}
	void addlink(const string link)
	{
		if (links.insert(link))
		{
			links_count++;
		}
	}

	linklist getlinks()
	{
		return this->links;
	}
	void showlinks()
	{
		links.print();
	}
	int totallinks()
	{
		return this->links_count;
	}
	Node* getheadoflinklist()
	{
		return links.gethead();
	}
	bool isLeaf()
	{
		if (left == nullptr && right == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};