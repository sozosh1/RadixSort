#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void rSort(std::vector<std::string>& keys);

bool isSorted(const std::vector<std::string>& keys);

int main()
{
	std::vector<std::string> keys(10);
	for (int i = 0; i < 10; i++)
	{
		std::string key;

		for (int j = 0; j < 1; j++)
		{
			key += 'a' + rand() % 26;
		}
		keys[i] = key;
	}

	std::cout << "Unsorted keys:" << std::endl;
	for (const std::string& key : keys) 
	{
		std::cout << key << " ";
	}
	std::cout << std::endl;

	rSort(keys);

	std::cout << "Sorted keys:" << std::endl;
	for (const std::string& key : keys) 
	{
		std::cout << key << " ";
	}
	std::cout << std::endl;

	if (isSorted(keys)) 
	{
		std::cout << "Sorting is correct!" << std::endl;
	}
	else 
	{
		std::cout << "Sorting is incorrect!" << std::endl;
	}

	return 0;
}

void rSort(std::vector<std::string>& keys)
{
	int d = keys[0].size(); // количество разрядов
	int n = keys.size(); // количество элементов в массиве

	std::vector<int> cnt(26, 0); // массив счетчиков для каждой буквы латинского алфавита
	std::vector<std::string> temp(n); // временный массив для копирования ключей

	for (int k = d - 1; k >= 0; k--)
	{
		std::fill(cnt.begin(), cnt.end(), 0);

		for (int i = 0; i < n; i++)
		{
			cnt[keys[i][k] - 'a']++;
		}
		for (int i = 1; i < 26; i++) 
		{ 
			cnt[i] += cnt[i - 1];
		}
		for (int i = n - 1; i >= 0;i--)
		{
			temp[--cnt[keys[i][k] - 'a']] = keys[i];
		}

		keys = temp;
	}
}

bool isSorted(const std::vector<std::string>& keys)
{
	int n = keys.size();

	for (int i = 1; i < n; i++)
	{
		if (keys[i - 1] > keys[i])
		{
			return false;
		}
		return true;
	}
}