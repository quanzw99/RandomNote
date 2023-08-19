#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void printmap(unordered_map<int, string>& ma) {
	for (unordered_map<int, string>::iterator it = ma.begin(); it != ma.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}

int main() {
	
	unordered_map<int, string> ma = {
		{1, "hello"},
		{2, "world"}
	};
	
	// insert
	// 使用pair往map中插入时，key值冲突时，忽略插入
	pair<int, string> p(1, "hello1");
	ma.insert(p);
	// printmap(ma);

	// 使用map[key] = val这种形式插入时，key值冲突，旧值被新值覆盖 
	ma[1] = "hello2";
	// printmap(ma);

	// find
	// map.end() 指向map中最后一个元素之后的位置
	auto it = ma.find(1);
	if (it == ma.end())
		cout << "not found" << endl;
	else cout << "found " << it->first << " -> " << it->second << endl;

	// count
	// 有时也可以用count来代替find，查看map中是否存在相应的key值
	auto ans = ma.count(1);
	cout << ans << endl;

	// empty
	// 非空返回0，空返回1
	cout << ma.empty() << endl;

	// size
	cout << ma.size() << endl;

	// erase
	// 通过迭代器erase
	ma.erase(ma.begin());
	// 通过key值erase
	ma.erase(2);

	// clear
	ma.clear();

}