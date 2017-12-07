#include <iostream>
#include <map>
#include <cassert>
#include <string>
#include <streambuf>
#include <string>
#include "transformer.h"


int main(int argc, char** argv){
	std::ios_base::sync_with_stdio(false);
	auto treeregex = treeregex::parse(argv[1]);

	std::string tree_str((std::istreambuf_iterator<char>(std::cin)), std::istreambuf_iterator<char>());
	if(tree_str[tree_str.length()-1] == '\n'){
		tree_str.pop_back();
	}
	auto tree = tree::parse(tree_str);

	Transformer t;
	t.add([&] (std::shared_ptr<Tree> t){
			auto ret = matches(treeregex, t);
			if(!ret.result) {
			//std::cout << "Match not found: "; t->print(std::cout); std::cout << '\n';

			return t;}
			std::cout << "Match found: "; t->print(std::cout); std::cout << '\n';
			return t;
			}, true);
	t(tree);
}
