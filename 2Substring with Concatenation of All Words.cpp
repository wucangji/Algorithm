//2014-1-25
class Solution3 {
public:
	vector<int> findSubstring(string S, vector<string> &L) 
	{
		vector<int> rs;
		if (L.empty()) return rs;
		int len = L[0].length();
		int num = 0;
		int m = L.size()*len;
		if (S.length() < m) return rs;

		unordered_map<string, int> fixedTable;
		unordered_map<string, int> countTable;
		for (int i = 0; i < L.size(); i++)
		{
			fixedTable[L[i]]++;
		}
		
		for (int d = 0; d < len; d++)
		{
			for (int i = d; i <= S.length()-m; )
			{
				countTable.clear();
				num = 0;//注意：清零，很严重的工作！！！
				for (int j = i; j < S.length(); j+=len)
				{
					string t = S.substr(j, len);
					if (!fixedTable.count(t)) 
					{
						i = j+len;
						break;
					}

					if (countTable[t]<fixedTable[t]) 
					{
						countTable[t]++;
						if (++num == L.size())
						{
							rs.push_back(i);
							num--;
							countTable[S.substr(i,len)]--;
							i += len;
						}
					}
					else 
					{
						string t2 = S.substr(i, len);
						for ( ; t2 != t; t2 = S.substr(i, len))
						{
							countTable[t2]--;
							i += len;
							num--;
						}
						i += len;
					}
				}
			}
		}
		return rs;
	}
};