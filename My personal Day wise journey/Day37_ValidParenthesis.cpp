class Solution
{
public:
	bool isValid(string str)
	{
		int cnt = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
				cnt++;
			else if (str[i] == ')')
				cnt--;
			if (cnt < 0)
				return false;
		}
		return (cnt == 0);
	}

	bool isParenthesis(char c)
	{
		return ((c == '(') || (c == ')'));
	}

	vector<string> removeInvalidParentheses(string s)
	{   
		vector<string> ans;
		queue<string> q;
		set<string> visited;
		q.push(s);
		visited.insert(s);
		bool level = false;
		while (!q.empty())
		{
			string str = q.front();
			q.pop();
            //cout<<"str is "<<str<<endl;
			if (isValid(str))
			{
				ans.push_back(str);
				visited.insert(str);
				level = true;
			}
			if (level)
				continue;
			for (int i = 0; i < str.length(); i++)
			{
				if (!isParenthesis(str[i]))
					continue;
				string temp = str.substr(0, i) + str.substr(i+1);
               // cout<<"temp is "<<temp<<endl;
				if (visited.find(temp) == visited.end())
				{
					//means if not visited
					q.push(temp);
					visited.insert(temp);
				}
			}
		}
		return ans;
	}
};
