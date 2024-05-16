#pragma once
using namespace std;
class BST {
private:
	TreeNode* root;
	int Max(int a, int b)
	{
		if (a > b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
	int compare(const string word1, const string word2)
	{
		int cmp;
		int i, j;
		for (i = 0, j = 0; word1[i] != '\0' && word2[j] != '\0'; i++, j++)
		{
			if (word1[i] > word2[j])
			{
				cmp = 1;
				break;
			}
			else if (word1[i] < word2[j])
			{
				cmp = -1;
				break;
			}
			else
			{
				cmp = 0;
			}
		}
		if (cmp == 0)
		{
			if (word1[i] == '\0' && word2[j] != '\0')
			{
				cmp = -1;
			}
			else if (word2[j] == '\0' && word1[i] != '\0')
			{
				cmp = 1;
			}
		}
		return cmp;
	}
	void free_tree(TreeNode* root)
	{
		if (root != nullptr)
		{
			free_tree(root->getleft());
			free_tree(root->getright());
			//cout << root->getword() << " deleted" << endl;
			delete root;
		}
	}
	TreeNode* avlInsert(TreeNode* root, const string word, const string link)
	{
		if (root == nullptr)
		{
			root = new TreeNode(word, link);
			return root;
		}
		int c = compare(word, root->getword());
		if (c == -1)
		{
			root->setleft(avlInsert(root->getleft(), word, link));
			int htdiff = height(root->getleft()) - height(root->getright());
			if (htdiff == 2)
			{
				c = compare(word, root->getleft()->getword());
				if (c == -1)
					root = singleRightRotate(root);
				else
					root = doubleLeftRightRotate(root);
			}
		}

		else if (c == 1)
		{
			root->setright(avlInsert(root->getright(), word, link));
			int htdiff = height(root->getright()) - height(root->getleft());
			if (htdiff == 2)
			{
				c = compare(word, root->getright()->getword());
				if (c == 1)
					root = singleLeftRotate(root);
				else
					root = doubleRightLeftRotate(root);
			}
		}

		else if (c == 0)
		{
			root->addlink(link);
			return root;
		}
		int h = Max(height(root->getleft()), height(root->getright()));
		root->setheight(h + 1);
		return root;
	}
	int height(TreeNode* Node)
	{
		if (Node != NULL)
			return Node->getheight();
		else
			return -1;
	}
public:
	BST()
	{
		this->root = nullptr;
	}
	bool createBST(const string filename)
	{
		fstream inout;
		inout.open(filename, ios::in);
		if (!inout.is_open())
		{
			return false;
		}
		else
		{
			string line, link, emptyline, word = "";
			char id[3];
			while (!inout.eof())
			{
				inout >> id;
				getline(inout, link);
				getline(inout, line);
				getline(inout, emptyline);
				for (int i = 0; line[i] != '\0'; i++)
				{
					if (line[i] != ' ')
					{
						word += line[i];
					}
					if (line[i] == ' ' || line[i + 1] == '\0')
					{
						root = avlInsert(root, word, link);
						word = "";
					}
				}
			}
			inout.close();
			return true;
		}
	}
	TreeNode* singleRightRotate(TreeNode* k2)
	{
		if (k2 == NULL)
			return NULL;
		TreeNode* k1 = k2->getleft();
		k2->setleft(k1->getright());
		k1->setright(k2);
		int h = Max(height(k2->getleft()), height(k2->getright()));
		k2->setheight(h + 1);
		h = Max(height(k1->getleft()), k2->getheight());
		k1->setheight(h + 1);
		return k1;
	}
	TreeNode* singleLeftRotate(TreeNode* k2)
	{
		if (k2 == NULL)
			return NULL;
		TreeNode* k1 = k2->getright();
		k2->setright(k1->getleft());
		k1->setleft(k2);
		int h = Max(height(k2->getleft()), height(k2->getright()));
		k2->setheight(h + 1);
		h = Max(k2->getheight(), height(k1->getright()));
		k1->setheight(h + 1);
		return k1;

	}
	TreeNode* doubleRightLeftRotate(TreeNode* k1)
	{
		//Single right rotate
		k1->setright(singleRightRotate(k1->getright()));
		//Single left rotate
		return singleLeftRotate(k1);
	}
	TreeNode* doubleLeftRightRotate(TreeNode* k3)
	{
		//Single left Rotate
		k3->setleft(singleLeftRotate(k3->getleft()));
		//Single Right Rotate
		return singleRightRotate(k3);
	}
	/*void insert(const string word)
	{
		root = insert(this->root, word);
	}*/
	void search(const string word)
	{
		TreeNode* p = this->root;
		bool find = false;
		while (p != nullptr && !find)
		{
			int c = compare(word, p->getword());
			if (c == -1)
			{
				p = p->getleft();
			}
			else if (c == 1)
			{
				p = p->getright();
			}
			else
			{
				find = true;
				break;
			}
		}
		if (find)
		{
			cout << p->totallinks() << " result(s) found" << endl;
			p->showlinks();
		}
		else
		{
			cout << "Opps...no results found!!!" << endl;
		}
	}
	~BST()
	{
		free_tree(this->root);
		this->root = nullptr;
	}
};