#include <iostream>

#include "tokenizer.h"


int main() {
	std::string sourceString = "(5 + 4) * 3";

	Tokenizer tokenizer = Tokenizer(true);
	tokenizer.addRule(new KeywordRule("(", "symbol.round_brace_left", false));
	tokenizer.addRule(new KeywordRule(")", "symbol.round_brace_right", false));

	tokenizer.addRule(new KeywordRule("+", "symbol.plus", false));
	tokenizer.addRule(new KeywordRule("*", "symbol.asterix", false));

	tokenizer.addRule(new KeywordRule("0", "digit", false));
	tokenizer.addRule(new KeywordRule("1", "digit", false));
	tokenizer.addRule(new KeywordRule("2", "digit", false));
	tokenizer.addRule(new KeywordRule("3", "digit", false));
	tokenizer.addRule(new KeywordRule("4", "digit", false));
	tokenizer.addRule(new KeywordRule("5", "digit", false));
	tokenizer.addRule(new KeywordRule("6", "digit", false));
	tokenizer.addRule(new KeywordRule("7", "digit", false));
	tokenizer.addRule(new KeywordRule("8", "digit", false));
	tokenizer.addRule(new KeywordRule("9", "digit", false));

	std::vector<Token> tokens = tokenizer.tokenize(sourceString);

	for (int i = 0; i < tokens.size(); i++) {
		std::cout << tokens[i].type << ": " << tokens[i].str << std::endl;
	}

	std::cin.get();

	return 0;
}