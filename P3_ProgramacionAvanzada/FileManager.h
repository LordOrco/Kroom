#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


class FileManager
{
private:
	ofstream file;
	int top1;
	int top2;
	int top3;
	int top4;
	int top5;
	int totalGames;
	int lastGame;

public:

	FileManager():
		top1(0),
		top2(0),
		top3(0),
		top4(0),
		top5(0),
		totalGames(0),
		lastGame(0)
	{}

	inline int GetTop1() const { return this->top1; }
	inline int GetTop2() const { return this->top2; }
	inline int GetTop3() const { return this->top3; }
	inline int GetTop4() const { return this->top4; }
	inline int GetTop5() const { return this->top5; }
	inline int GetLastGame() const { return this->lastGame; }
	inline int GetTotalGames() const { return this->totalGames; }

	inline void SetTop1(const int& topToSet) { this->top1 = topToSet; }
	inline void SetTop2(const int& topToSet) { this->top2 = topToSet; }
	inline void SetTop3(const int& topToSet) { this->top3 = topToSet; }
	inline void SetTop4(const int& topToSet) { this->top4 = topToSet; }
	inline void SetTop5(const int& topToSet) { this->top5 = topToSet; }
	inline void SetLastGame(const int& lastToSet) { this->lastGame = lastToSet; }
	inline void SetTotalGames(const int& gamesToSet) { this->totalGames = gamesToSet; }

	void saveFile();
	void loadFile();
	bool existFile();

};

