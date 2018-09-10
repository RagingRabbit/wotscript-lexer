#pragma once

#include <vector>
#include <string>

class TokenizerRule
{
public:
	std::string type;

public:
	TokenizerRule(std::string type);

	virtual std::vector<int> getIndices(std::string input, int fromIndex) = 0;
	virtual std::string getSequence(std::string token, std::vector<int> indices) = 0;
};

class KeywordRule : public TokenizerRule
{
private:
	std::string regex;
	bool strict;

public:
	KeywordRule(std::string regex, std::string type, bool strict);

	std::vector<int> getIndices(std::string input, int fromIndex) override;
	std::string getSequence(std::string token, std::vector<int> indices) override;
};

class BeginRule : public TokenizerRule
{
private:
	std::string begin;
	bool fearWhitespace;

public:
	BeginRule(std::string begin, std::string type, bool fearWhitespace);

	std::vector<int> getIndices(std::string input, int fromIndex) override;
	std::string getSequence(std::string token, std::vector<int> indices) override;
};

class BeginEndRule : public TokenizerRule
{
private:
	std::string begin;
	std::string end;

public:
	BeginEndRule(std::string begin, std::string end, std::string type);

	std::vector<int> getIndices(std::string input, int fromIndex) override;
	std::string getSequence(std::string token, std::vector<int> indices) override;
};

class Token
{
public:
	std::string str;
	std::string type;

	Token(std::string str, std::string type);
};

class Tokenizer
{
private:
	std::vector<TokenizerRule*> rules;
	bool trim;

public:
	Tokenizer(bool trim);

	void addRule(TokenizerRule* rule);

	std::vector<Token> tokenize(std::string source);

private:
	std::vector<Token> processRule(Token token, int ruleIndex);
	void skipWhitespace(std::vector<Token>& tokens);
};