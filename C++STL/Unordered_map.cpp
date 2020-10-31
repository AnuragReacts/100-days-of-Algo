
#include <bits/stdc++.h>

int main()
{
	std::unordered_map<int, int> order;

	order[5] = 10;
	order[3] = 5;
	order[20] = 100;
	order[1] = 1;

	// Iterating the map and printing unordered values
  
	for (auto i = order.begin(); i != order.end(); i++)
	{
		std::cout << i->first << "   ------>>> "<< i->second << '\n';
	}
}
